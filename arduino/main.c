#include <avr/io.h>
#include <util/delay_basic.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <Arduino.h>

#include "led.h"

#define BLINK_DELAY_MS 300
#define MIN_PULSE_WIDTH 544
#define MAX_PULSE_WIDTH 2400
#define DEFAULT_PULSE_WIDTH 1500
#define REFRESH_INTERVAL 20000

void delay(uint16_t us)
{
    uint16_t runs = us / 244;
    uint16_t res = us % 244;
    uint16_t i = 0;
    while (i < runs)
    {
        // one run is 16mhz / 65536 = 244 us
        _delay_loop_2((uint16_t)65536);
        i += 1;
    }
    _delay_loop_2((uint16_t)res * (uint16_t)16);
}

void pulse(int width)
{
    // set it to 1
    // PIND |= 1 << PIND1;
    led_toggle();
    delay(width);
    // set it to 0
    // PIND &= 0 << PIND1;
    led_toggle();
    // delay(width);
    // delay(REFRESH_INTERVAL);
}

int main(void)
{
    DDRD |= 1 << PIND1;
    led_write_mode();
    for (int x = 0; x < 5; x++)
    {
        for (int i = 0; i < 50; i++)
        {
            // led_toggle();
            // delay((uint16_t)65536);
            // pulse(DEFAULT_PULSE_WIDTH);
            led_toggle();
            _delay_us(MAX_PULSE_WIDTH);
            led_toggle();
            _delay_us(REFRESH_INTERVAL);
        }
        _delay_us(REFRESH_INTERVAL);
        for (int i = 0; i < 50; i++)
        {
            // led_toggle();
            // delay((uint16_t)65536);
            // pulse(DEFAULT_PULSE_WIDTH);
            led_toggle();
            _delay_us(MIN_PULSE_WIDTH);
            led_toggle();
            _delay_us(REFRESH_INTERVAL);
        }
        _delay_us(REFRESH_INTERVAL);
    }
    // // the number of pulses that i am going to send
    // int pulse_width = 1;
    // // 10k then decrease both max pulse width and step by order of 10 until somethign shows
    // int pulse_width_step = 1000;
    // // always send 100 pulses
    // int number_of_pulses = 0;
    // while (pulse_width < 10000) {
    //     if (number_of_pulses == 100) {
    //         number_of_pulses = 0;
    //         pulse_width += pulse_width_step;
    //         led_toggle();
    //     }

    //     _delay_us(pulse_width);
    //     PIND ^= 1 << PIND0;
    //     number_of_pulses +=1 ;
    // }
}