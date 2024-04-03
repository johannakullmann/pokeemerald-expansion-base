MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_KirkIntro:
	.string "My electric soul, it'll shatter your\n"
	.string "dreams whole, whoa-yeahah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "That was plugged in, amped up,\n"
	.string "over-driven electric, man!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON and rock, it's all about heart,\n"
	.string "whoa-yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "I trained under WATTSON!\n"
	.string "There ain't no way I'll lose easily!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Unplugged and turned off…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "WATTSON, our GYM LEADER, has been\n"
	.string "around for a long, long time.\p"
	.string "He was battling even before your\n"
	.string "daddy was born, that tough coot.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "This GYM's got puzzles!\n"
	.string "Isn't it fun?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "It's no fun to lose…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "WATTSON says he likes setting up\n"
	.string "little traps with switches.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "With my charm and my POKéMON's moves,\n"
	.string "you'll be shocked!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "I'm shocked by your power!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "I've heard that MAUVILLE was founded\n"
	.string "by WATTSON.\p"
	.string "He was a TRAINER long before we\n"
	.string "became TRAINERS.\l"
	.string "He must know all sorts of things!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "I love shiny things!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh…\n"
	.string "My eyes are frazzled…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "MAUVILLE GYM's WATTSON has a shiny\n"
	.string "forehead. It makes me happy!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "I've given up on my plans to convert\n"
	.string "the city, I have.\p"
	.string "And so, I put my time into making\n"
	.string "door traps in my GYM.\p"
	.string "Oh? Now, what are you doing here?\p"
	.string "What's that? You say you've gotten\n"
	.string "past all my rigged doors?\p"
	.string "Wahahahah!\n"
	.string "Now, that is amusing!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah!\n"
	.string "Go forth and endeavor, youngster!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "MAUVILLE CITY POKéMON GYM$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "MAUVILLE CITY POKéMON GYM\p"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "I'll make sparks fly from you!\n"
	.string "Don't say I didn't warn you!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Oof…\n"
	.string "Our batteries ran dry…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON: We'll have to recharge our\n"
	.string "batteries again.\p"
	.string "When we're fully charged up, we'll\n"
	.string "gladly accept your challenge.\p"
	.string "So, come back again sometime,\n"
	.string "won't you?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Oops! Wait!\n"
	.string "You've only one POKéMON with you!\p"
	.string "Come see me with two or more\n"
	.string "POKéMON, all right?$"

MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MauvilleCity_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MauvilleCity_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 1, MauvilleCity_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

MauvilleCity_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	goto MauvilleCity_Gym_EventScript_GymIntro
	return


MauvilleCity_Gym_OnTransition::
	goto_if_unset FLAG_DONE_MAUVILLE_GYM_INTRO, MauvilleCity_Gym_OnTransition_1
	return

MauvilleCity_Gym_OnTransition_1:
	setvar VAR_TEMP_1, 1
	return


MauvilleCity_Gym_EventScript_GymIntro::
	lock
	applymovement 6, MauvilleCity_Gym_Movement_GymGuideApproach
	waitmovement 0
	speakername CommonName_GymGuide
	msgbox MauvilleCity_Gym_EventScript_GymIntro_Text_0
	closemessage
	turnobject 6, DIR_NORTH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
	waitmovement 0
	speakername CommonName_GymGuide
	msgbox MauvilleCity_Gym_EventScript_GymIntro_Text_1
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	turnobject 6, DIR_SOUTH
	speakername CommonName_GymGuide
	msgbox MauvilleCity_Gym_EventScript_GymIntro_Text_2
	closemessage
	applymovement 6, MauvilleCity_Gym_Movement_GymGuideWalkBack
	waitmovement 0
	setvar VAR_TEMP_1, 0
	setflag FLAG_DONE_MAUVILLE_GYM_INTRO
	release
	end


MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	speakername CommonName_GymGuide
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuide_2
	msgbox MauvilleCity_Gym_EventScript_GymGuide_Text_1
MauvilleCity_Gym_EventScript_GymGuide_1:
	closemessage
	release
	end

MauvilleCity_Gym_EventScript_GymGuide_2:
	msgbox MauvilleCity_Gym_EventScript_GymGuide_Text_0
	goto MauvilleCity_Gym_EventScript_GymGuide_1


MauvilleCity_Gym_EventScript_Wattson::
	lock
	faceplayer
	checktrainerflag TRAINER_WATTSON_1
	goto_if 0, MauvilleCity_Gym_EventScript_Wattson_2
MauvilleCity_Gym_EventScript_Wattson_1:
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	speakername CommonName_Wattson
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

MauvilleCity_Gym_EventScript_Wattson_2:
	speakername CommonName_Wattson
	msgbox MauvilleCity_Gym_Text_WattsonIntro
	special SavePlayerParty
	getpartysize
	compare VAR_RESULT, 3
	goto_if_le MauvilleCity_Gym_EventScript_Wattson_4
	speakername CommonName_Wattson
	msgbox MauvilleCity_Gym_EventScript_Wattson_Text_0
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_ne MauvilleCity_Gym_EventScript_Wattson_8
MauvilleCity_Gym_EventScript_Wattson_7:
	special LoadPlayerParty
	release
	end

MauvilleCity_Gym_EventScript_Wattson_4:
	special SetHalfPartyForBattle
	goto MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty
	goto MauvilleCity_Gym_EventScript_Wattson_1

