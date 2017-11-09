
class CfgVehicles {
    class B_Boat_Transport_01_F;
    class GVAR(PortableBoat) : B_Boat_Transport_01_F {
        scope = 2;
        displayName = "Portable Boat";
        class assembleInfo {
            primary = 1;
            base = "";
            assembleTo = "";
            displayName = "";
            dissasembleTo[] = {QGVAR(PortableBoatBackpack)};
        };
    };

    class Weapon_Bag_Base;
    class GVAR(PortableBoatBackpack) : Weapon_Bag_Base {
        scope = 2;
        scopeArsenal = 2;
        displayName = "Portable Boat Bag";
        picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_rgr_ca";
        model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
        hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_rgr_co.paa"};
        maximumLoad = 0;
        mass = 150;
        mapSize = 0.6;
        class assembleInfo {
            primary = 1;
            base = "";
            assembleTo = QGVAR(PortableBoat);
            displayName = "Portable Boat";
            dissasembleTo[] = {};
        };
    };
};
