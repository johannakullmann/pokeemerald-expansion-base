.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	@goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "MT. CHIMNEY's JAGGED PASS…\p"
	.string "Now this is what I've always wanted\n"
	.string "in a mountain.\p"
	.string "This jagged bumpiness…\n"
	.string "It rocks my soul!$"

JaggedPass_Text_EricDefeat:
	.string "Losing left me bitter!$"

JaggedPass_Text_EricPostBattle:
	.string "Yes, I did lose at POKéMON…\p"
	.string "But, when it comes to the love of\n"
	.string "the mountains, I have you beat!$"

JaggedPass_Text_DianaIntro:
	.string "This place isn't your casual hike.\n"
	.string "It's not suited for a picnic.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, no!\n"
	.string "The ground is too bumpy…$"

JaggedPass_Text_DianaPostBattle:
	.string "Did you know?\p"
	.string "Some people cleverly ride their\n"
	.string "bicycles up this horribly bumpy pass.$"

JaggedPass_Text_DianaRegister:
	.string "Will you ever be back in this area?\n"
	.string "If you do return, I'd like a rematch.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Picnics are fun wherever you go.\n"
	.string "Just like POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "I only lost because the ground is\n"
	.string "too bumpy!$"

JaggedPass_Text_DianaPostRematch:
	.string "I'll forget about losing and just\n"
	.string "enjoy this bumpy hike.$"

JaggedPass_Text_EthanIntro:
	.string "JAGGED PASS is hard to walk on.\n"
	.string "It's a good place for training.$"

JaggedPass_Text_EthanDefeat:
	.string "It was all over while we were still\n"
	.string "trying to find a good footing…$"

JaggedPass_Text_EthanPostBattle:
	.string "If I had an ACRO BIKE, I'd be able to\n"
	.string "jump ledges.$"

JaggedPass_Text_EthanRegister:
	.string "When I get more used to this bumpiness,\n"
	.string "I'll be sure to win!\p"
	.string "Can you register me in your POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "I got used to this bumpiness.\n"
	.string "I sing while I climb now.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "It's still not easy to battle on this\n"
	.string "bumpy ground…$"

JaggedPass_Text_EthanPostRematch:
	.string "I should get an ACRO BIKE from RYDEL\n"
	.string "in MAUVILLE CITY…$"

JaggedPass_Text_GruntIntro:
	.string "Wah!\n"
	.string "What are you doing here?\p"
	.string "What am I doing in a place like this?\p"
	.string "What business is it of yours?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "I should've ducked into our HIDEOUT\n"
	.string "right away…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Okay, oh-kay!\n"
	.string "I admit it--you're strong!\p"
	.string "Don't worry about me.\n"
	.string "Go wherever you want!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! This boulder is shaking in response\n"
	.string "to the MAGMA EMBLEM!$"

JaggedPass_Text_JulioIntro:
	.string "Aiyeeh! It's awfully scary to shoot\n"
	.string "down the mountain in one go!$"

JaggedPass_Text_JulioDefeat:
	.string "I feel like I'm falling apart…$"

JaggedPass_Text_JulioPostBattle:
	.string "My bicycle bounced around so much,\n"
	.string "my rear end's sore…$"

JaggedPass_Text_AutumnIntro:
	.string "I climb this hill every day.\n"
	.string "I have confidence in my strength!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "What went wrong?$"

JaggedPass_Text_AutumnPostBattle:
	.string "What is that odd rock protrusion\n"
	.string "a little up the hill from here?$"

JaggedPass_EventScript_FootprintNerd::
	compare VAR_JAGGED_PASS_STATE, 3
	goto_if_le JaggedPass_EventScript_FootprintNerd_1
	lock
	faceplayer
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	compare VAR_0x8009, 15
	goto_if_lt JaggedPass_EventScript_FootprintNerd_9
	msgbox JaggedPass_EventScript_FootprintNerd_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq JaggedPass_EventScript_FootprintNerd_12
	msgbox JaggedPass_EventScript_FootprintNerd_Text_5, MSGBOX_AUTOCLOSE
JaggedPass_EventScript_FootprintNerd_11:
	release
	end

JaggedPass_EventScript_FootprintNerd_1:
	lock
	applymovement 8, Common_Movement_FacePlayer
	waitmovement 0
	speakername JaggedPass_EventScript_FootprintNerd_Text_0
	msgbox JaggedPass_EventScript_FootprintNerd_Text_1
	closemessage
	applymovement 8, Common_Movement_WalkInPlaceUp
	applymovement OBJ_EVENT_ID_PLAYER, JaggedPass_Movement_PlayerWalkUpToAsh
	waitmovement 0
	speakername JaggedPass_EventScript_FootprintNerd_Text_0
	msgbox JaggedPass_Text_FootprintNerdWannaKnowWhatHappendHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq JaggedPass_EventScript_FootprintNerd_5
	applymovement 8, Common_Movement_FacePlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox JaggedPass_Text_FootprintNerdNeedToStudy_2
JaggedPass_EventScript_FootprintNerd_4:
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	turnobject 8, DIR_NORTH
	waitmovement 0
	release
	end

JaggedPass_EventScript_FootprintNerd_5:
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox JaggedPass_Text_FootprintNerdStory
	applymovement 8, Common_Movement_FacePlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox JaggedPass_Text_FootprintNerdNeedToStudy_1
	goto JaggedPass_EventScript_FootprintNerd_4

