Sandyshore_Inn_2F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 7, Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_2
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 8, Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_3
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 9, Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_4
	.2byte 0

Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	clearflag FLAG_TEMP_7
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL_3
	return

Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
	clearflag FLAG_TEMP_7
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL_3
	return

Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_2:
	clearflag FLAG_TEMP_7
	setobjectxyperm 2, 20, 5
	turnobject 2, DIR_SOUTH
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL_3
	return

Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_3:
	setflag FLAG_TEMP_7
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	return

Sandyshore_Inn_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_4:
	setflag FLAG_TEMP_7
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	return


Sandyshore_Inn_EventScript_BrendanNoticePlayer::
	lockall
	delay 20
	turnobject 1, DIR_SOUTH
	applymovement 1, Common_Movement_WalkDown
	waitmovement 1
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_0
	closemessage
	delay 10
	applymovement 2, Sandyshore_Inn_2F_Movement_WalkUpToBrendanRuth
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Sandyshore_Inn_2F_Movement_WalkUpToBrendanPlayer
	waitmovement 2
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject 1, DIR_WEST
	delay 10
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_1
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_2
	closemessage
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_3
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_4
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_5
	closemessage
	turnobject 2, DIR_EAST
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_6
	closemessage
	applymovement 1, Common_Movement_WalkDown
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_7
	turnobject 1, DIR_WEST
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_8, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, Sandyshore_Inn_EventScript_BrendanNoticePlayer_3
	case YES, Sandyshore_Inn_EventScript_BrendanNoticePlayer_4
Sandyshore_Inn_EventScript_BrendanNoticePlayer_1:
	applymovement 1, Common_Movement_WalkInPlaceLeft
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_12
	applymovement 1, Common_Movement_WalkRight
	waitmovement 0
	turnobject 1, DIR_WEST
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_13
	turnobject 2, DIR_SOUTH
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_14
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	closemessage
	releaseall
	end

Sandyshore_Inn_EventScript_BrendanNoticePlayer_3:
	applymovement 2, Common_Movement_WalkInPlaceDown
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_9
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_10
	goto Sandyshore_Inn_EventScript_BrendanNoticePlayer_1

Sandyshore_Inn_EventScript_BrendanNoticePlayer_4:
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_11
	goto Sandyshore_Inn_EventScript_BrendanNoticePlayer_1


Sandyshore_Inn_EventScript_PreventPlayerLeavingBeforePickingMon::
	lock
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_PreventPlayerLeavingBeforePickingMon_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	release
	end


Sandyshore_Inn_EventScript_PreventPlayerLeavingBeforePickingMonLeft::
	lock
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_PreventPlayerLeavingBeforePickingMon_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	release
	end


Sandyshore_Inn_EventScript_PickMon::
	goto_if_set FLAG_RECEIVED_STARTER, Sandyshore_Inn_EventScript_PickMon_2
	lock
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RECEIVED_STARTER
	removeobject 4
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL_2
	addobject 4
	waitstate
	playfanfare MUS_OBTAIN_ITEM
	bufferleadmonspeciesname STR_VAR_1
	msgbox Sandyshore_Inn_EventScript_PickMon_Text_1, MSGBOX_AUTOCLOSE
	waitfanfare
	waitmessage
	applymovement 1, Common_Movement_WalkInPlaceLeft
	msgbox Sandyshore_Inn_EventScript_PickMon_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Sandyshore_Inn_EventScript_PickMon_5
	closemessage
Sandyshore_Inn_EventScript_PickMon_4:
	applymovement OBJ_EVENT_ID_PLAYER, Sandyshore_Inn_2F_Movement_PlayerWalkAfterChooseStarter
	waitmovement 0
	applymovement 2, Sandyshore_Inn_2F_Movement_RuthWalkToPokeballs
	waitmovement 0
	switch VAR_STARTER_MON
	case 0, Sandyshore_Inn_EventScript_PickMon_10
	case 1, Sandyshore_Inn_EventScript_PickMon_11
	case 2, Sandyshore_Inn_EventScript_PickMon_12
