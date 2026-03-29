#include "script_component.hpp"
params [["_channel", -1], "", "", "", ["_person", objNull]];

// Allow admins to always send messages
// Allow sending in vehicle, group, direct, command channels
if (!(_channel in [0, 1]) || isNull _person || {call FUNC(isAdmin)}) exitWith {false};

private _ret = false;

if !(GVAR(allowChatMessages)) then {
    if (_person isEqualTo ace_player) then {
        systemChat "Messages into global and side chat have been locked! Use whispers if you need to contact zeus or an admin!";
        playSound "3DEN_notificationWarning";
        _ret = true;
    };
};

if (!_ret && GVAR(chatSlowMode) > 0) then {
    if (GVAR(allowNextMessageTime) > time) then {
        systemChat format ["Chat is in slow mode! You can send your next message in %1 seconds!", round (GVAR(allowNextMessageTime) - time)];
        playSound "3DEN_notificationWarning";
        _ret = true;
    } else {
        GVAR(allowNextMessageTime) = time + GVAR(chatSlowMode);
        // make sure this text appear below your message and not above it
        [{
            systemChat format ["You can send your next message in %1 seconds!", GVAR(chatSlowMode)];
        }] call CBA_fnc_execNextFrame;
    };
};

_ret
