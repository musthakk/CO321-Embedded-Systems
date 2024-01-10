#include <avr/io.h>

int main(void)
{
    DDRD |= (1 << PD6); // Set PD1 as an output (pin for PWM output)

    TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // Set Timer/Counter 0 for Fast PWM mode
    TCCR0B = (1 << CS01) | (1 << CS00); // Set Timer/Counter 0 with a prescaler of 64

    OCR0A = 127; // Set the initial PWM duty cycle value (0 to 255)

    while (1);

    return 0;
  
}
