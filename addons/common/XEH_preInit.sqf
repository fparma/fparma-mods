
#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(vehicleNames) = [];

[
    QGVAR(ragdolling), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Enable ragdolling", "Enables ragdolling for players upon going unconscious"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    FP_SETTINGS, // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    false, // data for this setting
    true, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {
        params ["_value"];
        if (_value isEqualTo true) then {
            if(!hasInterface) exitWith {};
            ["ace_unconscious", {
                params [["_unit", objNull],["_state", false]];
                if(_unit != player) exitWith {}; // only ragdoll players
                if(_state && {vehicle _unit == _unit && {!([_unit] call ace_medical_fnc_isBeingCarried) && {!([_unit] call ace_medical_fnc_isBeingDragged)}}}) then {
                    // ragdoll player
                    _unit setUnconscious true;
                };
                if(!_state) then {
                    // player woke up before ragdolling was finished
                    _unit setUnconscious false;
                };
            }] call CBA_fnc_addEventHandler;
            player addEventHandler ["AnimChanged", {
                params ["_unit","_anim"];
                if(_anim == "unconsciousrevivedefault" && {alive _unit && {_unit getVariable ["ACE_isUnconscious",false] && {vehicle _unit == _unit}}}) then {
                    // unit stopped ragdolling, apply ace_death animation to unit
                    _unit setUnconscious false;
                    [_unit, [_unit] call ace_common_fnc_getDeathAnim, 2, true] call ace_common_fnc_doAnimation;
                    if(isMultiplayer) then {
                        // combat sync issues
                        [_unit] spawn {
                            params["_unit"];
                            sleep 5;
                            // in some cases the server does not sync that a unit is up and running or still down but with wrong animations, so reapply some things
                            if(!(_unit getVariable ["ACE_isUnconscious",false])) then {
                                // unit is not unconscious anymore
                                _unit setUnconscious false;
                            } else {
                                // unit is still unconscious, reapply death animation just in case and sync it again to all clients
                                [_unit, [_unit] call ace_common_fnc_getDeathAnim, 2, true] call ace_common_fnc_doAnimation;
                            };
                        };
                    };
                };
            }];
            player createDiaryRecord ["CBA_docs", ["Ragdolling", "Ragdolling has been activated in this mission! Better check those bodies!"]];
        };
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    QGVAR(displayVehicleNamesSetting), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Display vehicle names", "Mission makers may enable 3d vehicle names for easier identification"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    FP_SETTINGS, // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
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
] call CBA_Settings_fnc_init;

[
    QGVAR(customChatPingSound), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Custom chat ping", "Play a notification sound when sending whispers or receiving custom chat"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    FP_SETTINGS, // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    true, // data for this setting
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_Settings_fnc_init;

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
