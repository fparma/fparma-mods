class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

class Extended_Killed_EventHandlers {
    class CAManBase {
        class ADDON {
            clientKilled = QUOTE(call FUNC(handleKilled));
        };
    };
};

class Extended_Respawn_EventHandlers {
    class CAManBase {
        class ADDON {
            clientRespawn = QUOTE(call FUNC(handleRespawn));
        };
    };
};
