// Misc
force force STUI_Occlusion = false;

// ACRE
acre_sys_core_unmuteClients = true;
force force acre_sys_core_ts3ChannelSwitch = true;
force force acre_sys_core_interference = false;
force force acre_sys_core_fullDuplex = true;
force force acre_sys_core_ignoreAntennaDirection = true;
force force acre_sys_core_terrainLoss = 0;
force acre_sys_core_revealToAI = true;

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

// ACE Common
force force ace_common_checkPBOsAction = 0;
force force ace_common_checkPBOsCheckAll = false;
force force ace_common_checkPBOsWhitelist = "[]";

// ACE Cookoff
force ace_cookoff_enable = true;
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
force ace_interaction_enableTeamManagement = true;
force force ace_interaction_disableNegativeRating = true;
ace_interaction_enableMagazinePassing = true;

// ACE Mag repack
force force ace_magazinerepack_timePerAmmo = 1;
force force ace_magazinerepack_timePerMagazine = 1.5;
force force ace_magazinerepack_timePerBeltLink = 4;

// ACE Map
force ace_map_BFT_Enabled = true;
force ace_map_BFT_Interval = 15;
force force ace_map_BFT_HideAiGroups = true;
force ace_map_BFT_ShowPlayerNames = false;
force force ace_map_mapIllumination = true;
force force ace_map_mapGlow = true;
force force ace_map_mapShake = true;
force force ace_map_mapLimitZoom = false;
force force ace_map_mapShowCursorCoordinates = true;
force force ace_map_defaultChannel = 1;
force ace_map_gestures_enabled = true;
force force ace_map_gestures_maxRange = 10;
force force ace_map_gestures_interval = 0.05;

// ACE Markers
force ace_markers_movableMarkersEnabled = true;
force force ace_markers_moveRestriction = 3;

// ACE Medical
force force ace_medical_blood_enabledFor = 2;
force force ace_medical_level = 1;
force force ace_medical_medicSetting = 1;
force force ace_medical_increaseTrainingInLocations = true;
force ace_medical_enableFor = 0;
force force ace_medical_enableOverdosing = false;
force ace_medical_bleedingCoefficient = 1;
force ace_medical_painCoefficient = 1;
force force ace_medical_enableAdvancedWounds = false;
force force ace_medical_enableVehicleCrashes = true;
force force ace_medical_enableScreams = true;
force ace_medical_playerDamageThreshold = 2;
force ace_medical_AIDamageThreshold = 1;
force ace_medical_enableUnconsciousnessAI = 0;
force force ace_medical_remoteControlledAI = false;
force ace_medical_preventInstaDeath = false;
force ace_medical_enableRevive = 0;
force ace_medical_maxReviveTime = 600;
force ace_medical_amountOfReviveLives = -1;
force ace_medical_allowDeadBodyMovement = true;
force force ace_medical_allowLitterCreation = true;
force force ace_medical_litterSimulationDetail = 2;
force force ace_medical_litterCleanUpDelay = 300;
force force ace_medical_medicSetting_basicEpi = 0;
force force ace_medical_keepLocalSettingsSynced = true;
force force ace_medical_healHitPointAfterAdvBandage = true;
force force ace_medical_painIsOnlySuppressed = false;
force force ace_medical_allowUnconsciousAnimationOnTreatment = true;
force force ace_medical_moveUnitsFromGroupOnUnconscious = false;
force force ace_medical_delayUnconCaptive = 3;
force force ace_medical_ai_enabledFor = 2;
force force ace_medical_menu_allow = 1;
ace_medical_menu_useMenu = 1;
ace_medical_menu_openAfterTreatment = true;
force force ace_medical_menu_maxRange = 5;

// ACE MK6 Mortar
force ace_mk6mortar_airResistanceEnabled = false;
force ace_mk6mortar_allowComputerRangefinder = true;
force ace_mk6mortar_allowCompass = true;
force ace_mk6mortar_useAmmoHandling = true;

