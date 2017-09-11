/*
 * Author: Cuel
 * JIP and respawn manager
 *
 * Arguments:
 * 0 - mode. for now only "amount" works
 * 1 - lives, how many respawns
 * 2 - spectate timer. time spent in spectator between respawns
 *
 * Public: Yes
 */
#include "script_component.hpp"
params [
    ["_mode", "amount", [""]],
    ["_lives", -1, [0]],
    ["_spectateTimer", -1, [0]]
];

if (RETDEF(GVAR(jrmInit),false)) exitWith {false};
GVAR(jrmInit) = true;

if (isServer) then {
    GVAR(jrmState) = [[], []] call CBA_fnc_hashCreate;

    addMissionEventHandler ["PlayerConnected", {
        params ["", "_uid", "_name", "", "_owner"];
        private _state = [GVAR(jrmState), _name] call CBA_fnc_hashGet;
        if (_state isEqualTo []) exitWith {};
        [QGVAR(jrmCheckSettings), _state, _owner] call CBA_fnc_ownerEvent;
    }];
};

if (hasInterface) then {
    // increase _lives here to not having to worry about 0 and -1 when reconnecting
    _lives = [_lives + 1, -1] select (_lives < 0);

    GVAR(jrmSettings) = [_mode, _lives, _spectateTimer];
    GVAR(remainingLives) = RETDEF(GVAR(remainingLives),_lives);

    player addEventHandler ["Killed", {
        GVAR(jrmSettings) params ["_mode", "_lives", "_spectateTimer"];
        if (_lives < 0 && {_spectateTimer < 0}) exitWith {};

        GVAR(remainingLives) = [GVAR(remainingLives) - 1 max 0, -1] select (_lives < 0);
        [QGVAR(jrmOnPlayerDeath), [name player, GVAR(remainingLives), CBA_missionTime]] call CBA_fnc_serverEvent;

        if (GVAR(remainingLives) isEqualTo 0 || {_spectateTimer > -1}) then {
            [{alive player}, {
                params ["_t"];
                [player] call FUNC(lowerPlayerWeapon);
                [true, [_t, -1] select (GVAR(remainingLives) isEqualTo 0)] call FUNC(spectate);
            }, _spectateTimer] call CBA_fnc_waitUntilAndExecute;
        };
    }];
};

true
