/*
    Author: Karel Moricky
        Rewritten by Cuel

    Description:
    Export current arsenal loadout, with some improvements
    Also supports just "simply exporting" the players current gear, if called from editor

    Returns:
    STRING - SQF code
*/

private _var = "_unit";
private _savedRadios = [];
private _br = toString [13, 10];
private _center = missionNamespace getVariable ["BIS_fnc_arsenal_center", ace_player];
private _export = [format ['%1%1 ["%2", "example.sqf"]', '/', typeOf _center]];
_export pushBack ('params ["_unit", "_type"];' + _br);

private _fnc_getRadio = {
  params ["_item"];
  if (_item == "ItemRadio") exitWith {"ACRE_PRC343"};
  (_item splitString "_") params [["_prefix", ""], ["_suffix", ""]];
  if (_prefix != "acre" || {["prc", "sem"] find (_suffix select [0, 3]) < 0}) exitWith {""};
  (toUpper ([_prefix, _suffix] joinString "_"))
};

private _fnc_addMultiple = {
  params ["_items", "_command"];
  private _itemsUsed = [];
  private _toAdd= [];

  {
    private _item = _x;
    private _itemLowerCase = toLower _item;
    private _radio = _itemLowerCase call _fnc_getRadio;
    if (_radio != "") then {
      private _cmd = (_command splitString " ") select 1;
      _savedRadios pushBack (format ['%1 %2 "%3";', _var, _cmd, _radio]);
    } else {
      if !(_itemLowerCase in _itemsUsed) then {
        _itemsUsed pushBack _itemLowerCase;
        private _count = {_item == _x} count _items;
        private _localCommand = _command;

        if (_count > 1) then {
          private _numberArray = [];
          for "_i" from 1 to _count do {_numberArray pushBack _i};
          _localCommand = format ["{%1} count %2;", _command, _numberArray];
        } else {
          _localCommand = _localCommand + ";";
        };
        _toAdd pushBack (format [_localCommand, _var, _x]);
      };
    };
  } forEach _items;
  _export append ([_toAdd, [], {count _x}] call BIS_fnc_sortBy);
};

if (primaryWeapon _center != "" || {secondaryWeapon _center != ""} || {handgunWeapon _center != ""} || {binocular _center != ""}) then {
  _export pushBack "// Fake backpack to store magazines and then load them. This ensures that weapons are loaded";
  _export pushBack format ['%1 addBackpack "ACE_FakeBackpack";', _var];
  private _pw = primaryWeapon _center;
  private _sw = secondaryWeapon _center;
  private _hw = handgunWeapon _center;
  private _getAccessories = {
    params [["_wep", ""]];
    ((_center weaponAccessories _wep) select {_x != ""})
  };

  private _primary = ["// Primary weapon", _pw, _pw call _getAccessories, "addPrimaryWeaponItem", primaryWeaponMagazine _center];
  private _secondary = ["// Secondary weapon", _sw, _sw call _getAccessories, "addSecondaryWeaponItem", secondaryWeaponMagazine _center];
  private _handgun = ["// Handgun", _hw, _hw call _getAccessories, "addHandgunItem", handgunMagazine _center];
  private _binoc = ["// Binoc", binocular _center, [_center call CBA_fnc_binocularMagazine] select {_x != ""}, "addMagazine"];

  {
    _x params ["_comment", ["_weapon", ""], ["_accessories", []], "_command", ["_loadedAmmo", []]];
    if (_weapon != "") then {
      _export pushBack _comment;
      {
        _export pushBack format ['%1 addMagazine "%2";', _var, _x];
      } forEach _loadedAmmo;
      _export pushBack format ['%1 addWeapon "%2";', _var, _weapon];

      {
        _export pushBack format ['%1 %2 "%3";', _var, _command, _x];
      } forEach _accessories;
    };
  } forEach [_primary, _secondary, _handgun, _binoc];
  _export pushBack format ['removeBackpack %1;', _var];
};

// Containers / clothes
private _containerCommentAdded = false;
{
  _x params ["_clothing", "_cmd"];
  if (_clothing != "") then {
    if (!_containerCommentAdded) then {
      _export pushBack (_br + "// Containers / clothes");
      _containerCommentAdded = true;
    };
    _export pushBack format ['%1 %2 "%3";', _var, _cmd, _clothing];
  };
} forEach [
  [headgear _center, "addHeadgear"],
  [uniform _center, "forceAddUniform"],
  [vest _center, "addVest"]
];

if (!isNull unitBackpack _center) then {
  _export pushBack format ['%1 addBackpack "%2";', _var, typeOf unitBackpack _center];
  _export pushBack format ['clearAllItemsFromBackpack %1;', _var];
};

// Assigned items
private _assignedItems = assignedItems _center - [binocular _center, "ItemRadioAcreFlagged"];
if (count _assignedItems > 0) then {
  _export pushBack format ['{%1 linkItem _x} forEach %2;%3', _var, _assignedItems, _br];
};

{
  _x params ["_comment", ["_items", []], "_cmd"];
  if (_items isNotEqualTo []) then {
    _export pushBack _comment;
    [_items, _cmd] call _fnc_addMultiple;
  };
} forEach [
  ["// Uniform items", uniformItems _center, '%1 addItemToUniform "%2"'],
  ["// Vest items", vestItems _center, '%1 addItemToVest "%2"'],
  ["// Backpack items", backpackItems _center, '%1 addItemToBackpack "%2"']
];

// Radios
if (_savedRadios isNotEqualTo []) then {
  _export pushBack "// Radios";
  {_export pushBack _x} forEach _savedRadios;
};

private _ret = _export joinString _br;
copyToClipboard _ret;
_ret
