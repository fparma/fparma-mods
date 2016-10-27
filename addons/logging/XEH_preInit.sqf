#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

ADDON = true;

GVAR(disabled) = false;
GVAR(grenades) = [];
GVAR(playerDamageTimeout) = [objNull, 0];
