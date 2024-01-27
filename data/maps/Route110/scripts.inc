.set LOCALID_CHALLENGE_BIKER, 21

Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call Route110_EventScript_SetupAquaScene
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route110_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_DOWSING_MACHINE
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
	removeobject LOCALID_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_BirchExit1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0
	return

Route110_EventScript_BirchExit2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0
	return

Route110_EventScript_BirchExit3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0
	return

Route110_EventScript_BirchExit4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0
	return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "TEAM AQUA's activities…\n"
	.string "We can't talk about them yet.$"

Route110_Text_KickUpARuckus:
	.string "I want to get going to SLATEPORT and\n"
	.string "kick up a ruckus!$"

Route110_Text_MyFirstJobInAqua:
	.string "This is my first job after joining\n"
	.string "TEAM AQUA. It's a little scary.$"

Route110_Text_AquaActionsBringSmiles:
	.string "TEAM AQUA's actions should bring\n"
	.string "smiles to people's faces!$"

Route110_Text_MayLetsBattle:
	.string "MAY: Hi, {PLAYER}{KUN}, long time no see!\p"
	.string "While I was searching for other\n"
	.string "POKéMON, my POKéMON grew stronger.\p"
	.string "So…\n"
	.string "How about a little battle?$"

Route110_Text_MayDefeated:
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route110_Text_MayTakeThis:
	.string "MAY: {PLAYER}{KUN}, you've been busy\n"
	.string "training, too, haven't you?\p"
	.string "I think you deserve a reward!\n"
	.string "This is from me!$"

Route110_Text_MayExplainItemfinder:
	.string "MAY: That's an ITEMFINDER.\p"
	.string "Try it out. If there is an item that's\n"
	.string "not visible, it emits a sound.\p"
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
	.string "I know it's a little silly coming from\n"
	.string "me, but I think you should train a lot\l"
	.string "harder for the next time.$"

Route110_Text_BrendanLetsBattle:
	.string "BRENDAN: Hey, {PLAYER}.\n"
	.string "So this is where you were.\l"
	.string "How's it going?\p"
	.string "Have you been raising your POKéMON?\n"
	.string "I'll check for you.$"

Route110_Text_BrendanDefeated:
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route110_Text_BrendanTakeThis:
	.string "BRENDAN: {PLAYER}, you've trained\n"
	.string "without me noticing…\p"
	.string "Good enough!\n"
	.string "Here, take this.$"

Route110_Text_BrendanExplainItemfinder:
	.string "BRENDAN: That's an ITEMFINDER.\p"
	.string "Use it to root around for items that\n"
	.string "aren't visible.\p"
	.string "If it senses something, it emits\n"
	.string "a sound.\p"
	.string "Anyway, I'm off to look for new\n"
	.string "POKéMON.$"

Route110_Text_RideBikeAtFullSpeed:
	.string "Wouldn't it be great to ride a BIKE\n"
	.string "at full speed on CYCLING ROAD?$"

Route110_Text_HairStreamsBehindMe:
	.string "How do you like the way my raven-\n"
	.string "colored hair streams behind me?\p"
	.string "I grew my hair out just for that.$"

Route110_Text_YouGotBikeFromRydel:
	.string "Oh, hey, you got that BIKE from RYDEL!\p"
	.string "Oh, it's glaringly obvious.\n"
	.string "It says right on your bike…\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
	.string "That name's everywhere.\p"
	.string "You should ride it around all over\n"
	.string "the place--it's good advertising!$"

Route110_Text_TwoRoads:
	.string "The two roads, one above, one below…\p"
	.string "A road each for people and POKéMON.\n"
	.string "Perhaps that is right and fair.$"

Route110_Text_WalkOnTheLowRoad:
	.string "I don't have a BIKE, so I'll take\n"
	.string "a leisurely walk on the low road.$"

