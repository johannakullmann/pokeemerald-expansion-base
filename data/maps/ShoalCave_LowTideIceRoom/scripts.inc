ShoalCave_LowTideIceRoom_MapScripts::
	.byte 0

ShoalCave_LowTideIceRoom_FieldResearcher::
	lock
	faceplayer
	speakername ShoalCave_LowTideIceRoom_FieldResearcher_Text_0
	msgbox ShoalCave_LowTideIceRoom_FieldResearcher_Text_1
	applymovement 3, Common_Movement_WalkInPlaceLeft
	msgbox ShoalCave_LowTideIceRoom_FieldResearcher_Text_2
	waitmovement 0
	closemessage
	turnobject 4, DIR_EAST
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	speakername CommonName_BufferedNameString1
	playmoncry SPECIES_CASTFORM, CRY_MODE_NORMAL
	msgbox Common_Text_Castform_Cry
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_FOUND_SHOAL_CAVE_RESEARCHER
	removeobject 3
	removeobject 4
	delay 16
	fadescreen FADE_FROM_BLACK
	release
	end


ShoalCave_LowTideIceRoom_FieldResearcher_Text_0:
	.string "Javiera$"

ShoalCave_LowTideIceRoom_FieldResearcher_Text_1:
	.string "Brrr, it's way too cold down here!\p"
	.string "Castform and I are checking if\n"
	.string "Groudon's activities have had effects\l"
	.string "on the frost in Shoal Cave.$"

ShoalCave_LowTideIceRoom_FieldResearcher_Text_2:
	.string "Let's go, Castform.\p"
	.string "I need a hot chocolate to warm up after\n"
	.string "this!$"
