/**
 * @brief CS466 Lab1 Blink proigram based on pico blink example
 * 
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

#include "hardware/gpio.h"
#include "pico/stdlib.h"

const uint8_t LED_PIN = 25;
const uint8_t SW1_PIN = 17;

uint32_t heartbeatDelay = 500;  // ms

//static SemaphoreHandle_t _semBtn = NULL;

void gpio_int_callback(uint gpio, uint32_t events_unused) 
{
    printf("sw1_callback: GPIO ISR %d\n", gpio);

    if (gpio == SW1_PIN)
    {
        heartbeatDelay /= 2;
        //xSemaphoreGiveFromISR(_semBtn, NULL);
    }

    if (heartbeatDelay < 50)
        heartbeatDelay = 500;
}

void hardware_init(void)
{
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(SW1_PIN);
    gpio_pull_up(SW1_PIN);
    gpio_set_dir(SW1_PIN, GPIO_IN);
    gpio_set_irq_enabled_with_callback(SW1_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_int_callback);
}

#if 0
void sw1_handler(void * notUsed)
{
    while (true)
    {
        xSemaphoreTake( _semBtn, portMAX_DELAY);
        printf("sw1 Semaphore taken..\n");
    }
}
#endif

void heartbeat(void * notUsed)
{   
    while (true) {
        printf("hb-tick: %d\n", heartbeatDelay);
        gpio_put(LED_PIN, 1);
        vTaskDelay(heartbeatDelay);
        gpio_put(LED_PIN, 0);
        vTaskDelay(heartbeatDelay);
    }
}

int main()
{
    stdio_init_all();
    printf("lab2 Hello!\n");
    hardware_init();

    //_semBtn = xSemaphoreCreateBinary();

    xTaskCreate(heartbeat, "LED_Task", 256, NULL, 1, NULL);
    //xTaskCreate(sw1_handler, "SW1_Task", 256, NULL, 2, NULL);

    vTaskStartScheduler();

    while(1){};
}