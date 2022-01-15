class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;

    class FPA_scissors: ACE_ItemCore {
        displayName = "Tactical scissors";
        descriptionShort = "Cuts grass. Sometimes hair";
        picture = QPATHTOF(ui\scissors_ca.paa);
        scope = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };
};
