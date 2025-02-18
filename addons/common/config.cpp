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
            x = "safeZoneX";
            y = "safeZoneY + safeZoneH - 14 * pixelH";
            w = "80 * pixelW";
            h = "12 * pixelH";
            sizeEx = "12 * pixelH";
            text = "ACRE Spectator";
            action = QUOTE(_this call FUNC(toggleZeusAcre));
        };
        class GVAR(unitCount): RscText {
            idc = 777551;
            x = "safeZoneX + 80 * pixelW";
            y = "safeZoneY + safeZoneH - 14 * pixelH";
            w = "200 * pixelW";
            h = "14 * pixelH";
            sizeEx = "14 * pixelH";
            text = "Sample";
        };
    };
};

class RscDisplayChat {
    onLoad = QUOTE([ARR_2('GVAR(chatOpened)',_this)] call CBA_fnc_localEvent;);
    onUnload = QUOTE([ARR_2('GVAR(chatClosed)',_this)] call CBA_fnc_localEvent;);
};
