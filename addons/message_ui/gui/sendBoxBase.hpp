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
        "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
    };

    x = FPA_MESSAGEUI_TITLE_X;
    y = FPA_MESSAGEUI_TITLE_Y;
    w = FPA_MESSAGEUI_TOTAL_W;
    h = FPA_MESSAGEUI_ELEMENT_H;
};

class fpa_messageui_sendBoxBGBase: RscText {
    idc = -1;

    colorBackground[] = {0, 0, 0, 0.700000};

    x = FPA_MESSAGEUI_TITLE_X;
    y = FPA_MESSAGEUI_EDITBOX_BG_Y;
    w = FPA_MESSAGEUI_TOTAL_W;
    h = FPA_MESSAGEUI_EDITBOX_BG_H;
};

class fpa_messageui_sendBoxBase: RscEdit {
    idc = -1;
    style = 16;

    autocomplete = "";
    shadow = 0;
    font = "EtelkaMonospacePro";
    sizeEx = "0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";

    onLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxCtrl"",(_this select 0)]";
    onUnLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxCtrl"",nil]";

    onKeyDown = "if ((_this select 1) isEqualTo 28 && !(_this select 2) && !(_this select 3) && !(_this select 4)) then {call fpa_message_ui_fnc_sendMessage;};";

    x = FPA_MESSAGEUI_EDITBOX_X;
    y = FPA_MESSAGEUI_EDITBOX_Y;
    w = FPA_MESSAGEUI_EDITBOX_W;
    h = FPA_MESSAGEUI_EDITBOX_H;
};

class fpa_messageui_sendBoxButtonBase: RscButtonMenu {
    idc = FPA_MESSAGEUI_IDC_SENDBUTTON;

    onLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxButtonCtrl"",(_this select 0)]; _this call fpa_message_ui_fnc_setSendButtonPosition";
    onUnLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxButtonCtrl"",nil]";

    text = "Send";
    action = "call fpa_message_ui_fnc_sendMessage";

    x = FPA_MESSAGEUI_TITLE_X;
    y = FPA_MESSAGEUI_SENDBUTTON_Y_2;
    w = FPA_MESSAGEUI_TOTAL_W;
    h = FPA_MESSAGEUI_ELEMENT_H;
};

class fpa_messageui_sendBoxListboxBase: RscCombo {
    idc = -1;

    font = "EtelkaMonospacePro";
    rowHeight = 10;
    /*sizeEx = "0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";*/

    onLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxListboxCtrl"",(_this select 0)]; _this call fpa_message_ui_fnc_initListbox";
    onUnLoad = "uiNamespace setVariable [""fpa_message_ui_sendBoxListboxCtrl"",nil]";

    x = FPA_MESSAGEUI_TITLE_X;
    y = FPA_MESSAGEUI_SENDBUTTON_Y;
    w = FPA_MESSAGEUI_TOTAL_W;
    h = FPA_MESSAGEUI_ELEMENT_H;
};
