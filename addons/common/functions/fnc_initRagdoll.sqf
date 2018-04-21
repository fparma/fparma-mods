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
if(isNil QGVAR(init_ragdolling)) then {
	GVAR(init_ragdolling) = false;
};
// no need to initialise ragdolling twice!
if(GVAR(init_ragdolling)) exitWith {};
GVAR(init_ragdolling) = true;

["ace_unconscious", {
	params [["_unit", objNull],["_state", false]];
	if(_unit != player || {!GVAR(ragdolling)}) exitWith {}; // only ragdoll players and only ragdolling if it active
	if(_state && {vehicle _unit == _unit && {!([_unit] call ace_medical_fnc_isBeingCarried) && {!([_unit] call ace_medical_fnc_isBeingDragged)}}}) then {
		// ragdoll player
		_unit setUnconscious true;
	};
	if(!_state) then {
		// player woke up before ragdolling was finished
		_unit setUnconscious false;
	};
}] call CBA_fnc_addEventHandler;
player addEventHandler ["AnimChanged", {
	params ["_unit","_anim"];
    if(!GVAR(ragdolling)) exitWith {}; // disable ragdolling mid mission
	if(_anim == "unconsciousrevivedefault" && {alive _unit && {_unit getVariable ["ACE_isUnconscious",false] && {vehicle _unit == _unit}}}) then {
		// unit stopped ragdolling, apply ace_death animation to unit
		_unit setUnconscious false;
		[_unit, [_unit] call ace_common_fnc_getDeathAnim, 2, true] call ace_common_fnc_doAnimation;
		if(isMultiplayer) then {
			// combat sync issues
            [{
                params["_unit"];
                if(!(_unit getVariable ["ACE_isUnconscious",false])) then {
					// unit is not unconscious anymore
					_unit setUnconscious false;
				} else {
					// unit is still unconscious, reapply death animation just in case and sync it again to all clients
					[_unit, [_unit] call ace_common_fnc_getDeathAnim, 2, true] call ace_common_fnc_doAnimation;
				};
            }, [_unit]] call CBA_fnc_waitAndExecute;
		};
	};
}];
player createDiaryRecord ["CBA_docs", ["Ragdolling", "Ragdolling has been activated in this mission! Better check those bodies!"]];