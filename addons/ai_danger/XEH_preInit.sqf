#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(broadcast), {
    params ["_thisGrp", "_senderGrp", "_dangerCause", "_knowledge"];
    if (_thisGrp knowsAbout _dangerCause < _knowledge) then {
        TRACE_4("Receive knowledge",_thisGrp,_senderGrp,_dangerCause,_knowledge);
        _thisGrp reveal [_dangerCause, _knowledge];
    };

    // TODO: SAD waypoint
    /*private _isGarrisoned  = {if (_x getVariable ["ace_ai_garrisonned", false]) exitWith {1}} count units _thisGrp isEqualTo 1;
    if (!_isGarrisoned) then {

    };
    */
}] call CBA_fnc_addEventHandler;

ADDON = true;
