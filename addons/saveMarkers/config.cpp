#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = "GRAD";
        name = QUOTE(ADDON);
        requiredVersion = 1.0;
        requiredAddons[] = {"fpa_main", "fpa_common"};
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "cfgNotifications.hpp"
#include "cfgEventhandlers.hpp"
#include "ui\dialog.hpp"
