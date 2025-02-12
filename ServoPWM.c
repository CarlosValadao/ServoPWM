#include "pico/stdlib.h"   // Biblioteca padrão do Raspberry Pi Pico
#include "hardware/clocks.h"  // Biblioteca para controle de clocks
#include <stdlib.h>  // Biblioteca para funções de utilitários gerais (como EXIT_SUCCESS)
#include "inc/pwm.h"  // Arquivo de cabeçalho que contém funções para controle de PWM

// Define o pino que vai controlar o servo motor
#define SERVO_PIN 22

// Define o divisor de clock do PWM (quanto maior, menor a frequência do PWM)
#define PWM_CLKDIV 100.0

// Define o valor de "wrap", que afeta a frequência do PWM (quanto maior, menor a frequência)
#define PWM_WRAP 25000

// Define o duty cycle máximo (12% do valor do wrap)
const uint dc_max = PWM_WRAP * 0.12; // duty cycle de 12%

// Define o duty cycle mínimo (2.5% do valor do wrap)
const uint dc_min = PWM_WRAP * 0.025; // duty cycle de 2.5%

// Define o passo de incremento para o duty cycle, que será de 5 microssegundos
const uint step = PWM_WRAP * 0.00025; // step de incremento de 5us no ciclo ativo

int main()
{
    bool is_up = true;  // Flag para saber se o duty cycle deve aumentar ou diminuir
    uint dc = 0;  // Inicializa a variável do duty cycle com 0

    // Inicializa o PWM para o pino do servo motor com os parâmetros de divisor de clock e wrap
    pwm_init_all(SERVO_PIN, PWM_CLKDIV, PWM_WRAP);

    // Define o duty cycle do PWM para o valor máximo (12% do wrap)
    pwm_set_duty_cycle(SERVO_PIN, dc_max); 
    sleep_ms(5000);  // Espera 5 segundos

    // Define o duty cycle do PWM para um valor intermediário (7.35% do wrap)
    pwm_set_duty_cycle(SERVO_PIN, PWM_WRAP * 0.0735); 
    sleep_ms(5000);  // Espera 5 segundos

    // Define o duty cycle do PWM para o valor mínimo (2.5% do wrap)
    pwm_set_duty_cycle(SERVO_PIN, dc_min); 
    sleep_ms(5000);  // Espera 5 segundos

    // Inicializa a variável `dc` com o valor mínimo de duty cycle
    dc = dc_min;

    // Inicia um loop infinito para alterar dinamicamente o duty cycle
    while(true)
    {
        // Se a flag `is_up` for verdadeira, aumenta o duty cycle
        if (is_up){
            dc += step;  // Incrementa o duty cycle pelo valor de step
            if (dc >= dc_max)  // Se atingir o valor máximo, muda a flag para falso
                is_up = false;
        }
        else {
            // Se a flag `is_up` for falsa, diminui o duty cycle
            dc -= step;  // Decrementa o duty cycle pelo valor de step
            if (dc <= dc_min)  // Se atingir o valor mínimo, muda a flag para verdadeiro
                is_up = true;
        }

        // Atualiza o duty cycle do PWM com o novo valor calculado
        pwm_set_duty_cycle(SERVO_PIN, dc); 

        // Aguarda 10 milissegundos antes de atualizar novamente
        sleep_ms(10);
    }

    return EXIT_SUCCESS;  // Retorna sucesso ao sistema operacional
}
