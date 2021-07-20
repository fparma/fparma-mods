#include "script_component.hpp"
/*
 * Function: fpa_common_fnc_createZeus
 *
 * Author: diwako
 *
 * Arguments:
 * 0: Player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * Creates a curator for given player
 *
 * Public: Yes
 */
params [["_unit", objNull], ["_admin", objNull]];
if !(isServer) exitWith {};
if (isNull _unit || {!isPlayer _unit}) exitWith {};

if (isNull (getAssignedCuratorLogic _unit)) exitWith {
    private _grp = createGroup [sideLogic, true];
    private _curator = _grp createUnit ["ModuleCurator_F",[0,0,0],[],0,"NONE"];
    _curator setVariable ["Addons", 3, true];

    _curator addCuratorEditableObjects [(allMissionObjects "Man"), false];
    _curator addCuratorEditableObjects [(allMissionObjects "Air"), true];
    _curator addCuratorEditableObjects [(allMissionObjects "Car"), true];
    _curator addCuratorEditableObjects [(allMissionObjects "Ammo"), false];
    _curator setVariable ["birdType",""];
    _curator setvariable ["owner", getPlayerUID _unit];
    _curator setVariable ["showNotification",false];
    _curator setCuratorCoef ["Place", 0];
    _curator setCuratorCoef ["Delete", 0];
    [_curator, [-1, -2, 2]] call bis_fnc_setCuratorVisionModes;
    if (!isMultiplayer && {!isNull findDisplay 313}) then {
        // if loaded from editor (but not after restart), addons are not activated so we do it manually
        private _addons = ('true' configClasses (configFile >> "CfgPatches")) apply {configName _x};
        activateAddons _addons;
        removeAllCuratorAddons _curator;
        _curator addCuratorAddons _addons;
    };

    _curator addEventHandler ["CuratorPinged", {
        private _curator = _this select 0;
        if !(alive (getAssignedCuratorUnit _curator)) then {
            unassignCurator _curator;
            deleteVehicle _curator;
        };
    }];

    _unit assignCurator _curator;

    [QGVAR(chatMessage), ["Server", format ["%1 created a curator for %2!", name _admin, name _unit], "admin"]] call CBA_fnc_globalEvent;
    if (_unit isNotEqualTo _admin) then {
        [QGVAR(chatMessage), [name _admin, "Zeus has been enabled for you", "whisper", name _unit]] call CBA_fnc_globalEvent;
    };
};
