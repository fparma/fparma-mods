/*
 * Author: Cuel
 * Checks if admin
 *
 * Arguments:
 *
 * Public: Yes
 */

#include "script_component.hpp"

if (hasInterface) exitWith {
  (getPlayerUID player in (call GVAR(admins))) || {IS_ADMIN_LOGGED} // return
};

false
