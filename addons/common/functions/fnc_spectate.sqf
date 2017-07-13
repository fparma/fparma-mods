#include "script_component.hpp"
if (!hasInterface) exitWith {};

private _code = {
    params [["_spectate", false, [false]], ["_autoExitTimer", -1, [0]]];
    [player, _spectate] call ace_spectator_fnc_stageSpectator;
    [_spectate] call ace_spectator_fnc_setSpectator;

    if (_autoExitTimer > -1) then {
        TRACE_1("Auto exit", _autoExitTimer);
        titleText [format ["Respawning in: %1s", round _autoExitTimer], "PLAIN DOWN"];
        [{[false] call FUNC(spectate)}, [], _autoExitTimer max 2] call CBA_fnc_waitAndExecute;
    };
};

[_code, _this] call FUNC(runAfterPreload);