Route110_Text_BikeTechniques:
	.string "Learning techniques will make BIKE\n"
	.string "riding even more fun.\p"
	.string "There are some places that you can\n"
	.string "reach only by using a BIKE technique.$"

Route110_Text_WhichShouldIChoose:
	.string "Which should I choose?\p"
	.string "Make a beeline for MAUVILLE on\n"
	.string "CYCLING ROAD, or take the low road\l"
	.string "and look for POKéMON?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "Number of collisions:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Total time:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
	.string "Bravo! Splendid showing!\p"
	.string "Your love of cycling comes from deep\n"
	.string "within your heart.\l"
	.string "You've shaken me to my very soul!$"

Route110_Text_ChallengeReactionGood:
	.string "Your technique is remarkable.\p"
	.string "I suggest you speed up a bit while\n"
	.string "still avoiding collisions.$"

Route110_Text_ChallengeReactionOk:
	.string "I would consider you a work in\n"
	.string "progress.\p"
	.string "Still, I hope you don't forget the\n"
	.string "sheer pleasure of cycling.$"

Route110_Text_ChallengeReactionBad:
	.string "My word… Your cycling skills border\n"
	.string "on terrifying.\p"
	.string "Most certainly, you need much more\n"
	.string "practice riding.$"

Route110_Text_ChallengeReactionWorst:
	.string "…I am aghast…\p"
	.string "You're perhaps not cut out for this\n"
	.string "unfortunate cycling business.\p"
	.string "You ought to give serious thought to\n"
	.string "returning that BIKE to RYDEL.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "This is CYCLING ROAD.\p"
	.string "If you were to ride from MAUVILLE to\n"
	.string "SLATEPORT on a MACH BIKE, you would\l"
	.string "be rated for the number of collisions\l"
	.string "and your total time.$"

Route110_Text_AlwaysAimHigher:
	.string "Regardless of the results, I count on\n"
	.string "seeing more challenges from you.\l"
	.string "Always aim higher!$"

Route110_Text_AcroBikesDoNotQualify:
	.string "On this CYCLING ROAD, those riding\n"
	.string "MACH BIKES are rated for their number\l"
	.string "of collisions and their total times.\p"
	.string "ACRO BIKES do not qualify for rating.\n"
	.string "They are easy to turn, so it's not fair.$"

Route110_Text_SlateportCitySign:
	.string "ROUTE 110\n"
	.string "{DOWN_ARROW} SLATEPORT CITY$"

Route110_Text_CyclingRoadSign:
	.string "SEASIDE CYCLING ROAD$"

Route110_Text_AquaWasHere:
	.string "“TEAM AQUA was here!”\p"
	.string "Someone painted that onto this sign,\n"
	.string "but then someone else painted over it.\p"
	.string "“TEAM MAGMA rules!” is what it\n"
	.string "says now.$"

Route110_Text_Route103Sign:
	.string "ROUTE 110\n"
	.string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_SeasideParkingSign:
	.string "SEASIDE PARKING$"

Route110_Text_MauvilleCitySign:
	.string "ROUTE 110\n"
	.string "{UP_ARROW} MAUVILLE CITY$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "TRAINER TIPS\p"
	.string "The foe can be made helpless by\n"
	.string "paralyzing it or causing it to sleep.\p"
	.string "It is an important technique for\n"
	.string "POKéMON battles.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "TRAINER TIPS\p"
	.string "The items in the BAG can be reorganized\n"
	.string "by pressing SELECT.$"

Route110_Text_TrickHouseSign:
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
	.string "to reach the wondrous TRICK HOUSE.”$"

Route110_Text_BestRecord:
	.string "THE BEST RECORD TO DATE…\p"
	.string "No. of collisions: {STR_VAR_1}\p"
	.string "Elapsed time: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "THE BEST RECORD TO DATE…\p"
	.string "No one seems to have taken the\n"
	.string "challenge. There is no record…$"

Route110_Text_ImagineSeeingYouHere:
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Imagine seeing you here!\p"
	.string "And where might my {RIVAL} be?$"

