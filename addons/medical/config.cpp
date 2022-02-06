#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = QUOTE(COMPONENT_NAME);
        units[] = {QGVAR(vitalItem)};
        weapons[] = {QGVAR(vital)};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"fpa_main", "ace_medical_treatment", "ace_zeus"};
        author = "diwako";
        authorUrl = "";
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "ACE_Medical_Treatment.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"
#include "zen_context_menu_actions.hpp"
