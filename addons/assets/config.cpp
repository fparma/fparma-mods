#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"fpa_main", "A3_Boat_F_Boat_Transport_01"};
        author[] = {"Cuel"};
        authorUrl = "";
        VERSION_CONFIG;
    };
};

#include "CfgSounds.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
