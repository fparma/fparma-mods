class CfgAILevelPresets {
  class AILevelLow {
    displayName = "FPA";
    precisionAI = 0.13;
    skillAI = 0.95;
  };
};

class CfgDifficultyPresets {
  defaultPreset = "Custom";
  class Custom {
    description = "BI sucks";
    levelAI = "AILevelLow";
    class Options {
      autoReport = 0;
      cameraShake = 1;
      commands = 0;
      deathMessages = 0;
      detectedMines = 0;
      enemyTags = 0;
      friendlyTags = 0;
      groupIndicators = 0;
      mapContent = 0;
      multipleSaves = 0;
      reducedDamage = 0;
      scoreTable = 0;
      staminaBar = 1;
      stanceIndicator = 1;
      thirdPersonView = 0;
      visionAid = 0;
      vonID = 0;
      squadRadar = 0;
      waypoints = 2;
      weaponCrosshair = 0;
      weaponInfo = 1;
      roughLanding = 1;
    };
  };
};
