class zen_context_menu_actions {
    class HealUnits {
        class GVAR(areaHeal) {
            displayName = "Area heal";
            condition = "true";
            statement = "";
            icon = "\A3\3den\data\displays\display3den\toolbar\widget_area_off_ca.paa";
            class GVAR(areaHeal_10){
                displayName = "10 m";
                condition = "true";
                statement = QUOTE([ARR_2(_position,10)] call FUNC(areaHeal));
                icon = "";
            };
            class GVAR(areaHeal_50): GVAR(areaHeal_10) {
                displayName = "50 m";
                statement = QUOTE([ARR_2(_position,50)] call FUNC(areaHeal));
            };
            class GVAR(areaHeal_100): GVAR(areaHeal_10) {
                displayName = "100 m";
                statement = QUOTE([ARR_2(_position,100)] call FUNC(areaHeal));
            };
        };
    };
};
