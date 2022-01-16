#include "script_component.hpp"
/**
* Description:
* Plays animation and cuts grass
*
* Arguments
* None
*
* Example:
* [] call fpa_common_fnc_cutGrass
*
*/

[ace_player, "AinvPknlMstpSnonWnonDnon_medic4"] call ace_common_fnc_doAnimation;

private _condition = {
    param [0] params ["_unit", "_pos"];
    (_unit distance2D _pos < 1 && {[_unit] call ace_common_fnc_isAwake})
};

private _onComplete = {
    param [0] params ["_unit", "_pos"];
    [_unit, "", 1] call ace_common_fnc_doAnimation;
    (createVehicle ["Land_ClutterCutter_medium_F", [0,0,0], [], 0, "NONE"]) setPosATL _pos;
};

private _onFailure = {
    param [0] params ["_unit"];
    [_unit, "", 1] call ace_common_fnc_doAnimation;
};

[CBA_fnc_progressBar, ["Cutting grass", 8, _condition, _onComplete, _onFailure, [ace_player, getPosATL ace_player]]] call CBA_fnc_execNextFrame;
