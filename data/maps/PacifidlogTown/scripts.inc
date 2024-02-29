PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	.byte 0

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


PacifidlogTown_EventScript_RayquazaPlaque::
	msgbox PacifidlogTown_EventScript_RayquazaPlaque_Text_0, MSGBOX_SIGN
	end


PacifidlogTown_EventScript_Woman_1::
	lock
	faceplayer
	msgbox PacifidlogTown_EventScript_Woman_1_Text_0
	closemessage
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end


PacifidlogTown_EventScript_Woman_2::
	lock
	faceplayer
	msgbox PacifidlogTown_EventScript_Woman_2_Text_0
	closemessage
	turnobject VAR_LAST_TALKED, DIR_NORTH
	release
	end


PacifidlogTown_EventScript_Fisherman::
	lock
	faceplayer
	msgbox PacifidlogTown_EventScript_Fisherman_Text_0
	closemessage
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end


PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_EventScript_NinjaBoy_Text_0, MSGBOX_NPC
	end


PacifidlogTown_EventScript_OldMan::
	lock
	faceplayer
	msgbox PacifidlogTown_EventScript_OldMan_Text_0
	closemessage
	turnobject VAR_LAST_TALKED, DIR_NORTH
	release
	end


PacifidlogTown_OnTransition::
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	switch VAR_PACIFIDLOG_TOWN_STATE
	case 0, PacifidlogTown_OnTransition_3
	case 1, PacifidlogTown_OnTransition_4
	case 2, PacifidlogTown_OnTransition_5
	case 3, PacifidlogTown_OnTransition_5
	setflag FLAG_TEMP_10
	setobjectxyperm 4, 32, 28
	setobjectmovementtype 4, MOVEMENT_TYPE_LOOK_AROUND
	removeobject 8
PacifidlogTown_OnTransition_1:
	end

PacifidlogTown_OnTransition_3:
	setflag FLAG_TEMP_10
	goto PacifidlogTown_OnTransition_1

PacifidlogTown_OnTransition_4:
	setobjectxyperm 8, 66, 28
	goto PacifidlogTown_OnTransition_1

PacifidlogTown_OnTransition_5:
	setobjectxyperm 8, 36, 30
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	goto PacifidlogTown_OnTransition_1


PacifidlogTown_EventScript_MeetRuth::
	lock
	opendoor 65, 27
	waitdooranim
	clearflag FLAG_TEMP_10
	addobject 8
	showobjectat 8, MAP_PACIFIDLOG_TOWN
	delay 10
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 8
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement 8, Common_Movement_Delay48
	waitmovement 8
	msgbox PacifidlogTown_EventScript_MeetRuth_Text_0
	closemessage
	applymovement 8, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	closedoor 65, 27
	waitdooranim
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PacifidlogTown_EventScript_MeetRuth_Text_1
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PacifidlogTown_EventScript_MeetRuth_Text_2
	applymovement 8, Common_Movement_WalkInPlaceDown
	setvar VAR_PACIFIDLOG_TOWN_STATE, 1
	msgbox PacifidlogTown_EventScript_MeetRuth_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PacifidlogTown_EventScript_MeetRuth_2
	msgbox PacifidlogTown_EventScript_MeetRuth_Text_4
	closemessage
	applymovement 8, Common_Movement_WalkRight
	waitmovement 0
	turnobject 8, DIR_SOUTH
PacifidlogTown_EventScript_MeetRuth_1:
	release
	end

PacifidlogTown_EventScript_MeetRuth_2:
	goto PacifidlogTown_EventScript_RuthBattle
	goto PacifidlogTown_EventScript_MeetRuth_1


PacifidlogTown_EventScript_Ruth::
	lock
	faceplayer
	switch VAR_PACIFIDLOG_TOWN_STATE
	case 1, PacifidlogTown_EventScript_Ruth_3
	case 2, PacifidlogTown_EventScript_Ruth_4
	case 3, PacifidlogTown_EventScript_Ruth_5
PacifidlogTown_EventScript_Ruth_1:
	release
	end

