#include "script_component.hpp"
#include "\A3\Ui_f\hpp\defineResinclDesign.inc"
#include "\z\ace\addons\arsenal\defines.hpp"

if (!hasInterface) exitWith {};

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

#include "commands_admins.sqf"
#include "commands_clients.sqf"
