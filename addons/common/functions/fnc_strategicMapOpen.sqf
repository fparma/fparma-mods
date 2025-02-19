/*
Author: Karel Moricky. Edited by cuel to allow zoom

Description:
Open strategic map.

Parameter(s):
    0: DISPLAY - parent display. When empty, mission display is used.
    1: ARRAY - default view position in format [x,y,y] or [x,y]
    2: ARRAY - list of missions in format:
        0: ARRAY - mission position in format [x,y,y] or [x,y]
        1: CODE - expression executed when user clicks on mission icon
        2: STRING - mission name
        3: STRING - short description
        4: STRING - name of mission's player
        5: STRING - path to overview image
        6: NUMBER - size multiplier, 1 means default size
        7: ARRAY - parameters for the -on click- code; referenced from the script as (_this select 9)
    3: ARRAY - list of ORBAT groups in format:
        0: ARRAY - group position in format [x,y,y] or [x,y]
        1: CONFIG - preview CfgORBAT group
        2: CONFIG - topmost displayed CfgORBAT group
        3: ARRAY - list of allowed tags
        4: NUMBER - maximum number of displayed tiers
    4: ARRAY - list of markers revealed in strategic map (will be hidden when map is closed)
    5: ARRAY - list of custom images in format:
        0: STRING - texture path
        1: ARRAY - color in format [R,G,B,A]
        2: ARRAY - image position
        3: NUMBER - image width (in metres)
        4: NUMBER - image height (in metres)
        5: NUMBER - image angle (in degrees)
        6: STRING - text displayed next to the image
        7: BOOL - true to display shadow
    6: NUMBER - value in range <0-1> defining weather on strategic map (i.e. density of clouds)
    7: BOOL - true for night version of strategic map (darker with blue tone)
    8: NUMBER - default map scale coeficient (1 is automatic scale)
    9: BOOL - true to enable simulation while the map is opened (default: false)
       10: STRING - bottom bar action label text (default: "Select a mission")
       11: BOOL - true to show icon label as a mission name (default: true)
       12: STRING - path to mission icon texture (default: "\A3\Ui_f\data\Map\GroupIcons\badge_rotate_%1_gs.paa")
            %1 - animation frame from 0-6 (optional)
            %2 - index from 1-9 (optional)

Returns:
DISPLAY - RscDisplayStrategicMap
*/

#include "script_component.hpp"
private ["_parentDisplayDefault","_parentDisplay","_mapCenter","_missions","_ORBAT","_markers","_images","_overcast","_scale","_defaultScale","_simulationEnabled","_displayClass","_display","_playerIcon","_playerColor","_cloudTextures","_cloudsGrid","_cloudsMax","_cloudsSize","_map","_fade","_actionText","_missionIcon","_showIconText"];
disableSerialization;

_parentDisplayDefault = switch false do {
    case isNull (findDisplay 37): {findDisplay 37}; //--- GetReady
    case isNull (findDisplay 52): {findDisplay 52}; //--- ServerGetReady
    case isNull (findDisplay 53): {findDisplay 53}; //--- ClientGetReady
    default {[] call bis_fnc_displayMission}; //--- Mission
};
_parentDisplay = _this param [0,_parentDisplayDefault,[displayNull]];
_mapCenter = _this param [1,position player];
_mapCenter = _mapCenter call bis_fnc_position;
_missions = _this param [2,[],[[]]];
_ORBAT = _this param [3,[],[[]]];
_markers = _this param [4,[],[[]]];
_images = _this param [5,[],[[]]];
_overcast = (_this param [6,overcast,[0]]) max 0 min 1;
_isNight = _this param [7,false,[false]];
_defaultScale = _this param [8,1,[0]];
_simulationEnabled = _this param [9,false,[false]];
_actionText = _this param [10,localize "str_a3_rscdisplaystrategicmap_missions",[""]];
_showIconText = _this param [11,true,[true]];
_missionIcon = _this param [12,"\A3\Ui_f\data\Map\GroupIcons\badge_rotate_%1_gs.paa",[""]];

