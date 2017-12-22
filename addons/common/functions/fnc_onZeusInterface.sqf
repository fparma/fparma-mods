/*
* Author: PabstMirror / POTATO
*/

#include "script_component.hpp"

#define ACRE_CTRL ((findDisplay 312) displayCtrl 777550)
#define UNIT_COUNT ((findDisplay 312) displayCtrl 777551)

if (isNil QFUNC(toggleZeusAcre)) then {
    FUNC(toggleZeusAcre) = {[!ACRE_IS_SPECTATOR] call acre_api_fnc_setSpectator};
};

[player] call FUNC(lowerPlayerWeapon);

// hide zeus watermark
[{
    private _ctrl = (findDisplay 312) displayCtrl 15717;
    _ctrl ctrlSetText ""; //QPATHTOEF(assets,img\logo_lg.paa);
}] call CBA_fnc_execNextFrame;

[{
    if (isNull (findDisplay 312)) exitWith {
        [_this select 1] call CBA_fnc_removePerFrameHandler;
        [!([player] call ace_common_fnc_isAwake)] call acre_api_fnc_setSpectator;
    };

    if (missionNamespace getVariable ["ACRE_IS_SPECTATOR", false]) then {
        ACRE_CTRL ctrlSetTextColor [0,1,0,1];
    } else {
        ACRE_CTRL ctrlSetTextColor [1,1,1,1];
    };

    // if screenshot mode
    if (ctrlShown ((findDisplay 312) displayCtrl 15717)) exitWith {
        UNIT_COUNT ctrlShow false;
    };

    private _units = allUnits - [player];
    private _text = format ["AI: %1 (%2 loc). Plrs: %3 (%4 spec)",
        {simulationEnabled _x && {!isPlayer _x}} count _units,
        {local _x} count _units,
        count call CBA_fnc_players,
        count call ace_spectator_fnc_players
    ];

    UNIT_COUNT ctrlShow true;
    UNIT_COUNT ctrlSetText _text;
}, 0.5, []] call CBA_fnc_addPerFrameHandler;
