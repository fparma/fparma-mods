#include "script_component.hpp"
params ["_unit", "_killer"];

private _rc = isNull (_unit getVariable ["bis_fnc_moduleRemoteControl_owner", objNull]);
private _unitPlaya = !_rc && {hasInterface} && {_unit == ace_player};

// exit if not player or odd position
if (!_unitPlaya || {(getPosATL _unit) distance2D [0,0] < 400}) exitWith {};

private _keepChecking = true;
private _killerPlayer = _unit call FUNC(common,isPlayer);
private _msg = [format ["%1 died at %2", profileName, _unit call FUNC(posFormat)]];
private _lvl = 1;

// died directly by gunfire
if (_unit != _killer && {_killerPlayer} && {_killer isKindOf "CAManBase"}) then {
    private _text = format ["Killed by %1, (MAYBE using: %2), dist: %3, killer dir: %4",
        name _killer,
        currentWeapon _killer,
        round (_killer distance _unit),
        round (getDir _killer)
    ];

    _msg pushBack [_text];
    _lvl = 2;
    _keepChecking = false;
};

// died while unconscious or AI or suicide
if (_keepChecking && ({_unit == _killer} || {!_killerPlayer})) then {

    // check last damage source
    private _aceSource = _unit getVariable ["ace_medical_lastDamageSource", objNull];
    if ((!isNull _aceSource) && {_aceSource != _unit}) then {
        _killer = _aceSource;
        if (_killer isKindOf "CAManBase" && {_killer call EFUNC(common,isPlayer)}) then {
            _lvl = 2;
            _msg pushBack [format ["Last damage by %1", name _killer]];
        };
    };

    // killed by vehicle
    if ((!isNull _killer) && {!(_killer isKindof "CAManBase")}) then {
        private _text = format ["Killed by vehicle: %1", getText (configfile >> "CfgVehicles" >> (typeOf _killer) >> "displayName")];
        private _plrCrew = (fullCrew _killer)
            select {
                params ["_obj", "_role"];
                _role != "crew" && {_obj call EFUNC(common,isPlayer)};
            }
            apply {
                _x params ["_unit", "_role", "", "_turretPath"];
                (format ["%1(role: %2, tpath: %3)", name _unit, _role, _turretPath])
            };

        if (count _plrCrew > 0) then {
            _lvl = 2;
            _text = _text + format [", crew: (%1)", _plrCrew joinString (', ')];
        };

        _msg pushBack _text;
        _killer = effectiveCommander _killer;
    };

    // killed by AI
    if (_unit != _killer && {!(_killer call EFUNC(common,isPlayer))}) then {
        _lvl = 0;
        _msg pushBack [format ["Killed by AI(%1)", getText (configfile >> "CfgVehicles" >> (typeOf _killer) >> "displayName")]];
    };

    // still "suicide". get nearby player drivers
    if (_unit == _killer) then {
        private _nearbyDrivers = (nearestObjects [_posUnit, ["LandVehicle"], 16])
            apply {driver _x}
            select {_x call EFUNC(common,isPlayer)};

        if (count _nearbyDrivers > 0) then {
            private _texts = _nearbyDrivers apply {
                format ["%1 (%2, pos: %3, speed: %4, dir: %5, dist: %6m)",
                    name _x,
                    getText (configfile >> "CfgVehicles" >> (typeOf (vehicle _x)) >> "displayName"),
                    _x call FUNC(posFormat),
                    round speed _x,
                    round getDir _x,
                    round (_x distance _unit)
                ];
            };
            _msg pushBack [format ["Nearby player drivers: %1", _texts joinString (', ')]];
        };
    };
};

[_msg joinString ('. '), _lvl, CBA_missionTime] remoteExecCall [QFUNC(serverLog), 2];
