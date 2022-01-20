#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(forceRespawn), {
    call FUNC(forceRespawn);
}] call CBA_fnc_addEventHandler;

ADDON = true;
