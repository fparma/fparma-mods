
/*
    Function: fpa_common_fnc_disableWeapons

    API:
        client

    Description:
        Disables a players weaponfire, grenades, detonating explosives etc.

    Parameters:
        _disable - True to disable weapons, false for vice versa

  Examples:
    (begin)
      [true] call fpa_common_fnc_disableWeapons;
    (end)

    Author:
        Cuel 2015-10-29
*/

#include "script_component.hpp"

params [["_disableWeapons", false], ["_reason", ""]];
if (!hasInterface) exitWith {};

// Init
if (isNil QGVAR(weaponsDisabled)) then {
	GVAR(weaponsDisabled) = _disableWeapons;
	GVAR(prevAdvThrowEnabled) = ace_advanced_throwing_enabled;

	// "can" detonate
	[{!GVAR(weaponsDisabled)}] call ace_explosives_fnc_addDetonateHandler;	
	[player, "DefaultAction", {GVAR(weaponsDisabled)}, {}] call ace_common_fnc_addActionEventHandler;

	["ace_firedPlayer", {
	  if (!GVAR(weaponsDisabled)) exitWith {};
      private _obj = param [6, objNull];
      if (!isNil "ace_frag_fnc_addBlackList") then {
        [_obj] call ace_frag_fnc_addBlackList;
      };
      deleteVehicle _obj;
    }] call CBA_fnc_addEventHandler;
};

_reason = toLower _reason;
private _reasons = player getVariable [QGVAR(disableWeaponsReasons), []];
if (_disableWeapons) then {
	_reasons pushBackUnique _reason;
} else {
	_reasons deleteAt (_reasons find _reason);
};
player setVariable [QGVAR(disableWeaponsReasons), _reasons];

if (_disableWeapons) then {
    ace_advanced_throwing_enabled = false;
	GVAR(weaponsDisabled) = false;
} else {
	if (_reasons isEqualTo []) then {
		ace_advanced_throwing_enabled = GVAR(prevAdvThrowEnabled);	
		GVAR(weaponsDisabled) = true;
	};
};
