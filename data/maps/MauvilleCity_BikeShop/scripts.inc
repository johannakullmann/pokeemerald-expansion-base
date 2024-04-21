MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me RYDEL.\n"
	.string "I'm the owner of this cycle shop.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Your RUNNING SHOES…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: Is that right?\p"
	.string "Then, I guess you have no need for\n"
	.string "any of my BIKES.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!\p"
	.string "Oh, wait a second!\p"
	.string "I forgot to tell you that there are\n"
	.string "two kinds of BIKES!\p"
	.string "They are the MACH BIKE and\n"
	.string "the ACRO BIKE!\p"
	.string "The MACH BIKE is for cyclists who want\n"
	.string "to feel the wind with their bodies!\p"
	.string "And an ACRO BIKE is for those who\n"
	.string "prefer technical rides!\p"
	.string "I'm a real sweetheart, so you can\n"
	.string "have whichever one you like!\p"
	.string "Which one will you choose?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} chose the MACH BIKE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} chose the ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: If you get the urge to switch\n"
	.string "BIKES, just come see me!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: Oh? Were you thinking about\n"
	.string "switching BIKES?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Okay, no problem!\n"
	.string "I'll switch BIKES for you!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} got the MACH BIKE exchanged\n"
	.string "for an ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} got the ACRO BIKE exchanged\n"
	.string "for a MACH BIKE.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Good, good!\n"
	.string "I'm happy that you like it!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? What happened to that BIKE\n"
	.string "I gave you?\p"
	.string "Oh, I get it, you stored it using your PC.\p"
	.string "Well, take it out of PC storage,\n"
	.string "and I'll be happy to exchange it!\p"
	.string "May the wind always be at your back\n"
	.string "on your adventure!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "I'm learning about BIKES while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride your\n"
	.string "BIKE, there're a couple handbooks in\l"
	.string "the back.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "It's a handbook on the MACH BIKE.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "A BIKE moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The BIKE will slow to a stop.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "A MACH BIKE is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "There are small sandy slopes\n"
	.string "throughout the HOENN region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But if you have a MACH BIKE, you can\n"
	.string "zip up a sandy slope.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "It's a handbook on the ACRO BIKE.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk::
	lock
	faceplayer
	speakername MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_0
	goto_if_unset FLAG_PREORDERED_BIKE, MauvilleCity_BikeShop_EventScript_BikeShopClerk_2
	goto_if_unset FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_BikeShopClerk_3
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_11
MauvilleCity_BikeShop_EventScript_BikeShopClerk_1:
	closemessage
	release
	end

MauvilleCity_BikeShop_EventScript_BikeShopClerk_2:
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopClerk_7
	goto MauvilleCity_BikeShop_EventScript_BikeShopClerk_1

MauvilleCity_BikeShop_EventScript_BikeShopClerk_3:
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_7, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopClerk_9
	goto MauvilleCity_BikeShop_EventScript_BikeShopClerk_1

MauvilleCity_BikeShop_EventScript_BikeShopClerk_7:
	turnobject 3, DIR_WEST
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_2
	turnobject 3, DIR_SOUTH
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopClerk_11
	goto MauvilleCity_BikeShop_EventScript_BikeShopClerk_1

MauvilleCity_BikeShop_EventScript_BikeShopClerk_9:
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_8
	turnobject 3, DIR_WEST
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_9
	turnobject 3, DIR_SOUTH
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_10
	goto MauvilleCity_BikeShop_EventScript_BikeShopClerk_1

MauvilleCity_BikeShop_EventScript_BikeShopClerk_11:
	showmoneybox 0, 0
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopClerk_13
	goto MauvilleCity_BikeShop_EventScript_BikeShopClerk_1

MauvilleCity_BikeShop_EventScript_BikeShopClerk_13:
	checkmoney 5000
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_BikeShop_EventScript_BikeShopClerk_15
	hidemoneybox
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_6
	goto MauvilleCity_BikeShop_EventScript_BikeShopClerk_1

MauvilleCity_BikeShop_EventScript_BikeShopClerk_15:
	removemoney 5000
	updatemoneybox
	msgbox MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_5
	hidemoneybox
	setflag FLAG_PREORDERED_BIKE
	setflag FLAG_ENABLE_BIKE_SHOP_MATCH_CALL
	goto MauvilleCity_BikeShop_EventScript_BikeShopClerk_1


