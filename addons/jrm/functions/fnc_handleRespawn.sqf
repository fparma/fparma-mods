/*
 * Author: Cuel
 * Handles a unit respawn
 *
 * Arguments:
 * Unit
 *
 * Public: No
 */

#include "script_component.hpp"
params [["_unit", objNull]];

if (isNil QGVAR(state) || {player != _unit}) exitWith {};

(GVAR(state) getVariable [getPlayerUID player, []]) params [["_deaths", 0], ["_timeOfDeath", 0]];

private _respawns = RETDEF(GVAR(respawns),-1);
if (_respawns >= 0 && {_deaths > _respawns}) then {
    [true] call EFUNC(common,spectate);
    [QGVAR(onPermaDeath), [_deaths, _timeOfDeath]] call CBA_fnc_localEvent;
};
