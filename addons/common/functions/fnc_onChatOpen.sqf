#include "script_component.hpp"
params ["_display"];

if (GVAR(hideChatHint) || {!(isNull (_display getVariable [QGVAR(chatReminder), controlNull])) || {time < 1}}) exitWith {};

private _height = (((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25) * 0.8);
private _width = (profileNamespace getVariable ["IGUI_GRID_CHAT_W", (20 * ( ((safeZoneW / safeZoneH) min 1.2) / 40))]);
private _xPos = (profileNamespace getVariable ["IGUI_GRID_CHAT_X", (safeZoneX + 1 * ( ((safeZoneW / safeZoneH) min 1.2) / 40))]);
private _yPos = (profileNamespace getVariable ["IGUI_GRID_CHAT_Y", (safeZoneY + safeZoneH - 10.5 * ( ( ((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25))]);

private _dumbNamePair = selectRandom [
    ["_[SOG]_xXxSlayer69xXx_", "slayer"],
    ["361684XBlaBlub", "blab"],
    ["===Mingebag~~~~D!", "minge"],
    ["Username3813", "user"],
    ["Hard Core Milsim", "mils"],
    ["ih8Civs", "ih8"]
];

private _text = format ['<t size="2.0" color="#ff0000" shadow="1" shadowColor="#000000">%1</t><br/>
if you need to contact zeus, an admin, or want to send a messsage to a friend, do not use side or global chat!<br/>
Use the <t size="1.1" color="#ffDDDD" shadow="1" shadowColor="#000000">chat commands</t> instead or the <t size="1.1" color="#ffDDDD" shadow="1" shadowColor="#000000">chat box in the escape menu</t>!<br/>
<br/>
Here is how VVVV<br/>
Contact zeus:<br/>
<t size="1.1" color="#ff0000" shadow="1" shadowColor="#000000">#zeus</t> %2<br/>
<br/>
Contact an admin:<br/>
<t size="1.1" color="#ff0000" shadow="1" shadowColor="#000000">#admin</t> %3<br/>
<br/>
Contact your friend:<br/>
<t size="1.1" color="#ff0000" shadow="1" shadowColor="#000000">#w friendname</t> %4<br/>
The given name can be partial as well. Example, instead of <t color="#ff0000" shadow="1" shadowColor="#000000">%5</t> you can write <t color="#ff0000" shadow="1" shadowColor="#000000">%6</t><br/><br/>
You can hide this hint within the <t color="#ff0000" shadow="1" shadowColor="#000000">Addon Options</t> menu under <t color="#ff0000" shadow="1" shadowColor="#000000">FPARMA Settings</t>.<br/>
Also, check out the command <t size="1.1" color="#ff0000" shadow="1" shadowColor="#000000">#fp.help</t>',
selectRandom [ // 1 header
    "Hey, read this before you send a message!",
    "You best not be talking shit!",
    "AYOOOOOOOOO!",
    "Greetings!",
    "Hold it!",
    "Hewwo!",
    "Hey!",
    "Yo, listen up!",
    "Not this annoying thing again...",
    "Have you heard about tinter furniture?",
    "Literally 1984!",
    "Stop, think, type!"
], selectRandom [ // 2 zeus
    "hey can you tp me to my squad?",
    "stop using mortars on me!",
    "pls repair car",
    "heal pls!",
    "respawn pls",
    "i know what you are doing and i do not like it!",
    "i crashed, can you tp to my squad?",
    "i am die, pls respawn",
    "stuck in a burning car....",
    "my team mates are too stupid to heal me, pls heal",
    "my tank exploded and teleported me out of the map, pls help"
], selectRandom [ // 3 admin
    "uuuh hc crashed! pls restart!",
    "can you kick this guy?",
    "aaaaaaaaaaah",
    "uuh i do not have zeus, can you help?",
    "exabit is mean to me :(",
    "croguy is mean to me :(",
    "pilotguy is mean to me :(",
    "diwako is mean to me :("
], selectRandom [ // 4 whisper
    "yo waddap?",
    "hey there gorgeous",
    "i am down pls help",
    "enemy around there...",
    "aaaah stop crashing my body into every tree!",
    "backblast is a thing!",
    "stop overpressuring me!!!!",
    "epi last!!",
    "fart"
], _dumbNamePair select 0, _dumbNamePair select 1];

private _ctrl = _display ctrlCreate ["RscStructuredText", -1];
_ctrl ctrlSetStructuredText (parseText _text);
_ctrl ctrlSetPosition [_xPos, _yPos, _width, _height];
_ctrl ctrlSetBackgroundColor [0, 0, 0, 0.3];
_ctrl ctrlSetTextColor [1, 1, 1, 1];
_ctrl ctrlSetFont "RobotoCondensed";
_ctrl ctrlCommit 0;
private _textWidth = ctrlTextWidth _ctrl;
_ctrl ctrlSetPosition [_xPos, _yPos, _textWidth, _height];
_ctrl ctrlCommit 0;
private _textHeight = ctrlTextHeight _ctrl;
_ctrl ctrlSetPosition [_xPos, _yPos, _textWidth, 0];
_ctrl ctrlSetFade 1;
_ctrl ctrlCommit 0;
_ctrl ctrlSetPosition [_xPos, _yPos - _textHeight, _textWidth, _textHeight];
_ctrl ctrlCommit 0.1;
_ctrl ctrlSetFade 0;
_ctrl ctrlCommit 0.5;
_display setVariable [QGVAR(chatReminder), _ctrl];
playSound "soundExpand";
