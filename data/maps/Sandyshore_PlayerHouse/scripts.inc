Sandyshore_PlayerHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, Sandyshore_Playerhouse_EventScript_MomPleaseSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, Sandyshore_Playerhouse_EventScript_MomGiveRunningShoes
	.2byte 0

Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_2
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_3
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_4
	.2byte 0

Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	setobjectxy 1, 8, 3
	turnobject 1, DIR_NORTH
	return

Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
	setobjectxy 1, 8, 3
	turnobject 1, DIR_NORTH
	return

Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_2:
	setobjectxy 1, 8, 3
	turnobject 1, DIR_NORTH
	return

Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_3:
	setobjectxy 1, 8, 3
	turnobject 1, DIR_NORTH
	return

Sandyshore_PlayerHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_4:
	setobjectxy 1, 8, 3
	turnobject 1, DIR_NORTH
	return


Sandyshore_Playerhouse_EventScript_MomPleaseSetClock::
	lockall
	delay 10
	turnobject 1, DIR_WEST
	applymovement 1, Common_Movement_WalkInPlaceLeft
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	msgbox Sandyshore_Playerhouse_EventScript_MomPleaseSetClock_Text_0
	turnobject 1, DIR_NORTH
	applymovement 1, Common_Movement_WalkInPlaceUp
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	releaseall
	end


Sandyshore_Playerhouse_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, Sandyshore_Playerhouse_EventScript_WallClock_1
	goto Sandyshore_Playerhouse_EventScript_SetClock
	return

Sandyshore_Playerhouse_EventScript_WallClock_1:
	goto Sandyshore_Playerhouse_EventScript_CheckWallClock
	return


Sandyshore_Playerhouse_EventScript_SetClock::
	lock
	setvar VAR_0x8004, MALE
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	setflag FLAG_SET_WALL_CLOCK
	release
	end


Sandyshore_Playerhouse_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	release
	end


Sandyshore_Playerhouse_EventScript_MomPleaseSetClockFirst::
	lockall
	turnobject 1, DIR_WEST
	applymovement 1, Common_Movement_WalkInPlaceLeft
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	msgbox Sandyshore_Playerhouse_EventScript_MomPleaseSetClockFirst_Text_0
	waitmessage
	turnobject 1, DIR_NORTH
	applymovement 1, Common_Movement_WalkInPlaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end


Sandyshore_Playerhouse_EventScript_Mom::
	goto_if_set FLAG_RECEIVED_STARTER, Sandyshore_Playerhouse_EventScript_Mom_1
	switch VAR_LITTLEROOT_INTRO_STATE
	case 1, Sandyshore_Playerhouse_EventScript_Mom_10
	case 2, Sandyshore_Playerhouse_EventScript_Mom_10
	case 3, Sandyshore_Playerhouse_EventScript_Mom_10
	case 4, Sandyshore_Playerhouse_EventScript_Mom_10
	case 5, Sandyshore_Playerhouse_EventScript_Mom_11
	case 6, Sandyshore_Playerhouse_EventScript_Mom_11
	case 7, Sandyshore_Playerhouse_EventScript_Mom_11
	return

Sandyshore_Playerhouse_EventScript_Mom_1:
	lock
	faceplayer
	msgbox Sandyshore_Playerhouse_EventScript_Mom_Text_0
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	goto_if_unset FLAG_SHOWED_STARTER_TO_MOM, Sandyshore_Playerhouse_EventScript_Mom_6
Sandyshore_Playerhouse_EventScript_Mom_4:
	release
	end

Sandyshore_Playerhouse_EventScript_Mom_5:
	msgbox Sandyshore_Playerhouse_EventScript_Mom_Text_1
	closemessage
	goto Sandyshore_Playerhouse_EventScript_Mom_4

Sandyshore_Playerhouse_EventScript_Mom_6:
	goto_if_unset FLAG_ENABLE_MR_STONE_POKENAV, Sandyshore_Playerhouse_EventScript_Mom_5
	goto Sandyshore_Playerhouse_EventScript_Mom_4

