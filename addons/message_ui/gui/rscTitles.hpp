class RscStructuredText;

class RscTitles {
    class GVAR(rscCustomChat) {
        duration = 20;
        enableSimulation = 1;
        fadeIn = 0.2;
        fadeOut = 0.2;
        idd = -1;
        movingEnable = 0;
        onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(rscCustomChat),_this select 0)]);
        onUnload = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(rscCustomChat),nil)]);

        class controls {
            class chatBox: RscStructuredText {
                idc = FPA_MESSAGEUI_IDC_CUSTOMCHATTEXT;

                colorBackground[] = {0,0,0,0.3};
                font = "RobotoCondensed";
                shadow = 1;
                shadowColor[] = {0,0,0,0.5};
                size = "(((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25) * 0.8)";

                x = "(safeZoneX + 1 * (((safeZoneW / safeZoneH) min 1.2) / 40))";
                y = "(safeZoneY + safeZoneH - 10.5 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25))";
                w = "(20 *(((safeZoneW / safeZoneH) min 1.2) / 40))";
                h = "(((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25) * 0.8)";
            };
        };
    };
};
