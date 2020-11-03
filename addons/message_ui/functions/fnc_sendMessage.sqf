#include "script_component.hpp"

private _editBox = uiNamespace getVariable [QGVAR(sendBoxCtrl), controlNull];
private _listbox = uiNamespace getVariable [QGVAR(sendBoxListboxCtrl), controlNull];

if (isNull _editBox || isNull _listbox) exitWith {};

private _message = ctrlText _editBox;
if (_message == "") exitWith {};

_editBox ctrlSetText "";
private _lbCurSel = lbCurSel _listbox;
private _lbData = _listbox lbData _lbCurSel;

if (_lbData isEqualTo "-1") exitWith {
    [_listbox] call FUNC(initListbox);
};

if (_lbData in ["zeus", "admin"]) then {
    [_message, _lbData] call EFUNC(common,sendChatMessage);
} else {
    private _receiver = [_lbData] call EFUNC(common,getPlayer);
    if (isNull _receiver) exitWith {
        systemChat "Could not find receiver";
        if (_lbData isEqualTo EGVAR(common,lastMessageFrom)) then {
            EGVAR(common,lastMessageFrom) = "";
        };
        [_listbox] call FUNC(initListbox);
    };
    [_message, "whisper", name _receiver] call EFUNC(common,sendChatMessage);
};
