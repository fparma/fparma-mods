/*
* Author: Cuel
* Disable weapons / grenades for players including JIP 
*
* Arguments:
* 0: The module logic <OBJECT>
*
* Public: No
*/

#include "script_component.hpp"
params ["_logic", "_units", "_activated"];
if !(_activated && local _logic) exitWith {};
deleteVehicle _logic;

private _doDisable = !RETDEF(GVAR(weaponsDisabled),false);
missionNamespace setVariable [QGVAR(weaponsDisabled), _doDisable, true];
[_doDisable] remoteExecCall [QEFUNC(common,disableWeapons)];
[format ["Weapons %1", ["enabled", "disabled"] select _doDisable] call FUNC(curatorMessage);
