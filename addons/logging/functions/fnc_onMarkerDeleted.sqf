#include "script_component.hpp"
params ["_marker", "_local"];

if (missionNamespace getVariable [QGVAR(deleteMarkerDisabled),false]) exitWith {};

if (!_local || {
    !isMultiplayer || {
    ("ACE_BFT_" in _marker) || {
    (getPlayerUID player) in _marker}}}) exitWith {};

private _info = ["Just deleted"];
switch (markerShape _marker) do {
    case "POLYLINE": {
        _info pushBack "a line"
    };
    case "ICON": {
        _info pushBack "a marker";
        private _text = markerText _marker;
        if (_text != "") then {
            _info pushBack ('with text "' + _text + '"');
        };
    };
    case "RECTANGLE";
    case "ELLIPSE": {
        _info pushBack "an area marker";
    };
    default {
        _info pushBack "a marker";
    };
};
_info pushBack ('that was of color "' + (markerColor _marker) + '"');

[QEGVAR(common,chatMessage), [profileName, _info joinString " ", "server", nil, false]] call CBA_fnc_globalEvent;