BIS_fnc_strategicMapOpen_showIconText = _showIconText;
BIS_fnc_strategicMapOpen_missionIcon = _missionIcon;

//--- Calculate terrain size and outside color
_mapSize = worldSize;
BIS_fnc_strategicMapOpen_mapSize = _mapSize;
BIS_fnc_strategicMapOpen_isNight = _isNight;

_scale = 3500 / _mapSize / safeZoneH;
_scale = _scale * (_defaultScale max 0 min 1);
_maxSatelliteAlpha = [1, 0.75] select _isNight;

_colorOutside = configFile >> "CfgWorlds" >> worldName >> "OutsideTerrain" >> "colorOutside";
_colorOutside = if (isArray _colorOutside) then {
    _colorOutside call bis_fnc_colorCOnfigToRGBA;
} else {
    private _msg = format ["colorOutside param is mission in ""CfgWorlds"" >> ""%1"" >> ""OutsideTerrain""", worldName];
    WARNING(_msg);
    [0,0,0,1]
};

with uiNamespace do {
    RscDisplayStrategicMap_scaleMin = 0;
    RscDisplayStrategicMap_scaleMax = 1;
    RscDisplayStrategicMap_scaleDefault = _scale;
    RscDisplayStrategicMap_maxSatelliteAlpha = _maxSatelliteAlpha;

    RscDisplayStrategicMap_colorOutside_R = _colorOutside select 0;
    RscDisplayStrategicMap_colorOutside_G = _colorOutside select 1;
    RscDisplayStrategicMap_colorOutside_B = _colorOutside select 2;
};

//--- Create the viewer
_displayClass = ["RscDisplayStrategicMap", "RscDisplayStrategicMapSimulation"] select _simulationEnabled;
_parentDisplay createDisplay _displayClass;
_display = findDisplay 506;
if (isNull _display) exitWith {"Unable to create 'RscDisplayStrategicMap' display." call (uiNamespace getVariable "bis_fnc_error"); displayNull};

//--- Life, calculations and everything
// startloadingscreen ["","RscDisplayLoadingBlack"];

BIS_fnc_strategicMapOpen_player = player;
//selectnoplayer;

//--- Process ORBAT
BIS_fnc_strategicMapOpen_ORBAT = [];
_onClick = [];
{
    private ["_pos","_class","_parent","_tags","_tiers","_classParams","_text","_texture","_size","_color","_sizeLocal","_sizeParams","_sizeTexture"];
    _pos = _x param [0,player];
    _pos = _pos call bis_fnc_position;

    _class = _x param [1,configFile >> "CfgORBAT",[configFile]];
    _parent = _x param [2,_class,[configFile]];
    _tags = _x param [3,[],[[]]];
    _tiers = _x param [4,-1,[0]];

    _classParams = _class call bis_fnc_ORBATGetGroupParams;
    _text = _classParams select ("text" call bis_fnc_ORBATGetGroupParams);
    _texture = _classParams select ("texture" call bis_fnc_ORBATGetGroupParams);
    _size = _classParams select ("size" call bis_fnc_ORBATGetGroupParams);
    _color = _classParams select ("color" call bis_fnc_ORBATGetGroupParams);

    _iconSize = sqrt (_size + 1) * 32;

    //--- Group size
    //_sizeLocal = _size max 0 min (count (BIS_fnc_ORBATGetGroupParams_sizes) - 1);
    //_sizeParams = BIS_fnc_ORBATGetGroupParams_sizes select _sizeLocal;
    //_sizeTexture = _sizeParams select 0;

    BIS_fnc_strategicMapOpen_ORBAT set [
        count BIS_fnc_strategicMapOpen_ORBAT,
        [
            _class,
            [_parent,_tags,_tiers],
            [
                _texture,
                _color,
                _pos,
                _iconSize,
                _iconSize,
                0,
                "",
                false
            ],
            _classParams
        ]
    ];

    //--- Create shortcut from ORBAT viewer
    _onClick set [count _onClick,_class];
    _onClick set [count _onClick,{[_this select 0,1] spawn bis_fnc_strategicMapAnimate; true}];
} forEach _ORBAT;
BIS_fnc_strategicMapOpen_ORBATonClick = _onClick;

