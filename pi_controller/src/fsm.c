#include "fsm.h"
#include "serial_router.h"

static uint8_t decide_box_from_weight(float weight_grams)
{
    if (weight_grams < 80.0f)
    {
        return 1;
    }
    if (weight_grams < 150.0f)
    {
        return 2;
    }
    return 3;
}

void fsm_init(fsm_t *fsm)
{
    fsm->current = STATE_IDLE;
    fsm->previous = STATE_IDLE;
}

static void set_state(fsm_t *fsm, robot_state_t next)
{
    fsm->previous = fsm->current;
    fsm->current = next;
}

void fsm_step(fsm_t *fsm, app_context_t *ctx)
{
    switch (fsm->current)
    {
    case STATE_IDLE:
        set_state(fsm, STATE_WAIT_FOR_FRUIT);
        break;

    case STATE_WAIT_FOR_FRUIT:
        ctx->fruit_detected = fruit_sensor_detected();
        if (ctx->fruit_detected)
        {
            set_state(fsm, STATE_READ_WEIGHT);
        }
        break;

    case STATE_READ_WEIGHT:
        ctx->weight_grams = scale_read_weight_grams();
        set_state(fsm, STATE_DECIDE_BOX);
        break;

    case STATE_DECIDE_BOX:
        ctx->target_box_id = decide_box_from_weight(ctx->weight_grams);
        set_state(fsm, STATE_MOVE_TO_FRUIT);
        break;

    case STATE_MOVE_TO_FRUIT:
        if (!gantry_move_to(100.0f, 50.0f))
        {
            ctx->error_flag = true;
            ctx->error_code = 1001;
            set_state(fsm, STATE_ERROR_STATE);
            break;
        }
        set_state(fsm, STATE_CLOSE_CLAW);
        break;

    case STATE_CLOSE_CLAW:
        if (!claw_close())
        {
            ctx->error_flag = true;
            ctx->error_code = 1002;
            set_state(fsm, STATE_ERROR_STATE);
            break;
        }
        set_state(fsm, STATE_CHECK_GRIP);
        break;

    case STATE_CHECK_GRIP:
        ctx->grip_ok = claw_read_pressure() > 0.5f;
        if (!ctx->grip_ok)
        {
            ctx->error_flag = true;
            ctx->error_code = 1003;
            set_state(fsm, STATE_ERROR_STATE);
            break;
        }
        set_state(fsm, STATE_MOVE_TO_BOX);
        break;

    case STATE_MOVE_TO_BOX:
        if (!gantry_move_to(200.0f + (ctx->target_box_id * 20.0f), 160.0f))
        {
            ctx->error_flag = true;
            ctx->error_code = 1004;
            set_state(fsm, STATE_ERROR_STATE);
            break;
        }
        set_state(fsm, STATE_OPEN_CLAW);
        break;

    case STATE_OPEN_CLAW:
        if (!claw_open())
        {
            ctx->error_flag = true;
            ctx->error_code = 1005;
            set_state(fsm, STATE_ERROR_STATE);
            break;
        }
        set_state(fsm, STATE_RETURN_HOME);
        break;

    case STATE_RETURN_HOME:
        if (!gantry_home())
        {
            ctx->error_flag = true;
            ctx->error_code = 1006;
            set_state(fsm, STATE_ERROR_STATE);
            break;
        }
        set_state(fsm, STATE_WAIT_FOR_FRUIT);
        break;

    case STATE_ERROR_STATE:
        break;
    }
}

const char *fsm_state_to_string(robot_state_t state)
{
    switch (state)
    {
    case STATE_IDLE: return "IDLE";
    case STATE_WAIT_FOR_FRUIT: return "WAIT_FOR_FRUIT";
    case STATE_READ_WEIGHT: return "READ_WEIGHT";
    case STATE_DECIDE_BOX: return "DECIDE_BOX";
    case STATE_MOVE_TO_FRUIT: return "MOVE_TO_FRUIT";
    case STATE_CLOSE_CLAW: return "CLOSE_CLAW";
    case STATE_CHECK_GRIP: return "CHECK_GRIP";
    case STATE_MOVE_TO_BOX: return "MOVE_TO_BOX";
    case STATE_OPEN_CLAW: return "OPEN_CLAW";
    case STATE_RETURN_HOME: return "RETURN_HOME";
    case STATE_ERROR_STATE: return "ERROR_STATE";
    default: return "UNKNOWN";
    }
}
