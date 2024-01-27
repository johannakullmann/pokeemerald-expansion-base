PacifidlogTown_Mart_MapScripts::
	.byte 0

PacifidlogTown_Mart_Employee::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PacifidlogTown_Mart_Tier1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end


PacifidlogTown_EventScript_Girl::
	lock
	faceplayer
	msgbox PacifidlogTown_EventScript_Girl_Text_0, MSGBOX_AUTOCLOSE
	end


	.align 2
PacifidlogTown_Mart_Tier1:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_NONE

PacifidlogTown_EventScript_Girl_Text_0:
	.string "I'm happy we finally got a mart in\n"
	.string "Pacifidlog Town.\p"
	.string "Now I can shop to my heart's content!$"