//--- Process Missions
BIS_fnc_strategicMapOpen_missions = [];
if (count _missions > 0) then {
    _playerIcon = getText (configFile >> "CfgInGameUI" >> "IslandMap" >> "iconPlayer");
    _playerColor = (getArray (configFile >> "cfgingameui" >> "islandmap" >> "colorMe")) call BIS_fnc_colorRGBAtoHTML;

    _ctrlBackground = _display displayCtrl 1000;
    _ctrlBackground ctrlShow false;

    _ctrlMissions = _display displayCtrl 1500;
    _lbAdd = _ctrlMissions lbAdd _actionText;
    _ctrlMissions lbSetValue [_lbAdd,-1];
    _ctrlMissions lbSetColor [_lbAdd,[1,1,1,0.5]];
    {
        private ["_pos","_code","_title","_description","_player","_picture","_iconSize","_infoText","_codeParams"];
        _pos = _x param [0,player];
        _pos = _pos call bis_fnc_position;

        _code = _x param [1,{},[{}]];
        _title = _x param [2,"ERROR: MISSING TITLE",[""]];
        _description = _x param [3,"",[""]];
        _player = _x param [4,"",[""]];
        _picture = _x param [5,"",[""]];
        _iconSize = _x param [6,1,[1]];
        _codeParams = _x param [7,[],[[]]];

        _infoText = _title;
        if (_player != "") then {_infoText = _infoText + format ["<br /><t size='0.2' color='#00000000'>-<br /></t><img size='1' image='%2' color='%3'/><t size='0.8'> %1</t>",_player,_playerIcon,_playerColor];};
        if (_description != "") then {_infoText = _infoText + format ["<br /><t size='0.5' color='#00000000'>-<br /></t><t size='0.8'>%1</t>",_description];};
        //if (_picture != "") then {_infoText = _infoText + format ["<br /><img size='5.55' image='%1' />",_picture];};

        BIS_fnc_strategicMapOpen_missions set [
            count BIS_fnc_strategicMapOpen_missions,
            [
                _pos,
                _code,
                _title,
                _iconSize,
                _picture,
                0,
                0,
                0,
                _infoText,
                _codeParams
            ]
        ];

        _lbAdd = _ctrlMissions lbAdd format ["%1 (%2/%3)",_title,_forEachindex + 1,count _missions];
        _ctrlMissions lbSetValue [_lbAdd,_forEachindex];

    } forEach _missions;

    _ctrlMissions lbSetCurSel 0;
    _ctrlMissions ctrlAddEventHandler [
        "LBSelChanged",
        "
            _ctrlMissions = _this select 0;
            _cursel = _this select 1;
            if ((_ctrlMissions lbvalue 0) < 0) exitWith {_ctrlMissions lbdelete 0; _ctrlMissions lbSetCurSel 0;};
            _mission = BIS_fnc_strategicMapOpen_missions select (_ctrlMissions lbvalue _cursel);
            [_mission select 0,1] spawn bis_fnc_strategicmapanimate;
        "
    ];
};

//--- Process Images
BIS_fnc_strategicMapOpen_images = [];
{
    private ["_texture","_color","_pos","_w","_h","_dir","_text","_shadow"];
    _texture = _x param [0,"#(argb,8,8,3)color(0,0,0,0)",[""]];
    _color = _x param [1,[1,1,1,1],[[]]];
    _pos = _x param [2,position player];
    _w = _x param [3,0,[0]];
    _h = _x param [4,0,[0]];
    _dir = _x param [5,0,[0]];
    _text = _x param [6,"",[""]];
    _shadow = _x param [7,false,[false]];

    _pos = _pos call bis_fnc_position;
    _color = _color call bis_fnc_colorConfigToRGBA;
    _coef = (0.182 * safeZoneH); //--- Magic constant to make kilometer a kilometer
    _w = _w * _coef;
    _h = _h * _coef;

    BIS_fnc_strategicMapOpen_images set [
        count BIS_fnc_strategicMapOpen_images,
        [_texture,_color,_pos,_w,_h,_dir,_text,_shadow]
    ];
} forEach _images;

