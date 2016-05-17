#include "script_component.hpp"
#define UTIL "FP - Utils"
#define AI "FP - AI"

if (!hasInterface) exitWith {};
if (isNil "Ares_fnc_RegisterCustomModule") exitWith {};

GVAR(addToCurators) = {
  [_this, {
    {
      _x addCuratorEditableObjects [[_this], false];
    } forEach allCurators;
  }] remoteExecCall ["BIS_fnc_call", 2];
};

GVAR(ai) = COMPILE_FILE(ai);
GVAR(camera) = COMPILE_FILE(camera);
GVAR(eject) = COMPILE_FILE(eject_cargo);
GVAR(ied) = COMPILE_FILE(proximity_ied);

[UTIL, "Camera at position", {_this call GVAR(camera)}] call Ares_fnc_RegisterCustomModule;
[UTIL, "Eject cargo", {_this call GVAR(eject)}] call Ares_fnc_RegisterCustomModule;
[UTIL, "Phone IED", {_this call GVAR(ied)}] call Ares_fnc_RegisterCustomModule;
[UTIL, "Road IED", {
  params ["_pos"];
  private _bomb = createVehicle [selectRandom ["ACE_ModuleExplosive_IEDLandBig_Range", "ACE_ModuleExplosive_IEDLandBig_Range"], _pos, [], 0, "NONE"];
  _bomb call GVAR(addToCurators);
}] call Ares_fnc_RegisterCustomModule;

[AI, "Patrol area", {["PATROL", _this select 1] call GVAR(ai)}] call Ares_fnc_RegisterCustomModule;
[AI, "Defend area", {["DEFEND", _this select 1] call GVAR(ai)}] call Ares_fnc_RegisterCustomModule;
[AI, "Garrison", {["GARRISON", _this select 1] call GVAR(ai)}] call Ares_fnc_RegisterCustomModule;
[AI, "Force move WP", {["FORCE_WP", _this select 1] call GVAR(ai)}] call Ares_fnc_RegisterCustomModule;
