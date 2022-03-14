#include "script_component.hpp"
params ["_display"];
if !(isNull (_display getVariable [QGVAR(chatReminder), controlNull])) then {
    ctrlDelete (_display getVariable [QGVAR(chatReminder), controlNull]);
};
