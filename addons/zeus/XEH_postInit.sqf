#include "script_component.hpp"

[QGVAR(supress), {_this call FUNC(supressionEH)}] call CBA_fnc_addEventHandler;

if (hasInterface && RETDEF(GVAR(weaponsDisabled),false)) then {
   [true] call EFUNC(common,disableWeapons);
};
