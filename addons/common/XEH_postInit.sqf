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
    GVAR(chatChannel) = radioChannelCreate [[0.9,0.1,0.1,1], "Chat", "Chat", [], true];
    publicVariable QGVAR(chatChannel);
	
	GVAR(performanceChecks) = [
        [{diag_fps < 20}, {format ["fpw is low: %1.", diag_fps]}],
        [{
            count (allUnits select {simulationEnabled _x && !isPlayer _x}) > 120
        }, {"a lot of active AI (>120)"}],
        [{count allGroups > 125}, {"a lot of groups (>125)"}],
        [{count allDead > 50}, {"a lot of corpses (>50)"}]
    ];
    
    GVAR(performancePfh) = [{
        (GVAR(performanceChecks) deleteAt 0) params ["_condition", "_msg"];
        if (call _condition) then {
            [QGVAR(chatMessage), ["SERVER", call _msg, "server", nil, false]] call CBA_fnc_globalEvent;
        };
        GVAR(performanceChecks) pushBack [_condition, _msg];
    }, 20, []] call CBA_fnc_addPerFrameHandler;
};

#include "commands_admins.sqf"
#include "commands_clients.sqf"
