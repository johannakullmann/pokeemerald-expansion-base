#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "party_menu.h"
#include "script.h"
#include "sprite.h"
#include "task.h"
#include "wild_encounter.h"
#include "constants/field_effects.h"
#include "constants/songs.h"

static void FieldCallback_Roar(void);
void StartRoarFieldEffect(void);

bool8 SetUpFieldMove_Roar(void)
{
    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
    gPostMenuFieldCallback = FieldCallback_Roar;
    return TRUE;
}

static void FieldCallback_Roar(void)
{
    FieldEffectStart(FLDEFF_ROAR);
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
}

bool8 FldEff_Roar(void)
{
    u8 taskId;
    taskId = CreateFieldMoveTask();
    gTasks[taskId].data[8] = (u32)StartRoarFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartRoarFieldEffect;
    return FALSE;
}

void StartRoarFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_ROAR);
    VarSet(VAR_REPEL_STEP_COUNT, 50);
    #if VAR_LAST_REPEL_LURE_USED != 0
        VarSet(VAR_LAST_REPEL_LURE_USED, ITEM_REPEL_ROAR);
    #endif
    ScriptContext_SetupScript(EventScript_UseRoar);
}