Sandyshore_Inn_EventScript_PickMon_8:
	msgbox Sandyshore_Inn_EventScript_PickMon_Text_3
	removeobject 4
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ITEM_BALL
	addobject 4
	closemessage
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	applymovement 2, Sandyshore_Inn_2F_Movement_RuthWalkAfterChooseStarter
	waitmovement 0
	delay 10
	applymovement 1, Sandyshore_Inn_2F_Movement_BrendanWalkAfterChooseStarter
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_PickMon_Text_4
	closemessage
	delay 20
	applymovement 2, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_PickMon_Text_5
	closemessage
	delay 60
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_PickMon_Text_6
	closemessage
	applymovement 2, Sandyshore_Inn_2F_Movement_RuthLeaveBrendansRoom1
	waitmovement 0
	msgbox Sandyshore_Inn_EventScript_PickMon_Text_7
	closemessage
	applymovement 2, Sandyshore_Inn_2F_Movement_RuthLeaveBrendansRoom2
	waitmovement 0
	removeobject 2
	setflag FLAG_TEMP_7
	setvar VAR_LITTLEROOT_INTRO_STATE, 8
	release
	end

Sandyshore_Inn_EventScript_PickMon_2:
	lock
	msgbox Sandyshore_Inn_EventScript_PickMon_Text_0
	release
	end

Sandyshore_Inn_EventScript_PickMon_5:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto Sandyshore_Inn_EventScript_PickMon_4

Sandyshore_Inn_EventScript_PickMon_10:
	bufferspeciesname STR_VAR_1, SPECIES_GROCKO
	goto Sandyshore_Inn_EventScript_PickMon_8

Sandyshore_Inn_EventScript_PickMon_11:
	bufferspeciesname STR_VAR_1, SPECIES_CHIMERA1
	goto Sandyshore_Inn_EventScript_PickMon_8

Sandyshore_Inn_EventScript_PickMon_12:
	bufferspeciesname STR_VAR_1, SPECIES_TOXATIEL
	goto Sandyshore_Inn_EventScript_PickMon_8


Sandyshore_Inn_EventScript_Ruth::
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq Sandyshore_Inn_EventScript_Ruth_2
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_eq Sandyshore_Inn_EventScript_Ruth_3
Sandyshore_Inn_EventScript_Ruth_1:
	end

Sandyshore_Inn_EventScript_Ruth_2:
	lock
	faceplayer
	msgbox Sandyshore_Inn_EventScript_Ruth_Text_0
	closemessage
	specialvar VAR_TEMP_3, GetPlayerFacingDirection
	switch VAR_TEMP_3
	case DIR_EAST, Sandyshore_Inn_EventScript_Ruth_8
	case DIR_NORTH, Sandyshore_Inn_EventScript_Ruth_9
	case DIR_WEST, Sandyshore_Inn_EventScript_Ruth_10
Sandyshore_Inn_EventScript_Ruth_6:
	applymovement 2, Sandyshore_Inn_2F_Movement_RuthGoToBrendansRoom
	fadenewbgm MUS_BIRCH_LAB
	waitmovement 0
	goto Sandyshore_Inn_EventScript_BrendanNoticePlayer
	goto Sandyshore_Inn_EventScript_Ruth_1

Sandyshore_Inn_EventScript_Ruth_3:
	lock
	faceplayer
	msgbox Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_14
	closemessage
	release
	goto Sandyshore_Inn_EventScript_Ruth_1

Sandyshore_Inn_EventScript_Ruth_8:
	applymovement OBJ_EVENT_ID_PLAYER, Sandyshore_Inn_2F_Movement_PlayerGoToBrendansRoom_1
	goto Sandyshore_Inn_EventScript_Ruth_6

Sandyshore_Inn_EventScript_Ruth_9:
	applymovement OBJ_EVENT_ID_PLAYER, Sandyshore_Inn_2F_Movement_PlayerGoToBrendansRoom_2
	goto Sandyshore_Inn_EventScript_Ruth_6

Sandyshore_Inn_EventScript_Ruth_10:
	applymovement OBJ_EVENT_ID_PLAYER, Sandyshore_Inn_2F_Movement_PlayerGoToBrendansRoom_3
	goto Sandyshore_Inn_EventScript_Ruth_6


Sandyshore_Inn_EventScript_Brendan::
	lock
	faceplayer
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_eq Sandyshore_Inn_EventScript_Brendan_2
	msgbox Sandyshore_Inn_EventScript_Brendan_Text_1
Sandyshore_Inn_EventScript_Brendan_1:
	closemessage
	release
	return

