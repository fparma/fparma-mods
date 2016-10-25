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

if (!isServer) exitWith {
    _this remoteExecCall [QUOTE(FUNC(addToCurators)), 2];
};

if (!(_this isEqualType [])) then {
    _this = [_this];
};

{
  _x addCuratorEditableObjects [_this, true];
} forEach allCurators;
