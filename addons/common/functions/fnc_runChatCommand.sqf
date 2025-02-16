/*
 * Author: Cuel
 * Runs a chat command
 *
 * Arguments:
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_args", "_invokedCommand"];
private _command = GVAR(chatCommands) getVariable [_invokedCommand, []];
_command params ["", ["_code", {}], "_adminOnly", "_argsForCode"];

if (_code isNotEqualTo {} && (!_adminOnly || {call FUNC(isAdmin)})) then {
  // delay a frame to have the chat update with the message before running the function
  [{
    [_this select 0, _this select 1] call (_this select 2);
  }, [_args, _argsForCode, _code]] call CBA_fnc_execNextFrame;
};
