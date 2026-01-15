class SteamManagerConfig {
    class GameRecording {
        class GVAR(uncon) {
            scope = 2; // Can be modded to 1 or 0 to disable the event. Must be 2 to be visible
            title = "Uncon Event";
            description = "%1 at %2"; // Format string, arguments are passed by eventArguments
            icon = "a3_revive"; // Icon is enum, there is hardcoded set of available icons
            priority = 40; // See ISteamTimeline documentation
        };
        class GVAR(missionEnd): GVAR(uncon) {
            title = "Mission End";
            description = "End of mission (%1)";
            icon = "a3_challenge_timer";
        };
        class GVAR(aceThrow): GVAR(uncon) {
            title = "Grenade Thrown";
            description = "%1 thrown";
            icon = "a3_grenade_throw";
            priority = 20;
        };
        class GVAR(vehicle): GVAR(uncon) {
            title = "Vehicle";
            description = "Got %1 %2";
            icon = "a3_vehicle_driver";
            priority = 20;
        };

        class GVAR(mission): GVAR(uncon) {
            title = "Mission";
            description = "%1";
            icon = "a3_steam_info";
        };

        class UnitKilled {
            scope = 0; // hide vanilla event
        };
        class GVAR(UnitKilled): UnitKilled {
            scope = 2;
        };
    };
};
