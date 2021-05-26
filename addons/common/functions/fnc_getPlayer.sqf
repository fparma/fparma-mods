#include "script_component.hpp"
/*
    Function: fpa_common_fnc_getPlayer

    API:
        Any

    Description:
        Takes a string and returns a player object if found, otherwise objNull
        Can be used partially, to find "cuel" you can pass ["cu"]
        Will be objNull if not found, or if theres more than one match
        Case insensitive

    Parameters:
        _name - Player name

    Examples:
    (begin example)
        _cuel = "cu" call fpa_common_fnc_getPlayer;
        _cuel = ["Cuel"] call fpa_common_fnc_getPlayer;
    (end)

    Returns:
        Object

    Author:
        Cuel 2015-04-21
*/
params ["_name"];
_name = toLower _name;
private _players = ([] call CBA_fnc_players) select {_name in toLower(name _x)};
if ((count _players) isEqualTo 1) exitWith {_players select 0};
objNull
