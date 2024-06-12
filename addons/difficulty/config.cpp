#include "script_component.hpp"

class CfgPatches {
  class ADDON {
    units[] = {};
    weapons[] = {};
    requiredVersion = REQUIRED_VERSION;
    requiredAddons[] = {"fpa_main"};
    author[] = {"Cuel"};
    authorUrl = "";
  };
};

#include "CfgEventHandlers.hpp"
#include "CfgDifficulty.hpp"
#include "CfgAISkill.hpp"
#include "CfgSurfaces.hpp"