//--- Random clouds
_cloudTextures = [
    "\A3\data_f\mrak_01_ca.paa",
    "\A3\data_f\mrak_02_ca.paa",
    "\A3\data_f\mrak_03_ca.paa",
    "\A3\data_f\mrak_04_ca.paa"
];
_cloudsGrid = 500;
_cloudsMax = (_mapSize / _cloudsGrid) * _overcast;
_cloudsSize = (_cloudsGrid / 2) + (_cloudsGrid * _overcast);
BIS_fnc_strategicMapOpen_overcast = _overcast;
BIS_fnc_strategicMapOpen_clouds = [];

for "_i" from 1 to (_cloudsMax) do {
    BIS_fnc_strategicMapOpen_clouds set [
        count BIS_fnc_strategicMapOpen_clouds,
        [
            _cloudTextures call bis_fnc_selectrandom,
            (random _mapSize),
            ((_mapSize / _cloudsMax) * _i),
            random 360,
            _cloudsSize + (_cloudsSize * _overcast),
            [1,1,1,0.25]
        ]
    ];
};


BIS_fnc_strategicMapOpen_indexSizeTexture = ("sizeTexture" call bis_fnc_ORBATGetGroupParams);
BIS_fnc_strategicMapOpen_indexTextureSize = ("textureSize" call bis_fnc_ORBATGetGroupParams);

