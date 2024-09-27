#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen2[] =
{
#endif
#if P_FAMILY_TOXATIEL
    [SPECIES_TOXATIEL] =
    {
        .baseHP        = 50,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = 50,
        .baseSpDefense = 55,
        .types = { TYPE_FLYING, TYPE_POISON },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_NONE, ABILITY_POISON_POINT },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Toxatiel"),
        .cryId = CRY_TOXATIEL,
        .natDexNum = NATIONAL_DEX_TOXATIEL,
        .categoryName = _("Toxic Bird"), 
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
            "The iridescent plumage on Toxatiel's\n"
            "throat shimmers in all colors of the\n"
            "rainbow. Its slightly toxic saliva\n"
            "paralyzes the insects it hunts."),     
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Toxatiel,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Toxatiel,
        .frontAnimId = ANIM_H_JUMPS,
        .backPic = gMonBackPic_Toxatiel,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Toxatiel,
        .shinyPalette = gMonShinyPalette_Toxatiel,
        .iconSprite = gMonIcon_Toxatiel,
        .iconPalIndex = 2,
        .footprint = gMonFootprint_Toxatiel,
        .levelUpLearnset = sToxatielLevelUpLearnset,
        .teachableLearnset = sToxatielTeachableLearnset,
        .eggMoveLearnset = sToxatielEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_TOXATOO}),
        OVERWORLD(
            sPicTable_Toxatiel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Toxatiel,
            gShinyOverworldPalette_Toxatiel
        )
    },

    [SPECIES_TOXATOO] =
    {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 80,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_FLYING, TYPE_POISON },
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_CORROSION, ABILITY_NONE, ABILITY_POISON_TOUCH },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Toxatoo"),
        .cryId = CRY_TOXATOO,
        .natDexNum = NATIONAL_DEX_TOXATOO,
        .categoryName = _("Toxic Bird"),
        .height = 9,
        .weight = 122,
        .description = COMPOUND_STRING(
            "Toxatoo's feathers are very poisonous\n"
            "from the toxins in its diet. The bright\n"
            "patterns on its wings serve as a\n"
            "warning to predators."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Toxatoo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .enemyMonElevation = 10,
        .frontAnimFrames = sAnims_Toxatoo,
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Toxatoo,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Toxatoo,
        .shinyPalette = gMonShinyPalette_Toxatoo,
        .iconSprite = gMonIcon_Toxatoo,
        .iconPalIndex = 2,
        .footprint = gMonFootprint_Toxatoo,
        .levelUpLearnset = sToxatooLevelUpLearnset,
        .teachableLearnset = sToxatooTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_TOXATRICE}),
        OVERWORLD(
            sPicTable_Toxatoo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Toxatoo,
            gShinyOverworldPalette_Toxatoo
        )
    },

    [SPECIES_TOXATRICE] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 105,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = { TYPE_FLYING, TYPE_POISON },
        .catchRate = 45,
        .expYield = 265,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_CORROSION, ABILITY_NONE, ABILITY_POISON_TOUCH },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Toxatrice"),
        .cryId = CRY_TOXATRICE,
        .natDexNum = NATIONAL_DEX_TOXATRICE,
        .categoryName = _("Toxic Bird"),
        .height = 15,
        .weight = 312,
        .description = COMPOUND_STRING(
            "Toxatrice accumulates a deadly toxin\n"
            "in its body to use for hunting. Its\n"
            "piercing glare alone can paralyze small\n"
            "targets in an instant."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Toxatrice,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Toxatrice,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Toxatrice,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Toxatrice,
        .shinyPalette = gMonShinyPalette_Toxatrice,
        .iconSprite = gMonIcon_Toxatrice,
        .iconPalIndex = 2,
        .iconPalIndexFemale = 2,
        .footprint = gMonFootprint_Toxatrice,
        .levelUpLearnset = sToxatriceLevelUpLearnset,
        .teachableLearnset = sToxatriceTeachableLearnset,
        OVERWORLD(
            sPicTable_Toxatrice,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Toxatrice,
            gShinyOverworldPalette_Toxatrice
        )
    },
#endif //P_FAMILY_TOXATIEL

