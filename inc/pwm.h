#ifndef PWM_H
#define PWM_H

#include "pico/stdlib.h"

void pwm_init_all(uint8_t pwm_pin, float clkdiv, uint16_t wrap);
void pwm_set_duty_cycle(uint8_t pwm_pin, uint duty_cycle);

#endif //PWM_H