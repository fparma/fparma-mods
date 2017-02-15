#include "script_component.hpp"
#define UTIL "FP - Utils"
#define AI "FP - AI"

[QGVAR(eject), {
    params [["_units", []]];
    {
        if (local _x) then {
            _x leaveVehicle (vehicle _x);
            _x action ["Eject", vehicle _x];
        };
    } forEach _units;
}] call CBA_fnc_addEventHandler;

[QGVAR(garrison), {
    _this call EFUNC(ai,garrison);
}] call CBA_fnc_addEventHandler;

[QGVAR(forceMove), {
  _this call EFUNC(ai,forceMoveWp);
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

[AI, "Patrol area", {["PATROL", _this select 1] call FUNC(ai)}] call Ares_fnc_RegisterCustomModule;
[AI, "Defend area", {["DEFEND", _this select 1] call FUNC(ai)}] call Ares_fnc_RegisterCustomModule;
[AI, "Garrison", {["GARRISON", _this select 1] call FUNC(ai)}] call Ares_fnc_RegisterCustomModule;
[AI, "Force move WP", {["FORCE_WP", _this select 1] call FUNC(ai)}] call Ares_fnc_RegisterCustomModule;
