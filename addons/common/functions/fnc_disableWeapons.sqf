
/*
    Function: fpa_common_fnc_disableWeapons

    API:
        client

    Description:
        Disables a players weaponfire, grenades, detonating explosives etc.
        No zeus support

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
    GVAR(weaponsDisabledReasons) = [];
	GVAR(weaponsDisabled) = _disableWeapons;
	GVAR(origAdvThrow) = ace_advanced_throwing_enabled;

	// "can" detonate
	[{!GVAR(weaponsDisabled)}] call ace_explosives_fnc_addDetonateHandler;

    ["ace_firedPlayer", {
      if (!GVAR(weaponsDisabled)) exitWith {};
      private _obj = param [6, objNull];
      if (!isNil "ace_frag_fnc_addBlackList") then {
        [_obj] call ace_frag_fnc_addBlackList;
      };
      deleteVehicle _obj;
    }] call CBA_fnc_addEventHandler;

    GVAR(weaponsEvtId) = [player, "DefaultAction", {GVAR(weaponsDisabled)}, {}] call ace_common_fnc_addActionEventHandler;
    ["unit", {
        params ["_new", "_old"];
        [_old, "DefaultAction", GVAR(weaponsEvtId)] call ace_common_fnc_removeActionEventHandler;
        GVAR(weaponsEvtId) = [_new, "DefaultAction", {GVAR(weaponsDisabled)}, {}] call ace_common_fnc_addActionEventHandler;
    }] call CBA_fnc_addPlayerEventHandler;
};

_reason = toLower _reason;
private _reasons = player getVariable [QGVAR(disableWeaponsReasons), []];

if (_disableWeapons) then {
    _reasons pushBackUnique _reason;
    ace_advanced_throwing_enabled = false;
    GVAR(weaponsDisabled) = true;
} else {
    _reasons deleteAt (_reasons find _reason);
    if (_reasons isEqualTo []) then {
        ace_advanced_throwing_enabled = GVAR(origAdvThrow);
        GVAR(weaponsDisabled) = false;
    };
};

player setVariable [QGVAR(disableWeaponsReasons), _reasons];
