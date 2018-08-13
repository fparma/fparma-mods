/*
  Author: diwako

  Description:
  Code for AnimChanged eventhandler

  Parameter(s):
  _unit - Ragdolled unit
  _anim - Currently changed animation

  Examples:
  (begin)
    [_unit,_anim] call fpa_common_fnc_ragdoll_animChangedEH;
  (end)

  Returns:
    none
*/
#include "script_component.hpp"
params ["_unit","_anim"];
if(!(_unit getVariable ["ACE_isUnconscious",false])) exitWith {}; // do not run if unit is conscious
if(!(alive _unit) &&  // do not run if unit is dead
	{!(isNull objectParent _unit)}) exitWith {}; // do not run if unit in any vehicle

_anim = toLower(_anim);

if((_anim find "unconsciousrevive") != -1 || // catch ragdoll recovery animations
  {_anim == "unconsciousoutprone" || // catch another ragdoll recovery animation
  {(_anim find "amov") == 0 }} ) then { // catch any movement or stance type of animation (player specific clause)
  _anim = "unconscious";

  // figure out which position state is need
  private _vRightShoulder = _unit selectionPosition "rightshoulder";
  private _vLeftShoulder = _unit selectionPosition "leftshoulder";
  private _heightDif = _vRightShoulder#2 - _vLeftShoulder#2;

  // array of array for each animation
  private _animHolder = [];

  if(isNil QGVAR(ragdoll_animHolder)) then {
    GVAR(ragdoll_animHolder) = [];
    // mod version found
    GVAR(ragdoll_animHolder) pushBack ["kka3_unc_2","kka3_unc_2_1","kka3_unc_7_1","kka3_unc_8_1","kka3_unc_5_1","kka3_unc_6_1"]; // 0 on their back
    GVAR(ragdoll_animHolder) pushBack ["kka3_unc_1", "kka3_unc_3", "kka3_unc_4","unconscious","KIA_passenger_boat_holdleft","kka3_unc_3_1","kka3_unc_4_1"]; // 1 on their belly
    GVAR(ragdoll_animHolder) pushBack ["kka3_unc_7","kka3_unc_8","kka3_unc_6_1","kka3_unc_5_1"]; // 2 on their right shoulder
    GVAR(ragdoll_animHolder) pushBack ["kka3_unc_5","kka3_unc_6","KIA_driver_boat01","kka3_unc_1_1","kka3_unc_7_1","kka3_unc_8_1"]; // 3 on their left shoulder
  };

  if( _heightDif > 0.2 || _heightDif < -0.2) then {
    // unit on side
    // first one is right shoulder, second one is on left shoulder
    _anim = selectRandom ([GVAR(ragdoll_animHolder)#2 , GVAR(ragdoll_animHolder)#3] select (_heightDif < -0.2));
  } else {
    if(_vRightShoulder#0 > _vLeftShoulder#0) then {
      // unit on their belly
      _anim = selectRandom (GVAR(ragdoll_animHolder)#1);
    } else {
      // unit on their back
      _anim = selectRandom (GVAR(ragdoll_animHolder)#0);
    };
  };

  _unit setUnconscious false;
  // play animation
  [
    {
      params ["_unit","_anim"];
      if(_unit getVariable ["ACE_isUnconscious",false]) then {
        // [_unit, _anim, 2, true] call ace_common_fnc_doAnimation;
        if(_unit == ace_player) then {
          ["ace_common_switchMove", [_unit, _anim]] call CBA_fnc_globalEvent;
        } else {
          _unit switchMove _anim;
        };
      };
    }, // code
    [_unit,_anim], // params
    0.2 // delay
  ] call CBA_fnc_waitAndExecute;

  // combat network sync issues
  if(isMultiplayer) then {
    [
      {
        params ["_unit","_anim"];
        if((_unit getVariable ["ACE_isUnconscious",false]) && // unit still unconscious
          {(isNull objectParent _unit) && // unit not in a car
          {!([_unit] call ace_medical_fnc_isBeingCarried) && // not being carried
          {!([_unit] call ace_medical_fnc_isBeingDragged)}}} // not being dragged
          ) then {
          // reapply unconscious animation just in case
          // [_unit, _anim, 2, true] call ace_common_fnc_doAnimation;
          if(_unit == ace_player) then {
            ["ace_common_switchMove", [_unit, _anim]] call CBA_fnc_globalEvent;
          } else {
            _unit switchMove _anim;
          };
        };
        if(!(_unit getVariable ["ACE_isUnconscious",false])) then {
          // unit is not unconscious anymore
          _unit setUnconscious false;
          // free unit of unconscious animation if it is still trapped in it
          if(animationState _unit == _anim) then {
            _unit switchMove "";
          };
        };
      }, // code
      [_unit,_anim], // params
      6.25 // delay
    ] call CBA_fnc_waitAndExecute;
  };
};