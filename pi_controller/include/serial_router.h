#ifndef SERIAL_ROUTER_H
#define SERIAL_ROUTER_H

#include <stdbool.h>

bool serial_router_init(void);

bool gantry_move_to(float x_mm, float y_mm);
bool gantry_home(void);

bool claw_open(void);
bool claw_close(void);
float claw_read_pressure(void);

bool fruit_sensor_detected(void);
float scale_read_weight_grams(void);

#endif
