#include "script_component.hpp"

params [["_trigger", objNull, [objNull]], ["_enable", true, [true]], ["_displayHint", true]];
if (!(_trigger isKindOf "EmptyDetector")) exitWith {false};

if (_enable) then {
    _trigger setTriggerActivation ["ANYPLAYER", "PRESENT", true];
    private _onAct = {[true] call FUNC(disableWeapons);} call ace_common_fnc_codeToString;
    private _onDeAct = {diag_log "on deact"; [false] call FUNC(disableWeapons);} call ace_common_fnc_codeToString;

    if (_displayHint) then {
        private _text = {format ['["%1", "\A3\ui_f\data\map\markers\military\warning_ca.paa", [0, 0.5, 1]] call ace_common_fnc_displayTextPicture;', _this]};
        _onAct = _onAct + ("Entered safemode zone" call _text);
        _onDeAct = _onDeAct + ("Left safemode zone" call _text);
    };

    _trigger setTriggerStatements ["this && {player in thisList}", _onAct, _onDeAct];
} else {
    _trigger setTriggerStatements ["false", "", ""];
};

true

