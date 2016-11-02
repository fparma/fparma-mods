/*
* Suggested by snippers in acre chat
* "should" fix players not able to hear anyone else
* only call locally for the person having the issue
*/

diag_log format ["=== ACRE DEBUG START === CBA_missionTime: %1", CBA_missionTime];
diag_log str acre_sys_core_threadedExtCalls;
diag_log "==== ACRE DEBUG END ===";

ACRE_MAP_LOADED = false;
[
    "init",
    []
] call acre_sys_core_fnc_callExt;

private _wrpLocation = getText(configFile >> "CfgAcreWorlds" >> worldName >> "wrp");
if (_wrpLocation == "") then {
    _wrpLocation = getText(configFile >> "CfgWorlds" >> worldName >> "worldName");
};

[
    "load_map",
    [_wrpLocation],
    true,
    {
        ACRE_MAP_LOADED = true;
    },
    []
] call acre_sys_core_fnc_callExt;
