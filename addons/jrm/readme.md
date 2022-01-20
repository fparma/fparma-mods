# JRM Respawn

Respawn system for the FPArma modpack. Automatically handles lives and puts players into ACE spectator when no lives are left.
Simple way to for mission maker to respawn people via zeus interface or via mission triggers/code.

## Functions

Mission makers only need one function, if at all to respawn people. The function is named `fpa_jrm_fnc_forceRespawn`.

### Usage

Place down a trigger, make it server only, set the conditions as desired. Set the execution code like this:

```sqf
[] remoteExec ["fpa_jrm_fnc_forceRespawn"];
```

The function has two parameters:

**\_positionOrCode**

A marker, object, position, (\_this select 0 will be the unit for code)
If position, will be teleported there after exiting spectator
If code, the code is assumed to handle turning spectator off (fpa_common_fnc_spectate)
If nil, ace spectator will teleport the unit back to where he was when entering spectator (respawn pos)

**\_reset**

(server only) Clear all previous dead units [Default: false]. Value is a boolean.
Effectively resets lives if true is passed.

## Events

| Name                 | Params                        | Remark                                                                            |
| -------------------- | ----------------------------- | --------------------------------------------------------------------------------- |
| fpa_jrm_respawned    | none                          | Raised when player has been respawned using JRM, raised on player's machine       |
| fpa_jrm_forceRespawn | See the forceRespawn function | Never raised by framework, can be raised by mission maker to force respawn people |

### Usage

Subscribing to the respawned event can be done as such. Keep in mind it will be raised on the players machine when they respawn. You can use `player` here just fine. No headless client, dedicated server or player that is a virtual unit will receive this event!

```sqf
["fpa_jrm_respawned", {
    hint "Welcome back to the living!";
}] call CBA_fnc_addEventHandler;
```

Raising the forceRespawn event. The usage is effectively the same as the function above, just maybe some more elegant way instead of using `remoteExec`.

```sqf
["fpa_jrm_forceRespawn", [_positionOrCode, _reset]] call CBA_fnc_globalEvent;
```
