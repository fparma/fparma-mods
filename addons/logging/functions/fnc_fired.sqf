params ["_unit", "", "_muzzle", "", "", "", ["_proj", objNull]];
if (GVAR(disabled) ||
    {isNull  _proj} ||
    {!(_unit call EFUNC(common,isPlayer))} ||
    {_muzzle != "HandGrenadeMuzzle"}
) exitWith {};

// Clean up previous tracked nades
if (count (GVAR(grenades) select {!(isNull (_x select 0))}) == 0) then {
    GVAR(grenades) = [];
};

// let any other EHs delete the nade first
[{
    params ["_proj"];
    if (isNull _proj) exitWith {};
    private _id = GVAR(grenades) pushBack [_proj, getPosATL _proj];

    [{
        params ["_id", "_pfhId"];
        private _ele = GVAR(grenades) select _id;
        _ele params ["_proj", ["_pos", [0, 0]], "_type"];

        if (alive _proj) exitWith {
            GVAR(grenades) set [_id, [_proj, getPosATL _proj, typeOf _proj]];
        };

        [_pfhId] call CBA_fnc_removePerFrameHandler;
        private _near = (call CBA_fnc_players) select {
            _x call EFUNC(common,isPlayer) && {_x distance _pos < 30}
        };
        if (count _near == 0) exitWith {};

        private _names = _near apply {
            format ["%1 (%2m), ",
            name _x,
            round (_x distance _pos)];
        };

        private _str = format ["%1 threw a (%2), exploded at %3. %4 player(s) were within 30m. (%5)",
            name player,
            _type,
            _pos call FUNC(posFormat),
            count _near,
            _names
        ];

        private _lvl = [1, 2] select (count (_near select {_x distance _pos < 8}) > 0);
        [_str, _lvl, CBA_missionTime] remoteExecCall [QFUNC(serverLog), 2];

    }, 0.1, _id] call CBA_fnc_addPerFrameHandler;
}, _proj] call CBA_fnc_execNextFrame;
