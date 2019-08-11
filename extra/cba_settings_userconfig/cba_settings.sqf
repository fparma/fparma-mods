// ACRE
force force acre_sys_core_ts3ChannelSwitch = true;
force force acre_sys_core_interference = false;
force force acre_sys_core_fullDuplex = true;
force force acre_sys_core_ignoreAntennaDirection = true;
force acre_sys_core_revealToAI = true;
acre_sys_core_terrainLoss = 0.2;

// ACE Misc
ace_common_persistentLaserEnabled = false;
force ace_hitreactions_minDamageToTrigger = 0.1;
force ace_laser_dispersionCount = 2;
force ace_laserpointer_enabled = true;
force ace_overpressure_distanceCoefficient = 1;
force ace_switchunits_enableSwitchUnits = false;
force ace_vehiclelock_vehicleStartingLockState = -1;
force ace_scopes_enabled = true;
force ace_noradio_enabled = true;
force force ace_advanced_fatigue_enabled = false;
force force ace_microdagr_mapDataAvailable = 2;
force force ace_gforces_enabledFor = 1;
force force ace_cargo_enable = true;
force ace_cargo_paradropTimeCoefficent = 2;

// ACE Common
force force ace_common_checkPBOsAction = 0;
force force ace_common_checkPBOsCheckAll = false;
force force ace_common_checkPBOsWhitelist = "[]";

// ACE Cookoff
force force ace_cookoff_enable = false;
force ace_cookoff_enableAmmobox = true;
force ace_cookoff_enableAmmoCookoff = true;
force force ace_cookoff_ammoCookoffDuration = 0.2;
force force ace_cookoff_probabilityCoef = 0.75;

// ACE Finger
force ace_finger_enabled = true;
force ace_finger_maxRange = 7;

// ACE Frag
force ace_frag_enabled = true;
force ace_frag_spallEnabled = false;
force ace_frag_reflectionsEnabled = false;
force ace_frag_maxTrack = 8;
force ace_frag_maxTrackPerFrame = 8;

// ACE Interaction
ace_interaction_enableTeamManagement = true;
force force ace_interaction_disableNegativeRating = true;

// ACE Mag repack
force force ace_magazinerepack_timePerAmmo = 1;
force force ace_magazinerepack_timePerMagazine = 1.5;
force force ace_magazinerepack_timePerBeltLink = 4;

// ACE Map
ace_map_BFT_Enabled = true;
ace_map_BFT_Interval = 15;
force force ace_map_BFT_HideAiGroups = true;
force ace_map_BFT_ShowPlayerNames = false;
force force ace_map_mapIllumination = true;
force force ace_map_mapGlow = true;
force force ace_map_mapShake = true;
force force ace_map_mapLimitZoom = false;
force force ace_map_mapShowCursorCoordinates = true;
force force ace_map_defaultChannel = 1;
force ace_map_gestures_enabled = true;
force force ace_map_gestures_maxRange = 8;
force force ace_map_gestures_interval = 0.05;

// ACE Markers
force ace_markers_movableMarkersEnabled = true;
force force ace_markers_moveRestriction = 3;

//ACE Medical
force ace_medical_level = 1; //Medical Level (1 = basic, 2 = advanced)
force ace_medical_preventInstaDeath = true; //Prevent Instant Death

