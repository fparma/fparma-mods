#include "script_component.hpp"

params [["_ctrl",controlNull]];

private _fnc_getHeadlineText = {
    params ["_locStr"];
    private _text = if (isLocalized _locStr) then {localize _locStr} else {_locStr};
    _text = _text + " =======================================================================================";
    _text = [_text,0,30] call BIS_fnc_trimString;
    _text
};

private _fnc_addHeadline = {
    params ["_locStr"];
    private _index = [[_locStr] call _fnc_getHeadlineText,-1] call _fnc_addEntry;
    _ctrl lbSetColor [_index,[0.7,0.7,0.7,1]];
};

private _fnc_addEntry = {
    params ["_text","_data"];
    private _index = _ctrl lbAdd _text;
    _ctrl lbSetData [_index,if !(_data isEqualType "") then {str _data} else {_data}];
    _index
};

//LATEST CONVERSATION =========================================================
if (!isNil QEGVAR(common,lastMessageFrom) && {EGVAR(common,lastMessageFrom) != ""}) then {
    ["Reply to"] call _fnc_addHeadline;

    [toUpper EGVAR(common,lastMessageFrom), EGVAR(common,lastMessageFrom)] call _fnc_addEntry;
    ["",-1] call _fnc_addEntry;
};

["Help & Troubleshooting"] call _fnc_addHeadline;
["Zeus", "zeus"] call _fnc_addEntry;
["Admins", "admin"] call _fnc_addEntry;
["",-1] call _fnc_addEntry;

//LIST OF PLAYERS ==============================================================
["Players"] call _fnc_addHeadline;
private _playerData = [];
{
    private _name = [_x,true] call BIS_fnc_getName;
    _playerData pushBack [toUpper _name, _name];
} forEach ([] call CBA_fnc_players);
_playerData sort true;

{
    _x call _fnc_addEntry;
} forEach _playerData;


//SET CURSEL ===================================================================
if (lbCurSel _ctrl < 0 || lbCurSel _ctrl >= lbSize _ctrl) then {
    _ctrl lbSetCurSel 1;
} else {
    if (call compile (_ctrl lbData (lbCursel _ctrl)) < 0) then {
        _ctrl lbSetCurSel 1;
    };
};
