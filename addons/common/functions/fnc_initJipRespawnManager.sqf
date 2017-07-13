/*
 * Author: Cuel
 * JIP and respawn manager
 *
 * Arguments:
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

if (isServer) then {
    GVAR(jrmState) = [[], []] call CBA_fnc_hashCreate;

    addMissionEventHandler ["PlayerConnected", {
        params ["", "_uid", "", "", "_owner"];
        private _state = [GVAR(jrmstate), _uid] call CBA_fnc_hashGet;
        if (_state isEqualTo []) exitWith {};
       [QGVAR(jrmCheckSettings), _state, _owner] call CBA_fnc_ownerEvent;
    }];
};

if (hasInterface) then {
    GVAR(jrmSettings) = [_mode, _lives, _spectateTimer];
    GVAR(remainingLives) = RETDEF(GVAR(remainingLives),_lives);

    player addEventHandler ["Killed", {
        GVAR(jrmSettings) params ["_lives", "_spectateTimer"];
        if (_lives isEqualTo -1 && {_spectateTimer isEqualTo -1}) exitWith {};

        GVAR(remainingLives) = [(GVAR(remainingLives) - 1) max 0, -1] select (_lives isEqualTo -1);
        [QGVAR(jrmOnPlayerDeath), [getPlayerUID player, GVAR(remainingLives), CBA_missionTime]] call CBA_fnc_serverEvent;

        if (GVAR(remainingLives) isEqualTo 0 || {_spectateTimer > -1}) then {
            [true, [_spectateTimer, -1] select (GVAR(remainingLives) isEqualTo 0)] call FUNC(spectate);
        };
    }];
};

GVAR(jrmInit) = true;
