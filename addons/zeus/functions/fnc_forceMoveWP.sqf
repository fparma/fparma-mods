
#include "script_component.hpp"
params ["_logic", "_units", "_activated"];
if !(_activated && local _logic) exitWith {};
deleteVehicle _logic;

private _unit = [] call FUNC(getUnitUnderCursor);

_grp = group _unit;
_grp setBehaviour "AWARE";
_grp setCombatMode "RED";
_grp setSpeedMode "FULL";
_grp setFormation "LINE";
_grp allowFleeing 0;

{
    _x disableAI "AUTOCOMBAT";
    _x disableAI "COVER";
    _x setUnitPosWeak "UP";
} forEach (units _grp);
