#include "script_component.hpp"
if (GVAR(disabled)) exitWith {};

params ["_unit", "_dmgedPart", "", ["_shooter", objNull], "_proj"];
private _shooterIsPlayer = (_shooter call EFUNC(common,isPlayer));
private _sameSide = side group _unit == side group _shooter;
private _level = [0, 2] select _sameSide;

if (!_shooterIsPlayer ||
    {!alive _unit} ||
    {player != _unit} ||
    {player == _shooter} ||
    {name _shooter == "Error: No unit"}) exitWith {
    nil
};

GVAR(playerDamageTimeout) params ["_lastShooter", "_t"];
if (_lastShooter == _shooter && {time < _t}) exitWith {};
GVAR(playerDamageTimeout) = [_shooter, time + 1];

private _text = [];
_veh = vehicle _shooter;
if !(_veh isKindOf "CAManBase") then {
    private _info = fullCrew _veh select {(_x select 0) == _shooter};
    (_info select 0) params ["", ["_role", "unknown"], "", ["_tpath", "unknown"]];
    private _vehtype = typeOf _veh;

    _text pushBack (format ["Was in vehicle: %1(%2), role: %3, tpath: %4",
        getText (configFile >> "CfgVehicles" >> _vehtype >> "displayName"),
        _vehtype,
        _role,
        _tpath
    ]);
};

if (count _proj > 0) then {_text pushBack format ["Projectile: %1", _proj]};
if (count _dmgedPart > 0) then {_text pushBack format ["Part: %1", _dmgedPart]};

private _msg = format ["%1%2 was hit by %3. %4",
    ["", "FRIENDLY FIRE: "] select _sameSide,
    name _unit,
    name _shooter,
    (_text joinString (', '))
];

[_msg, _level, CBA_missionTime] remoteExecCall [QFUNC(serverLog), 2];

nil
