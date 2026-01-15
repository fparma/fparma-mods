#include "script_component.hpp"

if (!hasInterface || profileNamespace getVariable [QGVAR(disable), false]) exitWith {};

GVAR(delayedEvents) = [];
DFUNC(addDelayedEvents) = {
    {
        _x params ["_time", "_event", "_params"];
        private _relativeTime = _time - diag_tickTime; // negative time
        steamGameRecordingEvent [_event, 0, _params, _relativeTime];
    } forEach GVAR(delayedEvents);
    GVAR(delayedEvents) = [];
    INFO("Added Steam Events");
};
addMissionEventHandler ["Ended", {
    params ["_endType"];
    steamGameRecordingEvent [QGVAR(missionEnd), 0, [[CBA_missionTime] call CBA_fnc_formatElapsedTime]];
    [] call FUNC(addDelayedEvents)
}];

["ace_unconscious", {
    params ["_unit", "_uncon"];
    if (_unit != ACE_player) exitWith {};
    if (_uncon) then {
        steamGameRecordingEvent [QGVAR(uncon), 0, ["Knocked unconcious", [CBA_missionTime, "M:SS"] call CBA_fnc_formatElapsedTime]];
    } else {
        steamGameRecordingEvent [QGVAR(uncon), 0, ["Woke up", [CBA_missionTime, "M:SS"] call CBA_fnc_formatElapsedTime]];
    };
}] call CBA_fnc_addEventHandler;

["ace_throwableThrown", {
    params ["_unit", "_activeThrowable"];
    if (_unit != ACE_player) exitWith {}; // this should always be false
    switch (true) do {
        case (_activeThrowable isKindOf "ACE_G_Handflare_White"): {steamGameRecordingEvent [QGVAR(aceThrow), 0, ["Hand flare"]];};
        case (_activeThrowable isKindOf "SmokeShell"): {steamGameRecordingEvent [QGVAR(aceThrow), 0, ["Smoke grenade"]];};
        case (_activeThrowable isKindOf "ACE_SatchelCharge_Remote_Ammo_Thrown"): {steamGameRecordingEvent [QGVAR(aceThrow), 0, ["Explosive charge"]];};
        default {steamGameRecordingEvent [QGVAR(aceThrow), 0, ["Hand grenade"]];};
    };
}] call CBA_fnc_addEventHandler;

["ace_killtracker_kill", {
    params ["_name", "", "_unit"];
    private _distance = ace_player distance _unit;
    GVAR(delayedEvents) pushBack [diag_tickTime, QGVAR(UnitKilled), [_name, _distance toFixed 0]];
}] call CBA_fnc_addEventHandler;

["vehicle", {
    params ["_unit", "_vehicle", "_oldVehicle"];
    if (_unit != ACE_player) exitWith {}; // kind of redundant aint it?
    if (_unit isEqualTo _vehicle) then {
        steamGameRecordingEvent [QGVAR(vehicle), 0, ["out of", getText (configOf _oldVehicle >> "displayName")]];
    } else {
        steamGameRecordingEvent [QGVAR(vehicle), 0, ["into", getText (configOf _vehicle >> "displayName")]];
    };
}] call CBA_fnc_addPlayerEventHandler;
