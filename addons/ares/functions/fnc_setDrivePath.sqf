/*
* Author: Cuel
* Get all endings available
*
*
* Public: Yes
*/

#include "script_component.hpp"

params ["_success", "_obj", "_dest", "", "_holdingCtrl"];
if (!_success) exitWith {
    GVAR(pathDestinations) = [];
    [RETDEF(GVAR(pathDestEH), -1)] call CBA_fnc_removePerFrameHandler;
};

if (_holdingCtrl) exitWith {
    GVAR(pathDestinations) pushBack _dest;

    if (RETDEF(GVAR(pathDestEH), -1) == -1) then {
        GVAR(pathDestEH) = [{
            params ["_args"];
            _args params ["_obj"];
            private _draw = [getPosASL _obj] + GVAR(pathDestinations);
            {
                if (_forEachIndex >= count _draw - 1) exitWith {};
                private _next = _draw param [_forEachIndex + 1, [0,0,0]];
                drawLine3D [ASLToAGL _x vectorAdd [0, 0, 3], ASLToAGL _next vectorAdd [0, 0, 3], [0, 1, 0, 1]];
            } forEach _draw;
        }, 0, _obj] call CBA_fnc_addPerFrameHandler;
    };

    [{
        [_this, FUNC(setDrivePath), "Select path (hold ctrl for more)"] call ace_zeus_fnc_getModuleDestination;
    }, _obj] call CBA_fnc_execNextFrame;
};

private _dests = [getPosATL _obj] + GVAR(pathDestinations) + [_dest];
[RETDEF(GVAR(pathDestEH), -1)] call CBA_fnc_removePerFrameHandler;
GVAR(pathDestinations) = [];
GVAR(pathDestEH) = -1;

[QGVAR(driveOnPath), [_obj, _dests], _obj] call CBA_fnc_targetEvent;