JaggedPass_EventScript_FootprintNerd_9:
	msgbox JaggedPass_EventScript_FootprintNerd_Text_2, MSGBOX_AUTOCLOSE
	release
	end

JaggedPass_EventScript_FootprintNerd_12:
	msgbox JaggedPass_EventScript_FootprintNerd_Text_4, MSGBOX_AUTOCLOSE
	goto JaggedPass_EventScript_FootprintNerd_11


JaggedPass_EventScript_MachBikeTriathlete::
	msgbox JaggedPass_EventScript_MachBikeTriathlete_Text_0, MSGBOX_NPC
	end


JaggedPass_EventScript_HeadbuttTreeMan::
	msgbox JaggedPass_EventScript_HeadbuttTreeMan_Text_0, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	end


JaggedPass_EventScript_Ruth::
	switch VAR_JAGGED_PASS_STATE
	case 0, JaggedPass_EventScript_Ruth_2
	case 1, JaggedPass_EventScript_Ruth_2
	case 2, JaggedPass_EventScript_Ruth_2
	case 3, JaggedPass_EventScript_Ruth_3
	return

JaggedPass_EventScript_Ruth_2:
	faceplayer
	speakername CommonName_Ruth
	msgbox JaggedPass_EventScript_Ruth_Text_0
	turnobject VAR_LAST_TALKED, DIR_WEST
	switch VAR_STARTER_MON
	case 0, JaggedPass_EventScript_Ruth_6
	case 1, JaggedPass_EventScript_Ruth_7
	case 2, JaggedPass_EventScript_Ruth_8
JaggedPass_EventScript_Ruth_4:
	closemessage
	release
	end

JaggedPass_EventScript_Ruth_3:
	lock
	faceplayer
	speakername CommonName_Ruth
	switch VAR_STARTER_MON
	case 0, JaggedPass_EventScript_Ruth_11
	case 2, JaggedPass_EventScript_Ruth_11
	case 1, JaggedPass_EventScript_Ruth_12
JaggedPass_EventScript_Ruth_9:
	closemessage
	release
	end

JaggedPass_EventScript_Ruth_6:
	bufferspeciesname STR_VAR_1, SPECIES_RUBECKO
	msgbox JaggedPass_Text_GetHim
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice
	call JaggedPass_EventScript_Rubecko
	goto JaggedPass_EventScript_Ruth_4

JaggedPass_EventScript_Ruth_7:
	bufferspeciesname STR_VAR_1, SPECIES_AMALGOAT
	msgbox JaggedPass_Text_GetHim
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice
	call JaggedPass_EventScript_Amalgoat
	goto JaggedPass_EventScript_Ruth_4

JaggedPass_EventScript_Ruth_8:
	bufferspeciesname STR_VAR_1, SPECIES_TOXATOO
	msgbox JaggedPass_Text_GetHim
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice_NoGroundEffect
	call JaggedPass_EventScript_Toxatoo
	goto JaggedPass_EventScript_Ruth_4

JaggedPass_EventScript_Ruth_11:
	msgbox JaggedPass_EventScript_Ruth_Text_1
	goto JaggedPass_EventScript_Ruth_9

JaggedPass_EventScript_Ruth_12:
	msgbox JaggedPass_EventScript_Ruth_Text_2
	goto JaggedPass_EventScript_Ruth_9


JaggedPass_EventScript_RuthsMon::
	switch VAR_STARTER_MON
	case 0, JaggedPass_EventScript_RuthsMon_3
	case 1, JaggedPass_EventScript_RuthsMon_4
	case 2, JaggedPass_EventScript_RuthsMon_5
JaggedPass_EventScript_RuthsMon_1:
	closemessage
	release
	end

JaggedPass_EventScript_RuthsMon_3:
	call JaggedPass_EventScript_Rubecko
	goto JaggedPass_EventScript_RuthsMon_1

JaggedPass_EventScript_RuthsMon_4:
	call JaggedPass_EventScript_Amalgoat
	goto JaggedPass_EventScript_RuthsMon_1

JaggedPass_EventScript_RuthsMon_5:
	call JaggedPass_EventScript_Toxatoo
	goto JaggedPass_EventScript_RuthsMon_1


JaggedPass_EventScript_GruntTryStopPlayer1_T::
	lock
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMarkAndDelay
	waitmovement 0
	speakername CommonName_MagmaGrunt
	msgbox JaggedPass_Text_PoochyenaGetThem
	closemessage
	applymovement 13, JaggedPass_Movement_PoochyenaApprachPlayer_T
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	waitmoncry
	applymovement 13, JaggedPass_Movement_PoochyenaJumpAtPlayer
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, JaggedPass_Movement_PlayerStumbleBackwards
	waitmovement 13
	applymovement 13, JaggedPass_Movement_PoochyenaRetreat_T
	waitmovement 0
	release
	end


JaggedPass_EventScript_GruntTryStopPlayer1_C::
	lock
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMarkAndDelay
	waitmovement 0
	speakername CommonName_MagmaGrunt
	msgbox JaggedPass_Text_PoochyenaGetThem
	closemessage
	applymovement 13, JaggedPass_Movement_PoochyenaApprachPlayer_C
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	waitmoncry
	applymovement 13, JaggedPass_Movement_PoochyenaJumpAtPlayer
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, JaggedPass_Movement_PlayerStumbleBackwards
	waitmovement 13
	applymovement 13, JaggedPass_Movement_PoochyenaRetreat_C
	waitmovement 0
	release
	end


