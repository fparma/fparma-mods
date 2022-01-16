class CfgVehicles {
    class ACE_adenosineItem;
    class GVAR(vitalItem): ACE_adenosineItem {
        displayName = "Vital";
        author = "diwako";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(GVAR(vital),1);
        };
    };
};
