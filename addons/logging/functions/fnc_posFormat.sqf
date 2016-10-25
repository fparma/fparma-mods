/*
* Author: Cuel
* Formats a position to max two decimals
*
* Arguments:
* 1 - Any
*
* Public: Yes
*/

#include "script_component.hpp"
#define TWO_DEC(nr) (parseNumber ([nr, -1, 2] call CBA_fnc_formatNumber))
params ["_pos"];
(_pos call CBA_fnc_getPos) params ["_pX", "_pY", "_pZ"];

([
    TWO_DEC(_pX),
    TWO_DEC(_pY),
    TWO_DEC(_pZ)
])