JaggedPass_EventScript_GruntTryStopPlayer1_B::
	lock
	playse SE_PIN
	applymovement 12, Common_Movement_ExclamationMarkAndDelay
	waitmovement 0
	speakername CommonName_MagmaGrunt
	msgbox JaggedPass_Text_PoochyenaGetThem
	closemessage
	applymovement 13, JaggedPass_Movement_PoochyenaApprachPlayer_B
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	waitmoncry
	applymovement 13, JaggedPass_Movement_PoochyenaJumpAtPlayer
	delay 4
	applymovement OBJ_EVENT_ID_PLAYER, JaggedPass_Movement_PlayerStumbleBackwards
	waitmovement 13
	applymovement 13, JaggedPass_Movement_PoochyenaRetreat_B
	waitmovement 0
	release
	end


JaggedPass_EventScript_GruntTryStopPlayer2::
	applymovement 12, Common_Movement_FacePlayer
	speakername CommonName_MagmaGrunt
	msgbox JaggedPass_EventScript_GruntTryStopPlayer2_Text_0
	closemessage
	applymovement 12, Common_Movement_FaceOriginalDirection
	switch VAR_STARTER_MON
	case 0, JaggedPass_EventScript_GruntTryStopPlayer2_3
	case 1, JaggedPass_EventScript_GruntTryStopPlayer2_4
	case 2, JaggedPass_EventScript_GruntTryStopPlayer2_5
JaggedPass_EventScript_GruntTryStopPlayer2_1:
	waitmovement 0
	waitmoncry
	applymovement 13, JaggedPass_Movement_JumpInPlaceRightTwice
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	waitmovement 0
	waitmoncry
	speakername CommonName_MagmaGrunt
	msgbox JaggedPass_EventScript_GruntTryStopPlayer2_Text_1
	setvar VAR_JAGGED_PASS_STATE, 2
	release
	end

JaggedPass_EventScript_GruntTryStopPlayer2_3:
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice
	playmoncry SPECIES_RUBECKO, CRY_MODE_NORMAL
	goto JaggedPass_EventScript_GruntTryStopPlayer2_1

JaggedPass_EventScript_GruntTryStopPlayer2_4:
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice
	playmoncry SPECIES_AMALGOAT, CRY_MODE_NORMAL
	goto JaggedPass_EventScript_GruntTryStopPlayer2_1

JaggedPass_EventScript_GruntTryStopPlayer2_5:
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice_NoGroundEffect
	playmoncry SPECIES_TOXATOO, CRY_MODE_NORMAL
	goto JaggedPass_EventScript_GruntTryStopPlayer2_1


JaggedPass_EventScript_Rubecko::
	speakername CommonName_Rubecko
	playmoncry SPECIES_RUBECKO, CRY_MODE_NORMAL
	msgbox JaggedPass_Text_RubeckoCry
	waitmoncry
	return


JaggedPass_EventScript_Amalgoat::
	speakername CommonName_Amalgoat
	playmoncry SPECIES_AMALGOAT, CRY_MODE_NORMAL
	msgbox JaggedPass_Text_AmalgoatCry
	waitmoncry
	return


JaggedPass_EventScript_Toxatoo::
	speakername CommonName_Toxatoo
	playmoncry SPECIES_TOXATOO, CRY_MODE_NORMAL
	msgbox JaggedPass_Text_ToxatooCry
	waitmoncry
	return


JaggedPass_EventScript_Poochyena::
	speakername CommonName_Poochyena
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	msgbox MtChimney_Text_Bufoh
	waitmoncry
	return


JaggedPass_EventScript_GruntWithLostPoochyena::
	goto_if_unset FLAG_TEMP_7, JaggedPass_EventScript_GruntWithLostPoochyena_2
	speakername CommonName_MagmaGrunt
	msgbox JaggedPass_EventScript_GruntWithLostPoochyena_Text_3
	closemessage
JaggedPass_EventScript_GruntWithLostPoochyena_1:
	release
	end

JaggedPass_EventScript_GruntWithLostPoochyena_2:
	speakername CommonName_MagmaGrunt
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox JaggedPass_EventScript_GruntWithLostPoochyena_Text_0
	closemessage
	applymovement 21, JaggedPass_Movement_PoochyenaRunAway
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	waitmovement 0
	speakername CommonName_MagmaGrunt
	msgbox JaggedPass_EventScript_GruntWithLostPoochyena_Text_1
	closemessage
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_NUMEL, CRY_MODE_NORMAL
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	speakername CommonName_MagmaGrunt
	msgbox JaggedPass_EventScript_GruntWithLostPoochyena_Text_2
	closemessage
	setflag FLAG_TEMP_7
	goto JaggedPass_EventScript_GruntWithLostPoochyena_1


