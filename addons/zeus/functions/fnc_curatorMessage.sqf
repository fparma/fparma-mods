/*
* Author: Cuel
* Show curator feedback
*
* Arguments:
* 0: Message  <sintrg>
*
* Public: No
*/

#include "script_component.hpp"
params [["_msg", ""], ["_sound", true]];

[objNull, _msg] call BIS_fnc_showCuratorFeedbackMessage;
if (_sound) then {playSound "RscDisplayCurator_error01"};
