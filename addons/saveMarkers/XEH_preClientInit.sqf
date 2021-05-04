#include "script_component.hpp"

["saveMarkers", {
    params [["_name", ""]];

    private _canOpen = switch (true) do {
        case (call EFUNC(common,isAdmin)): {true};
        case (GVAR(setting_canBeOpened) == 2): {true};
        case (GVAR(setting_canBeOpened) == 1 && {(missionNamespace getVariable ["CBA_missionTime",0]) < 600}): {true};
        default {false};
    };

    if (!_canOpen) exitWith {
        playSound "3DEN_notificationWarning";
        systemChat "FPA saveMarkers is currently disabled by the mission. Log in as admin to use.";
    };

    if (_name isEqualTo "") exitWith {
        [] call FUNC(openDialog);
    };

    private _saveMarkersData = profileNamespace getVariable [QGVAR(saveData), []];

    private _index = _saveMarkersData findIf {(_x select 0) == _name && {(_x select 1) == worldName}};
    if (_index == -1) exitWith {
        playSound "3DEN_notificationWarning";
        systemChat format ["fpa-saveMarkers: Save with name ""%1"" could not be found for this terrain!", _name];
    };

    (_saveMarkersData select _index) params ["_saveName","_mapName",["_markersData",[]]];

    [_saveName,_mapName,_markersData] call FUNC(loadMarkers);

    (format ["fpa-saveMarkers: %1 just loaded his marker set %2.",profileName,_saveName]) remoteExec ["systemChat",0,false];
}, "Save and load markers <#fp.saveMarkers>", false] call EFUNC(common,registerChatCommand);

[] call FUNC(loadNotification);
