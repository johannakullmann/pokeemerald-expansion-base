SlateportCity_ShinyClub_MapScripts::
	.byte 0


SlateportCity_ShinyClub_EventScript_BugCatcher::
	msgbox SlateportCity_ShinyClub_EventScript_BugCatcher_Text_0, MSGBOX_NPC
	end


SlateportCity_ShinyClub_EventScript_Hiker::
	msgbox SlateportCity_ShinyClub_EventScript_Hiker_Text_0, MSGBOX_NPC
	end


SlateportCity_ShinyClub_EventScript_ShinyBook::
	msgbox SlateportCity_ShinyClub_EventScript_ShinyBook_Text_0, MSGBOX_SIGN
	end


SlateportCity_ShinyClub_EventScript_ShinyClubChairman::
	checkitem ITEM_CLUB_MEMBER_CARD
	compare VAR_RESULT, TRUE
	goto_if_eq SlateportCity_ShinyClub_EventScript_ShinyClubChairman_2
	special IsShinyMonInParty
	compare VAR_RESULT, PARTY_SIZE
	goto_if_lt SlateportCity_ShinyClub_EventScript_ShinyClubChairman_5
	msgbox SlateportCity_ShinyClub_EventScript_ShinyClubChairman_Text_3, MSGBOX_NPC
SlateportCity_ShinyClub_EventScript_ShinyClubChairman_1:
	end

SlateportCity_ShinyClub_EventScript_ShinyClubChairman_2:
	msgbox SlateportCity_ShinyClub_EventScript_ShinyClubChairman_Text_0
	goto SlateportCity_ShinyClub_EventScript_ShinyClubChairman_1

SlateportCity_ShinyClub_EventScript_ShinyClubChairman_5:
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox SlateportCity_ShinyClub_EventScript_ShinyClubChairman_Text_1, MSGBOX_NPC
	giveitem ITEM_CLUB_MEMBER_CARD
	msgbox SlateportCity_ShinyClub_EventScript_ShinyClubChairman_Text_2, MSGBOX_NPC
	goto SlateportCity_ShinyClub_EventScript_ShinyClubChairman_1


SlateportCity_ShinyClub_EventScript_Cooltrainer::
	lock
	faceplayer
	checktrainerflag TRAINER_SHINY_COOLTRAINER
	goto_if 1, SlateportCity_ShinyClub_EventScript_Cooltrainer_2
	msgbox SlateportCity_ShinyClub_EventScript_Cooltrainer_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SlateportCity_ShinyClub_EventScript_Cooltrainer_5
SlateportCity_ShinyClub_EventScript_Cooltrainer_1:
	release
	end

SlateportCity_ShinyClub_EventScript_Cooltrainer_2:
	msgbox SlateportCity_ShinyClub_EventScript_Cooltrainer_Text_0
	goto SlateportCity_ShinyClub_EventScript_Cooltrainer_1

SlateportCity_ShinyClub_EventScript_Cooltrainer_5:
	trainerbattle_no_intro TRAINER_SHINY_COOLTRAINER, SlateportCity_ShinyClub_EventScript_Cooltrainer_Text_2
	goto SlateportCity_ShinyClub_EventScript_Cooltrainer_1


Route135_ShinyHouse_EventScript_ShinyLureSeller::
	checkitem ITEM_CLUB_MEMBER_CARD
	compare VAR_RESULT, TRUE
	goto_if_eq Route135_ShinyHouse_EventScript_ShinyLureSeller_2
	msgbox Route135_ShinyHouse_EventScript_ShinyLureSeller_Text_2, MSGBOX_NPC
Route135_ShinyHouse_EventScript_ShinyLureSeller_1:
	release
	end

Route135_ShinyHouse_EventScript_ShinyLureSeller_2:
	msgbox Route135_ShinyHouse_EventScript_ShinyLureSeller_Text_0, MSGBOX_NPC
	waitmessage
	pokemart ShinyLureMart
	lock
	faceplayer
	msgbox Route135_ShinyHouse_EventScript_ShinyLureSeller_Text_1
	goto Route135_ShinyHouse_EventScript_ShinyLureSeller_1


SlateportCity_ShinyClub_EventScript_Geodude::
	playmoncry SPECIES_GEODUDE, CRY_MODE_NORMAL
	msgbox SlateportCity_ShinyClub_EventScript_Geodude_Text_0, MSGBOX_NPC
	end