force force ace_medical_blood_enabledFor = 2; //Enable Blood Drops (Enabled)
force force ace_medical_medicSetting = 1; //Medic Setting (Normal)
force force ace_medical_increaseTrainingInLocations = true; //Location Boost Training (Yes)
force force ace_medical_enableFor = 0; //Enabled for (Player only)
force force ace_medical_enableOverdosing = false; //Overdosing (No)
force force ace_medical_enableAdvancedWounds = false; //Advanced Wounds (No)
force force ace_medical_enableScreams = true; //Enable Screams (Yes)
force force ace_medical_enableVehicleCrashes = true; //Vehicle Crashes (Yes)
force force ace_medical_remoteControlledAI = true; //Treat Remote Controlled AI as AI (Yes)
force force ace_medical_allowLitterCreation = true; //Enable Litter (Yes)
force force ace_medical_litterCleanUpDelay = 300; //Litter Lifetime (300 seconds)
force force ace_medical_litterSimulationDetail = 2; //Litter Simulation Level (Medium)
force force ace_medical_medicSetting_basicEpi = 0; //Allow Epinephrine (Everyone)
force force ace_medical_medicSetting_PAK = 0; //Allow PAK (Everyone)
force force ace_medical_useLocation_basicEpi = 0; //Allow Epi-pen (Everyone)
force force ace_medical_useLocation_PAK = 0; //Allow PAK Location (Everywhere)
force force ace_medical_useLocation_SurgicalKit = 4; //Allow Surgical Kit Location (Disabled)
force force ace_medical_healHitPointAfterAdvBandage = true; //Bandages Heal Crippling (Yes)
force force ace_medical_keepLocalSettingsSynced = true; //Keep Unit Synced (Yes)
force force ace_medical_painIsOnlySuppressed = false; //Only Suppress Pain (No)
force force ace_medical_allowUnconsciousAnimationOnTreatment = true; //Unconscious Animation On Treatment (Yes)
force force ace_medical_moveUnitsFromGroupOnUnconscious = false; //Move Unconscious Units From Group (No)
force force ace_medical_ai_enabledFor = 2; //Medical AI Enabled (Yes)
force force ace_medical_delayUnconCaptive = 2; //Delay AI Cease Fire (2 seconds)
force force ace_medical_menu_allow = 1; //Allow Medical Menu (Yes)
force force ace_medical_menu_useMenu = 1; //Use Medical Menu (Yes)
force force ace_medical_menu_maxRange = 5; //Medical Menu Max Range (5 meters)

force ace_medical_bleedingCoefficient = 1; //Bleeding Coefficient (1)
force ace_medical_painCoefficient = 1; //Pain Coefficient (1)
force ace_medical_AIDamageThreshold = 1; //AI Damage Threshold (1)
force ace_medical_playerDamageThreshold = 2; //Player Damage Threshold
force ace_medical_enableUnconsciousnessAI = 0; //AI Unconsciousness (Disabled)

force ace_medical_amountOfReviveLives = -1; //Revive Lives (None)
force ace_medical_enableRevive = 0; //Enable Revive (Disabled)
force ace_medical_maxReviveTime = 600; //Max Revive Time (600 seconds)
force ace_medical_consumeItem_PAK = 0; //Consume PAK (No)
force ace_medical_useCondition_PAK = 0; //Condition PAK (Anytime)

ace_medical_consumeItem_SurgicalKit = 0; //Consume Surgical Kit (No)
ace_medical_medicSetting_SurgicalKit = 1; //Allow Surgical Kit (Medics Only)
ace_medical_useCondition_SurgicalKit = 0; //Condition Surgical Kit (Anytime)

// ACE MK6 Mortar
ace_mk6mortar_airResistanceEnabled = false;
ace_mk6mortar_allowComputerRangefinder = true;
ace_mk6mortar_allowCompass = true;
ace_mk6mortar_useAmmoHandling = true;

// ACE Nametags
ace_nametags_showNamesForAI = false;
ace_nametags_showPlayerRanks = false;
ace_nametags_playerNamesViewDistance = 12;

// ACE NVG
force ace_nightvision_disableNVGsWithSights = false;
force ace_nightvision_fogScaling = 0.2;
force ace_nightvision_effectScaling = 0.3;
force ace_nightvision_noiseScaling = 0.3;
force ace_nightvision_aimDownSightsBlur = 0.5;

// ACE Overheating
force ace_overheating_overheatingDispersion = true;
force ace_overheating_unJamOnreload = true;
force ace_overheating_unJamFailChance = 0;
force ace_overheating_enabled = true;