Route110_Text_HeardYouInstallMatchCall:
	.string "Oh, I see!\n"
	.string "You two are running separately.\l"
	.string "Well, that's fine.\p"
	.string "Oh, yes, I heard that your POKéNAV\n"
	.string "had the MATCH CALL system installed.\p"
	.string "Well, then, I should register you in\n"
	.string "my POKéNAV as well.\p"
	.string "That way, even when we're apart,\n"
	.string "I can rate your POKéDEX anytime.\p"
	.string "… … … … … …$"

Route110_Text_RegisteredBirchInPokenav:
	.string "Registered PROF. BIRCH\n"
	.string "in the POKéNAV.$"

Route110_Text_KeepAnEyeOutForRival:
	.string "PROF. BIRCH: {PLAYER}{KUN}…\p"
	.string "Please keep an eye out for my {RIVAL}.\n"
	.string "… … … … … …\p"
	.string "Well, I had better get going.\n"
	.string "See you again, {PLAYER}{KUN}!$"

Route110_EventScript_SetupAquaScene::
	goto_if_unset FLAG_DONE_AQUA_DOUBLE_BATTLE, Route110_EventScript_SetupAquaScene_1
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_9
	setflag FLAG_TEMP_8
	removeobject 29
	removeobject 33
	removeobject 30
	removeobject 31
	removeobject 32
	setvar VAR_TEMP_8, 0
	return

Route110_EventScript_SetupAquaScene_1:
	clearflag FLAG_TEMP_6
	clearflag FLAG_TEMP_7
	clearflag FLAG_TEMP_9
	clearflag FLAG_TEMP_8
	setvar VAR_TEMP_8, 1
	return


Route110_EventScript_AquaScene_Left::
	setvar VAR_TEMP_2, 0
	setobjectxy 30, 9, 92
	setobjectxy 31, 9, 80
	setobjectxy 32, 8, 80
	goto Route110_EventScript_AquaScene
	return


Route110_EventScript_AquaScene_Middle::
	setvar VAR_TEMP_2, 1
	setobjectxy 30, 8, 92
	setobjectxy 31, 9, 80
	setobjectxy 32, 8, 80
	goto Route110_EventScript_AquaScene
	return


Route110_EventScript_AquaScene_Right::
	setvar VAR_TEMP_2, 2
	setobjectxy 30, 9, 92
	setobjectxy 31, 9, 80
	setobjectxy 32, 10, 80
	goto Route110_EventScript_AquaScene
	return


Route110_EventScript_AquaScene::
	lock
	applymovement 30, Route110_Movement_RuthEnterScreen
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Route110_EventScript_AquaScene_Text_0
	closemessage
	applymovement 30, Route110_Movement_RuthWalkUpToPlayer
	waitmovement 0
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AquaScene_3
	case 1, Route110_EventScript_AquaScene_4
	case 2, Route110_EventScript_AquaScene_4
Route110_EventScript_AquaScene_1:
	msgbox Route110_EventScript_AquaScene_Text_1
	closemessage
	applymovement 31, Route110_Movement_Grunt1Encounter
	waitmovement 0
	delay 8
	clearflag FLAG_TEMP_6
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AquaScene_7
	case 1, Route110_EventScript_AquaScene_7
	case 2, Route110_EventScript_AquaScene_8
Route110_EventScript_AquaScene_5:
	showobjectat 33, MAP_ROUTE110
	waitmovement 31
	delay 8
	turnobject 31, DIR_NORTH
	delay 16
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject 30, DIR_NORTH
	msgbox Route110_EventScript_AquaScene_Text_2
	closemessage
	applymovement 32, Route110_Movement_Grunt2Encounter_1
	waitmovement 32
	msgbox Route110_EventScript_AquaScene_Text_3
	closemessage
	applymovement 32, Route110_Movement_Grunt2Encounter_2
	waitmovement 0
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AquaScene_11
	case 1, Route110_EventScript_AquaScene_11
	case 2, Route110_EventScript_AquaScene_12