JaggedPass_EventScript_MayScene::
	lock
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement 23, JaggedPass_Movement_TabithaWalkBackwards
	waitmovement 0
	speakername CommonName_Tabitha
	msgbox JaggedPass_EventScript_MayScene_Text_0
	closemessage
	applymovement 22, Common_Movement_WalkInPlaceRight
	waitmovement 0
	speakername CommonName_May
	msgbox JaggedPass_EventScript_MayScene_Text_1
	closemessage
	applymovement 23, Common_Movement_WalkLeft
	waitmovement 0
	speakername CommonName_Tabitha
	msgbox JaggedPass_EventScript_MayScene_Text_2
	closemessage
	applymovement 23, JaggedPass_Movement_TabithaWalkAway
	applymovement 28, JaggedPass_Movement_Grunt1WalkAway
	applymovement 29, JaggedPass_Movement_Grunt2WalkAway
	delay 64
	fadedefaultbgm
	waitmovement 0
	removeobject 28
	removeobject 29
	removeobject 23
	delay 128
	clearflag FLAG_TEMP_8
	addobject 24
	playse SE_FU_ZAKU
	waitse
	turnobject 22, DIR_NORTH
	applymovement 24, Common_Movement_WalkDown
	waitmovement 0
	speakername CommonName_Flannery
	msgbox JaggedPass_EventScript_MayScene_Text_3
	closemessage
	waitmovement 0
	applymovement 22, Common_Movement_WalkInPlaceUp
	waitmovement 0
	speakername CommonName_May
	msgbox JaggedPass_EventScript_MayScene_Text_4
	closemessage
	applymovement 24, Common_Movement_WalkInPlaceDown
	waitmovement 0
	speakername CommonName_Flannery
	msgbox JaggedPass_EventScript_MayScene_Text_5
	closemessage
	applymovement 22, Common_Movement_WalkInPlaceUp
	waitmovement 0
	speakername CommonName_May
	msgbox JaggedPass_EventScript_MayScene_Text_6
	closemessage
	setobjectxyperm 14, 36, 20
	addobject 14
	applymovement 14, JaggedPass_Movement_RuthApproachPlayer
	waitmovement 0
	speakername CommonName_Ruth
	msgbox JaggedPass_EventScript_MayScene_Text_7
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	closemessage
	getplayerxy VAR_0x8000, VAR_0x8001
	switch VAR_0x8001
	case 19, JaggedPass_EventScript_MayScene_3
	case 20, JaggedPass_EventScript_MayScene_4
	case 21, JaggedPass_EventScript_MayScene_5
JaggedPass_EventScript_MayScene_1:
	speakername CommonName_Ruth
	msgbox JaggedPass_EventScript_MayScene_Text_8
	closemessage
	turnobject 22, DIR_WEST
	turnobject 24, DIR_WEST
	switch VAR_0x8001
	case 19, JaggedPass_EventScript_MayScene_8
	case 20, JaggedPass_EventScript_MayScene_9
	case 21, JaggedPass_EventScript_MayScene_9
JaggedPass_EventScript_MayScene_6:
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	speakername CommonName_May
	msgbox JaggedPass_EventScript_MayScene_Text_9
	closemessage
	switch VAR_0x8001
	case 19, JaggedPass_EventScript_MayScene_12
	case 20, JaggedPass_EventScript_MayScene_13
	case 21, JaggedPass_EventScript_MayScene_13
JaggedPass_EventScript_MayScene_10:
	waitmovement 0
	turnobject 22, DIR_NORTH
	speakername CommonName_Flannery
	msgbox JaggedPass_EventScript_MayScene_Text_10
	applymovement 22, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	turnobject 24, DIR_WEST
	speakername CommonName_May
	msgbox JaggedPass_EventScript_MayScene_Text_11
	closemessage
	applymovement 14, JaggedPass_Movement_RuthUnsure
	waitmovement 0
	speakername CommonName_Ruth
	msgbox JaggedPass_EventScript_MayScene_Text_12
	applymovement 14, Common_Movement_FacePlayer
	switch VAR_0x8001
	case 19, JaggedPass_EventScript_MayScene_16
	case 20, JaggedPass_EventScript_MayScene_17
	case 21, JaggedPass_EventScript_MayScene_17
JaggedPass_EventScript_MayScene_14:
	msgbox JaggedPass_EventScript_MayScene_Text_13
	closemessage
	applymovement 14, JaggedPass_Movement_RuthLeave
	delay 16
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 0
	removeobject 14
	applymovement 24, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	speakername CommonName_Flannery
	msgbox JaggedPass_EventScript_MayScene_Text_14
	applymovement 24, Common_Movement_WalkInPlaceDown
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject 22, DIR_NORTH
	msgbox JaggedPass_EventScript_MayScene_Text_15
	closemessage
	applymovement 22, Common_Movement_WalkInPlaceUp
	waitmovement 0
	speakername CommonName_May
	msgbox JaggedPass_EventScript_MayScene_Text_16
	closemessage
	applymovement 24, JaggedPass_Movement_FlanneryLeave
	delay 16
	turnobject 22, DIR_EAST
	waitmovement 0
	speakername CommonName_Flannery
	msgbox JaggedPass_EventScript_MayScene_Text_17
	closemessage
	setfieldeffectargument 0, 1
	playmoncry SPECIES_MOLTRES, CRY_MODE_NORMAL
	delay 16
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 10
	removeobject 24
	waitfieldeffect FLDEFF_NPCFLY_OUT
	delay 32
	applymovement 22, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	speakername CommonName_May
	msgbox JaggedPass_EventScript_MayScene_Text_18
	closemessage
	switch VAR_0x8001
	case 19, JaggedPass_EventScript_MayScene_20
	case 20, JaggedPass_EventScript_MayScene_21
	case 21, JaggedPass_EventScript_MayScene_21
