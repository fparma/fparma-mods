#include "script_component.hpp"

/*
*   Original function from ace_logistics_wirecutter by gpgpgpgp, edited by commy2, PabstMirror
*   Adapted for grad_axe by McDiod
*/

params ["_unit", "_treeObject"];

if (_unit != ACE_player) exitWith {};

private _boundingBoxTree = boundingBox _treeObject;
private _treeSize = (_boundingBoxTree select 0) distance (_boundingBoxTree select 1);
private _specialistFactor = [1,0.80] select ([_unit] call ace_common_fnc_isEngineer);
private _timeToCut = (_treeSize * _specialistFactor * ([QGVAR(setting_timeFactor)] call CBA_settings_fnc_get)) min ([QGVAR(setting_maxTime)] call CBA_settings_fnc_get) max 5;

if !(_unit call ace_common_fnc_isSwimming) then {
    [_unit, "Acts_Executioner_Forehand", 0] call ace_common_fnc_doAnimation;
};

private _onCompletion = {
    (_this select 0) params ["_treeObject", "", "_unit"];
    _treeObject setdamage 1;
    [_treeObject] call FUNC(checkCutDown);
    if !(_unit call ace_common_fnc_isSwimming) then {
        [_unit, "AmovPknlMstpSrasWrflDnon", 1] call ace_common_fnc_doAnimation;
    };
    deleteVehicle (_unit getVariable [QGVAR(axeObject), objNull]);

    ["grad_treeChoppingSucceeded", [_unit, _treeObject]] call CBA_fnc_localEvent;
};

private _onFail = {
    (_this select 0) params ["_treeObject", "", "_unit"];
    if !(_unit call ace_common_fnc_isSwimming) then {
        [_unit, "AmovPknlMstpSrasWrflDnon", 1] call ace_common_fnc_doAnimation;
    };
    deleteVehicle (_unit getVariable [QGVAR(axeObject), objNull]);

    ["grad_treeChoppingStopped", [_unit, _treeObject]] call CBA_fnc_localEvent;
};

private _progressCheck = {
    params ["_args", "_passedTime"];
    _args params ["_treeObject", "_lastSoundEffectTime", "_unit", "_pos"];

    if (_passedTime > (_lastSoundEffectTime + SOUND_CLIP_TIME_SPACEING)) then {
        if !((animationState _unit) in ["AwopPercMstpSgthWnonDnon_start", "AwopPercMstpSgthWnonDnon_throw", "AwopPercMstpSgthWnonDnon_end"] || {stance _unit == "PRONE"}) then {
            _unit setPosWorld _pos;
            [_unit, "AwopPercMstpSgthWnonDnon_end", 2] call ace_common_fnc_doAnimation;
            [{
                params ["_unit", "_pos"];
                playSound3D [format [QUOTE(PATHTO_R(sound\chop_%1.ogg)), (round(random 25)) +1], objNull, false, (getPosASL _unit), 3, 1, 80];
            }, [_unit, _pos], 0.1] call CBA_fnc_waitAndExecute;;
        };
        _args set [1, _passedTime];
    };

    !isNull _treeObject && {damage _treeObject < 1} && {[_unit, QGVAR(axe)] call ace_common_fnc_hasItem}
};

private _axe = createSimpleObject ["\A3\Structures_F\Items\Tools\Axe_F.p3d", [0,0,0], false];
_axe attachTo [player, [0,0.15,-0.05], "rightHandMiddle1", true];
[_axe, -90] remoteExec ["setDir", _axe];
[_axe, [-0.4,0,-1]] remoteExec ["setVectorUp", _axe];
_unit setVariable [QGVAR(axeObject), _axe];

// holster any weapon
_unit action ["SwitchWeapon", _unit, _unit, 299];
_unit setdir ([_unit, _treeObject] call BIS_fnc_dirTo);

[_timeToCut, [_treeObject, 0, _unit, getPosWorld _unit], _onCompletion, _onFail, localize "STR_GRAD_AXE_CUTTING_TREE", _progressCheck, ["isNotSwimming"]] call ace_common_fnc_progressBar;

["grad_treeChoppingStarted", [_unit, _treeObject]] call CBA_fnc_localEvent;
