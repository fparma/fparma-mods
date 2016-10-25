/*
 * Author: Cuel
 * Spawns a splendid camera at position
 *
 * Arguments:
 * 1 - Position
 *
 * Public: Yes
 */
params ["_pos", ["_forceAcreSpectator", false]];

private _cam = missionNamespace getVariable ["BIS_fnc_camera_cam", objNull];
if (!isNull _cam) exitWith {};

if ((_pos select 2) < 1) then {
  _pos set [2, 3];
};

BIS_fnc_camera_cam = "camera" camCreate _pos;
["Init"] spawn BIS_fnc_camera;

if (_forceAcreSpectator && !isNil "acre_api_fnc_setSpectator") then {
    [true] call acre_api_fnc_setSpectator;

    [{isNull (missionNamespace getVariable ["BIS_fnc_camera_cam", objNull])}, {
        if (alive player) then {
            [false] call acre_api_fnc_setSpectator;
        };
    }, []] call CBA_fnc_waitUntilAndExecute;
};
