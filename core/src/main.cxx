/// @file main.cxx
/// @brief Main program starts here.
#include <libopencm3/stm32/gpio.h>
#include <FreeRTOS.h>
#include <task.h>
#include "common.h"
#include "PwmOut.h"
#include "main.h"



using namespace blclock;



void
led_task1(void* p)
{
  for (;;) {
    gpio_toggle(GPIOA, GPIO5);
    //gpio_toggle(GPIOC, GPIO13);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void
led_task2(void* p)
{
  blclock::PwmOut led_pb6(TIM3, TIM_OC1, ARR_TIM3_CH1) ;
  for (;;) {
    for(int i=0; i < 100; i+=1) {
      if(!is_ok(led_pb6.update(i)))
        panic();

      vTaskDelay(pdMS_TO_TICKS(10));
    }

    for(int i=100; i > 0; i-=1) {
      if(!is_ok(led_pb6.update(i)))
        panic();

      vTaskDelay(pdMS_TO_TICKS(10));
    }
  }
}



int
main() {
    if (!is_ok(rcc_setup()))
        panic();

    if (!is_ok(gpio_setup()))
        panic();

    if (!is_ok(timer_setup()))
        panic();

    xTaskCreate(led_task1, "led1", 100, NULL, configMAX_PRIORITIES-1, NULL);
    xTaskCreate(led_task2, "led2", 100, NULL, configMAX_PRIORITIES-1, NULL);
    vTaskStartScheduler();

    while (1) { }
}
