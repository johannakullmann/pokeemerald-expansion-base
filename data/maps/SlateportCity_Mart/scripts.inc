SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_BlackBelt::
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
	.string "The market does have some interesting\n"
	.string "merchandise.\p"
	.string "But there are some items you can only\n"
	.string "get at a Pokémon Mart.$"

SlateportCity_Mart_Text_GreatBallIsBetter:
	.string "A Great Ball is better than a Poké Ball\n"
	.string "at catching Pokémon.\p"
	.string "With this, I should be able to get that\n"
	.string "elusive Pokémon…$"

SlateportCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	switch VAR_POKEMART_TIER
	case 0, SlateportCity_Mart_EventScript_Clerk_3
	case 1, SlateportCity_Mart_EventScript_Clerk_4
SlateportCity_Mart_EventScript_Clerk_4:
	pokemart SlateportCity_Mart_Pokemart_Tier1
SlateportCity_Mart_EventScript_Clerk_1:
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_Mart_EventScript_Clerk_3:
	pokemart SlateportCity_Mart_Pokemart_Tier0
	goto SlateportCity_Mart_EventScript_Clerk_1


SlateportCity_Mart_EventScript_Man::
	switch VAR_POKEMART_TIER
	case 0, SlateportCity_Mart_EventScript_Man_3
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
SlateportCity_Mart_EventScript_Man_1:
	end

SlateportCity_Mart_EventScript_Man_3:
	msgbox SlateportCity_Mart_EventScript_Man_Text_0
	goto SlateportCity_Mart_EventScript_Man_1


	.align 2
SlateportCity_Mart_Pokemart_Tier0:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_NONE

	.align 2
SlateportCity_Mart_Pokemart_Tier1:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_NONE

SlateportCity_Mart_EventScript_Man_Text_0:
	.string "A Great Ball is better than a Poké Ball\n"
	.string "at catching Pokémon.\p"
	.string "But they seem to be out of stock right\n"
	.string "now…\p"
	.string "I wonder if they have some left in\n"
	.string "Mauville City…$"
