#include "script_component.hpp"
#include "\A3\ui_f_curator\ui\defineResinclDesign.inc"
disableSerialization;

private _display = findDisplay IDD_RSCDISPLAYCURATOR;
TRACE_1("isnull",_display);
if (isNull _display) exitWith {};

private _yCord = safezoneY + 0.4 * safezoneH;

private _pos = [safezoneX + 0.5 * safezoneW, _yCord, 0.5, 0.5];
private _bg = _display ctrlCreate ["IGUIBack", 5151];
_bg ctrlSetPosition _pos;
_bg ctrlCommit 0;

_bg spawn {
    disableSerialization;
    sleep 3;
    private _ok = ctrlDelete _this;
};
