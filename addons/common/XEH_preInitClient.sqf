#include "script_component.hpp"

if (!hasInterface) exitWith {};

[
    FP_SETTINGS,
    QGVAR(toggleScreenshot),
    ['Toggle Screenshot Mode', 'Hides UI elements for taking screenshots'],
    {
        [] call FUNC(toggleScreenshotMode);
        false
    },
    ''
] call CBA_fnc_addKeybind;

GVAR(lastMessageFrom) = "";
[QGVAR(chatMessage), {
    params ["_sender", "_msg", "_type", "_receiver", ["_ping", true]];

    private _args = switch (toLower _type) do {
        case "admin": {
            [{call FUNC(isAdmin)}, format ["(Admins) %1:", _sender]];
        };
        case "zeus": {
            [{!(profileName isEqualTo _sender) && !isNull (getAssignedCuratorLogic player)}, format ["(Zeus) %1:", _sender]];
        };
        case "whisper": {
            [{profileName isEqualTo _receiver}, format ["Whisper from %1:", _sender]];
        };
        case "server": {
            [{call FUNC(isAdmin) || !isNull (getAssignedCuratorLogic player)}, format ["Notice (%1):", _sender]];
        };
        default {
            [{true}, format ["Notice (%1):", _sender]];
        };
    };
    _args params ["_condition", "_text"];

    if ([] call _condition) then {
        GVAR(chatChannel) radioChannelAdd [ACE_player];
        GVAR(chatChannel) radioChannelSetCallsign _text;
        ACE_player customChat [GVAR(chatChannel), _msg];
        GVAR(chatChannel) radioChannelRemove [ACE_player];
        if (GVAR(customChatPingSound) && _ping) then {
            playSound "3DEN_notificationWarning";
        };

        if !((toLower _type) isEqualTo "server") then {
            GVAR(lastMessageFrom) = _sender;
        }
    };
}] call CBA_fnc_addEventHandler;