Sandyshore_Inn_EventScript_Brendan_2:
	msgbox Sandyshore_Inn_EventScript_Brendan_Text_0
	goto Sandyshore_Inn_EventScript_Brendan_1


Sandyshore_Inn_2F_Movement_StepLeftUp:
	walk_left
	walk_up
	step_end

Sandyshore_Inn_2F_Movement_WalkUpToBrendanPlayer:
	walk_up
	face_right
	step_end

Sandyshore_Inn_2F_Movement_WalkUpToBrendanRuth:
	walk_up
	walk_up
	walk_right
	step_end

Sandyshore_Inn_2F_Movement_PlayerWalkAfterChooseStarter:
	walk_left
	walk_left
	face_right
	step_end

Sandyshore_Inn_2F_Movement_RuthWalkToPokeballs:
	walk_right
	walk_right
	walk_down
	step_end

Sandyshore_Inn_2F_Movement_RuthWalkAfterChooseStarter:
	walk_up
	walk_left
	walk_left
	face_right
	step_end

Sandyshore_Inn_2F_Movement_BrendanWalkAfterChooseStarter:
	walk_left
	walk_up
	face_left
	step_end

Sandyshore_Inn_2F_Movement_RuthLeaveBrendansRoom1:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	face_up
	step_end

Sandyshore_Inn_2F_Movement_RuthLeaveBrendansRoom2:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Sandyshore_Inn_2F_EventScript_MudkipDoll::
	lock
	msgbox Sandyshore_Inn_2F_EventScript_MudkipDoll_Text_0
	closemessage
	release
	end


Sandyshore_Inn_2F_EventScript_OpenStarterBook::
	lock
	goto_if_set FLAG_READ_BRENDANS_NOTE_TOXATIEL, Sandyshore_Inn_2F_EventScript_OpenStarterBook_4
Sandyshore_Inn_2F_EventScript_OpenStarterBook_1:
	msgbox Sandyshore_Inn_2F_EventScript_OpenStarterBook_Text_1
	goto Sandyshore_Inn_2F_EventScript_StarterBook
	return

Sandyshore_Inn_2F_EventScript_OpenStarterBook_2:
	msgbox Sandyshore_Inn_2F_EventScript_OpenStarterBook_Text_0
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes
	goto Sandyshore_Inn_2F_EventScript_OpenStarterBook_1

Sandyshore_Inn_2F_EventScript_OpenStarterBook_3:
	goto_if_set FLAG_READ_BRENDANS_NOTE_CHIMERA, Sandyshore_Inn_2F_EventScript_OpenStarterBook_2
	goto Sandyshore_Inn_2F_EventScript_OpenStarterBook_1

Sandyshore_Inn_2F_EventScript_OpenStarterBook_4:
	goto_if_set FLAG_READ_BRENDANS_NOTE_GROCKO, Sandyshore_Inn_2F_EventScript_OpenStarterBook_3
	goto Sandyshore_Inn_2F_EventScript_OpenStarterBook_1


Sandyshore_Inn_2F_EventScript_StarterBook::
	multichoice 0, 0, MULTI_STARTER_NOTES, FALSE
	switch VAR_RESULT
	case 0, Sandyshore_Inn_2F_EventScript_StarterBook_3
	case 1, Sandyshore_Inn_2F_EventScript_StarterBook_4
	case 2, Sandyshore_Inn_2F_EventScript_StarterBook_5
	closemessage
	release
	end

Sandyshore_Inn_2F_EventScript_StarterBook_1:
	goto_if_set FLAG_READ_BRENDANS_NOTE_TOXATIEL, Sandyshore_Inn_2F_EventScript_StarterBook_11
Sandyshore_Inn_2F_EventScript_StarterBook_9:
	msgbox Sandyshore_Inn_2F_EventScript_StarterBook_Text_1
	goto Sandyshore_Inn_2F_EventScript_StarterBook
Sandyshore_Inn_2F_EventScript_StarterBook_7:
	closemessage
	release
	end

Sandyshore_Inn_2F_EventScript_StarterBook_3:
	showmonpic SPECIES_TOXATIEL, 10, 3
	msgbox Sandyshore_Inn_2F_Text_StarterBook_ToxatielNotes
	setflag FLAG_READ_BRENDANS_NOTE_TOXATIEL
	hidemonpic
	goto Sandyshore_Inn_2F_EventScript_StarterBook_1

