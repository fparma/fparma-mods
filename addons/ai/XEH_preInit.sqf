#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (isServer) then {
    GVAR(cachedGroups) = [[], []] call CBA_fnc_hashCreate;
    GVAR(activeGroups) = createHashMap;

    [QGVAR(updateActiveGroups), {
        params ["_newGroups", "_id"];
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
