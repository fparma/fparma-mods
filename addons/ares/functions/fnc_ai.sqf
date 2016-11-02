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
        (leader _grp) setVariable ["acex_headless_blacklist", true, true];
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
        [QGVAR(forceMove), [_grp], _grp] call CBA_fnc_targetEvent;
        ["Group will try to reach their waypoint no matter what"] call ares_fnc_ShowZeusMessage;
    };
};
