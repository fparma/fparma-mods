class ACE_Medical_Actions {
    class Advanced {
        class FieldDressing {
            treatmentTime = 6;
        };
    };
};

class ACE_Medical_Advanced {
    class Injuries;
    class Treatment {
        class Bandaging {
            class Bandage;
            class FieldDressing {
                effectiveness = 4;
                reopeningChance = 0;
                reopeningMinDelay = 120;
                reopeningMaxDelay = 200;

                class Abrasion {
                    effectiveness = 4;
                    reopeningChance = 0;
                    reopeningMinDelay = 200;
                    reopeningMaxDelay = 1000;
                };

                class AbrasionMinor: Abrasion{};
                class AbrasionMedium: Abrasion{};
                class AbrasionLarge: Abrasion{};
                class Avulsions: Abrasion{};
                class AvulsionsMinor: Avulsions{};
                class AvulsionsMedium: Avulsions{};
                class AvulsionsLarge: Avulsions{};
                class Contusion: Abrasion{};
                class ContusionMinor: Contusion{};
                class ContusionMedium: Contusion{};
                class ContusionLarge: Contusion{};
                class CrushWound: Abrasion{};
                class CrushWoundMinor: CrushWound{};
                class CrushWoundMedium: CrushWound{};
                class CrushWoundLarge: CrushWound{};
                class Cut: Abrasion{};
                class CutMinor: Cut{};
                class CutMedium: Cut{};
                class CutLarge: Cut{};
                class Laceration: Abrasion{};
                class LacerationMinor: Laceration{};
                class LacerationMedium: Laceration{};
                class LacerationLarge: Laceration{};
                class velocityWound: Abrasion{};
                class velocityWoundMinor: velocityWound{};
                class velocityWoundMedium: velocityWound{};
                class velocityWoundLarge: velocityWound{};
                class punctureWound: Abrasion{};
                class punctureWoundMinor: punctureWound{};
                class punctureWoundMedium: punctureWound{};
                class punctureWoundLarge: punctureWound{};
            };

            class PackingBandage: FieldDressing{};
            class ElasticBandage: FieldDressing{};
            class QuikClot: FieldDressing{};
        };
    };
};
