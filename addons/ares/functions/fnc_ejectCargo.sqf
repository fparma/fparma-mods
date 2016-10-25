/*
 * Author: Cuel
 * Ejects all cargo and FFV
 *
 * Arguments:
 * 1- Object(s), single or array
 *
 * Public: Yes
 */
#include "script_component.hpp"

params ["_vehicle"];
if (!alive _vehicle || {_vehicle isKindOf "CAManBase"}) exitWith {};

if (abs (speed _vehicle) > 2) exitWith {
    ["ERROR: Vehicle is moving"] call ares_fnc_ShowZeusMessage;
};

if (_vehicle isKindOf "Air" && {!isTouchingGround _vehicle}) exitWith {
    ["ERROR: Cannot eject air units"] call ares_fnc_ShowZeusMessage;
};

private _units = [_vehicle, ["ffv", "cargo"]] call ace_common_fnc_getVehicleCrew;
if (count _units == 0) exitWith {};
[QGVAR(eject), [_units], _units] call CBA_fnc_targetEvent;
