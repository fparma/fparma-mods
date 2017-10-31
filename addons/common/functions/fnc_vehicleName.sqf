/*
* Author: Cuel
*
* Description: Draws text on vehicle when close
*
* Arguments:
* 1 - Object - vehicle to display name
* 2 - Text - Displayed text
* 3 - Number - Custom height
* 4 - Number - Custom distance
* 5 - ARRAY [R,G,B,A] - custom color
*
* Public: Yes
*/
#include "script_component.hpp"

if (!hasInterface) exitWith {};

params [
    ["_veh", objNull, [objNull]],
    ["_text", "", [""]],
    ["_height", 0.4],
    ["_distance", 10],
    ["_color", [0, 0.6, 0.8, 1]]
];

if (!alive _veh || {_text isEqualTo ""}) exitWith {
    ["Invalid parameters %1", _this] call BIS_fnc_error;
};

private _cur = GVAR(vehicleNames) apply {_x select 0};
private _curIdx = _cur find _veh;
if (_curIdx != -1) then {
    GVAR(vehicleNames) deleteAt _curIdx;
};

GVAR(vehicleNames) pushBackUnique [_veh, _text, _distance, _height, _color];
[] call FUNC(runVehicleDrawEH);
