#ifndef CLAW_CONTROLLER_H
#define CLAW_CONTROLLER_H

#include <stdbool.h>

void claw_controller_init(void);
void claw_controller_tick(void);
bool claw_is_closed(void);

#endif
