/**
* Tracks losses for mission ending screen.
*/
#include "script_component.hpp"

if (!isServer || {RETDEF(GVAR(trackingKills),false)}) exitWith {};
GVAR(trackingKills) = true;

GVAR(statsNamespace) = [] call CBA_fnc_createNamespace;

FUNC(trackKilled) = {
    params ["_args", "_type"];
    _args params ["_veh"];
    private _side = [_veh, count _crew isEqualTo 0] call BIS_fnc_objectSide;
    if (!(_side in [blufor, opfor, independent, civilian])) exitWith {};

    private _sideStr = [_side] call FUNC(translateSide);
    private _key = format ["%1_%2", _sideStr, _type];
    private _nr = GVAR(statsNamespace) getVariable [_key, 0];
    GVAR(statsNamespace) setVariable [_key, _nr + 1];
};

["CAManBase", "killed", {
    [_this, "men"] call FUNC(trackKilled);
}] call CBA_fnc_addClassEventHandler;

["Car", "killed", {
    [_this, "car"] call FUNC(trackKilled);
}, nil, ["Wheeled_APC_F"]] call CBA_fnc_addClassEventHandler;

["Wheeled_APC_F", "killed", {
    [_this, "apc"] call FUNC(trackKilled);
}] call CBA_fnc_addClassEventHandler;

["Tank", "killed", {
    [_this, "tank"] call FUNC(trackKilled);
}] call CBA_fnc_addClassEventHandler;

["Air", "killed", {
    [_this, "air"] call FUNC(trackKilled);
}] call CBA_fnc_addClassEventHandler;
