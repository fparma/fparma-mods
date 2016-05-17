#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"fp_main", "ace_main"};
        author[] = {"Cuel"};
        VERSION_CONFIG;
    };
};
