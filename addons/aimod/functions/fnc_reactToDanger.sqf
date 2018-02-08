
#include "script_component.hpp"
params ["_grp", ["_dangerCause", objNull]];

[_grp, _dangerCause] call FUNC(broadcastInfo);
[_grp, _dangerCause] call FUNC(mountWeapons);
