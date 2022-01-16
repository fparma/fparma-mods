class ace_medical_treatment_actions {
    // - Syringes -------------------------------------------------------------
    class Morphine;
    class Vital: Morphine {
        displayName = "Inject Vital";
        displayNameProgress = "Injecting Vital...";
        allowSelfTreatment = 0;
        items[] = {QGVAR(vital)};
        condition = QFUNC(canInjectVital);
        litter[] = {{"ACE_MedicalLitter_adenosine"}};
    };
};
