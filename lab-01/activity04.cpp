#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void) {
// Configure PB2 as output
DDRB = DDRB | (1 << PB2);
while (1) {
// Toggling PB0 incorrectly while PB2 is set as output
PORTB = PORTB | (1 << PB0); // ON
_delay_ms(1000);
PORTB = PORTB & ~(1 << PB0); // OFF
_delay_ms(1000);
}
return 0;
}