MauvilleCity_Gym_EventScript_Wattson_8:
	goto MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty
	goto MauvilleCity_Gym_EventScript_Wattson_7


MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty::
	lock
	special ReducePlayerPartyToSelectedMons
	getpartysize
	compare VAR_RESULT, 3
	goto_if_lt MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty_1
	goto MauvilleCity_Gym_EventScript_WattsonGymBattle
	return

MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty_1:
	speakername CommonName_Wattson
	msgbox MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty_4
	special LoadPlayerParty
	release
	end

MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty_4:
	goto MauvilleCity_Gym_EventScript_WattsonGymBattle
	return


MauvilleCity_Gym_EventScript_WattsonGymBattle::
	setflag FLAG_LOAD_SAVED_PARTY_AFTER_NEXT_BATTLE
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonLetsGetStarted, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonAfterBattle, NO_MUSIC
	return


MauvilleCity_Gym_EventScript_WattsonAfterBattle::
	lock
	special LoadPlayerParty
	clearflag FLAG_LOAD_SAVED_PARTY_AFTER_NEXT_BATTLE
	speakername NULL
	message MauvilleCity_Gym_EventScript_WattsonAfterBattle_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	setflag FLAG_HIDE_ROUTE_111_SNORLAX
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	speakername CommonName_Wattson
	msgbox MauvilleCity_Gym_EventScript_WattsonAfterBattle_Text_1, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_TM_SHOCK_WAVE
	speakername CommonName_Wattson
	msgbox MauvilleCity_Gym_EventScript_WattsonAfterBattle_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 30
	speakername NULL
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_EventScript_WattsonAfterBattle_Text_3, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end


MauvilleCity_Gym_Movement_GymGuideApproach:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	face_down
	step_end

MauvilleCity_Gym_Movement_GymGuideWalkBack:
	walk_right
	walk_right
	walk_right
	face_left
	step_end

MauvilleCity_Gym_EventScript_GymIntro_Text_0:
	.string "Yo, how's it going?\p"
	.string "You look like this is your first time\n"
	.string "here, am I right?\p"
	.string "Haha, no need to be so anxious, I'm here\n"
	.string "to tell you exactly what to expect!$"

MauvilleCity_Gym_EventScript_GymIntro_Text_1:
	.string "See those electric doors?\p"
	.string "You can turn them on or off by stepping\n"
	.string "on those switches on the floor!$"

MauvilleCity_Gym_EventScript_GymIntro_Text_2:
	.string "Once you solve the puzzle, the real\n"
	.string "challenge starts!\p"
	.string "Wattson, the Gym Leader, is a user of\n"
	.string "Electric-type Pokémon.\p"
	.string "If you challenge him with Flying- or\n"
	.string "Water-type Pokémon, he'll zap them!\l"
	.string "Bzzt!\p"
	.string "Oh, and before the fight, you'll be\n"
	.string "asked to pick up to three Pokémon to\l"
	.string "fight with.\p"
	.string "That's the same number of Pokémon the\n"
	.string "Gym Leader will be using, after all.\p"
	.string "Well, go for it! Show them what you're\n"
	.string "made of!$"

MauvilleCity_Gym_EventScript_GymGuide_Text_0:
	.string "Whoa, you're electrifying! You've\n"
	.string "powered the door open!$"

MauvilleCity_Gym_EventScript_GymGuide_Text_1:
	.string "Wattson, the Gym Leader, is a user of\n"
	.string "Electric-type Pokémon.\p"
	.string "If you challenge him with Flying- or\n"
	.string "Water-type Pokémon, he'll zap them!\l"
	.string "Bzzt!\p"
	.string "Good luck, challenger!$"

MauvilleCity_Gym_EventScript_Wattson_Text_0:
	.string "Then go ahead and choose your team of\n"
	.string "three!$"

MauvilleCity_Gym_EventScript_WattsonGymBattle_CheckConfirmSmallParty_Text_0:
	.string "Wahaha! You got guts, going into your\n"
	.string "first gym battle with a handicap!\p"
	.string "Are you sure you want to face me with\n"
	.string "less than three Pokémon?$"

MauvilleCity_Gym_EventScript_WattsonAfterBattle_Text_0:
	.string "{PLAYER} received the Dynamo Badge\nfrom Wattson.$"

MauvilleCity_Gym_EventScript_WattsonAfterBattle_Text_1:
	.string "Hmm…\nYou should take this, too!$"

MauvilleCity_Gym_EventScript_WattsonAfterBattle_Text_2:
	.string "That TM34 there contains Shock Wave.\p"
	.string "It's a trustworthy move that never\n"
	.string "misses! You can count on it!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_EventScript_WattsonAfterBattle_Text_3:
	.string "Registered Gym Leader Wattson\nin the PokéNav.$"

MauvilleCity_Gym_Text_WattsonLetsGetStarted::
	.string "Then let's get started, shall we?\p"
	.string "I, Wattson, the leader of Mauville Gym,\n"
	.string "shall electrify you!$"

MauvilleCity_Gym_Text_WattsonDefeat::
	.string "Wahahahah!\n"
	.string "Fine, I lost!\p"
	.string "You ended up giving me a thrill!\n"
	.string "Take this Badge!$"

MauvilleCity_Gym_Text_WattsonPostBattle::
	.string "I swell with optimism, seeing a promising\n"
	.string "young trainer like you!$"