SlateportCity_ShinyClub_EventScript_Wurmple::
	playmoncry SPECIES_WURMPLE, CRY_MODE_NORMAL
	msgbox SlateportCity_ShinyClub_EventScript_Wurmple_Text_0, MSGBOX_NPC
	end


	.align 2
ShinyLureMart:
	.2byte ITEM_SHINY_LURE
	.2byte ITEM_SUPER_SHINY_LURE
	.2byte ITEM_MAX_SHINY_LURE
	.2byte ITEM_NONE

SlateportCity_ShinyClub_EventScript_BugCatcher_Text_0:
	.string "I love Wurmple!\p"
	.string "I even found a purple one, look! Its\n"
	.string "name is Purmple!\p"
	.string "I can't wait to see if it'll evolve into\n"
	.string "Beautifly or Dustox!$"

SlateportCity_ShinyClub_EventScript_Hiker_Text_0:
	.string "I found this little nugget while hiking\n"
	.string "in the mountains!\p"
	.string "It has been with me ever since.$"

SlateportCity_ShinyClub_EventScript_ShinyBook_Text_0:
	.string "Shiny Pokémon:\p"
	.string "Very rarely, one can find Pokémon that\n"
	.string "differ in color from their usual\l"
	.string "coloration.\p"
	.string "While they are not stronger than their\n"
	.string "normal-colored counterparts, they are\l"
	.string "very sought after by collectors.\p"
	.string "Finding one in the wild is said to be a\n"
	.string "sign of good luck.$"

SlateportCity_ShinyClub_EventScript_ShinyClubChairman_Text_0:
	.string "Welcome back, {PLAYER}!\p"
	.string "How have you been?$"

SlateportCity_ShinyClub_EventScript_ShinyClubChairman_Text_1:
	.string "I'm the chairman of the Shiny Pokémon\n"
	.string "Club!\p"
	.string "Here, we're big fans of rare odd-colored\n"
	.string "Pokémon and show them off to each\l"
	.string "other.\p"
	.string "What about you? Do you have a shiny\n"
	.string "Pokémon?\p"
	.string "... Oh? Your {STR_VAR_1}...\p"
	.string "What a beauty! You're so lucky to have\n"
	.string "found such a rare Pokémon!\p"
	.string "Are you interested in joining our little\n"
	.string "club? Of course you are!\p"
	.string "Here, take this membership card!$"

SlateportCity_ShinyClub_EventScript_ShinyClubChairman_Text_2:
	.string "I hope you stop by often!$"

SlateportCity_ShinyClub_EventScript_ShinyClubChairman_Text_3:
	.string "I'm the chairman of the Shiny Pokémon\n"
	.string "Club!\p"
	.string "Here, we're big fans of rare odd-colored\n"
	.string "Pokémon and show them off to each\l"
	.string "other.\p"
	.string "What about you? Do you have a shiny\n"
	.string "Pokémon?\p"
	.string "If you find one, make sure to come back\n"
	.string "and show it to me!$"

SlateportCity_ShinyClub_EventScript_Cooltrainer_Text_0:
	.string "Finding a surprise shiny on your\n"
	.string "journey makes you use Pokémon you\l"
	.string "otherwise wouldn't have.$"

SlateportCity_ShinyClub_EventScript_Cooltrainer_Text_1:
	.string "Do you want to see my shiny Pokémon?\p"
	.string "They are not only beautiful, but also\n"
	.string "strong!$"

SlateportCity_ShinyClub_EventScript_Cooltrainer_Text_2:
	.string "Wow.$"

Route135_ShinyHouse_EventScript_ShinyLureSeller_Text_0:
	.string "I invented a special lure that attracts\n"
	.string "odd-colored Pokémon! Want to buy\l"
	.string "some?$"

Route135_ShinyHouse_EventScript_ShinyLureSeller_Text_1:
	.string "Good luck on your hunt!$"

Route135_ShinyHouse_EventScript_ShinyLureSeller_Text_2:
	.string "I invented a special lure that attracts\n"
	.string "odd-colored Pokémon!\p"
	.string "They're hard to make, so I only sell them\n"
	.string "to members for now.$"

SlateportCity_ShinyClub_EventScript_Geodude_Text_0:
	.string "Geodude: Gyuuu!$"

SlateportCity_ShinyClub_EventScript_Wurmple_Text_0:
	.string "Wurmple: Rrrrz!$"