Route110_EventScript_AquaScene_9:
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AquaScene_15
	case 1, Route110_EventScript_AquaScene_16
	case 2, Route110_EventScript_AquaScene_16
Route110_EventScript_AquaScene_13:
	msgbox Route110_EventScript_AquaScene_Text_4
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject 30, DIR_NORTH
	closemessage
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AquaScene_19
	case 1, Route110_EventScript_AquaScene_19
	case 2, Route110_EventScript_AquaScene_20
Route110_EventScript_AquaScene_17:
	waitmovement 0
	hideobjectat 33, MAP_ROUTE110
	applymovement 31, Common_Movement_WalkDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route110_EventScript_AquaScene_22
	msgbox Route110_EventScript_AquaScene_Text_6
Route110_EventScript_AquaScene_21:
	applymovement 32, Common_Movement_WalkDown
	waitmovement 0
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AquaScene_27
	case 1, Route110_EventScript_AquaScene_28
	case 2, Route110_EventScript_AquaScene_28
Route110_EventScript_AquaScene_25:
	msgbox Route110_EventScript_AquaScene_Text_7
	closemessage
	goto Route110_EventScript_PrepareForAquaDoubleBattle
	return

Route110_EventScript_AquaScene_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	goto Route110_EventScript_AquaScene_1

Route110_EventScript_AquaScene_4:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto Route110_EventScript_AquaScene_1

Route110_EventScript_AquaScene_7:
	applymovement 31, Common_Movement_WalkInPlaceRight
	setobjectxy 33, 10, 84
	goto Route110_EventScript_AquaScene_5

Route110_EventScript_AquaScene_8:
	applymovement 31, Common_Movement_WalkInPlaceLeft
	setobjectxy 33, 8, 84
	goto Route110_EventScript_AquaScene_5

Route110_EventScript_AquaScene_11:
	turnobject 32, DIR_EAST
	turnobject 31, DIR_WEST
	delay 16
	turnobject 32, DIR_NORTH
	delay 16
	applymovement 32, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route110_Text_HowsHeSoFast
	applymovement 31, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route110_Text_WeWouldveLostHimAlready
	goto Route110_EventScript_AquaScene_9

Route110_EventScript_AquaScene_12:
	turnobject 32, DIR_WEST
	turnobject 31, DIR_EAST
	delay 16
	turnobject 32, DIR_NORTH
	delay 16
	applymovement 32, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route110_Text_HowsHeSoFast
	applymovement 31, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route110_Text_WeWouldveLostHimAlready
	goto Route110_EventScript_AquaScene_9

Route110_EventScript_AquaScene_15:
	applymovement 30, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route110_EventScript_AquaScene_13

Route110_EventScript_AquaScene_16:
	applymovement 30, Common_Movement_WalkInPlaceRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route110_EventScript_AquaScene_13

Route110_EventScript_AquaScene_19:
	applymovement 31, Common_Movement_WalkInPlaceRight
	goto Route110_EventScript_AquaScene_17

Route110_EventScript_AquaScene_20:
	applymovement 31, Common_Movement_WalkInPlaceLeft
	goto Route110_EventScript_AquaScene_17

Route110_EventScript_AquaScene_22:
	msgbox Route110_EventScript_AquaScene_Text_5
	goto Route110_EventScript_AquaScene_21

Route110_EventScript_AquaScene_27:
	applymovement 30, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route110_EventScript_AquaScene_25

Route110_EventScript_AquaScene_28:
	applymovement 30, Common_Movement_WalkInPlaceRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route110_EventScript_AquaScene_25