#if P_FAMILY_GROCKO
    [SPECIES_GROCKO] =
    {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 45,
        .baseSpeed     = 55,
        .baseSpAttack  = 60,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Grocko"),
        .cryId = CRY_GROCKO,
        .natDexNum = NATIONAL_DEX_GROCKO,
        .categoryName = _("Gem Lizard"),
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
            "This skittish Pokémon lives in stone\n"
            "crevices. It licks rocks to gather\n"
            "the minerals needed to grow the gem\n"
            "on its head."),      
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Grocko,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Grocko,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Grocko,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Grocko,
        .shinyPalette = gMonShinyPalette_Grocko,
        .iconSprite = gMonIcon_Grocko,
        .iconPalIndex = 1,
        .footprint = gMonFootprint_Grocko,
        .levelUpLearnset = sGrockoLevelUpLearnset,
        .teachableLearnset = sGrockoTeachableLearnset,
        .eggMoveLearnset = sGrockoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_RUBECKO}),
        OVERWORLD(
            sPicTable_Grocko,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Grocko,
            gShinyOverworldPalette_Grocko
        )
    },

    [SPECIES_RUBECKO] =
    {
        .baseHP        = 65,
        .baseAttack    = 55,
        .baseDefense   = 60,
        .baseSpeed     = 80,
        .baseSpAttack  = 85,
        .baseSpDefense = 60,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Rubecko"),
        .cryId = CRY_RUBECKO,
        .natDexNum = NATIONAL_DEX_RUBECKO,
        .categoryName = _("Gem Lizard"),
        .height = 9,
        .weight = 122,
        .description = COMPOUND_STRING( 
            "The brittle crystals on its back\n" 
            "grow with age. It prefers to avoid\n"
            "close combat to prevent its crystals\n"
            "from breaking."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Rubecko,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Rubecko,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Rubecko,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Rubecko,
        .shinyPalette = gMonShinyPalette_Rubecko,
        .iconSprite = gMonIcon_Rubecko,
        .iconPalIndex = 1,
        .footprint = gMonFootprint_Rubecko,
        .levelUpLearnset = sRubeckoLevelUpLearnset,
        .teachableLearnset = sRubeckoTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_DRABUNCLE}),
    },

    [SPECIES_DRABUNCLE] =
    {
        .baseHP        = 90,
        .baseAttack    = 65,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 120,
        .baseSpDefense = 80,
        .types = { TYPE_ROCK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 265,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Drabuncle"),
        .cryId = CRY_DRABUNCLE,
        .natDexNum = NATIONAL_DEX_DRABUNCLE,
        .categoryName = _("Ruby Dragon"),
        .height = 15,
        .weight = 312,
        .description = COMPOUND_STRING(
            "Drabuncle's sticky feet are strong\n"
            "enough to stick to the surface of cave\n"
            "ceilings. They are usually docile, but\n"
            "will defend their crystals viciously."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Drabuncle,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Drabuncle,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Drabuncle,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Drabuncle,
        .shinyPalette = gMonShinyPalette_Drabuncle,
        .iconSprite = gMonIcon_Drabuncle,
        .iconPalIndex = 1,
        .iconPalIndexFemale = 1,
        .footprint = gMonFootprint_Drabuncle,
        .levelUpLearnset = sDrabuncleLevelUpLearnset,
        .teachableLearnset = sDrabuncleTeachableLearnset,
        OVERWORLD(
            sPicTable_Drabuncle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Drabuncle,
            gShinyOverworldPalette_Drabuncle
        )
    },
#endif //P_FAMILY_GROCKO

#if P_FAMILY_CHIMERA
    [SPECIES_CHIMERA1] =
    {
        .baseHP        = 55,
        .baseAttack    = 60,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_NONE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Merakid"),
        .cryId = CRY_CHIMERA1,
        .natDexNum = NATIONAL_DEX_CHIMERA1,
        .categoryName = _("Goat"),
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
            "This feisty Pokémon can\n"
            "be found on steep cliffs.\n"
            "It picks fights with\n"
            "everyone and everything."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chimera1,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Chimera1,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Chimera1,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Chimera1,
        .shinyPalette = gMonShinyPalette_Chimera1,
        .iconSprite = gMonIcon_Chimera1,
        .iconPalIndex = 3,
        .footprint = gMonFootprint_Chimera1,
        .levelUpLearnset = sChimera1LevelUpLearnset,
        .teachableLearnset = sChimera1TeachableLearnset,
        .eggMoveLearnset = sChimera1EggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_CHIMERA2}),
    },

    [SPECIES_CHIMERA2] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 55,
        .baseSpAttack  = 55,
        .baseSpDefense = 70,
        .types = { TYPE_FIGHTING, TYPE_DARK },
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_NONE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Amalgoat"),
        .cryId = CRY_CHIMERA2,
        .natDexNum = NATIONAL_DEX_CHIMERA2,
        .categoryName = _("Goat"),
        .height = 9,
        .weight = 122,
        .description = COMPOUND_STRING(
            "Its tail's movements resemble that of\n"
            "a snake. The fake eyes on the tail\n"
            "pull the enemy's attention, giving\n"
            "this Pokémon an edge in a fight."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chimera2,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Chimera2,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Chimera2,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Chimera2,
        .shinyPalette = gMonShinyPalette_Chimera2,
        .iconSprite = gMonIcon_Chimera2,
        .iconPalIndex = 0,
        .footprint = gMonFootprint_Chimera2,
        .levelUpLearnset = sChimera2LevelUpLearnset,
        .teachableLearnset = sChimera2TeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_CHIMERA3}),
    },

    [SPECIES_CHIMERA3] =
    {
        .baseHP        = 115,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 60,
        .baseSpAttack  = 75,
        .baseSpDefense = 95,
        .types = { TYPE_FIGHTING, TYPE_DARK },
        .catchRate = 45,
        .expYield = 265,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_NONE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Chimeroar"),
        .cryId = CRY_CHIMERA3,
        .natDexNum = NATIONAL_DEX_CHIMERA3,
        .categoryName = _("Chimera"),
        .height = 15,
        .weight = 312,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."), 
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chimera3,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Chimera3,
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Chimera3,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Chimera3,
        .shinyPalette = gMonShinyPalette_Chimera3,
        .iconSprite = gMonIcon_Chimera3,
        .iconPalIndex = 2,
        .iconPalIndexFemale = 2,
        .footprint = gMonFootprint_Chimera3,
        .levelUpLearnset = sChimera3LevelUpLearnset,
        .teachableLearnset = sChimera3TeachableLearnset,
    },
