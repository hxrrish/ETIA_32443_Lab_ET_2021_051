#include <Arduino.h>

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Pin Mapping
    // D10 -> PB2  (System LED)
    // D9  -> PB1  (PIR Sensor Input)
    // D8  -> PB0  (Buzzer)
    // D7  -> PD7  (LED)

    // Configure Outputs
    DDRB |= (1 << PB2);   // PB2 output
    DDRB |= (1 << PB0);   // PB0 output
    DDRD |= (1 << PD7);   // PD7 output

    // Configure Input
    DDRB &= ~(1 << PB1);  // PB1 input

    while (1)
    {
        // System LED ON
        PORTB |= (1 << PB2);

        _delay_ms(1000);

        // Read PIR sensor
        if (PINB & (1 << PB1))
        {
            // Turn ON buzzer and LED
            PORTB |= (1 << PB0);
            PORTD |= (1 << PD7);

            _delay_ms(1000);
        }
        else
        {
            // Turn OFF buzzer and LED
            PORTB &= ~(1 << PB0);
            PORTD &= ~(1 << PD7);
        }

        // System LED OFF
        PORTB &= ~(1 << PB2);

        _delay_ms(1000);
    }
}