Route135_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route135_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route135_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_LITTLEROOT_INTRO_STATE, 8
	goto_if_eq Route135_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	setflag FLAG_TEMP_10
	return

Route135_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_TEMP_10
	return


Route135_EventScript_CatchTutorialEnterTop::
	lockall
	turnobject 5, DIR_EAST
	msgbox Route135_Text_CatchTutorialPsstComeOverHere
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route135_Movement_CatchTutorialEnterTop
	waitmovement 0
	goto Route135_EventScript_CatchTutorialMain
	return


Route135_EventScript_CatchTutorialEnterBottom::
	lockall
	turnobject 5, DIR_EAST
	msgbox Route135_Text_CatchTutorialPsstComeOverHere
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route135_Movement_CatchTutorialEnterBottom
	waitmovement 0
	delay 10
	goto Route135_EventScript_CatchTutorialMain
	return


Route135_EventScript_CatchTutorialMain::
	turnobject 5, DIR_WEST
	msgbox Route135_EventScript_CatchTutorialMain_Text_0
	closemessage
	applymovement 5, Common_Movement_WalkLeft
	waitmovement 0
	special SavePlayerParty
	special LoadCatchTutorialParty
	special StartWallyTutorialBattle
	waitstate
	setvar VAR_LITTLEROOT_INTRO_STATE, 9
	special LoadPlayerParty
	applymovement 5, Common_Movement_WalkRight
	waitmovement 0
	msgbox Route135_EventScript_CatchTutorialMain_Text_1
	closemessage
	giveitem ITEM_POKE_BALL, 3
	msgbox Route135_EventScript_CatchTutorialMain_Text_2
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route135_EventScript_CatchTutorialMain_Text_3
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route135_EventScript_CatchTutorialMain_Text_4
	closemessage
	applymovement 5, Route135_Movement_RuthLeave
	waitmovement 0
	setflag FLAG_TEMP_10
	removeobject 5
	setflag FLAG_DONE_CATCH_TUTORIAL
	releaseall
	end


Route135_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_unset FLAG_TEMP_11, Route135_EventScript_RockSmashGuy_2
Route135_EventScript_RockSmashGuy_1:
	msgbox Route135_EventScript_RockSmashGuy_Text_2
	release
	end

Route135_EventScript_RockSmashGuy_2:
	msgbox Route135_EventScript_RockSmashGuy_Text_0
	applymovement 7, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement 3, Movement_SmashRock
	playse SE_M_ROCK_THROW
	msgbox Route135_EventScript_RockSmashGuy_Text_1
	waitmovement 0
	waitse
	removeobject 3
	setflag FLAG_TEMP_11
	specialvar VAR_TEMP_1, GetPlayerFacingDirection
	switch VAR_TEMP_1
	case DIR_SOUTH, Route135_EventScript_RockSmashGuy_5
	case DIR_EAST, Route135_EventScript_RockSmashGuy_5
	case DIR_WEST, Route135_EventScript_RockSmashGuy_6
	case DIR_NORTH, Route135_EventScript_RockSmashGuy_7
	goto Route135_EventScript_RockSmashGuy_1

Route135_EventScript_RockSmashGuy_5:
	turnobject 7, DIR_WEST
	goto Route135_EventScript_RockSmashGuy_1

Route135_EventScript_RockSmashGuy_6:
	turnobject 7, DIR_EAST
	goto Route135_EventScript_RockSmashGuy_1

Route135_EventScript_RockSmashGuy_7:
	turnobject 7, DIR_SOUTH
	goto Route135_EventScript_RockSmashGuy_1


