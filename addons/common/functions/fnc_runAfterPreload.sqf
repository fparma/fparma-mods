#include "script_component.hpp"
params [
    ["_code", {}, [{}]],
    ["_args", []]
];

if (GVAR(preloadFinished)) exitWith {_args call _code; true};

if (isNil QGVAR(runAfterPreload)) then {GVAR(runAfterPreload) = []};
GVAR(runAfterPreload) pushBack [_args, _code];

true
