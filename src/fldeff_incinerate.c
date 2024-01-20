#include "global.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "faraway_island.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "malloc.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/songs.h"

// this file's functions
static void FieldCallback_IncinerateTree(void);
static void StartIncinerateTreeFieldEffect(void);

// code
bool8 SetUpFieldMove_IncinerateTree(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_CUTTABLE_TREE) == TRUE)
    {
        // Standing in front of cuttable tree.
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_IncinerateTree;
        return TRUE;
    }
    else {
        return FALSE;
    }
}

static void FieldCallback_IncinerateTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseIncinerate);
}

bool8 FldEff_UseIncinerateOnTree(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartIncinerateTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartIncinerateTreeFieldEffect;
    IncrementGameStat(GAME_STAT_USED_CUT);
    return FALSE;
}

static void StartIncinerateTreeFieldEffect(void)
{
    PlaySE(SE_M_FLAME_WHEEL2);
    FieldEffectActiveListRemove(FLDEFF_USE_INCINERATE_ON_TREE);
    ScriptContext_Enable();
}
