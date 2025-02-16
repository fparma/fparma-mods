#include "script_component.hpp"

addMissionEventHandler ["PlayerConnected",{
    params ["", "_uid", "_nick", "" ,"_owner"];
    if (_nick == "__SERVER__") exitWith {};
    [{
        if (!(["fpa_logging"] call ACE_common_fnc_isModLoaded)) then {
            (format ["%1: not running FP logs", profileName]) remoteExecCall ["systemChat", 0];
        };
    }] remoteExecCall ["BIS_fnc_call", _owner];
    [format ["%1 (%2) connected", _nick, _uid], 1] call FUNC(serverLog);
}];

addMissionEventHandler ["PlayerDisconnected",{
    params ["", "_uid", "_nick"];
    if (_nick == "__SERVER__") exitWith {};
    [format ["%1 disconnected", _nick], 0] call FUNC(serverLog);
}];

["ace_unconscious", {
    params ["_unit", "_state"];
    if ((getPosATL _unit) distance2D [0,0] < 400) exitWith {};
    if (!(_unit call EFUNC(common,isPlayer))) exitWith {};
    private _msg = format ["%1 %2 at %3",
        name _unit,
        ["woke up", "is unconscious"] select _state,
        _unit call FUNC(posFormat)];
    [_msg, 0] call FUNC(serverLog);
}] call CBA_fnc_addEventHandler;

["ace_explosives_place", {
    params ["_exp", "", "", "_unit"];
    private _msg = format ["%1 placed an explosive (%2) at %3", name _unit, typeOf _exp, getPosATL _exp];
    [_msg, 0] call FUNC(serverLog);
}] call CBA_fnc_addEventHandler;

["ace_explosives_defuse", {
    params ["_exp", "_unit"];
    private _msg = format ["%1 defused an explosive (%2) at %3", name _unit, typeOf _exp, getPosATL _exp];
    [_msg, 0] call FUNC(serverLog);
}] call CBA_fnc_addEventHandler;

["ace_explosives_explodeOnDefuse", {
    params ["_exp", "_unit"];
    private _msg = format ["%1 tried to defuse an explosive (%2) at %3, and failed", name _unit, typeOf _exp, getPosATL _exp];
    [_msg, 0] call FUNC(serverLog);
}] call CBA_fnc_addEventHandler;

(format ["Loaded mission: %1", briefingName]) call FUNC(serverLog);

[{time > 1}, {
  (format ["Mission started. %1 players", count (call CBA_fnc_players)]) call FUNC(serverLog);
}, []] call CBA_fnc_waitUntilAndExecute;

addMissionEventHandler ["Ended", {
  params ["_type"];
  format ["Mission ended. (%1)", _type] call FUNC(serverLog);
}];

if (isDedicated) then {
    [QEGVAR(common,chatMessage), {
        params [["_sender", "NONE"], ["_msg", ""], ["_type", "NONE"], ["_receiver", "NONE"]];
        if (_type == "server") exitWith {};
        switch (toLower _type) do {
            case "admin": {
                private _msg = format ['(admin WHISPER) from %1: "%2"', _sender, _msg];
                INFO(_msg);
            };
            case "zeus": {
                private _msg = format ['(ZEUS WHISPER) from %1: "%2"', _sender, _msg];
                INFO(_msg);
            };
            case "whisper": {
                private _msg = format ['(WHISPER) from %1 to %2: "%3"', _sender, _receiver, _msg];
                INFO(_msg);
            };
            default {
                private _msg = format ['(UNHANDLED WHISPER) type %4 from %1 to %2: "%3"', _sender, _receiver, _msg, _type];
                INFO(_msg);
            };
        };
    }] call CBA_fnc_addEventHandler;
};
