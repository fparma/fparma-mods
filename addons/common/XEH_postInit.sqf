#include "script_component.hpp"

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
                    {
                        private _side = _x param [2, sideUnknown];
                        if (side group player == _side) then {
                            _ending = _x param [0, "End1"];
                            _won = _x param [1, true];
                        };
                    } forEach _x;
                };
            };
        } forEach _args;
    };

    [true] call FUNC(disablePlayerWeapons);
    [_ending, _won] call BIS_fnc_endMission;
}] call CBA_fnc_addEventHandler;

private _admins =  [
    "76561197970604257", // cuel
    "76561198026206488", // mallow
    "76561197987062676", // tinter
    "76561198009543420", // croguy
    "76561197990522336" // comfy
];

if (!hasInterface || {!((getPlayerUID player) in _admins)}) exitWith {};

GVAR(adminCommands) = [];

private _add = {
    params ["_cmd", "_desc", "_code"];
    private _str = format ["fp.%1", _cmd];
    if (count _desc > 0) then {GVAR(adminCommands) pushBack [_str, _desc]};
    [_str, _code, "all"] call CBA_fnc_registerChatCommand;
};

["help", "", {
    [{
        {
            systemChat format ["%1 - %2", _x select 0, _x select 1];
        } forEach GVAR(adminCommands);
    }] call CBA_fnc_execNextFrame;
}] call _add;

["tpto", "Teleports you to other player. <#fp.tpto Cuel>", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {[{systemChat "Could not find unit"}] call CBA_fnc_execNextFrame};
    [{systemChat format ["Teleported you to %1", _this]}, name _unit] call CBA_fnc_execNextFrame;
    ACE_player setPos (_unit modelToWorld [0, -2, 0]);
}] call _add;

["tpme", "Teleports other player to you. <#fp.tpme Cuel>", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {[{systemChat "Could not find unit"}] call CBA_fnc_execNextFrame};
    moveOut _unit;
    _unit setVelocity [0,0,0];
    _unit setPos (ACE_player modelToWorld [0, 1, 0]);
    [{systemChat format ["Teleported %1 to you", _this]}, name _unit] call CBA_fnc_execNextFrame;
}] call _add;

["kill", "Kills player. <#fp.kill Cuel>", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {[{systemChat "Could not find unit"}] call CBA_fnc_execNextFrame};
    [{systemChat format ["Killed %1", _this]}, name _unit] call CBA_fnc_execNextFrame;
    _unit setDamage 1;
}] call _add;

["kick", "Kicks player <#fp.kick Cuel>", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {[{systemChat "Could not find unit"}] call CBA_fnc_execNextFrame};
    [{systemChat format ["Kicked %1", _this]}, name _unit] call CBA_fnc_execNextFrame;
    [_unit] remoteExecCall ["fpa_serverCommandKick", 2];
}] call _add;

["weaponlock", "Disable/enable all player weapons. 0 enable weapons, 1 disable weapons. <#fp.weaponlock 0/1>", {
    params [["_str", ""]];
    private _disableWeapons = [false, true] select (_str isEqualTo "1");
    [_disableWeapons] remoteExecCall [QFUNC(disableWeapons)];
    [{systemChat format ["All player weapons %1", ["enabled", "disabled"] select _this]}, _disableWeapons] call CBA_fnc_execNextFrame;
}] call _add;
