Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
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
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto(Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather)
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "The INSTITUTE created a type of\n"
	.string "POKéMON that has something to do with\l"
	.string "the weather. We're here to take them!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Our plan's being spoiled by a kid?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "If the POKéMON they made here can\n"
	.string "control the weather freely, then we of\l"
	.string "TEAM AQUA definitely need it!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "We're TEAM AQUA!\n"
	.string "We appear wherever anything rare is\l"
	.string "found!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "You got me!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "You don't have any idea what we of\n"
	.string "TEAM AQUA are working towards!\l"
	.string "You stay out of our way!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Don't tell me you're looking for that\n"
	.string "weather POKéMON, too?\p"
	.string "That's a no-no!\n"
	.string "We were here to get it first!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Oh, will you look at my POKéMON?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Humph, so what?\n"
	.string "What we want…\p"
	.string "What we really want isn't here…\n"
	.string "Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "You're going to meddle in TEAM AQUA's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!\p"
	.string "You're so cute, you're disgusting!\n"
	.string "I'll put you down, kiddy!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahahaha!\n"
	.string "You're disgustingly strong!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "It's bad enough to have TEAM MAGMA\n"
	.string "blunder about, but now there's you!\p"
	.string "What makes you want to sniff around\n"
	.string "in our business, anyway?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "We have a situation here!\p"
	.string "A TEAM MAGMA mob just passed\n"
	.string "the WEATHER INSTITUTE.\p"
	.string "They appear to be headed for\n"
	.string "MT. PYRE!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "What?!\p"
	.string "We can't waste any more time here!\n"
	.string "We have to hurry to MT. PYRE, too!\p"
	.string "Ahahahaha!\n"
	.string "TEAM MAGMA, just you wait!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this POKéMON.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"

Route119_WeatherInstitute_2F_OnTransition::
	goto_if_unset FLAG_DELIVERED_MAYS_PACKAGE, Route119_WeatherInstitute_2F_OnTransition_2
	setflag FLAG_TEMP_4
Route119_WeatherInstitute_2F_OnTransition_1:
	call Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers
	call Route119_WeatherInstitute_2F_EventScript_SetupCastformForms
	end

Route119_WeatherInstitute_2F_OnTransition_2:
	call Route119_WeatherInstitute_2F_EventScript_SetupArchieMaxieScene
	goto Route119_WeatherInstitute_2F_OnTransition_1


Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers::
	goto_if_unset FLAG_FOUND_ROUTE120_RESEARCHER, Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_2
Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_1:
	goto_if_unset FLAG_FOUND_VERDANTURF_RESEARCHER, Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_5
Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_4:
	goto_if_unset FLAG_FOUND_SOOTOPOLIS_RESEARCHER, Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_8
Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_7:
	goto_if_unset FLAG_FOUND_DESERT_RESEARCHER, Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_11
Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_10:
	return

Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_2:
	setflag FLAG_TEMP_5
	goto Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_1

Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_5:
	setflag FLAG_TEMP_6
	goto Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_4

Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_8:
	setflag FLAG_TEMP_7
	goto Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_7

Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_11:
	setflag FLAG_TEMP_8
	goto Route119_WeatherInstitute_2F_EventScript_SetupFieldResearchers_10


Route119_WeatherInstitute_2F_EventScript_SetupCastformForms::
	specialvar VAR_RESULT, GetRoute119Weather
	switch VAR_RESULT
	case WEATHER_RAIN, Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_3
	case WEATHER_RAIN_THUNDERSTORM, Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_3
	case WEATHER_SUNNY, Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_4
Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_1:
	specialvar VAR_RESULT, GetRoute119NextWeather
	switch VAR_RESULT
	case WEATHER_RAIN, Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_7
	case WEATHER_RAIN_THUNDERSTORM, Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_7
	case WEATHER_SUNNY, Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_8
Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_5:
	return

Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_3:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( CASTFORM_RAINY )
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( CASTFORM_RAINY )
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_SPECIES ( CASTFORM_RAINY )
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_SPECIES ( CASTFORM_RAINY )
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_SPECIES ( CASTFORM_RAINY )
	goto Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_1

Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_4:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( CASTFORM )
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( CASTFORM )
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_SPECIES ( CASTFORM )
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_SPECIES ( CASTFORM )
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_SPECIES ( CASTFORM )
	goto Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_1

Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_7:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CASTFORM_RAINY )
	goto Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_5

Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_8:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES ( CASTFORM )
	goto Route119_WeatherInstitute_2F_EventScript_SetupCastformForms_5


