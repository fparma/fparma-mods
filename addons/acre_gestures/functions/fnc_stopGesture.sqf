#include "script_component.hpp"
params ["_unit"];

if (_unit getVariable [QGVAR(onRadio), false]) then {
    _unit playActionNow "acre_radio_stop";
    _unit setVariable [QGVAR(onRadio), nil];
};
