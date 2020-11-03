#include "script_component.hpp"
if (is3DEN || {!hasInterface}) exitWith {};


if (isMultiplayer) then {
    ["CBA_loadingScreenDone", {
        [{
            systemChat "Hit escape for the whisper UI integration. Use it to send messages to zeus, admins or other players without ruining other people's immersion!";
        }, [], 6] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;
};
