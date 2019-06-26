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
INFO_1("ZEN loaded: %1", !isNil "zen_custom_modules_fnc_register");
if (!hasInterface) exitWith {};

if !(isNil "Ares_fnc_RegisterCustomModule") then {
    #include "aresModules.sqf";
};

if !(isNil "zen_custom_modules_fnc_register") then {
    #include "zenModules.sqf";
};
