.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
	.string "Oh? While I visited the hot springs,\n"
	.string "you got the LAVARIDGE GYM BADGE.\p"
	.string "You must have collected\n"
	.string "good POKéMON…\l"
	.string "No, I believe you raised some.\p"
	.string "I guess it would be okay for you to\n"
	.string "have this.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "MAY: With those GO-GOGGLES, you'll\n"
	.string "have no trouble getting through the\l"
	.string "desert near ROUTE 111.\p"
	.string "But, wow, {PLAYER}{KUN}…\n"
	.string "Challenging GYMS…\p"
	.string "You're trying hard because you don't\n"
	.string "want to lose to me, I bet!\p"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
	.string "your dad in PETALBURG GYM.\p"
	.string "See you again!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "That's a decent collection of BADGES.\p"
	.string "All right, then.\n"
	.string "You may as well have this.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN: Keep those with you if you're\n"
	.string "planning on going into that desert near\l"
	.string "ROUTE 111.\p"
	.string "There should be some POKéMON that\n"
	.string "are exclusively desert-dwellers.\l"
	.string "You might look around for those.\p"
	.string "As for me…\n"
	.string "I'm considering challenging NORMAN,\l"
	.string "the GYM LEADER of PETALBURG.\p"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
	.string "he really is tough.\p"
	.string "See you around!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "I have here an EGG.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with POKéMON and\l"
	.string "carried about.\p"
	.string "You are a TRAINER, yes?\n"
	.string "And your POKéMON radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this EGG to hatch?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} received the EGG.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Every so often, an EGG will be found at\n"
	.string "the POKéMON DAY CARE.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A POKéMON nipped my backside!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "GYM LEADER like FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "If people put POKéMON in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"

LavaridgeTown_Text_TownSign:
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER HOT SPRINGS\n"
	.string "An excellent place for relaxing!”$"

LavaridgeTown_Text_GymSign:
	.string "LAVARIDGE TOWN POKéMON GYM\n"
	.string "LEADER: FLANNERY\l"
	.string "“One with a fiery passion that burns!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "POKéMON HERB SHOP\n"
	.string "“Bitter taste--better cure!”$"

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeTown_OnLoad
	.byte 0


LavaridgeTown_OnTransition::
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	goto_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_OnTransition_2
LavaridgeTown_OnTransition_1:
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_OnTransition_5
LavaridgeTown_OnTransition_4:
	setflag FLAG_TEMP_10
	end

LavaridgeTown_OnTransition_2:
	call LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	goto LavaridgeTown_OnTransition_1

LavaridgeTown_OnTransition_5:
	call LavaridgeTown_EventScript_ShowMtChimneyTrainers
	goto LavaridgeTown_OnTransition_4


LavaridgeTown_OnLoad::
	compare VAR_LAVARIDGE_TOWN_STATE, 2
	goto_if_le LavaridgeTown_OnLoad_2
LavaridgeTown_OnLoad_1:
	return

LavaridgeTown_OnLoad_2:
	call LavaridgeTown_EventScript_LockGymDoor
	goto LavaridgeTown_OnLoad_1


LavaridgeTown_EventScript_LockGymDoor::
	setmetatile 5, 15, METATILE_Lavaridge_GymDoor_Closed, TRUE
	end


EventScript_ClosedLavaridgeGymDoor::
	msgbox EventScript_ClosedLavaridgeGymDoor_Text_0, MSGBOX_SIGN
	closemessage
	compare VAR_LAVARIDGE_TOWN_STATE, 0
	goto_if_eq EventScript_ClosedLavaridgeGymDoor_2
EventScript_ClosedLavaridgeGymDoor_1:
	end

EventScript_ClosedLavaridgeGymDoor_2:
	applymovement 9, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox EventScript_ClosedLavaridgeGymDoor_Text_1
	goto LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene
	goto EventScript_ClosedLavaridgeGymDoor_1


LavaridgeTown_EventScript_Ruth::
	lock
	faceplayer
	speakername CommonName_Ruth
	compare VAR_LAVARIDGE_TOWN_STATE, 0
	goto_if_eq LavaridgeTown_EventScript_Ruth_2
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	goto_if_eq LavaridgeTown_EventScript_Ruth_3
LavaridgeTown_EventScript_Ruth_1:
	release
	end

LavaridgeTown_EventScript_Ruth_2:
	msgbox EventScript_ClosedLavaridgeGymDoor_Text_1
	closemessage
	clearflag FLAG_TEMP_10
	addobject 8
	showobjectat 8, MAP_LAVARIDGE_TOWN
	goto LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene
	goto LavaridgeTown_EventScript_Ruth_1

LavaridgeTown_EventScript_Ruth_3:
	msgbox LavaridgeTown_EventScript_Ruth_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeTown_EventScript_Ruth_6
	goto LavaridgeTown_EventScript_Ruth_1

