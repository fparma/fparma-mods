/**
* Description:
* Ends mission, can only be called from server
*
* Arguments
* 0 - End type <string>
* 1 - Won <boolean>
* 2 - Side if using array version <side>
*
* Example:
* Same ending for everyone
* ["End1", true] call fpa_common_fnc_endMissionServer;
*
* Different endings
* [
*    ["OpforDead", false, opfor],
*    ["OpforDead", true, blufor],
*    ["TimeLimit", false, independent]
* ] call fpa_common_fnc_endMissionServer;
*/
#include "script_component.hpp"

if (!isServer) exitWith {};

if (!isNil QGVAR(statsNamespace)) then {
    private _msg = [];
    private _over60min = (ceil CBA_missionTime) > 3600;
    private _duration = [CBA_missionTime, ["M:SS","H:MM:SS"] select _over60min] call CBA_fnc_formatElapsedTime;
    _msg pushBack format ["<t font='PuristaBold' size='1'>Mission Duration %1<t><br/>", _duration];
    {
        private _side = [_x] call FUNC(translateSide);
        private _str = format ["%1 casualties:", _side call CBA_fnc_capitalize];
        {
            private _key = format ["%1_%2", _side, toLower _x];
            private _kills = GVAR(statsNamespace) getVariable [_key, 0];
            if (_kills > 0) then {
                _str = _str + format [" %1: %2.", _x, _kills];
            };
        } forEach ["Men", "Car", "APC", "Armor", "Air"];
        _msg pushBack _str;
    } forEach [blufor, opfor, independent, civilian];

    GVAR(stats)  = _msg joinString '<br/>';
    publicVariable QGVAR(stats);
};

[QGVAR(endMission), _this] call CBA_fnc_globalEvent;
