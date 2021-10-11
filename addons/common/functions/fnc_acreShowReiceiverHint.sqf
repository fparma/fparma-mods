#include "script_component.hpp"
/*
* Author: diwako
*
* Description:
* Uses ACRE's hint system to show who is sending you a message
*
* Arguments:
* 0 - unit
* 1 - speaking type (local, radio, god, etc)
* 2 - Radio id
*
* Example
* [carl, 1, "acre_prc148_id_2"] call fpa_common_fnc_acreShowReiceiverHint
*
* Public: no
*/

params ["_unit", ["_onRadio", 0], ["_radioID", ""]];
if !(GVAR(showReiceiverHint)) exitWith {};
private _player = [] call CBA_fnc_currentUnit;
if (_onRadio isNotEqualTo 1 || {_unit isEqualTo _player || {!([_radioID] call acre_sys_radio_fnc_canUnitReceive)}}) exitWith {};

[
    format ["%1$%2", QGVAR(acre), name _unit],
    format ["%1", name _unit],
    format ["RX: %1", [_radioID] call acre_api_fnc_getDisplayName],
    format ["CH: %1 | %2", [_radioID] call acre_api_fnc_getRadioChannel, groupId (group _unit)],
    -1,
    GVAR(showReiceiverHintColor)
] call acre_sys_list_fnc_displayHint;
