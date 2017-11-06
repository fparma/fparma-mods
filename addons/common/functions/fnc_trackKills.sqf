/**
* Tracks losses for mission ending screen.
* Arguments: None
* Public: Yes
*/

#include "script_component.hpp"

if (!isServer || {!isNil QGVAR(statsNamespace)}) exitWith {};
GVAR(statsNamespace) = [] call CBA_fnc_createNamespace;

FUNC(trackKilled) = {
    params ["_args", "_type"];
    _args params ["_veh"];
    private _returnConfigSide = !(_veh isKindOf "Man") && {count (crew _veh) > 0};
    private _side = [_veh, _returnConfigSide] call BIS_fnc_objectSide;
    if (!(_side in [blufor, opfor, independent, civilian])) exitWith {};

    private _sideStr = [_side] call FUNC(translateSide);
    private _key = format ["%1_%2", _sideStr, _type];
    private _nr = GVAR(statsNamespace) getVariable [_key, 0];
    GVAR(statsNamespace) setVariable [_key, _nr + 1];
};

addMissionEventHandler ["EntityKilled", {
    if (_x isKindOf "CAManBase") exitWith {[_this, "men"] call FUNC(trackKilled)};
    if (_x isKindOf "Wheeled_APC_F") exitWith {[_this, "apc"] call FUNC(trackKilled)};
    if (_x isKindOf "Car") exitWith {[_this, "car"] call FUNC(trackKilled)};
    if (_x isKindOf "Tank") exitWith {[_this, "armor"] call FUNC(trackKilled)};
    if (_x isKindOf "Air") exitWith {[_this, "air"] call FUNC(trackKilled)};
}];
