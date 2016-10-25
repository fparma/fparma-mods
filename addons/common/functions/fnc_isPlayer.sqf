/*
* Author: ACE team
* Returns true if given object is a player and not zeus controlled
*
* Arguments:
* 1 - Object
*
* Public: Yes
*/

params [["_unit", objNull, [objNull]]];
isPlayer _unit && {isNull (_unit getVariable ["bis_fnc_moduleRemoteControl_owner", objNull])}
