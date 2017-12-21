#include "script_component.hpp"
#define EADDON(var1) QUOTE(DOUBLES(PREFIX,var1))

FUNC(checkMods) = compileFinal ({
    private _str = '';
    private _v = getText (configFile >> "CfgPatches" >> QUOTE(ADDON) >> "version");
    if !(_v isEqualTo QUOTE(VERSION)) then {_str = format ["version mismatch %1 (%2 vs %3). ", QUOTE(ADDON), _v, QUOTE(VERSION)]};
    private _m = [];
    {
        if !([_x] call ace_common_fnc_isModLoaded) then {_m pushBack _x};
    } forEach [EADDON(assets),EADDON(common),EADDON(jrm),EADDON(logging)];
    if !(_m isEqualTo []) then {_str = _str + format ["missing addons: %1", _m joinString ", "]};
    if (count _m > 0) then {format ["SERVER: player %1 %2", profileName, _str] remoteExecCall ["systemChat"]; hintSilent _str};
} call ace_common_fnc_codeToString);

publicVariable QFUNC(checkMods);
