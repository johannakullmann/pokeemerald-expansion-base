#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "fldeff.h"
#include "party_menu.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"

// static functions
static void FieldCallback_Strength(void);
static void StartStrengthFieldEffect(void);

// text
bool8 SetUpFieldMove_Strength(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_PUSHABLE_BOULDER) 
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LARGE_PUSHABLE_BOULDER_1)
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LARGE_PUSHABLE_BOULDER_2)
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LARGE_PUSHABLE_BOULDER_3)
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LARGE_PUSHABLE_BOULDER_4)
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LONG_PUSHABLE_BOULDER_HORIZ_1) 
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LONG_PUSHABLE_BOULDER_HORIZ_2) 
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LONG_PUSHABLE_BOULDER_HORIZ_3) 
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LONG_PUSHABLE_BOULDER_VERT_1) 
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LONG_PUSHABLE_BOULDER_VERT_2) 
    || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_LONG_PUSHABLE_BOULDER_VERT_3))
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Strength;
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_Strength(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseStrength);
}

bool8 FldEff_UseStrength(void)
{
    u8 taskId = CreateFieldMoveTask();
    gTasks[taskId].data[8] = (u32)StartStrengthFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartStrengthFieldEffect;
    GetMonNickname(&gPlayerParty[gFieldEffectArguments[0]], gStringVar1);
    return FALSE;
}

// Just passes control back to EventScript_UseStrength
static void StartStrengthFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_STRENGTH);
    ScriptContext_Enable();
}
