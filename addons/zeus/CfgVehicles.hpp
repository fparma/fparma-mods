class CfgVehicles {
    class Module_F;

    class GVAR(moduleBase): Module_F {
        author = "FPARMA";
        category = "FP";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        scope = 1;
        scopeCurator = 2;
    };

    // AI Modules
    class GVAR(moduleSupressionUnit): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(AI);
        displayName = "SUPRESSION - select unit";
        function = QFUNC(selectSuppressionUnit);
    };

    class GVAR(moduleSupressionTarget): GVAR(moduleBase) {
        category = QGVAR(AI);
        displayName = "SUPRESSION - target area";
        function = QFUNC(selectSupressionTarget);
        portrait = "\a3\Modules_F_Curator\Data\portraitTracers_ca.paa";
        icon = "\a3\Modules_F_Curator\Data\iconTracers_ca.paa";
    };

    // Utilities modules
    class GVAR(moduleHealUnit): GVAR(moduleBase) {
        category = GVAR(Utilities);
        displayName = "Heal - unit";
        function = QFUNC(fullHeal);
        icon = QPATHTOF(data/icon_medkit.paa);
    };

    class GVAR(moduleHealGroup): GVAR(moduleBase) {
        category = GVAR(Utilities);
        displayName = "Heal - group";
        function = QFUNC(fullHeal);
        icon = QPATHTOF(data/icon_medkit.paa);
    };

    class GVAR(moduleToggleZeusInvisible): GVAR(moduleBase) {
        category = GVAR(Utilities);
        displayName = "Toggle zeus godmode";
        function = QFUNC(zeusGodmode);
    };

    class GVAR(moduleArsenalUnit): GVAR(moduleBase) {
        category = GVAR(Utilities);
        displayName = "Arsenal on unit";
        function = QFUNC(unitArsenal);
    };
};
