//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 2
        .trainerName = _("???"),
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("Steven"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 19
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
#line 18
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 17
            .lvl = 42,
#line 16
            .nature = NATURE_BRAVE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 20
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 25
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 29
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
#line 28
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 27
            .lvl = 43,
#line 26
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 30
                MOVE_TOXIC,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 35
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 39
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
#line 38
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 37
            .lvl = 44,
#line 36
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 40
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_SOLAR_BEAM,
                MOVE_DRAGON_CLAW,
            },
            },
        },
    },
#line 45
    [DIFFICULTY_NORMAL][PARTNER_RUTH_TOXATIEL] =
    {
#line 46
        .trainerName = _("Ruth"),
#line 47
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 48
        .trainerPic = TRAINER_BACK_PIC_RUTH,
        .encounterMusic_gender =
#line 49
F_TRAINER_FEMALE | 
#line 50
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 52
            .species = SPECIES_GROCKO,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 56
            .ev = TRAINER_PARTY_EVS(0, 0, 0, 64, 64, 0),
#line 55
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 54
            .lvl = 8,
#line 53
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 57
                MOVE_PEBBLE_SHOT,
                MOVE_LICK,
                MOVE_TACKLE,
                MOVE_GROWL,
            },
            },
            {
#line 62
            .species = SPECIES_BUDEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 66
            .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 64, 0),
#line 65
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 64
            .lvl = 7,
#line 63
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 67
                MOVE_ABSORB,
                MOVE_GROWTH,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 71
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 75
            .ev = TRAINER_PARTY_EVS(0, 64, 0, 64, 0, 0),
#line 74
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 73
            .lvl = 8,
#line 72
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 76
                MOVE_TACKLE,
                MOVE_HELPING_HAND,
                MOVE_SAND_ATTACK,
                MOVE_QUICK_ATTACK,
            },
            },
        },
    },
#line 81
    [DIFFICULTY_NORMAL][PARTNER_RUTH_GROCKO] =
    {
#line 82
        .trainerName = _("Ruth"),
#line 83
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 84
        .trainerPic = TRAINER_BACK_PIC_RUTH,
        .encounterMusic_gender =
#line 85
F_TRAINER_FEMALE | 
#line 86
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 88
            .species = SPECIES_MERAKID,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 92
            .ev = TRAINER_PARTY_EVS(0, 64, 0, 64, 0, 0),
#line 91
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 90
            .lvl = 8,
#line 89
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 93
                MOVE_POUND,
                MOVE_KICK,
                MOVE_ENDURE,
                MOVE_LEER,
            },
            },
            {
#line 98
            .species = SPECIES_BUDEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 102
            .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 64, 0),
#line 101
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 100
            .lvl = 7,
#line 99
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 103
                MOVE_ABSORB,
                MOVE_GROWTH,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 107
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 111
            .ev = TRAINER_PARTY_EVS(0, 64, 0, 64, 0, 0),
#line 110
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 109
            .lvl = 8,
#line 108
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 112
                MOVE_TACKLE,
                MOVE_HELPING_HAND,
                MOVE_SAND_ATTACK,
                MOVE_QUICK_ATTACK,
            },
            },
        },
    },
#line 117
    [DIFFICULTY_NORMAL][PARTNER_RUTH_MERAKID] =
    {
#line 118
        .trainerName = _("Ruth"),
#line 119
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 120
        .trainerPic = TRAINER_BACK_PIC_RUTH,
        .encounterMusic_gender =
#line 121
F_TRAINER_FEMALE | 
#line 122
            TRAINER_ENCOUNTER_MUSIC_FEMALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 124
            .species = SPECIES_TOXATIEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 128
            .ev = TRAINER_PARTY_EVS(0, 64, 0, 64, 0, 0),
#line 127
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 126
            .lvl = 8,
#line 125
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 129
                MOVE_POISON_STING,
                MOVE_PECK,
                MOVE_TAIL_WHIP,
                MOVE_SCRATCH,
            },
            },
            {
#line 134
            .species = SPECIES_BUDEW,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 138
            .ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 64, 0),
#line 137
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 136
            .lvl = 7,
#line 135
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 139
                MOVE_ABSORB,
                MOVE_GROWTH,
                MOVE_STUN_SPORE,
            },
            },
            {
#line 143
            .species = SPECIES_EEVEE,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 147
            .ev = TRAINER_PARTY_EVS(0, 64, 0, 64, 0, 0),
#line 146
            .iv = TRAINER_PARTY_IVS(16, 16, 16, 16, 16, 16),
#line 145
            .lvl = 8,
#line 144
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 148
                MOVE_TACKLE,
                MOVE_HELPING_HAND,
                MOVE_SAND_ATTACK,
                MOVE_QUICK_ATTACK,
            },
            },
        },
    },
