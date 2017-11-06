/**
* Tracks losses for mission ending screen.
* Arguments: None
* Public: Yes
*/

#include "script_component.hpp"

if (!isServer || {!isNil QGVAR(statsNamespace)}) exitWith {};
GVAR(statsNamespace) = [] call CBA_fnc_createNamespace;

FUNC(trackKilled) = {
    params ["_veh", "_type"];
    private _returnConfigSide = count (crew _veh) isEqualTo 0;
    private _side = [_veh, _returnConfigSide] call BIS_fnc_objectSide;
    if (!(_side in [blufor, opfor, independent, civilian])) exitWith {};

    private _sideStr = [_side] call FUNC(translateSide);
    private _key = format ["%1_%2", _sideStr, _type];
    private _nr = GVAR(statsNamespace) getVariable [_key, 0];
    GVAR(statsNamespace) setVariable [_key, _nr + 1];
};

addMissionEventHandler ["EntityKilled", {
    params ["_veh"];
    if (_veh isKindOf "CAManBase") exitWith {[_veh, "men"] call FUNC(trackKilled)};
    if (_veh isKindOf "Wheeled_APC_F") exitWith {[_veh, "apc"] call FUNC(trackKilled)};
    if (_veh isKindOf "Car") exitWith {[_veh, "car"] call FUNC(trackKilled)};
    if (_veh isKindOf "Tank") exitWith {[_veh, "armor"] call FUNC(trackKilled)};
    if (_veh isKindOf "Air") exitWith {[_veh, "air"] call FUNC(trackKilled)};
}];
