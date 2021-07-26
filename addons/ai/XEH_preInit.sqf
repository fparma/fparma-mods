#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (isServer) then {
    [QGVAR(updateActiveGroups), {
        params ["_newGroups"];
        private _spawnedGroups = GVAR(activeGroups) getOrDefault [_id, []];
        _spawnedGroups append _newGroups;
        GVAR(activeGroups) set [_id, _spawnedGroups];
    }] call CBA_fnc_addEventHandler;
};

if (isServer || {!hasInterface}) then {
    [QGVAR(spawnGroups), {
        call FUNC(spawnGroups);
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
