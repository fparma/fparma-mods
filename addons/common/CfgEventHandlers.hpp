class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_DisplayLoad_EventHandlers {
  class RscDisplayArsenal {
    ADDON = QUOTE(_this call FUNC(overrideArsenalExport));
  };

  class RscDisplayCurator {
    ADDON = QUOTE(_this call FUNC(onZeusInterface));
  }
};