PacifidlogTown_EventScript_Ruth_3:
	msgbox PacifidlogTown_EventScript_Ruth_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PacifidlogTown_EventScript_Ruth_6
	goto PacifidlogTown_EventScript_Ruth_1

PacifidlogTown_EventScript_Ruth_4:
	faceplayer
	goto PacifidlogTown_EventScript_RuthBoatScene
	goto PacifidlogTown_EventScript_Ruth_1

PacifidlogTown_EventScript_Ruth_5:
	faceplayer
	msgbox PacifidlogTown_EventScript_Ruth_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PacifidlogTown_EventScript_Ruth_8
	msgbox PacifidlogTown_EventScript_Ruth_Text_3
	closemessage
	release
	end

PacifidlogTown_EventScript_Ruth_6:
	goto PacifidlogTown_EventScript_RuthBattle
	goto PacifidlogTown_EventScript_Ruth_1

PacifidlogTown_EventScript_Ruth_8:
	msgbox PacifidlogTown_EventScript_Ruth_Text_2
	closemessage
	goto PacifidlogTown_EventScript_LeaveForSlateport
	goto PacifidlogTown_EventScript_Ruth_1


PacifidlogTown_EventScript_RuthBattle::
	switch VAR_STARTER_MON
	case 0, PacifidlogTown_EventScript_RuthBattle_3
	case 1, PacifidlogTown_EventScript_RuthBattle_4
	case 2, PacifidlogTown_EventScript_RuthBattle_5
PacifidlogTown_EventScript_RuthBattle_1:
	goto PacifidlogTown_EventScript_AfterRuthBattle
	return

PacifidlogTown_EventScript_RuthBattle_3:
	trainerbattle_no_intro TRAINER_RUTH_PACIFIDLOG_TOXATIEL, PacifidlogTown_EventScript_RuthBattle_Text_0
	goto PacifidlogTown_EventScript_RuthBattle_1

PacifidlogTown_EventScript_RuthBattle_4:
	trainerbattle_no_intro TRAINER_RUTH_PACIFIDLOG_GROCKO, PacifidlogTown_EventScript_RuthBattle_Text_0
	goto PacifidlogTown_EventScript_RuthBattle_1

PacifidlogTown_EventScript_RuthBattle_5:
	trainerbattle_no_intro TRAINER_RUTH_PACIFIDLOG_CHIMERA, PacifidlogTown_EventScript_RuthBattle_Text_0
	goto PacifidlogTown_EventScript_RuthBattle_1


PacifidlogTown_EventScript_AfterRuthBattle::
	lock
	specialvar VAR_TEMP_1, GetPlayerFacingDirection
	switch VAR_TEMP_1
	case DIR_SOUTH, PacifidlogTown_EventScript_AfterRuthBattle_3
	case DIR_EAST, PacifidlogTown_EventScript_AfterRuthBattle_3
	case DIR_WEST, PacifidlogTown_EventScript_AfterRuthBattle_3
	case DIR_NORTH, PacifidlogTown_EventScript_AfterRuthBattle_4
PacifidlogTown_EventScript_AfterRuthBattle_1:
	msgbox PacifidlogTown_EventScript_AfterRuthBattle_Text_0
	switch VAR_TEMP_1
	case DIR_NORTH, PacifidlogTown_EventScript_AfterRuthBattle_7
	case DIR_EAST, PacifidlogTown_EventScript_AfterRuthBattle_8
	case DIR_WEST, PacifidlogTown_EventScript_AfterRuthBattle_9
	case DIR_SOUTH, PacifidlogTown_EventScript_AfterRuthBattle_10
PacifidlogTown_EventScript_AfterRuthBattle_5:
	waitmovement 0
	msgbox PacifidlogTown_EventScript_AfterRuthBattle_Text_1
	closemessage
	delay 10
	switch VAR_TEMP_1
	case DIR_NORTH, PacifidlogTown_EventScript_AfterRuthBattle_13
	case DIR_EAST, PacifidlogTown_EventScript_AfterRuthBattle_14
	case DIR_WEST, PacifidlogTown_EventScript_AfterRuthBattle_15
	case DIR_SOUTH, PacifidlogTown_EventScript_AfterRuthBattle_16
