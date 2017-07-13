#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(overrideArsenalExport) = false;
GVAR(isWeaponsDisabled) = false;
GVAR(preloadFinished) = false;

GVAR(preloadId) = addMissionEventHandler ["PreloadFinished", {
    GVAR(preloadFinished) = true;
    removeMissionEventHandler ["PreloadFinished", GVAR(preloadId)];
    GVAR(preloadId) = nil;

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
        [_uid, [_lives, _spectateTimer]] call CBA_fnc_hashSet;
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
