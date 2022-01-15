class ace_medical_treatment {
    class Medication {
        class Morphine {
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
        };
        class Vital: Morphine {
            painReduce = 0;
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
            timeInSystem = 1;
            timeTillMaxEffect = 0;
            // maxDose = 4;
            incompatibleMedication[] = {};
            viscosityChange = 0;
        };
    };
};