Sandyshore_Inn_2F_EventScript_StarterBook_4:
	showmonpic SPECIES_GROCKO, 10, 3
	msgbox Sandyshore_Inn_2F_Text_StarterBook_GrockoNotes
	setflag FLAG_READ_BRENDANS_NOTE_GROCKO
	hidemonpic
	goto Sandyshore_Inn_2F_EventScript_StarterBook_1

Sandyshore_Inn_2F_EventScript_StarterBook_5:
	showmonpic SPECIES_CHIMERA1, 10, 3
	msgbox Sandyshore_Inn_2F_Text_StarterBook_ChimeraNotes
	setflag FLAG_READ_BRENDANS_NOTE_CHIMERA
	hidemonpic
	goto Sandyshore_Inn_2F_EventScript_StarterBook_1

Sandyshore_Inn_2F_EventScript_StarterBook_8:
	msgbox Sandyshore_Inn_2F_EventScript_StarterBook_Text_0, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq Sandyshore_Inn_2F_EventScript_StarterBook_17
	goto Sandyshore_Inn_2F_EventScript_StarterBook_7

Sandyshore_Inn_2F_EventScript_StarterBook_10:
	goto_if_set FLAG_READ_BRENDANS_NOTE_CHIMERA, Sandyshore_Inn_2F_EventScript_StarterBook_14
	goto Sandyshore_Inn_2F_EventScript_StarterBook_9

Sandyshore_Inn_2F_EventScript_StarterBook_11:
	goto_if_set FLAG_READ_BRENDANS_NOTE_GROCKO, Sandyshore_Inn_2F_EventScript_StarterBook_10
	goto Sandyshore_Inn_2F_EventScript_StarterBook_9

Sandyshore_Inn_2F_EventScript_StarterBook_14:
	goto_if_unset FLAG_READ_BRENDANS_NOTE_KYOGRE, Sandyshore_Inn_2F_EventScript_StarterBook_8
	goto Sandyshore_Inn_2F_EventScript_StarterBook_9

Sandyshore_Inn_2F_EventScript_StarterBook_17:
	msgbox Sandyshore_Inn_2F_Text_StarterBook_KyogreNotes
	setflag FLAG_READ_BRENDANS_NOTE_KYOGRE
	goto Sandyshore_Inn_2F_EventScript_StarterBook_7


Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes::
	multichoice 0, 0, MULTI_STARTER_NOTES_KYOGRE, TRUE
	switch VAR_RESULT
	case 0, Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_3
	case 1, Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_4
	case 2, Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_5
	case 3, Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_6
	closemessage
	release
	end

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_1:
	hidemonpic
	goto_if_set FLAG_READ_BRENDANS_NOTE_TOXATIEL, Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_12
Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_10:
	msgbox Sandyshore_Inn_2F_EventScript_StarterBook_Text_1
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes
Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_8:
	closemessage
	release
	end

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_3:
	showmonpic SPECIES_TOXATIEL, 10, 3
	msgbox Sandyshore_Inn_2F_Text_StarterBook_ToxatielNotes
	setflag FLAG_READ_BRENDANS_NOTE_TOXATIEL
	hidemonpic
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_1

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_4:
	showmonpic SPECIES_GROCKO, 10, 3
	msgbox Sandyshore_Inn_2F_Text_StarterBook_GrockoNotes
	setflag FLAG_READ_BRENDANS_NOTE_GROCKO
	hidemonpic
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_1

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_5:
	showmonpic SPECIES_CHIMERA1, 10, 3
	msgbox Sandyshore_Inn_2F_Text_StarterBook_ChimeraNotes
	setflag FLAG_READ_BRENDANS_NOTE_CHIMERA
	hidemonpic
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_1

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_6:
	msgbox Sandyshore_Inn_2F_Text_StarterBook_KyogreNotes
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_1

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_9:
	msgbox Sandyshore_Inn_2F_EventScript_StarterBook_Text_0, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_18
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_8

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_11:
	goto_if_set FLAG_READ_BRENDANS_NOTE_CHIMERA, Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_15
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_10

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_12:
	goto_if_set FLAG_READ_BRENDANS_NOTE_GROCKO, Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_11
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_10

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_15:
	goto_if_unset FLAG_READ_BRENDANS_NOTE_KYOGRE, Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_9
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_10

Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_18:
	msgbox Sandyshore_Inn_2F_Text_StarterBook_KyogreNotes
	setflag FLAG_READ_BRENDANS_NOTE_KYOGRE
	goto Sandyshore_Inn_2F_EventScript_StarterBook_KyogreNotes_8


