/*
* Author: Cuel
* Register a custom module
*
* Arguments:
* 0: Display name - <string>
* 1: Code - <code>. Will be called with [_pos, _unitUnderCursor]
*
* Returns:
* <boolean>
*
* Public: Yes
*/
#include "script_component.hpp"
if (count GVAR(registeredCustomModules) >= 10 || !params [
    ["_name", "", [""]],
    ["_code", {}, [{}]]
]) exitWith {false};

GVAR(registeredCustomModules) pushBack [_name, _code];
true
