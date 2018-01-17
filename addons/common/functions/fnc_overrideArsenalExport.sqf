/*
    Author: Cuel

    Description:
    Uses CBA DisplayLoad XEH to override the arsenal export button

*/

#include "script_component.hpp"
#define ID 909053

if (!RETDEF(GVAR(overrideArsenalExport),false)) exitWith {};

disableSerialization;
params [["_btnCtrl", controlNull], ["_display", displayNull], ["_mountCtrl", controlNull]];
if (isNull _btnCtrl || isNull _mountCtrl) exitWith {};

private _btn = _display ctrlCreate ["RscButton", ID, _mountCtrl];
_btn ctrlSetPosition (ctrlPosition _btnCtrl);
_btn ctrlSetScale (ctrlScale _btnCtrl);
_btn ctrlSetEventHandler ["buttonclick", QUOTE([] call FUNC(copyAllGear))];
_btn ctrlSetText ("(FP) " + ctrlText _btnCtrl);
_btnCtrl ctrlShow false;
_btn ctrlCommit 0;
