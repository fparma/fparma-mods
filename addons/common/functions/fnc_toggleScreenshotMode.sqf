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
        missionNamespace getVariable ["diwako_dui_main_toggled_off", false],
        missionNamespace getVariable [QGVAR(showReiceiverHint), false],
        shownHUD
    ];

    missionNamespace setVariable ["STHud_UIMode", 0];
    missionNamespace setVariable ["ace_nametags_showplayernames", 0];
    missionNamespace setVariable ["diwako_dui_main_toggled_off", true];
    showHUD (shownHUD apply {false});
    GVAR(showReiceiverHint) = false;

    hintSilent "";
    showChat false;

    if !(isNil "acre_player") then {
        ("acre_sys_gui_vehicleInfo" call BIS_fnc_rscLayer) cutText ["", "PLAIN"];
    };
} else {
    missionNamespace setVariable ["STHud_UIMode", GVAR(screenshotState) deleteAt 0];
    missionNamespace setVariable ["ace_nametags_showplayernames", GVAR(screenshotState) deleteAt 0];
    missionNamespace setVariable ["diwako_dui_main_toggled_off", GVAR(screenshotState) deleteAt 0];
    missionNamespace setVariable [QGVAR(showReiceiverHint), GVAR(screenshotState) deleteAt 0];
    showHUD (GVAR(screenshotState) param [0, []]);
    showChat true;
    if !(isNil "acre_player") then {
        private _player = acre_player;
        if !(isNull objectParent _player) then {
            // Show UI
            [_player, vehicle _player] call acre_sys_gui_fnc_enterVehicle;
            // Wait until UI is initialized
            [{
                [vehicle _this, _this] call acre_sys_intercom_fnc_updateVehicleInfoText;
            }, _player, 0.5] call CBA_fnc_waitAndExecute;
        };
    };
    GVAR(screenshotState) = nil;
};
