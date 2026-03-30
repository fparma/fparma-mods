
#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(vehicleNames) = [];
GVAR(admins) = compileFinal str (getArray (configFile >> QGVAR(admins)));

#include "settings.inc.sqf"

[QGVAR(endMission), {
    if (!isNil QGVAR(ending)) exitWith {};
    GVAR(ending) = true;

    params [["_args", []]];
    private _ending = "End1";
    private _won = true;

    if (_args isEqualType "") then {
        _ending = _args;
    } else {
        {
            if (_x isEqualType "") then {
                _ending = _x param [0, "End1"];
                _won = _x param [1, true];
            } else {
                if (_x isEqualType []) then {
                    private _side = _x param [2, sideUnknown];
                    if (side group player == _side) then {
                        _ending = _x param [0, "End1"];
                        _won = _x param [1, true];
                    };
                };
            };
        } forEach _args;
    };

    [true] call FUNC(disableWeapons);
    [_ending, _won] call BIS_fnc_endMission;
}] call CBA_fnc_addEventHandler;

ADDON = true;
