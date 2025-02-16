#include "script_component.hpp"
/*
* Author: diwako
*
* Description:
* Toggle unconsciousness on unit via zeus
*
* Arguments:
* 0 - Zeus module
*
* Example
* [_logic] call fpa_medical_fnc_moduleUnconscious
*
* Public: no
*/
params ["_logic"];

if !(local _logic) exitWith {};
private _mouseOver = GETMVAR(bis_fnc_curatorObjectPlaced_mouseOver,[""]);
if ((_mouseOver select 0) == "OBJECT") then {
    private _unit = effectiveCommander (_mouseOver select 1);
    if (_unit isKindOf "CAManBase" && {alive _unit && {_unit getVariable ["ACE_isUnconscious",false]}}) then {
        ["ace_medical_treatment_medicationLocal", [_unit, "body", "Vital"], _unit] call CBA_fnc_targetEvent;
    };
};

_this call ace_zeus_fnc_moduleUnconscious;
