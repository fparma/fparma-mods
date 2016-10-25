#include "script_component.hpp"

if (!hasInterface) exitWith {};

["ace_firedPlayer", DFUNC(fired)] call CBA_fnc_addEventHandler;

// does postinit ensure player?
[{!isNull player}, {
    player addEventHandler ["Killed", DFUNC(killed)];
}] call CBA_fnc_waitUntilAndExecute;
