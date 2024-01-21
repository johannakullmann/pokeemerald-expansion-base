SandyshoreTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandyshoreTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SandyshoreTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_SANDYSHORE_TOWN
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq SandyshoreTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_TEMP_10
	return

SandyshoreTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_TEMP_10
	return


SandyshoreTown_EventScript_InnSign::
	lock
	msgbox SandyshoreTown_EventScript_InnSign_Text_0
	release
	end


SandyshoreTown_EventScript_PreventExit_Route135::
	lock
	applymovement 2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox SandyshoreTown_EventScript_PreventExit_Route135_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	release
	end


SandyshoreTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox SandyshoreTown_EventScript_LittleGirl_Text_0
	return


SandyshoreTown_EventScript_RuthNoticePlayer_Left::
	lock
	turnobject 1, DIR_WEST
	goto SandyshoreTown_EventScript_RuthNoticePlayer
	return


SandyshoreTown_EventScript_RuthNoticePlayer_Right::
	lock
	turnobject 1, DIR_EAST
	goto SandyshoreTown_EventScript_RuthNoticePlayer
	return


SandyshoreTown_EventScript_RuthNoticePlayer::
	applymovement 1, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	msgbox SandyshoreTown_EventScript_RuthNoticePlayer_Text_0
	closemessage
	applymovement 1, Common_Movement_WalkUp
	waitmovement 0
	opendoor 26, 8
	applymovement 1, Common_Movement_WalkUp
	waitdooranim
	waitmovement 0
	closedoor 26, 8
	removeobject 1
	setflag FLAG_TEMP_10
	waitdooranim
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	release
	end


SandyshoreTown_EventScript_InnSign_Text_0:
	.string "Sandyshore Inn$"

SandyshoreTown_EventScript_PreventExit_Route135_Text_0:
	.string "Ah, {PLAYER}!\p"
	.string "I saw Ruth in front of the Inn!\p"
	.string "I wanna go visit the professor too, but\n"
	.string "Grandma said he's busy so I shouldn't\l"
	.string "bother him…$"

SandyshoreTown_EventScript_LittleGirl_Text_0:
	.string "I wanna go visit the professor too, but\n"
	.string "Grandma said he's busy so I shouldn't\l"
	.string "bother him…$"

SandyshoreTown_EventScript_RuthNoticePlayer_Text_0:
	.string "{PLAYER}! There you are!\p"
	.string "Let's go, I bet the professor is already\n"
	.string "waiting for us!$"
