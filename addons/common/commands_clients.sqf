["whisper", {
    params [["_str", ""]];
    private _split = (_str splitString " ");
    private _to = _split param [0, ""];
    _split deleteAt 0;
    private _msg = _split joinString " ";
    if (_to isEqualTo "" || _msg isEqualTo "") exitWith {systemChat "Invalid arguments"};

    private _receiver = [_to] call FUNC(getPlayer);
    if (isNull _receiver) exitWith {systemChat "Could not find receiver"};
    [_msg, "whisper", name _receiver] call FUNC(sendChatMessage);
}, "Send a whisper chat message only visible for receiver <#fp.whisper Cuel yo what is up>", false] call FUNC(registerChatCommand);

["zeus", {
    params [["_msg", ""]];
    _msg = [_msg] call CBA_fnc_trim;
    if (_msg isEqualTo "") exitWith {};
    [_msg, "zeus"] call FUNC(sendChatMessage);
}, "Send a chat message only visible for zeus <#fp.zeus Flip my vehicle>", false] call FUNC(registerChatCommand);

["admin", {
    params [["_msg", ""]];
    _msg = [_msg] call CBA_fnc_trim;
    if (_msg isEqualTo "") exitWith {};
    [_msg, "admin"] call FUNC(sendChatMessage);
}, "Send a chat message only visible for fparma moderators <#fp.admin I require assistance>", false] call FUNC(registerChatCommand);

{
    [_x, {
        params [["_msg", ""]];
        _msg = [_msg] call CBA_fnc_trim;
        if (_msg isEqualTo "") exitWith {};
        private _receiver = [GVAR(lastMessageFrom)] call FUNC(getPlayer);
        if (isNull _receiver) exitWith {systemChat "Could not find receiver"};
        if (_receiver isEqualTo ([] call CBA_fnc_currentUnit)) exitWith {systemChat "Messaging yourself is not helping"};
        [_msg, "whisper", name _receiver] call FUNC(sendChatMessage);
    }, "Send a whisper reply to the person you last recevied a message from <#fp.r OR #fp.reply Hello stop pinging me!>", false] call FUNC(registerChatCommand);
} forEach ["r", "reply"];
