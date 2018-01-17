#include "script_component.hpp"

["whisper", {
    params [["_str", ""]];
	(_str splitString " ") apply {[[_x] call BIS_fnc_trimString]} params ["_to", "_msg"];
	if (_to isEqualTo "" || _msg isEqualTo "") exitWith {systemChat "Invalid arguments"};
	
	private _receiver = [_to] call FUNC(getPlayer);
    if (isNull _receiver) exitWith {systemChat "Could not find receiver"};
	[_msg, "whisper", name _receiver] call FUNC(sendChatMessage);
}, "Send a whisper chat message only visible for receiver <#fp.whisper Cuel yo what is up>", false] call FUNC(registerChatCommand);

["zeus", {
    params [["_msg", ""]];
	_msg = [_msg] call BIS_fnc_trimString;
	if (_msg isEqualTo "") exitWith {};
	[_msg, "zeus"] call FUNC(sendChatMessage);
}, "Send a chat message only visible for zeus <#fp.zeus Flip my vehicle>", false] call FUNC(registerChatCommand);

["admin", {
	params [["_msg", ""]];
	_msg = [_msg] call BIS_fnc_trimString;
	if (_msg isEqualTo "") exitWith {};
	[_msg, "admin"] call FUNC(sendChatMessage);
}, "Send a chat message only visible for fparma moderators <#fp.admin I require assistance>", false] call FUNC(registerChatCommand);
