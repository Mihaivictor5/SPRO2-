#ifndef GRBL_CLIENT_H
#define GRBL_CLIENT_H

#include <stdbool.h>

bool grbl_send_gcode(const char *gcode_line);
bool grbl_home(void);
bool grbl_move_to(float x_mm, float y_mm);
bool grbl_get_status(char *out_status, unsigned int out_size);

#endif
