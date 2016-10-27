#include "script_component.hpp"
if (GVAR(disabled)) exitWith {};

params ["_unit", "_dmgedPart", "", ["_shooter", objNull], "_proj"];
private _shooterIsPlayer = (_shooter call EFUNC(common,isPlayer));
private _sameSide = side group _unit == side group _shooter;
private _level = [0, 1] select _sameSide;

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
if !(vehicle _shooter isKindOf "CAManBase") then {
    _text pushBack (format ["Was in vehicle: %1", getText (configfile >> "CfgVehicles" >> (typeOf (vehicle _shooter)) >> "displayName")]);
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