MauvilleCity_BikeShop_EventScript_Lass::
	lock
	faceplayer
	speakername MauvilleCity_BikeShop_EventScript_Lass_Text_0
	msgbox MauvilleCity_BikeShop_EventScript_Lass_Text_1
	closemessage
	release
	end


MauvilleCity_BikeShop_EventScript_Triathlete::
	lock
	faceplayer
	speakername MauvilleCity_BikeShop_EventScript_Triathlete_Text_0
	msgbox MauvilleCity_BikeShop_EventScript_Triathlete_Text_1
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	closemessage
	release
	end


MauvilleCity_BikeShop_EventScript_Assistant::
	lock
	faceplayer
	speakername MauvilleCity_BikeShop_EventScript_Assistant_Text_0
	msgbox MauvilleCity_BikeShop_EventScript_Assistant_Text_1
	closemessage
	release
	end


MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_0:
	.string "Shop Clerk$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_1:
	.string "Good day!\p"
	.string "Welcome at Rydel's Bike Shop!\p"
	.string "Yes, the one and only!\p"
	.string "Are you here to buy one of our famous\n"
	.string "bikes?$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_2:
	.string "Let me check my list…\p"
	.string "… What did you say your name was?\n"
	.string "{PLAYER}?\p"
	.string "…$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_3:
	.string "I'm sorry, you don't seem to on the list\n"
	.string "of reservations.\p"
	.string "But you can put down a pre-order for\n"
	.string "you, if you'd like that.$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_4:
	.string "That'll be a payment of ¥5000 up-front,\n"
	.string "and another ¥10000 once you pick up\l"
	.string "your bike.\p"
	.string "Is that okay with you?$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_5:
	.string "Please sign here… and here…\p"
	.string "Thank you! That's all!\p"
	.string "Here's our number, we'll call you once\n"
	.string "your order arrives.$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_6:
	.string "I am sorry, but you don't seem to have\n"
	.string "enough money with you.$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_7:
	.string "Good day!\p"
	.string "Welcome at Rydel's Bike Shop!\p"
	.string "Yes, the one and only!\p"
	.string "Are you here to check up on your\n"
	.string "pre-order?$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_8:
	.string "Let me check my list…$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_9:
	.string "… Hmmm… {PLAYER}, right?\p"
	.string "…$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_10:
	.string "It looks like your order has not arrived\n"
	.string "yet.\p"
	.string "We'll give you a call once your bike is\n"
	.string "ready for pick-up!$"

MauvilleCity_BikeShop_EventScript_BikeShopClerk_Text_11:
	.string "Good day!\p"
	.string "Welcome at Rydel's Bike Shop!\p"
	.string "Feel free to browse around!$"

MauvilleCity_BikeShop_EventScript_Lass_Text_0:
	.string "Neena$"

MauvilleCity_BikeShop_EventScript_Lass_Text_1:
	.string "Rydel's bikes are so popular right now\n"
	.string "you can't even get your hands on one\l"
	.string "without pre-ordering!\p"
	.string "I pre-ordered one of the new bikes a\n"
	.string "soon as I got the chance to!\p"
	.string "Ahhhh, I can barely wait for it to\n"
	.string "arrive!$"

MauvilleCity_BikeShop_EventScript_Triathlete_Text_0:
	.string "Georgios$"

MauvilleCity_BikeShop_EventScript_Triathlete_Text_1:
	.string "I really want to swap out my rickety old\n"
	.string "Mach Bike for a new one, but all of\l"
	.string "these bikes here are reserved.\p"
	.string "If I have to order one anyway, I might\n"
	.string "as well get one of them fancy new\l"
	.string "hybrid bikes.\p"
	.string "They're fast like a Mach Bike, but can\n"
	.string "also be used to traverse difficult\l"
	.string "terrain.\p"
	.string "Trying my hand at the Mount Chimney\n"
	.string "downhill sounds nice for a change!$"

MauvilleCity_BikeShop_EventScript_Assistant_Text_0:
	.string "Fred$"

MauvilleCity_BikeShop_EventScript_Assistant_Text_1:
	.string "There's a lot of customers here these\n"
	.string "days.\p"
	.string "Guess the owner's idea of giving out\n"
	.string "free bikes as advertisement really\l"
	.string "paid off!$"
