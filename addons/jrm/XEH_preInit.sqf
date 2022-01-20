#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(forceRespawn), {
    params ["_positionOrCode", ["_resetState", false]];
    [_positionOrCode, _resetState] call FUNC(forceRespawn);
}] call CBA_fnc_addEventHandler;

ADDON = true;
