#include "script_component.hpp"
params [["_channel", -1], "", "", "", ["_person", objNull]];

if (GVAR(allowChatMessages) || {!(_channel in [0,1])}) exitWith {false};

if (_person isEqualTo ace_player) then {
    systemChat "Messages into global and side chat have been locked! Use whispers if you need to contact zeus or an admin!";
    playSound "3DEN_notificationWarning";
};

true
