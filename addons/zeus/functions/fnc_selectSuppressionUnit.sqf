/*
* Author: Cuel
* Forces ai group to supress nearest enemy group
*
* Arguments:
* 0: The module logic <OBJECT>
* 1: Synchronized units <ARRAY>
* 2: Activated <BOOL>
*
* Public: No
*/
#define MAX_DISTANCE 600

#include "script_component.hpp"
params ["_logic", "_units", "_activated"];
if !(_activated && local _logic) exitWith {};

private _unit = [] call FUNC(getUnitUnderCursor);
deleteVehicle _logic;

if !(alive _unit) exitWith {
    ["Invalid target"] call FUNC(curatorMessage);
};

GVAR(selectedSupression) = _unit;
