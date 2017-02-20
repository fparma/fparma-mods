/*
* Author: Cuel
* Makes zeus invulnerable and invisible
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

private _unit = [] call FUNC(getUnitUnderCursor);
deleteVehicle _logic;

if (!alive _unit || {isNull getAssignedCuratorLogic _unit} || {!(_unit call EFUNC(common,isPlayer))}) exitWith {
    ["Invalid target"] call FUNC(curatorMessage);
};

if (isObjectHidden _unit) then {
    [_unit, false] remoteExecCall ["hideObjectGlobal", 2];
    [_unit, true] remoteExecCall ["allowDamage", _unit];
    ["Zeus godmode OFF", false] call FUNC(curatorMessage);
} else {
    [_unit, true] remoteExecCall ["hideObjectGlobal", 2];
    [_unit, false] remoteExecCall ["allowDamage", _unit];
    ["Zeus godmode ON", false] call FUNC(curatorMessage);
};
