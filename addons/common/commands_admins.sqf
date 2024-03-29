["tpto", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    moveOut ACE_player;
    ACE_player setPos (_unit modelToWorld [0, -2, 0]);
    [QGVAR(chatMessage), [profileName, format ["teleported to %1", name _unit], "admin", "", false]] call CBA_fnc_globalEvent;
}, "Teleports you to other player. <#fp.tpto Cuel>"] call FUNC(registerChatCommand);

["tpme", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    moveOut _unit;
    _unit setVelocity [0,0,0];
    _unit setPos (ACE_player modelToWorld [0, 1, 0]);
    [QGVAR(chatMessage), [profileName, format ["teleported %1 to himself", name _unit], "admin", "", false]] call CBA_fnc_globalEvent;
}, "Teleports other player to you. <#fp.tpme Cuel>"] call FUNC(registerChatCommand);

["kill", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    [QGVAR(chatMessage), [profileName, format ["killed %1", name _unit], "admin", "", true]] call CBA_fnc_globalEvent;
    _unit setDamage 1;
}, "Kills given player. <#fp.kill Cuel>"] call FUNC(registerChatCommand);

["kick", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    [QGVAR(chatMessage), [profileName, format ["kicked %1", name _unit], "admin", "", true]] call CBA_fnc_globalEvent;
    [_unit] remoteExecCall ["fpa_serverCommandKick", 2];
}, "Kicks player <#fp.kick Cuel>"] call FUNC(registerChatCommand);

["cam", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    [getPos _unit, false] call EFUNC(common,cameraAtPosition);
    [QGVAR(chatMessage), [profileName, format ["created camera at %1", name _unit], "admin", "", false]] call CBA_fnc_globalEvent;
}, "Creates camera at unit, acre spectator enabled <#fp.cam Cuel>"] call FUNC(registerChatCommand);

["heal", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    [QGVAR(chatMessage), [profileName, format ["fully healed %1", name _unit], "admin", "", false]] call CBA_fnc_globalEvent;
    [player, _unit] call ace_medical_treatment_fnc_fullHeal;
    _unit setDamage 0;
}, "Fully heals unit <#fp.heal Cuel>"] call FUNC(registerChatCommand);

{
    [_x, {
        params [["_str", ""]];
        private _disableWeapons = [false, true] select (_str isEqualTo "1");
        [_disableWeapons, "admin"] remoteExecCall [QFUNC(disableWeapons)];

        [QGVAR(chatMessage), [profileName, format ["%1 weapons", ["enabled", "disabled"] select _disableWeapons], "", "", true]] call CBA_fnc_globalEvent;
    }, "Disable/enable all player weapons. 0 enable weapons, 1 disable weapons. <#fp.weaponlock 0/1>"] call FUNC(registerChatCommand);
} forEach ["wl", "weaponlock"];

["adminend", {
    ["AdminEnd", true] remoteExec [QFUNC(endMissionServer), 2];
}, "Ends the missions with 'Admin End' ending type"] call FUNC(registerChatCommand);

["createzeus", {
    params [["_name", ""]];
    private _unit = player;
    if (_name isNotEqualTo "") then {
        _unit = [_name] call FUNC(getPlayer);
    };
    if (isNull _unit) exitWith {systemChat "Could not find unit"};
    [QGVAR(createzeus), [_unit, player]] call CBA_fnc_serverEvent;
}, "Create zeus for given name. No name means create Zeus for yourself"] call FUNC(registerChatCommand);

{
    [_x, {
        params [["_str", ""]];
        private _disable = [false, true] select (_str isEqualTo "1");
        missionNamespace setVariable [QGVAR(allowChatMessages), !_disable, true];

        [QGVAR(chatMessage), [profileName, format ["Side/Global chat has been %1!", ["unlocked", "locked"] select _disable], "", "", true]] call CBA_fnc_globalEvent;
    }, "Disable/enable all player chat messages in global and side chat. 0 enable weapons, 1 disable weapons. <#fp.chatlock 0/1>"] call FUNC(registerChatCommand);
} forEach ["cl", "chatlock"];
