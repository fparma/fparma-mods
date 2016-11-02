/*
* Author: Cuel
* AI occupy house
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
#include "script_component.hpp"
params ["_grp", "_radius", ["_putOnRoof", true], ["_fillEvenly", false], ["_lockUnits", true]];

if (!local _grp) exitWith {};
if (hasInterface || isServer) then {
    (leader _grp) setVariable ["acex_headless_blacklist", true, true];
};

private _unUsed = [getPosATL (leader _grp), units _grp, _radius, _putOnRoof, _fillEvenly] call FUNC(zenOccupy);

if (count _unUsed > 0) then {
  _grp2 = createGroup (side _grp);
  {
      [_x] joinSilent _grp2;
  }foreach _unUsed;

  private _patrolRadius = [40, _radius - 50] select (_radius > 101);
  private _args = [_grp2, getPosATL (leader _grp), _radius, 4, "MOVE", "SAFE", "YELLOW", "LIMITED", "COLUMN", "[this] spawn CBA_fnc_searchNearby", [3 + round random 4,10 ,10 + round random 5]];
  _args call CBA_fnc_taskPatrol;
};

if (_lockUnits) then {
  {
    _x disableAI "PATH";

    _x addEventHandler ["FiredNear", {
        params ["_unit", "_firer"];
        if (!alive _unit  || {side group _unit == side group _firer}) exitWith {};

        private _duckDelay = _unit getVariable [QGVAR(duckDelay), 0];
        if (CBA_missionTime < _duckDelay) exitWith {};

        private _delay = 1 + random 3;
        _unit setVariable [QGVAR(duckDelay), CBA_missionTime + _delay + (1 + random 2)];
        _unit setUnitPos "MIDDLE";
        [{
            params ["_unit"];
            if (!alive _unit) exitWith {};
            _unit setUnitPos "UP";
        }, _unit, _delay] call CBA_fnc_waitAndExecute;

    }];

    _x addEventHandler ["Hit", {
      params ["_unit"];
      if (!alive _unit) exitWith {};
      _unit enableAI "PATH";
      _unit doMove ([getPosATL _unit, 1] call CBA_fnc_randPos);
    }];
  } forEach units _grp;
};
