#include "grbl_client.h"
#include <stdio.h>
#include <string.h>

#ifndef GRBL_CLIENT_USE_MOCK
#define GRBL_CLIENT_USE_MOCK 1
#endif

bool grbl_send_gcode(const char *gcode_line)
{
    if (gcode_line == NULL)
    {
        return false;
    }

#if GRBL_CLIENT_USE_MOCK
    printf("[MOCK][GRBL] %s\n", gcode_line);
    return true;
#else
    // TODO: Send gcode_line to GRBL serial port and wait for "ok"/"error".
    return false;
#endif
}

bool grbl_home(void)
{
    return grbl_send_gcode("$H");
}

bool grbl_move_to(float x_mm, float y_mm)
{
    char line[64];
    (void)snprintf(line, sizeof(line), "G0 X%.2f Y%.2f", x_mm, y_mm);
    return grbl_send_gcode(line);
}

bool grbl_get_status(char *out_status, unsigned int out_size)
{
    if (out_status == NULL || out_size == 0U)
    {
        return false;
    }

#if GRBL_CLIENT_USE_MOCK
    (void)snprintf(out_status, out_size, "<Idle|MPos:0.000,0.000,0.000>");
    return true;
#else
    // TODO: Send "?" to GRBL serial port and copy status response into out_status.
    (void)memset(out_status, 0, out_size);
    return false;
#endif
}
