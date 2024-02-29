Sandyshore_PlayerHouse_2F_MapScripts::
	.byte 0


Sandyshore_Playerhouse_2F_EventScript_RuthCall::
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_ENABLE_RUTH_MATCH_CALL
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	clearflag FLAG_SYS_RIBBON_GET
	lock
	pokenavcall Sandyshore_Playerhouse_2F_RuthCall
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	waitmessage
	release
	end


Sandyshore_Playerhouse_2F_RuthCall::
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Ruth: Hi, hi, {PLAYER}!\n"
	.string "It's me, Ruth!\p"
	.string "Did the Professor give you a\n"
	.string "call too?\p"
	.string "I wonder what's up, isn't he\n"
	.string "really busy at the moment?\p"
	.string "Let's meet up at the inn\n"
	.string "and see what's going on!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
