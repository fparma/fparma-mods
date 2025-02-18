#include "script_component.hpp"

{
    ["ace_medical_treatment_" + _x, {
        if (lifeState ace_player == "INCAPACITATED") then {
            titleText ["Someone is helping you", "PLAIN DOWN", 2, true, true];
        };
    }] call CBA_fnc_addEventHandler;
} forEach ["bandageLocal", "checkBloodPressureLocal", "cprLocal", "fullHealLocal", "ivBagLocal", "medicationLocal", "splintLocal", "tourniquetLocal"];


private _effect = ppEffectCreate ["DynamicBlur", 815];
_effect ppEffectForceInNVG true;
_effect ppEffectAdjust [0];
_effect ppEffectCommit 0;
_effect ppEffectEnable false;
GVAR(unconBlur) = _effect;

["ace_unconscious", {
    params ["_unit", "_enable"];
    if (_unit isNotEqualTo player) exitWith {};
    if (GVAR(unconSpectator)) exitWith {
        if (_enable) then {
            _unit setVariable ["ace_medical_feedback_effectUnconsciousTimeout", 10e10];
            [{
                if (!(player getVariable ["ace_isunconscious", false]) || {!alive player}) exitWith {};
                [true, true, false] call ace_spectator_fnc_setSpectator;
                [{
                    hint "You are unconscious!";
                }, nil, 0.5] call CBA_fnc_waitAndExecute;
            }, nil, 5] call CBA_fnc_waitAndExecute;
        } else {
            [false] call ace_spectator_fnc_setSpectator;
        };
    };

    if (!GVAR(blurUnconScreen) || {!(isNull (getAssignedCuratorLogic _unit))}) exitWith {};
    if (_enable) then {
        _unit setVariable ["ace_medical_feedback_effectUnconsciousTimeout", 10e10];
        [{
            if !(player getVariable ["ace_isunconscious", false]) exitWith {};
            [false, 0] call ace_medical_feedback_fnc_effectUnconscious;
        }] call CBA_fnc_execNextFrame;

        GVAR(unconBlur) ppEffectEnable true;
        GVAR(unconBlur) ppEffectAdjust [4];
        GVAR(unconBlur) ppEffectCommit 3;

    } else {
        _unit setVariable ["ace_medical_feedback_effectUnconsciousTimeout", nil];
        GVAR(unconBlur) ppEffectEnable true;
        GVAR(unconBlur) ppEffectAdjust [0];
        GVAR(unconBlur) ppEffectCommit 5;
    };
}] call CBA_fnc_addEventHandler;

["CAManBase", "Killed", {
    params ["_unit"];
    if (!GVAR(blurUnconScreen) || {_unit isNotEqualTo player}) exitWith {};
    GVAR(unconBlur) ppEffectEnable true;
    GVAR(unconBlur) ppEffectAdjust [0];
    GVAR(unconBlur) ppEffectCommit 1;
}] call CBA_fnc_addClassEventHandler;

// uncon spectator

// if you do NOT use JRM
player addEventHandler ["Respawn", {
    if !(isNil "fpa_jrm_respawns") exitWith {};
    if !(GVAR(unconSpectator)) exitWith {};
    [false] call ace_spectator_fnc_setSpectator;
}];

// if you use JRM
["fpa_jrm_respawned", {
    if !(GVAR(unconSpectator)) exitWith {};
    [false] call ace_spectator_fnc_setSpectator;
}] call CBA_fnc_addEventHandler;
