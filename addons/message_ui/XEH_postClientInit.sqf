#include "script_component.hpp"
if (is3DEN || {!hasInterface}) exitWith {};


if (isMultiplayer) then {
    ["CBA_loadingScreenDone", {
        [{
            systemChat "Hit escape for the whisper UI. Send messages to zeus, admins, or players when you need to say something without ruining other people's immersion!";
        }, [], 6] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;
};
