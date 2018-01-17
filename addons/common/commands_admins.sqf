#include "script_component.hpp"


["tpto", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

	moveOut ACE_player;
    ACE_player setPos (_unit modelToWorld [0, -2, 0]);
    systemChat format ["Teleported you to %1", name _unit];
}, "Teleports you to other player. <#fp.tpto Cuel>"] call FUNC(registerChatCommand);

["tpme", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    moveOut _unit;
    _unit setVelocity [0,0,0];
    _unit setPos (ACE_player modelToWorld [0, 1, 0]);
    systemChat format ["Teleported %1 to you", name _unit];
}, "Teleports other player to you. <#fp.tpme Cuel>"] call FUNC(registerChatCommand);

["kill", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    systemChat format ["Killed %1", name _unit];
    _unit setDamage 1;
}, "Kills given player. <#fp.kill Cuel>"] call FUNC(registerChatCommand);

["kick", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    systemChat format ["Kicked %1", name _unit];
    [_unit] remoteExecCall ["fpa_serverCommandKick", 2];
}, "Kicks player <#fp.kick Cuel>"] call FUNC(registerChatCommand;

["cam", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    [getPos _unit, true] call EFUNC(common,cameraAtPosition);
}, "Creates camera at unit, acre spectator enabled <#fp.cam Cuel>"] call FUNC(registerChatCommand);

["heal", {
    params [["_name", ""]];
    private _unit = _name call FUNC(getPlayer);
    if (isNull _unit) exitWith {systemChat "Could not find unit"};

    systemChat format ["Fully healed %1", name _unit];
	[player, _unit] call ace_medical_fnc_treatmentAdvanced_fullHeal;
	_unit setDamage 0;
}, "Fully heals unit <#fp.heal Cuel>"] call FUNC(registerChatCommand);

["weaponlock", {
    params [["_str", ""]];
    private _disableWeapons = [false, true] select (_str isEqualTo "1");
    [_disableWeapons] remoteExecCall [QFUNC(disableWeapons)];

    systemChat format ["All player weapons %1", ["enabled", "disabled"] select _disableWeapons;
}, "Disable/enable all player weapons. 0 enable weapons, 1 disable weapons. <#fp.weaponlock 0/1>"] call FUNC(registerChatCommand);
