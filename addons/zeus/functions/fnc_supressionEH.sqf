/*
* Author: Cuel
* Does the actual supression
*
* Arguments:
* 0: Unit who supress <OBJECT>
* 1: Position <ARRAY>
*
* Public: No
*/
#include "script_component.hpp"

params [["_unit", objNull, [objNull]], ["_pos", []]];
if !(alive _unit || count _pos < 2) exitWith {};

private _grp = group _unit;
private _units = units _grp;

if !(isNull objectParent _unit) then {
    _units = [];
    {_units pushBackUnique _x} forEach (units _grp apply {effectiveCommander _x});
};

private _objs = [];

// TODO fix this crap
private _i = 1;
private _reachedHalf = false;
private _half = floor ((count _units) / 2);

{
    if (!_reachedHalf && _forEachIndex > _half) then {_i = 1; _reachedHalf = true};
    private _dir = (_x getDir _pos) + 90;
    private _randPos = _pos getPos [(_i * 5), [_dir, (_dir + 180)] select (_forEachIndex > _half)];
    _obj = "Land_HelipadEmpty_F" createVehicleLocal _randPos;
    _x doSuppressiveFire _obj;
    _objs pushBack _obj;
    INC(_i);
} forEach _units;

[{
    params ["_objs"];
    {deleteVehicle _x} forEach _objs;
}, [_objs], 20] call CBA_fnc_waitAndExecute;
