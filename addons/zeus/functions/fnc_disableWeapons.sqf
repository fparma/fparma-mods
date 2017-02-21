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

private _isAlreadyDisabled = RETDEF(GVAR(weaponsDisabled),false);
if (_isAlreadyDisabled) then {
    missionNamespace setVariable [QGVAR(weaponsDisabled), false, true];
    [false] remoteExecCall [QEFUNC(common,disableWeapons)];
} else {
    missionNamespace setVariable [QGVAR(weaponsDisabled), true, true];
    [true] remoteExecCall [QEFUNC(common,disableWeapons)];
};
