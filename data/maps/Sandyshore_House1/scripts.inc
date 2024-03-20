Sandyshore_House1_MapScripts::
	.byte 0


Sandyshore_House1_Grandma::
	lock
	faceplayer
	speakername Sandyshore_House1_Grandma_Text_0
	goto_if_unset FLAG_DAILY_SANDYSHORE_RECEIVED_COOKIE, Sandyshore_House1_Grandma_2
	msgbox Sandyshore_House1_Grandma_Text_2
Sandyshore_House1_Grandma_1:
	release
	end

Sandyshore_House1_Grandma_2:
	msgbox Sandyshore_House1_Grandma_Text_1
	speakername NULL
	giveitem ITEM_LAVA_COOKIE
	setflag FLAG_DAILY_SANDYSHORE_RECEIVED_COOKIE
	goto Sandyshore_House1_Grandma_1


Sandyshore_House1_Grandpa::
	lock
	faceplayer
	speakername Sandyshore_House1_Grandpa_Text_0
	msgbox Sandyshore_House1_Grandpa_Text_1
	applymovement 2, Common_Movement_WalkInPlaceRight
	applymovement 3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Sandyshore_House1_Grandpa_Text_2
	speakername Sandyshore_House1_Grandpa_Text_3
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox Sandyshore_House1_Grandpa_Text_4
	release
	end


Sandyshore_House1_Zigzagoon::
	lock
	faceplayer
	speakername Sandyshore_House1_Grandpa_Text_3
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox Sandyshore_House1_Grandpa_Text_4
	closemessage
	release
	end


Sandyshore_House1_Grandma_Text_0:
	.string "Berta$"

Sandyshore_House1_Grandma_Text_1:
	.string "Welcome, {PLAYER}! It is nice of you\n"
	.string "to visit.\p"
	.string "I just made cookies earlier. Please,\n"
	.string "take one!$"

Sandyshore_House1_Grandma_Text_2:
	.string "Welcome, {PLAYER}! It is nice of you\n"
	.string "to visit.$"

Sandyshore_House1_Grandpa_Text_0:
	.string "Wilbert$"

Sandyshore_House1_Grandpa_Text_1:
	.string "Zigzagoon and I like to take a stroll on\n"
	.string "the beach every once in a while.\p"
	.string "With its ability Pickup, it sometimes\n"
	.string "brings me small gifts too!$"

Sandyshore_House1_Grandpa_Text_2:
	.string "You're such a good boy, aren't you!$"

Sandyshore_House1_Grandpa_Text_3:
	.string "Zigzagoon$"

Sandyshore_House1_Grandpa_Text_4:
	.string "Gooo!$"
