#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "A3_Ui_F",
            "fpa_common"
        };
        author = "diwako";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "gui\defines.hpp"
#include "gui\sendBoxBase.hpp"
#include "gui\interruptMenu.hpp"
#include "gui\rscTitles.hpp"
