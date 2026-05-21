#ifndef APP_CONTEXT_H
#define APP_CONTEXT_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    float weight_grams;
    uint8_t target_box_id;
    bool fruit_detected;
    bool grip_ok;
    bool error_flag;
    uint32_t error_code;
} app_context_t;

#endif
