/*
 * Author: Cuel
 * Init JIP and respawn manager. Call on all clients
 *
 * Arguments:
 * 0 - Amount of respawns before permadeath <number>
 *
 * Public: Yes
 */

#include "script_component.hpp"

if (isServer && {!RETDEF(GVAR(initialized),false)}) then {

    GVAR(state) = [true] call CBA_fnc_createNamespace;
    publicVariable QGVAR(state);

    addMissionEventHandler ["PlayerDisconnected", {
        params ["", "_uid"];
        private _unit = allPlayers select {getPlayerUID _x == _uid} param [0, objNull];
        if (_unit getVariable ["ACE_isUnconscious", false]) then {
            (GVAR(state) getVariable [_uid, []]) params [["_prevDeaths", 0]];
            GVAR(state) setVariable [_uid, [_prevDeaths + 1, CBA_missionTime], true];
        };
    }];

    GVAR(initialized) = true;
};

if (hasInterface) then {
    params [["_respawns", -1]];
    GVAR(respawns) = _respawns;

    if (didJIP && {!isNil QGVAR(state)}) then {
        [{!isNull player}, {
            (GVAR(state) getVariable [getPlayerUID player, []]) params [["_deaths", 0], ["_timeOfDeath", 0]];
            if (GVAR(respawns) >= 0 && {_deaths > GVAR(respawns)}) then {
                [true] call EFUNC(common,spectate);
                [QGVAR(onPermaDeath), [_deaths, _timeOfDeath, true]] call CBA_fnc_localEvent;
            };
        }] call CBA_fnc_waitUntilAndExecute;
    };

    if (!isNil "Ares_fnc_RegisterCustomModule") then {
        private _res = "FP - Respawn";

        [_res, "Respawn ALL units at pos", {
            params ["_pos"];
            private _players = [] call ace_spectator_fnc_players;
            if (count _players == 0) exitWith {["ERROR: No dead players"] call ares_fnc_ShowZeusMessage};
            [_pos] remoteExecCall [QFUNC(forceRespawn)];
            ["Respawned %1 players at %2", count _players, mapGridPosition _pos] call ares_fnc_ShowZeusMessage;
        }] call Ares_fnc_RegisterCustomModule;

        [_res, "Respawn SINGLE unit at pos", {
            params ["_pos", "_obj"];

            private _players = [] call ace_spectator_fnc_players;
            if (count _players == 0) exitWith {["ERROR: No dead players"] call ares_fnc_ShowZeusMessage};
            private _names = _players apply {name _x};

            private _args = ["Respawn single unit", [
                ["Player", _names, 0]
            ]] call Ares_fnc_ShowChooseDialog;
            if (count _args == 0) exitWith {};

            private _plr = _players param [_args select 0, objNull];
            if (isNull _plr) exitWith {["ERROR: Unable to find player"] call ares_fnc_ShowZeusMessage};

            [_pos] remoteExecCall [QFUNC(forceRespawn), _plr];
            ["Respawned %1 at %2", name _plr, mapGridPosition _pos] call ares_fnc_ShowZeusMessage;
        }] call Ares_fnc_RegisterCustomModule;

        [_res, "Respawn in vehicle cargo", {
            private _veh = param [1, objNull];
            if (isNull _veh) exitWith {["ERROR: Select vehicle with cargo"] call ares_fnc_ShowZeusMessage};

            private _maxAmount =  (_veh emptyPositions "cargo");
            private _plrs = [] call ace_spectator_fnc_players;

            if (_maxAmount <= 0 || {_plrs isEqualTo []}) exitWith {["ERROR: No cargo slots / no dead players"] call ares_fnc_ShowZeusMessage};
            _plrs = _plrs select [0, _maxAmount];

            private _code = {
                [false] call EFUNC(common,spectate);
                GVAR(moveInCargoWait) = CBA_missionTime + 6;
                [{
                    params ["_args", "_id"];
                    _args params [["_veh", objNull]];

                    if (!alive _veh || {vehicle player == _veh} || {CBA_missionTime > GVAR(moveInCargoWait)}) exitWith {
                        GVAR(moveInCargoWait) = nil;
                        [_id] call CBA_fnc_removePerFrameHandler;
                    };

                    player assignAsCargo _veh;
                    player moveInCargo _veh;
                }, 0.1, _this] call CBA_fnc_addPerFrameHandler;
            };

            [_veh, _code] remoteExecCall ["BIS_fnc_call", _plrs];
            ["Moved %1 players into cargo", count _plrs] call ares_fnc_ShowZeusMessage;
        }] call Ares_fnc_RegisterCustomModule;
    };
};