PacifidlogTown_EventScript_AfterRuthBattle_11:
	waitmovement 0
	msgbox PacifidlogTown_EventScript_AfterRuthBattle_Text_2
	closemessage
	switch VAR_TEMP_1
	case DIR_NORTH, PacifidlogTown_EventScript_AfterRuthBattle_19
	case DIR_SOUTH, PacifidlogTown_EventScript_AfterRuthBattle_19
	case DIR_WEST, PacifidlogTown_EventScript_AfterRuthBattle_19
	case DIR_EAST, PacifidlogTown_EventScript_AfterRuthBattle_20
PacifidlogTown_EventScript_AfterRuthBattle_17:
	waitmovement 0
	goto_if_set FLAG_TEMP_1, PacifidlogTown_EventScript_AfterRuthBattle_22
PacifidlogTown_EventScript_AfterRuthBattle_21:
	setvar VAR_PACIFIDLOG_TOWN_STATE, 2
	setflag FLAG_DEFEATED_RIVAL_1
	setobjectxyperm 8, 36, 30
	setobjectxy 8, 36, 30
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	release
	end

PacifidlogTown_EventScript_AfterRuthBattle_3:
	turnobject 8, DIR_SOUTH
	goto PacifidlogTown_EventScript_AfterRuthBattle_1

PacifidlogTown_EventScript_AfterRuthBattle_4:
	turnobject 8, DIR_WEST
	goto PacifidlogTown_EventScript_AfterRuthBattle_1

PacifidlogTown_EventScript_AfterRuthBattle_7:
	applymovement 8, Common_Movement_WalkInPlaceDown
	goto PacifidlogTown_EventScript_AfterRuthBattle_5

PacifidlogTown_EventScript_AfterRuthBattle_8:
	applymovement 8, Common_Movement_WalkInPlaceLeft
	goto PacifidlogTown_EventScript_AfterRuthBattle_5

PacifidlogTown_EventScript_AfterRuthBattle_9:
	applymovement 8, Common_Movement_WalkInPlaceRight
	goto PacifidlogTown_EventScript_AfterRuthBattle_5

PacifidlogTown_EventScript_AfterRuthBattle_10:
	applymovement 8, Common_Movement_WalkInPlaceUp
	goto PacifidlogTown_EventScript_AfterRuthBattle_5

PacifidlogTown_EventScript_AfterRuthBattle_13:
	applymovement 8, Common_Movement_WalkInPlaceDown
	goto PacifidlogTown_EventScript_AfterRuthBattle_11

PacifidlogTown_EventScript_AfterRuthBattle_14:
	applymovement 8, Common_Movement_WalkInPlaceLeft
	goto PacifidlogTown_EventScript_AfterRuthBattle_11

PacifidlogTown_EventScript_AfterRuthBattle_15:
	applymovement 8, Common_Movement_WalkInPlaceRight
	goto PacifidlogTown_EventScript_AfterRuthBattle_11

PacifidlogTown_EventScript_AfterRuthBattle_16:
	applymovement 8, Common_Movement_WalkInPlaceUp
	goto PacifidlogTown_EventScript_AfterRuthBattle_11

PacifidlogTown_EventScript_AfterRuthBattle_19:
	applymovement 8, PacifidlogTown_Movement_RuthLeaveForBoat
	goto PacifidlogTown_EventScript_AfterRuthBattle_17

PacifidlogTown_EventScript_AfterRuthBattle_20:
	applymovement 8, PacifidlogTown_Movement_RuthLeaveForBoat2
	goto PacifidlogTown_EventScript_AfterRuthBattle_17

PacifidlogTown_EventScript_AfterRuthBattle_22:
	goto PacifidlogTown_EventScript_AfterRuthBattle_21