BIS_fnc_strategicMapOpen_draw = {
    scriptName "bis_fnc_strategicMapOpen - Draw";
    _map = _this select 0;
    _mapSize = BIS_fnc_strategicMapOpen_mapSize / 2;
    _display = ctrlParent _map;
    _time = diag_tickTime;

    //_tooltip = (ctrlParent _map) displayCtrl 2350;
    //_tooltip ctrlSetFade 1;
    //_tooltip ctrlCommit 0;

    _mousePos = _map ctrlMapScreenToWorld BIS_fnc_strategicMapOpen_mousePos;
    //_mouseLimit = BIS_fnc_strategicMapOpen_mapSize / 3400;
    _mouseLimit = 2.5 / safeZoneH;
    _selected = [];

    //--- Cross grid
    _map drawRectangle [
        [_mapSize,_mapSize,0],
        _mapSize,
        _mapSize,
        0,
        [1,1,1,0.42],
        "\A3\Ui_f\data\GUI\Rsc\RscDisplayStrategicMap\cross_ca.paa"
    ];

    //--- Images
    {
        _map drawIcon _x;
    } forEach BIS_fnc_strategicMapOpen_images;

    //--- ORBAT groups
    {
        _class = _x select 0;
        _iconParams = +(_x select 2);
        _classParams = +(_x select 3);

        _pos = _iconParams select 2;
        _iconSize = _iconParams select 3;

        if (((_iconParams select 2) distance _mousePos) < (_mouseLimit * _iconSize)) then {
            _iconParams set [3,(_iconParams select 3) * 1.2];
            _iconParams set [4,(_iconParams select 4) * 1.2];
            _selected = _x;
        };

        _textureSize = _classParams select BIS_fnc_strategicMapOpen_indexTextureSize;
        _iconSizeParams = +_iconParams;
        _iconParams set [3,(_iconParams select 3) * _textureSize];
        _iconParams set [4,(_iconParams select 4) * _textureSize];

        _map drawIcon _iconParams;

        //--- Draw size texture
        _size = _classParams select 5;
        if (_size >= 0) then {
            _sizeTexture = _classParams select BIS_fnc_strategicMapOpen_indexSizeTexture;
            _iconSizeParams set [0,_sizeTexture];
            _map drawIcon _iconSizeParams;
        };

    } forEach BIS_fnc_strategicMapOpen_ORBAT;

    //--- Clouds
    _cloudSpeed = sin _time * (1138 + 2000 * BIS_fnc_strategicMapOpen_overcast);
    {
        _texture = _x select 0;
        _posX = _x select 1;
        _posY = _x select 2;
        _dir = _x select 3;
        _size = _x select 4;
        _color = _x select 5;

        _map drawIcon [
            _texture,
            _color,
            [
                _posX + _cloudSpeed,
                _posY
            ],
            _size,
            _size,
            _dir + (_time * _forEachindex) / (count BIS_fnc_strategicMapOpen_clouds * 3),
            "",
            false
        ];
    } forEach BIS_fnc_strategicMapOpen_clouds;

    //--- Missions
    _textureAnimPhase = abs(6 - floor (_time * 16) % 12);
    {
        _pos = _x select 0;
        _title = _x select 2;
        _size = (_x select 3) * 32;
        _dir = 0;
        _alpha = 0.75;
        _texture = format [BIS_fnc_strategicMapOpen_missionIcon,_textureAnimPhase,_forEachindex + 1];

        //--- Icon is under cursor
        if ((_pos distance _mousePos) < (_mouseLimit * _size)) then {
            _size = _size * 1.2;
            _alpha = 1;
            _selected = _x;
        };

        //--- Outside of the screen area
        _mappos = _map ctrlMapWorldToScreen _pos;
        _mapposX = _mappos select 0;
        _mapposY = _mappos select 1;

        _borderLeft = safeZoneX;
        _borderRight = safeZoneX + safeZoneW;
        _borderTop = safeZoneY;
        _borderBottom = safeZoneY + safeZoneH;

        if (
            _mapposX < _borderLeft || _mapposX > _borderRight
            ||
            _mapposY < _borderTop || _mapposY > _borderBottom
        ) then {
            _texture = getText (configFile >> "CfgInGameUI" >> "Cursor" >> "outArrow");
            _mapposX = _mapposX max safeZoneX min (safeZoneX + safeZoneW);
            _mapposY = _mapposY max safeZoneY min (safeZoneY + safeZoneH);
            _title = "";

            _offset = (_size / 1200);
            _offsetDefX = _offset;
            _offsetDefY = _offset * 4/3;
            _offsetX = 0;
            _offsetY = 0;
            _dir = -([[0.5,0.5],_mappos] call bis_fnc_dirto) - 90;

            switch (true) do {
                case (_mapposX <= _borderLeft): {
                    _offsetX = +_offsetDefX;
                    _mapposY = _mapposY min (_borderBottom - _offsetDefY) max (_borderTop + _offsetDefY);
                };
                case (_mapposX >= _borderRight): {
                    _offsetX = -_offsetDefX;
                    _mapposY = _mapposY min (_borderBottom - _offsetDefY) max (_borderTop + _offsetDefY);
                };
                case (_mapposY <= _borderTop): {
                    _offsetY = +_offsetDefY;
                    _mapposX = _mapposX min (_borderRight - _offsetDefX) max (_borderLeft + _offsetDefX);
                };
                case (_mapposY >= _borderBottom): {
                    _offsetY = -_offsetDefY;
                    _mapposX = _mapposX min (_borderRight - _offsetDefX) max (_borderLeft + _offsetDefX);
                };
            };

            _pos = _map ctrlMapScreenToWorld [
                _mapposX + _offsetX,
                _mapposY + _offsetY
            ];
        };

        _map drawIcon [
            _texture,
            [1,1,1,_alpha],
            _pos,
            _size,
            _size,
            _dir,
            if (BIS_fnc_strategicMapOpen_showIconText) then {" " + _title} else {""},
            2,
            0.08,
            "PuristaBold"
        ];
    } forEach BIS_fnc_strategicMapOpen_missions;

    //--- Night
    if (BIS_fnc_strategicMapOpen_isNight) then {
        _map drawRectangle [
            [_mapSize,_mapSize,0],
            99999,
            99999,
            0,
            [0,0.05,0.2,0.42],
            "#(argb,8,8,3)color(1,1,1,1)"
        ];
    };

    //--- Tooltip
    if (count _selected > 0 && !BIS_fnc_strategicMapOpen_mouseClickDisable) then {
        switch (count _selected) do {

            //--- ORBAT
            case 4: {
                _class = _selected select 0;
                _classParams = _selected select 3;

                [_classParams,_display,BIS_fnc_strategicMapOpen_mousePos] call bis_fnc_ORBATTooltip;
            };

            //--- Mission
            case 10;
            case 9: {
                [_selected,_display,BIS_fnc_strategicMapOpen_mousePos] call bis_fnc_ORBATTooltip;
            };
        };
    } else {
        [[],_display] call bis_fnc_ORBATTooltip;
    };
    _info ctrlCommit 0;
    BIS_fnc_strategicMapOpen_selected = _selected;
};

