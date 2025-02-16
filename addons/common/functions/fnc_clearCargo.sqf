/*
* Author: Cuel
*
* Description:
* Clear all passed vehicles's cargo
*
* Arguments:
* 0 - Object | Object[]
*
* Example
* [car1, car2] call fpa_common_fnc_clearCargo;
* Public: Yes
*/
#include "script_component.hpp"

private _thisNew = _this;
if !(_thisNew isEqualType []) then {_thisNew = [_thisNew]};

{
  if (_x isEqualType objNull) then {
    clearMagazineCargoGlobal _x;
    clearWeaponCargoGlobal _x;
    clearItemCargoGlobal _x;
    clearBackpackCargoGlobal _x;
  };
} count _thisNew;
true
