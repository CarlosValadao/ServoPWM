#include "pwm.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

void pwm_init_all(uint8_t pwm_pin, float clkdiv, uint16_t wrap)
{
    gpio_set_function(pwm_pin, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(pwm_pin);
    pwm_set_clkdiv(pwm_pin, clkdiv);
    pwm_set_wrap(pwm_pin, wrap);
    pwm_set_enabled(slice, true);
    pwm_gpio_set_level(pwm_pin, 0);
}

void pwm_set_duty_cycle(uint8_t pwm_pin, uint duty_cycle)
{
    return; //TO DO
}