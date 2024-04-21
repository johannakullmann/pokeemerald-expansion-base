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

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

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
	lock
	faceplayer
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	compare VAR_0x8009, 15
	goto_if_lt JaggedPass_EventScript_FootprintNerd_2
	msgbox JaggedPass_EventScript_FootprintNerd_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq JaggedPass_EventScript_FootprintNerd_5
	msgbox JaggedPass_EventScript_FootprintNerd_Text_3, MSGBOX_AUTOCLOSE
JaggedPass_EventScript_FootprintNerd_4:
	release
	end

JaggedPass_EventScript_FootprintNerd_2:
	msgbox JaggedPass_EventScript_FootprintNerd_Text_0, MSGBOX_AUTOCLOSE
	release
	end

JaggedPass_EventScript_FootprintNerd_5:
	msgbox JaggedPass_EventScript_FootprintNerd_Text_2, MSGBOX_AUTOCLOSE
	goto JaggedPass_EventScript_FootprintNerd_4


JaggedPass_EventScript_MachBikeTriathlete::
	msgbox JaggedPass_EventScript_MachBikeTriathlete_Text_0, MSGBOX_NPC
	end


JaggedPass_EventScript_HeadbuttTreeMan::
	msgbox JaggedPass_EventScript_HeadbuttTreeMan_Text_0, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	end


JaggedPass_EventScript_Ruth::
	lock
	faceplayer
	speakername CommonName_Ruth
	msgbox JaggedPass_EventScript_Ruth_Text_0
	turnobject VAR_LAST_TALKED, DIR_WEST
	switch VAR_STARTER_MON
	case 0, JaggedPass_EventScript_Ruth_3
	case 1, JaggedPass_EventScript_Ruth_4
	case 2, JaggedPass_EventScript_Ruth_5
JaggedPass_EventScript_Ruth_1:
	closemessage
	release
	end

JaggedPass_EventScript_Ruth_3:
	bufferspeciesname STR_VAR_1, SPECIES_RUBECKO
	msgbox JaggedPass_Text_GetHim
	closemessage
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice
	call JaggedPass_EventScript_Rubecko
	goto JaggedPass_EventScript_Ruth_1

JaggedPass_EventScript_Ruth_4:
	bufferspeciesname STR_VAR_1, SPECIES_CHIMERA2
	msgbox JaggedPass_Text_GetHim
	closemessage
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice
	call JaggedPass_EventScript_Amalgoat
	goto JaggedPass_EventScript_Ruth_1

JaggedPass_EventScript_Ruth_5:
	bufferspeciesname STR_VAR_1, SPECIES_TOXATOO
	msgbox JaggedPass_Text_GetHim
	closemessage
	applymovement 15, JaggedPass_Movement_JumpInPlaceLeftTwice_NoGroundEffect
	call JaggedPass_EventScript_Toxatoo
	goto JaggedPass_EventScript_Ruth_1


JaggedPass_EventScript_RuthsMon::
	lock
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


JaggedPass_EventScript_Rubecko::
	speakername CommonName_Rubecko
	playmoncry SPECIES_RUBECKO, CRY_MODE_NORMAL
	msgbox JaggedPass_Text_RubeckoCry
	waitmovement 0
	waitmoncry
	return


JaggedPass_EventScript_Amalgoat::
	speakername CommonName_Amalgoat
	playmoncry SPECIES_CHIMERA2, CRY_MODE_NORMAL
	msgbox JaggedPass_Text_AmalgoatCry
	waitmovement 0
	waitmoncry
	return


JaggedPass_EventScript_Toxatoo::
	speakername CommonName_Toxatoo
	playmoncry SPECIES_TOXATOO, CRY_MODE_NORMAL
	msgbox JaggedPass_Text_ToxatooCry
	waitmovement 0
	waitmoncry
	return


JaggedPass_Movement_JumpInPlaceLeftTwice:
	jump_in_place_left
	jump_in_place_left
	step_end

JaggedPass_Movement_JumpInPlaceLeftTwice_NoGroundEffect:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

JaggedPass_EventScript_FootprintNerd_Text_0:
	.string "There's lots of footprints in the ash\n"
	.string "here!\p"
	.string "I'm trying to figure out which Pokémon\n"
	.string "they belong to.\p"
	.string "Maybe I'll let you have a guess when you\n"
	.string "filled out that PokéDex of yours a\l"
	.string "little more.$"

JaggedPass_EventScript_FootprintNerd_Text_1:
	.string "There's lots of footprints in the ash\n"
	.string "here!\p"
	.string "I'm trying to figure out which Pokémon\n"
	.string "they belong to.\p"
	.string "Are you good with Pokémon footprints?$"

JaggedPass_EventScript_FootprintNerd_Text_2:
	.string "I knew you were a fellow footprint\n"
	.string "enthusiast!\p"
	.string "Let Jojo know she needs to find out how\n"
	.string "to display footprints and we'll start!$"

JaggedPass_EventScript_FootprintNerd_Text_3:
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

JaggedPass_Text_GetHim::
	.string "Get him, {STR_VAR_1}!$"

JaggedPass_Text_RubeckoCry::
	.string "Ribbit!$"

JaggedPass_Text_AmalgoatCry::
	.string "Maaaaaah!$"

JaggedPass_Text_ToxatooCry::
	.string "Too! Tootoo!$"
