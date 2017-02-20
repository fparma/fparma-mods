/*
* Author: Cuel
* Get unit under cursor (where module dropped)
*
* Arguments:
* 0: The module logic <OBJECT>
*
* Public: No
*/
#include "script_component.hpp"
params [["_onlyReturn", false, [true]]];

private _cursorData = missionNamespace getVariable ["bis_fnc_curatorObjectPlaced_mouseOver", ["", objNull]];
if (_onlyReturn) exitWith {_cursorData};

_cursorData params ["_type", "_target"];
if (_type == "GROUP") then {
    _type = "OBJECT";
    _target = leader _target;
};

if (_type != "OBJECT") exitWith {objNull};
private _unit = effectiveCommander _target;
if !(_unit isKindOf "CAManBase") exitWith {objNull};
_unit
