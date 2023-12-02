////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.10
//https://mikero.bytex.digital/Downloads
//'now' is Fri Dec 01 18:19:51 2023 : 'file' last modified on Mon Apr 25 08:06:12 2022
////////////////////////////////////////////////////////////////////

#define _ARMA_

//(19 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxesxyz = 4,
	stabilizedinaxisy = 2,
	stabilizedinaxesboth = 3,
	destructno = 0,
	_hintsw = 25,
	_hintsh = 4,
	_hintsx = 0,
	_hintsy = 0,
	stabilizedinaxesnone = 0,
	_xspacing = 0,
	destructman = 5,
	_yspacing = 0,
	destructbuilding = 1
};

class CfgPatches
{
	class A3_Ui_F_Curator
	{
		author = "$STR_A3_Bohemia_Interactive";
		name = "Arma 3 Zeus Update - User Interface";
		url = "https://www.arma3.com";
		requiredAddons[] = {"A3_Functions_F_Curator","A3_Ui_F"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
	};
};
class DefaultFont
{
	font = "RobotoCondensed";
};
class ScrollBar
{
	color[] = {1,1,1,0.6};
	colorActive[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.3};
	thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
	arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	shadow = 0;
	scrollSpeed = 0.06;
	width = 0;
	height = 0;
	autoScrollEnabled = 0;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
};
class CfgCurator
{
	icon = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
	logo = "\a3\ui_f_curator\data\logos\arma3_curator_256_ca.paa";
	soundsPing[] = {"RscDisplayCurator_ping01","RscDisplayCurator_ping02","RscDisplayCurator_ping03","RscDisplayCurator_ping04","RscDisplayCurator_ping05","RscDisplayCurator_ping06","RscDisplayCurator_ping07"};
	class EditingArea
	{
		class 2D
		{
			textureBorder = "\a3\ui_f_curator\data\cfgcurator\area_ca.paa";
			colorBorder[] = {1,1,1,1};
			iconSizeMultiplier = 0.003;
		};
		class 3D
		{
			objectBorder = "a3\UI_F_Curator\Objects\objectBorder.p3d";
		};
	};
	class DrawObject
	{
		iconSize = 0.65;
		iconDriver = "\a3\Ui_f\data\IGUI\Cfg\CommandBar\imageDriver_ca.paa";
		iconCommander = "\a3\Ui_f\data\IGUI\Cfg\CommandBar\imageCommander_ca.paa";
		iconGunner = "\a3\Ui_f\data\IGUI\Cfg\CommandBar\imageGunner_ca.paa";
		iconCargo = "\a3\Ui_f\data\IGUI\Cfg\CommandBar\imageCargo_ca.paa";
		class PlayerPings
		{
			animationLength = 6000;
			alowRepeatAfter = 4000;
		};
		class 3D
		{
			alphaNormal = 0.4;
			alphaNormalBackground = 0.25;
			alphaSelected = 0.7;
			alphaSelectedBackground = 0.5;
			alphaHover = 1;
			alphaHoverBackground = 1;
			sizeNormal = 1.0;
			sizeSelected = 1.0;
			sizeTarget = 1.1;
			sizeCoefStartDistance = 50;
			sizeCoefEndDistance = 200;
			texture = "\A3\ui_f_curator\data\cfgcurator\entity_ca.paa";
			textureBackground = "\A3\ui_f_curator\data\cfgcurator\entity_selected_ca.paa";
			textureDisabled = "\A3\ui_f_curator\data\cfgcurator\entity_disabled_ca.paa";
			textureDisabledBackground = "\A3\ui_f_curator\data\cfgcurator\entity_selected_ca.paa";
			color[] = {1,1,1,1};
			colorBackground[] = {"side"};
			colorDisabled[] = {1,1,1,1};
			colorDisabledBackground[] = {"side"};
			colorLogic[] = {1,1,1,1};
			colorLogicBackground[] = {0.5,0.5,0.5,1};
			colorLogicDisabled[] = {1,1,1,1};
			colorLogicDisabledBackground[] = {0.5,0.5,0.5,1};
			colorPreview[] = {1,1,1,1};
			colorPreviewBackground[] = {1,1,1,0.25};
			colorPreviewDisabled[] = {1,0,0,1};
			colorPreviewDisabledBackground[] = {1,1,1,0.25};
			colorSelectionSquare[] = {0,1,0,1};
			colorLineGroupingUnits[] = {0,1,1,1};
			colorBBoxWhileDragging[] = {0,1,1,1};
			colorGroupsPreviewColor[] = {0,1,1,1};
			startIconFading = 250;
			endIconFading = 750;
			starLogictIconFading = 1000;
			endLogicIconFading = 1500;
		};
		class 2D
		{
			alphaNormal = 0.4;
			alphaNormalBackground = 0.25;
			alphaSelected = 0.7;
			alphaSelectedBackground = 0.5;
			alphaHover = 1;
			alphaHoverBackground = 1;
			sizeNormal = 1.0;
			sizeSelected = 1.0;
			sizeTarget = 1.1;
			sizeCoefStartDistance = 50;
			sizeCoefEndDistance = 200;
			texture = "\A3\ui_f_curator\data\cfgcurator\entity_ca.paa";
			textureBackground = "\A3\ui_f_curator\data\cfgcurator\entity_selected_ca.paa";
			textureDisabled = "\A3\ui_f_curator\data\cfgcurator\entity_disabled_ca.paa";
			textureDisabledBackground = "\A3\ui_f_curator\data\cfgcurator\entity_selected_ca.paa";
			color[] = {1,1,1,1};
			colorBackground[] = {"side"};
			colorDisabled[] = {1,1,1,1};
			colorDisabledBackground[] = {"side"};
			colorLogic[] = {1,1,1,1};
			colorLogicBackground[] = {0.5,0.5,0.5,1};
			colorLogicDisabled[] = {1,1,1,1};
			colorLogicDisabledBackground[] = {0.5,0.5,0.5,1};
			colorPreview[] = {1,1,1,1};
			colorPreviewBackground[] = {1,1,1,0.25};
			colorPreviewDisabled[] = {1,0,0,1};
			colorPreviewDisabledBackground[] = {1,1,1,0.25};
			colorSelectionSquare[] = {0,1,0,1};
			colorLineGroupingUnits[] = {0,1,1,1};
			colorBBoxWhileDragging[] = {0,1,1,1};
			colorGroupsPreviewColor[] = {0,1,1,1};
			size = 26;
		};
	};
	class DrawGroup
	{
		alphaNormal = 0.5;
		alphaSelected = 1;
		alphaTarget = 1;
		color = "side";
		colorPreview[] = {1,1,1,1};
		sizeCoefStartDistance = 5000;
		sizeCoefEndDistance = 6000;
		textureWest = "\a3\Ui_f\data\Map\Markers\NATO\b_unknown.paa";
		textureEast = "\a3\Ui_f\data\Map\Markers\NATO\o_unknown.paa";
		textureGuer = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
		textureCivilian = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
		textureUnknown = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
		class 3D
		{
			sizeCoefStartDistance = 5000;
			sizeCoefEndDistance = 6000;
			alphaNormal = 0.5;
			alphaSelected = 1;
			alphaTarget = 1;
			color = "side";
			colorPreview[] = {1,1,1,1};
			textureWest = "\a3\Ui_f\data\Map\Markers\NATO\b_unknown.paa";
			textureEast = "\a3\Ui_f\data\Map\Markers\NATO\o_unknown.paa";
			textureGuer = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
			textureCivilian = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
			textureUnknown = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
		};
		class 2D
		{
			alphaNormal = 0.5;
			alphaSelected = 1;
			alphaTarget = 1;
			color = "side";
			colorPreview[] = {1,1,1,1};
			textureWest = "\a3\Ui_f\data\Map\Markers\NATO\b_unknown.paa";
			textureEast = "\a3\Ui_f\data\Map\Markers\NATO\o_unknown.paa";
			textureGuer = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
			textureCivilian = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
			textureUnknown = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
		};
	};
	class DrawWaypoint
	{
		class 3D
		{
			texture = "\a3\Ui_F_Curator\Data\CfgCurator\waypoint_ca.paa";
			textureCycle = "\a3\Ui_F_Curator\Data\CfgCurator\waypointCycle_ca.paa";
			colorNormal[] = {0.5,1.0,0.5,1.0};
			colorSelected[] = {1.0,1.0,1.0,1.0};
			colorHover[] = {1.0,1.0,1.0,1.0};
			colorCycleNormal[] = {0.5,1.0,0.5,1.0};
			colorCycleSelected[] = {1.0,1.0,1.0,1.0};
			colorCycleHover[] = {1.0,1.0,1.0,1.0};
			texturePreview = "\a3\Ui_F_Curator\Data\CfgCurator\waypoint_ca.paa";
			colorPreview[] = {0,0,0,0.5};
		};
		class 2D
		{
			texture = "\a3\Ui_F_Curator\Data\CfgCurator\waypoint_ca.paa";
			textureCycle = "\a3\Ui_F_Curator\Data\CfgCurator\waypointCycle_ca.paa";
			colorNormal[] = {0,0,0,0.5};
			colorSelected[] = {1,1,1,0.5};
			colorHover[] = {1,1,1,1};
			colorCycleNormal[] = {0,0,0,0.5};
			colorCycleSelected[] = {1,1,1,0.5};
			colorCycleHover[] = {1,1,1,1};
			texturePreview = "\a3\Ui_F_Curator\Data\CfgCurator\waypoint_ca.paa";
			colorPreview[] = {0,0,0,0.5};
		};
	};
	class DrawPlayer
	{
		class 3D
		{
			texture = "\A3\ui_f\data\igui\cfg\islandmap\iconPlayer_ca.paa";
			color[] = {0.7,0.1,0,1};
			textureRemote = "\A3\ui_f\data\igui\cfg\islandmap\iconPlayer_ca.paa";
			colorRemote[] = {1,1,1,0.5};
			textureLaser = "\a3\Ui_F_Curator\Data\CfgCurator\laser_ca.paa";
			colorLaser[] = {1,1,1,0.5};
		};
		class 2D
		{
			texture = "\A3\ui_f\data\igui\cfg\islandmap\iconPlayer_ca.paa";
			color[] = {0.7,0.1,0,1};
			textureRemote = "\A3\ui_f\data\igui\cfg\islandmap\iconPlayer_ca.paa";
			colorRemote[] = {1,1,1,0.5};
			textureLaser = "\a3\Ui_F_Curator\Data\CfgCurator\laser_ca.paa";
			colorLaser[] = {1,1,1,0.5};
		};
	};
	class DrawCamera
	{
		class 2D
		{
			texture = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMissionEditor\iconCamera_ca.paa";
			color[] = {0,0,0,1};
			maxLineDistance = 1000;
		};
	};
	groupInfoType = "RscDisplayAttributesGroup";
	waypointInfoType = "RscDisplayAttributesWaypoint";
	markerInfoType = "RscDisplayAttributesMarker";
};
class CfgMPGameTypes
{
	class Zeus
	{
		shortcut = "$STR_A3_CfgMPGameTypes_Zeus_shortcut";
		name = "$STR_A3_CfgMPGameTypes_Zeus_name";
		id = 21;
		picture = "\a3\Missions_F_Curator\data\img\showcase_Curator_overview_CA.paa";
		icon = "\a3\Ui_F_Curator\Data\CfgMPGameTypes\zgm_ca.paa";
		featured = 1;
	};
};
class CfgNotifications
{
	class CuratorAddAddons
	{
		title = "$STR_A3_CfgNotifications_CuratorAddAddons_0";
		iconPicture = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
		description = "%1";
		color[] = {1,1,0.4,1};
	};
	class CuratorAddArea
	{
		title = "$STR_A3_CfgNotifications_CuratorAddArea_0";
		iconPicture = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
		description = "%1";
		color[] = {1,1,0.4,1};
	};
	class CuratorRemoveArea
	{
		title = "$STR_A3_CfgNotifications_CuratorRemoveArea_0";
		iconPicture = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
		description = "%1";
		color[] = {1,1,0.4,1};
	};
	class CuratorAssign
	{
		title = "$STR_A3_CfgNotifications_CuratorAssign_0";
		iconPicture = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
		description = "$STR_A3_CfgNotifications_CuratorAssign_1";
		color[] = {1,1,0.4,1};
	};
	class CuratorUnassign: CuratorAssign
	{
		title = "$STR_A3_CfgNotifications_CuratorUnassign_0";
		description = "$STR_A3_CfgNotifications_CuratorUnassign_1";
	};
	class IntelAdded
	{
		title = "$STR_A3_CfgNotifications_IntelAdded_0";
		description = "%1";
		iconPicture = "%2";
	};
	class Countdown
	{
		title = "$STR_A3_CfgNotifications_Countdown_0";
		iconPicture = "\a3\Modules_F_Curator\Data\portraitCountdown_ca.paa";
		description = "$STR_A3_CfgNotifications_Countdown_1";
	};
	class BootcampStageChanged
	{
		title = "$STR_A3_CfgNotifications_BootcampStageChanged_0";
		description = "$STR_A3_CfgNotifications_BootcampStageChanged_1";
		iconPicture = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
		priority = 7;
		duration = 3;
	};
	class TimeTrialStarted: BootcampStageChanged
	{
		title = "$STR_A3_CfgNotifications_TimeTrialStarted_0";
		description = "$STR_A3_CfgNotifications_TimeTrialStarted_1";
		iconPicture = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
	};
	class TimeTrialEnded: TimeTrialStarted
	{
		title = "$STR_A3_CfgNotifications_TimeTrialEnded_0";
		description = "$STR_A3_CfgNotifications_TimeTrialEnded_1";
		iconPicture = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
		duration = 5;
	};
	class TimeTrialCheckpoint: TimeTrialStarted
	{
		title = "$STR_A3_CfgNotifications_TimeTrialCheckpoint_0";
		description = "$STR_A3_CfgNotifications_TimeTrialCheckpoint_1";
		iconPicture = "\A3\ui_f\data\gui\cfg\CommunicationMenu\instructor_ca.paa";
	};
	class TimeTrialAborted: TimeTrialStarted
	{
		title = "$STR_A3_CfgNotifications_TimeTrialAborted_0";
		description = "$STR_A3_CfgNotifications_TimeTrialAborted_1";
		iconPicture = "\A3\ui_f\data\gui\cfg\Debriefing\endDefault_ca.paa";
	};
	class FiringRangeStarted: TimeTrialStarted
	{
		title = "$STR_A3_CfgNotifications_FiringRangeStarted_0";
		description = "$STR_A3_CfgNotifications_FiringRangeStarted_1";
		iconPicture = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
	};
	class FiringRangeEnded: TimeTrialStarted
	{
		title = "$STR_A3_CfgNotifications_FiringRangeEnded_0";
		description = "$STR_A3_CfgNotifications_FiringRangeEnded_1";
		iconPicture = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
	};
	class FiringRangeAborted: TimeTrialStarted
	{
		title = "$STR_A3_CfgNotifications_FiringRangeAborted_0";
		description = "$STR_A3_CfgNotifications_FiringRangeAborted_1";
		iconPicture = "\A3\ui_f\data\gui\cfg\Debriefing\endDefault_ca.paa";
	};
};
class CfgWrapperUI
{
	class Cursors
	{
		class Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\Curator_ca.paa";
			width = 32;
			height = 32;
			hotspotX = 0.1875;
			hotspotY = 0;
			color[] = {1,1,1,1};
		};
		class CuratorSelect: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorSelect_ca.paa";
			color[] = {1.0,1.0,1.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlace: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlace_ca.paa";
			color[] = {1.0,1.0,1.0,1.0};
			hotspotX = 0.1875;
			hotspotY = 0;
		};
		class CuratorPlaceMulti: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceMulti_ca.paa";
			color[] = {1.0,1.0,1.0,1.0};
			hotspotX = 0.1875;
			hotspotY = 0;
		};
		class CuratorPlaceDisabled: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceDisabled_ca.paa";
			color[] = {1.0,0.5,0.0,1.0};
			hotspotX = 0.1875;
			hotspotY = 0;
		};
		class CuratorPlaceWaypoint: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypoint_ca.paa";
			color[] = {0.5,1.0,0.5,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlaceWaypointMulti: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypointMulti_ca.paa";
			color[] = {0.5,1.0,0.5,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlaceWaypointCycle: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypointCycle_ca.paa";
			color[] = {0.5,1.0,0.5,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlaceWaypointDestroy: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypointDestroy_ca.paa";
			color[] = {1.0,0.0,0.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlaceWaypointDestroyMulti: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypointDestroyMulti_ca.paa";
			color[] = {1.0,0.0,0.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlaceWaypointGetIn: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypointGetIn_ca.paa";
			color[] = {0.5,1.0,0.5,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlaceWaypointGetInMulti: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypointGetInMulti_ca.paa";
			color[] = {0.5,1.0,0.5,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlaceWaypointHook: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypointHook_ca.paa";
			color[] = {0.5,1.0,0.5,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorPlaceWaypointHookMulti: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorPlaceWaypointHookMulti_ca.paa";
			color[] = {0.5,1.0,0.5,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorMove: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorMove_ca.paa";
			color[] = {0.0,1.0,1.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorMoveZ: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorMoveZ_ca.paa";
			color[] = {0.0,1.0,1.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorMoveSnap: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorMoveSnap_ca.paa";
			color[] = {0.0,1.0,1.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorMoveDisabled: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorMoveDisabled_ca.paa";
			color[] = {1.0,0.5,0.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorMoveIn: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorMoveIn_ca.paa";
			color[] = {0.0,1.0,1.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorMoveInDisabled: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorMoveInDisabled_ca.paa";
			color[] = {1.0,0.5,0.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorRotate: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorRotate_ca.paa";
			color[] = {0.0,1.0,1.0,1.0};
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
		class CuratorGroup: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorGroup_ca.paa";
			color[] = {1.0,1.0,1.0,1.0};
			hotspotX = 0.1875;
			hotspotY = 0;
		};
		class CuratorSync: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorSync_ca.paa";
			color[] = {1.0,1.0,1.0,1.0};
			hotspotX = 0.1875;
			hotspotY = 0;
		};
		class CuratorDisconnect: Curator
		{
			texture = "\a3\Ui_F_Curator\Data\CfgWrapperUI\Cursors\CuratorDisconnect_ca.paa";
			color[] = {1.0,0.5,0.0,1.0};
			hotspotX = 0.1875;
			hotspotY = 0;
		};
	};
};
class CfgDiaryPictures
{
	class Default
	{
		displayName = "$STR_DISP_DEFAULT";
		class Default
		{
			displayName = "$STR_EMPTY";
			texture = "";
		};
	};
	class Altis
	{
		displayName = "$STR_A3_MAP_ALTIS";
		class altis_Abdera
		{
			displayName = "$STR_A3_Abdera0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Abdera_ca.paa";
		};
		class altis_Aggelochori
		{
			displayName = "$STR_A3_Aggelochori0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Aggelochori_ca.paa";
		};
		class altis_AgiaTriada
		{
			displayName = "$STR_A3_AgiaTriada0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\AgiaTriada_ca.paa";
		};
		class altis_AgiosDionysios
		{
			displayName = "$STR_A3_AgiosDionysios0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\AgiosDionysios_ca.paa";
		};
		class altis_AgiosKonstantinos
		{
			displayName = "$STR_A3_AgiosKonstantinos0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\AgiosKonstantinos_ca.paa";
		};
		class altis_AgiosPetros
		{
			displayName = "$STR_A3_AgiosPetros0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\AgiosPetros_ca.paa";
		};
		class altis_Alikampos
		{
			displayName = "$STR_A3_Alikampos0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Alikampos_ca.paa";
		};
		class altis_Anthrakia
		{
			displayName = "$STR_A3_Anthrakia0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Anthrakia_ca.paa";
		};
		class altis_Athira
		{
			displayName = "$STR_A3_Athira0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Athira_ca.paa";
		};
		class altis_Delfinaki
		{
			displayName = "$STR_A3_Delfinaki0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Delfinaki_ca.paa";
		};
		class altis_Dorida
		{
			displayName = "$STR_A3_Dorida0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Dorida_ca.paa";
		};
		class altis_Ekali
		{
			displayName = "$STR_A3_Ekali0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Ekali_ca.paa";
		};
		class altis_Feres
		{
			displayName = "$STR_A3_Feres0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Feres_ca.paa";
		};
		class altis_Frini
		{
			displayName = "$STR_A3_Frini0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Frini_ca.paa";
		};
		class altis_Galati
		{
			displayName = "$STR_A3_Galati0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Galati_ca.paa";
		};
		class altis_Gravia
		{
			displayName = "$STR_A3_Gravia0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Gravia_ca.paa";
		};
		class altis_Chalkeia
		{
			displayName = "$STR_A3_Chalkeia0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Chalkeia_ca.paa";
		};
		class altis_Charkia
		{
			displayName = "$STR_A3_Charkia0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Charkia_ca.paa";
		};
		class altis_Ifestiona
		{
			displayName = "$STR_A3_Ifestiona0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Ifestiona_ca.paa";
		};
		class altis_Ioannina
		{
			displayName = "$STR_A3_Ioannina0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Ioannina_ca.paa";
		};
		class altis_Kalithea
		{
			displayName = "$STR_A3_Kalithea0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Kalithea_ca.paa";
		};
		class altis_Kalochori
		{
			displayName = "$STR_A3_Kalochori0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Kalochori_ca.paa";
		};
		class altis_Katalaki
		{
			displayName = "$STR_A3_Katalaki0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Katalaki_ca.paa";
		};
		class altis_Kavala
		{
			displayName = "$STR_A3_Kavala0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Kavala_ca.paa";
		};
		class altis_Kore
		{
			displayName = "$STR_A3_Kore0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Kore_ca.paa";
		};
		class altis_Koroni
		{
			displayName = "$STR_A3_Koroni0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Koroni_ca.paa";
		};
		class altis_Lakka
		{
			displayName = "$STR_A3_Lakka0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Lakka_ca.paa";
		};
		class altis_Molos
		{
			displayName = "$STR_A3_Molos0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Molos_ca.paa";
		};
		class altis_Negades
		{
			displayName = "$STR_A3_Negades0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Negades_ca.paa";
		};
		class altis_Neochori
		{
			displayName = "$STR_A3_Neochori0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Neochori_ca.paa";
		};
		class altis_Neri
		{
			displayName = "$STR_A3_Neri0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Neri_ca.paa";
		};
		class altis_Nifi
		{
			displayName = "$STR_A3_Nifi0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Nifi_ca.paa";
		};
		class altis_Oreokastro
		{
			displayName = "$STR_A3_Oreokastro0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Oreokastro_ca.paa";
		};
		class altis_Orino
		{
			displayName = "$STR_A3_Orino0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Orino_ca.paa";
		};
		class altis_Panagia
		{
			displayName = "$STR_A3_Panagia0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Panagia_ca.paa";
		};
		class altis_Panochori
		{
			displayName = "$STR_A3_Panochori0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Panochori_ca.paa";
		};
		class altis_Paros
		{
			displayName = "$STR_A3_Paros0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Paros_ca.paa";
		};
		class altis_Poliakko
		{
			displayName = "$STR_A3_Poliakko0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Poliakko_ca.paa";
		};
		class altis_Pyrgos
		{
			displayName = "$STR_A3_Pyrgos0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Pyrgos_ca.paa";
		};
		class altis_Rodopoli
		{
			displayName = "$STR_A3_Rodopoli0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Rodopoli_ca.paa";
		};
		class altis_Selakano
		{
			displayName = "$STR_A3_Selakano0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Selakano_ca.paa";
		};
		class altis_Sofia
		{
			displayName = "$STR_A3_Sofia0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Sofia_ca.paa";
		};
		class altis_Stavros
		{
			displayName = "$STR_A3_Stavros0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Stavros_ca.paa";
		};
		class altis_Syrta
		{
			displayName = "$STR_A3_Syrta0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Syrta_ca.paa";
		};
		class altis_Telos
		{
			displayName = "$STR_A3_Telos0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Telos_ca.paa";
		};
		class altis_Therisa
		{
			displayName = "$STR_A3_Therisa0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Therisa_ca.paa";
		};
		class altis_Topolia
		{
			displayName = "$STR_A3_Topolia0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Topolia_ca.paa";
		};
		class altis_Zaros
		{
			displayName = "$STR_A3_Zaros0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\altis\Zaros_ca.paa";
		};
	};
	class Stratis
	{
		displayName = "$STR_A3_CfgWorlds_Stratis0";
		class stratis_AgiaMarina
		{
			displayName = "$STR_A3_Agia_Marina0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\stratis\AgiaMarina_ca.paa";
		};
		class stratis_AirStationMike26
		{
			displayName = "$STR_A3_AirStation0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\stratis\AirStationMike26_ca.paa";
		};
		class stratis_CampMaxwell
		{
			displayName = "$STR_A3_CampMaxwell0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\stratis\CampMaxwell_ca.paa";
		};
		class stratis_CampRogain
		{
			displayName = "$STR_A3_CampRogain0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\stratis\CampRogain_ca.paa";
		};
		class stratis_CampTempest
		{
			displayName = "$STR_A3_CampTempest10";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\stratis\CampTempest_ca.paa";
		};
		class stratis_Girna
		{
			displayName = "$STR_A3_Girna0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\stratis\Girna_ca.paa";
		};
		class stratis_KaminoFiringRange
		{
			displayName = "$STR_A3_SniperSchool0";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\stratis\KaminoFiringRange_ca.paa";
		};
		class stratis_stratisAirBase
		{
			displayName = "$STR_A3_NatoBase10";
			texture = "\a3\Ui_F_Curator\Data\CfgDiaryImages\stratis\stratisAirBase_ca.paa";
		};
	};
};
class CfgPostProcessTemplates
{
	class Default
	{
		displayName = "$STR_A3_CfgPostProcessTemplates_Default_0";
		colorCorrections[] = {1,1,0,{0,0,0,0},{1,1,1,1},{0,0,0,0}};
		filmGrain[] = {0,0,0,0,0};
	};
	class EastWind
	{
		displayName = "$STR_A3_CfgPostProcessTemplates_Survive_0";
		colorCorrections[] = {1,1.08,-0.06,{0.5,0.5,0.5,0},{1.0,1.0,1.0,1.21},{0.09,0.09,0.09,0.0}};
	};
	class RealIsBrown
	{
		displayName = "$STR_A3_CfgPostProcessTemplates_RealIsBrown_0";
		colorCorrections[] = {1,1,0,{0.1,0.2,0.3,-0.5},{1,1,1,0.4},{0.5,0.2,0.0,1.0}};
		filmGrain[] = {0.04,1,1,0,1};
	};
	class BlackAndWhite
	{
		displayName = "$STR_A3_CfgPostProcessTemplates_BlackAndWhite_0";
		colorCorrections[] = {1,1,0,{1,1,1,0},{1,1,1,0},{0.75,0.25,0,1.0}};
		filmGrain[] = {0.04,1,1,0,1};
	};
	class Mediterranean
	{
		displayName = "$STR_A3_CfgPostProcessTemplates_Mediterranean_0";
		colorCorrections[] = {1,1.14,-0.04,{1,0,0,-0.07},{1,1,1,0.8},{1,0,0,1}};
	};
};
class CfgDiary
{
	class Icons
	{
		playerLogic = "\a3\UI_F_Curator\Data\CfgDiary\playerLogic_ca.paa";
		playerBriefLogic = "\a3\UI_F_Curator\Data\CfgDiary\playerBriefLogic_ca.paa";
	};
};
class CfgDebriefing
{
	class RespawnRoundsWon
	{
		title = "$STR_A3_CfgDebriefing_RespawnRoundsWon_0";
		subtitle = "";
		picture = "\a3\Ui_f\data\GUI\Cfg\Hints\Commanding_ca.paa";
	};
	class endDeath;
	class RespawnRoundsLost: endDeath
	{
		title = "$STR_A3_CfgDebriefing_RespawnRoundsLost_0";
		subtitle = "";
	};
	class RespawnRoundsTie
	{
		title = "$STR_A3_CfgDebriefing_RespawnRoundsTie_0";
		subtitle = "";
		picture = "\a3\Ui_f\data\GUI\Cfg\Hints\Rules_ca.paa";
	};
	class SideWon
	{
		title = "$STR_A3_CfgDebriefing_SideWon_0";
	};
	class SideLost
	{
		title = "$STR_A3_CfgDebriefing_SideLost_0";
	};
	class GroupWon
	{
		title = "$STR_A3_CfgDebriefing_GroupWon_0";
	};
	class GroupLost
	{
		title = "$STR_A3_CfgDebriefing_GroupLost_0";
	};
	class PlayerWon
	{
		title = "$STR_A3_CfgDebriefing_PlayerWon_0";
	};
	class PlayerLost
	{
		title = "$STR_A3_CfgDebriefing_PlayerLost_0";
	};
};
class CfgIngameUI
{
	class Compass
	{
		left = "0.5 - 8 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
		top = "safezoneY + 1.6 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		width = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
		height = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		shadow = 0;
		texture0 = "A3\ui_f_curator\data\cfgIngameUI\compass\texture0_ca.paa";
		texture90 = "A3\ui_f_curator\data\cfgIngameUI\compass\texture90_ca.paa";
		texture180 = "A3\ui_f_curator\data\cfgIngameUI\compass\texture180_ca.paa";
		texture270 = "A3\ui_f_curator\data\cfgIngameUI\compass\texture270_ca.paa";
		color[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		bgColor[] = {0,0,0,0};
	};
	class FLIRModeNames
	{
		FLIRModeName[] = {"WHOT","BHOT","WHOT","BHOT","WHOT","BHOT","WHOT","WHOT"};
	};
	class FLIRModeColors
	{
		FLIRModeColor[] = {{{0.0,0.0,0.0,1.0},{1.0,1.0,1.0,1.0}},{{1.0,1.0,1.0,1.0},{0.0,0.0,0.0,1.0}},{{0.0,0.13,0.0,1.0},{0.0,1.0,0.0,1.0}},{{0.0,1.0,0.0,1.0},{0.0,0.13,0.0,1.0}},{{0.15,0.07,0.0,1.0},{1.0,0.4,0.0,1.0}},{{1.0,0.4,0.0,1.0},{0.15,0.07,0.0,1.0}},{{0.29,0.02,0.15,1.0},{1.0,0.94,0.98,1.0}},{{0.0,0.16,0.16,1.0},{1.0,0.7,0.7,1.0}}};
	};
};
class CfgMarkers
{
	class KIA
	{
		name = "$STR_A3_CfgMarkers_KIA_0";
		icon = "\a3\Ui_F_Curator\Data\CfgMarkers\kia_ca.paa";
		color[] = {0,0,0,1};
		shadow = 0;
		scope = 1;
		size = 29;
	};
	class Minefield
	{
		name = "$STR_A3_CfgMarkers_Minefield_0";
		icon = "\a3\Ui_F_Curator\Data\CfgMarkers\minefield_ca.paa";
		color[] = {0.9,0,0,1};
		shadow = 0;
		scope = 1;
		size = 29;
		showEditorMarkerColor = 1;
	};
	class MinefieldAP: Minefield
	{
		name = "$STR_A3_CfgMarkers_MinefieldAP_0";
		icon = "\a3\Ui_F_Curator\Data\CfgMarkers\minefieldAP_ca.paa";
	};
};
class CfgHints
{
	class Default{};
	class Curator
	{
		displayName = "$STR_A3_Curator";
		logicalOrder = 23;
		class Curator
		{
			displayName = "$STR_A3_CfgHints_Curator_Curator_displayName";
			description = "$STR_A3_CfgHints_Curator_Curator_description";
			tip = "$STR_A3_CfgHints_Curator_Curator_tip";
			arguments[] = {"gettext (configfile >> ""CfgCurator"" >> ""icon"")"};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class Ping
		{
			displayName = "$STR_A3_CfgHints_Curator_Ping_displayName";
			description = "$STR_A3_CfgHints_Curator_Ping_description";
			tip = "$STR_A3_CfgHints_Curator_Ping_tip";
			arguments[] = {{{"curatorInterface"}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class OpenInterface
		{
			displayName = "$STR_A3_CfgHints_Curator_OpenInterface_displayName";
			description = "$STR_A3_CfgHints_Curator_OpenInterface_description";
			tip = "";
			arguments[] = {{{"curatorInterface"}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class Camera
		{
			displayName = "$STR_A3_CfgHints_Curator_Camera_displayName";
			description = "$STR_A3_CfgHints_Curator_Camera_description";
			tip = "$STR_A3_CfgHints_Curator_Camera_tip";
			arguments[] = {{{17}},{{30}},{{31}},{{32}},{{16}},{{44}},{{42}},{{"CuratorMoveCamTo"}},{{"personView"}},{{57}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class Interface
		{
			displayName = "$STR_A3_CfgHints_Curator_Interface_displayName";
			description = "$STR_A3_CfgHints_Curator_Interface_description";
			tip = "";
			arguments[] = {{{"diary"}},{{"nightVision"}},{{"watch"}},{{"compass"}},{{14}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class Map
		{
			displayName = "$STR_A3_CfgHints_Curator_Map_displayName";
			description = "$STR_A3_CfgHints_Curator_Map_description";
			tip = "";
			arguments[] = {{{"showMap"}},{{"hideMap"}},{{1}},{{20}},"gettext (configfile >> ""cfgCurator"" >> ""drawCamera"" >> ""2D"" >> ""texture"")"};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class EntitySelect
		{
			displayName = "$STR_A3_CfgHints_Curator_EntitySelect_displayName";
			description = "$STR_A3_CfgHints_Curator_EntitySelect_description";
			tip = "";
			arguments[] = {{{"CuratorMultipleMod"}},{{42}},"gettext (configfile >> ""cfgCurator"" >> ""drawWaypoint"" >> ""3D"" >> ""texture"")"};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class EntityEdit
		{
			displayName = "$STR_A3_CfgHints_Curator_EntityEdit_displayName";
			description = "$STR_A3_CfgHints_Curator_EntityEdit_description";
			tip = "$STR_A3_CfgHints_Curator_EntityEdit_tip";
			arguments[] = {{{"CuratorMoveY"}},{{"CuratorRotateMod"}},"gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorMove"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorMove"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML","gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorMoveZ"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorMoveZ"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML","gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorMoveIn"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorMoveIn"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML","gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorRotate"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorRotate"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML","gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorMoveDisabled"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorMoveDisabled"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML"};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class WPPlace
		{
			displayName = "$STR_A3_CfgHints_Curator_WPPlace_displayName";
			description = "$STR_A3_CfgHints_Curator_WPPlace_description";
			tip = "";
			arguments[] = {{{"CuratorMultipleMod"}},"gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorPlaceWaypoint"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorPlaceWaypoint"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML","gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorPlaceWaypointGetIn"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorPlaceWaypointGetIn"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML","gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorPlaceWaypointDestroy"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorPlaceWaypointDestroy"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML","gettext (configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorPlaceWaypointCycle"" >> ""texture"")","((configfile >> ""cfgWrapperUI"" >> ""Cursors"" >> ""CuratorPlaceWaypointCycle"" >> ""color"") call BIS_fnc_colorConfigToRGBA) call BIS_fnc_colorRGBAtoHTML",{{"CuratorContentWaypoint"}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class Attributes
		{
			displayName = "$STR_A3_CfgHints_Curator_Attributes_displayName";
			description = "$STR_A3_CfgHints_Curator_Attributes_description";
			tip = "$STR_A3_CfgHints_Curator_Attributes_tip";
			arguments[] = {};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class EntityConnect
		{
			displayName = "$STR_A3_CfgHints_Curator_EntityConnect_displayName";
			description = "$STR_A3_CfgHints_Curator_EntityConnect_description";
			tip = "";
			arguments[] = {{{"CuratorGroupMod"}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class EntityEditAdvanced
		{
			displayName = "$STR_A3_CfgHints_Curator_EntityEditAdvanced_displayName";
			description = "$STR_A3_CfgHints_Curator_EntityEditAdvanced_description";
			tip = "";
			arguments[] = {{{"CuratorGetOut"}},{{"CuratorDestroy"}},{{"CuratorDelete"}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class EntityPlace
		{
			displayName = "$STR_A3_CfgHints_Curator_EntityPlace_displayName";
			description = "$STR_A3_CfgHints_Curator_EntityPlace_description";
			tip = "";
			arguments[] = {{{"CuratorMultipleMod"}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class RemoteControl
		{
			displayName = "$STR_A3_CfgHints_Curator_RemoteControl_displayName";
			description = "$STR_A3_CfgHints_Curator_RemoteControl_description";
			tip = "";
			arguments[] = {{{"curatorInterface"}}};
			image = "\a3\ui_f\data\gui\cfg\hints\Zeus_ca.paa";
		};
		class PlaceOrdnance
		{
			displayName = "$STR_A3_CfgHints_Curator_PlaceOrdnance_displayName";
			description = "$STR_A3_CfgHints_Curator_PlaceOrdnance_description";
			tip = "$STR_A3_CfgHints_Curator_PlaceOrdnance_tip";
			arguments[] = {};
			image = "\a3\ui_f_curator\data\CfgHints\PlaceOrdnance_ca.paa";
		};
		class PlaceMines
		{
			displayName = "$STR_A3_CfgHints_Curator_PlaceMines_displayName";
			description = "$STR_A3_CfgHints_Curator_PlaceMines_description";
			tip = "$STR_A3_CfgHints_Curator_PlaceMines_tip";
			arguments[] = {{{"curatorDestroy"}}};
			image = "\a3\ui_f_curator\data\CfgHints\PlaceMines_ca.paa";
		};
	};
	class Tactics
	{
		class RespawnCamps
		{
			displayName = "$STR_A3_CfgHints_Tactics_RespawnCamps_displayName";
			description = "$STR_A3_CfgHints_Tactics_RespawnCamps_description";
			tip = "$STR_A3_CfgHints_Tactics_RespawnCamps_tip";
			arguments[] = {};
			image = "\A3\Ui_f\data\GUI\Cfg\Hints\Miss_icon_ca.paa";
		};
	};
};
class CfgSounds
{
	class RscDisplayCurator_visionMode
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\visionMode",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_error01
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\error01",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_error02
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\error02",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_error03
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\error03",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_error04
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\error04",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_error05
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\error05",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping01
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping01",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping02
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping02",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping03
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping03",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping04
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping04",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping05
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping05",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping06
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping06",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping07
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping07",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping08
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping08",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping09
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping09",1.0,1};
		titles[] = {};
	};
	class RscDisplayCurator_ping10
	{
		sound[] = {"\a3\Ui_F_Curator\Data\Sound\CfgSound\ping10",1.0,1};
		titles[] = {};
	};
};
class CfgUIColors
{
	class GUI
	{
		class Presets
		{
			class PresetZeus
			{
				displayName = "$STR_A3_Curator";
				class Variables
				{
					BCG_RGB[] = {0.31,0.78,0.78,0.8};
					TITLETEXT_RGB[] = {1,1,1,1};
				};
			};
		};
	};
};
class CfgDefaultKeysPresets
{
	class Arma2
	{
		class Mappings
		{
			curatorInterface[] = {21};
			CuratorMultipleMod[] = {29};
			CuratorRotateMod[] = {42};
			CuratorMoveY[] = {56};
			CuratorDelete[] = {211};
			CuratorDestroy[] = {207};
			CuratorGetOut[] = {34};
			CuratorContentWaypoint[] = {56};
			CuratorMoveCamTo[] = {33};
			CuratorLockCameraTo[] = {{29,33}};
			CuratorGroupMod[] = {29};
			CuratorLevelObject[] = {45};
			CuratorCollapseParent[] = {46};
			curatorNightvision[] = {49};
			curatorPersonView[] = {156};
			curatorPingView[] = {57};
			curatorToggleInterface[] = {14};
			curatorToggleEdit[] = {18};
			curatorToggleCreate[] = {19};
			curatorMapTextures[] = {20};
			curatorCompass[] = {37};
			curatorWatch[] = {24};
		};
	};
};
class UserActionGroups
{
	class Curator
	{
		name = "$STR_A3_Curator";
		group[] = {"curatorInterface","curatorRotateMod","curatorMoveY","curatorDelete","curatorDestroy","curatorGetOut","curatorContentWaypoint","curatorMoveCamTo","curatorLockCameraTo","curatorLevelObject","curatorGroupMod","curatorMultipleMod","CuratorCollapseParent","curatorNightvision","curatorPersonView","curatorPingView","curatorToggleInterface","curatorToggleEdit","curatorToggleCreate","curatorMapTextures","curatorCompass","curatorWatch"};
	};
};
class UserActionsConflictGroups
{
	class ActionGroups
	{
		curator[] = {"curatorInterface","curatorRotateMod","curatorMoveY","curatorDelete","curatorDestroy","curatorGetOut","curatorContentWaypoint","curatorMoveCamTo","curatorLockCameraTo","curatorLevelObject","curatorGroupMod","curatorMultipleMod","CuratorCollapseParent","curatorNightvision","curatorPersonView","curatorPingView","curatorToggleInterface","curatorToggleEdit","curatorToggleCreate","curatorMapTextures","curatorCompass","curatorWatch"};
	};
	class CollisionGroups
	{
		curator[] = {"curator"};
	};
	class Exceptions
	{
		curator[] = {"curatorMoveY","curatorContentWaypoint","curatorLockCameraTo","curatorGroupMod","curatorMultipleMod"};
	};
};
class RscChatListDefault;
class RscChatListCurator: RscChatListDefault
{
	colorBackground[] = {0,0,0,0.3};
	x = "13 * 							(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
	y = "(profilenamespace getvariable [""IGUI_GRID_CHAT_Y"",		(safezoneY + safezoneH - 10.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
	w = "(profilenamespace getvariable [""IGUI_GRID_CHAT_W"",		(20 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
	h = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	rows = "(profilenamespace getvariable [""IGUI_GRID_CHAT_H"",		(5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))]) / 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
};
class CfgScriptPaths
{
	CuratorDisplays = "A3\ui_f_curator\UI\displays\";
	CuratorCommon = "A3\ui_f_curator\UI\RscCommon\";
	CuratorTitles = "A3\ui_f_curator\UI\RscTitles\";
	BootcampDisplays = "A3\ui_f_curator\UI\displays\";
	BootcampCommon = "A3\ui_f_curator\UI\RscCommon\";
	BootcampTitles = "A3\ui_f_curator\UI\RscTitles\";
};
class IGUIBack;
class RscStandardDisplay;
class RscPicture;
class RscCombo;
class RscMapControl
{
	class Waypoint;
};
class RscText;
class RscEdit;
class RscStructuredText;
class RscTitle;
class RscFrame;
class RscSlider;
class RscXSliderH;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscListbox
{
	class ListScrollBar;
};
class RscXListbox;
class RscListNBox;
class RscToolbox;
class RscTree;
class RscHTML;
class RscActiveText;
class RscActivePicture;
class RscActivePictureKeepAspect;
class RscButton;
class RscButtonMenu;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscButtonSearch;
class RscMap
{
	class Controls;
};
class RscMissionStatus;
class RscNotificationArea;
class RscVignette;
class RscButtonMenuSteam;
class RscProgress;
class RscCheckbox;
class RscToolboxButton: RscToolbox
{
	font = "RobotoCondensedLight";
	color[] = {1,1,1,1};
	colorTextSelect[] = {0,0,0,1};
	colorSelectedBg[] = {1,1,1,1};
};
class RscAttributeOwners: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeOwners"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 18708;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 17410;
			text = "$STR_A3_RscAttributeOwners_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 17408;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class TabSide: RscButton
		{
			colorDisabled[] = {1,1,1,1};
			colorFocused[] = {1,1,1,0.1};
			colorBackground[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0.3};
			colorBackgroundDisabled[] = {1,1,1,0.1};
			period = 0;
			periodFocus = 0;
			periodOver = 0;
			shadow = 0;
			font = "RobotoCondensedLight";
			idc = 18010;
			text = "SIDES";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "8.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TabGroup: TabSide
		{
			idc = 18011;
			text = "GROUP";
			x = "8.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TabUnit: TabSide
		{
			idc = 18012;
			text = "PLAYER";
			x = "17.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "8.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BLUFOR: RscActivePicture
		{
			idc = 17608;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
			x = "7.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_WEST";
		};
		class OPFOR: BLUFOR
		{
			idc = 17609;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_east_ca.paa";
			x = "10.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_EAST";
		};
		class Independent: BLUFOR
		{
			idc = 17610;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_guer_ca.paa";
			x = "13.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_guerrila";
		};
		class Civilian: BLUFOR
		{
			idc = 17611;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_civ_ca.paa";
			x = "16.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Civilian";
		};
		class GroupList: RscCombo
		{
			idc = 18508;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "22 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class UnitList: RscCombo
		{
			idc = 18509;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "22 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeOwners2: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeOwners2"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 19608;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "5.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title1: RscText
		{
			idc = 18310;
			text = "$STR_A3_RscAttributeOwners_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Title2: Title1
		{
			idc = 18309;
			text = "$STR_A3_RscAttributeOwners_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background1: RscText
		{
			idc = 18308;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Background2: Background1
		{
			idc = 18311;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class BLUFOR1: RscActivePicture
		{
			idc = 18508;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
			x = "12.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_WEST";
		};
		class BLUFOR2: BLUFOR1
		{
			idc = 18512;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
			x = "12.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.85 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_WEST";
		};
		class OPFOR1: BLUFOR1
		{
			idc = 18509;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_east_ca.paa";
			x = "15.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_EAST";
		};
		class OPFOR2: OPFOR1
		{
			idc = 18513;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_east_ca.paa";
			x = "15.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.85 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_EAST";
		};
		class Independent1: BLUFOR1
		{
			idc = 18510;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_guer_ca.paa";
			x = "18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_guerrila";
		};
		class Independent2: Independent1
		{
			idc = 18514;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_guer_ca.paa";
			x = "18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.85 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_guerrila";
		};
		class Civilian1: BLUFOR1
		{
			idc = 18511;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_civ_ca.paa";
			x = "21.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Civilian";
		};
		class Civilian2: Civilian1
		{
			idc = 18515;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\side_civ_ca.paa";
			x = "21.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.85 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Civilian";
		};
	};
};
class RscAttributeRank: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeRank"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 14769;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 13471;
			text = "$STR_DISP_ARCUNIT_RANK";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 13469;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Private: RscActivePicture
		{
			idc = 13669;
			text = "\a3\Ui_f\data\GUI\Cfg\Ranks\private_gs.paa";
			x = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Private";
		};
		class Corporal: Private
		{
			idc = 13670;
			text = "\a3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa";
			x = "13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Corporal";
		};
		class Sergeant: Private
		{
			idc = 13671;
			text = "\a3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa";
			x = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Sergeant";
		};
		class Lieutenant: Private
		{
			idc = 13672;
			text = "\a3\Ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa";
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Lieutenant";
		};
		class Captain: Private
		{
			idc = 13673;
			text = "\a3\Ui_f\data\GUI\Cfg\Ranks\captain_gs.paa";
			x = "19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Captain";
		};
		class Major: Private
		{
			idc = 13674;
			text = "\a3\Ui_f\data\GUI\Cfg\Ranks\major_gs.paa";
			x = "21 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Major";
		};
		class Colonel: Private
		{
			idc = 13675;
			text = "\a3\Ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa";
			x = "23 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Colonel";
		};
	};
};
class RscAttributeUnitPos: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeUnitPos"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 20276;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 18978;
			text = "$STR_A3_RscAttributeUnitPos_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 18976;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Down: RscActivePicture
		{
			idc = 19176;
			text = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_prone_ca.paa";
			x = "14.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeUnitPos_Down_tooltip";
		};
		class Crouch: Down
		{
			idc = 19177;
			text = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_crouch_ca.paa";
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeUnitPos_Crouch_tooltip";
		};
		class Up: Down
		{
			idc = 19178;
			text = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_stand_ca.paa";
			x = "19.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeUnitPos_Up_tooltip";
		};
		class Auto: Down
		{
			idc = 19179;
			text = "\a3\ui_f_curator\Data\default_ca.paa";
			x = "24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeUnitPos_Auto_tooltip";
		};
	};
};
class RscAttributeDamage: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeDamage"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 17802;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 16502;
			text = "$STR_disp_arcunit_health";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscXSliderH
		{
			idc = 17402;
			x = "10.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeFuel: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeFuel"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 14774;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 13474;
			text = "$STR_disp_arcunit_fuel";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscXSliderH
		{
			idc = 14374;
			x = "10.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeSide: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeSide"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 32300;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 31002;
			text = "$STR_disp_arcunit_side";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 31000;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class BLUFOR: RscActivePicture
		{
			idc = 31200;
			text = "\a3\Ui_f\data\Map\Markers\NATO\b_unknown.paa";
			x = "12.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_WEST";
		};
		class OPFOR: BLUFOR
		{
			idc = 31201;
			text = "\a3\Ui_f\data\Map\Markers\NATO\o_unknown.paa";
			x = "15.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_EAST";
		};
		class Independent: BLUFOR
		{
			idc = 31202;
			text = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
			x = "18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_guerrila";
		};
		class Civilian: BLUFOR
		{
			idc = 31203;
			text = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
			x = "21.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Civilian";
		};
	};
};
class RscAttributeTaskState: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTaskState"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 42300;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 41002;
			text = "$STR_A3_RscAttributeTaskState_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 41000;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Assigned: RscActivePicture
		{
			idc = 41200;
			text = "\a3\3DEN\Data\Attributes\TaskStates\assigned_ca.paa";
			x = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_a3_cfgvehicles_moduletasksetstate_f_arguments_state_values_assigned_0";
		};
		class Created: Assigned
		{
			idc = 41201;
			text = "\a3\3DEN\Data\Attributes\TaskStates\created_ca.paa";
			x = "14 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_a3_cfgvehicles_moduletasksetstate_f_arguments_state_values_created_0";
		};
		class Succeeded: Assigned
		{
			idc = 41202;
			text = "\a3\3DEN\Data\Attributes\TaskStates\succeeded_ca.paa";
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_a3_cfgvehicles_moduletasksetstate_f_arguments_state_values_succeeded_0";
		};
		class Failed: Assigned
		{
			idc = 41203;
			text = "\a3\3DEN\Data\Attributes\TaskStates\failed_ca.paa";
			x = "20 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_a3_cfgvehicles_moduletasksetstate_f_arguments_state_values_failed_0";
		};
		class Canceled: Assigned
		{
			idc = 41204;
			text = "\a3\3DEN\Data\Attributes\TaskStates\canceled_ca.paa";
			x = "23 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_a3_cfgvehicles_moduletasksetstate_f_arguments_state_values_canceled_0";
		};
	};
};
class RscAttributeTaskDescription: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTaskDescription"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 39391;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "9.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class TitleTemplate: RscText
		{
			idc = 38094;
			text = "$STR_A3_RscAttributeTaskDescription_TitleTemplate";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class EditTemplate: RscCombo
		{
			idc = 39191;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TitleTitle: RscText
		{
			idc = 38093;
			text = "$STR_A3_RscAttributeTaskDescription_TitleTitle";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class EditTitle: RscEdit
		{
			idc = 38491;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class TitleMarker: RscText
		{
			idc = 38091;
			text = "$STR_A3_RscAttributeTaskDescription_TitleMarker";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class EditMarker: RscEdit
		{
			idc = 38492;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class TitleDescription: RscText
		{
			idc = 38092;
			text = "$STR_A3_RscAttributeTaskDescription_TitleDescription";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "3.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class EditDescription: RscEdit
		{
			style = 16;
			idc = 38493;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "4.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
	};
};
class RscAttributeSkiptime: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeSkiptime"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 22438;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 21138;
			text = "$STR_A3_RscAttributeSkiptime_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 21140;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Value: RscXSliderH
		{
			idc = 22038;
			x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Time: RscText
		{
			style = 2;
			idc = 21139;
			x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Skiptime: RscText
		{
			style = 2;
			idc = 21141;
			x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeSound: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeSound"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 16706;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 15406;
			text = "$STR_A3_RscAttributeSound_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscListbox
		{
			idc = 16506;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeMusic: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeMusic"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 16593;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "13 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 15293;
			text = "$STR_A3_RscAttributeMusic_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscTree
		{
			idc = 16393;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "12 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeMusicVolume: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeMusicVolume"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 28956;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 27656;
			text = "$STR_A3_RscAttributeMusicVolume_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscXSliderH
		{
			idc = 28556;
			x = "10.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeGenericRadio: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeGenericRadio"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 30451;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 29151;
			text = "$STR_A3_RscAttributeGenericRadio_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscListbox
		{
			idc = 29651;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeDiaryRecord: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeDiaryRecord"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 28471;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "16 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class TemplateTitle: RscText
		{
			idc = 27175;
			text = "$STR_A3_RscAttributeDiaryRecord_TemplateTitle";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class TemplateList: RscCombo
		{
			idc = 28271;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TitleTitle: RscText
		{
			idc = 27173;
			text = "$STR_A3_CfgVehicles_ModuleTaskSetDescription_F_Arguments_Title_0";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class TitleEdit: RscEdit
		{
			idc = 27571;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class DescriptionTitle: RscText
		{
			idc = 27172;
			text = "$STR_A3_CfgVehicles_ModuleTaskSetDescription_F_Arguments_Description_0";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class DescriptionEdit: RscEdit
		{
			style = 16;
			idc = 27573;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "3.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "4.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class ImageTitle: RscText
		{
			idc = 27171;
			text = "$STR_A3_RscAttributeDiaryRecord_ImageTitle";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class ImagePreview: RscPicture
		{
			idc = 27371;
			text = "#(argb,8,8,3)color(0,0,0,0)";
			x = "19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ImageTree: RscTree
		{
			idc = 27174;
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "9.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeOvercast: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeOvercast"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 22492;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 21194;
			text = "$STR_A3_RscAttributeOvercast_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 21192;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Value000: RscActivePicture
		{
			idc = 21392;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\clear_ca.paa";
			x = "10.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeOvercast_Value000_tooltip";
		};
		class Value025: Value000
		{
			idc = 21393;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\cloudly_ca.paa";
			x = "13.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeOvercast_Value025_tooltip";
		};
		class Value050: Value000
		{
			idc = 21394;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\overcast_ca.paa";
			x = "16.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeOvercast_Value050_tooltip";
		};
		class Value075: Value000
		{
			idc = 21395;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\rainy_ca.paa";
			x = "19.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeOvercast_Value075_tooltip";
		};
		class Value100: Value000
		{
			idc = 21396;
			text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\stormy_ca.paa";
			x = "22.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeOvercast_Value100_tooltip";
		};
	};
};
class RscAttributeFog: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeFog"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 13104;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 11804;
			text = "$STR_A3_RscAttributeFog_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscXSliderH
		{
			idc = 12704;
			x = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeFog_Value_tooltip";
		};
	};
};
class RscAttributePostprocess: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributePostprocess"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 29706;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			style = 16;
			idc = 28406;
			text = "$STR_A3_RscAttributePostprocess_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscListbox
		{
			idc = 28906;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeGroupID: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeGroupID"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 19279;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 17979;
			text = "$STR_A3_RscAttributeGroupID_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscEdit
		{
			idc = 18379;
			x = "10.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeFormation: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeFormation"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 24616;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 23318;
			text = "$STR_disp_arcwp_form";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 23316;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Wedge: RscActivePicture
		{
			idc = 23518;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\wedge_ca.paa";
			x = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_wedge";
		};
		class Vee: Wedge
		{
			idc = 23521;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\vee_ca.paa";
			x = "14.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_vee";
		};
		class Line: Wedge
		{
			idc = 23522;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\line_ca.paa";
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_line";
		};
		class Column: Wedge
		{
			idc = 23516;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\column_ca.paa";
			x = "19.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_column";
		};
		class File: Wedge
		{
			idc = 23523;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\file_ca.paa";
			x = "22 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_file";
		};
		class Stag_Column: Wedge
		{
			idc = 23517;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\stag_column_ca.paa";
			x = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_staggered";
		};
		class Ech_Left: Wedge
		{
			idc = 23519;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\ech_left_ca.paa";
			x = "14.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_echl";
		};
		class Ech_Right: Wedge
		{
			idc = 23520;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\ech_right_ca.paa";
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_echr";
		};
		class Diamond: Wedge
		{
			idc = 23524;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\diamond_ca.paa";
			x = "19.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_diamond";
		};
		class Default: Wedge
		{
			idc = 23525;
			text = "\a3\ui_f_curator\Data\default_ca.paa";
			x = "22.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_no_change";
		};
	};
};
class RscAttributeBehaviour: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeBehaviour"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 24569;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 23271;
			text = "$STR_disp_arcwp_semaphore";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 23269;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Safe: RscActivePicture
		{
			idc = 23471;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeBehaviour\safe_ca.paa";
			x = "13.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_safe";
		};
		class Aware: Safe
		{
			idc = 23474;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeBehaviour\aware_ca.paa";
			x = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_aware";
		};
		class Combat: Safe
		{
			idc = 23475;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeBehaviour\combat_ca.paa";
			x = "18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_combat";
		};
		class Stealth: Safe
		{
			idc = 23469;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeBehaviour\stealth_ca.paa";
			x = "21 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_stealth";
		};
		class Default: Safe
		{
			idc = 23470;
			text = "\a3\ui_f_curator\Data\default_ca.paa";
			x = "24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_combat_unchanged";
		};
	};
};
class RscAttributeLock: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeLock"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 14725;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 13427;
			text = "$STR_disp_arcunit_lock";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			style = 2;
			idc = 13425;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
			colorBackground[] = {1,1,1,0.1};
		};
		class Locked: RscActivePicture
		{
			idc = 13627;
			text = "\a3\Modules_f\data\iconLock_ca.paa";
			x = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_vehicle_locked";
		};
		class Unlocked: Locked
		{
			idc = 13630;
			text = "\a3\Modules_f\data\iconUnlock_ca.paa";
			x = "19.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_vehicle_unlocked";
		};
	};
};
class RscAttributeMarkerText: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeMarkerText"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 26586;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 25286;
			text = "$STR_DISP_ARCMARK_TEXT";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscEdit
		{
			idc = 25686;
			x = "10.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeMarkerColor: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeMarkerColor"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 28633;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 27335;
			text = "$STR_DISP_ARCMARK_COLOR";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 27333;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Color1: RscActivePicture
		{
			shadow = 0;
			idc = 27535;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color2: Color1
		{
			idc = 27538;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color3: Color1
		{
			idc = 27533;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color4: Color1
		{
			idc = 27534;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color5: Color1
		{
			idc = 27536;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color6: Color1
		{
			idc = 27537;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "21 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color7: Color1
		{
			idc = 27539;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "23 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color8: Color1
		{
			idc = 27540;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color9: Color1
		{
			idc = 27541;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color10: Color1
		{
			idc = 27542;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color11: Color1
		{
			idc = 27543;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color12: Color1
		{
			idc = 27544;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color13: Color1
		{
			idc = 27545;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "21 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Color14: Color1
		{
			idc = 27546;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = "23 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeRespawnVehicle: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeRespawnVehicle"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 36063;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 34765;
			text = "$STR_A3_RscAttributeRespawnVehicle_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 34763;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class West: RscActivePicture
		{
			idc = 34964;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnVehicle\west_ca.paa";
			x = "10.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeRespawnVehicle_West_tooltip";
		};
		class East: West
		{
			idc = 34965;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnVehicle\east_ca.paa";
			x = "13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeRespawnVehicle_East_tooltip";
		};
		class Guer: West
		{
			idc = 34966;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnVehicle\guer_ca.paa";
			x = "15.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeRespawnVehicle_Guer_tooltip";
		};
		class Civ: West
		{
			idc = 34967;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnVehicle\civ_ca.paa";
			x = "18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeRespawnVehicle_Civ_tooltip";
		};
		class Start: West
		{
			idc = 34963;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnVehicle\start_ca.paa";
			x = "20.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeRespawnVehicle_Start_tooltip";
		};
		class Disabled: West
		{
			idc = 34968;
			text = "\a3\Ui_F_Curator\Data\default_ca.paa";
			x = "24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_disabled";
		};
	};
};
class RscAttributeRespawnPosition: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeRespawnPosition"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 39809;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 38511;
			text = "$STR_A3_RscAttributeRespawnPosition_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			style = 2;
			idc = 38509;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
			colorBackground[] = {1,1,1,0.1};
		};
		class West: RscActivePicture
		{
			idc = 38710;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\west_ca.paa";
			x = "10.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_WEST";
		};
		class East: West
		{
			idc = 38711;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\east_ca.paa";
			x = "13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_EAST";
		};
		class Guer: West
		{
			idc = 38712;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\guer_ca.paa";
			x = "15.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_guerrila";
		};
		class Civ: West
		{
			idc = 38713;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeRespawnPosition\civ_ca.paa";
			x = "18 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Civilian";
		};
		class Disabled: West
		{
			idc = 38714;
			text = "\a3\Ui_F_Curator\Data\default_ca.paa";
			x = "24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_sensoractiv_none";
		};
	};
};
class RscAttributeSkill: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeSkill"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 16584;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 15284;
			text = "$STR_disp_arcunit_skill";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscXSliderH
		{
			idc = 16184;
			x = "10.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeText: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeText"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 15120;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscStructuredText
		{
			idc = 13920;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
	};
};
class RscAttributeAreaSize: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeAreaSize"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 21738;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 20438;
			text = "$STR_A3_RscAttributeAreaSize_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscToolboxButton
		{
			rows = 1;
			columns = 2;
			strings[] = {"$STR_WORD_DIST100","$STR_WORD_DIST200","$STR_WORD_DIST500"};
			idc = 20439;
			x = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeRespawnTickets: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeRespawnTickets"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 36632;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "9.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Background: RscText
		{
			idc = 35332;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class WEST: RscPicture
		{
			colorText[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])","(profilenamespace getvariable ['Map_BLUFOR_G',1])","(profilenamespace getvariable ['Map_BLUFOR_B',1])",1};
			idc = 35532;
			text = "\a3\Ui_f\data\Map\Markers\NATO\b_unknown.paa";
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class WESTValue: RscXSliderH
		{
			idc = 36232;
			x = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "22.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_WEST";
		};
		class WESTText: RscText
		{
			style = 2;
			shadow = 2;
			idc = 35333;
			text = "$STR_A3_RscAttributeRespawnTickets_WESTText";
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class EAST: WEST
		{
			colorText[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])","(profilenamespace getvariable ['Map_OPFOR_G',1])","(profilenamespace getvariable ['Map_OPFOR_B',1])",1};
			idc = 35533;
			text = "\a3\Ui_f\data\Map\Markers\NATO\o_unknown.paa";
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class EASTValue: WESTValue
		{
			idc = 36233;
			x = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "22.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_EAST";
		};
		class EASTText: WESTText
		{
			idc = 35334;
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GUER: WEST
		{
			colorText[] = {"(profilenamespace getvariable ['Map_Independent_R',0])","(profilenamespace getvariable ['Map_Independent_G',1])","(profilenamespace getvariable ['Map_Independent_B',1])",1};
			idc = 35534;
			text = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class GUERValue: WESTValue
		{
			idc = 36234;
			x = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "22.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_guerrila";
		};
		class GuerText: WESTText
		{
			idc = 35335;
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CIV: WEST
		{
			colorText[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])","(profilenamespace getvariable ['Map_Civilian_G',1])","(profilenamespace getvariable ['Map_Civilian_B',1])",1};
			idc = 35535;
			text = "\a3\Ui_f\data\Map\Markers\NATO\n_unknown.paa";
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class CIVValue: WESTValue
		{
			idc = 36235;
			x = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "6.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "22.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Civilian";
		};
		class CIVText: WESTText
		{
			idc = 35336;
			x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "6.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Title: RscText
		{
			idc = 35337;
			text = "$STR_A3_CfgVehicles_ModuleBleedTickets_F";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "8.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
			sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Value: RscToolboxButton
		{
			rows = 1;
			columns = 2;
			strings[] = {"$STR_DISABLED","$STR_ENABLED"};
			idc = 35338;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "8.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeCountdown: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeCountdown"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 24929;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 23629;
			text = "$STR_A3_RscAttributeCountdown_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 23631;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Value: RscXSliderH
		{
			idc = 24529;
			x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Time: RscText
		{
			style = 2;
			idc = 23630;
			x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeEndMission: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeEndMission"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 26422;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "16 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			style = 16;
			idc = 25122;
			text = "$STR_A3_RscAttributeEndMission_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscListbox
		{
			idc = 25622;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TitleDebriefing: RscText
		{
			idc = 25123;
			text = "$STR_A3_RscAttributeEndMission_TitleDebriefing";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Debriefing: RscEdit
		{
			style = 16;
			idc = 25522;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeName: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeName"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 14617;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 13317;
			text = "$STR_A3_RscAttributeName_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscEdit
		{
			idc = 13717;
			x = "10.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeInventory: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeInventory"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 25168;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "17 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class ListBackground: RscText
		{
			idc = 23869;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26.0092 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "13.498 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class FilterBackground: RscText
		{
			idc = 23870;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "-2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Filter0: RscActivePicture
		{
			idc = 24068;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_0_ca.paa";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Current";
		};
		class Filter1: Filter0
		{
			idc = 24069;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_1_ca.paa";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Rifles";
		};
		class Filter2: Filter0
		{
			idc = 24070;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_2_ca.paa";
			x = "4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Machineguns";
		};
		class Filter3: Filter0
		{
			idc = 24071;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_3_ca.paa";
			x = "6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Sniper Rifles";
		};
		class Filter4: Filter0
		{
			idc = 24072;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_4_ca.paa";
			x = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Launchers";
		};
		class Filter5: Filter0
		{
			idc = 24073;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_5_ca.paa";
			x = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Handguns";
		};
		class Filter6: Filter0
		{
			idc = 24074;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_6_ca.paa";
			x = "12 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Misc Weapons";
		};
		class Filter7: Filter0
		{
			idc = 24075;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_7_ca.paa";
			x = "14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Weapon Accessories";
		};
		class Filter8: Filter0
		{
			idc = 24076;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_8_ca.paa";
			x = "16 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Uniforms";
		};
		class Filter9: Filter0
		{
			idc = 24077;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_9_ca.paa";
			x = "18 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Vests";
		};
		class Filter10: Filter0
		{
			idc = 24078;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_10_ca.paa";
			x = "20 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Backpacks";
		};
		class Filter11: Filter0
		{
			idc = 24079;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_11_ca.paa";
			x = "22 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Headgear";
		};
		class Filter12: Filter0
		{
			idc = 24080;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_12_ca.paa";
			x = "24 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Items";
		};
		class ArrowLeft: RscButtonMenu
		{
			class Attributes
			{
				font = "RobotoCondensed";
				color = "#ffffff";
				align = "center";
				shadow = "false";
			};
			class TextPos
			{
				left = 0;
				top = 0;
				right = 0;
				bottom = 0;
			};
			idc = 24468;
			text = "-";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "-1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ArrowRight: ArrowLeft
		{
			idc = 24469;
			text = "+";
			x = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "-1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class List: RscListNBox
		{
			columns[] = {0.05,0.15,0.85,0.85};
			drawSideArrows = 1;
			idcLeft = 24468;
			idcRight = 24469;
			colorSelect2[] = {0.95,0.95,0.95,1};
			colorSelectBackground[] = {1,1,1,0.25};
			colorSelectBackground2[] = {1,1,1,0.25};
			idc = 24368;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "13.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Load: RscProgress
		{
			texture = "";
			textureExt = "";
			colorBar[] = {0.9,0.9,0.9,0.9};
			colorExtBar[] = {1,1,1,1};
			colorFrame[] = {1,1,1,1};
			idc = 23868;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "16 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.75};
		};
	};
};
class RscAttributeRespawnInventory: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeRespawnInventory"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 43128;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "17 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class ListBackground: RscText
		{
			style = 2;
			shadow = 0;
			idc = 41829;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.75};
			colorBackground[] = {1,1,1,0.1};
			sizeEx = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class FilterBackground: RscText
		{
			idc = 41830;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "-2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "6.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Filter0: RscActivePictureKeepAspect
		{
			idc = 42028;
			text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "6.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_WEST";
		};
		class Filter1: Filter0
		{
			idc = 42029;
			text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_east_ca.paa";
			x = "6.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "6.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_EAST";
		};
		class Filter2: Filter0
		{
			idc = 42030;
			text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_guer_ca.paa";
			x = "13 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "6.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Guerrila";
		};
		class Filter3: Filter0
		{
			idc = 42031;
			text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_civ_ca.paa";
			x = "19.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "6.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_Civilian";
		};
		class TreeWest: RscTree
		{
			colorSelect[] = {0,0,0,0};
			colorSelectText[] = {1,1,1,1.0};
			colorSelectBackground[] = {0,0,0,0};
			idc = 42328;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0};
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TreeEast: TreeWest
		{
			idc = 42329;
		};
		class TreeGuer: TreeWest
		{
			idc = 42330;
		};
		class TreeCiv: TreeWest
		{
			idc = 42331;
		};
	};
};
class RscAttributeCAS: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeCAS"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 12190;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			style = 16;
			idc = 10890;
			text = "$STR_DN_Plane";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscListNBox
		{
			columns[] = {0.0,0.1,0.25};
			colorSelect[] = {0.95,0.95,0.95,1};
			colorSelect2[] = {0.95,0.95,0.95,1};
			colorSelectBackground[] = {1,1,1,0.25};
			colorSelectBackground2[] = {1,1,1,0.25};
			idc = 11390;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeExec: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeExec"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	adminOnly = 1;
	idc = 14666;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 13366;
			text = "$STR_a3_rscdebugconsole_expressiontext";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class ValueTemplate: RscCombo
		{
			wholeHeight = "4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			font = "EtelkaMonospacePro";
			idc = 14466;
			x = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Value: RscEdit
		{
			style = 16;
			autocomplete = "scripting";
			shadow = 0;
			font = "EtelkaMonospacePro";
			idc = 13766;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RSCATTRIBUTEMISSIONNAME: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RSCATTRIBUTEMISSIONNAME"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 21475;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 20175;
			text = "$STR_A3_RscAttributeName_Title";
			x = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "20 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscEdit
		{
			idc = 20575;
			x = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "20 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class PreviewTitle: RscText
		{
			idc = 20176;
			text = "$STR_disp_arcmap_preview";
			x = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "20 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Preview: RscStructuredText
		{
			idc = 20275;
			x = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "20 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
	};
};
class RscAttributeSpeedMode: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeSpeedMode"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 23587;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 22289;
			text = "$STR_disp_arcwp_speed";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 22287;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Limited: RscActivePicture
		{
			shadow = 0;
			idc = 22489;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\limited_ca.paa";
			x = "14.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_speed_limited";
		};
		class Normal: Limited
		{
			idc = 22492;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\normal_ca.paa";
			x = "17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_speed_normal";
		};
		class Full: Limited
		{
			idc = 22493;
			text = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\full_ca.paa";
			x = "19.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_speed_full";
		};
		class Default: Limited
		{
			idc = 22488;
			text = "\a3\ui_f_curator\Data\default_ca.paa";
			x = "24 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_speed_unchanged";
		};
	};
};
class RscAttributeTaskDestination: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTaskDestination"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 39309;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 38011;
			text = "$STR_a3_cfgvehicles_moduletasksetdestination_f_arguments_destination_0";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			style = 2;
			idc = 38009;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
			colorBackground[] = {1,1,1,0.1};
		};
		class Value: RscToolbox
		{
			rows = 1;
			columns = 2;
			font = "RobotoCondensedLight";
			color[] = {1,1,1,1};
			colorTextSelect[] = {0,0,0,1};
			colorSelectedBg[] = {1,1,1,1};
			strings[] = {"$STR_a3_cfgvehicles_moduletasksetdestination_f_arguments_destination_values_module_0","$STR_disabled"};
			idc = 38010;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeWaypointType: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeWaypointType"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 31811;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 30513;
			text = "$STR_disp_arcwp_type";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			style = 2;
			idc = 30511;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
			colorBackground[] = {1,1,1,0.1};
		};
		class Value: RscToolbox
		{
			rows = 3;
			columns = 3;
			font = "RobotoCondensedLight";
			color[] = {1,1,1,1};
			colorTextSelect[] = {0,0,0,1};
			colorSelectedBg[] = {1,1,1,1};
			sizeEx = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			strings[] = {"$STR_ac_move","$STR_ac_getout","$STR_ac_unload","$STR_ac_transportunload","$STR_A3_CfgWaypoints_Land","$STR_A3_CfgWaypoints_Artillery","$STR_ac_unhook"};
			names[] = {"MOVE","GETOUT","UNLOAD","TR UNLOAD","%1/cfgWaypoints/A3/Land","%1/cfgWaypoints/A3/Artillery","UNHOOK"};
			idc = 31011;
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeWaypointTimeout: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeWaypointTimeout"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 40014;
	x = "6.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 38714;
			text = "$STR_hc_menu_waituntil";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = "IDC_RSCATTRIBUTEWAYPOINTTIMEOUT_BACKGROUND";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class ButtonTime00: RscButton
		{
			font = "RobotoCondensedLight";
			shadow = 0;
			colorDisabled[] = {0,0,0,1};
			colorBackgroundDisabled[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			idc = 39314;
			text = "$STR_hc_menu_nowait";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonTime05: ButtonTime00
		{
			idc = 39316;
			x = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonTime10: ButtonTime00
		{
			idc = 39317;
			x = "11 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonTime15: ButtonTime00
		{
			idc = 39318;
			x = "14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonTime20: ButtonTime00
		{
			idc = 39319;
			x = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonTime25: ButtonTime00
		{
			idc = 39320;
			x = "20 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonTime30: ButtonTime00
		{
			idc = 39321;
			x = "23 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "3 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeTimeMultiplier: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTimeMultiplier"",'CuratorCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 36679;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 35379;
			text = "$STR_controls_tooltips_TIME_INC";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 35381;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Value: RscXSliderH
		{
			sliderRange[] = {0.01,60};
			sliderPosition = 1;
			idc = 36279;
			x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Multiplier: RscText
		{
			style = 2;
			idc = 35380;
			x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Example: RscText
		{
			style = 2;
			idc = 35382;
			x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "25 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeBootcampStage: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeBootcampStage"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 33254;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 31956;
			text = "$STR_A3_RscAttributeBootcampStage_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 31954;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class Infantry: RscActivePicture
		{
			idc = 32154;
			text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
			x = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeBootcampStage_Infantry_tooltip";
		};
		class MotorizedVehicles: Infantry
		{
			idc = 32155;
			text = "a3\UI_F_Curator\Data\RscCommon\RscAttributeBootcampStage\Icon_VehiclesFiringRange.paa";
			x = "13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeBootcampStage_MotorizedVehicles_tooltip";
		};
	};
};
class RscAttributeHintTopics: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeHintTopics"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 26525;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "11 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 25225;
			text = "$STR_A3_RscAttributeHintTopics_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscTree
		{
			idc = 25725;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeHintCustom: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeHintCustom"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 26732;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class TitleTitle: RscText
		{
			idc = 25434;
			text = "$STR_A3_RscAttributeHintCustom_TitleTitle";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class EditTitle: RscEdit
		{
			style = 16;
			idc = 25832;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
	};
};
class RscAttributePunishmentAnimation: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributePunishmentAnimation"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 51418;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 50120;
			text = "$STR_A3_RscAttributePunishmentAnimation_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 50118;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class PushUps: RscActivePicture
		{
			idc = 50318;
			text = "\a3\UI_F_Curator\Data\RscCommon\RscAttributePunishmentAnimation\Pushups.paa";
			x = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributePunishmentAnimation_PushUps_tooltip";
		};
		class LegPushUps: PushUps
		{
			idc = 50319;
			text = "\a3\UI_F_Curator\Data\RscCommon\RscAttributePunishmentAnimation\PushupsLegs.paa";
			x = "13 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributePunishmentAnimation_LegPushUps_tooltip";
		};
	};
};
class RscAttributeTargetTexture: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTargetTexture"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 34264;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "25.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 32966;
			text = "$STR_A3_RscAttributeTargetTexture_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			idc = 32964;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.1};
		};
		class TextureList: RscListbox
		{
			idc = 33464;
			x = "10.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class Overlap: RscControlsGroup
{
	idc = 34265;
	x = "29 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "11 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "1.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "3.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Preview: RscPicture
		{
			idc = 33167;
			text = "a3\structures_f\training\data\Target_Zom_Acc1_CO";
			x = "-2.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "4.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "$STR_A3_RscAttributeTargetTexture_Preview_tooltip";
		};
	};
};
class RscAttributeTargetPopup: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTargetPopup"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 29087;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 27789;
			text = "$STR_A3_RscAttributeTargetPopup_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			style = 2;
			idc = 27787;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
			colorBackground[] = {1,1,1,0.1};
		};
		class Value: RscToolbox
		{
			rows = 1;
			columns = 2;
			strings[] = {"$STR_enabled","$STR_disabled"};
			idc = 27788;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeTargetPopupDelay: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTargetPopupDelay"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 41564;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 40264;
			text = "$STR_A3_RscAttributeTargetPopupDelay_Title";
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Value: RscXSliderH
		{
			idc = 41164;
			x = "10.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeTargetState: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTargetState"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 28673;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 27375;
			text = "$STR_A3_RscAttributeTargetState_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			style = 2;
			idc = 27373;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
			colorBackground[] = {1,1,1,0.1};
		};
		class Value: RscToolbox
		{
			rows = 1;
			columns = 2;
			strings[] = {"$STR_A3_RscAttributeTargetState_Up","$STR_A3_RscAttributeTargetState_Down"};
			idc = 27374;
			x = "5.28 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "-7.81 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeTargetData: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTargetData"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 25801;
	x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
	y = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
	w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "5.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Value: RscListNBox
		{
			columns[] = {0,0.2,0.4,0.6,0.8};
			colorSelect2[] = {0.95,0.95,0.95,1};
			colorSelectBackground[] = {1,1,1,0.25};
			colorSelectBackground2[] = {1,1,1,0.25};
			idc = 25001;
			x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscAttributeTargetDataStore: RscControlsGroupNoScrollbars
{
	onSetFocus = "[_this,""RscAttributeTargetDataStore"",'BootcampCommon'] call (uinamespace getvariable ""BIS_fnc_initCuratorAttribute"")";
	idc = 38435;
	x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	class controls
	{
		class Title: RscText
		{
			idc = 37137;
			text = "$STR_A3_RscAttributeTargetDataStore_Title";
			x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.5};
		};
		class Background: RscText
		{
			style = 2;
			idc = 37135;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
			colorBackground[] = {1,1,1,0.1};
		};
		class Value: RscToolbox
		{
			rows = 1;
			columns = 2;
			strings[] = {"$STR_enabled","$STR_disabled"};
			idc = 37136;
			x = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "16 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayAttributes
{
	idd = -1;
	movingenable = 0;
	scriptName = "RscDisplayAttributes";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributes"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributes"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class ControlsBackground
	{
		class Map: RscMapControl
		{
			idc = 50;
			x = "safezoneXAbs";
			y = "safezoneY";
			w = "safezoneWAbs";
			h = "safezoneH";
			class CustomMark
			{
				icon = "#(argb,8,8,3)color(0,0,0,0)";
				color[] = {0,0,0,0};
				size = 0;
				importance = 0;
				coefMin = 0;
				coefMax = 0;
			};
		};
	};
	class Controls
	{
		class Background: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 30001;
			x = "6.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "9.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "27 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Title: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 30002;
			text = "$STR_A3_RscDisplayAttributes_Title";
			x = "6.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "8.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "27 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Content: RscControlsGroup
		{
			idc = 30003;
			x = "7 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "26 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls{};
		};
		class ButtonOK: RscButtonMenuOK
		{
			x = "28.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "16.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonCustom: RscButtonMenu
		{
			idc = 30004;
			x = "23.4 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "16.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			x = "6.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "16.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayAttributesMan: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesMan";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesMan"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesMan"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	filterAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Rank: RscAttributeRank{};
				class UnitPos: RscAttributeUnitPos{};
				class Damage: RscAttributeDamage{};
				class Skill: RscAttributeSkill{};
				class RespawnPosition: RscAttributeRespawnPosition{};
				class Exec: RscAttributeExec{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesVehicle: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesVehicle";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesVehicle"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesVehicle"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	filterAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Rank: RscAttributeRank{};
				class Damage: RscAttributeDamage{};
				class Fuel: RscAttributeFuel{};
				class Skill: RscAttributeSkill{};
				class Lock: RscAttributeLock{};
				class RespawnVehicle: RscAttributeRespawnVehicle{};
				class RespawnPosition: RscAttributeRespawnPosition{};
				class Exec: RscAttributeExec{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesVehicleEmpty: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesVehicleEmpty";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesVehicleEmpty"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesVehicleEmpty"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	filterAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Damage: RscAttributeDamage{};
				class Fuel: RscAttributeFuel{};
				class Lock: RscAttributeLock{};
				class RespawnVehicle: RscAttributeRespawnVehicle{};
				class RespawnPosition: RscAttributeRespawnPosition{};
				class Exec: RscAttributeExec{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesGroup: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesGroup";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesGroup"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesGroup"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	filterAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class GroupID: RscAttributeGroupID{};
				class Skill: RscAttributeSkill{};
				class Formation: RscAttributeFormation{};
				class Behaviour: RscAttributeBehaviour{};
				class SpeedMode: RscAttributeSpeedMode{};
				class UnitPos: RscAttributeUnitPos{};
				class RespawnPosition: RscAttributeRespawnPosition
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscAttributeRespawnPosition_TitleGroup";
						};
						class Background: Background{};
						class West: West{};
						class East: East{};
						class Guer: Guer{};
						class Civ: Civ{};
						class Disabled: Disabled{};
					};
				};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesWaypoint: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesWaypoint";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesWaypoint"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesWaypoint"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	filterAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class WaypointType: RscAttributeWaypointType{};
				class WaypointTimeout: RscAttributeWaypointTimeout{};
				class Formation: RscAttributeFormation{};
				class Behaviour: RscAttributeBehaviour{};
				class SpeedMode: RscAttributeSpeedMode{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesMarker: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesMarker";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesMarker"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesMarker"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	filterAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class MarkerText: RscAttributeMarkerText{};
				class MarkerColor: RscAttributeMarkerColor{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesIntel: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesIntel";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesIntel"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesIntel"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	curatorObjectAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Owners: RscAttributeOwners{};
				class DiaryRecord: RscAttributeDiaryRecord{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesInventory: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesInventory";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesInventory"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesInventory"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	curatorObjectAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Inventory: RscAttributeInventory{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCustom: ButtonCustom{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleObjectiveMove: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleObjectiveMove";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleObjectiveMove"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleObjectiveMove"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Text: RscAttributeText
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveMove_Controls_Content_Controls_Text_Controls_Title_0";
						};
					};
				};
				class Owners: RscAttributeOwners{};
				class TaskDescription: RscAttributeTaskDescription
				{
					class Controls: controls
					{
						class TitleTemplate: TitleTemplate{};
						class EditTemplate: EditTemplate{};
						class TitleTitle: TitleTitle{};
						class EditTitle: EditTitle
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveMove_Controls_Content_Controls_TaskDescription_Controls_EditTitle_0";
						};
						class TitleMarker: TitleMarker{};
						class EditMarker: EditMarker
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveMove_Controls_Content_Controls_TaskDescription_Controls_EditMarker_0";
						};
						class TitleDescription: TitleDescription{};
						class EditDescription: EditDescription
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveMove_Controls_Content_Controls_TaskDescription_Controls_EditDescription_0";
						};
					};
				};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleObjectiveCustom: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleObjectiveCustom";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleObjectiveCustom"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleObjectiveCustom"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Text: RscAttributeText
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveCustom_Controls_Content_Controls_Text_Controls_Title_0";
						};
					};
				};
				class Owners: RscAttributeOwners{};
				class TaskState: RscAttributeTaskState{};
				class TaskDestination: RscAttributeTaskDestination{};
				class TaskDescription: RscAttributeTaskDescription{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleObjectiveSector: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleObjectiveSector";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleObjectiveSector"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleObjectiveSector"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Text: RscAttributeText
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveSector_Controls_Content_Controls_Text_Controls_Title_0";
						};
					};
				};
				class Owners: RscAttributeOwners
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveSector_Controls_Content_Controls_Owners_Controls_Title_0";
						};
						class Background: Background{};
						class TabSide: TabSide{};
						class BLUFOR: BLUFOR{};
						class OPFOR: OPFOR{};
						class Independent: Independent{};
						class Civilian: Civilian{};
						class GroupList: GroupList{};
						class UnitList: UnitList{};
					};
				};
				class AreaSize: RscAttributeAreaSize{};
				class Name: RscAttributeName{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleObjectiveAttackDefend: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleObjectiveAttackDefend";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleObjectiveAttackDefend"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleObjectiveAttackDefend"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Text: RscAttributeText
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveAttackDefend_Controls_Content_Controls_Text_Controls_Title_0";
						};
					};
				};
				class Owners2: RscAttributeOwners2
				{
					class Controls: controls
					{
						class Title1: Title1
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveAttackDefend_Controls_Content_Controls_Owners2_Controls_Title1_0";
						};
						class Title2: Title2
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveAttackDefend_Controls_Content_Controls_Owners2_Controls_Title2_0";
						};
						class Background1: Background1{};
						class Background2: Background2{};
						class BLUFOR1: BLUFOR1{};
						class BLUFOR2: BLUFOR2{};
						class OPFOR1: OPFOR1{};
						class OPFOR2: OPFOR2{};
						class Independent1: Independent1{};
						class Independent2: Independent2{};
						class Civilian1: Civilian1{};
						class Civilian2: Civilian2{};
					};
				};
				class AreaSize: RscAttributeAreaSize{};
				class Name: RscAttributeName
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveAttackDefend_Controls_Content_Controls_Name_Controls_Title_0";
						};
						class Value: Value{};
					};
				};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleObjectiveNeutralize: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleObjectiveNeutralize";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleObjectiveNeutralize"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleObjectiveNeutralize"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Text: RscAttributeText
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveNeutralize_Controls_Content_Controls_Text_Controls_Title_0";
						};
					};
				};
				class Owners: RscAttributeOwners{};
				class TaskDescription: RscAttributeTaskDescription
				{
					class Controls: controls
					{
						class TitleTemplate: TitleTemplate{};
						class EditTemplate: EditTemplate{};
						class TitleTitle: TitleTitle{};
						class EditTitle: EditTitle
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveNeutralize_Controls_Content_Controls_TaskDescription_Controls_EditTitle_0";
						};
						class TitleMarker: TitleMarker{};
						class EditMarker: EditMarker
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveNeutralize_Controls_Content_Controls_TaskDescription_Controls_EditMarker_0";
						};
						class TitleDescription: TitleDescription{};
						class EditDescription: EditDescription
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveNeutralize_Controls_Content_Controls_TaskDescription_Controls_EditDescription_0";
						};
					};
				};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleObjectiveProtect: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleObjectiveProtect";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleObjectiveProtect"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleObjectiveProtect"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Text: RscAttributeText
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveProtect_Controls_Content_Controls_Text_Controls_Title_0";
						};
					};
				};
				class Owners: RscAttributeOwners{};
				class TaskDescription: RscAttributeTaskDescription
				{
					class Controls: controls
					{
						class TitleTemplate: TitleTemplate{};
						class EditTemplate: EditTemplate{};
						class TitleTitle: TitleTitle{};
						class EditTitle: EditTitle
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveProtect_Controls_Content_Controls_TaskDescription_Controls_EditTitle_0";
						};
						class TitleMarker: TitleMarker{};
						class EditMarker: EditMarker
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveProtect_Controls_Content_Controls_TaskDescription_Controls_EditMarker_0";
						};
						class TitleDescription: TitleDescription{};
						class EditDescription: EditDescription
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveProtect_Controls_Content_Controls_TaskDescription_Controls_EditDescription_0";
						};
					};
				};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleObjectiveGetIn: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleObjectiveGetIn";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleObjectiveGetIn"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleObjectiveGetIn"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Text: RscAttributeText
				{
					class Controls: controls
					{
						class Title: Title
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveGetIn_Controls_Content_Controls_Text_Controls_Title_0";
						};
					};
				};
				class Owners: RscAttributeOwners{};
				class TaskDescription: RscAttributeTaskDescription
				{
					class Controls: controls
					{
						class TitleTemplate: TitleTemplate{};
						class EditTemplate: EditTemplate{};
						class TitleTitle: TitleTitle{};
						class EditTitle: EditTitle
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveGetIn_Controls_Content_Controls_TaskDescription_Controls_EditTitle_0";
						};
						class TitleMarker: TitleMarker{};
						class EditMarker: EditMarker
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveGetIn_Controls_Content_Controls_TaskDescription_Controls_EditMarker_0";
						};
						class TitleDescription: TitleDescription{};
						class EditDescription: EditDescription
						{
							text = "$STR_A3_RscDisplayAttributesModuleObjectiveGetIn_Controls_Content_Controls_TaskDescription_Controls_EditDescription_0";
						};
					};
				};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleSkiptime: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleSkiptime";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleSkiptime"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleSkiptime"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Skiptime: RscAttributeSkiptime{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleWeather: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleWeather";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleWeather"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleWeather"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Overcast: RscAttributeOvercast{};
				class Fog: RscAttributeFog{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleMusic: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleMusic";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleMusic"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleMusic"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Owners: RscAttributeOwners{};
				class Music: RscAttributeMusic{};
				class MusicVolume: RscAttributeMusicVolume{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleSound: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleSound";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleSound"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleSound"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Sound: RscAttributeSound{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleRadio: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleRadio";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleRadio"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleRadio"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Owners: RscAttributeOwners{};
				class GenericRadio: RscAttributeGenericRadio{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleDiary: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleDiary";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleDiary"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleDiary"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Owners: RscAttributeOwners{};
				class DiaryRecord: RscAttributeDiaryRecord{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModulePostprocess: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModulePostprocess";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModulePostprocess"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModulePostprocess"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Postprocess: RscAttributePostprocess{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleRespawnTickets: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleRespawnTickets";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleRespawnTickets"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleRespawnTickets"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class RespawnTickets: RscAttributeRespawnTickets{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleCountdown: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleCountdown";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleCountdown"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleCountdown"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Countdown: RscAttributeCountdown{};
				class EndMission: RscAttributeEndMission{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleEndMission: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleEndMission";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleEndMission"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleEndMission"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class EndMission: RscAttributeEndMission{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleRespawnInventory: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleRespawnInventory";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleRespawnInventory"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleRespawnInventory"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	curatorObjectAttributes = 1;
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class RespawnInventory: RscAttributeRespawnInventory{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCustom: ButtonCustom{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleCAS: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleCAS";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleCAS"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleCAS"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class CAS: RscAttributeCAS{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleMissionName: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleMissionName";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleMissionName"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleMissionName"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class MissionName: RSCATTRIBUTEMISSIONNAME{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleTimeMultiplier: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleTimeMultiplier";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleTimeMultiplier"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleTimeMultiplier"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class TimeMultiplier: RscAttributeTimeMultiplier{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayFiringRangeBoard
{
	idd = 50500;
	enableSimulation = 1;
	movingEnable = 0;
	onLoad = "['uiOnLoad', [_this select 0]] call BIS_fnc_firingRange;";
	class controls
	{
		class BackgroundTitle: IGUIBack
		{
			idc = 34891;
			x = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "36 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,0.8,0.4,0.5};
		};
		class Table: RscListNBox
		{
			columns[] = {0,0.25,0.5,0.75};
			colorSelect2[] = {0.95,0.95,0.95,1};
			colorSelectBackground[] = {1,1,1,0.25};
			colorSelectBackground2[] = {1,1,1,0.25};
			colorText[] = {0,0,0,1};
			idc = 34191;
			x = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "36 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "21 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonOk: RscButtonMenuOK
		{
			x = "29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "23.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "8.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayTimeTrialBoard: RscDisplayFiringRangeBoard
{
	idd = 50502;
	onLoad = "['uiOnLoad', [_this select 0]] call BIS_fnc_timeTrial;";
	class controls
	{
		class BackgroundTitle: IGUIBack
		{
			idc = 30099;
			x = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "36 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,0.8,0.4,0.5};
		};
		class Table: RscListNBox
		{
			columns[] = {0,0.33,0.66};
			colorSelect2[] = {0.95,0.95,0.95,1};
			colorSelectBackground[] = {1,1,1,0.25};
			colorSelectBackground2[] = {1,1,1,0.25};
			colorText[] = {0,0,0,1};
			idc = 29399;
			x = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "36 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "21 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonOk: RscButtonMenuOK
		{
			x = "29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "23.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "8.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayTargetBoard: RscDisplayFiringRangeBoard
{
	idd = 50502;
	onLoad = "['uiOnLoad', [_this select 0]] call BIS_fnc_target;";
	class controls
	{
		class Background: IGUIBack
		{
			idc = 23629;
			x = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "36 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "21 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,1,1,0.5};
		};
		class BackgroundTitle: IGUIBack
		{
			idc = 23628;
			x = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "36 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {1,0.8,0.4,0.5};
		};
		class Table: RscListNBox
		{
			columns[] = {0,0.166,0.333,0.499,0.665,0.831};
			colorSelect2[] = {0.95,0.95,0.95,1};
			colorSelectBackground[] = {1,1,1,0.25};
			colorSelectBackground2[] = {1,1,1,0.25};
			colorText[] = {0,0,0,1};
			idc = 22928;
			x = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "36 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "21 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonOk: RscButtonMenuOK
		{
			x = "29.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "23.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "8.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayAttributesModuleBootcampStage: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleBootcampStage";
	scriptPath = "BootcampDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleBootcampStage"",'BootcampDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleBootcampStage"",'BootcampDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Stage: RscAttributeBootcampStage{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCustom: ButtonCustom{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModuleHint: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModuleHint";
	scriptPath = "BootcampDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModuleHint"",'BootcampDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModuleHint"",'BootcampDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Side: RscAttributeSide{};
				class Custom: RscAttributeHintCustom{};
				class Topic: RscAttributeHintTopics{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesModulePunishment: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesModulePunishment";
	scriptPath = "BootcampDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesModulePunishment"",'BootcampDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesModulePunishment"",'BootcampDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Animation: RscAttributePunishmentAnimation{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayAttributesTarget: RscDisplayAttributes
{
	scriptName = "RscDisplayAttributesTarget";
	scriptPath = "BootcampDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayAttributesTarget"",'BootcampDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayAttributesTarget"",'BootcampDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class Controls: Controls
	{
		class Background: Background{};
		class Title: Title{};
		class Content: Content
		{
			class Controls: controls
			{
				class Texture: RscAttributeTargetTexture{};
				class State: RscAttributeTargetState{};
				class Popup: RscAttributeTargetPopup{};
				class PopupDelay: RscAttributeTargetPopupDelay{};
				class DataStore: RscAttributeTargetDataStore{};
				class Data: RscAttributeTargetData{};
			};
		};
		class ButtonOK: ButtonOK{};
		class ButtonCustom: ButtonCustom{};
		class ButtonCancel: ButtonCancel{};
	};
};
class RscDisplayCurator
{
	idd = 312;
	scriptName = "RscDisplayCurator";
	scriptPath = "CuratorDisplays";
	onLoad = "[""onLoad"",_this,""RscDisplayCurator"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload = "[""onUnload"",_this,""RscDisplayCurator"",'CuratorDisplays'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	class ControlsBackground
	{
		class Map: RscMapControl
		{
			idc = 50;
			x = "safezoneXAbs";
			y = "safezoneY";
			w = "safezoneWAbs";
			h = "safezoneH";
			class CustomMark
			{
				icon = "#(argb,8,8,3)color(0,0,0,0)";
				color[] = {0,0,0,0};
				size = 0;
				importance = 0;
				coefMin = 0;
				coefMax = 0;
			};
		};
		class MouseArea: RscText
		{
			idc = 53;
			style = 16;
			x = "safezoneXAbs";
			y = "safezoneY";
			w = "safezoneWAbs";
			h = "safezoneH";
		};
	};
	class Controls
	{
		class Watermark: RscPicture
		{
			x = "safezoneX + safezoneW - 5.3 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "safezoneY + safezoneH - 4.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			idc = 15717;
			text = "\a3\Ui_F_Curator\Data\Logos\arma3_curator_eye_256_ca.paa";
			w = "4.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "4.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,0.5};
		};
		class Main: RscControlsGroupNoScrollbars
		{
			x = "safezoneX + 12.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			w = "safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			idc = 16806;
			y = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "1.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class PointsBackground: RscText
				{
					w = "safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					idc = 15513;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0.1,0.1,0.1,0.5};
				};
				class Points: RscText
				{
					w = "safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",0.8};
					idc = 111;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class PointsPreview: RscText
				{
					shadow = 2;
					style = 2;
					idc = 112;
					x = "6.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "7 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {1,0,0,0.4};
				};
				class PointsFrame: RscFrame
				{
					w = "safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					idc = 16306;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
				class Logo: RscPicture
				{
					x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) / 2 - 0.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					idc = 15715;
					text = "\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "1 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
				class FeedbackMessage: RscText
				{
					style = 2;
					w = "safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					idc = 15512;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class AddBar: RscControlsGroupNoScrollbars
		{
			x = "safezoneX + safezoneW - 12.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			idc = 16805;
			y = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class AddBarFrame: RscFrame
				{
					idc = 16309;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
				class AddBarTitle: RscButton
				{
					idc = 16105;
					text = "$STR_A3_RscDisplayCurator_AddBarTitle";
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class Add: RscControlsGroupNoScrollbars
		{
			h = "safezoneH - 2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			x = "safezoneX + safezoneW - 12.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			idc = 450;
			y = "1.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			class controls
			{
				class CreateBackground: RscText
				{
					h = "safezoneH - 2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					idc = 15505;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					colorBackground[] = {0.1,0.1,0.1,0.5};
				};
				class CreateClassesBackground: RscText
				{
					h = "safezoneH - 6 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					idc = 15510;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "4 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class ModeFrame: RscFrame
				{
					idc = 16304;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
				class ModeUnits: RscActivePicture
				{
					idc = 150;
					text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeUnits_ca.paa";
					x = "0.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip = "$STR_A3_RscDisplayCurator_ModeUnits_tooltip";
				};
				class ModeGroups: ModeUnits
				{
					idc = 151;
					text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
					x = "2.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip = "$STR_A3_RscDisplayCurator_ModeGroups_tooltip";
				};
				class ModeModules: ModeUnits
				{
					idc = 152;
					text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeModules_ca.paa";
					x = "4.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip = "$STR_A3_RscDisplayCurator_ModeModules_tooltip";
				};
				class ModeMarkers: ModeUnits
				{
					idc = 154;
					text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeMarkers_ca.paa";
					x = "6.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip = "$STR_A3_RscDisplayCurator_ModeMarkers_tooltip";
				};
				class ModeRecent: ModeUnits
				{
					idc = 170;
					text = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeRecent_ca.paa";
					x = "8.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip = "$STR_A3_RscDisplayCurator_ModeRecent_tooltip";
				};
				class SideFrame: RscFrame
				{
					idc = 16305;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
				class SideBLUFOR: RscActivePicture
				{
					color[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])","(profilenamespace getvariable ['Map_BLUFOR_G',1])","(profilenamespace getvariable ['Map_BLUFOR_B',1])",1};
					colorActive[] = {"(profilenamespace getvariable ['Map_BLUFOR_R',0])","(profilenamespace getvariable ['Map_BLUFOR_G',1])","(profilenamespace getvariable ['Map_BLUFOR_B',1])",1};
					shadow = 0;
					idc = 155;
					text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_west_ca.paa";
					x = "0.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0.3,0.6,1};
					tooltip = "$STR_WEST";
				};
				class SideOPFOR: SideBLUFOR
				{
					color[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])","(profilenamespace getvariable ['Map_OPFOR_G',1])","(profilenamespace getvariable ['Map_OPFOR_B',1])",1};
					colorActive[] = {"(profilenamespace getvariable ['Map_OPFOR_R',0])","(profilenamespace getvariable ['Map_OPFOR_G',1])","(profilenamespace getvariable ['Map_OPFOR_B',1])",1};
					idc = 156;
					text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_east_ca.paa";
					x = "2.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0.5,0,0,1};
					tooltip = "$STR_EAST";
				};
				class SideIndependent: SideBLUFOR
				{
					color[] = {"(profilenamespace getvariable ['Map_Independent_R',0])","(profilenamespace getvariable ['Map_Independent_G',1])","(profilenamespace getvariable ['Map_Independent_B',1])",1};
					colorActive[] = {"(profilenamespace getvariable ['Map_Independent_R',0])","(profilenamespace getvariable ['Map_Independent_G',1])","(profilenamespace getvariable ['Map_Independent_B',1])",1};
					idc = 157;
					text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_guer_ca.paa";
					x = "4.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0.5,0,1};
					tooltip = "$STR_GUERRILA";
				};
				class SideCivilian: SideBLUFOR
				{
					color[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])","(profilenamespace getvariable ['Map_Civilian_G',1])","(profilenamespace getvariable ['Map_Civilian_B',1])",1};
					colorActive[] = {"(profilenamespace getvariable ['Map_Civilian_R',0])","(profilenamespace getvariable ['Map_Civilian_G',1])","(profilenamespace getvariable ['Map_Civilian_B',1])",1};
					idc = 158;
					text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_civ_ca.paa";
					x = "6.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0.4,0,0.5,1};
					tooltip = "$STR_CIVILIAN";
				};
				class SideEmpty: SideBLUFOR
				{
					color[] = {"(profilenamespace getvariable ['Map_Unknown_R',0])","(profilenamespace getvariable ['Map_Unknown_G',1])","(profilenamespace getvariable ['Map_Unknown_B',1])",1};
					colorActive[] = {"(profilenamespace getvariable ['Map_Unknown_R',0])","(profilenamespace getvariable ['Map_Unknown_G',1])","(profilenamespace getvariable ['Map_Unknown_B',1])",1};
					idc = 159;
					text = "\a3\ui_f_curator\Data\Displays\RscDisplayCurator\side_unknown_ca.paa";
					x = "8.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0.7,0.6,0,1};
					tooltip = "$STR_EMPTY";
				};
				class CreateFrame: RscFrame
				{
					h = "safezoneH - 6 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					idc = 16307;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "4 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					colorText[] = {0,0,0,1};
				};
				class CreateSearch: RscEdit
				{
					idc = 283;
					x = "0.1 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "4.1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "9.7 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CreateSearchButton: RscButtonSearch
				{
					x = "9.8 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "4.1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "1 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CreateUnitsWest: RscTree
				{
					idc = 270;
					h = "safezoneH - 7.1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					idcSearch = 283;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "5.1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					sizeEx = "0.8 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CreateUnitsEast: CreateUnitsWest
				{
					idc = 271;
				};
				class CreateUnitsGuer: CreateUnitsWest
				{
					idc = 272;
				};
				class CreateUnitsCiv: CreateUnitsWest
				{
					idc = 273;
				};
				class CreateUnitsEmpty: CreateUnitsWest
				{
					idc = 274;
				};
				class CreateGroupsWest: CreateUnitsWest
				{
					idc = 275;
				};
				class CreateGroupsEast: CreateUnitsWest
				{
					idc = 276;
				};
				class CreateGroupsGuer: CreateUnitsWest
				{
					idc = 277;
				};
				class CreateGroupsCiv: CreateUnitsWest
				{
					idc = 278;
				};
				class CreateGroupsEmpty: CreateUnitsWest
				{
					idc = 279;
				};
				class CreateModules: CreateUnitsWest
				{
					idc = 280;
				};
				class CreateMarkers: CreateUnitsWest
				{
					idc = 281;
				};
				class CreateRecent: CreateUnitsWest
				{
					idc = 282;
				};
			};
		};
		class MissionBar: RscControlsGroupNoScrollbars
		{
			idc = 16809;
			x = "1.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
			y = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class MissionBarFrame: RscFrame
				{
					idc = 16311;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
				class MissionBarTitle: RscButton
				{
					idc = 16104;
					text = "$STR_A3_RscDisplayCurator_MissionBarTitle";
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class Mission: RscControlsGroupNoScrollbars
		{
			h = "safezoneH - 2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			idc = 453;
			x = "1.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
			y = "1.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			class controls
			{
				class EntitiesBackground: RscText
				{
					h = "safezoneH - 2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					idc = 15508;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					colorBackground[] = {0.1,0.1,0.1,0.5};
				};
				class EntitiesFrame: RscFrame
				{
					h = "safezoneH - 2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					idc = 16308;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					colorText[] = {0,0,0,1};
				};
				class Entities: RscTree
				{
					idc = 251;
					h = "safezoneH - 2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					multiselectEnabled = 1;
					expandOnDoubleclick = 0;
					colorMarked[] = {1,1,1,0.35};
					colorMarkedSelected[] = {1,1,1,0.7};
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "11 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					sizeEx = "0.8 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class Compass: RscControlsGroupNoScrollbars
		{
			x = "0.5 - 8 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			idc = 16810;
			y = "1.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "0.7 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class CompassBackground: RscText
				{
					idc = 15518;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.7 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0.1,0.1,0.1,0.5};
				};
				class CompassFrame: RscFrame
				{
					idc = 16312;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.7 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
				class CompassCaret: RscFrame
				{
					idc = 16314;
					x = "8 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "0.7 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
			};
		};
		class Clock: RscControlsGroup
		{
			x = "0.5 - 8 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			idc = 16808;
			y = "2.2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class ClockFrame: RscFrame
				{
					idc = 16310;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[] = {0,0,0,1};
				};
				class ClockDuration: RscText
				{
					font = "RobotoCondensedLight";
					idc = 15506;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0.1,0.1,0.1,0.5};
					sizeEx = "0.8 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ClockDaytime: RscText
				{
					style = 2;
					idc = 15509;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "-0.1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0,0,0,0};
				};
				class ClockCountdown: RscText
				{
					font = "RobotoCondensedLight";
					style = 1;
					idc = 15511;
					x = "0 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "16 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0,0,0,0};
					sizeEx = "0.8 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class MPProgress: RscMissionStatus{};
		class NotificationArea: RscNotificationArea{};
		class HintGroup: RscControlsGroupNoScrollbars
		{
			w = "(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			idc = 12957;
			x = "safezoneX + safezoneW - 13 * 							(			((safezoneW / safezoneH) min 1.2) / 40) - 		(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "3.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class Title: RscStructuredText
				{
					colorBackground[] = {0,0,0,0.7};
					w = "(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
					idc = 11657;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Hint: RscStructuredText
				{
					colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",0.7};
					size = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
					w = "(12 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
					idc = 11757;
					x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					h = "4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class ButtonTextures: RscActiveText
		{
			idc = 107;
			x = -1;
			y = -1;
			w = 0;
			h = 0;
		};
		class Black: RscText
		{
			idc = 999;
			colorBackground[] = {0,0,0,1};
			x = "safezoneXAbs";
			y = "safezoneY";
			w = "safezoneWAbs";
			h = "safezoneH";
		};
	};
};
class RscDisplayCuratorEngine: RscDisplayCurator{};
class RscTitles
{
	class RscCuratorPing
	{
		idd = -1;
		duration = 1;
		fadeIn = 0;
		scriptName = "RscCuratorPing";
		scriptPath = "CuratorTitles";
		onLoad = "[""onLoad"",_this,""RscCuratorPing"",'CuratorTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		onUnload = "[""onUnload"",_this,""RscCuratorPing"",'CuratorTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		class controls
		{
			class Icon: RscPicture
			{
				idc = 10674;
				text = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
				x = "19 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
				y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
				w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			};
			class Player: RscPicture
			{
				idc = 10675;
				text = "\A3\ui_f\data\igui\cfg\islandmap\iconPlayer_ca.paa";
				x = "19 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
				y = "11.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
				w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			};
		};
	};
	class RscCuratorVisionModes
	{
		idd = -1;
		duration = 2;
		fadeIn = 0;
		scriptName = "RscCuratorVisionModes";
		scriptPath = "CuratorTitles";
		onLoad = "[""onLoad"",_this,""RscCuratorVisionModes"",'CuratorTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		onUnload = "[""onUnload"",_this,""RscCuratorVisionModes"",'CuratorTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		class controls
		{
			class VisionModes: RscControlsGroupNoScrollbars
			{
				x = "safezoneX + 12.5 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
				w = "safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
				idc = 11763;
				y = "2.2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
				h = "1.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				class controls
				{
					delete Frame;
					class VisionMode0: RscText
					{
						style = 2;
						shadow = 0;
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 0";
						w = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1";
						idc = 10463;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						h = "0.75 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode1: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 1";
						idc = 10464;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode2: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 2";
						idc = 10465;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode3: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 3";
						idc = 10466;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode4: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 4";
						idc = 10467;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode5: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 5";
						idc = 10468;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode6: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 6";
						idc = 10469;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode7: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 7";
						idc = 10470;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode8: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 8";
						idc = 10471;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class VisionMode9: VisionMode0
					{
						x = "(safezoneW - 25 * 							(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1 * 9";
						idc = 10472;
						y = "0 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.5 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
				};
			};
		};
	};
	class RscMissionText
	{
		idd = 20145;
		fadein = 0;
		fadeout = 0;
		duration = 1e+11;
		scriptName = "RscMissionText";
		scriptPath = "BootcampTitles";
		onLoad = "[""onLoad"",_this,""RscMissionText"",'BootcampTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		onUnload = "[""onUnload"",_this,""RscMissionText"",'BootcampTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		class Controls
		{
			class Text: RscStructuredText
			{
				idc = 20146;
				style = 1;
				x = "(profilenamespace getvariable [""IGUI_GRID_MISSION_X"",		(safezoneX + safezoneW - 21 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
				y = "(profilenamespace getvariable [""IGUI_GRID_MISSION_Y"",		(safezoneY + safezoneH - 10.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
				w = "(20 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
				h = "(5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				class Attributes
				{
					align = "right";
					color = "#ffffff";
					font = "RobotoCondensed";
					shadow = 1;
				};
			};
		};
	};
	class RscRecruitStatus
	{
		idd = 455545;
		fadein = 0.5;
		fadeout = 0.5;
		duration = 1e+11;
		scriptName = "RscRecruitStatus";
		scriptPath = "BootcampTitles";
		onLoad = "[""onLoad"",_this,""RscRecruitStatus"",'BootcampTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		onUnload = "[""onUnload"",_this,""RscRecruitStatus"",'BootcampTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		class Controls
		{
			class Background: IGUIBack
			{
				idc = 15186;
				x = "13 * 							(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
				y = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
				w = "13.7 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "4.2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			};
			class Title: RscStructuredText
			{
				class Attributes
				{
					align = "center";
				};
				idc = 14086;
				x = "13 * 							(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
				y = "2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
				w = "13.7 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "1.2 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				colorText[] = {0,0,0,1};
				colorBackground[] = {1,0.8,0.4,0.8};
			};
			class Description: RscStructuredText
			{
				class Attributes
				{
					align = "center";
				};
				shadow = 0;
				idc = 14087;
				x = "13.13 * 							(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
				y = "3.9 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
				w = "13.4 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				colorText[] = {0,0,0,0.8};
				colorBackground[] = {1,1,1,0.8};
			};
			class List: RscListbox
			{
				class ListScrollBar: ScrollBar
				{
					color[] = {1,1,1,0};
					autoScrollEnabled = 0;
				};
				idc = 14486;
				x = "13.13 * 							(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
				y = "5.1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
				w = "13.4 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "1 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			};
			class ProgressBar: RscText
			{
				idc = 13986;
				x = "13.13 * 							(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX)";
				y = "3.4 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
				w = "13.4 * 							(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "0.3 * 							(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				colorBackground[] = {0.5,1,0.5,0.8};
			};
		};
	};
	class RscVRMeta
	{
		idd = -1;
		fadein = 0;
		fadeout = 0;
		duration = 1e+11;
		scriptName = "RscVRMeta";
		scriptPath = "BootcampTitles";
		onLoad = "[""onLoad"",_this,""RscVRMeta"",'BootcampTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		onUnload = "[""onUnload"",_this,""RscVRMeta"",'BootcampTitles'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
		class Controls
		{
			class VRMeta: RscControlsGroupNoScrollbars
			{
				idc = 5778;
				x = "8.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(profilenamespace getvariable [""IGUI_GRID_MISSION_X"",		(safezoneX + safezoneW - 21 * 			(			((safezoneW / safezoneH) min 1.2) / 40))])";
				y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(profilenamespace getvariable [""IGUI_GRID_MISSION_Y"",		(safezoneY + safezoneH - 10.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
				w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
				h = "5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				class controls
				{
					class BackgroundSpeed: RscText
					{
						idc = 4479;
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						colorBackground[] = {0.2,0.2,0.2,0.3};
					};
					class BackgroundTgt: BackgroundSpeed
					{
						idc = 4481;
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						colorBackground[] = {0.2,0.2,0.2,0.3};
					};
					class ProgressSpeed: RscProgress
					{
						colorBar[] = {0,0,0,0.25};
						idc = 4484;
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						colorBackground[] = {0,0,0,0.25};
					};
					class ProgressTgt: ProgressSpeed
					{
						idc = 4492;
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class TextSpeed: RscText
					{
						idc = 4487;
						text = "$STR_HC_MENU_SPEED";
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class ValueSpeed: RscText
					{
						style = 1;
						idc = 4490;
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "2.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class TextTgt: TextSpeed
					{
						idc = 4491;
						text = "$STR_MENU_TARGET";
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class ValueTgt: ValueSpeed
					{
						style = 2;
						idc = 4494;
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
					class ValueTgtDmg: ValueTgt
					{
						style = 1;
						idc = 4495;
						x = "0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						y = "3.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
						h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					};
				};
			};
		};
	};
};