Sandyshore_Inn_2F_EventScript_Woman::
	msgbox Sandyshore_Inn_2F_EventScript_Woman_Text_0, MSGBOX_NPC
	return


Sandyshore_Inn_2F_EventScript_Man::
	msgbox Sandyshore_Inn_2F_EventScript_Man_Text_0, MSGBOX_NPC
	return


Sandyshore_Inn_2F_EventScript_Boy::
	return


Sandyshore_Inn_2F_EventScript_OldWoman::
	return


Sandyshore_Inn_2F_EventScript_OldMan::
	return


Sandyshore_Inn_2F_Movement_RuthGoToBrendansRoom:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

Sandyshore_Inn_2F_Movement_PlayerGoToBrendansRoom_1:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Sandyshore_Inn_2F_Movement_PlayerGoToBrendansRoom_2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Sandyshore_Inn_2F_Movement_PlayerGoToBrendansRoom_3:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_0:
	.string "Oh! You're already here!$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_1:
	.string "Ruth: Professor…$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_2:
	.string "Brendan: I'm not a professor yet, I'm\n"
	.string "still in the middle of writing my\l"
	.string "thesis…$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_3:
	.string "… I'm sorry, it's eating so much of my\n"
	.string "time I haven't had the time to tidy up.$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_4:
	.string "Actually, that's part of the reason I\n"
	.string "wanted to talk to the both of you.\p"
	.string "You already have experience with\n"
	.string "Pokémon, right?$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_5:
	.string "Ruth: Yes! I've already had a Pokémon\n"
	.string "since not too long ago!\p"
	.string "And {PLAYER}'s family has a Skitty at\n"
	.string "home.$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_6:
	.string "Brendan: Perfect.$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_7:
	.string "These are three rare Pokémon I have\n"
	.string "been studying.\p"
	.string "I caught them in the wild, so they\n"
	.string "prefer to be outside… but at the\l"
	.string "moment I am struggling to find time to\l"
	.string "properly care for all three of them.$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_8:
	.string "Would you two be able to take one of\n"
	.string "them each?$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_9:
	.string "Ruth: {PLAYER}, this is not the time\n"
	.string "to joke around!\p"
	.string "The professor might think you're\n"
	.string "serious!$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_10:
	.string "Of course, we're always happy to help\n"
	.string "out!$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_11:
	.string "Ruth: Of course, we're always happy to\n"
	.string "help out!$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_12:
	.string "Brendan: Thanks, that really means a\n"
	.string "lot to me.$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_13:
	.string "Please, go ahead and pick one.\p"
	.string "There should be some notes about them\n"
	.string "on my desk to help you choose.$"

Sandyshore_Inn_EventScript_BrendanNoticePlayer_Text_14:
	.string "Ruth: {PLAYER}, you should pick one\n"
	.string "first, since you don't own a Pokémon\l"
	.string "yet.$"

Sandyshore_Inn_EventScript_PreventPlayerLeavingBeforePickingMon_Text_0:
	.string "Where are you going, {PLAYER}?$"

Sandyshore_Inn_EventScript_PickMon_Text_0:
	.string "It's the professor's last Pokémon…$"

Sandyshore_Inn_EventScript_PickMon_Text_1:
	.string "{PLAYER} obtained the {STR_VAR_1}!$"

Sandyshore_Inn_EventScript_PickMon_Text_2:
	.string "Brendan: While you're at it, why not\n"
	.string "give a nickname to that\l"
	.string "{STR_VAR_1}?$"

Sandyshore_Inn_EventScript_PickMon_Text_3:
	.string "Ruth: Then I'll choose this {STR_VAR_1}!$"

Sandyshore_Inn_EventScript_PickMon_Text_4:
	.string "Brendan: Thanks for helping me out!\n"
	.string "Please take good care of these two!$"

Sandyshore_Inn_EventScript_PickMon_Text_5:
	.string "Hey, {PLAYER}…\p"
	.string "Now that you have a Pokémon, you know\n"
	.string "what we should do?$"

