.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "The BOSS got interested in\n"
	.string "the research they have going here,\l"
	.string "so he sent us out.\p"
	.string "You quit meddling!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Blast it…\n"
	.string "Blasted by a kid…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Our BOSS knows everything.\p"
	.string "But I'm just a GRUNT. What would I know\n"
	.string "about what he's thinking?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Huh?\n"
	.string "What's a kid doing here?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Huh?\n"
	.string "I lost?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, no…\n"
	.string "I'll catch an earful for losing to a kid…\p"
	.string "I should just take a nap in the bed…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "While I was sleeping, everyone went\n"
	.string "upstairs!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wow, you're really strong!\p"
	.string "I wish I could be a POKéMON TRAINER\n"
	.string "like you!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "The PROFESSOR loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the PROFESSOR is studying\n"
	.string "if the rain can be put to good use.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "On the 2nd floor of the INSTITUTE,\n"
	.string "we study the weather patterns over\l"
	.string "the HOENN region.\p"
	.string "We've been noticing temporary and\n"
	.string "isolated cases of droughts and\l"
	.string "heavy rain lately…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the AQUAS were up to.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "There's a bed…\n"
	.string "Let's take a rest.$"

Route119_WeatherInstitute_1F_OnTransition::
	goto_if_unset FLAG_HIDE_ROUTE_119_CASTFORM_SCIENTIST, Route119_WeatherInstitute_1F_OnTransition_2
Route119_WeatherInstitute_1F_OnTransition_1:
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_1F_OnTransition_5
Route119_WeatherInstitute_1F_OnTransition_4:
	call Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers
	end

Route119_WeatherInstitute_1F_OnTransition_2:
	setflag FLAG_TEMP_4
	goto Route119_WeatherInstitute_1F_OnTransition_1

Route119_WeatherInstitute_1F_OnTransition_5:
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	goto Route119_WeatherInstitute_1F_OnTransition_4


Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers::
	goto_if_unset FLAG_FOUND_SHOAL_CAVE_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_2
Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_1:
	goto_if_unset FLAG_FOUND_MT_PYRE_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_5
Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_4:
	goto_if_unset FLAG_FOUND_MT_CHIMNEY_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_8
Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_7:
	return

Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_2:
	setflag FLAG_TEMP_5
	goto Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_1

Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_5:
	setflag FLAG_TEMP_6
	goto Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_4

Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_8:
	setflag FLAG_TEMP_7
	goto Route119_WeatherInstitute_1F_EventScript_SetupFieldResearchers_7


Route119_WeatherInstitute_2F_EventScript_FormerAquaMember::
	lock
	faceplayer
	speakername Route119_WeatherInstitute_2F_EventScript_FormerAquaMember_Text_0
	msgbox Route119_WeatherInstitute_2F_EventScript_FormerAquaMember_Text_1, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	closemessage
	end


Route119_WeatherInstitute_2F_EventScript_FormerMagmaMember::
	lock
	faceplayer
	speakername Route119_WeatherInstitute_2F_EventScript_FormerMagmaMember_Text_0
	msgbox Route119_WeatherInstitute_2F_EventScript_FormerMagmaMember_Text_1, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	closemessage
	end


Route119_WeatherInstitute_EventScript_Castform::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	speakername CommonName_BufferedNameString1
	playmoncry SPECIES_CASTFORM, CRY_MODE_NORMAL
	msgbox Common_Text_Castform_Cry
	closemessage
	waitmoncry
	release
	end


