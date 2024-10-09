SandyshoreTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandyshoreTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SandyshoreTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto SandyshoreTown_EventScript_OnTransition
	return


SandyshoreTown_EventScript_InnSign::
	lock
	msgbox SandyshoreTown_EventScript_InnSign_Text_0
	release
	end


SandyshoreTown_EventScript_PreventExit_Route135::
	lock
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMarkAndDelay
	waitmovement 0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	compare VAR_TEMP_1, 19
	goto_if_eq SandyshoreTown_EventScript_PreventExit_Route135_2
	compare VAR_TEMP_1, 20
	goto_if_eq SandyshoreTown_EventScript_PreventExit_Route135_3
SandyshoreTown_EventScript_PreventExit_Route135_1:
	waitmovement 0
	release
	end

SandyshoreTown_EventScript_PreventExit_Route135_2:
	applymovement 2, Common_Movement_WalkLeft2
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject 2, DIR_SOUTH
	msgbox SandyshoreTown_Text_LittleGirlPreventExit
	closemessage
	applymovement 2, Common_Movement_WalkRight2
	goto SandyshoreTown_EventScript_PreventExit_Route135_1

SandyshoreTown_EventScript_PreventExit_Route135_3:
	applymovement 2, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject 2, DIR_SOUTH
	speakername SandyshoreTown_EventScript_PreventExit_Route135_Text_0
	msgbox SandyshoreTown_Text_LittleGirlPreventExit
	closemessage
	applymovement 2, Common_Movement_WalkRight
	goto SandyshoreTown_EventScript_PreventExit_Route135_1


SandyshoreTown_EventScript_LittleGirl::
	lock
	faceplayer
	speakername SandyshoreTown_EventScript_PreventExit_Route135_Text_0
	msgbox SandyshoreTown_EventScript_LittleGirl_Text_0
	closemessage
	end


SandyshoreTown_EventScript_RuthNoticePlayer::
	lock
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMarkAndDelay
	playbgm MUS_ENCOUNTER_MAY, FALSE
	playse SE_PIN
	waitmovement 0
	speakername CommonName_Ruth
	msgbox SandyshoreTown_EventScript_RuthNoticePlayer_Text_0
	turnobject 1, DIR_EAST
	msgbox SandyshoreTown_EventScript_RuthNoticePlayer_Text_1
	closemessage
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	waitmoncry
	applymovement 3, EnterPokeballMovement
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	removeobject 3
	addobject 3
	delay 32
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	removeobject 3
	delay 16
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	speakername CommonName_Ruth
	msgbox SandyshoreTown_EventScript_RuthNoticePlayer_Text_2
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
	fadedefaultbgm
	waitdooranim
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	release
	end


SandyshoreTown_EventScript_OnTransition::
	setflag FLAG_VISITED_SANDYSHORE_TOWN
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq SandyshoreTown_EventScript_OnTransition_2
	setflag FLAG_TEMP_10
	setflag FLAG_TEMP_11
SandyshoreTown_EventScript_OnTransition_1:
	goto_if_unset FLAG_RECEIVED_STARTER, SandyshoreTown_EventScript_OnTransition_5
	setvar VAR_TEMP_3, 0
	return

SandyshoreTown_EventScript_OnTransition_2:
	clearflag FLAG_TEMP_10
	clearflag FLAG_TEMP_11
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( EEVEE )
	removeobject 3
	addobject 3
	goto SandyshoreTown_EventScript_OnTransition_1

SandyshoreTown_EventScript_OnTransition_5:
	setvar VAR_TEMP_3, 1
	setobjectxyperm 2, 21, 2
	setobjectmovementtype 2, MOVEMENT_TYPE_LOOK_AROUND
	return


SandyshoreTown_EventScript_InnSign_Text_0:
	.string "Sandyshore Inn$"

SandyshoreTown_EventScript_PreventExit_Route135_Text_0:
	.string "Minnie$"

SandyshoreTown_EventScript_LittleGirl_Text_0:
	.string "I wanna go visit the professor too, but\n"
	.string "Grandma said he's busy and I shouldn't\l"
	.string "bother him…$"

SandyshoreTown_EventScript_RuthNoticePlayer_Text_0:
	.string "{PLAYER}! There you are!$"

SandyshoreTown_EventScript_RuthNoticePlayer_Text_1:
	.string "Eevee, you'll have to go in your ball for\n"
	.string "now.$"

SandyshoreTown_EventScript_RuthNoticePlayer_Text_2:
	.string "Let's go {PLAYER}, I bet the\n"
	.string "professor is already waiting for us!$"

SandyshoreTown_Text_LittleGirlPreventExit::
	.string "Ah, {PLAYER}!\p"
	.string "I saw Ruth in front of the Inn!\p"
	.string "I wanna go visit the professor too, but\n"
	.string "Grandma said he's busy…$"
