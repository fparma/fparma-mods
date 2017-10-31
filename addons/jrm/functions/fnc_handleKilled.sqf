/*
 * Author: Cuel
 * Handles a unit dying
 *
 * Arguments:
 * Unit
 *
 * Public: No
 */

#include "script_component.hpp"
params [["_unit", objNull]];

if (isNil QGVAR(state) || {player != _unit}) exitWith {};

private _uid = getPlayerUID player;
(GVAR(state) getVariable [_uid, []]) params [["_prevDeaths", 0]];

private _deaths = _prevDeaths + 1;
GVAR(state) setVariable [_uid, [_deaths, CBA_missionTime], true];