Route110_EventScript_PrepareForAquaDoubleBattle::
	special SavePlayerParty
	getpartysize
	compare VAR_RESULT, 3
	goto_if_le Route110_EventScript_PrepareForAquaDoubleBattle_1
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_ne Route110_EventScript_PrepareForAquaDoubleBattle_5
Route110_EventScript_PrepareForAquaDoubleBattle_4:
	special LoadPlayerParty
	msgbox Route110_EventScript_PrepareForAquaDoubleBattle_Text_0
	closemessage
	goto Route110_EventScript_PrepareForAquaDoubleBattle
	return

Route110_EventScript_PrepareForAquaDoubleBattle_1:
	goto Route110_EventScript_StartAquaDoubleBattle
	return

Route110_EventScript_PrepareForAquaDoubleBattle_5:
	special ReducePlayerPartyToSelectedMons
	goto Route110_EventScript_StartAquaDoubleBattle
	goto Route110_EventScript_PrepareForAquaDoubleBattle_4


Route110_EventScript_StartAquaDoubleBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	turnobject 30, DIR_NORTH
	delay 16
	applymovement 31, Common_Movement_WalkInPlaceDown
	msgbox Route110_EventScript_StartAquaDoubleBattle_Text_0, MSGBOX_AUTOCLOSE
	waitmovement 32
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_0x8004, SPECIAL_BATTLE_RUTH
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	frontier_saveparty
	special LoadPlayerParty
	lock
	switch VAR_RESULT
	case 1, Route110_EventScript_StartAquaDoubleBattle_3
	setflag FLAG_DONE_AQUA_DOUBLE_BATTLE
	applymovement 30, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route110_EventScript_StartAquaDoubleBattle_Text_2
Route110_EventScript_StartAquaDoubleBattle_1:
	special HealPlayerParty
	goto Route110_EventScript_AfterAquaDoubleBattle
	return

Route110_EventScript_StartAquaDoubleBattle_3:
	setflag FLAG_DONE_AQUA_DOUBLE_BATTLE
	applymovement 30, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route110_EventScript_StartAquaDoubleBattle_Text_1
	goto Route110_EventScript_StartAquaDoubleBattle_1


Route110_EventScript_AfterAquaDoubleBattle::
	applymovement 29, Route110_Movement_Birch
	waitmovement 0
	turnobject 31, DIR_NORTH
	turnobject 32, DIR_NORTH
	applymovement 31, Common_Movement_ExclamationMarkAndDelay
	playse SE_PIN
	applymovement 32, Common_Movement_WalkInPlaceUp
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_0
	waitse
	closemessage
	waitmovement 31
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AfterAquaDoubleBattle_3
	case 1, Route110_EventScript_AfterAquaDoubleBattle_3
	case 2, Route110_EventScript_AfterAquaDoubleBattle_4
Route110_EventScript_AfterAquaDoubleBattle_1:
	setflag FLAG_TEMP_8
	removeobject 31
	removeobject 32
	applymovement 29, Route110_Movement_BirchWalkToBox
	waitmovement 0
	delay 10
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AfterAquaDoubleBattle_7
	case 1, Route110_EventScript_AfterAquaDoubleBattle_7
	case 2, Route110_EventScript_AfterAquaDoubleBattle_8
Route110_EventScript_AfterAquaDoubleBattle_5:
	waitmovement 0
	hideobjectat 33, MAP_ROUTE110
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_1
	closemessage
	applymovement 30, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_2
	closemessage
	applymovement 29, Common_Movement_WalkInPlaceDown
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_3
	applymovement 29, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_4
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_5
	closemessage
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AfterAquaDoubleBattle_11
	case 1, Route110_EventScript_AfterAquaDoubleBattle_12
	case 2, Route110_EventScript_AfterAquaDoubleBattle_12
Route110_EventScript_AfterAquaDoubleBattle_9:
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_6
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	turnobject 30, DIR_NORTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_7
	closemessage
	applymovement 29, Common_Movement_WalkInPlaceRight
	waitmovement 0
	setobjectxyperm 33, 10, 85
	clearflag FLAG_TEMP_6
	showobjectat 33, MAP_ROUTE110
	delay 48
	applymovement 29, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 16
	setflag FLAG_TEMP_6
	hideobjectat 33, MAP_ROUTE110
	removeobject 33
	delay 16
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_8
	closemessage
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AfterAquaDoubleBattle_15
	case 1, Route110_EventScript_AfterAquaDoubleBattle_16
	case 2, Route110_EventScript_AfterAquaDoubleBattle_17
