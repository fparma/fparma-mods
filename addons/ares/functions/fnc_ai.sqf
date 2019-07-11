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
_grp = [_grp] call CBA_fnc_getGroup;
private _units = units _grp;
private _zen = !isNil "zen_custom_modules_fnc_register";
private _msgFnc = [ares_fnc_ShowZeusMessage, zen_common_fnc_showMessage] select _zen;
if (_grp isEqualTo grpNull || {count _units == 0} || {{isPlayer _x} count _units > 0}) exitWith {
    ["Invalid group"] call _msgFnc;
};

switch (toUpper _mode) do {
    case "PATROL": {
        private _radius = ["50", "100", "150", "200", "250", "300", "400", "500"];
        private _menuName = "Patrol settings";
        if (_zen) then {
            [_menuName, [
                ["COMBO", "Radius (m)", [_radius apply {parseNumber _x}, _radius]],
                ["CHECKBOX", "Search buildings", true]
            ], {
                params ["_dialog", "_args"];
                _dialog params ["_radius", "_search"];
                _args params ["_grp"];
                private _cond = ["", "this spawn CBA_fnc_searchNearby"] select _search;
                private _cbaArgs = [_grp,  _grp, _radius, 6, "MOVE", "AWARE", "YELLOW", "LIMITED", "STAG COLUMN", _cond, [3,6,9]];
                _cbaArgs remoteExecCall ["CBA_fnc_taskPatrol", leader _grp];
            }, {}, [_grp]] call zen_dialog_fnc_create;
        } else {
            private _args = [_menuName, [
                ["Radius (m)", _radius, 2],
                ["Search buildings", ["Yes", "No"], 0]
            ]] call Ares_fnc_ShowChooseDialog;
            if (count _args == 0) exitWith {};

            _radius = parseNumber (_radius select (_args select 0));
            private _cond = ["", "this spawn CBA_fnc_searchNearby"] select (_args select 1);
            private _cbaArgs = [_grp,  _grp, _radius, 6, "MOVE", "AWARE", "YELLOW", "LIMITED", "STAG COLUMN", _cond, [3,6,9]];
            _cbaArgs remoteExecCall ["CBA_fnc_taskPatrol", leader _grp];
        };
    };

    case "DEFEND": {
        (leader _grp) setVariable ["acex_headless_blacklist", true, true];
        private _radius = ["50", "100", "150", "200", "250", "300", "400", "500"];
        private _treshold = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10"];
        private _menuName = "Defend settings";
        if (_zen) then {
            [_menuName, [
                ["COMBO", "Radius (m)", [_radius apply {parseNumber _x}, _radius]],
                ["COMBO", "Building pos treshold", [_treshold apply {parseNumber _x}, _treshold]]
            ], {
                params ["_dialog", "_args"];
                _dialog params ["_radius", "_treshold"];
                _args params ["_grp"];
                [_grp, _grp, _radius, _treshold, true] remoteExecCall ["CBA_fnc_taskDefend", leader _grp];
            }, {}, [_grp]] call zen_dialog_fnc_create;
        } else {
            private _args = [_menuName, [
                ["Radius (m)", _radius, 2],
                ["Building pos treshold", _treshold, 1]
            ]] call Ares_fnc_ShowChooseDialog;
            if (count _args == 0) exitWith {};

            _radius = parseNumber (_radius select (_args select 0));
            _treshold = parseNumber (_treshold select (_args select 1));
            [_grp, _grp, _radius, _treshold, true] remoteExecCall ["CBA_fnc_taskDefend", leader _grp];
        };
    };

    case "FORCE_WP": {
        private _wps = waypoints _grp;
        private _wp1 = currentWaypoint _grp;
        if (_wp1 in [0, count _wps]) exitWith {["ERROR: Group needs a waypoint to reach"] call _msgFnc};
        [QGVAR(forceMove), [_grp], _grp] call CBA_fnc_targetEvent;
        ["Group will try to reach their waypoint no matter what"] call _msgFnc;
    };
};
