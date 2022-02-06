#include "script_component.hpp"
/*
* Author: diwako
*
* Description:
* Heals all units in area
*
* Arguments:
* 0 - MARKER, OBJECT, LOCATION, GROUP, TASK or POSITION (ASL)
* 1 - range of effect in meters
*
* Example
* [_position, 100] call fpa_common_fnc_areaHeal
*
* Public: yes
*/
params ["_position", ["_range", 100]];

if (_position isEqualType []) then {
    _position = ASLToAGL _position;
} else {
    _position = [_position] call CBA_fnc_getPos;
};

{
    ["ace_medical_treatment_fullHealLocal", [_x], _x] call CBA_fnc_targetEvent;
} forEach (_position nearEntities [["CAManBase"], _range]);
