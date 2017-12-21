#include "script_component.hpp"

if (isMultiplayer) then {
    addMissionEventHandler ["PlayerConnected",{
        private _owner = param [4, 0];
        if (_owner isEqualTo 0 || {CBA_missionTime < 5}) exitWith {};
        [] remoteExecCall [QFUNC(checkMods), _owner];
    }];

    [{CBA_missionTime > 5}, {
        [] remoteExecCall [QFUNC(checkMods), -2];
    }] call CBA_fnc_waitUntilAndExecute;
};
