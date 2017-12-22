/*
* Author: cuel
* Removes HUD elements for screenshot mode
*
* Arguments:
* 1 - boolean (mode)
*
* Example:
*  [] call fpa_common_fnc_toggleScreenshotMode
*
* Public: Yes
*/

#include "script_component.hpp"

if (isNil QGVAR(screenshotState)) then {
    GVAR(screenshotState) = [
        missionNamespace getVariable ["STHud_UIMode", 0],
        missionNamespace getVariable ["ace_nametags_showplayernames", 0],
        shownHUD
    ];

    missionNamespace setVariable ["STHud_UIMode", 0];
    missionNamespace setVariable ["ace_nametags_showplayernames", 0];
    showHUD (shownHUD apply {false});
} else {
    missionNamespace setVariable ["STHud_UIMode", GVAR(screenshotState) deleteAt 0];
    missionNamespace setVariable ["ace_nametags_showplayernames", GVAR(screenshotState) deleteAt 0];
    showHUD (GVAR(screenshotState) param [0, []]);
    GVAR(screenshotState) = nil;
};
