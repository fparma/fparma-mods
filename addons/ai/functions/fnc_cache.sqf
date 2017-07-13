/*
    Function: FP_fnc_cache

    API:
        Server

    Description:
        Cache (hide/disable) a group of units for later use in the mission
        @TODO: need any HC support?

    Parameters:
    _units - A single unit, a group, or array of units to cache.
        If STRING, will re-cache all previously cached units with this ID
        In that case, second parameter can be left blank.
    _id - The ID to use for this "cache", which can be used with FP_fnc_unCache to enable the units again

    Example:
    (begin example)
        [group this, "id1"] call FP_fnc_cache;
    (end)

    Author:
    Tinter/Cuel 2016-02-15
*/

if (!isServer) exitWith {};
params [
  ["_units", [], ["", objNull, grpNull, []]],
  ["_id", "", [""]]
];

if (isNil "FP_cachedGroups") then {
  FP_cachedGroups = [[], []] call CBA_fnc_hashCreate;
};

private _isReCache = _units isEqualType "";
if (_isReCache) then {
  _id = _units;
  _units = [FP_cachedGroups, _id] call CBA_fnc_hashGet;
} else {
  if (!(_units isEqualType [])) then {
    if (_units isEqualType objNull) exitWith {_units = [_units]};
    if (_units isEqualType grpNull) then {_units = units _units};
  };
};

if (_id == "" || {count _units == 0}) exitWith {
  ["Wrong parameters or no units: %1", _this] call BIS_fnc_error;
  false
};

{
  _x allowDamage false;
  _x hideObjectGlobal true;
  _x enableSimulationGlobal false;

  private _veh = vehicle _x;
  if (_veh != _x && {simulationEnabled _veh}) then {
    _veh enableSimulationGlobal false;
    _veh hideObjectGlobal true;
  };
} forEach (_units select {alive _x && {simulationEnabled _x} && {!isPlayer _x}});

if (_isReCache) exitWith {true};
private _existingUnits = [FP_cachedGroups, _id] call CBA_fnc_hashGet;

if (count _existingUnits == 0) exitWith {
  [FP_cachedGroups, _id, _units] call CBA_fnc_hashSet;
  true
};

{
  _existingUnits pushBackUnique _x;
} forEach _units;
[FP_cachedGroups, _id, _existingUnits] call CBA_fnc_hashSet;

true
