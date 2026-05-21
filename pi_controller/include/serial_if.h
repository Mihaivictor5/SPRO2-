#ifndef SERIAL_IF_H
#define SERIAL_IF_H

#include <stdbool.h>
#include <stddef.h>

bool serial_init(void);
bool serial_send_grbl(const char *line);
bool serial_send_claw(const char *line);
bool serial_read_line(char *buffer, size_t buffer_size);

#endif