//--- Mouse click on icon
BIS_fnc_strategicMapOpen_mouseClickDisable = false;
BIS_fnc_strategicMapOpen_selected = [];
BIS_fnc_strategicMapOpen_mousePos = [0,0];
BIS_fnc_strategicMapOpen_mouse = {
    BIS_fnc_strategicMapOpen_mousePos = [_this select 1,_this select 2];
};

#define DIK_H               0x23
#define DIK_NUMPAD5         0x4C

BIS_fnc_strategicMapOpen_keyDown = {
    _display = _this select 0;
    _key = _this select 1;

    //--- H
    switch _key do {
        case DIK_H: {
            _fade = ceil ctrlFade (_display displayCtrl 2);
            _fade = (_fade + 1) % 2;
            {
                (_display displayCtrl _x) ctrlSetFade _fade;
                (_display displayCtrl _x) ctrlCommit 0.3;
            } forEach [2,1000,1500,2350,2301];
        };
        case DIK_NUMPAD5: {
            [BIS_fnc_strategicMapOpen_mapCenter,1] spawn bis_fnc_strategicMapAnimate;
        };
    };
    false
};


_map = _display displayCtrl 51;
_map ctrlMapAnimAdd [0,_scale,_mapCenter];
ctrlMapAnimCommit _map;
BIS_fnc_strategicMapOpen_mapCenter = _mapCenter;

_map ctrlAddEventHandler ["Draw","_this call BIS_fnc_strategicMapOpen_draw;"];
_map ctrlAddEventHandler ["MouseMoving","_this call BIS_fnc_strategicMapOpen_mouse;"];
_map ctrlAddEventHandler ["MouseHolding","_this call BIS_fnc_strategicMapOpen_mouse;"];
_map ctrlAddEventHandler ["MouseButtonDblClick","[nil,_this] spawn BIS_fnc_strategicMapMouseButtonClick;"];
_display displayAddEventHandler ["KeyDown","_this call BIS_fnc_strategicMapOpen_keyDown"];

if (_isNight) then {
    _map ctrlSetBackgroundColor [0,0,0,1];
    _map ctrlCommit 0;
};

