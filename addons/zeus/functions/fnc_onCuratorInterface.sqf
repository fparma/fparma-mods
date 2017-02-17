/*
* Event on curator interface opened. Adds FP icon
*/
#include "script_component.hpp"
#include "\A3\ui_f_curator\ui\defineResinclDesign.inc"

// module categories are not loaded on this frame
[{
    disableSerialization;
    params ["_display"];
    if (isNull _display) exitWith {};

    private _ctrl = _display displayCtrl IDC_RSCDISPLAYCURATOR_CREATE_MODULES;

    for "_i" from 0 to (_ctrl tvCount []) do {
        private _name = _ctrl tvText [_i];
        if ((_name select [0, 3]) == "FP ") then {
            _ctrl tvSetPicture [[_i], QPATHTOF(data\icon_fp.paa)];
        };
    };
}, _this] call CBA_fnc_execNextFrame;
