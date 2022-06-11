#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

#define BLINK_DELAY_MS 300

int main(void)
{
    led_write_mode();
    while (1)
    {
        led_on();
        _delay_ms(BLINK_DELAY_MS);
        led_off();
        _delay_ms(BLINK_DELAY_MS);
    }
}