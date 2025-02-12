#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include <stdlib.h>
#include "inc/pwm.h"

#define SERVO_PIN 12
#define PWM_CLKDIV 100.0
#define PWM_WRAP 25000

const uint dc_max = PWM_WRAP*0.12; // duty cycle de 12%
const uint dc_min = PWM_WRAP*0.025; // duty cycle de 2.5%
const uint step = PWM_WRAP*0.00025; // step de incremento de 5us no ciclo ativo

int main()
{
    bool is_up = true;
    uint dc = 0;

    pwm_init_all(SERVO_PIN, PWM_CLKDIV, PWM_WRAP);

    pwm_set_duty_cycle(SERVO_PIN, dc_max); // duty cycle no limite superior
    sleep_ms(5000);
    pwm_set_duty_cycle(SERVO_PIN, PWM_WRAP*0.0735); // duty cycle em valor intermediário
    sleep_ms(5000);
    pwm_set_duty_cycle(SERVO_PIN, dc_min); // duty cycle no limite inferior
    sleep_ms(5000);
    dc = dc_min;
    while(true)
    {
        if (is_up){
            dc += step;
            if (dc >= dc_max) is_up = false;
        }
        else {
            dc -= step;
            if (dc <= dc_min) is_up = true;
        }
        pwm_set_duty_cycle(SERVO_PIN, dc); // muda duty cycle do pwm
        sleep_ms(10);
    }
    return EXIT_SUCCESS;
}