Route119_WeatherInstitute_1F_EventScript_CastformScientist::
	lock
	faceplayer
	speakername Route119_WeatherInstitute_1F_EventScript_CastformScientist_Text_0
	msgbox Route119_WeatherInstitute_1F_EventScript_CastformScientist_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end


Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	lock
	faceplayer
	speakername Route119_WeatherInstitute_1F_Text_Martin
	goto_if_set FLAG_FOUND_VERDANTURF_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_4
Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_1:
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_15
	msgbox Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_Text_1
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_2:
	goto Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform
	goto Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_1

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_3:
	goto_if_set FLAG_FOUND_SHOAL_CAVE_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_8
	goto Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_1

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_4:
	goto_if_set FLAG_FOUND_SOOTOPOLIS_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_3
	goto Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_1

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_7:
	goto_if_set FLAG_FOUND_MT_PYRE_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_11
	goto Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_1

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_8:
	goto_if_set FLAG_FOUND_ROUTE120_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_7
	goto Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_1

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_11:
	goto_if_set FLAG_FOUND_MT_CHIMNEY_RESEARCHER, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_2
	goto Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_1

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_15:
	msgbox Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_Text_0
	closemessage
	release
	end


Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform::
	msgbox Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_2
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM_NORMAL
	givemon SPECIES_CASTFORM, 30, item = ITEM_MYSTIC_WATER, move1 = MOVE_WEATHER_BALL, move2 = MOVE_SUNNY_DAY, move3 = MOVE_RAIN_DANCE, move4 = MOVE_HAIL, isShiny = TRUE
	switch VAR_RESULT
	case MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_5
	case MON_GIVEN_TO_PC, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_6
	case MON_CANT_GIVE, Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_7
	return

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_2:
	msgbox Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_Text_1
	closemessage
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_5:
	speakername NULL
	call Route119_WeatherInstitute_1F_EventScript_ReceivedCastformFanfare
	speakername Route119_WeatherInstitute_1F_Text_Martin
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_1F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_1F_EventScript_ExplainCastform
	return

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_6:
	speakername NULL
	call Route119_WeatherInstitute_1F_EventScript_ReceivedCastformFanfare
	speakername Route119_WeatherInstitute_1F_Text_Martin
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_1F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_1F_EventScript_SendCastformToPC
	return

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_7:
	msgbox Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_Text_2
	closemessage
	release
	end


Route119_WeatherInstitute_1F_EventScript_SendCastformToPC::
	speakername NULL
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_1F_EventScript_ExplainCastform
	return


Route119_WeatherInstitute_1F_EventScript_ReceivedCastformFanfare::
	applymovement 6, EnterPokeballMovement
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_1F_EventScript_ReceivedCastformFanfare_Text_0
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM_NORMAL
	return


Route119_WeatherInstitute_1F_EventScript_ExplainCastform::
	speakername Route119_WeatherInstitute_1F_Text_Martin
	msgbox Route119_WeatherInstitute_1F_EventScript_ExplainCastform_Text_0, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end


Route119_WeatherInstitute_1F_EventScript_ShoalCaveResearcher::
	lock
	speakername Route119_WeatherInstitute_1F_EventScript_ShoalCaveResearcher_Text_0
	msgbox Route119_WeatherInstitute_1F_EventScript_ShoalCaveResearcher_Text_1
	closemessage
	release
	end


Route119_WeatherInstitute_1F_EventScript_MtPyreResearcher::
	lock
	faceplayer
	speakername Route119_WeatherInstitute_1F_EventScript_MtPyreResearcher_Text_0
	msgbox Route119_WeatherInstitute_1F_EventScript_MtPyreResearcher_Text_1
	closemessage
	release
	end


Route119_WeatherInstitute_1F_EventScript_MtChimneyResearcher::
	lock
	faceplayer
	speakername Route119_WeatherInstitute_1F_EventScript_MtChimneyResearcher_Text_0
	msgbox Route119_WeatherInstitute_1F_EventScript_MtChimneyResearcher_Text_1
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end


Route119_WeatherInstitute_2F_EventScript_FormerAquaMember_Text_0:
	.string "Tiberius$"

Route119_WeatherInstitute_2F_EventScript_FormerAquaMember_Text_1:
	.string "I always loved the ocean, so I joined\n"
	.string "Team Aqua.\p"
	.string "Yep, that was a huge mistake - I left to\n"
	.string "work at the weather institute.\p"
	.string "I almost had a heart attack when my\n"
	.string "former Boss showed up here!\p"
	.string "I know he regrets his actions, but it\n"
	.string "gives me the creeps having him run\l"
	.string "around.$"

