#include <Arduino.h>
#include "claw_controller.h"

static bool g_is_closed = false;

void claw_controller_init(void)
{
    Serial.begin(115200);
    while (!Serial)
    {
    }
    g_is_closed = false;
}

void claw_controller_tick(void)
{
    if (!Serial.available())
    {
        return;
    }

    String line = Serial.readStringUntil('\n');
    line.trim();

    if (line == "CLAW:CLOSE")
    {
        // TODO: Drive physical claw actuator to close.
        g_is_closed = true;
        Serial.println("ACK:CLAW:CLOSED");
        return;
    }

    if (line == "CLAW:OPEN")
    {
        // TODO: Drive physical claw actuator to open.
        g_is_closed = false;
        Serial.println("ACK:CLAW:OPENED");
        return;
    }

    if (line == "CLAW:STATUS?")
    {
        Serial.println(g_is_closed ? "STATUS:CLOSED" : "STATUS:OPEN");
        return;
    }

    Serial.println("ERR:UNKNOWN_CMD");
}

bool claw_is_closed(void)
{
    return g_is_closed;
}

void setup()
{
    claw_controller_init();
}

void loop()
{
    claw_controller_tick();
    delay(5);
}
