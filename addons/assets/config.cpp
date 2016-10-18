#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"fpa_main"};
        author[] = {"Cuel"};
        authorUrl = "";
        VERSION_CONFIG;
    };
};

#include "CfgSounds.hpp"
