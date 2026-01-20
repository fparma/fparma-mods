#include "script_component.hpp"

params ["_saveName","_mapName",["_markersData",[]]];

if (_mapName != worldName) exitWith {
    playSound "3DEN_notificationWarning";
    systemChat format ["fpa-saveMarkers: Save with name ""%1"" is made for map ""%2"" but we are on ""%3""!", _saveName, _mapName, worldName];
};

// client who loads markers will be owner
private _playerID = getPlayerID player;
private _markerIDIndex = 0;

INFO_4("starting to load %1 markers from save %2 on terrain %3 for player %4",count _markersData,_saveName,_mapName,_playerID);

[_playerID, _markerIDIndex, _markersData] call FUNC(loadMarkersLoop);
