#include "script_component.hpp"
params ["_unit", ["_killer", objNull, [objNull]]];
private _isRc = !isNull (_unit getVariable ["bis_fnc_moduleRemoteControl_owner", objNull]);
private _unitIsPlayer = !_isRc && {hasInterface} && {_unit == ace_player};

// exit if not player or odd position
if (!_unitIsPlayer || {(getPosATL _unit) distance2D [0,0] < 400}) exitWith {};

private _msg = [format ["%1 died at %2", profileName, _unit call FUNC(posFormat)]];
private _killerPlayer = _killer call EFUNC(common,isPlayer);
private _sideGrp = side group _unit;
private _keepChecking = true;
private _lvl = 0;

// died directly by player gunfire
if (_unit != _killer && {_killerPlayer} && {(vehicle _killer) isKindOf "CAManBase"}) then {
    private _wep = currentWeapon _killer;
    private _text = format ["Killed by %1, MAYBE using: %2, pos: %3 dist: %4, killer dir: %5",
        name _killer,
        format ["%1 (%2)", getText (configFile >> "CfgWeapons" >> currentWeapon _killer >> "displayName"), _wep],
        _killer call FUNC(posFormat),
        round (_killer distance _unit),
        round (getDir _killer)
    ];

    _msg pushBack _text;
    _lvl = [0, 2] select (_sideGrp == side group _killer);
    _keepChecking = false;
};

// died while unconscious or AI or suicide
if (_keepChecking && (_unit == _killer || {!_killerPlayer}))  then {
    // check last damage source
    private _aceSource = _unit getVariable ["ace_medical_lastDamageSource", objNull];
    if ((!isNull _aceSource) && {_aceSource != _unit}) then {
        _killer = _aceSource;
        if (_killer isKindOf "CAManBase" && {_killer call EFUNC(common,isPlayer)}) then {
            _lvl = [0, 2] select (side group _unit == side group _killer);
            _msg pushBack format ["Last damage by %1", name _killer];
        };
    };

    // killed by vehicle, use effectiveCommander like vanilla does
    if ((!isNull _killer) && {!((vehicle _killer) isKindOf "CAManBase")}) then {
        private _text = format ["Killed by vehicle: %1", getText (configFile >> "CfgVehicles" >> (typeOf _killer) >> "displayName")];
        private _plrCrew = (fullCrew _killer) select {
                _x params ["_obj", "_role"];
                (_role != "cargo" && {_obj call EFUNC(common,isPlayer)})
            } apply {
                _x params ["_unit", "_role", "", "_turretPath"];
                (format ["%1 (role: %2, tpath: %3)", name _unit, _role, _turretPath])
            };

        _killer = effectiveCommander _killer;
        if (count _plrCrew > 0) then {
            _lvl = [0, 2] select (_sideGrp == side group _killer);
            _text = _text + format [", crew: (%1)", _plrCrew joinString (', ')];
        };
        _msg pushBack _text;
    };

    // killed by AI
    if (_unit != _killer && {!(_killer call EFUNC(common,isPlayer))}) then {
        _lvl = 0;
        _msg pushBack format ["Killed by AI(%1)", getText (configFile >> "CfgVehicles" >> (typeOf _killer) >> "displayName")];
    };

    // still "suicide". get nearby player drivers
    if (_unit == _killer) then {
        private _nearbyDrivers = (nearestObjects [getPosATL _unit, ["LandVehicle", "Air"], 20])
            select {(driver _x) call EFUNC(common,isPlayer)};

        if (count _nearbyDrivers > 0) then {
            private _withDist = _nearbyDrivers apply {[_x, _x distance _unit]};
            private _sorted = [_withDist, 1] call CBA_fnc_sortNestedArray;

            private _texts = _sorted apply {
                _x params ["_driver", "_dist"];
                private _veh = vehicle _driver;
                private _type = typeOf _veh;
                private _dispName =  getText (configFile >> "CfgVehicles" >> _type >> "displayName");
                format ["%1 in %2(%3). pos: %4, speed: %5, dir: %6, dist: %7m",
                    name _driver,
                    _dispName,
                    _type,
                    _veh call FUNC(posFormat),
                    round speed _veh,
                    round getDir _veh,
                    round _dist
                ];
            };

            _msg pushBack format ["Nearby drivers: %1", _texts joinString ('. ')];
            _lvl = parseNumber (({_sideGrp == side group _x} count _nearbyDrivers) > 0);
        };
    };
};

[_msg joinString ('. '), _lvl, CBA_missionTime] remoteExecCall [QFUNC(serverLog), 2];
