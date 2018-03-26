#include "script_component.hpp"

if (isServer) then {
    [] call FUNC(trackKills);

    GVAR(chatChannel) = radioChannelCreate [[0.9,0.1,0.1,1], "Chat", "Chat", [], true];
    publicVariable QGVAR(chatChannel);
};

if (isDedicated) then {
	[{
        GVAR(performanceChecks) = [
            [{diag_fps < 12}, {format ["fps is low: %1.", round diag_fps]}],
            [{
                count (allUnits select {simulationEnabled _x && !isPlayer _x}) > 120
            }, {"a lot of active AI (>120)"}],
            [{count allGroups > 75}, {"a lot of groups (>75)"}],
            [{count allDead > 40}, {"a lot of corpses (>40)"}]
        ];

        GVAR(performancePfh) = [{
            (GVAR(performanceChecks) deleteAt 0) params ["_condition", "_msg"];
            if (call _condition) then {
                [QGVAR(chatMessage), ["SERVER", call _msg, "server", nil, false]] call CBA_fnc_globalEvent;
            };
            GVAR(performanceChecks) pushBack [_condition, _msg];
        }, 30, []] call CBA_fnc_addPerFrameHandler;
    }, 10] call CBA_fnc_waitAndExecute;
};
