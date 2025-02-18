/*
* Author: Cuel
*
* Description:
* Sends a custom chat command
*
* Arguments:
*
* Public: No
*/

#include "script_component.hpp"
params ["_msg", "_type", "_receiver"];

private _callsign = switch (toLower _type) do {
  case "admin": {"to Admins:"};
  case "zeus": {"to Zeus:"};
  case "whisper": {format ["Whisper to %1:", _receiver]};
  default {"Chat:"}
};

GVAR(chatChannel) radioChannelAdd [ACE_player];
GVAR(chatChannel) radioChannelSetCallSign _callsign;
player customChat [GVAR(chatChannel), _msg];
GVAR(chatChannel) radioChannelRemove [ACE_player];

[QGVAR(chatMessage), [profileName, _msg, _type, _receiver]] call CBA_fnc_globalEvent;
if (GVAR(customChatPingSound)) then {
    playSound "3DEN_notificationDefault";
};
