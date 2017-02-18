#define ACE_MEDICAL "ace_zeus_Medical"

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

    // Utilities modules
    class GVAR(moduleToggleGodmode): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Utilities);
        displayName = "Toggle zeus godmode";
        function = QFUNC(zeusGodmode);
        icon = "\a3\Missions_F_Beta\data\img\iconMPTypeDefense_ca.paa";
    };

    // Custom modules
    class GVAR(moduleCustom01): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom02): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom03): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom04): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom05): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom06): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom07): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom08): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom09): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
    class GVAR(moduleCustom10): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(Custom);
        displayName = "";
        function = QFUNC(customModule);
    };
};