// ACE Nametags
ace_nametags_showPlayerNames = 1;
ace_nametags_showNamesForAI = false;
ace_nametags_showPlayerRanks = false;
ace_nametags_showVehicleCrewInfo = true;
ace_nametags_showCursorTagForVehicles = true;
ace_nametags_showSoundWaves = 1;
ace_nametags_tagSize = 2;
ace_nametags_playerNamesViewDistance = 12;

// ACE NVG
force ace_nightvision_disableNVGsWithSights = false;
force ace_nightvision_fogScaling = 1;
force ace_nightvision_effectScaling = 1;
force ace_nightvision_aimDownSightsBlur = 1;

// ACE Overheating
force ace_overheating_overheatingDispersion = true;
force ace_overheating_unJamOnreload = true;
force ace_overheating_unJamFailChance = 0;
force ace_overheating_enabled = true;
ace_overheating_displayTextOnJam = true;
ace_overheating_showParticleEffects = true;
ace_overheating_showParticleEffectsForEveryone = true;

// ACE Pylons
force ace_pylons_enabled = true;
force ace_pylons_searchDistance = 15;
force ace_pylons_timePerPylon = 5;
ace_pylons_rearmNewPylons = true;
ace_pylons_requireEngineer = false;
ace_pylons_requireToolkit = false;

// ACE Rearm
force ace_rearm_level = 1;
force ace_rearm_supply = 0;

// ACE Refuel
force ace_refuel_rate = 2;
force force ace_refuel_hoseLength = 20;

// ACE Respawn
force ace_respawn_savePreDeathGear = false;
force force ace_respawn_removeDeadBodiesDisconnected = true;

// ACE Repair
ace_repair_displayTextOnRepair = true;
force ace_repair_engineerSetting_repair = 0;
force ace_repair_engineerSetting_wheel = 0;
force ace_repair_repairDamageThreshold = 0.75;
force ace_repair_repairDamageThreshold_engineer = 0.4;
force ace_repair_consumeItem_toolKit = 0;
force ace_repair_fullRepairLocation = 3;
force ace_repair_engineerSetting_fullRepair = 1;
force ace_repair_addSpareParts = true;
force ace_repair_wheelRepairRequiredItems = 0;
force force ace_repair_autoShutOffEngineWhenStartingRepair = true;

// ACE Spect
force ace_spectator_enableAI = false;
force ace_spectator_restrictModes = 0;
force ace_spectator_restrictVisions = 0;

// ACE VD
force ace_viewdistance_enabled = false;
ace_viewdistance_viewDistanceOnFoot = 0;
ace_viewdistance_viewDistanceLandVehicle = 0;
ace_viewdistance_viewDistanceAirVehicle = 0;
ace_viewdistance_limitViewDistance = 0;
ace_viewdistance_objectViewDistanceCoeff = 0;

// ACE Weather
force ace_weather_enabled = true;
force ace_weather_updateInterval = 60;
force ace_weather_windSimulation = false;

// ACE Wind deflection
force ace_winddeflection_enabled = true;
force ace_winddeflection_vehicleEnabled = true;
force ace_winddeflection_simulationInterval = 0.05;

// ACE Adv Throwing
ace_advanced_throwing_enabled = true;
ace_advanced_throwing_showThrowArc = true;
ace_advanced_throwing_showMouseControls = true;
force ace_advanced_throwing_enablePickUp = true;
force ace_advanced_throwing_enablePickUpAttached = true;
force ace_captives_allowHandcuffOwnSide = true;
force ace_captives_requireSurrender = 2;
force ace_captives_allowSurrender = true;
force ace_captives_requireSurrenderAi = false;
force force ace_cargo_enable = true;
force ace_cargo_paradropTimeCoefficent = 2;
force ace_explosives_requireSpecialist = false;
force ace_explosives_punishNonSpecialists = true;
force ace_explosives_explodeOnDefuse = true;
ace_gestures_showOnInteractionMenu = 2;

// ACE Zeus
force force ace_zeus_zeusAscension = false;
force force ace_zeus_zeusBird = false;
force force ace_zeus_remoteWind = false;
force force ace_zeus_radioOrdnance = false;
force force ace_zeus_revealMines = 0;
force force ace_zeus_autoAddObjects = true;

// ACE Adv ballistic
force ace_advanced_ballistics_enabled = true;
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
