/*
 * Author: Cuel
 * lowers player weapon
 *
 * Arguments:
 *
 * Public: Yes
 */

 #include "script_component.hpp"

if (!hasInterface) exitWith {};

[{
    private _anim = switch (currentWeapon player) do {
        case (primaryWeapon player): {"amovpercmstpslowwrfldnon"};
        case (handgunWeapon player): {"amovpercmstpsraswpstdnon"};
        default {""};
    };

    if (_anim != "") then {
        [{
            [player, _this] remoteExecCall ["switchMove"];
        }, _anim] call CBA_fnc_execNextFrame;
    };
}] call FUNC(runAfterPreload);
