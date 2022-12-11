[
    QGVAR(blurUnconScreen),
    "CHECKBOX",
    "Blur screen instead of using blackout effects",
    [FP_SETTINGS, "Medical"],
    false,
    false
] call CBA_fnc_addSetting;

[
    QGVAR(unconSpectator),
    "CHECKBOX",
    "Enable Unconscious Spectator",
    [FP_SETTINGS, "View Distance"],
    false,
    true
] call CBA_fnc_addSetting;
