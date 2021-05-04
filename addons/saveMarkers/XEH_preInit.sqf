#include "script_component.hpp"

#include "XEH_PREP.hpp"

[
    QGVAR(setting_canBeOpened),
    "LIST",
    ["Save markers", "Enabled"],
    FP_SETTINGS,
    [
        [0,1,2],
        ["never","first 10min of mission","always"],
        1
    ]
] call CBA_Settings_fnc_init;
