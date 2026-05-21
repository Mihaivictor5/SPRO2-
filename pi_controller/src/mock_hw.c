#include "hw_if.h"
#include <stdio.h>

bool hw_detect_fruit(void)
{
    static int calls = 0;
    calls++;
    // TODO: Replace with GPIO/vision trigger from real fruit sensor.
    return (calls % 3) == 0;
}

float hw_read_weight_grams(void)
{
    // TODO: Replace with HX711 (or equivalent) load-cell reading.
    return 120.0f;
}

bool hw_move_to_fruit(void)
{
    // TODO: Send G-code over USB serial to GRBL for fruit pickup position.
    return true;
}

bool hw_move_to_box(uint8_t box_id)
{
    (void)box_id;
    // TODO: Map box_id to XY coordinates and send move command to GRBL.
    return true;
}

bool hw_move_home(void)
{
    // TODO: Call GRBL homing / return-to-safe-home sequence.
    return true;
}

bool hw_claw_close(void)
{
    // TODO: Send claw close command to Seeeduino controller.
    return true;
}

bool hw_claw_open(void)
{
    // TODO: Send claw open command to Seeeduino controller.
    return true;
}

bool hw_claw_check_grip(void)
{
    // TODO: Read claw status sensor or controller feedback.
    return true;
}
