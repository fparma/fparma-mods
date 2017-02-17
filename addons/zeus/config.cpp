#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            QGVAR(moduleSupressionUnit),
            QGVAR(moduleSupressionTarget)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"fpa_main"};
        author[] = {"Cuel"};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