Route110_EventScript_AfterAquaDoubleBattle_13:
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_9
	closemessage
	applymovement 30, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_10
	closemessage
	applymovement 29, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_11
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_12
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_13
	closemessage
	applymovement 29, Route110_Movement_BirchLeave
	waitmovement 0
	setflag FLAG_TEMP_7
	removeobject 29
	delay 30
	switch VAR_TEMP_2
	case 0, Route110_EventScript_AfterAquaDoubleBattle_20
	case 1, Route110_EventScript_AfterAquaDoubleBattle_21
	case 2, Route110_EventScript_AfterAquaDoubleBattle_21
Route110_EventScript_AfterAquaDoubleBattle_18:
	msgbox Route110_EventScript_AfterAquaDoubleBattle_Text_14
	closemessage
	applymovement 30, Route110_Movement_RuthLeave
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	waitmovement 30
	setflag FLAG_TEMP_9
	removeobject 30
	setvar VAR_TEMP_8, 0
	release
	end

Route110_EventScript_AfterAquaDoubleBattle_3:
	applymovement 31, Route110_Movement_GruntPanicking_1
	delay 10
	turnobject 32, DIR_EAST
	waitmovement 31
	msgbox Route110_Text_FineHavePackageBack
	closemessage
	applymovement 31, Common_Movement_WalkInPlaceRight
	clearflag FLAG_TEMP_6
	setobjectxy 33, 10, 85
	showobjectat 33, MAP_ROUTE110
	waitmovement 0
	applymovement 31, Route110_Movement_GruntLeave_Left
	applymovement 32, Route110_Movement_GruntLeave2
	waitmovement 0
	goto Route110_EventScript_AfterAquaDoubleBattle_1

Route110_EventScript_AfterAquaDoubleBattle_4:
	applymovement 31, Route110_Movement_GruntPanicking_2
	delay 10
	turnobject 32, DIR_WEST
	waitmovement 31
	msgbox Route110_Text_FineHavePackageBack
	closemessage
	applymovement 31, Common_Movement_WalkInPlaceLeft
	clearflag FLAG_TEMP_6
	setobjectxy 33, 10, 85
	showobjectat 33, MAP_ROUTE110
	waitmovement 0
	applymovement 31, Route110_Movement_GruntLeave_Right
	applymovement 32, Route110_Movement_GruntLeave2
	waitmovement 0
	goto Route110_EventScript_AfterAquaDoubleBattle_1

Route110_EventScript_AfterAquaDoubleBattle_7:
	applymovement 29, Common_Movement_WalkInPlaceRight
	goto Route110_EventScript_AfterAquaDoubleBattle_5

Route110_EventScript_AfterAquaDoubleBattle_8:
	applymovement 29, Common_Movement_WalkInPlaceLeft
	goto Route110_EventScript_AfterAquaDoubleBattle_5

Route110_EventScript_AfterAquaDoubleBattle_11:
	applymovement 30, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route110_EventScript_AfterAquaDoubleBattle_9

Route110_EventScript_AfterAquaDoubleBattle_12:
	applymovement 30, Common_Movement_WalkInPlaceRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route110_EventScript_AfterAquaDoubleBattle_9

Route110_EventScript_AfterAquaDoubleBattle_15:
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 16
	applymovement 29, Common_Movement_WalkLeft
	waitmovement 0
	turnobject 29, DIR_SOUTH
	delay 16
	msgbox Route110_Text_HereYouGetOneToo
	closemessage
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	closemessage
	goto Route110_EventScript_AfterAquaDoubleBattle_13

