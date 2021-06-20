class CfgAmmo {
    class RocketBase;
    class R_PG7_F : RocketBase {
        aiAmmoUsageFlags = "64 + 128 + 256 + 512";
        airLock = 1;
        allowAgainstInfantry = 1;
        cost = 0.1;
        effectsMissile = "missile3";
        whistleDist = 30;
    };
    class M_SPG9_HEAT : RocketBase {
        aiAmmoUsageFlags = "64 + 128 + 512";
        allowAgainstInfantry = 1;
    };
    class R_PG32V_F : RocketBase {
        aiAmmoUsageFlags = "64 + 128 + 256 + 512";
        airLock = 1;
        allowAgainstInfantry = 1;
        cost = 40;
    };
    class R_MRAAWS_HEAT_F : RocketBase {
        aiAmmoUsageFlags = "64 + 128 + 512";
        allowAgainstInfantry = 1;
        cost = 40;
    };
};
