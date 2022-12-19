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

    addMissionEventHandler ["HandleChatMessage", {
        call FUNC(handleChatMessage);
    }];

    [QGVAR(chatOpened), {
        params ["_display"];
        [_display] call FUNC(onChatOpen);
    }] call CBA_fnc_addEventHandler;

    [QGVAR(chatClosed), {
        params ["_display"];
        [_display] call FUNC(onChatClose);
    }] call CBA_fnc_addEventHandler;
};

GVAR(acreTalking) = [];
["acre_remoteStartedSpeaking", {
    GVAR(acreTalking) pushBackUnique (_this select 0);
    _this call FUNC(fpDuplex);
    _this call FUNC(acreShowReiceiverHint);
}] call CBA_fnc_addEventHandler;

["acre_remoteStoppedSpeaking", {
    params ["_unit"];
    GVAR(acreTalking) = GVAR(acreTalking) - [_unit, objNull];
    [QGVAR(removeAcreReceiverHint), [name _unit]] call CBA_fnc_localEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(removeAcreReceiverHint), {
    params ["_name"];
    [format ["%1$%2", QGVAR(acre), _name]] call acre_sys_list_fnc_hideHint;
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

if (GVAR(arsenalAddMedicalTab)) then {
    [
        ["FirstAidKit","Medikit","ACE_adenosine","ACE_fieldDressing","ACE_elasticBandage","ACE_packingBandage","ACE_quikclot","ACE_SterileGauze","ACE_bodyBag","gm_ge_army_burnBandage","ACE_EarPlugs","ACE_epinephrine","Empty_bloodIV_250","Empty_bloodIV_500","ACE_morphine","ACE_plasmaIV","ACE_plasmaIV_250","ACE_plasmaIV_500","ACE_salineIV","ACE_salineIV_250","ACE_salineIV_500","ACE_splint","ACE_surgicalKit","ACE_tourniquet",QEGVAR(medical,vital)],
        "Medical",
        "\z\ace\addons\medical_gui\data\categories\medication.paa"
    ] call ace_arsenal_fnc_addRightPanelButton;
};

if (GVAR(arsenalAddAcreTab)) then {
    private _radios = [];
    {
        _radios pushBack _x;
        for "_i" from 1 to 512 do {
            _radios pushBack (format ["%1_ID_%2", _x, _i]);
        };
    } forEach [
        "ACRE_BF888S",
        "ACRE_PRC117F",
        "ACRE_PRC148",
        "ACRE_PRC152",
        "ACRE_PRC343",
        "ACRE_PRC77",
        "ACRE_SEM52SL",
        "ACRE_SEM70"
    ];
    [
        _radios,
        "Radios",
        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Radio_ca.paa"
    ] call ace_arsenal_fnc_addRightPanelButton;
};

if (GVAR(enableViewdistanceSelector)) then {
    private _actDistCat = ["ViewDist","View distance","",{},{}] call ace_interact_menu_fnc_createAction;
    [typeOf player, 1, ["ACE_SelfActions"], _actDistCat] call ace_interact_menu_fnc_addActionToClass;
    _actDistCat = ["OverallDist","Overall","",{},{}] call ace_interact_menu_fnc_createAction;
    [typeOf player, 1, ["ACE_SelfActions","ViewDist"], _actDistCat] call ace_interact_menu_fnc_addActionToClass;
    _actDistCat = ["ObjectDist","Object","",{},{}] call ace_interact_menu_fnc_createAction;
    [typeOf player, 1, ["ACE_SelfActions","ViewDist"], _actDistCat] call ace_interact_menu_fnc_addActionToClass;
    _actDistCat = ["BothtDist","Both","",{},{}] call ace_interact_menu_fnc_createAction;
    [typeOf player, 1, ["ACE_SelfActions","ViewDist"], _actDistCat] call ace_interact_menu_fnc_addActionToClass;

    private _min = GVAR(viewdistanceMaximum) min GVAR(viewdistanceMinimum);
    private _max = GVAR(viewdistanceMaximum) max GVAR(viewdistanceMinimum);

    for "_i" from _min to _max step 250 do {
        private _iStr = str _i;
        private _action = [_iStr,_iStr,"",{
            params ["", "", "_dist"];
            setViewDistance _dist
        },{viewDistance isNotEqualTo (_this select 2)}, nil, _i] call ace_interact_menu_fnc_createAction;
        [typeOf player, 1, ["ACE_SelfActions","ViewDist","OverallDist"], _action] call ace_interact_menu_fnc_addActionToClass;
        _action = [_iStr,_iStr,"",{
            params ["", "", "_dist"];
            setObjectViewDistance _dist
        },{(getObjectViewDistance select 0) isNotEqualTo (_this select 2)}, nil, _i] call ace_interact_menu_fnc_createAction;
        [typeOf player, 1, ["ACE_SelfActions","ViewDist","ObjectDist"], _action] call ace_interact_menu_fnc_addActionToClass;
        private _action = [_iStr,_iStr,"",{
            params ["", "", "_dist"];
            setViewDistance _dist;
            setObjectViewDistance _dist
        },{viewDistance isNotEqualTo (_this select 2) || {(getObjectViewDistance select 0) isNotEqualTo (_this select 2)}}, nil, _i] call ace_interact_menu_fnc_createAction;
        [typeOf player, 1, ["ACE_SelfActions","ViewDist","BothtDist"], _action] call ace_interact_menu_fnc_addActionToClass;
    };
};
