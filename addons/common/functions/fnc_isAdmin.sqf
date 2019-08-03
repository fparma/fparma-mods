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
  private _isModerator = getPlayerUID player in [
    "76561197970604257", // cuel
    "76561198009543420", // croguy
    "76561197997030424", // Terry
    "76561197980328722", // diwako
    "76561197997590271" // G4rrus
  ];

  _isModerator || IS_ADMIN_LOGGED // return
};

false