Route135_EventScript_RockSmashSpecialRock::
	lock
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route135_EventScript_RockSmashSpecialRock_2
Route135_EventScript_RockSmashSpecialRock_1:
	checkpartymove MOVE_ROCK_SMASH
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq Route135_EventScript_RockSmashSpecialRock_5
Route135_EventScript_RockSmashSpecialRock_4:
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route135_EventScript_RockSmashSpecialRock_8
Route135_EventScript_RockSmashSpecialRock_7:
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	applymovement 3, Movement_SmashRock
	waitmovement 0
	removeobject 3
	setflag FLAG_TEMP_11
	applymovement 7, Route135_Movement_RockSmashGuyNotice
	playse SE_PIN
	waitmovement 7
	specialvar VAR_TEMP_1, GetPlayerFacingDirection
	switch VAR_TEMP_1
	case DIR_SOUTH, Route135_EventScript_RockSmashSpecialRock_12
	case DIR_EAST, Route135_EventScript_RockSmashSpecialRock_12
	case DIR_WEST, Route135_EventScript_RockSmashSpecialRock_13
	case DIR_NORTH, Route135_EventScript_RockSmashSpecialRock_14
Route135_EventScript_RockSmashSpecialRock_10:
	checkpartymove MOVE_ROCK_SMASH
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox Route135_EventScript_RockSmashSpecialRock_Text_0
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	closemessage
	releaseall
	end

Route135_EventScript_RockSmashSpecialRock_2:
	goto EventScript_RockSmash
	goto Route135_EventScript_RockSmashSpecialRock_1

Route135_EventScript_RockSmashSpecialRock_5:
	goto EventScript_CantSmashRock
	goto Route135_EventScript_RockSmashSpecialRock_4

Route135_EventScript_RockSmashSpecialRock_8:
	goto EventScript_CancelSmash
	goto Route135_EventScript_RockSmashSpecialRock_7

Route135_EventScript_RockSmashSpecialRock_12:
	turnobject 7, DIR_WEST
	goto Route135_EventScript_RockSmashSpecialRock_10

Route135_EventScript_RockSmashSpecialRock_13:
	turnobject 7, DIR_EAST
	goto Route135_EventScript_RockSmashSpecialRock_10

Route135_EventScript_RockSmashSpecialRock_14:
	turnobject 7, DIR_SOUTH
	goto Route135_EventScript_RockSmashSpecialRock_10


Route135_Movement_CatchTutorialEnterTop:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	face_left
	step_end

Route135_Movement_CatchTutorialEnterBottom:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	face_left
	step_end

Route135_Movement_RuthLeave:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

Route135_EventScript_Boy1::
	msgbox Route135_EventScript_Boy1_Text_0, MSGBOX_NPC
	return


Route135_EventScript_Lia::
	trainerbattle_double TRAINER_ALI_AND_LIA, Route135_EventScript_Lia_Text_0, Route135_EventScript_Lia_Text_1, Route135_EventScript_Lia_Text_2
	msgbox Route135_EventScript_Lia_Text_3, MSGBOX_AUTOCLOSE
	end


Route135_EventScript_Ali::
	trainerbattle_double TRAINER_ALI_AND_LIA, Route135_EventScript_Ali_Text_0, Route135_EventScript_Ali_Text_1, Route135_EventScript_Ali_Text_2
	msgbox Route135_EventScript_Ali_Text_3, MSGBOX_AUTOCLOSE
	end


Route135_EventScript_Darien::
	trainerbattle_single TRAINER_DARIEN, Route135_EventScript_Darien_Text_0, Route135_EventScript_Darien_Text_1
	msgbox Route135_EventScript_Darien_Text_2, MSGBOX_AUTOCLOSE
	end


Route135_EventScript_Lass::
	lock
	faceplayer
	msgbox Route135_EventScript_Lass_Text_0, MSGBOX_AUTOCLOSE
	end


Route135_EventScript_Tuber_F::
	lock
	faceplayer
	msgbox Route135_EventScript_Tuber_F_Text_0, MSGBOX_AUTOCLOSE
	end


Route135_Movement_RockSmashGuyNotice:
	face_down
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	step_end

Route135_Movement_RockSmashRockSmash:
	delay_16
	delay_16
	delay_16
	rock_smash_break
	step_end

Route135_EventScript_CatchTutorialMain_Text_0:
	.string "See that Budew over there in the grass?\p"
	.string "Watch closely!$"

Route135_EventScript_CatchTutorialMain_Text_1:
	.string "See? It's not hard at all!\p"
	.string "Here, you should try it yourself!$"

