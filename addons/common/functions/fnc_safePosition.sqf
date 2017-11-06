/*
* Author: Cuel
*
* Description:
* Wrapper for findEmptyPosition, guarantees to return a position but radius might increase
*
* Arguments:
* Position - any
*
* Public: Yes
*/

#include "script_component.hpp"

params ["_pos", ["_radius", 10], ["_className", ""]];
_pos = [_pos] call CBA_fnc_getPos;

private _args = [_radius];
if !(_className isEqualTo "") then {_args pushBack _className};

private _emptyPos = _pos findEmptyPosition _args;
if !(_emptyPos isEqualTo []) exitWith {_emptyPos};
[_pos, _radius + 10, _className] call FUNC(safePosition);