PacifidlogTown_EventScript_RuthBoatScene::
	delay 16
	applymovement 8, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PacifidlogTown_EventScript_RuthBoatScene_Text_0
	closemessage
	turnobject 8, DIR_NORTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement 4, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox PacifidlogTown_EventScript_RuthBoatScene_Text_1
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PacifidlogTown_EventScript_RuthBoatScene_Text_2
	closemessage
	applymovement 8, Common_Movement_WalkInPlaceRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox PacifidlogTown_EventScript_RuthBoatScene_Text_3
	closemessage
	delay 20
	goto PacifidlogTown_EventScript_MatchCallTutorial
	return


PacifidlogTown_EventScript_MatchCallTutorial::
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	setflag FLAG_STARTED_MC_TUTORIAL
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	waitstate
	switch VAR_RESULT
	case 0, PacifidlogTown_EventScript_MatchCallTutorial_3
	case 1, PacifidlogTown_EventScript_MatchCallTutorial_3
	case 2, PacifidlogTown_EventScript_MatchCallTutorial_3
	case 4, PacifidlogTown_EventScript_MatchCallTutorial_3
	case 5, PacifidlogTown_EventScript_MatchCallTutorial_3
	case 6, PacifidlogTown_EventScript_MatchCallTutorial_3
	case 7, PacifidlogTown_EventScript_MatchCallTutorial_3
	case MULTI_B_PRESSED, PacifidlogTown_EventScript_MatchCallTutorial_3
PacifidlogTown_EventScript_MatchCallTutorial_1:
	special OpenPokenavForTutorial
	waitstate
	setvar VAR_PACIFIDLOG_TOWN_STATE, 3
	delay 20
	applymovement 8, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox PacifidlogTown_EventScript_MatchCallTutorial_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PacifidlogTown_EventScript_MatchCallTutorial_4
	msgbox PacifidlogTown_EventScript_Ruth_Text_3
	closemessage
	release
	end

PacifidlogTown_EventScript_MatchCallTutorial_3:
	msgbox PacifidlogTown_EventScript_MatchCallTutorial_Text_0
	closemessage
	delay 20
	goto PacifidlogTown_EventScript_MatchCallTutorial
	goto PacifidlogTown_EventScript_MatchCallTutorial_1

PacifidlogTown_EventScript_MatchCallTutorial_4:
	msgbox PacifidlogTown_EventScript_Ruth_Text_2
	closemessage
	goto PacifidlogTown_EventScript_LeaveForSlateport
	return


PacifidlogTown_EventScript_LeaveForSlateport::
	applymovement 4, PacifidlogTown_Movement_SailorEnterBoat
	applymovement 8, PacifidlogTown_Movement_RuthEnterBoat
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerEnterBoat
	waitmovement 4
	setflag FLAG_TEMP_9
	removeobject 4
	waitmovement 8
	removeobject 8
	waitmovement OBJ_EVENT_ID_PLAYER
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_PACIFIDLOG_TOWN
	delay 20
	applymovement 7, PacifidlogTown_Movement_BoatLeaveForSlateport
	waitmovement 0
	setvar VAR_PACIFIDLOG_TOWN_STATE, 4
	warp MAP_SLATEPORT_CITY, 37, 40
	return


PacifidlogTown_EventScript_Sailor::
	lock
	faceplayer
	switch VAR_PACIFIDLOG_TOWN_STATE
	case 0, PacifidlogTown_EventScript_Sailor_3
	case 1, PacifidlogTown_EventScript_Sailor_3
	case 2, PacifidlogTown_EventScript_Sailor_3
	case 3, PacifidlogTown_EventScript_Sailor_3
	case 4, PacifidlogTown_EventScript_Sailor_4
PacifidlogTown_EventScript_Sailor_1:
	closemessage
	release
	end

PacifidlogTown_EventScript_Sailor_3:
	msgbox PacifidlogTown_EventScript_Sailor_Text_0
	goto PacifidlogTown_EventScript_Sailor_1

PacifidlogTown_EventScript_Sailor_4:
	msgbox PacifidlogTown_EventScript_Sailor_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PacifidlogTown_EventScript_Sailor_5
	goto PacifidlogTown_EventScript_Sailor_1