LavaridgeTown_EventScript_Ruth_6:
	goto LavaridgeTown_EventScript_RuthBattle
	goto LavaridgeTown_EventScript_Ruth_1


LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene::
	lock
	closemessage
	delay 16
	applymovement 8, LavaridgeTown_Movement_FlanneryApproachGym
	waitmovement 0
	applymovement 9, LavaridgeTown_Movement_RuthNoticeFlannery
	playse SE_PIN
	waitmovement 0
	speakername CommonName_Ruth
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_0
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 5
	goto_if_eq LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_2
	applymovement 9, LavaridgeTown_Movement_RuthApproachFlannery_2
LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_1:
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	speakername CommonName_Ruth
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_1
	closemessage
	applymovement 8, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	speakername CommonName_Flannery
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_2
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceRight
	waitmovement 0
	speakername CommonName_Ruth
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_3
	applymovement 9, Common_Movement_WalkInPlaceLeft
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_4
	closemessage
	compare VAR_0x8008, 5
	goto_if_eq LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_6
	compare VAR_0x8008, 4
	goto_if_eq LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_7
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerApproachFlannery_3
LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_5:
	waitmovement 0
	turnobject 9, DIR_SOUTH
	speakername CommonName_Ruth
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_5
	closemessage
	applymovement 8, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject 9, DIR_EAST
	speakername CommonName_Flannery
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_6
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceRight
	speakername CommonName_Ruth
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_7
	closemessage
	applymovement 8, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	speakername CommonName_Flannery
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_8
	turnobject 8, DIR_EAST
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_9
	closemessage
	applymovement 8, LavaridgeTown_Movement_FlanneryLeave_1
	waitmovement 0
	speakername CommonName_Ruth
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_10, MSGBOX_AUTOCLOSE
	applymovement 8, LavaridgeTown_Movement_FlanneryLeave_2
	waitmovement 0
	setflag FLAG_TEMP_10
	removeobject 8
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	delay 30
	speakername CommonName_Ruth
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_11
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_12
	goto LavaridgeTown_EventScript_RuthBattle
	release
	end

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_2:
	applymovement 9, LavaridgeTown_Movement_RuthApproachFlannery_1
	goto LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_1

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_6:
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerApproachFlannery_1
	goto LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_5

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_7:
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerApproachFlannery_2
	goto LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_5


LavaridgeTown_EventScript_RuthBattle::
	switch VAR_STARTER_MON
	case 0, LavaridgeTown_EventScript_RuthBattle_3
	case 1, LavaridgeTown_EventScript_RuthBattle_4
	case 2, LavaridgeTown_EventScript_RuthBattle_5
LavaridgeTown_EventScript_RuthBattle_1:
	goto LavaridgeTown_EventScript_AfterRuthBattle
	return

LavaridgeTown_EventScript_RuthBattle_3:
	trainerbattle_no_intro TRAINER_RUTH_LAVARIDGE_TOXATIEL, LavaridgeTown_Text_RuthDefeat
	goto LavaridgeTown_EventScript_RuthBattle_1

LavaridgeTown_EventScript_RuthBattle_4:
	trainerbattle_no_intro TRAINER_RUTH_LAVARIDGE_GROCKO, LavaridgeTown_Text_RuthDefeat
	goto LavaridgeTown_EventScript_RuthBattle_1

LavaridgeTown_EventScript_RuthBattle_5:
	trainerbattle_no_intro TRAINER_RUTH_LAVARIDGE_MERAKID, LavaridgeTown_Text_RuthDefeat
	goto LavaridgeTown_EventScript_RuthBattle_1


LavaridgeTown_EventScript_AfterRuthBattle::
	lock
	speakername CommonName_Ruth
	msgbox LavaridgeTown_EventScript_AfterRuthBattle_Text_0, MSGBOX_AUTOCLOSE
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 7
	goto_if_eq LavaridgeTown_EventScript_AfterRuthBattle_3
LavaridgeTown_EventScript_AfterRuthBattle_1:
	compare VAR_0x8008, 5
	goto_if_eq LavaridgeTown_EventScript_AfterRuthBattle_9
LavaridgeTown_EventScript_AfterRuthBattle_8:
	applymovement 9, LavaridgeTown_Movement_RuthLeave_2
LavaridgeTown_EventScript_AfterRuthBattle_6:
	waitmovement 0
	removeobject 9
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	setflag FLAG_DEFEATED_RIVAL_2
	setflag FLAG_HIDE_JAGGED_PASS_NPCS
	release
	end

LavaridgeTown_EventScript_AfterRuthBattle_2:
	applymovement 9, LavaridgeTown_Movement_RuthLeave_3
	goto LavaridgeTown_EventScript_AfterRuthBattle_1

