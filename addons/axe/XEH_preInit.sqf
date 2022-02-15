#include "script_component.hpp"
ADDON = false;
#include "XEH_PREP.hpp"

[
    QGVAR(setting_timeFactor),
    "SLIDER",
    "Chopping time factor (higher means longer)",
    [FP_SETTINGS, "Axe"],
    [0.1,10,1,1],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(setting_maxTime),
    "SLIDER",
    "Max. chopping time (no matter how tall the tree)",
    [FP_SETTINGS, "Axe"],
    [5,600,40,0],
    1
] call CBA_fnc_addSetting;

[
    QGVAR(setting_alwaysHideTree),
    "CHECKBOX",
    "Always hide chopped tree",
    [FP_SETTINGS, "Axe"],
    false,
    1
] call CBA_fnc_addSetting;

ADDON = true;
