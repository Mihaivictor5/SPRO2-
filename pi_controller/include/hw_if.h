#ifndef HW_IF_H
#define HW_IF_H

#include <stdbool.h>
#include <stdint.h>

bool hw_detect_fruit(void);
float hw_read_weight_grams(void);
bool hw_move_to_fruit(void);
bool hw_move_to_box(uint8_t box_id);
bool hw_move_home(void);
bool hw_claw_close(void);
bool hw_claw_open(void);
bool hw_claw_check_grip(void);

#endif
