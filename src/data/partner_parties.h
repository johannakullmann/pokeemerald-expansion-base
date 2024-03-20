static const struct TrainerMon sParty_StevenPartner[] = {
    {
        .species = SPECIES_METANG,
        .lvl = 42,
        .nature = NATURE_BRAVE,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
        .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
    },
    {
        .species = SPECIES_SKARMORY,
        .lvl = 43,
        .nature = NATURE_IMPISH,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
        .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
    },
    {
        .species = SPECIES_AGGRON,
        .lvl = 44,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
        .moves = {MOVE_THUNDER, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW},
    }
};

static const struct TrainerMon sParty_RuthPartnerToxatiel[] = {
    {
        .species = SPECIES_GROCKO,
        .gender = TRAINER_MON_FEMALE,
        .lvl = 9,
    },
    {
        .species = SPECIES_BUDEW,
        .gender = TRAINER_MON_FEMALE,
        .lvl = 8,
    },
    {
        .species = SPECIES_EEVEE,
        .gender = TRAINER_MON_MALE,
        .lvl = 10,
    }
};

static const struct TrainerMon sParty_RuthPartnerGrocko[] = {
    {
        .species = SPECIES_CHIMERA1,
        .gender = TRAINER_MON_FEMALE,
        .lvl = 9,
    },
    {
        .species = SPECIES_BUDEW,
        .gender = TRAINER_MON_FEMALE,
        .lvl = 8,
    },
    {
        .species = SPECIES_EEVEE,
        .gender = TRAINER_MON_MALE,
        .lvl = 10,
    }
};

static const struct TrainerMon sParty_RuthPartnerMerakid[] = {
    {
        .species = SPECIES_TOXATIEL,
        .gender = TRAINER_MON_FEMALE,
        .lvl = 9,
    },
    {
        .species = SPECIES_BUDEW,
        .gender = TRAINER_MON_FEMALE,
        .lvl = 8,
    },
    {
        .species = SPECIES_EEVEE,
        .gender = TRAINER_MON_MALE,
        .lvl = 10,
    }
};