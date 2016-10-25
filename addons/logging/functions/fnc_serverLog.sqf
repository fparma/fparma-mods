#include "script_component.hpp"
private _exit = params [["_args", "", [""]], ["_logLevel", 0, [0]], ["_t", CBA_missionTime]];
if (_exit || {!isServer} || {!isMultiplayer} || {GVAR(disabled)}) exitWith {};

["log", [GVAR(id), _logLevel min 2, _t, _args]] call sock_rpc;
