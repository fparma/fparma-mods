/*
* Author: PabstMirror / POTATO for acre/unit count
* Edits by cuel
*/

#include "script_component.hpp"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
#include "\A3\ui_f_curator\ui\defineResinclDesign.inc"

#define IDD_CTRL_ACRE 777550
#define IDD_CTRL_UNIT_COUNT  777551

#define SEARCH_ID 777558
#define ZEUS_SEARCH_BOX ((findDisplay IDD_RSCDISPLAYCURATOR) displayCtrl IDC_RSCDISPLAYCURATOR_CREATE_SEARCH)

#define SEARCH_DEBOUNCE_IN_SEC 0.4

if (isNil QFUNC(toggleZeusAcre)) then {
    FUNC(toggleZeusAcre) = {[!ACRE_IS_SPECTATOR] call acre_api_fnc_setSpectator};
};

// Remove "gear" animation for zeus
[player] call FUNC(lowerPlayerWeapon);

[{
    // hide zeus watermark
    params [["_display", displayNull]];
    if (isNull _display) exitWith {};

    private _ctrlWaterMark = _display displayCtrl IDC_RSCDISPLAYCURATOR_WATERMARK;
    _ctrlWaterMark ctrlSetText ""; //QPATHTOEF(assets,img\logo_lg.paa);

    // Replace search box with a debounced and enter-friendly search box
    private _ctrlSearchBox = _display displayCtrl IDC_RSCDISPLAYCURATOR_CREATE_SEARCH;
    private _ctrl = _display ctrlCreate ["RscEdit", SEARCH_ID, ctrlParentControlsGroup _ctrlSearchBox];
    _ctrl ctrlSetPosition (ctrlPosition _ctrlSearchBox);
    _ctrl ctrlSetScale (ctrlScale _ctrlSearchBox);

    _ctrlSearchBox ctrlShow false;
    _ctrlSearchBox ctrlCommit 0;
    _ctrl ctrlCommit 0;

    _ctrl ctrlAddEventHandler ["KeyUp", {
        params ["_displayCtrl", "_key", "_shift", "_ctrl", "_alt"];
        if (_key in [DIK_RETURN, DIK_NUMPADENTER]) then {
            [RETDEF(GVAR(zeusSearchDebounce),-1)] call CBA_fnc_removePerFrameHandler;
            ZEUS_SEARCH_BOX ctrlSetText (ctrlText _displayCtrl);
        } else {
            if (ctrlText ZEUS_SEARCH_BOX isEqualTo ctrlText _displayCtrl) exitWith {};

            [RETDEF(GVAR(zeusSearchDebounce),-1)] call CBA_fnc_removePerFrameHandler;
            GVAR(zeusSearchDebounce) = [{
                params ["_args", "_id"];
                _args params ["_displayCtrl", "_delay"];

                if (isNull _displayCtrl) exitWith {
                    [_id] call CBA_fnc_removePerFrameHandler;
                };

                if (CBA_missionTIme > _delay) exitWith {
                    [_id] call CBA_fnc_removePerFrameHandler;
                    ZEUS_SEARCH_BOX ctrlSetText (ctrlText _displayCtrl);
                };

            }, 0, [_displayCtrl, CBA_missionTIme + SEARCH_DEBOUNCE_IN_SEC]] call CBA_fnc_addPerFrameHandler;
        };
    }];

    _ctrl ctrlAddEventHandler ["KeyDown", { false }];
    _ctrl ctrlAddEventHandler ["SetFocus", {
        missionNamespace setVariable ["RscDisplayCurator_search", true];
    }];
    _ctrl ctrlAddEventHandler ["KillFocus", {
        missionNamespace setVariable ["RscDisplayCurator_search", false];
    }];
}, _this] call CBA_fnc_execNextFrame;

[{
    params ["_args", "_id"];
    _args params [["_display", displayNull]];

    if (isNull _display) exitWith {
        [_id] call CBA_fnc_removePerFrameHandler;
    };

    if (missionNamespace getVariable ["ACRE_IS_SPECTATOR", false]) then {
        (_display displayCtrl IDD_CTRL_ACRE) ctrlSetTextColor [0,1,0,1];
    } else {
        (_display displayCtrl IDD_CTRL_ACRE) ctrlSetTextColor [1,1,1,1];
    };

    private _unitCtrl = _display displayCtrl IDD_CTRL_UNIT_COUNT;

    // if zeus screenshot mode
    if (ctrlShown (_display displayCtrl IDC_RSCDISPLAYCURATOR_WATERMARK)) exitWith {
        _unitCtrl ctrlShow false;
    };

    private _units = allUnits select {simulationEnabled _x && {_x != player}};
    private _text = format ["AI: %1 (%2 loc). Plrs: %3 (%4 spec)",
        {!isPlayer _x} count _units,
        {local _x} count _units,
        count call CBA_fnc_players,
        count call ace_spectator_fnc_players
    ];

    _unitCtrl ctrlShow true;
    _unitCtrl ctrlSetText _text;
}, 0.5, _this] call CBA_fnc_addPerFrameHandler;