LavaridgeTown_EventScript_AfterRuthBattle_3:
	compare VAR_0x8009, 17
	goto_if_eq LavaridgeTown_EventScript_AfterRuthBattle_2
	goto LavaridgeTown_EventScript_AfterRuthBattle_1

LavaridgeTown_EventScript_AfterRuthBattle_7:
	applymovement 9, LavaridgeTown_Movement_RuthLeave_1
	goto LavaridgeTown_EventScript_AfterRuthBattle_6

LavaridgeTown_EventScript_AfterRuthBattle_9:
	compare VAR_0x8009, 16
	goto_if_eq LavaridgeTown_EventScript_AfterRuthBattle_7
	goto LavaridgeTown_EventScript_AfterRuthBattle_8


LavaridgeTown_Movement_FlanneryApproachGym:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

LavaridgeTown_Movement_FlanneryApproachPlayer:
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_FlanneryLeave_1:
	walk_fast_right
	walk_fast_up
	walk_up
	delay_16
	delay_16
	walk_down
	step_end

LavaridgeTown_Movement_FlanneryLeave_2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_RuthNoticeFlannery:
	walk_in_place_fast_right
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

LavaridgeTown_Movement_RuthApproachFlannery_1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	step_end

LavaridgeTown_Movement_RuthApproachFlannery_2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_PlayerApproachFlannery_1:
	walk_down
	walk_right
	walk_right
	face_up
	step_end

LavaridgeTown_Movement_PlayerApproachFlannery_2:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

LavaridgeTown_Movement_PlayerApproachFlannery_3:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

LavaridgeTown_Movement_RuthLeave_1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LavaridgeTown_Movement_RuthLeave_2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LavaridgeTown_Movement_RuthLeave_3:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EventScript_ClosedLavaridgeGymDoor_Text_0:
	.string "The door is closed.$"

EventScript_ClosedLavaridgeGymDoor_Text_1:
	.string "Hey, {PLAYER}…\p"
	.string "Looks like we can't challenge the\n"
	.string "Fire-type gym yet, the door's closed.$"

LavaridgeTown_EventScript_Ruth_Text_0:
	.string "The gym leader hasn't come back yet…\n"
	.string "How about we have a go at it again?$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_0:
	.string "Flannery?!$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_1:
	.string "What are you doing here?\p"
	.string "Aren't you really busy with your new\n"
	.string "job?$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_2:
	.string "Haha, the new gym leader asked me to\n"
	.string "help her out with some ruffians.\p"
	.string "But! Ruth! Auntie told me you're\n"
	.string "collecting badges now?\p"
	.string "Haha, to think last year you would've\n"
	.string "had to face me here!\p"
	.string "I would've grilled you!$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_3:
	.string "Psh, just you wait! I'll put out that\n"
	.string "fire of yours some day!$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_4:
	.string "Ah, right! {PLAYER}!$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_5:
	.string "You remember my cousin Flannery, right?\p"
	.string "She was the gym leader of Lavaridge\n"
	.string "Town until a while ago.$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_6:
	.string "Ah, {PLAYER}! You're Ruth's neighbour,\n"
	.string "right?$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_7:
	.string "Yes! {PLAYER} is also challenging the\n"
	.string "gyms! We're competing!\p"
	.string "That reminds me, Flanny, do you know\n"
	.string "where the new gym leader is? The gym\l"
	.string "door is locked.$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_8:
	.string "Huh? She's not inside?$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_9:
	.string "That means she must've already left for\n"
	.string "Mt. Chimney!$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_10:
	.string "Oh, yes. {PLAYER}, Ruth… Why don't you\n"
	.string "two check the hot springs until we got\l"
	.string "that thing sorted?$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_11:
	.string "There she goes…$"

LavaridgeTown_EventScript_FlanneryGymLeaderGoneScene_Text_12:
	.string "… I don't feel like lazing around in the\n"
	.string "hot springs.\p"
	.string "{PLAYER}, care for a quick battle to\n"
	.string "pass the time?$"

LavaridgeTown_EventScript_AfterRuthBattle_Text_0:
	.string "Ah, I thought I could beat you this\n"
	.string "time.\p"
	.string "Looks like I need to step up my game a\n"
	.string "little bit more to win against you!\p"
	.string "I noticed my Barboach was falling off a\n"
	.string "bit, I might have to go back to\l"
	.string "training…\p"
	.string "…\p"
	.string "I don't feel like waiting here until\n"
	.string "they're done. {PLAYER}, let's go look\l"
	.string "for them!\p"
	.string "Flannery said they're at Mt. Chimney,\n"
	.string "right?$"

LavaridgeTown_Text_RuthDefeat::
	.string "Darn, I thought I could win this one.$"
