/*
    Description:
        Handles FP group AI
*/

params ["_mode", "_grp"];
if (_grp isEqualType objNull) then {_grp = [_grp] call CBA_fnc_getGroup};
if (!(_grp isEqualType grpNull) || {{alive _x} count units _grp == 0} || {{isPlayer _x} count units _grp > 0}) exitWith {};

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
      private _cbaArgs = [_grp,  _grp, _radius, 8, "MOVE", "AWARE", "YELLOW", "NORMAL", "STAG COLUMN", _cond, [3,6,9]];
      _cbaArgs remoteExecCall ["CBA_fnc_taskPatrol", leader _grp];
  };

  case "DEFEND": {
      if (local _grp) then {
        _grp setVariable ["acex_headless_blacklist", true, true];
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
    if (!local _grp) exitWith {
      ["ERROR: Group must be local"] call ares_fnc_ShowZeusMessage;
    };
    _grp setVariable ["acex_headless_blacklist", true, true];

    private _radius = ["Closest building","50", "100", "150", "200", "250", "300", "400", "500"];
    private _args = ["Garrison settings", [
      ["Radius (m)", _radius, 2],
      ["Put on roof", ["Yes", "No"], 0],
      ["Fill buildings evenly", ["Yes", "No"], 1],
      ["Lock units in place", ["Yes", "No"], 1]
    ]] call Ares_fnc_ShowChooseDialog;
    if (count _args == 0) exitWith {};

    _args params ["_r"];
    _radius = [parseNumber (_radius select _r), -1] select (_r == 0);
    private _putOnRoof = [true, false] select (_args select 1);
    private _fillEvenly = [true, false] select (_args select 2);
    private _lockUnits = [true, false] select (_args select 3);
    private _unUsed = [getPosATL (leader _grp), units _grp, _radius, _putOnRoof, _fillEvenly] call Ares_fnc_ZenOccupyHouse;

    if (count _unUsed > 0) then {
      _grp2 = createGroup (side (_unUsed select 0));
      {
        [_x] joinSilent _grp2;
      }foreach _unUsed;

      // doesn't matter if this group gets transferred to HC, it's only waypoints
      [_grp2, getPosATL (leader _grp), _radius, 6+(round (random 4)), "MOVE", "SAFE", "YELLOW", "LIMITED", "COLUMN", "[this] spawn CBA_fnc_searchNearby", [3+(random 4),10,10+(random 5)]] call CBA_fnc_taskPatrol;
    };

    if (_lockUnits) then {
      {
        _x disableAI "MOVE";
        _x addEventHandler ["Hit", {
          params ["_unit"];
          if (!alive _unit) exitWith {};
          _unit setVariable ["fp_enabled", true];
          _unit enableAI "MOVE";
          // ai seems unable to move unless doing this
          _unit doMove [(getPosATL _unit select 0)+1, (getPosATL _unit select 1) +1, getPosATL _unit select 2];
        }];
      }forEach units _grp;

      [{
        params ["_units", "_id"];
        if ({!alive _x || {_x getVariable ["fp_enabled", false]}} count _units == count _units) exitWith {
          [_id] call CBA_fnc_removePerFrameHandler;
        };

        {
          if (alive _x && {!(_x getVariable ["fp_enabled", false])} && {simulationEnabled _x}) then {
            if (_x distance (_x findNearestEnemy (getPosATL _x)) < 60 || {[_x, 30] call CBA_fnc_nearPlayer}) then {
              _x setVariable ["fp_enabled", true];
              _x enableAI "MOVE";
              _x doMove [(getPosATL _x select 0)+1, (getPosATL _x select 1) +1, getPosATL _x select 2];
            };
          };
        } forEach units _grp;
      }, 3.23, units _grp] call CBA_fnc_addPerFrameHandler;
    };
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
      {_x disableAI "TARGET"; _x disableAI "AUTOTARGET"} forEach _units;
      _grp setCombatMode "BLUE";
      _grp setBehaviour "CARELESS";
      _grp setSpeedMode "FULL";
      _grp enableAttack false;

      _wp1 setWaypointStatements ["true", format [
          "
              %1;
              private _grp = group this;
              [(_grp getVariable ['fp_forcewp_id', -1])] call CBA_fnc_removePerFrameHandler;
              _grp setVariable ['fp_forcewp_id', nil];
              _grp enableAttack true;
              _grp setCombatMode (((group this) getVariable ['fp_orig_mode', ['YELLOW']]) select 0);
              _grp setBehaviour (((group this) getVariable ['fp_orig_mode', ['AWARE']]) select 1);
              {_x enableAI 'TARGET'; _x enableAI 'AUTOTARGET';  _x forceSpeed -1} forEach units _grp;
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
                  _x doMove (getPosATL _x);
              } forEach units _grp;
              _grp enableAttack true;
              _grp setCombatMode ((_grp getVariable ['fp_orig_mode', ['YELLOW']]) select 0);
              _grp setBehaviour ((_grp getVariable ['fp_orig_mode', ['', 'AWARE']]) select 1);
              _grp setSpeedMode 'NORMAL';
          };

          {
              _x forceSpeed (_x getSpeed "FAST");
              _x doMove _wpPos;
          }forEach _units;
      }, 3, [_grp,  _wp1, waypointPosition _wp1]] call CBA_fnc_addPerFrameHandler;

      _grp setVariable ["fp_forcewp_id", _pfhId];
      ["Group will try to reach their waypoint no matter what"] call ares_fnc_ShowZeusMessage;
  };
};
