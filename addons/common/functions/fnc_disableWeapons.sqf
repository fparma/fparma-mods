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

params [["_disableWeapons", false]];

if (!hasInterface || {_disableWeapons isEqualTo GVAR(isWeaponsDisabled)}) exitWith {false};

GVAR(isWeaponsDisabled) = _disableWeapons;

// Detonating explosives
if (isNil QGVAR(canDetonate)) then {
    GVAR(canDetonate) = !_disableWeapons;
    [{GVAR(canDetonate)}] call ace_explosives_fnc_addDetonateHandler;
};
GVAR(canDetonate) = !_disableWeapons;

if (_disableWeapons) then {
    // ace adv throw
    GVAR(advThrowEnabled) = ace_advanced_throwing_enabled;
    ace_advanced_throwing_enabled = false;

    // Thrown grenades etc
    GVAR(firedId) = ["ace_firedPlayer", {
      private _obj = param [6, objNull];
      if (!isNil "ace_frag_fnc_addBlackList") then {
        [_obj] call ace_frag_fnc_addBlackList;
      };
      deleteVehicle _obj;
    }] call CBA_fnc_addEventHandler;

    // Disable default action mouse1 (firing)
    GVAR(actionEventId) = [player, "DefaultAction", {true}, {}] call ace_common_fnc_addActionEventHandler;

} else {
    ace_advanced_throwing_enabled = GVAR(advThrowEnabled);
    ["ace_firedPlayer", GVAR(firedId)] call CBA_fnc_removeEventHandler;
    [player, "DefaultAction", GVAR(actionEventId)] call ACE_common_fnc_removeActionEventHandler;
};

true
