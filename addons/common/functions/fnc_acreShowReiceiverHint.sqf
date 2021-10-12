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

private _availableRadioList = [[_radioID], [] call acre_sys_data_fnc_getPlayerRadioList, false] call acre_sys_modes_fnc_checkAvailability;

if (_availableRadioList isEqualTo []) exitWith {};
private _playerRadioID = _availableRadioList select 0 select 1;
if (_playerRadioID isEqualTo []) exitWith {};
_playerRadioID = _playerRadioID select 0;

[{
    params ["_unit", "_radioID", "_playerRadioID"];
    if !(_unit in GVAR(acreTalking)) exitWith {};
    private _dataRemote = [_radioID, "getCurrentChannelData"] call acre_sys_data_fnc_dataEvent;
    private _frequencyRemote = _dataRemote getVariable ["frequencyTX", 0];
    ([_frequencyRemote, _dataRemote getVariable ["power", 0], _playerRadioID, _radioID] call acre_sys_signal_fnc_getSignal) params ["_pX", "_signal"];
    private _isShortRange = "acre_prc343" in _radioID || {"acre_sem70" in _radioID};
    private _radioClass = (toLower _playerRadioID) regexReplace ["(_id_\d+)", ""];
    private _cutOffPoint = getNumber (configfile >> "CfgAcreComponents" >> _radioClass >> "sensitivityMin");

    if (_signal <= _cutOffPoint || {_signal <= -150}) exitWith {};

    [
        format ["%1$%2", QGVAR(acre), name _unit],
        format ["%1", name _unit],
        format ["RX: %1", [_playerRadioID] call acre_api_fnc_getDisplayName],
        format ["CH: %1 | %2 | %3", [_playerRadioID] call acre_api_fnc_getRadioChannel, ([_playerRadioID] call acre_api_fnc_getRadioSpatial) select [0,1], groupId (group _unit)],
        -1,
        [GVAR(showReiceiverHintColorLR), GVAR(showReiceiverHintColorSR)] select _isShortRange
    ] call acre_sys_list_fnc_displayHint;
}, [_unit, _radioID, _playerRadioID], 0.1] call CBA_fnc_waitAndExecute;