Sandyshore_Inn_EventScript_PickMon_Text_6:
	.string "I should teach you how to catch a\n"
	.string "Pokémon, of course!\p"
	.string "What did you think? Battle?\p"
	.string "Nah, that wouldn't be fair.\p"
	.string "I have more experience AND my Pokémon\n"
	.string "has a type advantage.\p"
	.string "You should practice against wild\n"
	.string "Pokémon first.$"

Sandyshore_Inn_EventScript_PickMon_Text_7:
	.string "I'll go grab some Pokéballs, meet me at\n"
	.string "the town exit!$"

Sandyshore_Inn_EventScript_Ruth_Text_0:
	.string "{PLAYER}! Let's find out why the\n"
	.string "Professor called!$"

Sandyshore_Inn_EventScript_Brendan_Text_0:
	.string "Go ahead and choose one!\p"
	.string "There should be some notes about them\n"
	.string "on my desk so you can see which one\l"
	.string "fits best for you.$"

Sandyshore_Inn_EventScript_Brendan_Text_1:
	.string "Please take good care of this little\n"
	.string "one!$"

Sandyshore_Inn_2F_EventScript_MudkipDoll_Text_0:
	.string "It's a cute little Mudkip doll!$"

Sandyshore_Inn_2F_EventScript_OpenStarterBook_Text_0:
	.string "It's the Professor's notes about the\n"
	.string "three Pokémon… And a mystery note.\p"
	.string "Open at which page?$"

Sandyshore_Inn_2F_EventScript_OpenStarterBook_Text_1:
	.string "It's the Professor's notes about the\n"
	.string "three Pokémon…\p"
	.string "Open at which page?$"

Sandyshore_Inn_2F_EventScript_StarterBook_Text_0:
	.string "… There's another note between the\n"
	.string "pages. Read it?$"

Sandyshore_Inn_2F_EventScript_StarterBook_Text_1:
	.string "Open which page?$"

Sandyshore_Inn_2F_EventScript_Woman_Text_0:
	.string "This little remote town is a hidden gem,\n"
	.string "with its mild sea breeze and the\l"
	.string "colorful reef just off the shores.$"

Sandyshore_Inn_2F_EventScript_Man_Text_0:
	.string "We come here for vacation every year.\p"
	.string "It's nice to get away from the busy city\n"
	.string "life every once in a while.$"

Sandyshore_Inn_2F_Text_StarterBook_ToxatielNotes::
	.string "Toxatiel - A rare bird Pokémon from the\n"
	.string "treetops of Fortree City.\p"
	.string "This little bird is one of the most\n"
	.string "acrobatic fliers I've seen!\p"
	.string "Its flight resembles bug-type Pokémon\n"
	.string "like Yanma rather than birds, which\l"
	.string "allows it to hover in the air and even\l"
	.string "fly backwards.\p"
	.string "Its saliva irritates the skin, I suspect\n"
	.string "it to be toxic, possibly for use in\l"
	.string "hunting insects.$"

Sandyshore_Inn_2F_Text_StarterBook_GrockoNotes::
	.string "Grocko - An elusive rock-type Pokémon\n"
	.string "from the Cave of Origin.\p"
	.string "I found this curious little Pokémon\n"
	.string "snuggled up in a cluster of crystals.\p"
	.string "Its feet aren't sticky, but I haven't\n"
	.string "yet found a surface it can't climb.\p"
	.string "It can even cling to ceilings without\n"
	.string "any effort!\p"
	.string "It loves belly rubs, but doesn't seem to\n"
	.string "like when I touch the gems on its head\l"
	.string "and tail.$"

Sandyshore_Inn_2F_Text_StarterBook_ChimeraNotes::
	.string "Chimera - A feisty fighting-type from\n"
	.string "the cliffs of Mt. Ember.\p"
	.string "This especially energetic little\n"
	.string "Pokémon picks fights with everything.\p"
	.string "Even inanimate objects aren't safe\n"
	.string "from its headbutt.\p"
	.string "I am so glad the innkeeper isn't too mad\n"
	.string "about all the broken chairs…$"

Sandyshore_Inn_2F_Text_StarterBook_KyogreNotes::
	.string "Needs text, and Jojo couldn't think of\n"
	.string "one yet. Basically, this is a cryptic\l"
	.string "note about Brendans observation of\l"
	.string "the tides and ocean currents at the\l"
	.string "nearby underwater ruins, suggesting\l"
	.string "there's something big down there.$"
