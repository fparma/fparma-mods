#define ACE_MEDICAL "ace_zeus_Medical"

class CfgVehicles {
    class Module_F;

    // Baseclass
    class GVAR(moduleBase): Module_F {
        author = "FPARMA";
        category = "FP";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        scope = 1;
        scopeCurator = 2;
    };

    // ACE Medical modules
    class GVAR(moduleHealUnit): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = ACE_MEDICAL;
        displayName = "Full heal - unit";
        function = QFUNC(fullHeal);
        icon = QPATHTOF(data\icon_medkit.paa);
    };

    class GVAR(moduleHealGroup): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = ACE_MEDICAL;
        displayName = "Full heal - group";
        function = QFUNC(fullHeal);
        icon = QPATHTOF(data\icon_medkit.paa);
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

    class GVAR(moduleForceWP): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(AI);
        displayName = "Group - force move WP";
        function = QFUNC(forceMoveWP);
        icon = QPATHTOF(data\icon_run.paa);
    };

    // Utilities modules
    class GVAR(moduleToggleGodmode): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Utilities);
        displayName = "Toggle zeus godmode";
        function = QFUNC(zeusGodmode);
        icon = "\a3\Missions_F_Beta\data\img\iconMPTypeDefense_ca.paa";
    };

    class GVAR(moduleSmoke): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Utilities);
        displayName = "Spawn smokestack";
        function = QFUNC(smokestack);
        icon = "\a3\Modules_F_Curator\Data\iconSmoke_ca.paa";
    };

    class GVAR(moduleSwapNV): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Utilities);
        displayName = "Group - remove nvg / add flashlight";
        function = QFUNC(swapNV);
        icon = QPATHTOF(data\icon_flashlight.paa);
    };

    class GVAR(moduleDisableWeapons): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Utilities);
        displayName = "Players - toggle disable weapons";
        function = QFUNC(disableWeapons);
        icon = QPATHTOF(data\icon_holdfire.paa);
    };

    class GVAR(moduleUnitCode): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Utilities);
        displayName = "Execute code on unit";
        function = QFUNC(unitCode);
        icon = QPATHTOF(data\icon_keyboard.paa);
    };

    class GVAR(moduleCode): GVAR(moduleBase) {
        category = QGVAR(Utilities);
        displayName = "Execute code";
        function = QFUNC(code);
        icon = QPATHTOF(data\icon_keyboard.paa);
    };

    // Custom modules
    class GVAR(moduleCustom): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
};