Route110_EventScript_AfterAquaDoubleBattle_16:
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	closemessage
	applymovement 29, Common_Movement_WalkLeft
	waitmovement 0
	turnobject 29, DIR_SOUTH
	delay 16
	msgbox Route110_Text_HereYouGetOneToo
	closemessage
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	goto Route110_EventScript_AfterAquaDoubleBattle_13

Route110_EventScript_AfterAquaDoubleBattle_17:
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 16
	applymovement 29, Common_Movement_WalkRight
	waitmovement 0
	turnobject 29, DIR_SOUTH
	delay 16
	msgbox Route110_Text_HereYouGetOneToo
	closemessage
	applymovement 29, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	closemessage
	goto Route110_EventScript_AfterAquaDoubleBattle_13

Route110_EventScript_AfterAquaDoubleBattle_20:
	applymovement 30, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route110_EventScript_AfterAquaDoubleBattle_18

Route110_EventScript_AfterAquaDoubleBattle_21:
	applymovement 30, Common_Movement_WalkInPlaceRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route110_EventScript_AfterAquaDoubleBattle_18


Route110_Movement_RuthEnterScreen:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_RuthWalkUpToPlayer:
	walk_fast_up
	walk_fast_up
	face_player
	step_end

Route110_Movement_Grunt1Encounter:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route110_Movement_Grunt2Encounter_1:
	walk_down
	walk_down
	step_end

Route110_Movement_Grunt2Encounter_2:
	walk_fast_down
	walk_down
	step_end

Route110_Movement_Birch:
	walk_fast_down
	walk_fast_down
	step_end

Route110_Movement_GruntPanicking_1:
	walk_in_place_down
	walk_in_place_up
	walk_in_place_right
	walk_in_place_up
	step_end

Route110_Movement_GruntPanicking_2:
	walk_in_place_down
	walk_in_place_up
	walk_in_place_left
	walk_in_place_up
	step_end

Route110_Movement_GruntLeave_Left:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_GruntLeave_Right:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_GruntLeave2:
	walk_up
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_BirchWalkToBox:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_RuthLeave:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_Grunt1Trainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_GRUNT_ROUTE110_1, 0, Route110_EventScript_Grunt1Trainer_Text_0, Route110_EventScript_Grunt1Trainer_Text_0
	end


Route110_EventScript_Grunt2Trainer::
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_GRUNT_ROUTE110_2, 0, Route110_EventScript_Grunt2Trainer_Text_0, Route110_EventScript_Grunt2Trainer_Text_0
	return


Route110_EventScript_AquaScene_Text_0:
	.string "{PLAYER}!$"

Route110_EventScript_AquaScene_Text_1:
	.string "Are you already on your way to Mauville?\p"
	.string "I tried my hand in the Slateport Battle\n"
	.string "Tent, but it's so hard to battle with\l"
	.string "Pokémon I am not familiar with...$"

Route110_EventScript_AquaScene_Text_2:
	.string "???: Come on, hurry up you slowpoke!\pThe old man's catching up!$"

Route110_EventScript_AquaScene_Text_3:
	.string "???: Huff, huff...\p"
	.string "Wait for me!$"

Route110_EventScript_AquaScene_Text_4:
	.string "Ruth: They seem suspicious.\p"
	.string "I bet they stole that package from\n"
	.string "somebody!$"

Route110_EventScript_AquaScene_Text_5:
	.string "???: Out of the way!$"

Route110_EventScript_AquaScene_Text_6:
	.string "???: Out of the way, girls!$"

Route110_EventScript_AquaScene_Text_7:
	.string "Ruth: {PLAYER}! Let's stop these two\n"
	.string "together!$"

Route110_EventScript_PrepareForAquaDoubleBattle_Text_0:
	.string "Ruth: Come on, {PLAYER}! We can do\n"
	.string "this!$"

Route110_EventScript_StartAquaDoubleBattle_Text_0:
	.string "???: Bring it on!$"

