/*
* Author: ACE team edited by cuel to account for headless
* Returns true if given object is a player and not zeus controlled and not HC
*
* Arguments:
* 1 - Object
*
* Public: Yes
*/

params [["_unit", objNull, [objNull]]];

private _ret = isPlayer _unit &&
    {!(_unit isKindOf "HeadlessClient_F")} &&
    {isNull (_unit getVariable ["bis_fnc_moduleRemoteControl_owner", objNull])};

_ret
