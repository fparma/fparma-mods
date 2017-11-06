/*
 * Author: Cuel
 * Starts the draw EH if not already started
 *
 * Arguments:
 *
 *
 * Public: No
 */

#include "script_component.hpp"

if (isNil QGVAR(drawNamesId) && {!(GVAR(vehicleNames) isEqualTo [])}) then {
    GVAR(drawNamesId) = addMissionEventHandler ["Draw3D", {
        GVAR(vehicleNames) = GVAR(vehicleNames) select {alive (_x select 0)};

        if (GVAR(vehicleNames) isEqualTo []) exitWith {
            removeMissionEventHandler ["Draw3D", GVAR(drawNamesId)];
            GVAR(drawNamesId) = nil;
        };

        {
            _x params ["_veh", "_text", "_distance", "_height", "_color"];
            if (!isObjectHidden _veh &&
                {positionCameraToWorld [0,0,0] distance _veh < _distance} &&
                {objectParent ACE_player != _veh}) then
            {
                private _drawPos = _veh modelToWorldVisual [0,0, _height];
                drawIcon3D ["", _color, _drawPos, 0, 0, 0, _text, 2, 0.04, "PuristaMedium"];
            };
        } forEach GVAR(vehicleNames);
    }];
};
