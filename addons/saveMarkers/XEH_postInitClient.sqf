#include "script_component.hpp"

private _title = "Save Markers";
private _helpText = "
If you slotted for a commanding role in an upcoming mission, this tool will come in handy. Save Markers allows you to save any markers from one mission and load them in another. That means you can just start a game in advance to the actual mission, draw your plan on the map, and save it for later. On gameday, you can load your markers instantly, saving valuable preparation time.<br/>
<br/>
After mission start you can open the Save Marker dialog with the chatcommand '#fp.saveMarkers', or by clicking here:<br/>
<execute expression='openMap [false,false]; [fpa_saveMarkers_fnc_openDialog,[]] call CBA_fnc_execNextFrame;'>[Open Save Markers]</execute><br/>
During map screen you can also load markers if you know the save name like so:<br/>
'#fp.saveMarkers %save name goes here%'
";
// <execute expression='openMap [false,false]; [fpa_saveMarkers_fnc_loadDisplay,[]] call CBA_fnc_execNextFrame;'>[Open Save Markers]</execute>

if (isMultiplayer) then {
    _helpText = _helpText + "<br/><br/>This message will self destruct 10 minutes after mission start!";

    [{ time > 0.1},{
        private _wait = 600 - CBA_missionTime;
        [{
            player removeDiarySubject QGVAR(helpSubject);
        }, [], 0 max _wait] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_waitUntilAndExecute
};

player createDiarySubject [QGVAR(helpSubject),"FPA Save Marker"];
player createDiaryRecord [QGVAR(helpSubject),[
    _title,
    format ["<font size='32' color='#D18D1F' face='RobotoCondensedLight'>%1</font><br/><br/>%2",_title,_helpText]
]];
