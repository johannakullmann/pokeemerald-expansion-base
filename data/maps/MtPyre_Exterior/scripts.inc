MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition:
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit::
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	doweather
	end

MtPyre_Exterior_EventScript_FieldResearcher::
	lock
	faceplayer
	speakername MtPyre_Exterior_EventScript_FieldResearcher_Text_0
	msgbox MtPyre_Exterior_EventScript_FieldResearcher_Text_1
	applymovement 4, Common_Movement_WalkInPlaceLeft
	msgbox MtPyre_Exterior_EventScript_FieldResearcher_Text_2
	waitmovement 0
	closemessage
	turnobject 3, DIR_EAST
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	speakername CommonName_BufferedNameString1
	playmoncry SPECIES_CASTFORM, CRY_MODE_NORMAL
	msgbox Common_Text_Castform_Cry
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_FOUND_MT_PYRE_RESEARCHER
	removeobject 4
	removeobject 3
	delay 16
	fadescreen FADE_FROM_BLACK
	release
	end


MtPyre_Exterior_EventScript_FieldResearcher_Text_0:
	.string "Levi$"

MtPyre_Exterior_EventScript_FieldResearcher_Text_1:
	.string "Mount Pyre's summit is always covered\n"
	.string "in clouds.\p"
	.string "We're actually standing inside of one\n"
	.string "right now!$"

MtPyre_Exterior_EventScript_FieldResearcher_Text_2:
	.string "Castform is in its normal form right\n"
	.string "now...\p"
	.string "I'm always wondering if there's forms we\n"
	.string "don't know of yet.\p"
	.string "Could there be a fog form or a\n"
	.string "thunderstorm form?\p"
	.string "Anyway, let's go back to the institute,\n"
	.string "Castform!$"
