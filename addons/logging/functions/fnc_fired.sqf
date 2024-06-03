#include "script_component.hpp"

params ["_unit", "", "_muzzle", "", "", "", ["_proj", objNull]];
if (_muzzle != "HandGrenadeMuzzle" ||
    {GVAR(disabled)} ||
    {isNull _proj} ||
    {!(_unit call EFUNC(common,isPlayer))}
) exitWith {};

// Clean up previous tracked nades
if (count (GVAR(grenades) select {!(isNull (_x select 0))}) == 0) then {
    GVAR(grenades) = [];
};

// let any other EHs delete the nade first
[{
    params ["_proj"];
    private _gPos = getPosATL _proj;
    if (isNull _proj || {_gPos distance2D [0,0] < 400}) exitWith {};
    private _id = GVAR(grenades) pushBack [_proj, _gPos];

    [{
        params ["_id", "_pfhId"];
        private _ele = GVAR(grenades) select _id;
        _ele params ["_proj", ["_pos", [0, 0]], "_type", ["_lastNear", []]];

        if (alive _proj) exitWith {
            private _near = (call CBA_fnc_players)
                select {_x call EFUNC(common,isPlayer) && {_x distance _pos < 30}};

            GVAR(grenades) set [_id, [_proj, getPosATL _proj, typeOf _proj, _near]];
        };

        [_pfhId] call CBA_fnc_removePerFrameHandler;
        if (count _lastNear == 0) exitWith {};

        private _withDist = _lastNear apply {[name _x, _x distance _pos]};
        private _sortedNear = [_withDist, 1] call CBA_fnc_sortNestedArray;
        private _names = _sortedNear apply {
            _x params ["_name", "_dist"];
            format ["%1 (%2m)", _name, round _dist];
        };

        private _str = format ["%1 threw a '%2', exploded at %3. %4 player(s) were within 30m: %5",
            profileName,
            _type,
            [_pos] call FUNC(posFormat),
            count _lastNear,
            _names joinString (', ')
        ];

        private _sideGrp = side group player;
        private _lvl = parseNumber (({_x distance _pos < 10 && side group _x == _sideGrp} count _lastNear) > 0);
        [_str, _lvl, CBA_missionTime] remoteExecCall [QFUNC(serverLog), 2];
    }, 0.1, _id] call CBA_fnc_addPerFrameHandler;
}, _proj] call CBA_fnc_execNextFrame;
