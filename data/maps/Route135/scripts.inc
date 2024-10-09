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
	playbgm MUS_ENCOUNTER_MAY, TRUE
	speakername CommonName_Ruth
	msgbox Route135_Text_CatchTutorialPsstComeOverHere
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route135_Movement_CatchTutorialEnterTop
	waitmovement 0
	delay 10
	goto Route135_EventScript_CatchTutorialMain
	return


Route135_EventScript_CatchTutorialEnterBottom::
	lockall
	turnobject 5, DIR_EAST
	playbgm MUS_ENCOUNTER_MAY, TRUE
	speakername CommonName_Ruth
	msgbox Route135_Text_CatchTutorialPsstComeOverHere
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route135_Movement_CatchTutorialEnterBottom
	waitmovement 0
	delay 10
	goto Route135_EventScript_CatchTutorialMain
	return


Route135_EventScript_CatchTutorialMain::
	turnobject 5, DIR_WEST
	speakername CommonName_Ruth
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
	speakername CommonName_Ruth
	msgbox Route135_EventScript_CatchTutorialMain_Text_1
	speakername NULL
	giveitem ITEM_POKE_BALL, 5
	speakername CommonName_Ruth
	msgbox Route135_EventScript_CatchTutorialMain_Text_2
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	speakername CommonName_Ruth
	msgbox Route135_EventScript_CatchTutorialMain_Text_3
	applymovement 5, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto_if_unset FLAG_SHOWED_STARTER_TO_MOM, Route135_EventScript_CatchTutorialMain_2
	msgbox Route135_EventScript_CatchTutorialMain_Text_5
Route135_EventScript_CatchTutorialMain_1:
	closemessage
	applymovement 5, Route135_Movement_RuthLeave
	savebgm MUS_DUMMY
	fadedefaultbgm
	waitmovement 0
	setflag FLAG_TEMP_10
	removeobject 5
	setflag FLAG_DONE_CATCH_TUTORIAL
	releaseall
	end

Route135_EventScript_CatchTutorialMain_2:
	msgbox Route135_EventScript_CatchTutorialMain_Text_4
	goto Route135_EventScript_CatchTutorialMain_1


Route135_EventScript_RockSmashGuy::
	lock
	faceplayer
	speakername Route135_EventScript_RockSmashGuy_Text_0
	goto_if_unset FLAG_TEMP_11, Route135_EventScript_RockSmashGuy_2
Route135_EventScript_RockSmashGuy_1:
	msgbox Route135_EventScript_RockSmashGuy_Text_3
	release
	end

Route135_EventScript_RockSmashGuy_2:
	msgbox Route135_EventScript_RockSmashGuy_Text_1
	closemessage
	applymovement 7, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 20
	applymovement 3, Movement_SmashRock
	playse SE_M_ROCK_THROW
	speakername Route135_EventScript_RockSmashGuy_Text_0
	msgbox Route135_EventScript_RockSmashGuy_Text_2
	waitmovement 0
	waitse
	removeobject 3
	setflag FLAG_TEMP_11
	applymovement 7, Common_Movement_FacePlayer
	waitmovement 0
	goto Route135_EventScript_RockSmashGuy_1


Route135_EventScript_SmashedSpecialRock::
	lock
	msgbox Route135_EventScript_SmashedSpecialRock_Text_0
	closemessage
	goto_if_unset FLAG_RECEIVED_HM_ROCK_SMASH, Route135_EventScript_SmashedSpecialRock_2
Route135_EventScript_SmashedSpecialRock_1:
	releaseall
	end

Route135_EventScript_SmashedSpecialRock_2:
	applymovement 7, Route135_Movement_RockSmashGuyNotice
	playse SE_PIN
	waitmovement 7
	specialvar VAR_TEMP_1, GetPlayerFacingDirection
	switch VAR_TEMP_1
	case DIR_SOUTH, Route135_EventScript_SmashedSpecialRock_6
	case DIR_EAST, Route135_EventScript_SmashedSpecialRock_6
	case DIR_WEST, Route135_EventScript_SmashedSpecialRock_7
	case DIR_NORTH, Route135_EventScript_SmashedSpecialRock_8
Route135_EventScript_SmashedSpecialRock_4:
	speakername Route135_EventScript_RockSmashGuy_Text_0
	msgbox Route135_EventScript_SmashedSpecialRock_Text_1
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	closemessage
	goto Route135_EventScript_SmashedSpecialRock_1

Route135_EventScript_SmashedSpecialRock_6:
	turnobject 7, DIR_WEST
	goto Route135_EventScript_SmashedSpecialRock_4

Route135_EventScript_SmashedSpecialRock_7:
	turnobject 7, DIR_EAST
	goto Route135_EventScript_SmashedSpecialRock_4

Route135_EventScript_SmashedSpecialRock_8:
	turnobject 7, DIR_SOUTH
	goto Route135_EventScript_SmashedSpecialRock_4


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
	walk_left
	walk_left
	step_end

Route135_EventScript_Boy1::
	speakername Route135_EventScript_Boy1_Text_0
	msgbox Route135_EventScript_Boy1_Text_1, MSGBOX_NPC
	return


Route135_EventScript_Lia::
	trainerbattle_double TRAINER_EMI_AND_LIA, Route135_EventScript_Lia_Text_0, Route135_EventScript_Lia_Text_1, Route135_EventScript_Lia_Text_2
	speakername Route135_EventScript_Lia_Text_3
	msgbox Route135_EventScript_Lia_Text_4, MSGBOX_AUTOCLOSE
	end


