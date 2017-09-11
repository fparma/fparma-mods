/*
    Function: fpa_ai_fnc_unCache

    API:
        Server

    Description:
        Uncache all units associated with an ID

    Parameters:
    _id - ID string

    Example:
    (begin example)
        ["id1"] call fpa_ai_fnc_unCache;
    (end)

    Author:
    Tinter/Cuel 2016-02-15
*/

if (!isServer) exitWith {};
if (isNil QGVAR(cachedGroups)) exitWith {false};
if (!params [["_id", "", [""]]]) exitWith {false};

private _units = [GVAR(cachedGroups), _id] call CBA_fnc_hashGet;
if (isNil "_units") exitWith {false};

{
  _x allowDamage true;
  _x enableSimulationGlobal true;
  _x hideObjectGlobal false;

  private _veh = vehicle _x;
  if (_veh != _x && {!simulationEnabled _veh}) then {
    _veh enableSimulationGlobal true;
    _veh hideObjectGlobal false;
  };
} forEach _units;

true