PacifidlogTown_EventScript_Sailor_5:
	closemessage
	specialvar VAR_TEMP_1, GetPlayerFacingDirection
	switch VAR_TEMP_1
	case DIR_WEST, PacifidlogTown_EventScript_Sailor_9
	case DIR_NORTH, PacifidlogTown_EventScript_Sailor_10
PacifidlogTown_EventScript_Sailor_7:
	waitmovement 4
	removeobject 4
	waitmovement OBJ_EVENT_ID_PLAYER
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_PACIFIDLOG_TOWN
	delay 20
	applymovement 7, PacifidlogTown_Movement_BoatLeaveForSlateport
	waitmovement 0
	warp MAP_SLATEPORT_CITY, 37, 40
	goto PacifidlogTown_EventScript_Sailor_1

PacifidlogTown_EventScript_Sailor_9:
	applymovement 4, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerEnterBoat_1
	goto PacifidlogTown_EventScript_Sailor_7

PacifidlogTown_EventScript_Sailor_10:
	applymovement 4, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerEnterBoat_2
	goto PacifidlogTown_EventScript_Sailor_7


PacifidlogTown_Movement_RuthLeaveForBoat:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

PacifidlogTown_Movement_RuthLeaveForBoat2:
	walk_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

PacifidlogTown_Movement_RuthEnterBoat:
	walk_up
	walk_left
	walk_diag_southwest
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

PacifidlogTown_Movement_SailorEnterBoat:
	walk_left
	walk_diag_southwest
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

PacifidlogTown_Movement_PlayerEnterBoat:
	walk_left
	walk_up
	walk_left
	walk_diag_southwest
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

PacifidlogTown_Movement_BoatLeaveForSlateport:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PacifidlogTown_Movement_PlayerEnterBoat_1:
	walk_left
	walk_up
	step_end

PacifidlogTown_Movement_PlayerEnterBoat_2:
	walk_up
	walk_up
	step_end

PacifidlogTown_EventScript_TownSign_Text_0:
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the clear sky smiles upon the\n"
	.string "waters.”$"

PacifidlogTown_EventScript_RayquazaPlaque_Text_0:
	.string "The plaque says that this statue\n"
	.string "depicts Rayquaza, the legendary\l"
	.string "Pokémon of the sky.$"

PacifidlogTown_EventScript_Woman_1_Text_0:
	.string "Our house got swept away in the huge\n"
	.string "tidal wave that destroyed the old\l"
	.string "Pacifidlog.\p"
	.string "I wonder if it is still there somewhere,\n"
	.string "at the bottom of the ocean…$"

PacifidlogTown_EventScript_Woman_2_Text_0:
	.string "The weather is always clear in New\n"
	.string "Pacifidlog.\p"
	.string "That's because of the legendary\n"
	.string "Pokémon that lives on top of the Sky\l"
	.string "Pillar.\p"
	.string "Who knows if we would have been able to\n"
	.string "rebuild the town here at all if it\l"
	.string "weren't for its help.$"

PacifidlogTown_EventScript_Fisherman_Text_0:
	.string "This is my favourite fishing spot.\p"
	.string "I caught a huge Magikarp here\n"
	.string "yesterday!$"

PacifidlogTown_EventScript_NinjaBoy_Text_0:
	.string "I'm sad our town isn't floating on the\n"
	.string "ocean anymore.\p"
	.string "But the big tower is pretty cool too!$"

PacifidlogTown_EventScript_OldMan_Text_0:
	.string "Rayquaza rests on top of this tower.\p"
	.string "It keeps our town safe from the wrath\n"
	.string "of the elements, and in turn, we make\l"
	.string "sure it can rest undisturbed.$"

PacifidlogTown_EventScript_MeetRuth_Text_0:
	.string "{PLAYER}!$"

PacifidlogTown_EventScript_MeetRuth_Text_1:
	.string "You got here faster than I expected!\p"
	.string "How did you manage? Were you able to\n"
	.string "catch some Pokémon?$"

