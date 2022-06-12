#include <avr/io.h>

#define LED_PORT 5

void led_write_mode() {
    DDRB |= 1 << LED_PORT;
}

void led_toggle() {
    PORTB ^= 1 << LED_PORT;
}