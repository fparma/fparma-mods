/*
* Author: Cuel
* Forces ai group to move to their current wp, ignoring everything
*
* Arguments:
* 0 - Group
* 1- Radius to search for building. -1 to use nearest building
* 2 - Allow units on roof (default true)
* 3 - Fill buildings evenly (default false)
* 4 - Lock units in place (default true)
*
* Public: Yes
*/

#define AI_MODES ["TARGET", "AUTOTARGET", "SUPPRESSION", "COVER", "AUTOCOMBAT"]

params [["_grp", grpNull, [grpNull]]];
if (!local _grp) exitWith {};

private _units = units _grp;
private _wps = waypoints _grp;
private _wp1 = currentWaypoint _grp;

// If all waypoints are 'completed', then the index is 1 greater than the last valid index.
// If there are no waypoints, then the index is 0
if (_wp1 in [0, count _wps]) exitWith {["ERROR: Failed to determine waypoint"] call ares_fnc_ShowZeusMessage};
_wp1 = _wps select _wp1;
_targetPos = waypointPosition _wp1;

_grp enableAttack false;
_grp setSpeedMode "FULL";
[_grp] call CBA_fnc_clearWaypoints;

{
    private _unit = _x;
    {_unit disableAI _x} forEach AI_MODES;
    _unit forceSpeed (_unit getSpeed "FAST");
    _unit setUnitPos "UP";
} forEach _units;

[{
    params ["_units", "_targetPos"];
    {
        _x doMove _targetPos;
    } forEach _this;
}, [_units, _targetPos]] call CBA_fnc_execNextFrame;




/*
private _wpid = _grp getVariable ["fp_forcewp_id", -1];
if (_wpid != -1) exitWith {
    _wpid call CBA_fnc_removePerFrameHandler;
};

if (hasInterface || isServer) then {
    (leader _grp) setVariable ["acex_headless_blacklist", true, true];
};

private _units = units _grp;
private _wps = waypoints _grp;
private _wp1 = currentWaypoint _grp;

// If all waypoints are 'completed', then the index is 1 greater than the last valid index.
// If there are no waypoints, then the index is 0
if (_wp1 in [0, count _wps]) exitWith {["ERROR: Failed to determine waypoint"] call ares_fnc_ShowZeusMessage};
_wp1 = _wps select _wp1;

_grp setVariable ["fp_orig_mode", [combatMode _grp, behaviour (leader _grp)]];
_grp setCombatMode "BLUE";
_grp setBehaviour "CARELESS";
_grp setSpeedMode "FULL";
_grp enableAttack false;
{
    private _unit = _x;
    {_unit disableAI _x} forEach AI_MODES;
    _x setUnitPos "UP";
} forEach _units;

private _wpStatements = {
    private _grp = group this;
    [(_grp getVariable ['fp_forcewp_id', -1])] call CBA_fnc_removePerFrameHandler;
    _grp setVariable ['fp_forcewp_id', nil];

    {
        private _unit = _x;
        {_unit enableAI _x} forEach AI_MODES;
        _x forceSpeed -1;
        _x setunitPos 'AUTO';
    } forEach units _grp;

    _grp setCombatMode ((_grp getVariable ['fp_orig_mode', ['YELLOW']]) select 0);
    _grp setBehaviour ((_grp getVariable ['fp_orig_mode', ['', 'AWARE']]) select 1);
    _grp setSpeedMode 'NORMAL';
    _grp enableAttack true;
};
_wp1 setWaypointStatements ["true", _wpStatements call ace_common_fnc_codeToString];

private _pfh = {
    params ["_args", "_id"];
    _args params ["_grp", "_wp", "_origWpPos"];
    private _wpPos = waypointPosition _wp;

    private _units = units _grp select {alive _x && {!(_x getVariable ["ACE_isUnconcious", false])}};
    private _noUnits = count _units == 0;
    if (_noUnits ||
        {(waypointVisible _wp) isEqualType 0} ||
        {!(_wpPos isEqualTo _origWpPos)}
    ) exitWith {
        [_id] call CBA_fnc_removePerFrameHandler;
        _grp setVariable ['fp_forcewp_id', nil];

        {
            private _unit = _x;
            {_unit enableAI _x} forEach AI_MODES;
            _x forceSpeed -1;
            _x setUnitPos "AUTO";
            _x doMove (getPosATL _x);
        } forEach units _grp;

        _grp setCombatMode ((_grp getVariable ['fp_orig_mode', ['YELLOW']]) select 0);
        _grp setBehaviour ((_grp getVariable ['fp_orig_mode', ['', 'AWARE']]) select 1);
        _grp setSpeedMode 'NORMAL';
        _grp enableAttack true;
    };

    {
        _x forceSpeed (_x getSpeed "FAST");
        _x doMove _wpPos
    } forEach _units;
};

private _pfhId = [_pfh, 3, [_grp,  _wp1, waypointPosition _wp1]] call CBA_fnc_addPerFrameHandler;
_grp setVariable ["fp_forcewp_id", _pfhId];
*/
