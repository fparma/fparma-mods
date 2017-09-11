#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(overrideArsenalExport) = false;
GVAR(isWeaponsDisabled) = false;
GVAR(preloadFinished) = false;
GVAR(vehicleNames) = [];

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

GVAR(preloadId) = addMissionEventHandler ["PreloadFinished", {
    GVAR(preloadFinished) = true;
    removeMissionEventHandler ["PreloadFinished", GVAR(preloadId)];
    GVAR(preloadId) = nil;
    diag_log format ["preload finished %1", diag_tickTime];
    {
        _x params ["_args", "_code"];
        _args call _code;
    } forEach RETDEF(GVAR(runAfterPreload),[]);
    GVAR(runAfterPreload) = nil;
}];

[QGVAR(jrmCheckSettings), {
    [{!isNil QGVAR(jrmInit)}, {
        params ["_remainingLives", "_timeOfDeath"];
        GVAR(jrmSettings) params ["_mode", "_lives", "_spectateTimer"];
        TRACE_3("Connected", _remainingLives, _timeOfDeath, GVAR(jrmSettings));
        if (_lives < 0 && {_spectateTimer < 0}) exitWith {};

        GVAR(remainingLives) = _remainingLives;
        private _timeRemaining = (_timeOfDeath + _spectateTimer) - CBA_missionTime;
        TRACE_1("Time remaining", _timeRemaining);

        if (_spectateTimer > -1 && {(_timeRemaining - 10) > 0}) then {
            private _t = [_timeRemaining, -1] select (_remainingLives isEqualTo 0);
            [true, _t] call FUNC(spectate);
        } else {
            if (_lives > -1 && {_remainingLives isEqualTo 0}) then {
                [true] call FUNC(spectate);
            };
        };
    }, _this] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

if (isServer) then {
    [QGVAR(jrmOnPlayerDeath), {
        params ["_uid", "_lives", "_spectateTimer"];
        [GVAR(jrmstate), _uid, [_lives, _spectateTimer]] call CBA_fnc_hashSet;
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