JaggedPass_EventScript_MayScene_18:
	delay 16
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement 0
	removeobject 22
	setvar VAR_JAGGED_PASS_STATE, 3
	setobjectxyperm 14, 10, 33
	addobject 14
	setobjectmovementtype 14, MOVEMENT_TYPE_LOOK_AROUND
	removeobject 15
	setflag FLAG_HIDE_JAGGED_PASS_GRUNTS
	setflag FLAG_TEMP_7
	setflag FLAG_HIDE_JAGGED_PASS_NPCS
	setflag FLAG_LAVARIDGE_GYM_OPEN
	setflag FLAG_TEMP_10
	special DrawWholeMapView
	release
	end

JaggedPass_EventScript_MayScene_3:
	applymovement 14, JaggedPass_Movement_RuthApproachPlayer_T
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto JaggedPass_EventScript_MayScene_1

JaggedPass_EventScript_MayScene_4:
	applymovement 14, JaggedPass_Movement_RuthApproachPlayer_C
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto JaggedPass_EventScript_MayScene_1

JaggedPass_EventScript_MayScene_5:
	applymovement 14, JaggedPass_Movement_RuthApproachPlayer_B
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto JaggedPass_EventScript_MayScene_1

JaggedPass_EventScript_MayScene_8:
	applymovement 22, JaggedPass_Movement_MayApproachPlayer_2
	goto JaggedPass_EventScript_MayScene_6

JaggedPass_EventScript_MayScene_9:
	applymovement 22, JaggedPass_Movement_MayApproachPlayer_1
	goto JaggedPass_EventScript_MayScene_6

JaggedPass_EventScript_MayScene_12:
	applymovement 24, JaggedPass_Movement_FlanneryApproachPlayer_2
	goto JaggedPass_EventScript_MayScene_10

JaggedPass_EventScript_MayScene_13:
	applymovement 24, JaggedPass_Movement_FlanneryApproachPlayer_1
	goto JaggedPass_EventScript_MayScene_10

JaggedPass_EventScript_MayScene_16:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto JaggedPass_EventScript_MayScene_14

JaggedPass_EventScript_MayScene_17:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto JaggedPass_EventScript_MayScene_14

JaggedPass_EventScript_MayScene_20:
	applymovement 22, JaggedPass_Movement_MayLeave_2
	goto JaggedPass_EventScript_MayScene_18

JaggedPass_EventScript_MayScene_21:
	applymovement 22, JaggedPass_Movement_MayLeave_1
	goto JaggedPass_EventScript_MayScene_18


JaggedPass_EventScript_FootprintNerdTryStopPlayer_L::
	lock
	applymovement 8, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMarkAndDelay
	waitmovement 0
	speakername JaggedPass_EventScript_FootprintNerd_Text_0
	msgbox JaggedPass_Text_FootprintNerdHey
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox JaggedPass_Text_FootprintNerdPerfectFootprints
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox JaggedPass_Text_FootprintNerdWannaKnowWhatHappendHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq JaggedPass_EventScript_FootprintNerdTryStopPlayer_L_2
	applymovement 8, Common_Movement_FacePlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox JaggedPass_Text_FootprintNerdNeedToStudy_2
JaggedPass_EventScript_FootprintNerdTryStopPlayer_L_1:
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	turnobject 8, DIR_NORTH
	waitmovement 0
	release
	end

JaggedPass_EventScript_FootprintNerdTryStopPlayer_L_2:
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox JaggedPass_Text_FootprintNerdStory
	applymovement 8, Common_Movement_FacePlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox JaggedPass_Text_FootprintNerdNeedToStudy_1
	goto JaggedPass_EventScript_FootprintNerdTryStopPlayer_L_1


JaggedPass_EventScript_FootprintNerdTryStopPlayer_R::
	lock
	applymovement 8, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMarkAndDelay
	waitmovement 0
	speakername JaggedPass_EventScript_FootprintNerd_Text_0
	msgbox JaggedPass_Text_FootprintNerdHey
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox JaggedPass_Text_FootprintNerdPerfectFootprints
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox JaggedPass_Text_FootprintNerdWannaKnowWhatHappendHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq JaggedPass_EventScript_FootprintNerdTryStopPlayer_R_2
	applymovement 8, Common_Movement_FacePlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox JaggedPass_Text_FootprintNerdNeedToStudy_2
JaggedPass_EventScript_FootprintNerdTryStopPlayer_R_1:
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	turnobject 8, DIR_NORTH
	waitmovement 0
	release
	end

JaggedPass_EventScript_FootprintNerdTryStopPlayer_R_2:
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox JaggedPass_Text_FootprintNerdStory
	applymovement 8, Common_Movement_FacePlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox JaggedPass_Text_FootprintNerdNeedToStudy_1
	goto JaggedPass_EventScript_FootprintNerdTryStopPlayer_R_1


JaggedPass_Movement_JumpInPlaceLeftTwice:
	jump_in_place_left
	jump_in_place_left
	step_end

JaggedPass_Movement_JumpInPlaceRightTwice:
	jump_in_place_right
	jump_in_place_right
	step_end

JaggedPass_Movement_PoochyenaRunAway:
	jump_in_place_right
	jump_in_place_right
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

