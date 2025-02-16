/*
* Author: Cuel
*
* Description:
* Wrapper for findEmptyPosition, guarantees to return a position but radius might increase
*
* Arguments:
* Position - any
* Radius - max radius to begin search with
* Classname - type of class to that should fit
*
* Public: Yes
*/

#include "script_component.hpp"

params ["_pos", ["_radius", 10], ["_className", ""]];
_pos = [_pos] call CBA_fnc_getPos;

private _args = [0, _radius];
if (_className isNotEqualTo "") then {_args pushBack _className};

private _emptyPos = _pos findEmptyPosition _args;
if (_emptyPos isNotEqualTo []) exitWith {_emptyPos};
[_pos, _radius + 5, _className] call FUNC(findSafePos);
