#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

ADDON = true;

// Fix setdir
// TODO: remove when added to ace or cba
["ModuleCurator_F", "init", {
    params ["_logic"];

    _logic addEventHandler ["CuratorObjectEdited", {
        params ["", "_unit"];

        if (!local _unit) then {
            private _dir = getDir _unit;
            [_unit, _dir] remoteExec ["setDir", _unit];

            if (_unit == formLeader _unit) then {
                [_unit, _dir] remoteExec ["setFormDir", _unit];
            };
        };
    }];
}] call CBA_fnc_addClassEventHandler;
