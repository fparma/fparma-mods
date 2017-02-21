/*
* Author: Cuel
* Disable player weapons / grenades
*
* Arguments:
* 0: Disable weapons <boolean>
*
* Public: Yes
*/

#include "script_component.hpp"
params [["_doDisable", false]];
if (!hasInterface) exitWith {};

TRACE_1("Do disable",_doDisable);
if (!_doDisable) exitWith {
    if (!isNil QGVAR(previousAceThrowingState)) then {
        ace_advanced_throwing_enabled = GVAR(previousAceThrowingState);
        GVAR(previousAceThrowingState) = nil;
    };

    [player, "DefaultAction", RETDEF(GVAR(disableWeaponsId),-1)] call ace_common_fnc_removeActionEventHandler;
    player removeEventHandler ["Fired", RETDEF(GVAR(disableWeaponsFiredId),-1)];
};
TRACE_1("nil",isNil QGVAR(previousAceThrowingState));
// Use this GVAR to know if it's already disabled
if (!isNil QGVAR(previousAceThrowingState)) exitWith {};

GVAR(previousAceThrowingState) = ace_advanced_throwing_enabled;
ace_advanced_throwing_enabled = false;

GVAR(disableWeaponsId) = [player, "DefaultAction", {true}, {}] call ace_common_fnc_addActionEventHandler;
GVAR(disableWeaponsFiredId) = player addEventHandler ["Fired", {
    private _obj = param [6, objNull];
    if (!isNil "ace_frag_fnc_addBlackList") then {
        [_obj] call ace_frag_fnc_addBlackList;
    };
    deleteVehicle _obj;
}];
