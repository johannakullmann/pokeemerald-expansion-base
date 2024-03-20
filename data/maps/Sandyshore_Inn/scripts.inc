Sandyshore_Inn_MapScripts::
	.byte 0


Sandyshore_Inn_EventScript_Man::
	speakername Sandyshore_Inn_EventScript_Man_Text_0
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq Sandyshore_Inn_EventScript_Man_1
	msgbox Sandyshore_Inn_EventScript_Man_Text_2, MSGBOX_NPC
	end

Sandyshore_Inn_EventScript_Man_1:
	msgbox Sandyshore_Inn_EventScript_Man_Text_1, MSGBOX_NPC
	end


Sandyshore_Inn_EventScript_Woman::
	end


Sandyshore_Inn_EventScript_Man_Text_0:
	.string "Robert$"

Sandyshore_Inn_EventScript_Man_Text_1:
	.string "Are you looking for Ruth, {PLAYER}?\p"
	.string "She just stormed past here and up the\n"
	.string "stairs.$"

Sandyshore_Inn_EventScript_Man_Text_2:
	.string "There's a lot of guests at the inn this\n"
	.string "time of the year.\p"
	.string "In my not-at-all-biased opinion, our\n"
	.string "small beachside inn is the best\l"
	.string "vacation spot this side of Hoenn,\l"
	.string "after all!$"
