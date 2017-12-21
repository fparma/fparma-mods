#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_common"};
        author[] = {"Cuel"};
        authorUrl = "";
        VERSION_CONFIG;
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        serverInit = QUOTE(call COMPILE_FILE(XEH_preInitServer));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        serverInit = QUOTE(call COMPILE_FILE(XEH_postInitServer));
    };
};
