/*
    Function: fpa_ai_fnc_spawn
    API:
        Server
    Description:
        Spawns all units associated with an ID
    Parameters:
    _id - ID string
    Example:
    (begin example)
        ["id1"] call fpa_ai_fnc_spawn;
    (end)
    Author:
    Tinter 2021-07-19
*/

#include "script_component.hpp"
if (!isServer || {isNil QGVAR(savedGroups)}) exitWith {false};
if (!params [["_id", "", [""]]]) exitWith {false};

private _groups = GVAR(savedGroups) getOrDefault [_id, []];
private _hcs = entities "HeadlessClient_F";
if (_hcs isNotEqualTo []) then {
    [QGVAR(spawnGroups), [_groups, _id], selectRandom _hcs] call CBA_fnc_targetEvent;
} else {
    [QGVAR(spawnGroups), [_groups, _id]] call CBA_fnc_localEvent;
};
GVAR(savedGroups) set [_id, []];

true
