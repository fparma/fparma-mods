// ZEN modules

[UTIL, "Camera at position", {
    params ["_pos", "_obj"];
    if (!isNull _obj) then {
        _pos = _obj call CBA_fnc_getPos;
    } else {
        _pos = ASLToATL _pos;
    };

    [_pos, false] call EFUNC(common,cameraAtPosition);
}] call zen_custom_modules_fnc_register;

[UTIL, "Eject cargo", {
    params ["", "_veh"];
    if (isNull _veh) exitWith {};
    _veh call FUNC(ejectCargo);
}] call zen_custom_modules_fnc_register;

[UTIL, "Phone buzz IED", {
    params ["_pos"];
    [ASLToATL _pos] call FUNC(proximityIed);
}] call zen_custom_modules_fnc_register;

[UTIL, "Road IED", {
  params ["_pos"];
  private _type = selectRandom ["ACE_ModuleExplosive_IEDLandBig_Range", "ACE_ModuleExplosive_IEDLandBig_Range"];
  private _bomb = createVehicle [_type, ASLToATL _pos, [], 0, "NONE"];
  _bomb call EFUNC(common,addToCurators);
}] call zen_custom_modules_fnc_register;

[UTIL, "Delete IED", {
    params ["", "_obj"];
    if (isNull _obj) exitWith {};
    deleteVehicle _obj;
}] call zen_custom_modules_fnc_register;

[UTIL, "End Mission (COOP)", {
    private _endings = [] call FUNC(getEndings);

    ["End Mission", [
            ["COMBO", "Ending", [_endings apply {_x select 0}, _endings apply {[_x select 1, "", "", [1,1,1,1]]}, 0]],
            ["CHECKBOX", "Victory", true]
        ],
        {
            params ["_dialog"];
            _dialog params ["_end", "_victory"];
            [_end, _victory] remoteExecCall [QEFUNC(common,endMissionServer),2];
        }
    ] call zen_dialog_fnc_create;
}] call zen_custom_modules_fnc_register;

[UTIL, "End Mission (TVT)", {
    private _endings = [] call FUNC(getEndings);
    private _sides = [blufor, opfor, independent, civilian];
    private _dialogArgs = [];
    {
        private _sideName = [[_x] call EFUNC(common,translateSide)] call CBA_fnc_capitalize;
        _dialogArgs pushBack ["COMBO", _sideName + " ending", [_endings apply {_x select 0}, _endings apply {[_x select 1, "", "", [1,1,1,1]]}, 0]];
        _dialogArgs pushBack ["CHECKBOX", _sideName + " victory", false];
    } forEach _sides;

    ["End Mission", _dialogArgs, {
        params ["_dialog", "_args"];
        _args params ["_sides"];
        private _endMissionArgs = [];
        {
            private _ending = _dialog deleteAt 0;
            private _won = _dialog deleteAt 0;
            _endMissionArgs pushBack [_ending, _won, _x];
        } forEach _sides;

        [_endMissionArgs] remoteExecCall [QEFUNC(common,endMissionServer),2];
    },{},[_sides]] call zen_dialog_fnc_create;
}] call zen_custom_modules_fnc_register;

[AI, "Patrol area", {["PATROL", _this select 1] call FUNC(ai)}] call zen_custom_modules_fnc_register;
[AI, "Defend area", {["DEFEND", _this select 1] call FUNC(ai)}] call zen_custom_modules_fnc_register;
[AI, "Force move WP", {["FORCE_WP", _this select 1] call FUNC(ai)}] call zen_custom_modules_fnc_register;

[AI, "Drive in straight line", {
    params ["", "_obj"];
    if (!(_obj isKindOf "LandVehicle") || !alive _obj) exitWith {["ERROR: Select vehicle"] call zen_common_fnc_showMessage};

    [_obj, FUNC(setDrivePath), "Select path (hold ctrl for more)"] call ace_zeus_fnc_getModuleDestination;
}] call zen_custom_modules_fnc_register;
