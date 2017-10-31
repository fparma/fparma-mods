/*
 * Author: Cuel
 * Respawn menu using strategic map like the normal respawn menu but working when alive
 *
 * Arguments:
 * args passed to strategic map, see: https://community.bistudio.com/wiki/BIS_fnc_StrategicMapOpen
 * 0 - Mission data for strategeic map, optional. Defaults to respawn points
 * 1 - Middle position when map is opened
 * 2 - orbat?
 * 3 - markers revealed when opened
 * 4 - custom imges
 * 5 - custom text for map
 * Public: Yes
 */

#include "script_component.hpp"
if (!hasInterface) exitWith {displayNull};

params [
  ["_missions", []],
  ["_middle", [0,0,0]],
  ["_orbatGroups", []],
  ["_hiddenMarkersList", []],
  ["_customImagesList", []],
  ["_strategicText", "Choose Respawn"]
];

if (_missions isEqualTo []) then {
  private _markers = [side group player] call BIS_fnc_getRespawnMarkers apply {[[_x] call CBA_fnc_getPos, ""]};
  // this is the dumbest shit
  private _respawns = [player, false] call BIS_fnc_getRespawnPositions;
  private _names = [player, true] call BIS_fnc_getRespawnPositions;
  private _idx = -1;
  private _respawnPositions = _respawns apply {_idx = _idx + 1; [[_x] call CBA_fnc_getPos, _names select _idx]};

  _idx = 0;
  _missions = (_respawnPositions + _markers) apply {
    _x params ["_pos", "_name"];
    if (_name isEqualTo "") then {
      private _locTypes = ["NameCityCapital","NameCity","NameVillage"];
      private _nearbyLocation = nearestLocations [_pos, _locTypes, 1000] param [0, locationNull];
      if (!isNull _nearbyLocation) then {
        _name = format ["Near %1", text _nearbyLocation];
      } else {
        _idx = _idx + 1;
        _name = format ["Respawn #%1", _idx];
      };
    };

    [_pos, {player setPos (param [9, getPos player])}, _name, "", "", "", 1, _pos]
  };
};

if (_missions isEqualTo []) exitWith {displayNull};

if (_middle - [0] isEqualTo []) then {
  {_middle = _middle vectorAdd (_x select 0)} foreach _missions;
  _middle = _middle vectorMultiply (1 / count _missions);
};

private _isNight = daytime > 20 || daytime < 6;
// return strategic map
[
  [] call BIS_fnc_displayMission,   //0: DISPLAY - parent display. When empty, mission display is used.
  _middle,                          //1: ARRAY - default view position in format [x,y,y] or [x,y]
  _missions,                        //2: ARRAY - list of missions in format:
  _orbatGroups,                     //3: ARRAY - list of ORBAT groups in format:
  _hiddenMarkersList,               //4: ARRAY - list of markers revealed in strategic map (will be hidden when map is closed)
  _customImagesList,                //5: ARRAY - list of custom images in format:
  0,                                //6: NUMBER - value in range <0-1> defining weather on strategic map (i.e. density of clouds)
  _isNight,                         //7: BOOL - true for night version of strategic map (darker with blue tone)
  25,                                //8: NUMBER - default map scale coeficient (1 is automatic scale)
  false,                             //9: BOOL - true to enable simulation while the map is opened (default: false)
  _strategicText                   //10: STRING - bottom bar action label text (default: "Select a mission")
] call FUNC(strategicMapOpen);
