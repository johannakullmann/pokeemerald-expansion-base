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
	walk_up
	step_end

Route135_EventScript_Boy1::
	lock
	faceplayer
	msgbox Route135_EventScript_Boy1_Text_0
	release
	end


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

Route135_EventScript_Boy1_Text_0:
	.string "Did you know that Pokémon have\n"
	.string "different weaknesses depending on\l"
	.string "their type?\p"
	.string "My Taillow can easily defeat wild Budew\n"
	.string "with its flying-type attack!\p"
	.string "It doesn't do well against a Neuchi's\n"
	.string "Thundershock, though…$"

Route135_Text_CatchTutorialPsstComeOverHere::
	.string "Psst! {PLAYER}!\p"
	.string "Come over here, quickly!$"
