#include "script_component.hpp"
params ["_medic", "_patient", "_bodyPart", "_bandage"];

!([_patient] call ace_common_fnc_isAwake)
