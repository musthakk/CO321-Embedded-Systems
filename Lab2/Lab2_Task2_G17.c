
/*

   LAB2_TASK2_CO321
   GROUP_17 : E/19/244 , E/19/247 , E/19/249

   2. Write a program that toggles pin PB0 (show using a connected LED) whenever the push
	  button is released, using external interrupts

	  chosen Pin of PORTB => PB0
      using external INTERRUPT 0 (INT0)
*/

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRD &= ~(1<<2); // assigning PD2(INT0) to be input
    DDRB |= (1<<0); // assigning PB0 as OUTPUT..
  	
  
  	// setting ISC bits 00 and 01 to send for FALLING EDGE detection..
    EICRA |= (1<<ISC01);
  	EICRA &= ~(1<<ISC00);
  	
  	// enabling GLOBAL interrupt..
  	sei();
  
  	// enabling external interrupt for INT0;
  	EIMSK |= (1<<INT0);
  
    while(1)
    {
      // Makes the program run forever...
    }
  
  	return 0;
  
}

ISR(INT0_vect){
  	
  	PORTB = PORTB ^ (1<<0);     // toggling PB0;
  
}