#endif //P_FAMILY_CHIMERA

#if P_FAMILY_HATCHIK
    [SPECIES_HATCHIK] =
    {
        .baseHP        = 40,
        .baseAttack    = 61,
        .baseDefense   = 54,
        .baseSpeed     = 65,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_RECKLESS, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hatchik"),
        .cryId = CRY_HATCHIK,
        .natDexNum = NATIONAL_DEX_HATCHIK,
        .categoryName = _("Dodo"),
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),      
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hatchik,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Hatchik,
        .frontAnimId = ANIM_V_JUMPS_BIG,
        .backPic = gMonBackPic_Hatchik,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Hatchik,
        .shinyPalette = gMonShinyPalette_Hatchik,
        .iconSprite = gMonIcon_Hatchik,
        .iconPalIndex = 3,
        .footprint = gMonFootprint_Hatchik,
        .levelUpLearnset = sHatchikLevelUpLearnset,
        .teachableLearnset = sHatchikTeachableLearnset,
        .eggMoveLearnset = sHatchikEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_DODO2}),
    },

    [SPECIES_DODO2] =
    {
        .baseHP        = 61,
        .baseAttack    = 80,
        .baseDefense   = 63,
        .baseSpeed     = 83,
        .baseSpAttack  = 60,
        .baseSpDefense = 63,
        .types = { TYPE_ROCK, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_RECKLESS, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Dodo2"),
        .cryId = CRY_DODO2,
        .natDexNum = NATIONAL_DEX_DODO2,
        .categoryName = _("Axe Beak"),
        .height = 9,
        .weight = 122,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dodo2,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Dodo2,
        .frontAnimId = ANIM_H_JUMPS,
        .backPic = gMonBackPic_Dodo2,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Dodo2,
        .shinyPalette = gMonShinyPalette_Dodo2,
        .iconSprite = gMonIcon_Dodo2,
        .iconPalIndex = 2,
        .footprint = gMonFootprint_Dodo2,
        .levelUpLearnset = sDodo2LevelUpLearnset,
        .teachableLearnset = sDodo2TeachableLearnset,
    },
#endif //P_FAMILY_HATCHIK

#if P_FAMILY_MBIELU
    [SPECIES_MBIELU] =
    {
        .baseHP        = 40,
        .baseAttack    = 61,
        .baseDefense   = 54,
        .baseSpeed     = 65,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_MAGMA_ARMOR, ABILITY_BATTLE_ARMOR, ABILITY_WHITE_SMOKE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Mbielu"),
        .cryId = CRY_MBIELU,
        .natDexNum = NATIONAL_DEX_MBIELU,
        .categoryName = _("Tail Spike"),
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),      
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mbielu,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Mbielu,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Mbielu,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Mbielu,
        .shinyPalette = gMonShinyPalette_Mbielu,
        .iconSprite = gMonIcon_Mbielu,
        .iconPalIndex = 1,
        .footprint = gMonFootprint_Mbielu,
        .levelUpLearnset = sMbieluLevelUpLearnset,
        .teachableLearnset = sMbieluTeachableLearnset,
        .eggMoveLearnset = sMbieluEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_MBIELAVA}),
    },

    [SPECIES_MBIELAVA] =
    {
        .baseHP        = 61,
        .baseAttack    = 80,
        .baseDefense   = 63,
        .baseSpeed     = 83,
        .baseSpAttack  = 60,
        .baseSpDefense = 63,
        .types = { TYPE_ROCK, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_MAGMA_ARMOR, ABILITY_BATTLE_ARMOR, ABILITY_WHITE_SMOKE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Mbielava"),
        .cryId = CRY_MBIELAVA,
        .natDexNum = NATIONAL_DEX_MBIELAVA,
        .categoryName = _("Fire Plate"),
        .height = 9,
        .weight = 122,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mbielava,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Mbielava,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Mbielava,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Mbielava,
        .shinyPalette = gMonShinyPalette_Mbielava,
        .iconSprite = gMonIcon_Mbielava,
        .iconPalIndex = 1,
        .footprint = gMonFootprint_Mbielava,
        .levelUpLearnset = sMbielavaLevelUpLearnset,
        .teachableLearnset = sMbielavaTeachableLearnset,
    },
#endif //P_FAMILY_HATCHIK

#ifdef __INTELLISENSE__
};
#endif