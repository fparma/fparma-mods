/*
 * Author: Cuel
 * Simulate entering a zone where safemode is on, prevents weapons fire
 *
 * Arguments:
 * 0 - Disable weapons <bool>
 * 1 - Display a hint <bool>
 *
 * Public: Yes
 */

#include "script_component.hpp"

if (!hasInterface) exitWith {};
params [["_enable", false, [true]], ["_displayHint", true]];

[_enable, "safezone"] call FUNC(disableWeapons);
if (_displayHint) then {
    private _text = format ["%1 safemode zone", ["Left", "Entered"] select _enable];
    [_text, "\A3\ui_f\data\map\markers\military\warning_ca.paa", [0, 0.5, 1]] call ace_common_fnc_displayTextPicture;
};
