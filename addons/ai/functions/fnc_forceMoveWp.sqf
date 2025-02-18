/*
* Author: Cuel
* Forces ai group to move to their current wp, ignoring everything
*
* Arguments:
* 0 - Group (needs a waypoint)
*
* Public: Yes
*/

#include "script_component.hpp"
#define AI_MODES ["AUTOCOMBAT", "COVER", "SUPPRESSION", "TARGET", "AUTOTARGET", "FSM"]

params [["_grp", grpNull, [grpNull]]];
if (!local _grp) exitWith {};

_grp setVariable ["acex_headless_blacklist", true, true];
private _units = units _grp;
private _wps = waypoints _grp;
private _curWp = currentWaypoint _grp;

// If all waypoints are 'completed', then the index is 1 greater than the last valid index.
// If there are no waypoints, then the index is 0
if (_curWp in [0, count _wps]) exitWith {WARNING("Failed to determine waypoint")};

private _prevId = _grp getVariable ["fp_forcewp_id", -1];
if (_prevId != -1) then {
    TRACE_1("Removing previous pfh",_prevId);
    [_prevId] call CBA_fnc_removePerFrameHandler;
};

_targetPos = waypointPosition [_grp, _curWp];
{
    private _unit = _x;
    {_unit disableAI _x} forEach AI_MODES;
    _unit setUnitPos "UP";
    _unit doMove _targetPos;
} forEach _units;

TRACE_1("Running pfh",_targetPos);

private _pfhCode = {
    params ["_args", "_id"];
    _args params ["_grp", "_origWpPos"];

    private _curWp = currentWaypoint _grp;
    private _wpPos = waypointPosition [_grp, _curWp];
    private _units = units _grp;
    private _aliveUnits = _units select {alive _x && {!(_x getVariable ["ACE_isUnconscious", false])}};
    private _noUnits = count _aliveUnits == 0;
    private _wpChanged = (_wpPos isNotEqualTo _origWpPos);
    private _someoneClose = {_x distance _wpPos < 15} count units _grp > 0;

    if (_wpChanged || {_noUnits} || {_someoneClose}) exitWith {
        TRACE_3("Exiting",_noUnits,_wpChanged,_someoneClose);
        {
            private _unit = _x;
            {_unit enableAI _x} forEach AI_MODES;
            _unit setUnitPos "AUTO";
            doStop _unit;
        } forEach _units;

        [{
            params ["_grp"];
            private _leader = leader _grp;
            {_x doFollow _leader} forEach units _grp;
        }, _grp] call CBA_fnc_execNextFrame;
        //, 0.5] call CBA_fnc_waitAndExecute;

        _grp setVariable ["acex_headless_blacklist", false, true];
        _grp setVariable ["fp_forcewp_id", nil];
        [_id] call CBA_fnc_removePerFrameHandler;
    };

    {
        // need to check distance, sometimes they'll just run off in a random direction
        private _gettingCloser = _x distance2D _wpPos < (_x getVariable ["fp_lastDist", 9999]);
        if (!_gettingCloser || {speed _x < 4}) then {
            TRACE_2("Ordering move",_x,_gettingCloser);
            _x forceSpeed (_x getSpeed "FAST");
            _x doMove _wpPos;
        };
        _x setVariable ["fp_lastDist", _x distance2D _wpPos];
    } forEach _aliveUnits;
};

private _pfhId = [_pfhCode, 3, [_grp, _targetPos]] call CBA_fnc_addPerFrameHandler;
_grp setVariable ["fp_forcewp_id", _pfhId];