Route110_EventScript_StartAquaDoubleBattle_Text_1:
	.string "Ruth: Ha, take that!$"

Route110_EventScript_StartAquaDoubleBattle_Text_2:
	.string "Ruth: Ugh, they're strong...$"

Route110_EventScript_AfterAquaDoubleBattle_Text_0:
	.string "Birch: There you are!\pGive me back my package, you thieves!$"

Route110_EventScript_AfterAquaDoubleBattle_Text_1:
	.string "Birch: Thank you, I don't know if I\n"
	.string "would've been able to catch them if you\l"
	.string "didn't hold them back.\p"
	.string "...\p"
	.string "That Pokémon you used...\p"
	.string "By any chance, do you know my son\n"
	.string "Brendan?$"

Route110_EventScript_AfterAquaDoubleBattle_Text_2:
	.string "Ruth: Yes! He's staying in our hometown\n"
	.string "at the moment!\p"
	.string "But... your son? That means... You're THE\n"
	.string "Professor Birch?!$"

Route110_EventScript_AfterAquaDoubleBattle_Text_3:
	.string "Birch: Haha, yes. That's me.$"

Route110_EventScript_AfterAquaDoubleBattle_Text_4:
	.string "I was on my way to collect the new\n"
	.string "PokéDex model, when those goons\l"
	.string "snatched the package out of my hands.$"

Route110_EventScript_AfterAquaDoubleBattle_Text_5:
	.string "My son gave one to the two of you too,\n"
	.string "right?$"

Route110_EventScript_AfterAquaDoubleBattle_Text_6:
	.string "Ruth: Ehrm... I didn't get one, did you,\n"
	.string "{PLAYER}?$"

Route110_EventScript_AfterAquaDoubleBattle_Text_7:
	.string "Birch: Hmm, he must've been really busy\n"
	.string "with his work to forget that.$"

Route110_EventScript_AfterAquaDoubleBattle_Text_8:
	.string "Here, take these.$"

Route110_EventScript_AfterAquaDoubleBattle_Text_9:
	.string "These devices collect information\n"
	.string "about the Pokémon you catch.\p"
	.string "It's a very useful tool for every\n"
	.string "Pokémon trainer!$"

Route110_EventScript_AfterAquaDoubleBattle_Text_10:
	.string "Ruth: Thank you, Professor! We'll make\n"
	.string "sure to make good use of it!\p"
	.string "What did those guys want them for,\n"
	.string "anyway?$"

Route110_EventScript_AfterAquaDoubleBattle_Text_11:
	.string "Birch: I don't know.\p"
	.string "It doesn't even hold the information\n"
	.string "they're after.$"

Route110_EventScript_AfterAquaDoubleBattle_Text_12:
	.string "Oh, and this is my PokéNav contact, you\n"
	.string "can call me if you want me to take a\l"
	.string "look at your PokéDex progress.$"

Route110_EventScript_AfterAquaDoubleBattle_Text_13:
	.string "Again, thanks for helping me out.\p"
	.string "You should visit me at my lab in\n"
	.string "Littleroot Town sometime.$"

Route110_EventScript_AfterAquaDoubleBattle_Text_14:
	.string "So, {PLAYER}! Mauville is waiting for\n"
	.string "us!\p"
	.string "Let's see who gets the badge first!$"

Route110_EventScript_Grunt1Trainer_Text_0:
	.string "EEEE$"

Route110_EventScript_Grunt2Trainer_Text_0:
	.string "AAAA$"

Route110_Text_HowsHeSoFast::
	.string "He's almost here! How's he so fast?!$"

Route110_Text_WeWouldveLostHimAlready::
	.string "???: If you weren't this slow, we would\n"
	.string "have lost him already!$"

Route110_Text_FineHavePackageBack::
	.string "???: ...\p"
	.string "Fine! Have your stupid package back!$"

Route110_Text_HereYouGetOneToo::
	.string "Here, you get one too!$"
