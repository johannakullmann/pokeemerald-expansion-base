#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "item_use.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/map_types.h"
#include "constants/songs.h"

static void StartHeadbuttTreeFieldEffect(void);
static void FieldCallback_HeadbuttTree(void);

bool8 SetUpFieldMove_Headbutt(void)
{

    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_HEADBUTT_TREE) == TRUE)
    {
        // Standing in front of headbutt tree.
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_HeadbuttTree;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

static void FieldCallback_HeadbuttTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseHeadbutt);
}

bool8 FldEff_UseHeadbutt(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartHeadbuttTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartHeadbuttTreeFieldEffect;
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

static void StartHeadbuttTreeFieldEffect(void)
{
    PlaySE(SE_NOT_EFFECTIVE);
    FieldEffectActiveListRemove(FLDEFF_USE_HEADBUTT);
    ScriptContext_Enable();
}