
#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(vehicleNames) = [];
GVAR(admins) = compileFinal str (getArray (configFile >> QGVAR(admins)));

[
    QGVAR(displayVehicleNamesSetting), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Display vehicle names", "Mission makers may enable 3d vehicle names for easier identification"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [FP_SETTINGS, "General"], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    true, // data for this setting
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {
        params ["_value"];
        if (_value isEqualTo false) then {
            removeMissionEventHandler ["Draw3D", RETDEF(GVAR(drawNamesId),-1)];
            GVAR(drawNamesId) = nil;
        } else {
            [] call FUNC(runVehicleDrawEH);
        };
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_fnc_addSetting;

[
    QGVAR(customChatPingSound), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Custom chat ping", "Play a notification sound when sending whispers or receiving custom chat"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [FP_SETTINGS, "General"], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    true, // data for this setting
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    QGVAR(useFpDuplex),
    "CHECKBOX",
    ["Use FP Duplex", "Displays message if stepping on or being stepped on while talking on long range radio. Makes sender who spoke first stop transmitting."],
    [FP_SETTINGS, "ACRE"],
    true,
    true
] call CBA_fnc_addSetting;

[
    QGVAR(fpDuplexCutOffTransmission),
    "CHECKBOX",
    ["Make FP duplex end transmission", ""],
    [FP_SETTINGS, "ACRE"],
    true,
    true
] call CBA_fnc_addSetting;

[
    QGVAR(showReiceiverHint),
    "CHECKBOX",
    ["Show message receive hint", "Shows an ACRE hint box detailing who is currently sending a message onto your radio"],
    [FP_SETTINGS, "ACRE"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(showReiceiverHintColorLR),
    "COLOR",
    ["Receiver hint color LR", "Color for long range receiving hint"],
    [FP_SETTINGS, "ACRE"],
    [0.5, 1.0, 0, 0.8],
    false
] call CBA_fnc_addSetting;

[
    QGVAR(showReiceiverHintColorSR),
    "COLOR",
    ["Receiver hint color SR", "Color for short range receiving hint"],
    [FP_SETTINGS, "ACRE"],
    [0.8, 0.5, 1.0, 0.8],
    false
] call CBA_fnc_addSetting;

[
    QGVAR(arsenalAddMedicalTab),
    "CHECKBOX",
    "Add medical tab",
    [FP_SETTINGS, "Arsenal"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(arsenalAddAcreTab),
    "CHECKBOX",
    "Add radio tab",
    [FP_SETTINGS, "Arsenal"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(disableRHSStartUp),
    "CHECKBOX",
    "Disable RHS engine start up",
    [FP_SETTINGS, "General"],
    true,
    true
] call CBA_fnc_addSetting;

[
    QGVAR(enableViewdistanceSelector),
    "CHECKBOX",
    "Enable Viewdistance Selector",
    [FP_SETTINGS, "View Distance"],
    true,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(viewdistanceMinimum), "SLIDER",
    ["Minimum Value", "Must be set before mission, cannot change during mission!"],
    [FP_SETTINGS, "View Distance"],
    [250, 10000, 500, 0],
    false
] call CBA_fnc_addSetting;

[
    QGVAR(viewdistanceStep), "SLIDER",
    ["Value Step", "Must be set before mission, cannot change during mission!"],
    [FP_SETTINGS, "View Distance"],
    [100, 1000, 500, 0],
    false
] call CBA_fnc_addSetting;

[
    QGVAR(viewdistanceMaximum), "SLIDER",
    ["Maximum Value", "Must be set before mission, cannot change during mission!"],
    [FP_SETTINGS, "View Distance"],
    [250, 10000, 5000, 0],
    false
] call CBA_fnc_addSetting;

[QGVAR(endMission), {
    if (!isNil QGVAR(ending)) exitWith {};
    GVAR(ending) = true;

    params [["_args", []]];
    private _ending = "End1";
    private _won = true;

    if (_args isEqualType "") then {
        _ending = _args;
    } else {
        {
            if (_x isEqualType "") then {
                _ending = _x param [0, "End1"];
                _won = _x param [1, true];
            } else {
                if (_x isEqualType []) then {
                    private _side = _x param [2, sideUnknown];
                    if (side group player == _side) then {
                        _ending = _x param [0, "End1"];
                        _won = _x param [1, true];
                    };
                };
            };
        } forEach _args;
    };

    [true] call FUNC(disableWeapons);
    [_ending, _won] call BIS_fnc_endMission;
}] call CBA_fnc_addEventHandler;

ADDON = true;