Route135_EventScript_CatchTutorialMain_Text_2:
	.string "The more you weaken a Pokémon, the\n"
	.string "easier it is to catch.\p"
	.string "Inflicting a status condition will also\n"
	.string "increase your chances!\p"
	.string "If you don't want to catch a Pokémon,\n"
	.string "you can defeat it instead.\p"
	.string "That way your own Pokémon can earn\n"
	.string "battle experience!$"

Route135_EventScript_CatchTutorialMain_Text_3:
	.string "Since I gave my three last balls to you,\n"
	.string "I'll go to the mart in Pacifidlog Town\l"
	.string "and buy new ones.\p"
	.string "I wouldn't want to have to pass on a\n"
	.string "rare Pokémon just because I forgot to\l"
	.string "buy Poké Balls!$"

Route135_EventScript_CatchTutorialMain_Text_4:
	.string "You should meet me there, and try to\n"
	.string "get the hang of battling on the way!\p"
	.string "But before you go, why don't you show\n"
	.string "your new Pokémon to your mom?\p"
	.string "I bet she'll love it!$"

Route135_EventScript_RockSmashGuy_Text_0:
	.string "Rocks like these are breakable! Watch!$"

Route135_EventScript_RockSmashGuy_Text_1:
	.string "HIYA!$"

Route135_EventScript_RockSmashGuy_Text_2:
	.string "If you steel your body and train your\n"
	.string "muscles, you can smash these rocks\l"
	.string "too!\p"
	.string "Or you can ask a strong Pokémon to\n"
	.string "break them for you, I guess.$"

Route135_EventScript_RockSmashSpecialRock_Text_0:
	.string "That's a powerful Rock Smash! You\n"
	.string "trained your {STR_VAR_1} well!\p"
	.string "Here, with this HM you can use it in\n"
	.string "battle too!\p"
	.string "Or you can teach it to other Pokémon\n"
	.string "that can't use it innately.$"

Route135_EventScript_Boy1_Text_0:
	.string "Did you know that Pokémon have\n"
	.string "different weaknesses depending on\l"
	.string "their type?\p"
	.string "My Wingull can easily defeat wild Budew\n"
	.string "with its flying-type moves!\p"
	.string "It doesn't do well against eletric or\n"
	.string "rock-type attacks, though…$"

Route135_EventScript_Lia_Text_0:
	.string "Lia: I'll battle you together with my\n"
	.string "sister!$"

Route135_EventScript_Lia_Text_1:
	.string "Lia: Uh-oh, we lost.$"

Route135_EventScript_Lia_Text_2:
	.string "Lia: If you have two Pokémon, you can\n"
	.string "try to beat us!\p"
	.string "But don't cry if you lose!$"

Route135_EventScript_Lia_Text_3:
	.string "Lia: You have to think about all kinds\n"
	.string "of things when you're battling against\l"
	.string "two trainers.$"

Route135_EventScript_Ali_Text_0:
	.string "Ali: Let's go, Lia!$"

Route135_EventScript_Ali_Text_1:
	.string "Ali: Aw.$"

Route135_EventScript_Ali_Text_2:
	.string "Ali: Oh, you only have one Pokémon! You\n"
	.string "can't battle us like that!$"

Route135_EventScript_Ali_Text_3:
	.string "Ali: Double battles are much harder\n"
	.string "than single battles!$"

Route135_EventScript_Darien_Text_0:
	.string "{PLAYER}! You have a Pokémon too\n"
	.string "now?\p"
	.string "Let me check if you are any good!$"

Route135_EventScript_Darien_Text_1:
	.string "Aw, shucks.$"

Route135_EventScript_Darien_Text_2:
	.string "As a trainer, you have to be ready for a\n"
	.string "challenge anytime!$"

Route135_EventScript_Lass_Text_0:
	.string "I jumped down this ledge, but now I\n"
	.string "can't get back up!\p"
	.string "I could get back to Pacifidlog via the\n"
	.string "beach, but I don't want to get sand in\l"
	.string "my shoes…$"

Route135_EventScript_Tuber_F_Text_0:
	.string "Hehe!\p"
	.string "My footsteps make funny sounds!$"

Route135_Text_CatchTutorialPsstComeOverHere::
	.string "Psst! {PLAYER}!\p"
	.string "Come over here, quickly!$"
