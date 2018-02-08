#include "script_component.hpp"

["CAManBase", "init", {
    params ["_unit"];
    if (local _unit) then {
        _unit disableAI "AUTOCOMBAT";
    };
}, true, [], true] call CBA_fnc_addClassEventHandler;


["CAManBase", "local", {
    params ["_unit"];
    _unit disableAI "AUTOCOMBAT";
}] call CBA_fnc_addClassEventHandler;