JaggedPass_Movement_PoochyenaApprachPlayer_T:
	walk_fast_up
	walk_fast_right
	step_end

JaggedPass_Movement_PoochyenaApprachPlayer_C:
	walk_fast_right
	step_end

JaggedPass_Movement_PoochyenaApprachPlayer_B:
	walk_fast_down
	walk_fast_right
	step_end

JaggedPass_Movement_PoochyenaJumpAtPlayer:
	jump_right
	delay_16
	step_end

JaggedPass_Movement_PlayerStumbleBackwards:
	lock_facing_direction
	walk_faster_right
	unlock_facing_direction
	step_end

JaggedPass_Movement_PoochyenaRetreat_T:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	face_right
	step_end

JaggedPass_Movement_PoochyenaRetreat_C:
	walk_fast_left
	walk_fast_left
	face_right
	step_end

JaggedPass_Movement_PoochyenaRetreat_B:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	face_right
	step_end

JaggedPass_Movement_TabithaWalkBackwards:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

JaggedPass_Movement_TabithaWalkAway:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

JaggedPass_Movement_Grunt1WalkAway:
	delay_16
	delay_16
	delay_16
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

JaggedPass_Movement_Grunt2WalkAway:
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

JaggedPass_Movement_RuthApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

JaggedPass_Movement_RuthApproachPlayer_T:
	walk_right
	walk_right
	step_end

JaggedPass_Movement_RuthApproachPlayer_C:
	walk_up
	walk_right
	walk_right
	step_end

JaggedPass_Movement_RuthApproachPlayer_B:
	walk_right
	walk_right
	step_end

JaggedPass_Movement_RuthLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

JaggedPass_Movement_FlanneryApproachPlayer_1:
	walk_left
	walk_in_place_down
	step_end

JaggedPass_Movement_FlanneryApproachPlayer_2:
	walk_left
	walk_down
	step_end

JaggedPass_Movement_MayApproachPlayer_1:
	walk_left
	step_end

JaggedPass_Movement_MayApproachPlayer_2:
	walk_down
	walk_left
	step_end

JaggedPass_Movement_FlanneryLeave:
	walk_right
	walk_down
	walk_right
	delay_8
	walk_in_place_left
	step_end

JaggedPass_Movement_MayLeave_1:
	walk_down
	walk_down
	jump_down
	walk_down
	walk_down
	step_end

JaggedPass_Movement_MayLeave_2:
	walk_down
	jump_down
	walk_down
	walk_down
	walk_down
	step_end

JaggedPass_Movement_RuthUnsure:
	delay_16
	face_player
	delay_16
	face_right
	step_end

JaggedPass_Movement_PlayerWalkUpToAsh:
	walk_right
	walk_up
	step_end

JaggedPass_Movement_JumpInPlaceLeftTwice_NoGroundEffect:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

JaggedPass_OnTransition::
	switch VAR_JAGGED_PASS_STATE
	case 0, JaggedPass_OnTransition_3
	case 1, JaggedPass_OnTransition_4
	case 2, JaggedPass_OnTransition_4
	case 3, JaggedPass_OnTransition_5
	case 4, JaggedPass_OnTransition_6
JaggedPass_OnTransition_1:
	setflag FLAG_TEMP_8
	goto_if_set FLAG_LAVARIDGE_GYM_OPEN, JaggedPass_OnTransition_12
JaggedPass_OnTransition_10:
	goto_if_set FLAG_LAVARIDGE_GYM_OPEN, JaggedPass_OnTransition_9
	return

JaggedPass_OnTransition_3:
	setflag FLAG_HIDE_JAGGED_PASS_NPCS
	clearflag FLAG_HIDE_JAGGED_PASS_GRUNTS
	setobjectmovementtype 13, MOVEMENT_TYPE_FACE_RIGHT
	setflag FLAG_TEMP_9
	setflag FLAG_TEMP_10
	goto JaggedPass_OnTransition_1

JaggedPass_OnTransition_4:
	setflag FLAG_HIDE_JAGGED_PASS_NPCS
	clearflag FLAG_HIDE_JAGGED_PASS_GRUNTS
	setobjectmovementtype 13, MOVEMENT_TYPE_FACE_RIGHT
	clearflag FLAG_TEMP_9
	clearflag FLAG_TEMP_10
	switch VAR_STARTER_MON
	case 0, JaggedPass_OnTransition_16
	case 1, JaggedPass_OnTransition_17
	case 2, JaggedPass_OnTransition_18
	goto JaggedPass_OnTransition_1

JaggedPass_OnTransition_5:
	setflag FLAG_HIDE_JAGGED_PASS_GRUNTS
	clearflag FLAG_HIDE_JAGGED_PASS_NPCS
	clearflag FLAG_TEMP_9
	setflag FLAG_TEMP_10
	setobjectxyperm 14, 10, 33
	setobjectmovementtype 14, MOVEMENT_TYPE_LOOK_AROUND
	setflag FLAG_TEMP_7
	goto JaggedPass_OnTransition_1

JaggedPass_OnTransition_6:
	setflag FLAG_HIDE_JAGGED_PASS_GRUNTS
	clearflag FLAG_HIDE_JAGGED_PASS_NPCS
	setflag FLAG_TEMP_9
	setflag FLAG_TEMP_10
	setflag FLAG_TEMP_7
	setobjectxyperm 8, 14, 11
	setobjectmovementtype 8, MOVEMENT_TYPE_LOOK_AROUND
	goto JaggedPass_OnTransition_1

