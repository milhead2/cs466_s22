/**
 * @brief CS466 Lab1 Blink proigram based on pico blink example
 * 
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>

#include "pico/stdlib.h"

const uint8_t LED_PIN = 25;

void hardware_init(void)
{
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void heartbeat()
{   
    const uint32_t heartbeatDelay = 500;  // ms

    while (true) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(heartbeatDelay);
        gpio_put(LED_PIN, 0);
        vTaskDelay(heartbeatDelay);
    }
}

int main()
{
    stdio_init_all();
    hardware_init();

    xTaskCreate(heartbeat, "LED_Task", 256, NULL, 1, NULL);

    vTaskStartScheduler();

    while(1){};
}