#include "script_component.hpp"

params ["_saveName","_mapName",["_markersData",[]]];

if (_mapName != worldName) exitWith {
    playSound "3DEN_notificationWarning";
    systemChat format ["fpa-saveMarkers: Save with name ""%1"" is made for map ""%2"" but we are on ""%3""!", _saveName, _mapName, worldName];
};

// client who loads markers will be owner
private _playerID = getPlayerID player;
private _markerIDIndex = 0;

{
    _x params [
        "_alpha",
        "_brush",
        "_color",
        "_dir",
        "_pos",
        "_shape",
        "_size",
        "_text",
        "_type",
        "_channel",
        ["_polyline",[]]
    ];

    // _channel is type string in legacy saves
    if (_channel isEqualType "") then {
        _channel = call compile _channel;
    };

    // increment marker index until unused _markerID is found
    private _markerID = format ["_USER_DEFINED #%1/%2/%3",_playerID,_markerIDIndex,_channel];
    while {markerShape _markerID != ""} do {
        _markerIDIndex = _markerIDIndex + 1;
        _markerID = format ["_USER_DEFINED #%1/%2/%3",_playerID,_markerIDIndex,_channel];
    };

    private _marker = createMarker [_markerID,_pos,_channel,player];
    _marker setMarkerAlphaLocal _alpha;
    _marker setMarkerBrushLocal _brush;
    _marker setMarkerColorLocal _color;
    _marker setMarkerDirLocal _dir;
    _marker setMarkerPosLocal _pos;
    _marker setMarkerShapeLocal _shape;
    _marker setMarkerSizeLocal _size;
    _marker setMarkerTextLocal _text;
    if (count _polyline > 0) then {
        _marker setMarkerPolylineLocal _polyline;
    };
    _marker setMarkerType _type;

} forEach _markersData;