JaggedPass_OnTransition_7:
	clearflag FLAG_TEMP_6
	setvar VAR_TEMP_0, 3
	return

JaggedPass_OnTransition_8:
	setflag FLAG_TEMP_6
	return

JaggedPass_OnTransition_9:
	goto_if_set FLAG_BADGE04_GET, JaggedPass_OnTransition_8
	return

JaggedPass_OnTransition_12:
	goto_if_unset FLAG_BADGE04_GET, JaggedPass_OnTransition_7
	goto JaggedPass_OnTransition_10

JaggedPass_OnTransition_16:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( RUBECKO )
	goto JaggedPass_OnTransition_1

JaggedPass_OnTransition_17:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( AMALGOAT )
	goto JaggedPass_OnTransition_1

JaggedPass_OnTransition_18:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( TOXATOO )
	goto JaggedPass_OnTransition_1


JaggedPass_EventScript_FootprintNerd_Text_0:
	.string "Gunther$"

JaggedPass_EventScript_FootprintNerd_Text_1:
	.string "Hello! You!\p"
	.string "Take a look at these fascinating\n"
	.string "Pokémon footprints here!$"

JaggedPass_EventScript_FootprintNerd_Text_2:
	.string "There's lots of footprints in the ash\n"
	.string "here!\p"
	.string "I'm trying to figure out which Pokémon\n"
	.string "they belong to.\p"
	.string "Maybe I'll let you have a guess when you\n"
	.string "filled out that PokéDex of yours a\l"
	.string "little more.$"

JaggedPass_EventScript_FootprintNerd_Text_3:
	.string "There's lots of footprints in the ash\n"
	.string "here!\p"
	.string "I'm trying to figure out which Pokémon\n"
	.string "they belong to.\p"
	.string "Are you good with Pokémon footprints?$"

JaggedPass_EventScript_FootprintNerd_Text_4:
	.string "I knew you were a fellow footprint\n"
	.string "enthusiast!\p"
	.string "Let Jojo know she needs to find out how\n"
	.string "to display footprints and we'll start!$"

JaggedPass_EventScript_FootprintNerd_Text_5:
	.string "No? That's too bad, I'd have given you\n"
	.string "an item if you got them right.$"

JaggedPass_EventScript_MachBikeTriathlete_Text_0:
	.string "Hmmmm, my Mach Bike isn't suited for\n"
	.string "this kind of terrain…\p"
	.string "If I had an Acro Bike, I could get up\n"
	.string "these rocks and maybe get to the top\l"
	.string "of the mountain…$"

JaggedPass_EventScript_HeadbuttTreeMan_Text_0:
	.string "Pokémon like to hide in large trees like\n"
	.string "this!\p"
	.string "I bet a Pokémon that knows the move\n"
	.string "Headbutt could knock them out of the\l"
	.string "branches.$"

JaggedPass_EventScript_Ruth_Text_0:
	.string "Grr! He won't let me through!\p"
	.string "{PLAYER}, go ahead, I'll catch up once\n"
	.string "I beat this guy!$"

JaggedPass_EventScript_Ruth_Text_1:
	.string "Hey, {PLAYER}!\p"
	.string "My Barboach is starting to catch up!\p"
	.string "Just a little bit more…\p"
	.string "Oh, by the way! Do you see that large\n"
	.string "tree there?\p"
	.string "That man over there said you can knock\n"
	.string "Pokémon out of the branches.\p"
	.string "Argh, I wish one of my Pokémon knew the\n"
	.string "move Headbutt!\p"
	.string "I want to check out what lives up\n"
	.string "there…$"

JaggedPass_EventScript_Ruth_Text_2:
	.string "Hey, {PLAYER}!\p"
	.string "My Barboach is starting to catch up!\p"
	.string "Just a little bit more…\p"
	.string "Oh, by the way! Do you see that large\n"
	.string "tree there?\p"
	.string "My Amalgoat knocked a little Seedot out\n"
	.string "of the branches!\p"
	.string "Do you have a Pokémon that knows the\n"
	.string "move Headbutt?\p"
	.string "You should really try it out!$"

JaggedPass_EventScript_GruntTryStopPlayer2_Text_0:
	.string "Hey! You can't-$"

JaggedPass_EventScript_GruntTryStopPlayer2_Text_1:
	.string "Argh! This annoying little…!$"

JaggedPass_EventScript_GruntWithLostPoochyena_Text_0:
	.string "Come back up here, Poochyena!\p"
	.string "We've got things to do and stairs to\n"
	.string "guard!$"

JaggedPass_EventScript_GruntWithLostPoochyena_Text_1:
	.string "Wha-? Where are you going?!$"

JaggedPass_EventScript_GruntWithLostPoochyena_Text_2:
	.string "No! Leave that wild Numel alone! Bad\n"
	.string "girl!$"

JaggedPass_EventScript_GruntWithLostPoochyena_Text_3:
	.string "What am I supposed to do now?\p"
	.string "I can't stand guard without my\n"
	.string "Poochyena!\p"
	.string "I should've trained the little rascal\n"
	.string "better…$"

JaggedPass_EventScript_MayScene_Text_0:
	.string "Ugh… You're as strong as ever.$"

