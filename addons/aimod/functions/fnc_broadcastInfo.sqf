#include "script_component.hpp"

params ["_grp", ["_dangerCause", objNull]];
private _sendTimeout = _grp getVariable [QGVAR(broadcastTimeout), 0];
if (CBA_missionTime < _sendTimeout || {isNull _dangerCause}) exitWith {};

private _leader = leader _grp;
private _knowledge = _leader knowsAbout _dangerCause;
if (_knowledge < 1.5) exitWith {};

if (_sendTimeout isEqualTo 0) exitWith {
    // initial broadcast
    TRACE_1("inital broadcast wait", _grp);
    _grp setVariable [QGVAR(broadcastTimeout), 20 + random [5, 10, 25]];
};

// send it
TRACE_1("send knowledge", _grp);
private _nearGrps = allGroups select {side _x isEqualTo side _grp && {count units _x >= 2} && {leader _x distance leader _grp < 300}};
if (_nearGrps isEqualTo []) then {
    // try again in 15s
    TRACE_1("no nearby units", _grp);
    _grp setVariable [QGVAR(broadcastTimeout), CBA_missionTime + 15];
} else {
    TRACE_1("broadcasting", _grp);
    // wait until next send. longer delay for dumb units
    private _skill = 0.1 max (_leader skillFinal "commanding");
    private _wait = 15 + ((1 - _skill) * random [15, 40, 80]);
    _grp setVariable [QGVAR(broadcastTimeout), CBA_missionTime + _wait, true];
    private _sendTo = selectRandom _nearGrps;
    [QGVAR(broadcast), [_sendTo, _grp, _dangerCause, _knowledge], _sendTo] call CBA_fnc_targetEvent;
};
