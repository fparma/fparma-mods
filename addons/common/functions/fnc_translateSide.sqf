/*
* Author: commy2
*
* Description: Translate side to string
*
* Arguments:
* 1 - Side
*
* Public: Yes
*/

#include "script_component.hpp"

#define SIDES [blufor, opfor, independent, civilian]
#define SIDES_STR ["BLUFOR", "OPFOR", "INDEPENDENT", "CIVILIAN"]

params [["_side", sideUnknown, [blufor]]];
SIDES_STR param [SIDES find _side, "SIDEUNKNOWN"] // return
