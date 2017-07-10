/*
* Event on curator interface opened. Adds FP icon
*/
#include "script_component.hpp"
#include "\A3\ui_f_curator\ui\defineResinclDesign.inc"

if (isNil QGVAR(categories)) then {
    GVAR(categories) = "true" configClasses (configFile >> "CfgFactionClasses")
        select {QUOTE(ADDON) in (configSourceAddonList _x)}
        apply {getText (_x >> "displayName")};
};

// module categories are not loaded on this frame
[{
    disableSerialization;
    params ["_display"];
    if (isNull _display) exitWith {};

    private _ctrl = _display displayCtrl IDC_RSCDISPLAYCURATOR_CREATE_MODULES;
    private _customCategoryName = getText (configFile >> "CfgFactionClasses" >> QGVAR(Custom) >> "displayName");
    GVAR(customCategoryIdx) = -1;

    // Set icon on FP modules
    for "_i" from 0 to (_ctrl tvCount []) do {
        private _name = _ctrl tvText [_i];
        if (_name in GVAR(categories)) then {
            _ctrl tvSetPicture [[_i], QPATHTOF(data\icon_fp.paa)];

            if (_name isEqualTo _customCategoryName) then {
                GVAR(customCategoryIdx) = _i;
            };
        };
    };

    // Delete the custom category if no registered modules
    if (GVAR(customCategoryIdx) isEqualTo -1) exitWith {};
    if (count GVAR(registeredCustomModules) isEqualTo 0) exitWith {
        _ctrl tvDelete [GVAR(customCategoryIdx)];
    };

    // delete the first empty module, it's just there to get the category
    _ctrl tvDelete [GVAR(customCategoryIdx), 0];

    // add all registered modules
    {
        _x params [["_displayName", ""]];
        private _idx = _ctrl tvAdd [[GVAR(customCategoryIdx)], _displayName];
        private _path = [GVAR(customCategoryIdx), _idx];
        _ctrl tvSetData [_path, QGVAR(moduleCustom)];
        _ctrl tvSetValue [_path, _forEachIndex];
    } forEach GVAR(registeredCustomModules);
    _ctrl tvSort [QGVAR(customCategoryIdx), false];

    // After the module is placed the current selection is removed
    // we save whatever the curator selects in the custom category and run that index
    // not the cleanest solution but hey..
    _ctrl ctrlAddEventHandler ["MouseButtonUp", {
        params ["_ctrl"];
        tvCurSel _ctrl params [["_category", -1], ["_idx", -1]];
        if (GVAR(customCategoryIdx) isEqualTo _category && _idx >= 0) then {
            TRACE_1("Selected custom category",_idx);
            GVAR(selectedCustomIdx) = _idx;
        };
    }];
}, _this] call CBA_fnc_execNextFrame;