Route135_EventScript_Ali::
	trainerbattle_double TRAINER_EMI_AND_LIA, Route135_EventScript_Lia_Text_0, Route135_EventScript_Ali_Text_0, Route135_EventScript_Ali_Text_1
	speakername Route135_EventScript_Ali_Text_2
	msgbox Route135_EventScript_Ali_Text_3, MSGBOX_AUTOCLOSE
	end


Route135_EventScript_Darien::
	trainerbattle_single TRAINER_DARIEN, Route135_EventScript_Darien_Text_0, Route135_EventScript_Darien_Text_1
	speakername Route135_EventScript_Darien_Text_2
	msgbox Route135_EventScript_Darien_Text_3, MSGBOX_AUTOCLOSE
	end


Route135_EventScript_Lass::
	lock
	faceplayer
	speakername Route135_EventScript_Lass_Text_0
	msgbox Route135_EventScript_Lass_Text_1, MSGBOX_AUTOCLOSE
	end


Route135_EventScript_Tuber_F::
	lock
	faceplayer
	speakername Route135_EventScript_Tuber_F_Text_0
	msgbox Route135_EventScript_Tuber_F_Text_1, MSGBOX_AUTOCLOSE
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
	.string "Or you could defeat it to have your own\n"
	.string "Pokémon earn battle experience!$"

Route135_EventScript_CatchTutorialMain_Text_3:
	.string "I'll go ahead to Pacifidlog Town, I need\n"
	.string "to to grab more Poké Balls.\p"
	.string "I wouldn't want to have to pass on a\n"
	.string "rare one because I ran out!$"

Route135_EventScript_CatchTutorialMain_Text_4:
	.string "You should meet me there, and try to\n"
	.string "get the hang of battling on the way!\p"
	.string "But before you go, why don't you show\n"
	.string "your new Pokémon to your mom?\p"
	.string "I bet she'll love it!$"

Route135_EventScript_CatchTutorialMain_Text_5:
	.string "You should meet me there, and try to\n"
	.string "get the hang of battling on the way!$"

Route135_EventScript_RockSmashGuy_Text_0:
	.string "Makoto$"

Route135_EventScript_RockSmashGuy_Text_1:
	.string "Rocks like these are breakable! Watch!$"

Route135_EventScript_RockSmashGuy_Text_2:
	.string "HIYA!$"

Route135_EventScript_RockSmashGuy_Text_3:
	.string "If you steel your body and train your\n"
	.string "muscles, you can smash these rocks\l"
	.string "too!\p"
	.string "Or you can ask a strong Pokémon like\n"
	.string "Machop to break them for you, I guess.$"

Route135_EventScript_SmashedSpecialRock_Text_0:
	.string "EEEEE$"

Route135_EventScript_SmashedSpecialRock_Text_1:
	.string "That was a powerful Rock Smash! You\n"
	.string "trained your Pokémon well!\p"
	.string "Here, with this HM you can use it in\n"
	.string "battle too!\p"
	.string "Or you can teach it to other Pokémon\n"
	.string "that can't use it innately.$"

Route135_EventScript_Boy1_Text_0:
	.string "Alvin$"

Route135_EventScript_Boy1_Text_1:
	.string "Did you know that Pokémon have\n"
	.string "different weaknesses depending on\l"
	.string "their type?\p"
	.string "My Wingull can easily defeat wild Budew\n"
	.string "with its flying-type moves!\p"
	.string "It doesn't do well against electric or\n"
	.string "rock-type attacks, though…$"

Route135_EventScript_Lia_Text_0:
	.string "We'll battle you together!$"

Route135_EventScript_Lia_Text_1:
	.string "Uh-oh, we lost.$"

Route135_EventScript_Lia_Text_2:
	.string "If you have two Pokémon, you can try to\n"
	.string "beat us!\p"
	.string "But don't cry if you lose!$"

Route135_EventScript_Lia_Text_3:
	.string "Lia$"

Route135_EventScript_Lia_Text_4:
	.string "You have to think about all kinds of\n"
	.string "things when you're battling against\l"
	.string "two trainers.$"

Route135_EventScript_Ali_Text_0:
	.string "Aw.$"

Route135_EventScript_Ali_Text_1:
	.string "Oh, you only have one Pokémon! You\n"
	.string "can't battle us like that!$"

Route135_EventScript_Ali_Text_2:
	.string "Emi$"

Route135_EventScript_Ali_Text_3:
	.string "Double battles are much harder than\n"
	.string "single battles!$"

Route135_EventScript_Darien_Text_0:
	.string "{PLAYER}! You have a Pokémon too\n"
	.string "now?\p"
	.string "Let me check if you are any good!$"

Route135_EventScript_Darien_Text_1:
	.string "Aw, shucks.$"

Route135_EventScript_Darien_Text_2:
	.string "Darien$"

Route135_EventScript_Darien_Text_3:
	.string "As a trainer, you have to be ready for a\n"
	.string "challenge anytime!$"

Route135_EventScript_Lass_Text_0:
	.string "Kirstin$"

Route135_EventScript_Lass_Text_1:
	.string "I jumped down this ledge, but now I\n"
	.string "can't get back up!\p"
	.string "I could get back to Pacifidlog via the\n"
	.string "beach, but I don't want to get sand in\l"
	.string "my shoes…$"

Route135_EventScript_Tuber_F_Text_0:
	.string "Ida$"

Route135_EventScript_Tuber_F_Text_1:
	.string "Hihi!\p"
	.string "My footsteps make funny sounds!$"

Route135_Text_CatchTutorialPsstComeOverHere::
	.string "Psst! {PLAYER}!\p"
	.string "Come over here, quickly!$"
