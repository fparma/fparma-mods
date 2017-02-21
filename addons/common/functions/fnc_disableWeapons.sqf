/*
* Author: Cuel
* Disable player weapons / grenades
*
* Arguments:
* 0: Disable weapons <boolean>
*
* Public: Yes
*/

params [["_doDisable", false]];
if (!hasInterface) exitWith {};

if (!_doDisable) exitWith {
	if (!isNil QGVAR(previousAceThrowingState) then {
		ace_advanced_throwing_enabled = GVAR(previousAceThrowingState);
		GVAR(previousAceThrowingState) = nil;
	};

	[player, "DefaultAction", RETDEF(GVAR(disableWeaponsId),-1)] call ace_common_fnc_removeActionEventHandler;
	player removeEventHandler ["Fired", RETDEF(GVAR(disableWeaponsFiredId),-1)];
};

// Use this GVAR to know if it's already disabled
if (!isNil QGVAR(previousAceThrowingState) exitWith {};

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
