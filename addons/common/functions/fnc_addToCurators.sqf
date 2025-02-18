/*
 * Author: Cuel
 * Adds whatever to curators
 *
 * Arguments:
 * Object(s), single or array
 *
 * Public: Yes
 */
#include "script_component.hpp"

if !(isServer) exitWith {
    _this remoteExecCall [QUOTE(FUNC(addToCurators)), 2];
};

private _thisNew = _this;
if !(_thisNew isEqualType []) then {
    _thisNew = [_thisNew];
};

{
  _x addCuratorEditableObjects [_thisNew, true];
} forEach allCurators;
