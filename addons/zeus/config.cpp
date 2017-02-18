#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            QGVAR(moduleSupressionUnit),
            QGVAR(moduleSupressionTarget),
            QGVAR(moduleHealUnit),
            QGVAR(moduleHealGroup),
            QGVAR(moduleToggleGodmode),
            QGVAR(moduleCustom01),
            QGVAR(moduleCustom02),
            QGVAR(moduleCustom03),
            QGVAR(moduleCustom04),
            QGVAR(moduleCustom05),
            QGVAR(moduleCustom06),
            QGVAR(moduleCustom07),
            QGVAR(moduleCustom08),
            QGVAR(moduleCustom09),
            QGVAR(moduleCustom10)
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