//--- Measure
[_display] spawn {
    disableSerialization;
    _display = _this select 0;
    _showMiles = false;

    _map = _display displayCtrl 51;
    waitUntil {ctrlMapAnimDone _map};

    _xStart = (_map ctrlMapWorldToScreen [0,0,0]) select 0;
    _xEnd = (_map ctrlMapWorldToScreen [1000,0,0]) select 0;
    _w1km = abs (_xstart - _xEnd);
    _w1m = _w1km * 1.60934;
    if !(_showMiles) then {_w1m = 0.01};
    _h = 0.01;

    _measure = _display displayCtrl 2301;
    _measure ctrlSetPosition [
        safeZoneX + 0.02125,
        safeZoneY + safeZoneH - 3.5 * 0.04,
        1,
        _h * 5
    ];
    //_measure ctrlSetFade 0.25;
    _measure ctrlCommit 0;
    _measure ctrlEnable false;

    _colors = ["#(argb,8,8,3)color(0,0,0,1)","\A3\Ui_f\data\GUI\Rsc\RscDisplayStrategicMap\measure_ca.paa"];
    _kmSegment = _w1km / 5;
    for "_i" from 0 to 4 do {
        _km = _display displayCtrl (1200 + _i);
        _km ctrlSetText (_colors select (_i % 2));
        _km ctrlSetPosition [
            _w1m + _kmSegment * _i,
            _h,
            _kmSegment,
            _h
        ];
        _km ctrlCommit 0;
    };

    _text_0 = _display displayCtrl 1002;
    _text_0 ctrlSetPosition [
        _w1m - _w1km,
        _h * 3,
        2 * _w1km,
        _h * 2
    ];
    _text_0 ctrlCommit 0;
    _text_km = _display displayCtrl 1004;
    _text_km ctrlSetPosition [
        _w1m - _w1km + (safeZoneH / 30),
        _h * 3,
        2 * _w1km,
        _h * 2
    ];
    _text_km ctrlCommit 0;

    if (_showMiles) then {
        _m0 = _display displayCtrl 1205;
        _m0 ctrlSetText "#(argb,8,8,3)color(1,1,1,1)";
        _m0 ctrlSetPosition [
            0,
            _h,
            _w1m,
            _h
        ];
        _m0 ctrlCommit 0;
        _text_m = _display displayCtrl 1003;
        _text_m ctrlSetPosition [
            0,
            _h * 3,
            2 * _w1m,
            _h * 2
        ];
        _text_m ctrlCommit 0;
    };
};

//--- Show markers
{
    _x setMarkerAlphaLocal 1;
} forEach _markers;
BIS_fnc_strategicMapOpen_markers = _markers;

//--- Fade in
_fade = _display displayCtrl 1099;
_fade ctrlSetFade 1;
_fade ctrlCommit 2;

//--- Garbage collector
_display displayAddEventHandler [
    "Unload",
    "
        {
            _x setMarkerAlphaLocal 0;
        } forEach BIS_fnc_strategicMapOpen_markers;

        BIS_fnc_strategicMapOpen_player = nil;
        BIS_fnc_strategicMapOpen_mapSize = nil;
        BIS_fnc_strategicMapOpen_mapCenter = nil;
        BIS_fnc_strategicMapOpen_isNight = nil;
        BIS_fnc_strategicMapOpen_ORBAT = nil;
        BIS_fnc_strategicMapOpen_ORBATOverlay = nil;
        BIS_fnc_strategicMapOpen_missions = nil;
        BIS_fnc_strategicMapOpen_markers = nil;
        BIS_fnc_strategicMapOpen_images = nil;
        BIS_fnc_strategicMapOpen_draw = nil;
        BIS_fnc_strategicMapOpen_clouds = nil;
        BIS_fnc_strategicMapOpen_mousePos = nil;
        BIS_fnc_strategicMapOpen_mouseClickDisable = nil;
        BIS_fnc_strategicMapOpen_selected = nil;
        BIS_fnc_strategicMapOpen_indexSizeTexture = nil;
        BIS_fnc_strategicMapOpen_indexTextureSize = nil;
        with uiNamespace do {
            RscDisplayStrategicMap_scaleMin = nil;
            RscDisplayStrategicMap_scaleMax = nil;
            RscDisplayStrategicMap_scaleDefault = nil;

            RscDisplayStrategicMap_colorOutside_R = nil;
            RscDisplayStrategicMap_colorOutside_G = nil;
            RscDisplayStrategicMap_colorOutside_B = nil;
        };
    "
];

cutText ["","black in"];
_display
