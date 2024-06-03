#include "defines.hpp"

class RscMapControl;
class RscPicture;
class RscText;
class RscTitle;
class RscActiveText;
class RscControlsGroupNoScrollbars;
class RscEdit;
class RscListNBox;
class RscButtonMenu;
class RscStructuredText;


class GVAR(RscDisplayMarkers) {
    access = 0;
    idd = IDD_SAVEMARKERS;
    movingEnable = 0;

    onUnload = QUOTE(_this call FUNC(onUnload));

    class controlsBackground {
        class map: RscMapControl {
            idc = IDC_MAP;

            x = "safezoneXAbs";
            y = "safezoneY";
            w = "safezoneWAbs";
            h = "safezoneH";
        };
    };

    class controls {

        class helpDialog: RscControlsGroupNoScrollbars {
            idc = IDC_HELP;

            x = QUOTE(safezoneX + safezoneW - 13 * X_FACTOR);
            y = QUOTE(safezoneY + 5 * Y_FACTOR);
            w = QUOTE(8 * X_FACTOR);
            h = QUOTE(22.2 * Y_FACTOR);

            deletable = 0;
            fade = 0;
            shadow = 0;
            style = 16;
            type = 15;
            moving = QUOTE(true);

            class controls {
                class mainBackground: RscText {
                    idc = -1;

                    x = 0;
                    y = 0;
                    w = QUOTE(8 * X_FACTOR);
                    h = QUOTE(22.2 * Y_FACTOR);

                    SizeEx = QUOTE(Y_FACTOR * 1);
                    colorBackground[] = {0,0,0,0.8};
                };

                class text: RscStructuredText {
                    idc = IDC_HELP_TEXT;

                    x = QUOTE(HELP_TEXT_PADDING_X);
                    y = QUOTE(HELP_TEXT_PADDING_Y);
                    w = QUOTE(8 * X_FACTOR - 2 * HELP_TEXT_PADDING_X);
                    h = QUOTE(22.2 * Y_FACTOR - 2 * HELP_TEXT_PADDING_Y);

                    sizeEx = QUOTE(0.8 * Y_FACTOR);

                    class Attributes;
                };
            };
        };

        class markersDialog: RscControlsGroupNoScrollbars {
            idc = -1;

            x = QUOTE(safezoneX + 5 * X_FACTOR);
            y = QUOTE(safezoneY + 5 * Y_FACTOR);
            w = QUOTE(20 * X_FACTOR);
            h = QUOTE(22.2 * Y_FACTOR);

            deletable = 0;
            fade = 0;
            shadow = 0;
            style = 16;
            type = 15;
            moving = QUOTE(true);

            class controls {
                class title: RscTitle {
                    idc = -1;

                    x = QUOTE(0 * X_FACTOR);
                    y = QUOTE(0 * Y_FACTOR);
                    w = QUOTE(20 * X_FACTOR);
                    h = QUOTE(1 * Y_FACTOR);

                    sizeEx = QUOTE(Y_FACTOR * 1);
                    text = "FPA SAVE-MARKERS";
                    colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
                };

                class mainBackground: RscText {
                    idc = -1;

                    x = QUOTE(0 * X_FACTOR);
                    y = QUOTE(1.1 * Y_FACTOR);
                    w = QUOTE(20 * X_FACTOR);
                    h = QUOTE(20 * Y_FACTOR);

                    SizeEx = QUOTE(Y_FACTOR * 1);
                    colorBackground[] = {0,0,0,0.8};
                };

                class editName: RscEdit {
                    idc = IDC_EDITNAME;

                    x = QUOTE(6 * X_FACTOR);
                    y = QUOTE(19.6 * Y_FACTOR);
                    w = QUOTE(13.5 * X_FACTOR);
                    h = QUOTE(1 * Y_FACTOR);

                    sizeEx = QUOTE(0.8 * Y_FACTOR);
                };

                class saveAsText: RscText {
                    idc = -1;

                    text = "Save as:";

                    x = QUOTE(0.5 * X_FACTOR);
                    y = QUOTE(19.6 * Y_FACTOR);
                    w = QUOTE(5.5 * X_FACTOR);
                    h = QUOTE(1 * Y_FACTOR);

                    sizeEx = QUOTE(0.8 * Y_FACTOR);
                    style = 1;
                };

                class savesList: RscListNBox {
                    idc = IDC_SAVESLIST;

                    x = QUOTE(0.5 * X_FACTOR);
                    y = QUOTE(1.6 * Y_FACTOR);
                    w = QUOTE(19 * X_FACTOR);
                    h = QUOTE(17.5 * Y_FACTOR);

                    sizeEx = QUOTE(0.8 * Y_FACTOR);
                    columns[] = {0,0.7};

                    class ListScrollBar;
                    class ScrollBar;
                };

                class buttonCancel: RscButtonMenu {
                    idc = -1;
                    text = "Cancel";

                    action = QUOTE((findDisplay IDD_SAVEMARKERS) closeDisplay 2);

                    x = QUOTE(0 * X_FACTOR);
                    y = QUOTE(21.2 * Y_FACTOR);
                    w = QUOTE(4.925 * X_FACTOR);
                    h = QUOTE(1 * Y_FACTOR);
                };

                class buttonDelete: RscButtonMenu {
                    idc = IDC_BUTTONDELETE;

                    text = "Delete";

                    x = QUOTE(5.025 * X_FACTOR);
                    y = QUOTE(21.2 * Y_FACTOR);
                    w = QUOTE(4.925 * X_FACTOR);
                    h = QUOTE(1 * Y_FACTOR);
                };

                class buttonSave: RscButtonMenu {
                    idc = IDC_BUTTONSAVE;

                    text = "Save";

                    x = QUOTE(10.050 * X_FACTOR);
                    y = QUOTE(21.2 * Y_FACTOR);
                    w = QUOTE(4.925 * X_FACTOR);
                    h = QUOTE(1 * Y_FACTOR);
                };

                class buttonLoad: RscButtonMenu {
                    idc = IDC_BUTTONLOAD;

                    text = "Load";

                    x = QUOTE(15.075 * X_FACTOR);
                    y = QUOTE(21.2 * Y_FACTOR);
                    w = QUOTE(4.925 * X_FACTOR);
                    h = QUOTE(1 * Y_FACTOR);
                };
            };
        };
    };
};
