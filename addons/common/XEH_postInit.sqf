#include "script_component.hpp"

if (isServer) then {
    GVAR(chatChannel) = radioChannelCreate [[0.9,0.1,0.1,1], "Chat", "Chat", [], true];
    publicVariable QGVAR(chatChannel);
};

#include "commands_admins.sqf"
#include "commands_clients.sqf"
