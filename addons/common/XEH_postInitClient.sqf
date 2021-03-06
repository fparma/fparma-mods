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

if (isMultiplayer) then {
    ["CBA_loadingScreenDone", {
        [{
            systemChat "Type #fp.help to see available commands!";
        }, [], 5] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;

    if (getPlayerUID player in (call GVAR(admins))) then {
        [true, true] call acre_api_fnc_godModeConfigureAccess;
        [call GVAR(admins), 2, 0] call acre_sys_godmode_fnc_modifyGroup;
        ["Admin", 2] call acre_api_fnc_godModeNameGroup;
    };
};

{
    ["ace_medical_treatment_" + _x, {
        if (lifeState ace_player == "INCAPACITATED") then {
            titleText ["Someone is helping you", "PLAIN DOWN", 2, true, true];
        };
    }] call CBA_fnc_addEventHandler;
} foreach ["bandageLocal", "checkBloodPressureLocal", "cprLocal", "fullHealLocal", "ivBagLocal", "medicationLocal", "splintLocal", "tourniquetLocal"];

["acre_remoteStartedSpeaking", {
    _this call FUNC(remoteStartedSpeaking);
}] call CBA_fnc_addEventHandler;

[QGVAR(acreInterruped), {
    params ["_unit"];
    systemChat format [selectRandom [
        "HEY! You stepped on %1 (%2)!!!",
        "HEY! You cut off %1's (%2) radio message!!!",
        "HEY! I hope this was important becasue %1 (%2) was still talking!!!"
    ], name _unit, groupId (group _unit)];
    playSound "3DEN_notificationWarning";
}] call CBA_fnc_addEventHandler;

// set default speaking step to second lowest
[{time > 0.1}, {
    acre_sys_gui_volumeLevel = 0.25;
    acre_sys_gui_volumeLevel call acre_sys_gui_fnc_setVoiceCurveLevel;
}, []] call CBA_fnc_waitUntilAndExecute;
