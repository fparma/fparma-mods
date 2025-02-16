/*
 * Author: Cuel
 * Spawns and IED at position with a 6x6 trigger and cellphone sound
 * when players close
 *
 * Arguments:
 * 1- Position
 *
 * Public: Yes
 */
#include "script_component.hpp"

params ["_pos"];
private _type = selectRandom ["ACE_ModuleExplosive_IEDUrbanBig_Range", "ACE_ModuleExplosive_IEDUrbanSmall_Range"];
private _ied = createVehicle [_type, _pos, [], 0, "NONE"];

private _condition = {
  {isPlayer _x &&
    {isNull objectParent _x} &&
    {toUpper (stance _x) in ['CROUCH', 'STAND']}
  } count thisList > 0
};

private _onAct = {
    private _ied = thisTrigger getVariable [QGVAR(ied), objNull];
    if (!alive _ied || {(_ied distance thisTrigger) > 2}) exitWith {
        deleteVehicle thisTrigger
    };
    deleteVehicle thisTrigger;

    private _snd = format ["fp_iedbuzz%1", ceil random 6];
    [_ied, _snd, 100] call CBA_fnc_globalSay3d;

    private _afterSoundPlayed = {
        params ["_ied"];
        private _pos = getPosATL _ied;
        deleteVehicle _ied;

        [{
            params ["_pos"];
            ("M_Titan_AT" createVehicle [_pos select 0, _pos select 1, (_pos select 2) + 0.1]) setVelocity [0, 0, -50];
            [2.5, 2, 25] remoteExecCall ["addCamShake", allPlayers select {alive _x && (_x distance _pos) < 50}];

            _crater = createVehicle ["CraterLong_small", _pos, [], 0, "NONE"];
            [{
                deleteVehicle _this;
            }, _crater, 300] call CBA_fnc_waitAndExecute;
        }, [_pos]] call CBA_fnc_execNextFrame;
    };
    [_afterSoundPlayed, _ied, 3.5] call CBA_fnc_waitAndExecute;
};

private _trigger = ([
    _pos,
    "AREA:", [6, 6, 0, false],
    "ACT:", ["ANY", "PRESENT", false],
    "STATE:", [
        _condition call ace_common_fnc_codeToString,
        _onAct call ace_common_fnc_codeToString,
        ""
    ]
] call CBA_fnc_createTrigger) select 0;

_trigger setVariable [QGVAR(ied), _ied];
_trigger attachTo [_ied, [0,0,0]];

_ied call EFUNC(common,addToCurators);
