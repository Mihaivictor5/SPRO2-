#include "app_context.h"
#include "fsm.h"
#include "serial_router.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    app_context_t ctx;
    fsm_t fsm;
    unsigned int loop_count;

    memset(&ctx, 0, sizeof(ctx));
    fsm_init(&fsm);

    if (!serial_router_init())
    {
        printf("Serial router init failed.\n");
        return 1;
    }

    for (loop_count = 0; loop_count < 30; loop_count++)
    {
        fsm_step(&fsm, &ctx);
        printf("state=%s weight=%.2f box=%u err=%u\n",
               fsm_state_to_string(fsm.current),
               ctx.weight_grams,
               ctx.target_box_id,
               ctx.error_code);
        if (fsm.current == STATE_ERROR_STATE)
        {
            break;
        }
    }

    return 0;
}
