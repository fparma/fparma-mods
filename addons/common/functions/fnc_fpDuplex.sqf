#include "script_component.hpp"
/*
* Author: diwako
*
* Description:
* Code for acre's remote started speaking event
*
* Arguments:
* 0 - unit
* 1 - speaking type (local, radio, god, etc)
* 2 - Radio id
*
* Example
* [carl, 1, "acre_prc148_id_2"] call fpa_common_fnc_fpDuplex;
*
* Public: no
*/

params ["_unit", ["_onRadio", 0], ["_radioID", ""]];
if !(GVAR(useFpDuplex)) exitWith {};
private _player = [] call CBA_fnc_currentUnit;
if (_onRadio isNotEqualTo 1 || {_unit isEqualTo _player || {_player getVariable [QGVAR(hasFPDuplexPriority), false] || {!([_radioID] call acre_sys_radio_fnc_canUnitReceive)}}}) exitWith {};
private _isLR = false;
private _prcBand = false;
{
    if (_x in _radioID) then {
        _isLR = true;
        _prcBand = true;
        break;
    };
} forEach ["acre_prc148", "acre_prc117f", "acre_prc152", "acre_prc77", "acre_vrc64", "acre_vrc103", "acre_vrc110", "acre_vrc111"];

if !(_isLR) then {
    {
        if (_x in _radioID) then {
            _isLR = true;
            break;
        };
    } forEach ["acre_sem70", "acre_sem90"];
};

if !(_isLR) exitWith {}; // exit if not a LR radio
if !([_player] call acre_api_fnc_isBroadcasting) exitWith {}; // player is not broadcasting
private _currentPlayerRadio = [] call acre_api_fnc_getCurrentRadio;
if ("acre_prc343" in _currentPlayerRadio || {"acre_sem52sl" in _currentPlayerRadio}) exitWith {}; // player is speaking on short range
if (_prcBand && {"acre_sem" in _currentPlayerRadio}) exitWith {};
if (!_prcBand && ({"acre_prc" in _currentPlayerRadio || {"acre_vrc" in _currentPlayerRadio}})) exitWith {};
private _dataRemote = [_radioID, "getCurrentChannelData"] call acre_sys_data_fnc_dataEvent;
private _dataPlayer = [_currentPlayerRadio, "getCurrentChannelData"] call acre_sys_data_fnc_dataEvent;

private _frequencyRemote = _dataRemote getVariable ["frequencyTX", 0];
private _frequencyPlayer = _dataPlayer getVariable ["frequencyTX", 0];

if (_frequencyRemote isEqualTo _frequencyPlayer) then {
    [{
        params ["_frequencyRemote", "_dataRemote", "_currentPlayerRadio", "_radioID", "_unit", "_player"];
        ([_frequencyRemote, _dataRemote getVariable ["power", 0], _currentPlayerRadio, _radioID] call acre_sys_signal_fnc_getSignal) params ["_pX", "_signal"];

        private _radioClass = (toLower _currentPlayerRadio) regexReplace ["(_id_\d+)", ""];
        private _cutOffPoint = getNumber (configFile >> "CfgAcreComponents" >> _radioClass >> "sensitivityMin");

        if (_signal <= _cutOffPoint || {_signal <= -150}) exitWith {};

        // steppy
        if (GVAR(fpDuplexCutOffTransmission)) then {
            [] call acre_sys_core_fnc_handleMultiPttKeyPressUp;
        };

        systemChat format [selectRandom [
            "%1 (%2) stepped on your message",
            "Your message was cut off by %1 (%2)",
            "%1 (%2) just stomped your message"
        ], name _unit, groupId (group _unit)];
        playSound "3DEN_notificationWarning";
        if (player isEqualTo _player) then {
            [QGVAR(acreInterruped), [player], _unit] call CBA_fnc_targetEvent;
        };
    }, [_frequencyRemote, _dataRemote, _currentPlayerRadio, _radioID, _unit, _player], 0.1] call cba_fnc_waitAndExecute;
};
