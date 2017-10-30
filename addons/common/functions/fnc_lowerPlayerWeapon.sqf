/*
* Author: ACE-Team (doAnimation), modified by Cuel
*
* Description:
* lowers player weapon
*
* Arguments:
* None
*
* Public: Yes
*/

#include "script_component.hpp"

if (!hasInterface) exitWith {};

// can't do anim until mission started
[{!isNull player && {time > 0}}, {
    private _unit = player;

    if (vehicle _unit != _unit) exitWith {};
    private _anim = toLower animationState _unit;

    // stance is broken for some animations.
    private _stance = stance _unit;
    if (_anim find "ppne" == 4) then {
    _stance = "PRONE";
    };

    if (_anim find "pknl" == 4) then {
    _stance = "CROUCH";
    };

    if (_anim find "perc" == 4) then {
    _stance = "STAND";
    };

    _anim = format ["AmovP%1M%2S%3W%4D%5",
        ["erc", "knl", "pne"] select (["STAND", "CROUCH", "PRONE"] find _stance) max 0,
        ["stp", "run"] select (vectorMagnitude velocity _unit > 1),
        ["low", "non"] select (currentWeapon _unit == ""),
        ["non", "rfl", "lnr", "pst", "bin"] select (["", primaryWeapon _unit, secondaryWeapon _unit, handgunWeapon _unit, binocular _unit] find currentWeapon _unit) max 0,
        ["non", _anim select [count _anim - 1, 1]] select (_anim select [count _anim - 2, 2] in ["df", "db", "dl", "dr"])
    ];

    player switchMove (["", _anim] select isClass (configFile >> "CfgMovesMaleSdr" >> "States" >> _anim));
}] call CBA_fnc_waitUntilAndExecute;
