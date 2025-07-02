Route135_DiveSchool_MapScripts::
	.byte 0


Route135_DiveSchool_EventScript_DiveTeacher::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE02_GET, Route135_DiveSchool_EventScript_DiveTeacher_1
	checkitem ITEM_DIVING_EQUIPMENT
	compare VAR_RESULT, TRUE
	goto_if_eq Route135_DiveSchool_EventScript_DiveTeacher_5
	checktrainerflag TRAINER_DIVING_INSTRUCTOR
	goto_if 0, Route135_DiveSchool_EventScript_DiveTeacher_6
	goto Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment
Route135_DiveSchool_EventScript_DiveTeacher_4:
	end

Route135_DiveSchool_EventScript_DiveTeacher_1:
	msgbox Route135_DiveSchool_EventScript_DiveTeacher_Text_0, MSGBOX_NPC
	release
	end

Route135_DiveSchool_EventScript_DiveTeacher_5:
	msgbox Route135_DiveSchool_Text_DivingInstructorExplainDive, MSGBOX_NPC
	release
	end

Route135_DiveSchool_EventScript_DiveTeacher_6:
	msgbox Route135_DiveSchool_EventScript_DiveTeacher_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route135_DiveSchool_EventScript_DiveTeacher_10
	goto Route135_DiveSchool_EventScript_DiveTeacher_4

Route135_DiveSchool_EventScript_DiveTeacher_10:
	trainerbattle_double TRAINER_DIVING_INSTRUCTOR, Route135_DiveSchool_EventScript_DiveTeacher_Text_2, Route135_DiveSchool_EventScript_DiveTeacher_Text_3, Route135_DiveSchool_EventScript_DiveTeacher_Text_4, Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment, NO_MUSIC
	goto Route135_DiveSchool_EventScript_DiveTeacher_4


Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment::
	lock
	msgbox Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_2
	closemessage
	release
	end

Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_2:
	checkmoney 1500
	compare VAR_RESULT, FALSE
	goto_if_eq Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_4
	msgbox Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_Text_2
	giveitem ITEM_DIVING_EQUIPMENT
	removemoney 1500
	waitfanfare
	msgbox Route135_DiveSchool_Text_DivingInstructorExplainDive
	closemessage
	release
	end

Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_4:
	msgbox Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_Text_1
	closemessage
	release
	end


Route135_DiveSchool_EventScript_Tuber::
	end


Route135_DiveSchool_EventScript_Fisherman::
	speakername Route135_DiveSchool_EventScript_Fisherman_Text_0
	msgbox Route135_DiveSchool_EventScript_Fisherman_Text_1, MSGBOX_NPC
	end


Route135_DiveSchool_EventScript_DiveTeacher_Text_0:
	.string "Sandyshore Town has beautiful reefs\n"
	.string "just off the shore.\p"
	.string "It's like entering a whole new world with\n"
	.string "the colorful corals and water Pokémon.\p"
	.string "You'll need some diving equipment\n"
	.string "though.\p"
	.string "But because of the strong tides\n"
	.string "recently it is dangerous to dive alone,\l"
	.string "so we can only rent out equipment to\l"
	.string "trainers with at least five badges.$"

Route135_DiveSchool_EventScript_DiveTeacher_Text_1:
	.string "Sandyshore Town has beautiful reefs\n"
	.string "just off the shore.\p"
	.string "It's like entering a whole new world with\n"
	.string "the colorful corals and water Pokémon.\p"
	.string "You'll need some diving equipment\n"
	.string "though.\p"
	.string "The strong tides recently make it\n"
	.string "dangerous to dive alone, but you seem\l"
	.string "like a strong trainer.\p"
	.string "If you can beat me in a battle, I'll let\n"
	.string "you rent some equipment!$"

Route135_DiveSchool_EventScript_DiveTeacher_Text_2:
	.string "Then prove to me you can watch out for\n"
	.string "yourself out there!$"

Route135_DiveSchool_EventScript_DiveTeacher_Text_3:
	.string "Haha, good, good! Looks like you'll be\n"
	.string "fine!$"

Route135_DiveSchool_EventScript_DiveTeacher_Text_4:
	.string "Hmmm, you seem to only have one Pokémon\n"
	.string "with you. You should have a few more\l"
	.string "with you if you want to stay safe out\l"
	.string "there.$"

Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_Text_0:
	.string "I see, you'll be able to hold your ground\n"
	.string "out there.\p"
	.string "I feel safe letting you use some of our\n"
	.string "equipment. It'll be ¥1500 for a set.$"

Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_Text_1:
	.string "I'm sorry, but you don't seem to have\n"
	.string "enough money.$"

Route135_DiveSchool_EventScript_DiveTeacherGetDivingEquipment_Text_2:
	.string "Here you go!$"

Route135_DiveSchool_EventScript_Fisherman_Text_0:
	.string "Stefano$"

Route135_DiveSchool_EventScript_Fisherman_Text_1:
	.string "I exclusively fish with an Old Rod.\p"
	.string "Why, you ask?\p"
	.string "You can only catch Magikarp with that,\n"
	.string "you say?\p"
	.string "But that's exactly the point!\p"
	.string "I'm looking for ones with rare patterns!\p"
	.string "I once caught one that was almost fully\n"
	.string "white.\p"
	.string "My fishing pal almost fainted from\n"
	.string "envy!$"

Route135_DiveSchool_Text_DivingInstructorExplainDive::
	.string "With that diving equipment, you'll be\n"
	.string "able to explore the seafloor.\p"
	.string "You'll need a Pokémon that knows the\n"
	.string "move Dive to pull you along underwater.\p"
	.string "When you find a spot where the water\n"
	.string "looks deep, just take a dive down and\l"
	.string "explore the seafloor!$"
