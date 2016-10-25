/*
* Author: Cuel
* AI stuff for zeus
*
* Arguments:
* Object(s), single or array
*
* Public: Yes
*/
#include "script_component.hpp"

params [["_mode", ""], ["_grp", objNull]];
if (_grp isEqualType objNull) then {_grp = [_grp] call CBA_fnc_getGroup};
if (!(_grp isEqualType grpNull) ||
    {count units _grp == 0} ||
    {{isPlayer _x} count units _grp > 0}
) exitWith {};

switch (toUpper _mode) do {
  case "PATROL": {
      private _radius = ["50", "100", "150", "200", "250", "300", "400", "500"];
      private _args = ["Patrol settings", [
        ["Radius (m)", _radius, 2],
        ["Search buildings", ["Yes", "No"], 0]
      ]] call Ares_fnc_ShowChooseDialog;
      if (count _args == 0) exitWith {};

      _radius = parseNumber (_radius select (_args select 0));
      private _cond = ["", "this spawn CBA_fnc_searchNearby"] select (_args select 1);
      private _cbaArgs = [_grp,  _grp, _radius, 6, "MOVE", "AWARE", "YELLOW", "LIMITED", "STAG COLUMN", _cond, [3,6,9]];
      _cbaArgs remoteExecCall ["CBA_fnc_taskPatrol", leader _grp];
  };

  case "DEFEND": {
      if (local _grp) then {
        (leader _grp) setVariable ["acex_headless_blacklist", true, true];
      };
      private _radius = ["50", "100", "150", "200", "250", "300", "400", "500"];
      private _treshold = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"];
      private _args = ["Defend settings", [
        ["Radius (m)", _radius, 2],
        ["Building pos treshold", _treshold, 1]
      ]] call Ares_fnc_ShowChooseDialog;
      if (count _args == 0) exitWith {};

      _radius = parseNumber (_radius select (_args select 0));
      _treshold = parseNumber (_treshold select (_args select 1));
      [_grp, _grp, _radius, _treshold, true] remoteExecCall ["CBA_fnc_taskDefend", leader _grp];
  };

  case "GARRISON": {
    private _radius = ["Closest building","50", "100", "150", "200", "250", "300", "400", "500"];
    private _args = ["Garrison settings", [
      ["Radius (m)", _radius, 2],
      ["Allow roof", ["Yes", "No"], 0],
      ["Fill buildings in radius evenly", ["Yes", "No"], 1],
      ["Lock units in place", ["Yes", "No"], 0]
    ]] call Ares_fnc_ShowChooseDialog;
    if (count _args == 0) exitWith {};

    _args params ["_r"];
    _radius = [parseNumber (_radius select _r), -1] select (_r == 0);
    private _putOnRoof = [true, false] select (_args select 1);
    private _fillEvenly = [true, false] select (_args select 2);
    private _lockUnits = [true, false] select (_args select 3);
    [QGVAR(garrison), [_grp, _radius, _putOnRoof, _fillEvenly, _lockUnits], _grp] call CBA_fnc_targetEvent;
  };

  case "FORCE_WP": {
      private _wpid = _grp getVariable ["fp_forcewp_id", -1];
      if (_wpid != -1) exitWith {
          _wpid call CBA_fnc_removePerFrameHandler;
      };

      if (!local _grp) exitWith {["ERROR: Group must be local"] call ares_fnc_ShowZeusMessage};
      _grp setVariable ["acex_headless_blacklist", true, true];

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
      {_x disableAI "TARGET"; _x disableAI "AUTOTARGET"; _x disableAI "AUTOCOMBAT"; _x setUnitPos "UP";} forEach _units;

      _wp1 setWaypointStatements ["true", format [
          "
              %1;
              private _grp = group this;
              [(_grp getVariable ['fp_forcewp_id', -1])] call CBA_fnc_removePerFrameHandler;
              _grp setVariable ['fp_forcewp_id', nil];
              _grp enableAttack true;
              _grp setCombatMode (((group this) getVariable ['fp_orig_mode', ['YELLOW']]) select 0);
              _grp setBehaviour (((group this) getVariable ['fp_orig_mode', ['AWARE']]) select 1);
              {_x enableAI 'TARGET'; _x enableAI 'AUTOTARGET'; _x enableAI 'AUTOCOMBAT'; _x forceSpeed -1; _x setunitPos 'AUTO';} forEach units _grp;
              _grp setSpeedMode 'NORMAL';
          ",
          waypointStatements _wp1
      ]];

      private _pfhId = [{
          params ["_args", "_id"];
          _args params ["_grp", "_wp", "_origWpPos"];
          private _wpPos = waypointPosition _wp;

          private _units = units _grp select {alive _x && {!(_x getVariable ["ACE_isUnconcious", false])}};
          if (count _units == 0 ||
              {(waypointVisible _wp) isEqualType 0} ||
              {!(_wpPos isEqualTo _origWpPos)}
          ) exitWith {
              [_id] call CBA_fnc_removePerFrameHandler;
              _grp setVariable ['fp_forcewp_id', nil];
              {
                  _x forceSpeed -1;
                  _x enableAI "TARGET";
                  _x enableAI "AUTOTARGET";
                  _x enableAI "AUTOCOMBAT";
                  _x setUnitPos "AUTO";
                  _x doMove (getPosATL _x);
              } forEach units _grp;
              _grp enableAttack true;
              _grp setCombatMode ((_grp getVariable ['fp_orig_mode', ['YELLOW']]) select 0);
              _grp setBehaviour ((_grp getVariable ['fp_orig_mode', ['', 'AWARE']]) select 1);
              _grp setSpeedMode 'NORMAL';
          };

          /*{
              _x forceSpeed (_x getSpeed "FAST");
              _x doMove _wpPos;
          }forEach _units;*/
      }, 3, [_grp,  _wp1, waypointPosition _wp1]] call CBA_fnc_addPerFrameHandler;

      _grp setVariable ["fp_forcewp_id", _pfhId];
      ["Group will try to reach their waypoint no matter what"] call ares_fnc_ShowZeusMessage;
  };
};
