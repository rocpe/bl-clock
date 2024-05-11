#pragma once

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <expected>
#include "common.h"
#include "ErrorKind.h"



auto
rcc_setup() -> std::expected<Ok_t, ErrorKind>
{
    // Use 8Mhz quartz to create 72Mhz
    //rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);
    rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_48MHZ]);

    Ok_t ok; return ok;
}

auto
gpio_setup() -> std::expected<Ok_t, ErrorKind>
{
    // Enable clock GPIOA/C
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOC);

    // Configure GPIO5/13
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO5);
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

    Ok_t ok; return ok;
}

auto
timer_setup() -> std::expected<Ok_t, ErrorKind>
{
    //PB6 is on timer 3, channel 1
    // Enable clock for PB6
    rcc_periph_clock_enable(RCC_TIM3);
    rcc_periph_clock_enable(RCC_AFIO);

    // Set alternate mode for channel 1 of timer 3 (PB6)
    gpio_set_mode(GPIOA,
        GPIO_MODE_OUTPUT_50_MHZ,
        GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
        GPIO_TIM3_CH1);
        //GPIO6);


    // Set timer 3 mode
    timer_set_mode(TIM3,
        TIM_CR1_CKD_CK_INT, // don't divide
        TIM_CR1_CMS_EDGE, // aligment doesnt matter here
        TIM_CR1_DIR_UP // counting upwards
        );


    // Set channel 1 of timer 3 to pwm
    timer_set_oc_mode(TIM3,
        TIM_OC1, // for channel 1 so it is pa6
        TIM_OCM_PWM1
        );

    // Enable timer 3 on channel 1
    timer_enable_counter(TIM3);
    timer_enable_oc_output(TIM3,
        TIM_OC1
        );

    //in_freq = 48_000_000 hz
    //freq = in_freq  / (prescaler-1) + (arr-1)
    // Set freq for channel 1 of timer 3 to 50 Hz
    timer_set_prescaler(TIM3,
        PS_TIM3_CH1 - 1
        );
    timer_set_period(TIM3,
        ARR_TIM3_CH1 - 1
        );


    Ok_t ok; return ok;
}