Sandyshore_Playerhouse_EventScript_Mom_10:
	lock
	faceplayer
	msgbox Sandyshore_Playerhouse_EventScript_Mom_Text_2
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 1
	release
	end

Sandyshore_Playerhouse_EventScript_Mom_11:
	lock
	faceplayer
	msgbox Sandyshore_Playerhouse_EventScript_Mom_Text_2
	release
	end


Sandyshore_Playerhouse_EventScript_MomGiveRunningShoes::
	lockall
	delay 20
	turnobject 1, DIR_WEST
	applymovement 1, Common_Movement_WalkInPlaceFasterLeft
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	msgbox Sandyshore_Playerhouse_EventScript_MomGiveRunningShoes_Text_0
	closemessage
	applymovement 1, Sandyshore_Playerhouse_Movement_MomWalkToShelf
	waitmovement 1
	delay 40
	applymovement 1, Sandyshore_Playerhouse_Movement_MomWalkFromShelfToPlayer
	waitmovement 1
	msgbox Sandyshore_Playerhouse_EventScript_MomGiveRunningShoes_Text_1
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	setflag FLAG_SYS_B_DASH
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox Sandyshore_Playerhouse_EventScript_MomGiveRunningShoes_Text_2
	closemessage
	delay 10
	applymovement 1, Sandyshore_Playerhouse_Movement_MomWalkFromPlayerToSink
	waitmovement 1
	releaseall
	end


Sandyshore_Playerhouse_EventScript_Skitty::
	lock
	faceplayer
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox Sandyshore_Playerhouse_EventScript_Skitty_Text_0
	release
	end


Sandyshore_Playerhouse_Movement_MomWalkToShelf:
	walk_left
	walk_left
	face_up
	step_end

Sandyshore_Playerhouse_Movement_MomWalkFromShelfToPlayer:
	walk_left
	step_end

Sandyshore_Playerhouse_Movement_MomWalkFromPlayerToSink:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Sandyshore_Playerhouse_EventScript_MomPleaseSetClock_Text_0:
	.string "Are you going out, dear?\p"
	.string "…\p"
	.string "I see, you're meeting up with Ruth.\p"
	.string "Before you go, could you please set the\n"
	.string "new clock correctly?\p"
	.string "It's right there on the wall next to the\n"
	.string "stairs.$"

Sandyshore_Playerhouse_EventScript_MomPleaseSetClockFirst_Text_0:
	.string "The clock is right there on the wall\n"
	.string "next to the stairs.$"

Sandyshore_Playerhouse_EventScript_Mom_Text_0:
	.string "Mom: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

Sandyshore_Playerhouse_EventScript_Mom_Text_1:
	.string "Oh? Is that a Pokémon?\p"
	.string "...\p"
	.string "I see, the Professor asked you to take\n"
	.string "care of it.\p"
	.string "You got yourself a pretty active little\n"
	.string "one there!\p"
	.string "Sounds like you'll be spending a lot of\n"
	.string "time outside now!\p"
	.string "When you and your Pokémon get tired,\n"
	.string "you can always come back home and\l"
	.string "rest.$"

Sandyshore_Playerhouse_EventScript_Mom_Text_2:
	.string "Are you two going to visit the\n"
	.string "Professor again?$"

Sandyshore_Playerhouse_EventScript_MomGiveRunningShoes_Text_0:
	.string "Oh! Before I forget!$"

Sandyshore_Playerhouse_EventScript_MomGiveRunningShoes_Text_1:
	.string "Your new shoes arrived earlier today!$"

Sandyshore_Playerhouse_EventScript_MomGiveRunningShoes_Text_2:
	.string "You two go and have fun outside, and\n"
	.string "don't forget to call if you'll be back\l"
	.string "home late!$"

Sandyshore_Playerhouse_EventScript_Skitty_Text_0:
	.string "Skitty: Meoww!$"
