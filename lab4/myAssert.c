#include <stdio.h>
#include <stdint.h>
#include "FreeRTOS.h"

#include "hardware/gpio.h"
#include "pico/stdlib.h"

// Candidate for my assert Module
void 
_assert_failed (const char *assertion, const char *file, unsigned int line)
{
    const uint8_t LED_PIN = 25;

    // Not alot that we can do at the current time so simply blink the 
    // LED rapidly
    //
    // Normally an IO would display:
    //   Assertion failed: expression, file filename, line line number 
    printf("Assertion Failed: %s at %s::%d\n", assertion, file, line);
    
    // Denergize any outputs

    // if task mode disable context switching

    // Do I disable Interrupts?
    
    // Enable the GPIO port that is used for the on-board LED.
    //
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    
    // turn off the LED's
    //
    gpio_put(LED_PIN, 0);
    
    //
    // Loop forever.
    //
    const uint32_t assertLoopDelayMs = 50;
    while (true) 
    {
        gpio_put(LED_PIN, 1);
        sleep_ms(assertLoopDelayMs);
        gpio_put(LED_PIN, 0);
        sleep_ms(assertLoopDelayMs);
    }
}
               
               


               
               
               
