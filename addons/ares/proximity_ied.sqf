/*
    Description:
        Spawns a custom IED with settings
*/

#include "script_component.hpp"
params ["_pos"];
private _ied = createVehicle [selectRandom ["ACE_ModuleExplosive_IEDUrbanBig_Range", "ACE_ModuleExplosive_IEDUrbanSmall_Range"], _pos, [], 0, "NONE"];

private _condition = {
  {isPlayer _x &&
    {(vehicle _x) == _x} &&
    {(stance _x) in ([['CROUCH', 'STAND'], ['STAND']] select ('MineDetector' in items _x))}
  } count thisList > 0
} call ace_common_fnc_codeToString;

private _onAct = {
    private _ied = thisTrigger getVariable ["fp_ied", objNull];
    if (!alive _ied || {(_ied distance thisTrigger) > 2}) exitWith {deleteVehicle thisTrigger};
    deleteVehicle thisTrigger;

    private _snd = selectRandom ["fp_iedbuzz", "fp_iedbuzz2", "fp_iedbuzz3", "fp_iedbuzz4", "fp_iedbuzz5"];
    [_ied, _snd, 100] call CBA_fnc_globalSay3d;

    [{
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
        }, _crater, 300] call ACE_common_fnc_waitAndExecute;
      }, [_pos]] call ace_common_fnc_execNextFrame;
    }, _ied, 3.5] call ace_common_fnc_waitAndExecute;
} call ACE_common_fnc_codeToString;

private _trigger = ([_pos,
  "AREA:", [6, 6, 0, false],
  "ACT:", ["ANY", "PRESENT", false],
  "STATE:", [_condition, _onAct, ""]
] call CBA_fnc_createTrigger) select 0;

_trigger setVariable ["fp_ied", _ied];
_trigger attachTo [_ied, [0,0,0]];

_ied call GVAR(addToCurators);
