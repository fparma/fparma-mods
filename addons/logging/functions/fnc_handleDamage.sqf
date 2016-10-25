#include "script_component.hpp"

if (GVAR(disabled)) exitWith {};
params ["_unit", "_dmgedPart", "", ["_shooter", objNull], "_proj"];
private _shooterAPlaya = (_shooter call EFUNC(common,isPlayer));
private _sameSide = side group _unit == side group _shooter;

if (!_shooterAPlaya || {!_sameSide} || {player != _unit} || {player == _shooter}) exitWith {
    nil
};

private _text = [];
if (count _dmgedPart > 0) then {
    _text pushBack format ["part: %1", _dmgedPart];
};
if (count _proj > 0) then {
    _text pushBack format ["proj: %1", _proj];
};

private _msg = format ["%1 was hit by %2.%3",
  name _unit,
  name _shooter,
  _text joinString (', ');
];

[_msg, 1, CBA_missionTime] remoteExecCall [QFUNC(serverLog), 2];

nil