// ACE Pylons
force ace_pylons_enabled = true;
ace_pylons_searchDistance = 15;
ace_pylons_timePerPylon = 5;
force ace_pylons_rearmNewPylons = true;
force ace_pylons_requireEngineer = false;
force ace_pylons_requireToolkit = false;

// ACE Rearm
ace_rearm_level = 1;
force ace_rearm_supply = 0;

// ACE Refuel
ace_refuel_rate = 2;
force force ace_refuel_hoseLength = 20;

// ACE Respawn
force ace_respawn_savePreDeathGear = false;
force force ace_respawn_removeDeadBodiesDisconnected = true;

// ACE Repair
ace_repair_engineerSetting_repair = 0;
ace_repair_engineerSetting_wheel = 0;
ace_repair_repairDamageThreshold = 0.75;
ace_repair_repairDamageThreshold_engineer = 0.4;
ace_repair_consumeItem_toolKit = 0;
ace_repair_fullRepairLocation = 3;
ace_repair_engineerSetting_fullRepair = 1;
ace_repair_addSpareParts = true;
ace_repair_wheelRepairRequiredItems = 0;
force force ace_repair_autoShutOffEngineWhenStartingRepair = true;

// ACE Spect
ace_spectator_enableAI = false;
ace_spectator_restrictModes = 0;
ace_spectator_restrictVisions = 0;

// ACE VD
force ace_viewdistance_enabled = false;
ace_viewdistance_viewDistanceOnFoot = 0;
ace_viewdistance_viewDistanceLandVehicle = 0;
ace_viewdistance_viewDistanceAirVehicle = 0;
ace_viewdistance_limitViewDistance = 0;
ace_viewdistance_objectViewDistanceCoeff = 0;

// ACE Weather
ace_weather_enabled = true;
force ace_weather_updateInterval = 60;
force ace_weather_windSimulation = false;

// ACE Wind deflection
ace_winddeflection_enabled = true;
force ace_winddeflection_vehicleEnabled = true;
force ace_winddeflection_simulationInterval = 0.05;

// ACE Adv Throwing
ace_advanced_throwing_enabled = true;
force ace_advanced_throwing_enablePickUp = true;
force ace_advanced_throwing_enablePickUpAttached = true;

// ACE Captives
force ace_captives_allowHandcuffOwnSide = true;
force ace_captives_requireSurrender = 2;
force ace_captives_allowSurrender = true;
force ace_captives_requireSurrenderAi = false;

// ACE Expl
ace_explosives_requireSpecialist = false;
force ace_explosives_punishNonSpecialists = true;
force ace_explosives_explodeOnDefuse = true;

// ACE Zeus
force force ace_zeus_zeusAscension = false;
force force ace_zeus_zeusBird = false;
force force ace_zeus_remoteWind = false;
force force ace_zeus_radioOrdnance = false;
force force ace_zeus_revealMines = 0;
force force ace_zeus_autoAddObjects = true;

// ACE Adv ballistic
ace_advanced_ballistics_enabled = true;
force ace_advanced_ballistics_muzzleVelocityVariationEnabled = true;
force ace_advanced_ballistics_ammoTemperatureEnabled = true;
force ace_advanced_ballistics_barrelLengthInfluenceEnabled = true;
force ace_advanced_ballistics_bulletTraceEnabled = true;
force ace_advanced_ballistics_simulationInterval = 0.05;

// ACE Arsenal
ace_arsenal_enableModIcons = true;
force ace_arsenal_allowDefaultLoadouts = true;
force ace_arsenal_allowSharedLoadouts = true;
ace_arsenal_EnableRPTLog = false;

//ACEX
force force acex_sitting_enable = true;
force force acex_viewrestriction_mode = 0;
force acex_viewrestriction_modeSelectiveFoot = 0;
force acex_viewrestriction_modeSelectiveLand = 0;
force acex_viewrestriction_modeSelectiveAir = 0;
force acex_viewrestriction_modeSelectiveSea = 0;

// ACEX HC
force force acex_headless_enabled = true;
force force acex_headless_delay = 60;
force force acex_headless_endMission = 2;
force acex_headless_log = false;
