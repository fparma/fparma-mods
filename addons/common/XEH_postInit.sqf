#include "script_component.hpp"
#include "\A3\Ui_f\hpp\defineResinclDesign.inc"
#include "\z\ace\addons\arsenal\defines.hpp"

[missionNamespace, "arsenalOpened", {
    disableSerialization;
    params [["_display", displayNull]];
    private _btn = (_display displayCtrl IDC_RSCDISPLAYARSENAL_CONTROLSBAR_BUTTONEXPORT);
    [_btn, _display, _display displayCtrl IDC_RSCDISPLAYARSENAL_CONTROLSBAR_CONTROLBAR] call FUNC(overrideArsenalExport);
}] call BIS_fnc_addScriptedEventHandler;

["ace_arsenal_displayOpened", {
    [{
        private _display = findDisplay IDD_ace_arsenal;
        private _text = localize "STR_ACE_Arsenal_buttonExportText";
        {
            if (ctrlText _x isEqualTo _text) exitWith {
                [_x, _display, _display displayCtrl IDC_menuBar] call FUNC(overrideArsenalExport);
            };
        } forEach (allControls _display);
    }] call CBA_fnc_execNextFrame;
}] call CBA_fnc_addEventHandler;


if (isServer) then {
    [] call FUNC(trackKills);

    GVAR(chatChannel) = radioChannelCreate [[0.9,0.1,0.1,1], "Chat", "Chat", [], true];
    publicVariable QGVAR(chatChannel);
};

if (isDedicated) then {
	[{
        GVAR(performanceChecks) = [
            [{diag_fps < 12}, {format ["fpw is low: %1.", round diag_fps]}],
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

#include "commands_admins.sqf"
#include "commands_clients.sqf"
