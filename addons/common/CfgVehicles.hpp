class CfgVehicles {
    class Man;

    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class GVAR(cutGrass) {
                    displayName = "Cut grass";
                    exceptions[] = {"isNotSurrendering", "notOnMap", "isNotInside", "isNotInZeus", "isNotSitting"};
                    condition = QUOTE(_player call FUNC(canCutGrass));
                    statement = QUOTE(call FUNC(cutGrass));
                    icon = QPATHTOEF(assets,ui\scissors_ca.paa);
                };
            };
        };
    };
};
