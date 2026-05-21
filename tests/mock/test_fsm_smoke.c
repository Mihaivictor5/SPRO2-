#include "../../pi_controller/include/fsm.h"
#include <assert.h>
#include <string.h>

int main(void)
{
    fsm_t fsm;
    app_context_t ctx;

    memset(&ctx, 0, sizeof(ctx));
    fsm_init(&fsm);

    assert(fsm.current == STATE_IDLE);
    fsm_step(&fsm, &ctx);
    assert(fsm.current == STATE_WAIT_FOR_FRUIT);

    return 0;
}
