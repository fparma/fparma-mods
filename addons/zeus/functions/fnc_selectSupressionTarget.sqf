/*
* Author: Cuel
* Select supression target area
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

private _pos = getPosASL _logic;
deleteVehicle _logic;


private _who = RETDEF(GVAR(selectedSupression),objNull);

if !(alive _who) exitWith {
    ["No unit selected to perform supression"] call FUNC(curatorMessage);
};

if (_who distance _pos > 600) exitWith {
    ["Supression area is too far away"] call FUNC(curatorMessage);
};

[QGVAR(supress), [_who, _pos], _who] call CBA_fnc_targetEvent;
GVAR(selectedSupression) = objNull;