JaggedPass_EventScript_MayScene_Text_1:
	.string "I'm sorry, but this cave is off-limits.\p"
	.string "It's not safe, there's been cave-ins all\n"
	.string "over the place.$"

JaggedPass_EventScript_MayScene_Text_2:
	.string "Spare me the sarcasm, girl.\p"
	.string "We both know the real reason why you're\n"
	.string "trying to stop us from entering our old\l"
	.string "hideout.\p"
	.string "But it doesn't matter, we'll get in there\n"
	.string "one way or another.\p"
	.string "Don't think for a second you can keep\n"
	.string "us away just because you're a gym\l"
	.string "leader now.$"

JaggedPass_EventScript_MayScene_Text_3:
	.string "May!$"

JaggedPass_EventScript_MayScene_Text_4:
	.string "So, how far did they get?$"

JaggedPass_EventScript_MayScene_Text_5:
	.string "They cleared out a bunch, but the\n"
	.string "path's still blocked by boulders and\l"
	.string "debris.$"

JaggedPass_EventScript_MayScene_Text_6:
	.string "That's good, at least…\p"
	.string "I'll have to see what I can do to close\n"
	.string "off the cave.$"

JaggedPass_EventScript_MayScene_Text_7:
	.string "{PLAYER}, there you are!$"

JaggedPass_EventScript_MayScene_Text_8:
	.string "Oh, and Flannery! And…\p"
	.string "Uhm…$"

JaggedPass_EventScript_MayScene_Text_9:
	.string "The name's May!\p"
	.string "I took over Lavaridge Gym recently.\p"
	.string "And you are?$"

JaggedPass_EventScript_MayScene_Text_10:
	.string "This is my little cousin Ruth, and her\n"
	.string "friend {PLAYER}.\p"
	.string "They came to earn themselves a shiny\n"
	.string "new badge.$"

JaggedPass_EventScript_MayScene_Text_11:
	.string "Oh, I'm sorry I kept you waiting!\p"
	.string "We can go back to Lavaridge\n"
	.string "immediately, if the two of you are\l"
	.string "ready.$"

JaggedPass_EventScript_MayScene_Text_12:
	.string "Wait, right now?\p"
	.string "I… I think I'll stay here for a bit.$"

JaggedPass_EventScript_MayScene_Text_13:
	.string "{PLAYER}, as much as I want to get\n"
	.string "this badge before you, I don't think I\l"
	.string "should rush it right now.\p"
	.string "I'll take my time to build a strong\n"
	.string "foundation and catch up to you in no\l"
	.string "time!$"

JaggedPass_EventScript_MayScene_Text_14:
	.string "Huh? What was that?\p"
	.string "My little cousin… being reasonable?$"

JaggedPass_EventScript_MayScene_Text_15:
	.string "Anyway, May, I think I have to go now.\p"
	.string "You've got the situation under control?$"

JaggedPass_EventScript_MayScene_Text_16:
	.string "Yes, thanks for your help, Flannery!$"

JaggedPass_EventScript_MayScene_Text_17:
	.string "Next visit to the hot springs is on you,\n"
	.string "May!$"

JaggedPass_EventScript_MayScene_Text_18:
	.string "I'll be looking forward to our battle,\n"
	.string "{PLAYER}!$"

JaggedPass_Text_FootprintNerdHey::
	.string "Hey!\p"
	.string "Hey hey!$"

JaggedPass_Text_FootprintNerdPerfectFootprints::
	.string "You didn't intend to step on this ash,\n"
	.string "right?\p"
	.string "Just take a look at those perfect\n"
	.string "Pokémon footprints!$"

JaggedPass_Text_FootprintNerdWannaKnowWhatHappendHere::
	.string "What a specimen!\p"
	.string "Just a look at them and I can see the\n"
	.string "scene it in front of my eyes!\p"
	.string "Want to know what happened here?$"

JaggedPass_Text_FootprintNerdStory::
	.string "These tracks belong to a young Numel,\n"
	.string "snoozing in the volcanic ash, when\l"
	.string "suddenly…\p"
	.string "Bam!\p"
	.string "A Poochyena attacks! Completely out of\n"
	.string "nowhere!\p"
	.string "The Numel, disoriented, gets up and\n"
	.string "tries to run away.\p"
	.string "The Poochyena prepares a second\n"
	.string "attack…\p"
	.string "But it gets distracted by something\n"
	.string "else and runs off.$"

JaggedPass_Text_FootprintNerdNeedToStudy_1::
	.string "Fascinating, isn't it?\p"
	.string "I'll have to study these more!\p"
	.string "I'll have to ask you not to step on this\n"
	.string "patch of ash until I'm done, though.\p"
	.string "Sorry.$"

JaggedPass_Text_FootprintNerdNeedToStudy_2::
	.string "Still, I have to study these!\p"
	.string "I'll have to ask you not to step on this\n"
	.string "patch of ash until I'm done.\p"
	.string "Sorry.$"

JaggedPass_Text_GetHim::
	.string "Get him, {STR_VAR_1}!$"

JaggedPass_Text_RubeckoCry::
	.string "Ribbit!$"

JaggedPass_Text_AmalgoatCry::
	.string "Maaaaaah!$"

JaggedPass_Text_ToxatooCry::
	.string "Too! Tootoo!$"

JaggedPass_Text_PoochyenaGetThem::
	.string "Hey! You can't go here!\p"
	.string "Poochyena, get them!$"
