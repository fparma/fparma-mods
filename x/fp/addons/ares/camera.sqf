/*
    Description:
        Creates a splendid camera at selected position
        and entersr ACRE spectator to hear players nearby

*/

params ["_pos", "_obj"];
if (!isNull _obj) then {_pos = _obj call CBA_fnc_getPos};
if ((_pos select 2) < 1) then {
  _pos set [2, 3];
};

if (!(isNull (missionNamespace getVariable ["BIS_fnc_camera_cam", objNull]))) exitWith {
    ["ERROR: BIS Camera exists"] call ares_fnc_ShowZeusMessage;
};

BIS_fnc_camera_cam = "camera" camCreate _pos;
["Init"] spawn BIS_fnc_camera;
[true] call acre_api_fnc_setSpectator;

[{isNull (missionNamespace getVariable ["BIS_fnc_camera_cam", objNull])}, {
    if (alive player) then {
        [false] call acre_api_fnc_setSpectator;
    };
}, []] call ACE_common_fnc_waitUntilAndExecute;
