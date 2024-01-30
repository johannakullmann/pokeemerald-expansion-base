#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "fldeff.h"
#include "party_menu.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "constants/field_effects.h"

#define NUM_ROAR_REPEL_STEPS 20

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
    VarSet(VAR_REPEL_STEP_COUNT, NUM_ROAR_REPEL_STEPS);
    #if VAR_LAST_REPEL_LURE_USED != 0
        VarSet(VAR_LAST_REPEL_LURE_USED, ITEM_NONE);
    #endif
    ScriptContext_SetupScript(EventScript_UseRoar);
}

bool8 FldEff_Roar(void)
{
    u8 taskId;
    taskId = CreateFieldMoveTask();
    gTasks[taskId].data[8] = (u32)StartRoarFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartRoarFieldEffect;
    GetMonNickname(&gPlayerParty[gFieldEffectArguments[0]], gStringVar1);
    return FALSE;
}

void StartRoarFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_ROAR);
    ScriptContext_Enable();
}
