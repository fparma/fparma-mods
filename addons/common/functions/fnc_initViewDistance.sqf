/*
 * Author: diwako
 * Sets up the viewdistance ace interactions
 *
 * Arguments:
 *
 * Public: No
 */
#include "script_component.hpp"

private _insertChildren = {
    params ["_target", "_player", "_params"];
    _params params ["_setOveral", "_setObject"];

    // Add children to this action
    private _actions = [];
    private _min = GVAR(viewdistanceMaximum) min GVAR(viewdistanceMinimum);
    private _max = GVAR(viewdistanceMaximum) max GVAR(viewdistanceMinimum);

    private _modifierFunc = {
        params ["_target", "_player", "_params", "_actionData"];
        _params params ["_dist", "_setOveral", "_setObject"];

        if (_setOveral && !_setObject && {viewDistance isEqualTo _dist}) exitWith {
            _actionData set [2, ["", [221, 0, 0] call BIS_fnc_colorRGBtoHTML]];
            nil
        };
        if (_setObject && !_setOveral && {(getObjectViewDistance select 0) isEqualTo _dist}) exitWith {
            _actionData set [2, ["", [221, 0, 0] call BIS_fnc_colorRGBtoHTML]];
            nil
        };
        if (_setOveral && _setOveral && {(viewDistance isEqualTo _dist) && {(getObjectViewDistance select 0) isEqualTo _dist}}) exitWith {
            _actionData set [2, ["", [221, 0, 0] call BIS_fnc_colorRGBtoHTML]];
            nil
        };

        nil;
    };

    for "_i" from _min to _max step GVAR(viewdistanceStep) do {
        private _iStr = str _i;
        private _action = [_iStr,_iStr,"",{
            params ["", "", "_params"];
            _params params ["_dist", "_setOveral", "_setObject"];
            if (_setOveral) then {
                setViewDistance _dist;
            };
            if (_setObject) then {
                setObjectViewDistance _dist;
            };
        },{true}, nil, [_i, _setOveral, _setObject], nil, nil, nil, _modifierFunc] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _target];
    };

    _actions
};

private _actDistCat = ["ViewDist","View distance","",{},{GVAR(enableViewdistanceSelector)}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _actDistCat, true] call ace_interact_menu_fnc_addActionToClass;
_actDistCat = ["OverallDist","Overall","",{},{true},_insertChildren, [true, false]] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions","ViewDist"], _actDistCat, true] call ace_interact_menu_fnc_addActionToClass;
_actDistCat = ["ObjectDist","Object","",{},{true},_insertChildren, [false, true]] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions","ViewDist"], _actDistCat, true] call ace_interact_menu_fnc_addActionToClass;
_actDistCat = ["BothtDist","Both","",{},{true},_insertChildren, [true, true]] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions","ViewDist"], _actDistCat, true] call ace_interact_menu_fnc_addActionToClass;
