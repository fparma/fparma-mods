    /*
    Function: fpa_ai_fnc_despawn
    API:
        Server
    Description:
        Despawns a group, saving certain information for later use in the mission
    Parameters:
    _group - An object, a group or to a string to use "recaching" to save units that have been spawned with fpa_ai_fnc_spawn.
    _id - The ID to use for saving the information, which can be used with FP_fnc_spawn to spawn the units again
    _init - Code to run on the group when they spawn in, the group will be passed as the first argument to the code
    _params - Array of parameters passed to the code that will be accessed after the group, so from the second parameter and so on
    Example:
    (begin example)
        [group this, "id1"] call fpa_ai_fnc_despawn;
        [group this, "id1", {[_this#0] call cba_fnc_taskDefend}] call fpa_ai_fnc_despawn;
        ["id1"] call fpa_ai_fnc_despawn;
    (end)
    Author:
    Tinter 2021-07-19
*/

#include "script_component.hpp"
if !(isServer) exitWith {};
params [
    ["_group", [], ["", objNull, grpNull]],
    ["_id", "", [""]],
    ["_init", {}, [{}]],
    ["_params",[], [[]]]
];

if (isNil QGVAR(savedGroups)) then {
    GVAR(savedGroups) = createHashMap;
};

private _isReCache = _group isEqualType "";
private _groups = [];
private _savedGroups = [];
private _newGroups = [];
if (_isReCache) then {
    _id = _group;
    _groups = GVAR(activeGroups) getOrDefault [_id, []];
    _savedGroups = GVAR(savedGroups) getOrDefault [_id, []];

    if !(_groups isEqualTo []) then {
        GVAR(activeGroups) set [_id, []];
        GVAR(savedGroups) set [_id, []];
    };
} else {
    if !(_group isEqualType grpNull) then {
        if (_group isEqualType objNull) then {_group = group _group};
    };
    _groups = [_group];
};

if (_id == "" ) exitWith {
    ["Wrong parameter: %1", _this] call BIS_fnc_error;
    false
};
{
    private _group = _x;
    if (_isReCache) then {
        _group = _x#0;
        _params = _x#1;
        _init = _x#2;
    };
    if ((units _group) isEqualTo []) then {deleteGroup _group; continue};

    private _info = [side _group, _init, _params, currentWaypoint _group, combatMode _group, combatBehaviour _group, formation _group, speedMode _group];

    private _units = [];
    private _realUnits = units _group;
    {
        _units pushBack [typeOf _x, getPosWorld _x, [vectorDir _x, vectorUp _x], getUnitLoadout _x, unitPos _x];
    } foreach _realUnits;

    private _vehicles = [];
    private _realVehicles = [_group, true] call BIS_fnc_groupVehicles;
    {
        private _crew = fullCrew _x;
        {
            private _unit = _x#0;
            private _index = _realUnits findIf {_x == _unit};
            _x set [0, _index];
        } foreach _crew;
        _vehicles pushBack [typeOf _x, getPosWorld _x, [vectorDir _x, vectorUp _x], _crew, getBackpackCargo _x, getItemCargo _x, getMagazineCargo _x, getWeaponCargo _x];
    } foreach _realVehicles;

    private _waypoints = [];
    {
        //waypointAttachedObject
        //waypointAttachedVehicle
        //waypointHousePosition
        _waypoints pushBack [
            waypointType _x,
            waypointPosition _x,
            waypointBehaviour _x,
            waypointCombatMode _x,
            waypointCompletionRadius _x,
            waypointDescription _x,
            waypointForceBehaviour _x,
            waypointFormation _x,
            waypointLoiterAltitude _x,
            waypointLoiterRadius _x,
            waypointLoiterType _x,
            waypointName _x,
            waypointScript _x,
            waypointSpeed _x,
            waypointStatements _x,
            waypointTimeout _x,
            waypointVisible _x
        ];
    } foreach (waypoints _group);

    private _newGroup = [_info, _units, _vehicles, _waypoints];

    //Cleanup
    {
        deleteVehicle _x;
    } foreach _realUnits;
    {
        deleteVehicle _x;
    } foreach _realVehicles;

    deleteGroup _group;

    _newGroups pushback _newGroup;
} foreach _groups;

private _existingGroups = GVAR(savedGroups) getOrDefault [_id, []];
_existingGroups append _newGroups;
GVAR(savedGroups) set [_id, _existingGroups];

true
