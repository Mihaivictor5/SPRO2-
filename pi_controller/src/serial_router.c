#include "serial_router.h"
#include "serial_if.h"
#include <stdio.h>

#ifndef SERIAL_ROUTER_USE_MOCK
#define SERIAL_ROUTER_USE_MOCK 1
#endif

static bool send_grbl_line(const char *line)
{
#if SERIAL_ROUTER_USE_MOCK
    printf("[MOCK][GRBL] %s\n", line);
    return true;
#else
    // TODO: Send line to GRBL USB serial and wait for "ok"/"error".
    return serial_send_grbl(line);
#endif
}

static bool send_claw_line(const char *line)
{
#if SERIAL_ROUTER_USE_MOCK
    printf("[MOCK][CLAW] %s\n", line);
    return true;
#else
    // TODO: Send line to claw-controller USB serial and parse ACK.
    return serial_send_claw(line);
#endif
}

bool serial_router_init(void)
{
#if SERIAL_ROUTER_USE_MOCK
    return true;
#else
    // TODO: Open and configure real serial ports here.
    return serial_init();
#endif
}

bool gantry_move_to(float x_mm, float y_mm)
{
    char cmd[64];
    (void)snprintf(cmd, sizeof(cmd), "G0 X%.2f Y%.2f", x_mm, y_mm);
    return send_grbl_line(cmd);
}

bool gantry_home(void)
{
    return send_grbl_line("$H");
}

bool claw_open(void)
{
    return send_claw_line("CLAW:OPEN");
}

bool claw_close(void)
{
    return send_claw_line("CLAW:CLOSE");
}

float claw_read_pressure(void)
{
#if SERIAL_ROUTER_USE_MOCK
    return 0.75f;
#else
    // TODO: Add claw pressure/status command and parse numeric response.
    return 0.0f;
#endif
}

bool fruit_sensor_detected(void)
{
#if SERIAL_ROUTER_USE_MOCK
    static int calls = 0;
    calls++;
    return (calls % 3) == 0;
#else
    // TODO: Read fruit-present signal from GPIO/vision input.
    return false;
#endif
}

float scale_read_weight_grams(void)
{
#if SERIAL_ROUTER_USE_MOCK
    return 120.0f;
#else
    // TODO: Read weight from load-cell ADC and return grams.
    return 0.0f;
#endif
}
