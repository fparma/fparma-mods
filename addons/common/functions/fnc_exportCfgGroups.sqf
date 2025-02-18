/*
    Author: Karel Moricky, edited by Cuel for eden support

    Description:
    Export group or object composition for use in CfgGroups. The result will be copied to clipboard.

    Parameter(s):
        0: center object. Screen center is used by default
        1: objects to be saved. Currently selected objects in eden/curator are used by default
            ARRAY of OBJECTs - specific objects to be saved
            array in format used by nearEntities, which automatically get nearby objects
                0: STRING or ARRAY of STRINGS - object types
                1: NUMBER - radius in metres

    Returns:
    STRING
*/

params [
    ["_center", objNull],
    ["_objects", []],
    "_dir"
];

if (_center isEqualType objNull && {isNull _center}) then {_center = [curatorCamera, get3DENCamera] select is3DEN};
private _pos = _center call CBA_fnc_getPos;
if (isNil "_dir") then {_dir = getDir _center};

private _isTypeSearch = _objects params [
    ["_searchType", "AllVehicles", ["", []]],
    ["_radius", 100, [0]]
];

if (_isTypeSearch) then {
    _objects = _pos nearEntities [_searchType, _radius];
} else {
    if (count _objects isEqualTo 0) then {
        _objects = [curatorSelected select 0, get3DENSelected "object"] select is3DEN;
    };
};

if (count _objects isEqualTo 0) exitWith {
    ["No selected objects"] call BIS_fnc_error;
};

private _logic = createAgent ["Logic", _pos, [], 0, "none"];
_logic setPos _pos;
_logic setDir _dir;

private _text = "";
private _br = toString [13, 10];
{
    private _objPos = _logic worldToModel position _x;
    private _objSide = 8;
    private _objRank = "";
    if !(isNull group _x) then {
        _objSide = (_x call bis_fnc_objectSide) call bis_fnc_sideID;
        _objRank = rank _x;
    };
    private _objText = format [
        "class Object%1 {side = %2; vehicle = ""%3""; rank = ""%4""; position[] = {%5,%6,%7}; dir = %8;};",
        _forEachIndex,
        _objSide,
        typeOf _x,
        _objRank,
        (_objPos select 0),
        (_objPos select 1),
        getPosATL _x select 2,
        (getDir _x - _dir) % 360
    ];
    _text = _text + _objText + _br;
} forEach _objects;

deleteVehicle _logic;
copyToClipboard _text;
_text
