
#include "script_component.hpp"
params ["_grp", ["_dangerCause", objNull]];

if (CBA_missionTime < _grp getVariable [QGVAR(staticsCheck), 0]) exitWith {};
_grp setVariable [QGVAR(staticsCheck), CBA_missionTime + 15 + random 15];

private _leader = leader _grp;
if (_leader distance _dangerCause < 50) exitWith {};

// don't mount leader or guy with launcher
private _canMount = units _grp select {alive _x && {isNull assignedVehicle _x} && {_x != _leader} && {secondaryWeapon _x isEqualTo ""}};
if (_canMount isEqualTo []) exitWith {};

private _emptyVehicles = [];
private _notEmptyVehicles = [];
private _hasGunnerSeat = {!(allTurrets [_this, false] isEqualTo []) && {!alive (assignedGunner _this)}};

 {
    if (alive _x && {locked _x != 2} && {_x call _hasGunnerSeat}) then {
        if (side _x isEqualTo side _grp) then {
            _notEmptyVehicles pushBack _x;
        } else {
            if (crew _x isEqualTo []) then {_emptyVehicles pushBack _x};
        };
    };
} forEach (getPos _leader nearEntities [["Static", "LandVehicle"], 80]);

if (_emptyVehicles isEqualTo [] && {_notEmptyVehicles isEqualTo []}) exitWith {};
TRACE_3("considering weapons",count _canMount,_emptyVehicles,_notEmptyVehicles);

private _mount = {
    params ["_veh"];
    {
        if (random 1 < 0.8) exitWith {
            TRACE_2("Order mount",typeof _x,typeof _veh);
            _x assignAsGunner _veh;
            [_x] orderGetIn true;
            _x
        };
        objNull
    } forEach _canMount;
};

{
    private _mounted = [_x] call _mount;
    if (!isNull _mounted) exitWith {
        if (_x in _notEmptyVehicles) then {
            TRACE_1("Joining group",typeof _mounted);
            [_mounted] joinSilent ([group effectiveCommander _x] param [0, group _mounted]);
        };
    };
} forEach (_emptyVehicles + _notEmptyVehicles);
