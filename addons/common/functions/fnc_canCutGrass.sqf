#include "script_component.hpp"
/**
* Description:
* Check if can cut grass
*
* Arguments
* 0 - unit
*
* Example:
* [_unit] call fpa_common_fnc_cutGrass
*
*/

params [["_unit", objNull]];
('FPA_scissors' in items _unit && {[_unit] call ace_common_fnc_canDig})
