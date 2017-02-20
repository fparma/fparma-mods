#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            QGVAR(moduleHealUnit),
            QGVAR(moduleHealGroup),
            QGVAR(moduleSupressionUnit),
            QGVAR(moduleSupressionTarget),
            QGVAR(moduleForceWP),
            QGVAR(moduleToggleGodmode),
            QGVAR(moduleSmoke),
            QGVAR(moduleSwapNV),
            QGVAR(moduleDisableWeapons),
            QGVAR(moduleUnitCode),
            QGVAR(moduleCode),
            QGVAR(moduleCustom)
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

#include "ui\dynamicDialog.hpp"
