#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"fpa_main"};
        author[] = {"Cuel"};
        VERSION_CONFIG;
    };
};

class Extended_PostInit_EventHandlers {
  class ADDON {
    clientInit = QUOTE(call COMPILE_FILE(XEH_postInit));
  };
};
