#include "script_component.hpp"
params [
    ["_txt", "", [""]],
    ["_logLevel", 0, [0]],
    ["_t", CBA_missionTime, [0]]
];

if (GVAR(disabled) || {!isServer} || {count (call CBA_fnc_players) < 2}) exitWith {};
["log", [GVAR(id), _logLevel min 2, _t, _txt]] call sock_rpc;
