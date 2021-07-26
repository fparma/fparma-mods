/*
    Function: fpa_ai_fnc_spawnGroups
    API:
        Server or HC
    Description:
        Part of spawn/despawn functions, used by fpa_ai_fnc_spawn to delegate the actual spawning to possibly other clients
    Parameters:
    _groups - Array of groups formatted as used by spawning/despawning system
    _id - The id to associate with the spawned groups
    Example:
    (begin example)
        [_groups, _id] call fpa_ai_fnc_spawnGroups;
    (end)
    Author:
    Tinter 2021-07-26
*/

#include "script_component.hpp"
if (!params [["_groups", [], [[]]], ["_id", "", [""]]]) exitWith {false};

private _newGroups = [];

{
    _x params["_info", "_units", "_vehicles", "_waypoints"];
    _info params ["_side", "_init", "_params", "_currentWaypoint", "_combatMode", "_behaviour", "_formation", "_speedMode"];
    private _group = createGroup [_side, true];

    private _spawnedUnits = [];
    {
        _x params["_type", "_pos", "_vectorDirAndUp", "_loadout", "_unitPos"];
        private _unit = _group createUnit [_type, _pos, [], 0, "CAN_COLLIDE"];
        _unit setPosWorld _pos;
        _unit setVectorDirAndUp _vectorDirAndUp;
        _unit setUnitLoadout _loadout;
        _unit setUnitPos _unitPos;
        _spawnedUnits pushback _unit;
    } forEach _units;

    {
        //_itemCargo
        _x params["_type", "_pos", "_vectorDirAndUp", "_crew", "_backpackCargo", "_itemCargo", "_magazineCargo", "_weaponCargo"];
        private _veh = _type createVehicle _pos;
        _veh setPosWorld _pos;
        _veh setVectorDirAndUp _vectorDirAndUp;

        {
            _x params["_crewIndex", "_role", "_cargoIndex", "_turretPath"];
            private _unit = _spawnedUnits#_crewIndex;

            switch (_role) do {
                case "driver": {_unit moveInDriver _veh};
                case "commander": {_unit moveInCommander _veh};
                case "gunner": {_unit moveInGunner _veh};
                case "turret": {_unit moveInTurret [_veh, _turretPath]};
                case "cargo": {_unit moveInCargo [_veh, _cargoIndex]};
            };
        } foreach _crew;

        clearBackpackCargoGlobal _veh;
        clearItemCargoGlobal _veh;
        clearMagazineCargoGlobal _veh;
        clearWeaponCargoGlobal _veh;

        {
            _type = _x;
            _amount = _backpackCargo#1#_forEachIndex;
            _veh addBackpackCargoGlobal [_type, _amount];
        } foreach _backpackCargo#0;

        {
            private _array = _x;
            {
                _type = _x;
                _amount = _array#1#_forEachIndex;
                _veh addItemCargoGlobal [_type, _amount];
            } foreach (_array#0);
        } foreach [_itemCargo, _magazineCargo, _weaponCargo];

    } forEach _vehicles;

    {
        if (_currentWaypoint > _forEachIndex) then {continue};
        _x params[
        "_type",
        "_pos",
        "_behaviour",
        "_combatMode",
        "_completionRadius",
        "_description",
        "_forceBehaviour",
        "_formation",
        "_loiterAltitude",
        "_loiterRadius",
        "_loiterType",
        "_name",
        "_script",
        "_speed",
        "_statements",
        "_timeout",
        "_visible"

        ];
        private _wp = _group addWaypoint [[0,0,0], 0];
        _wp setWaypointType _type;
        _wp setWaypointPosition [_pos, 0];
        _wp setWaypointBehaviour _behaviour;
        _wp setWaypointCombatMode _combatMode;
        _wp setWaypointCompletionRadius _completionRadius;
        _wp setWaypointDescription _description;
        _wp setWaypointForceBehaviour _forceBehaviour;
        _wp setWaypointFormation _formation;
        _wp setWaypointLoiterAltitude _loiterAltitude;
        _wp setWaypointLoiterRadius _loiterRadius;
        _wp setWaypointLoiterType _loiterType;
        _wp setWaypointName _name;
        _wp setWaypointScript _script;
        _wp setWaypointSpeed _speed;
        _wp setWaypointStatements _statements;
        _wp setWaypointTimeout _timeout;
        _wp setWaypointVisible _visible;
    } forEach _waypoints;
    private _leader = leader _group;

    _group setCombatMode _combatMode;
    _group setCombatBehaviour _behaviour;
    _group setFormation _formation;
    _group setSpeedMode _speedMode;
    private _callParams = [_group];
    _callParams append _params;
    _callParams call _init;

    _newGroups pushBack [_group, _params, _init];
} forEach _groups;

[QGVAR(updateActiveGroups), [_newGroups, _id]] call CBA_fnc_serverEvent;

true