Route119_WeatherInstitute_2F_EventScript_FormerMagmaMember_Text_0:
	.string "Keegan$"

Route119_WeatherInstitute_2F_EventScript_FormerMagmaMember_Text_1:
	.string "I fell for Team Magma's recruitmen\n"
	.string "scheme…\p"
	.string "The nerve, saying they wanted to\n"
	.string "conserve habitats for Pokémon!\p"
	.string "And then having Groudon wreak havoc on\n"
	.string "the climate!\p"
	.string "I'm glad Boss is making an effort to\n"
	.string "reverse the damage.$"

Route119_WeatherInstitute_1F_EventScript_CastformScientist_Text_0:
	.string "Milton$"

Route119_WeatherInstitute_1F_EventScript_CastformScientist_Text_1:
	.string "This Castform is very sensitive to\n"
	.string "atmospheric conditions.\p"
	.string "It's in its normal form now, that means\n"
	.string "the rain will clear soon!$"

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_Text_0:
	.string "Our field researchers take Castform all\n"
	.string "over the region to check on the climate\l"
	.string "conditions.\p"
	.string "They're a big help in predicting\n"
	.string "abnormal weather conditions!$"

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_Text_1:
	.string "The number of Castform at the\n"
	.string "institute has grown a lot after the\l"
	.string "weather crisis.\p"
	.string "The ones you see here aren't even all of\n"
	.string "them!\p"
	.string "I think we have about a dozen.\p"
	.string "Our field researchers take them all\n"
	.string "over the region to check on the climate\l"
	.string "conditions.\p"
	.string "Maybe you'll run into some of them!$"

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_Text_0:
	.string "It's really packed with all the Castform\n"
	.string "back at the institute.\p"
	.string "I'm starting to think the others are\n"
	.string "right and we do have to many.\p"
	.string "Hey, you're a trainer, right?\p"
	.string "Do you want to take care of this\n"
	.string "funny-colored little guy?$"

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_Text_1:
	.string "You can always come back if you change\n"
	.string "your mind.$"

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2_GiveShinyCastform_Text_2:
	.string "Oh wow, your PC is even more crowded\n"
	.string "than the institute!\p"
	.string "Come back after you made some space.$"

Route119_WeatherInstitute_1F_EventScript_ReceivedCastformFanfare_Text_0:
	.string "{PLAYER} received Castform!$"

Route119_WeatherInstitute_1F_EventScript_ExplainCastform_Text_0:
	.string "Like you probably saw, Castform\n"
	.string "changes its appearance and type with\l"
	.string "the weather.\p"
	.string "It also knows the move Weather Ball.\p"
	.string "That move doubles in power and has a\n"
	.string "different effect with weather effects\l"
	.string "on the battlefield!$"

Route119_WeatherInstitute_1F_EventScript_ShoalCaveResearcher_Text_0:
	.string "Javiera$"

Route119_WeatherInstitute_1F_EventScript_ShoalCaveResearcher_Text_1:
	.string "Temperatures in Shoal Cave back below\n"
	.string "zero…\p"
	.string "Cold enough to freeze my butt off.\p"
	.string "Note: Bring thermos next time.$"

Route119_WeatherInstitute_1F_EventScript_MtPyreResearcher_Text_0:
	.string "Levi$"

Route119_WeatherInstitute_1F_EventScript_MtPyreResearcher_Text_1:
	.string "So Castform doesn't have a fog form…\p"
	.string "I wonder if there's other forms we don't\n"
	.string "know about yet.$"

Route119_WeatherInstitute_1F_EventScript_MtChimneyResearcher_Text_0:
	.string "Felicity$"

Route119_WeatherInstitute_1F_EventScript_MtChimneyResearcher_Text_1:
	.string "It's you! From Mount Chimney!\p"
	.string "I should get some other clothes with a\n"
	.string "hood.\p"
	.string "I really want to leave the time with\n"
	.string "Team Magma behind me…$"

Route119_WeatherInstitute_1F_Text_Martin::
	.string "Martin$"
