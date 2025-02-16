/*
* Author: Cuel
* Get all endings available
*
*
* Public: Yes
*/

#include "script_component.hpp"
params [["_filterBad", true]];

private _endings = [];
private _usedClasses= [];

private _missionEndings = "true" configClasses (getMissionConfig "CfgDebriefing");
private _addonEndings = "true" configClasses (configFile >> "CfgDebriefing");

private _add = {
    params [["_config", configNull]];
    if (isNull _config) exitWith {};

    private _cfgName = configName _config;
    if !((toLower _cfgName) in _usedClasses) then {
        private _title = getText (_config >> "title");
        if (_title isEqualTo "") exitWith {};

        private _extra = getText (_config >> "subtitle");
        private _str = format ['(%1) "%2" %3', _cfgName, _title, ["", " - " + _extra] select (count _extra > 0)];

        _endings pushBack [_cfgName, _str];
        _usedClasses pushBack (toLower _cfgName);
    };
};

// add all mission endings first
{_x call _add} forEach _missionEndings;

if (_filterBad) then {
    _addonEndings = _addonEndings select {
        private _name = configName _x;
        (_name select [0, 8] != "moduleMP" &&
            {_name select [0,5] != "CPEnd"} &&
            {toUpper _name isNotEqualTo _name})
    };
};

{_x call _add} forEach _addonEndings;

_endings
