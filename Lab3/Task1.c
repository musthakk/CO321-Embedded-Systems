
#include <avr/io.h>

void delay_timer0(){

    TCNT0 = 131; // set initial value of timer register to 131

    TCCR0A = 0x00;  // set timer0 to normal mode.
    TCCR0B = 0x04;  // set prescale to 1/256... (set the prescale 1/1024 to see the blink clearly..)

    while((TIFR0 & 0x01) == 0);  // wait until timer overflow bit (TOV0) is set..

    // clear timer settings.. (this stops the timer..)
    TCCR0A = 0x00;
    TCCR0B = 0x00;

    TIFR0 = 0x01;  // clear the timer overflow bit (TOV0) for next round..
}

int main(void)
{

    DDRB |= (1<<5); // set pin5(PB5) of port PORTB regesiter to output.

    while(1)
    {
        PORTB ^= (1<<5);   // toggle PB5 of PORTB
        delay_timer0();
    }
    return 0;
}