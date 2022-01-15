#include "script_component.hpp"

{
    ["ace_medical_treatment_" + _x, {
        if (lifeState ace_player == "INCAPACITATED") then {
            titleText ["Someone is helping you", "PLAIN DOWN", 2, true, true];
        };
    }] call CBA_fnc_addEventHandler;
} foreach ["bandageLocal", "checkBloodPressureLocal", "cprLocal", "fullHealLocal", "ivBagLocal", "medicationLocal", "splintLocal", "tourniquetLocal"];
