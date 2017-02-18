/*
* Author: Cuel
* Fully heal unit/group
*
* Arguments:
* 0: The module logic <OBJECT>
* 1: Synchronized units <ARRAY>
* 2: Activated <BOOL>
*
* Public: No
*/

#include "script_component.hpp"
params ["_logic", "_units", "_activated"];
if !(_activated && local _logic) exitWith {};

private _unit = call FUNC(getUnitUnderCursor);
private _logicType = typeOf _logic;

deleteVehicle _logic;
if !(alive _unit) exitWith {
    ["Invalid target"] call FUNC(curatorMessage);
};

private _units = switch (toLower _logicType) do {
    case "fpa_zeus_modulehealunit": {[_unit]};
    case "fpa_zeus_modulehealgroup": {units group _unit};
    default {WARNING("Unknown logic"); []};
};

{[player, _x] call ace_medical_fnc_treatmentAdvanced_fullHeal} forEach _units;
[format ["%1 fully healed", ["Group", "Unit"] select (count _units isEqualTo 1)], false] call FUNC(curatorMessage);
