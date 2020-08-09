/*
* Author: Cuel
*
* Description:
* Registers a FP chat command
*
* Arguments:
* 0 - string command. if no dot is provided, the command will be prefixed with "fp."
* 1 - code to execute
* 2 - description for the command (if empty string the command is not visible using #fp.help)
* 3 - admin only (true default)
* 4 - arguments passed to running code as _this select 1
*
* Example
* ["seppuku", {player setDamage 1}, "Kills player <#fp.seppuku>", false] call fpa_common_fnc_registerChatCommand;
*
* Public: Yes
*/
#include "script_component.hpp"

params [
    ["_cmd", "", [""]],
    ["_code", {}, [{}]],
    ["_description", "", [""]],
    ["_adminOnly", true],
    "_argsForCode"
];

if (_cmd isEqualTo "" || _code isEqualTo {}) exitWith {false};

if (isNil QGVAR(chatCommands)) then {
    GVAR(chatCommands) = [] call CBA_fnc_createNamespace;

    ["fp.help", {
        [{
            systemChat "=== Available Commands ===";
            {
                (GVAR(chatCommands) getVariable [_x, []]) params ["_description", "", "_adminOnly"];
                if (count _description > 0 && (!_adminOnly || {call FUNC(isAdmin)})) then {
                    systemChat format ["%1 - %2", _x, _description];
                };
            } forEach (allVariables GVAR(chatCommands));
            systemChat "=== End ===";
        }] call CBA_fnc_execNextFrame;
    }, "all"] call CBA_fnc_registerChatCommand;
};

private _fpCmd = _cmd;
if (_fpCmd find "." isEqualTo -1) then {
    _fpCmd = format ["fp.%1", _fpCmd];
};

GVAR(chatCommands) setVariable [_fpCmd, [_description, _code, _adminOnly, _argsForCode]];

[_fpCmd, {
    [param [0, ""], _thisArgs] call FUNC(runChatCommand);
}, "all", _fpCmd] call CBA_fnc_registerChatCommand;

if !(_fpCmd isEqualTo _cmd) then {
    systemChat format ["registering %1", _cmd];
    [_cmd, {
        [param [0, ""], _thisArgs] call FUNC(runChatCommand);
    }, "all", _fpCmd] call CBA_fnc_registerChatCommand;
};
