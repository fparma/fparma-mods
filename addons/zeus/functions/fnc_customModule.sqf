/*
* Author: Cuel
* Runs a custom module
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

private _type = typeof _logic;
private _pos = getPosASL _logic;
private _unit = call FUNC(getUnitUnderCursor);
deleteVehicle _logic;

// Get the index based on the module's type... not so clean
private _cnt = count _type;
private _typeNumber = parseNumber (_type select [_cnt - 2, _cnt - 1]);
private _idx = _typeNumber -1;

GVAR(registeredModules) param [_idx, ["", {}]] params ["", "_code"];
[_pos, _unit] call _code;