Route119_WeatherInstitute_2F_EventScript_SetupArchieMaxieScene::
	setobjectxyperm 2, 14, 6
	return


Route119_WeatherInstitute_2F_EventScript_Archie::
	goto_if_unset FLAG_DELIVERED_MAYS_PACKAGE, Route119_WeatherInstitute_2F_EventScript_Archie_2
Route119_WeatherInstitute_2F_EventScript_Archie_1:
	lock
	faceplayer
	speakername CommonName_Archie
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_Archie_5
	bufferstring STR_VAR_1, Route119_WeatherInstitute_2F_EventScript_Archie_Text_1
Route119_WeatherInstitute_2F_EventScript_Archie_4:
	msgbox Route119_WeatherInstitute_2F_EventScript_Archie_Text_2
	closemessage
	turnobject 2, DIR_NORTH
	release
	end

Route119_WeatherInstitute_2F_EventScript_Archie_2:
	goto Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage
	goto Route119_WeatherInstitute_2F_EventScript_Archie_1

Route119_WeatherInstitute_2F_EventScript_Archie_5:
	bufferstring STR_VAR_1, Route119_WeatherInstitute_2F_EventScript_Archie_Text_0
	goto Route119_WeatherInstitute_2F_EventScript_Archie_4


Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage::
	lock
	faceplayer
	speakername CommonName_Archie
	msgbox Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 36
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_1
	closemessage
	applymovement 2, Route119_WeatherInstitute_2F_ArchieReturnToWorkplace
	delay 30
	speakername CommonName_Maxie
	msgbox Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_2
	closemessage
	waitmovement 0
	applymovement 3, Route119_WeatherInstitute_2F_MaxieApproachPlayer
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_3
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	speakername NULL
	setvar VAR_0x8004, ITEM_MAYS_PACKAGE
	call Common_EventScript_PlayerHandedOverTheItem
	speakername CommonName_Maxie
	msgbox Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_PlayerMakeRoom
	applymovement 3, Route119_WeatherInstitute_2F_MaxieLeave
	waitmovement 3
	playse SE_FU_ZAKU
	removeobject 3
	waitse
	setobjectxyperm 2, 2, 2
	removeobject 2
	addobject 2
	setflag FLAG_HIDE_ROUTE_119_CASTFORM_SCIENTIST
	setflag FLAG_DELIVERED_MAYS_PACKAGE
	release
	end


Route119_WeatherInstitute_2F_EventScript_Route120FieldResearcher::
	lock
	msgbox Route119_WeatherInstitute_2F_EventScript_Route120FieldResearcher_Text_0
	closemessage
	release
	end


Route119_WeatherInstitute_2F_EventScript_VerdanturfFieldResearcher::
	lock
	speakername Route119_WeatherInstitute_2F_EventScript_VerdanturfFieldResearcher_Text_0
	msgbox Route119_WeatherInstitute_2F_EventScript_VerdanturfFieldResearcher_Text_1
	closemessage
	applymovement 4, Common_Movement_JumpInPlaceDown
	waitmovement 0
	speakername Route119_WeatherInstitute_2F_EventScript_VerdanturfFieldResearcher_Text_2
	playmoncry SPECIES_CASTFORM, CRY_MODE_NORMAL
	msgbox Common_Text_Castform_Cry
	closemessage
	waitmoncry
	release
	end


Route119_WeatherInstitute_2F_EventScript_SootopolisFieldResearcher::
	lock
	speakername Route119_WeatherInstitute_2F_EventScript_SootopolisFieldResearcher_Text_0
	msgbox Route119_WeatherInstitute_2F_EventScript_SootopolisFieldResearcher_Text_1
	closemessage
	release
	end


Route119_WeatherInstitute_2F_EventScript_ExpositionManiac::
	lock
	faceplayer
	speakername Route119_WeatherInstitute_2F_EventScript_ExpositionManiac_Text_0
	msgbox Route119_WeatherInstitute_2F_EventScript_ExpositionManiac_Text_1
	closemessage
	release
	end


