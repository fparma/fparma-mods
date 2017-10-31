/**
* Description:
* Validate mission settings
* Currently checks wind, respawn type and respawn templates
* 
* Arguments:
* 0 - Mission config
*/

params [["_cfg", configNull]];
if (isNull _cfg) exitWith {false};

private _err = [];
private _add = {
        _err pushBack _this;
        _err pushBack lineBreak;
};

// Respawn type
private _okrespawn = getMissionConfigValue "respawn" isEqualTo "BASE";
if (!_okrespawn) then {
    'Error: Respawn is not set to "BASE"' call _add;
};

// RespawnTemplates
private _custom = "true" configClasses (_cfg >> "CustomAttributes") select {getText (_x >> "name") == "multiplayer"};
if !(_custom isEqualTo []) then {
    private _res = "true" configClasses (_custom select 0) select {getText (_x >> "property") == "RespawnTemplates"};
     if (!(_res isEqualTo []) && {getText ((_res select 0) >> "expression") == "true"}) then {
        "Error: Do not select any RespawnTemplates in Eden" call _add;
    };
};

// Check unit lobby description and callsign
private _grps = "true" configClasses (_cfg >> "Mission" >> "Entities") select {getText (_x >> "dataType") == "Group"};
{
    private _ents = "true" configClasses (_x >> "Entities") select {getText (_x >> "dataType") == "Object"};
    private _hasPlayable = {
        private _attrs = _x >> "Attributes";
        if (getNumber(_attrs >> "isPlayer") isEqualTo 1 || getNumber(_attrs >> "isPlayable") isEqualTo 1) exitWith {true};
        false
    } forEach _ents;

    if (_hasPlayable) then {
        private _ldr = (_ents select 0) >> "Attributes";
        private _hasDesc = ["@", getText (_ldr >> "description")] call bis_fnc_inString;
        if (!_hasDesc) then {
            private _c = str _x;
            private _desc = getText (_ldr >> "description");
            (format [
                "Warning: A playable group is missing lobby description (@ sign on first unit) [%1, %2, %3, %4]",
                [_desc, "<empty description>"] select (_desc isEqualTo ""),
                getText (_ldr >> "name"),
                getText ((_ents select 0) >> "type"),
                _c select [(_c find "MissionSQM"), count _c]
            ]) call _add;
        };

        private _attr = "true" configClasses (_x >> "CustomAttributes") select {getText (_x >> "property") == "groupID"};
        private _str =  getText ((_attr select 0) >> "Value" >> "data" >> "value");
        if (_attr isEqualTo [] || {_str isEqualTo ""}) then {
            private _c = str _x;
            (format ["Warning: A playable group is missing a callsign (%1)", _c select [(_c find "MissionSQM"), count _c]]) call _add;
        };
    };
} forEach _grps;

if (!(_err isEqualTo [])) then {
    "Validation errors" hintC composeText _err;
};
