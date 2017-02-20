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
#include "\A3\ui_f_curator\ui\defineResinclDesign.inc"

params ["_logic", "_units", "_activated"];
if !(_activated && local _logic) exitWith {};

private _pos = getPosASL _logic;
private _unit = [] call FUNC(getUnitUnderCursor);
deleteVehicle _logic;

private _idx = RETDEF(GVAR(selectedCustomIdx),-1);
if (_idx isEqualTo -1) exitWith {};

TRACE_1("Running index",_idx);
GVAR(registeredCustomModules) param [_idx, ["", {}]] params ["", "_code"];
[_pos, _unit] call _code;
