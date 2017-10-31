#include "script_component.hpp"

if (!hasInterface) exitWith {};
_this call ace_spectator_fnc_setSpectator;

// TODO: remove in ace 3.12.0
if (param [0, true] isEqualTo false) then {
    [player, "ace_spectator_isSet"] call ace_common_fnc_unhideUnit;
    [player, "ace_spectator_isSet"] call ace_common_fnc_unmuteUnit;
    player setVariable ["ace_spectator_isSet", false, true];
    if (RETDEF(ace_spectator_uiDraw3D,-1) > -1) then {
        removeMissionEventHandler ["Draw3D", ace_spectator_uiDraw3D];
    };
};
