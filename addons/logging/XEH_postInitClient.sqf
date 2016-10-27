#include "script_component.hpp"

if (!hasInterface) exitWith {};

["ace_firedPlayer", DFUNC(fired)] call CBA_fnc_addEventHandler;

// does postinit ensure player?
player addEventHandler ["Killed", DFUNC(killed)];
player addEventHandler ["HandleDamage", DFUNC(handleDamage)];
