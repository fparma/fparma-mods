/*
    Author: diwako

    Description:
    Adds ragdolling for players upon going unconscious

    Parameter(s):
    none

    Examples:
    (begin)
        [] call fpa_common_fnc_initRagdoll;
    (end)

    Returns:
    none
*/
#include "script_component.hpp"

if(!hasInterface) exitWith {};

// no need to initialise ragdolling twice!
if (RETDEF(GVAR(ragdollRunning),false)) exitWith {};
GVAR(ragdollRunning) = true;

["ace_unconscious", {
    params [["_unit", objNull],["_state", false]];
    if(!GVAR(ragdolling)) exitWith {}; // ragdolling if it's active
    if((!(isPlayer _unit) && {!GVAR(ragdoll_ai)})) exitWith {}; // only ragdoll players and only ragdolling AI if that option is set active
    if(_state && {(isNull objectParent _unit) && {!([_unit] call ace_medical_fnc_isBeingCarried) && {!([_unit] call ace_medical_fnc_isBeingDragged)}}}) then {
        // ragdoll unit
        _unit setUnconscious true;
    };
    if(!_state) then {
        // unit woke up before ragdolling was finished
        _unit setUnconscious false;
        // if(isMultiplayer && {_unit == ace_player}) then {
        if(_unit == ace_player) then {
            // try to brute force animation in case unit is still ragdolled on another machine
            [
                {
                    params ["_unit"];
                    if!(_unit getVariable ["ACE_isUnconscious",false]) then {
                        _unit setUnconscious false;
                        ["ace_common_switchMove", [_unit, (animationState _unit)]] call CBA_fnc_globalEvent;
                    };
                }, // code
                [_unit], // params
                10 // delay
            ] call CBA_fnc_waitAndExecute;
        };
    };
}] call CBA_fnc_addEventHandler;

["CAManBase", "AnimChanged", {
    _this call FUNC(ragdoll_animChangedEH);
}] call CBA_fnc_addClassEventHandler;

player createDiaryRecord ["CBA_docs", ["Ragdolling", "Ragdolling has been activated in this mission! Better check those bodies!"]];