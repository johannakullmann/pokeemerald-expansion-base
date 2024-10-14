LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_MAY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! That was a scorching-hot battle!$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "I'm trying to relieve my stress.\n"
	.string "Don't come along and stress me out!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "I hope FLANNERY flames you good!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Whew…\p"
	.string "If you spend too much time buried in\n"
	.string "hot sand, it tuckers you out…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "You must be getting tired by now.\n"
	.string "You'd like to rest in the hot sand,\l"
	.string "wouldn't you?\p"
	.string "But you should know that maintaining\n"
	.string "your willpower is an important ability\l"
	.string "for all TRAINERS.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Play with fire, and be burned…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Your skill is real…\n"
	.string "But our LEADER FLANNERY is strong.\p"
	.string "If you don't watch yourself, you'll be\n"
	.string "burned seriously.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "See how the flames blaze wildly?\n"
	.string "They flare in anticipation of my win!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Something didn't go right.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Well, so what? I say so what?\n"
	.string "I can walk on hot coals barefoot!\p"
	.string "…Don't even think about trying it!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "I guess I was trying too hard…\p"
	.string "I… I've only recently become\n"
	.string "a GYM LEADER.\p"
	.string "I tried too hard to be someone\n"
	.string "I'm not.\p"
	.string "I have to do things my natural way. If\n"
	.string "I don't, my POKéMON will be confused.\p"
	.string "Thanks for teaching me that.\n"
	.string "For that, you deserve this.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} received the HEAT BADGE\n"
	.string "from FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "If you have a HEAT BADGE, all POKéMON\n"
	.string "up to Level 50, even those you get in\l"
	.string "trades from other people, will obey\l"
	.string "you completely.\p"
	.string "And, it lets POKéMON use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "This is a token of my appreciation.\n"
	.string "Don't be shy about taking it!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "That TM50 contains OVERHEAT.\p"
	.string "That move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "But it also sharply cuts the SP. ATK\n"
	.string "of the POKéMON using it. It might not\l"
	.string "be suitable for longer battles.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Registered GYM LEADER FLANNERY\n"
	.string "in the POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Your power reminds me of someone…\p"
	.string "Oh! I know! You battle like NORMAN,\n"
	.string "the GYM LEADER of PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "LAVARIDGE TOWN POKéMON GYM$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "LAVARIDGE TOWN POKéMON GYM\p"
	.string "FLANNERY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Whew!\n"
	.string "On the verge of eruption!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: I lost the match,\n"
	.string "but I'm completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Losing a battle isn't going\n"
	.string "to deflate me.\p"
	.string "I love POKéMON.\n"
	.string "I love to battle.\l"
	.string "And… I love this GYM!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!\p"
	.string "Oh, wait. Do you only have one POKéMON\n"
	.string "that can battle?\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two POKéMON.$"

LavaridgeTown_Gym_1F_OnTransition::
	setflag FLAG_SYS_USE_STRENGTH
	return


LavaridgeTown_Gym_EventScript_May::
	lock
	faceplayer
	checktrainerflag TRAINER_MAY_1
	goto_if 0, LavaridgeTown_Gym_EventScript_May_2
LavaridgeTown_Gym_EventScript_May_1:
	msgbox LavaridgeTown_Gym_1F_Text_MayPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

LavaridgeTown_Gym_EventScript_May_2:
	speakername CommonName_May
	msgbox LavaridgeTown_Gym_1F_Text_MayIntro
	special SavePlayerParty
	getpartysize
	compare VAR_RESULT, 3
	goto_if_le LavaridgeTown_Gym_EventScript_May_4
	speakername CommonName_May
	msgbox LavaridgeTown_Gym_EventScript_May_Text_0
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_ne LavaridgeTown_Gym_EventScript_May_8
LavaridgeTown_Gym_EventScript_May_7:
	special LoadPlayerParty
	release
	end

LavaridgeTown_Gym_EventScript_May_4:
	special SetHalfPartyForBattle
	goto LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty
	goto LavaridgeTown_Gym_EventScript_May_1

LavaridgeTown_Gym_EventScript_May_8:
	goto LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty
	goto LavaridgeTown_Gym_EventScript_May_7


LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty::
	lock
	special ReducePlayerPartyToSelectedMons
	getpartysize
	compare VAR_RESULT, 3
	goto_if_lt LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty_1
	goto LavaridgeTown_Gym_EventScript_MayGymBattle
	return

LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty_1:
	speakername CommonName_May
	msgbox LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty_4
	special LoadPlayerParty
	release
	end

LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty_4:
	goto LavaridgeTown_Gym_EventScript_MayGymBattle
	return


LavaridgeTown_Gym_EventScript_MayGymBattle::
	setflag FLAG_LOAD_SAVED_PARTY_AFTER_NEXT_BATTLE
	trainerbattle_single TRAINER_MAY_1, LavaridgeTown_Gym_Text_MayBeforeBattle, LavaridgeTown_Gym_Text_MayDefeat, LavaridgeTown_Gym_EventScript_MayAfterBattle, NO_MUSIC
	return


LavaridgeTown_Gym_EventScript_MayAfterBattle::
	lock
	special LoadPlayerParty
	clearflag FLAG_LOAD_SAVED_PARTY_AFTER_NEXT_BATTLE
	speakername NULL
	message LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_0
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	setvar VAR_JAGGED_PASS_STATE, 4
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	speakername CommonName_May
	msgbox LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_1, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_TM_FIRE_PUNCH
	speakername CommonName_May
	msgbox LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_2
	closemessage
	delay 30
	speakername CommonName_May
	msgbox LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_3
	closemessage
	speakername NULL
	giveitem ITEM_MAYS_PACKAGE
	speakername CommonName_May
	msgbox LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_4
	closemessage
	delay 30
	speakername NULL
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_5, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	release
	end


LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end


LavaridgeTown_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_COLE, LavaridgeTown_Gym_EventScript_Cole_Text_0, LavaridgeTown_Gym_EventScript_Cole_Text_1
	msgbox LavaridgeTown_Gym_EventScript_Cole_Text_2, MSGBOX_AUTOCLOSE
	end


LavaridgeTown_Gym_EventScript_Danielle::
	trainerbattle_single TRAINER_DANIELLE, LavaridgeTown_Gym_EventScript_Danielle_Text_0, LavaridgeTown_Gym_EventScript_Danielle_Text_1
	msgbox LavaridgeTown_Gym_EventScript_Danielle_Text_2, MSGBOX_AUTOCLOSE
	end


LavaridgeTown_Gym_EventScript_Gerald::
	trainerbattle_single TRAINER_GERALD, LavaridgeTown_Gym_EventScript_Gerald_Text_0, LavaridgeTown_Gym_EventScript_Gerald_Text_1
	msgbox LavaridgeTown_Gym_EventScript_Gerald_Text_2, MSGBOX_AUTOCLOSE
	end


LavaridgeTown_Gym_EventScript_Jace::
	trainerbattle_single TRAINER_JACE, LavaridgeTown_Gym_EventScript_Jace_Text_0, LavaridgeTown_Gym_EventScript_Jace_Text_1
	msgbox LavaridgeTown_Gym_EventScript_Jace_Text_2, MSGBOX_AUTOCLOSE
	end


LavaridgeTown_Gym_EventScript_Eli::
	trainerbattle_single TRAINER_ELI, LavaridgeTown_Gym_EventScript_Eli_Text_0, LavaridgeTown_Gym_EventScript_Eli_Text_1
	msgbox LavaridgeTown_Gym_EventScript_Eli_Text_2, MSGBOX_AUTOCLOSE
	end


LavaridgeTown_Gym_EventScript_Axle::
	trainerbattle_single TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end


LavaridgeTown_Gym_EventScript_Keegan::
	trainerbattle_single TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end


LavaridgeTown_Gym_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end


LavaridgeTown_Gym_EventScript_May_Text_0:
	.string "Alright, which Pokémon will you be\n"
	.string "fighting with?$"

LavaridgeTown_Gym_EventScript_MayGymBattle_CheckConfirmSmallParty_Text_0:
	.string "Are you really sure you want to battle\n"
	.string "with less than three Pokémon?\p"
	.string "You won't get extra points for that,\n"
	.string "you know.$"

LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_0:
	.string "{PLAYER} received the Heat Badge\nfrom May.$"

LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_1:
	.string "I think you earned this TM too!$"

LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_2:
	.string "TM51 contains Fire Punch.\p"
	.string "It's a strong Fire-type attack that\n"
	.string "can also burn the target.\p"
	.string "A lot of non-Fire type Pokémon can\n"
	.string "learn it, so you can surprise your\l"
	.string "opponent by hitting them with an\l"
	.string "unexpected super-effective Fire move!$"

LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_3:
	.string "… Say, {PLAYER}, could I ask a favour?\p"
	.string "That encounter with Team Magma at\n"
	.string "Jagged Pass still bothers me.\p"
	.string "Could you deliver something to the\n"
	.string "Weather Institute on Route 119 for\l"
	.string "me?\p"
	.string "It'll be right on your way when you go to\n"
	.string "Fortree City to challenge Winona's gym.$"

LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_4:
	.string "The safest way to reach Fortree City at\n"
	.string "the moment…\p"
	.string "That should be the tunnel connecting\n"
	.string "Route 119 and the northern part of\l"
	.string "Route 111.\p"
	.string "You can get there by going past Jagged\n"
	.string "Pass, then take a turn east as soon as\l"
	.string "you exit the forest.$"

LavaridgeTown_Gym_EventScript_MayAfterBattle_Text_5:
	.string "Registered Gym Leader May\nin the PokéNav.$"

LavaridgeTown_Gym_EventScript_Cole_Text_0:
	.string "These boulder puzzles are really neat,\n"
	.string "don't you think?$"

LavaridgeTown_Gym_EventScript_Cole_Text_1:
	.string "Hmmm… If I rolled that boulder over\n"
	.string "there…$"

LavaridgeTown_Gym_EventScript_Cole_Text_2:
	.string "Those long boulders can only roll in one\n"
	.string "direction.\p"
	.string "It's tricky to get the small boulder\n"
	.string "past them.$"

LavaridgeTown_Gym_EventScript_Danielle_Text_0:
	.string "The hot water is so soothing for sore\n"
	.string "muscles…$"

LavaridgeTown_Gym_EventScript_Danielle_Text_1:
	.string "Ow… I think my shoulder still hurts a\n"
	.string "bit…$"

LavaridgeTown_Gym_EventScript_Danielle_Text_2:
	.string "The hot spring water relaxes muscles\n"
	.string "and promotes circulation.\p"
	.string "I can train a lot more thanks to that!$"

LavaridgeTown_Gym_EventScript_Gerald_Text_0:
	.string "Can your Pokémon withstand the\n"
	.string "scalding heat?$"

LavaridgeTown_Gym_EventScript_Gerald_Text_1:
	.string "It didn't burn hot enough…$"

LavaridgeTown_Gym_EventScript_Gerald_Text_2:
	.string "Your Pokémon seem to be entirely\n"
	.string "fireproof.$"

LavaridgeTown_Gym_EventScript_Jace_Text_0:
	.string "Auntie May always lets me swim in here.\p"
	.string "Come on, play with me!$"

LavaridgeTown_Gym_EventScript_Jace_Text_1:
	.string "That was fun!$"

LavaridgeTown_Gym_EventScript_Jace_Text_2:
	.string "Look, I've got this entire pool all for\n"
	.string "myself!\p"
	.string "But you want to, I can share with you!$"

LavaridgeTown_Gym_EventScript_Eli_Text_0:
	.string "Nothing beats hot springs when it\n"
	.string "comes to natural skin cleanses.$"

LavaridgeTown_Gym_EventScript_Eli_Text_1:
	.string "The heat must've made me feel\n"
	.string "light-headed…$"

LavaridgeTown_Gym_EventScript_Eli_Text_2:
	.string "The minerals in the spring water are\n"
	.string "good for your skin.$"

LavaridgeTown_Gym_1F_Text_MayIntro::
	.string "Welcome, {PLAYER}! You made it!\p"
	.string "Since we meet in this official manner,\n"
	.string "let's do the introductions properly!\p"
	.string "My name's May, and it's always been my\n"
	.string "dream to become a gym leader like my\l"
	.string "father.\p"
	.string "One thing led to another, and I was able\n"
	.string "to take over this gym for Flannery.\p"
	.string "{PLAYER}, you somehow remind me of\n"
	.string "myself when I started my own\l"
	.string "adventure a few years ago.\p"
	.string "That doesn't mean I'll be going easy on\n"
	.string "you, though!$"

LavaridgeTown_Gym_Text_MayBeforeBattle::
	.string "…$"

LavaridgeTown_Gym_Text_MayDefeat::
	.string "…$"

LavaridgeTown_Gym_1F_Text_MayPostBattle::
	.string "…$"

LavaridgeTown_Gym_1F_Text_GymGuideAdvice::
	.string "Hey, how's it going, {PLAYER}?\p"
	.string "Our new Gym Leader May uses Fire-type Pokémon, just like Flannery used to.\p"
	.string "You'll need Pokémon that can withstand the scorching heat!\p"
	.string "Ground-, Rock- and Water-type attacks can extinguish her flames…\p"
	.string "But be careful, as a former champion, she packs moves that can counter those weaknesses!$"