PacifidlogTown_EventScript_MeetRuth_Text_2:
	.string "If you run out of Pokéballs, you can buy\n"
	.string "more at the mart here.\p"
	.string "They also sell potions and some other\n"
	.string "useful items!$"

PacifidlogTown_EventScript_MeetRuth_Text_3:
	.string "You should check it out!\p"
	.string "…\p"
	.string "Since you got here so quickly, how\n"
	.string "about I test your skills in a quick\l"
	.string "battle?$"

PacifidlogTown_EventScript_MeetRuth_Text_4:
	.string "You want to prepare first? That's fine,\n"
	.string "I'll wait here!$"

PacifidlogTown_EventScript_Ruth_Text_0:
	.string "Are you ready?$"

PacifidlogTown_EventScript_Ruth_Text_1:
	.string "Are you ready to leave?$"

PacifidlogTown_EventScript_Ruth_Text_2:
	.string "Perfect, let's go!$"

PacifidlogTown_EventScript_Ruth_Text_3:
	.string "I see. But make it quick, okay?$"

PacifidlogTown_EventScript_RuthBattle_Text_0:
	.string "…$"

PacifidlogTown_EventScript_AfterRuthBattle_Text_0:
	.string "Ha…\pHahaha!$"

PacifidlogTown_EventScript_AfterRuthBattle_Text_1:
	.string "I can't believe I lost!\p"
	.string "You only just got a Pokémon and you\n"
	.string "already beat me!\p"
	.string "I think you have a knack for this,\n"
	.string "{PLAYER}.$"

PacifidlogTown_EventScript_AfterRuthBattle_Text_2:
	.string "You know what?\p"
	.string "We'll make this a challenge!\p"
	.string "We fight the gym leaders and see who\n"
	.string "can collect the most badges!\p"
	.string "I think I know just the right person to\n"
	.string "get us to the mainland too.$"

PacifidlogTown_EventScript_RuthBoatScene_Text_0:
	.string "Ruth: This is Captain Moore, probably\n"
	.string "the best sailor in all of Pacifidlog.\p"
	.string "He'll be able to get us to Slateport no\n"
	.string "problem!$"

PacifidlogTown_EventScript_RuthBoatScene_Text_1:
	.string "Cpt. Moore: The currents between here\n"
	.string "and Slateport are vicious, and it's only\l"
	.string "gotten worse in recent times.\p"
	.string "The weather on the open seas has been\n"
	.string "awful ever since Kyogre woke from its\l"
	.string "slumber.\p"
	.string "I'm glad you two are asking for help\n"
	.string "from someone experienced.\p"
	.string "We can set sail right now, if the two of\n"
	.string "you are ready.$"

PacifidlogTown_EventScript_RuthBoatScene_Text_2:
	.string "Ruth: Thank you, sir!\p"
	.string "And yes, we're ready to go!\p"
	.string "...\p"
	.string "Wait.$"

PacifidlogTown_EventScript_RuthBoatScene_Text_3:
	.string "{PLAYER}, you should call your mom and\n"
	.string "tell her where you're going.\p"
	.string "You have your PokéNav with you, right?$"

PacifidlogTown_EventScript_MatchCallTutorial_Text_0:
	.string "Come on, we shouldn't let Mr. Moore wait!\p"
	.string "Go give your mom a quick call!$"

PacifidlogTown_EventScript_MatchCallTutorial_Text_1:
	.string "Nice! Now, are you ready to leave?$"

PacifidlogTown_EventScript_Sailor_Text_0:
	.string "The sea between New Pacifidlog and\n"
	.string "Slateport has a fast-running tide.\p"
	.string "I strongly advise against trying to\n"
	.string "surf there on the back of a Pokémon.\p"
	.string "If you must go to Slateport, it's much\n"
	.string "safer to go by boat.$"

PacifidlogTown_EventScript_Sailor_Text_1:
	.string "Cpt. Moore: Do you want to sail to\n"
	.string "Slateport?$"
