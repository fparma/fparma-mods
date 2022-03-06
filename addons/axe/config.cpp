#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = "Gruppe Adler";
        name = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"fpa_main", "ace_interaction"};
        units[] = {};
        weapons[] = {QGVAR(axe)};
        authorUrl = "";
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"
