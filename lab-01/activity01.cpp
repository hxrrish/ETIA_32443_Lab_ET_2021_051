#include <Arduino.h>
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void) {
// Configure PB0 as an output pin
DDRB = DDRB | (1 << PB0);
while (1) {
PORTB = PORTB | (1 << PB0); // Turn LED ON
_delay_ms(1000); // Wait 1 second
PORTB = PORTB & ~(1 << PB0); // Turn LED OFF
_delay_ms(1000); // Wait 1 second
}
return 0;
}