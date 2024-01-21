Sandyshore_Inn_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Sandyshore_Inn_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Sandyshore_Inn_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Sandyshore_Inn_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq Sandyshore_Inn_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_TEMP_10
	return

Sandyshore_Inn_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_TEMP_10
	return

Sandyshore_Inn_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, Sandyshore_Inn_EventScript_RuthGoUpstairs
	.2byte 0


Sandyshore_Inn_EventScript_RuthGoUpstairs::
	lock
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_RuthGoUpstairs_Text_0
	closemessage
	applymovement 1, Sandyshore_Inn_Movement_RuthWalkUpstairs
	waitmovement 0
	removeobject 1
	setflag FLAG_TEMP_10
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	release
	end


Sandyshore_Inn_Movement_RuthWalkUpstairs:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Sandyshore_Inn_EventScript_RuthGoUpstairs_Text_0:
	.string "Here, this way!$"
