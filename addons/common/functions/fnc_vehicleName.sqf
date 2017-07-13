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

params [
    ["_veh", objNull, [objNull]],
    ["_text", "", [""]],
    ["_height", 0.4],
    ["_distance", 10],
    ["_color", [0, 0.6, 0.8, 1]]
];

if (isNull _veh || {_text isEqualTo ""}) exitWith {
    ["Invalid parameters %1", _this] call BIS_fnc_error;
};

if (isNil QGVAR(vehicleNames)) then {GVAR(vehicleNames) = []};
GVAR(vehicleNames) pushBackUnique [_veh, _text, _distance, _height, _color];

if (isNil QGVAR(drawNamesId)) then {
    GVAR(drawNamesId) = addMissionEventHandler ["Draw3D", {
        GVAR(vehicleNames) = GVAR(vehicleNames) select {alive (_x select 0)};

        if (GVAR(vehicleNames) isEqualTo []) exitWith {
            removeMissionEventHandler ["Draw3D", GVAR(drawNamesId)];
            GVAR(drawNamesId) = nil;
        };

        {
            _x params ["_veh", "_text", "_distance", "_height", "_color"];
            private _pos = _veh modelToWorldVisual [0,0, _height];
            if (positionCameraToWorld [0, 0, 0] distance _veh < _distance && {objectParent ACE_player != _veh}) then {
                drawIcon3D ["", _color, _pos, 0, 0, 0, _text, 2, 0.04, "PuristaMedium"];
            };
        } forEach GVAR(vehicleNames);
    }];
};
