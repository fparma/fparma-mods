class RscText;
class RscTitle;
class RscEdit;
class RscButtonMenu;
class RscCombo;

class fpa_messageui_sendBoxTitleBase: RscTitle {
    idc = -1;
    style = 0;

    text = "Message some schmuck";
    colorBackground[] = {
        "(profilenamespace getVariable ['GUI_BCG_RGB_R',0.13])",
        "(profilenamespace getVariable ['GUI_BCG_RGB_G',0.54])",
        "(profilenamespace getVariable ['GUI_BCG_RGB_B',0.21])",
        "(profilenamespace getVariable ['GUI_BCG_RGB_A',0.8])"
    };

    x = QUOTE(FPA_MESSAGEUI_TITLE_X);
    y = QUOTE(FPA_MESSAGEUI_TITLE_Y);
    w = QUOTE(FPA_MESSAGEUI_TOTAL_W);
    h = QUOTE(FPA_MESSAGEUI_ELEMENT_H);
};

class fpa_messageui_sendBoxBGBase: RscText {
    idc = -1;

    colorBackground[] = {0, 0, 0, 0.700000};

    x = QUOTE(FPA_MESSAGEUI_TITLE_X);
    y = QUOTE(FPA_MESSAGEUI_EDITBOX_BG_Y);
    w = QUOTE(FPA_MESSAGEUI_TOTAL_W);
    h = QUOTE(FPA_MESSAGEUI_EDITBOX_BG_H);
};

class fpa_messageui_sendBoxBase: RscEdit {
    idc = -1;
    style = 16;

    autocomplete = "";
    shadow = 0;
    font = "EtelkaMonospacePro";
    sizeEx = "0.7 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";

    onLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxCtrl"",(_this select 0)]";
    onUnLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxCtrl"",nil]";

    onKeyDown = "if ((_this select 1) isEqualTo 28 && !(_this select 2) && !(_this select 3) && !(_this select 4)) then {call fpa_message_ui_fnc_sendMessage;};";

    x = QUOTE(FPA_MESSAGEUI_EDITBOX_X);
    y = QUOTE(FPA_MESSAGEUI_EDITBOX_Y);
    w = QUOTE(FPA_MESSAGEUI_EDITBOX_W);
    h = QUOTE(FPA_MESSAGEUI_EDITBOX_H);
};

class fpa_messageui_sendBoxButtonBase: RscButtonMenu {
    idc = FPA_MESSAGEUI_IDC_SENDBUTTON;

    onLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxButtonCtrl"",(_this select 0)]; _this call fpa_message_ui_fnc_setSendButtonPosition";
    onUnLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxButtonCtrl"",nil]";

    text = "Send";
    action = "call fpa_message_ui_fnc_sendMessage";

    x = QUOTE(FPA_MESSAGEUI_TITLE_X);
    y = QUOTE(FPA_MESSAGEUI_SENDBUTTON_Y_2);
    w = QUOTE(FPA_MESSAGEUI_TOTAL_W);
    h = QUOTE(FPA_MESSAGEUI_ELEMENT_H);
};

class fpa_messageui_sendBoxListboxBase: RscCombo {
    idc = -1;

    font = "EtelkaMonospacePro";
    rowHeight = 10;
    /*sizeEx = "0.7 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";*/

    onLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxListboxCtrl"",(_this select 0)]; _this call fpa_message_ui_fnc_initListbox";
    onUnLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxListboxCtrl"",nil]";

    x = QUOTE(FPA_MESSAGEUI_TITLE_X);
    y = QUOTE(FPA_MESSAGEUI_SENDBUTTON_Y);
    w = QUOTE(FPA_MESSAGEUI_TOTAL_W);
    h = QUOTE(FPA_MESSAGEUI_ELEMENT_H);
};
