#ifndef FSM_H
#define FSM_H

#include "app_context.h"

typedef enum
{
    STATE_IDLE = 0,
    STATE_WAIT_FOR_FRUIT,
    STATE_READ_WEIGHT,
    STATE_DECIDE_BOX,
    STATE_MOVE_TO_FRUIT,
    STATE_CLOSE_CLAW,
    STATE_CHECK_GRIP,
    STATE_MOVE_TO_BOX,
    STATE_OPEN_CLAW,
    STATE_RETURN_HOME,
    STATE_ERROR_STATE
} robot_state_t;

typedef struct
{
    robot_state_t current;
    robot_state_t previous;
} fsm_t;

void fsm_init(fsm_t *fsm);
void fsm_step(fsm_t *fsm, app_context_t *ctx);
const char *fsm_state_to_string(robot_state_t state);

#endif
