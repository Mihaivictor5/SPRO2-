#include "serial_if.h"
#include <stdio.h>

bool serial_init(void)
{
    // TODO: Open and configure /dev/ttyUSB* devices for GRBL and claw board.
    return true;
}

bool serial_send_grbl(const char *line)
{
    // TODO: Write to GRBL serial port and wait for "ok"/"error".
    printf("[GRBL] %s\n", line);
    return true;
}

bool serial_send_claw(const char *line)
{
    // TODO: Write to claw-controller serial port and parse ACK lines.
    printf("[CLAW] %s\n", line);
    return true;
}

bool serial_read_line(char *buffer, size_t buffer_size)
{
    (void)buffer;
    (void)buffer_size;
    // TODO: Implement non-blocking line reader for USB serial channels.
    return false;
}
