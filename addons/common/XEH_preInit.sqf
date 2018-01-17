
#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(vehicleNames) = [];
GVAR(preloadFinished) = false;
GVAR(isWeaponsDisabled) = false;

[
    QGVAR(displayVehicleNamesSetting), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Display vehicle names", "Mission makers may enable 3d vehicle names for easier identification"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    FP_SETTINGS, // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    true, // data for this setting
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {
        params ["_value"];
        if (_value isEqualTo false) then {
            removeMissionEventHandler ["Draw3D", RETDEF(GVAR(drawNamesId),-1)];
            GVAR(drawNamesId) = nil;
        } else {
            [] call FUNC(runVehicleDrawEH);
        };
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    QGVAR(customChatPingSound), // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Custom chat ping", "Play a notification sound when sending whispers or receiving custom chat"], // Pretty name of the category where the setting can be found. Can be stringtable entry.
    FP_SETTINGS, // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    true, // data for this setting
    nil // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_Settings_fnc_init;

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

if (hasInterface) then {
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
        };
    }] call CBA_fnc_addEventHandler;
};

[QGVAR(endMission), {
    if (!isNil QGVAR(ending)) exitWith {};
    GVAR(ending) = true;

    params [["_args", []]];
    private _ending = "End1";
    private _won = true;

    if (_args isEqualType "") then {
        _ending = _args;
    } else {
        {
            if (_x isEqualType "") then {
                _ending = _x param [0, "End1"];
                _won = _x param [1, true];
            } else {
                if (_x isEqualType []) then {
                    private _side = _x param [2, sideUnknown];
                    if (side group player == _side) then {
                        _ending = _x param [0, "End1"];
                        _won = _x param [1, true];
                    };
                };
            };
        } forEach _args;
    };

    [true] call FUNC(disableWeapons);
    [_ending, _won] call BIS_fnc_endMission;
}] call CBA_fnc_addEventHandler;

ADDON = true;
