#include "script_component.hpp"
#define UTIL "FP - Utils"
#define AI "FP - AI"

[QGVAR(eject), {
    params [["_units", []]];
    {
        _x leaveVehicle (vehicle _x);
        _x action ["Eject", vehicle _x];
    } forEach (_units select {local _x});
}] call CBA_fnc_addEventHandler;

[QGVAR(forceMove), {
  _this call EFUNC(ai,forceMoveWp);
}] call CBA_fnc_addEventHandler;

[QGVAR(driveOnPath), {
    TRACE_1("args", _this);
    params [["_unit", objNull], ["_paths", []]];
    _unit setDriveOnPath _paths;
}] call CBA_fnc_addEventHandler;

INFO_1("Ares loaded: %1", !isNil "Ares_fnc_RegisterCustomModule");
if (!hasInterface || isNil "Ares_fnc_RegisterCustomModule") exitWith {};

[UTIL, "Camera at position", {
    params ["_pos", "_obj"];
    if (!isNull _obj) then {
        _pos = _obj call CBA_fnc_getPos;
    };

    [_pos, true] call EFUNC(common,cameraAtPosition);
}] call Ares_fnc_RegisterCustomModule;

[UTIL, "Eject cargo", {
    params ["", "_veh"];
    if (isNull _veh) exitWith {};
    _veh call FUNC(ejectCargo);
}] call Ares_fnc_RegisterCustomModule;

[UTIL, "Phone buzz IED", {
    params ["_pos"];
    [_pos] call FUNC(proximityIed);
}] call Ares_fnc_RegisterCustomModule;

[UTIL, "Road IED", {
  params ["_pos"];
  private _type = selectRandom ["ACE_ModuleExplosive_IEDLandBig_Range", "ACE_ModuleExplosive_IEDLandBig_Range"];
  private _bomb = createVehicle [_type, _pos, [], 0, "NONE"];
  _bomb call EFUNC(common,addToCurators);
}] call Ares_fnc_RegisterCustomModule;

[UTIL, "Delete IED", {
    params ["", "_obj"];
    if (isNull _obj) exitWith {};
    deleteVehicle _obj;
}] call Ares_fnc_RegisterCustomModule;

[UTIL, "End Mission (COOP)", {
    private _endings = [] call FUNC(getEndings);
    private _args = ["End Mission", [
        ["Ending", _endings apply {_x param [1, ""]}],
        ["Victory", ["Yes", "No"]]
    ]] call Ares_fnc_ShowChooseDialog;
    if (count _args == 0) exitWith {};

    _args params ["_end", "_won"];
    [(_endings select _end) param [0, ""], [true, false] select _won] remoteExecCall [QEFUNC(common,endMissionServer),2];
}] call Ares_fnc_RegisterCustomModule;

[UTIL, "End Mission (TVT)", {
    private _endings = [] call FUNC(getEndings);
    private _sides = [blufor, opfor, independent, civilian];
    private _dialogArgs = [];
    {
        private _sideName = [[_x] call EFUNC(common,translateSide)] call CBA_fnc_capitalize;
        _dialogArgs pushBack [_sideName + " ending", _endings apply {_x param [1, ""]}, 0];
        _dialogArgs pushBack [_sideName + " victory", ["Yes", "No"], 0];
    } forEach _sides;

    private _args = ["End Mission", _dialogArgs] call Ares_fnc_ShowChooseDialog;
    if (count _args == 0) exitWith {};

    private _endMissionArgs = [];
    {
        private _ending = _args deleteAt 0;
        private _won = _args deleteAt 0;
        _endMissionArgs pushBack [(_endings select _ending) param [0, ""], [true, false] select _won, _x];
    } forEach _sides;

    [_endMissionArgs] remoteExecCall [QEFUNC(common,endMissionServer),2]
}] call Ares_fnc_RegisterCustomModule;

[AI, "Patrol area", {["PATROL", _this select 1] call FUNC(ai)}] call Ares_fnc_RegisterCustomModule;
[AI, "Defend area", {["DEFEND", _this select 1] call FUNC(ai)}] call Ares_fnc_RegisterCustomModule;
[AI, "Force move WP", {["FORCE_WP", _this select 1] call FUNC(ai)}] call Ares_fnc_RegisterCustomModule;

[AI, "Drive in straight line", {
    params ["", "_obj"];
    if (!(_obj isKindOf "LandVehicle") || !alive _obj) exitWith {["ERROR: Select vehicle"] call ares_fnc_ShowZeusMessage};

    [_obj, FUNC(setDrivePath), "Select path (hold ctrl for more)"] call ace_zeus_fnc_getModuleDestination;
}] call Ares_fnc_RegisterCustomModule;
