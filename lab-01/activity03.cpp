#define F_CPU 16000000UL
#include <avr/io.h>
int main(void) {
// Set PB0 as output for the LED
DDRB = DDRB | (1 << PB0);
// Set PD2 as input for the PIR sensor
DDRD = DDRD & ~(1 << PD2);
while (1) {
// Check if motion is detected on PD2
if (PIND & (1 << PD2)) {
PORTB = PORTB | (1 << PB0); // Turn LED ON
} else {
PORTB = PORTB & ~(1 << PB0); // Turn LED OFF
}
}
return 0;
}