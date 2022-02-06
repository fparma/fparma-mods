#include "script_component.hpp"

class CfgPatches {
  class ADDON {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    requiredAddons[] = {"fpa_main"};
    author[] = {"Cuel"};
    authorUrl = "";
  };
};

#include "CfgEventHandlers.hpp"
#include "CfgDebriefing.hpp"
#include "CfgVehicles.hpp"
#include "CfgVideoOptions.hpp"
#include "adminWhitelist.hpp"
#include "CfgEden.hpp"

class RscButton;
class RscText;

class RscDisplayCurator {
    class Controls {
        class GVAR(acreSpectateButton): RscButton {
            idc = 777550;
            x = "safezoneX";
            y = "safezoneY + safeZoneH - 14 * pixelH";
            w = "80 * pixelW";
            h = "12 * pixelH";
            sizeEx = "12 * pixelH";
            text = "ACRE Spectator";
            action = QUOTE(_this call FUNC(toggleZeusAcre));
        };
        class GVAR(unitCount): RscText {
            idc = 777551;
            x = "safezoneX + 80 * pixelW";
            y = "safezoneY + safeZoneH - 14 * pixelH";
            w = "200 * pixelW";
            h = "14 * pixelH";
            sizeEx = "14 * pixelH";
            text = "Sample";
        };
    };
};