Route119_WeatherInstitute_2F_EventScript_DesertFieldResearcher::
	lock
	faceplayer
	speakername Route119_WeatherInstitute_2F_EventScript_DesertFieldResearcher_Text_0
	msgbox Route119_WeatherInstitute_2F_EventScript_DesertFieldResearcher_Text_1
	closemessage
	release
	end


Route119_WeatherInstitute_2F_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_ArchieReturnToWorkplace:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route119_WeatherInstitute_2F_MaxieApproachPlayer:
	walk_fast_up
	walk_fast_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_PlayerMakeRoom:
	walk_up
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	step_end

Route119_WeatherInstitute_2F_MaxieLeave:
	delay_8
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_WeatherInstitute_2F_EventScript_Archie_Text_0:
	.string "boy$"

Route119_WeatherInstitute_2F_EventScript_Archie_Text_1:
	.string "girl$"

Route119_WeatherInstitute_2F_EventScript_Archie_Text_2:
	.string "Hm?\n"
	.string "Oh, the errand {STR_VAR_1}.\p"
	.string "Yes, I used to be the leader of Team\n"
	.string "Aqua.\p"
	.string "I have done some bad things in the\n"
	.string "past, now it's my responsibility to fix\l"
	.string "that.$"

Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_0:
	.string "Hm?\n"
	.string "And who might you be?\p"
	.string "…\p"
	.string "{PLAYER}? And you have something to\n"
	.string "deliver? From Lavaridge Town's Gym\l"
	.string "Leader?\p"
	.string "Let me see…$"

Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_1:
	.string "Maxie!\n"
	.string "Here's more work for you!\p"
	.string "Your minions are stirring up trouble\n"
	.string "again!$"

Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_2:
	.string "For the last time Archie, stop calling\n"
	.string "them my minions!\p"
	.string "You don't have any control over what's\n"
	.string "left of Team Aqua either!$"

Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_3:
	.string "So, what do you have for me?$"

Route119_WeatherInstitute_2F_EventScript_ArchieDeliverPackage_Text_4:
	.string "…\p"
	.string "That's… not good.\p"
	.string "Would you mind letting me through?$"

Route119_WeatherInstitute_2F_EventScript_Route120FieldResearcher_Text_0:
	.string "Hmmm, the amount of rain on Route 120\n"
	.string "over the past year is…\p"
	.string "Yes, that sounds about right…$"

Route119_WeatherInstitute_2F_EventScript_VerdanturfFieldResearcher_Text_0:
	.string "Trevor$"

Route119_WeatherInstitute_2F_EventScript_VerdanturfFieldResearcher_Text_1:
	.string "You're so high up, Bubbles!$"

Route119_WeatherInstitute_2F_EventScript_VerdanturfFieldResearcher_Text_2:
	.string "Bubbles$"

Route119_WeatherInstitute_2F_EventScript_SootopolisFieldResearcher_Text_0:
	.string "Silvia$"

Route119_WeatherInstitute_2F_EventScript_SootopolisFieldResearcher_Text_1:
	.string "Ah, that trip to Sootopolis City was\n"
	.string "like a vacation…\p"
	.string "Why does the institute have to be in\n"
	.string "such a perpetually rainy place?$"

Route119_WeatherInstitute_2F_EventScript_ExpositionManiac_Text_0:
	.string "Florent$"

Route119_WeatherInstitute_2F_EventScript_ExpositionManiac_Text_1:
	.string "There's so much to do…\p"
	.string "After Groudon and Kyogre woke up, the\n"
	.string "climate went wild all over the region.\p"
	.string "We're doing our best to predict\n"
	.string "abnormal weather events with\l"
	.string "Castform's help.$"

Route119_WeatherInstitute_2F_EventScript_DesertFieldResearcher_Text_0:
	.string "Irwin$"

Route119_WeatherInstitute_2F_EventScript_DesertFieldResearcher_Text_1:
	.string "We thought we knew all about Castform's\n"
	.string "forms.\p"
	.string "But the existence of a Sandy form…\p"
	.string "I swear we tested this before, too…\p"
	.string "Did the reappearance of Groudon and\n"
	.string "Kyogre change something?\p"
	.string "$"
