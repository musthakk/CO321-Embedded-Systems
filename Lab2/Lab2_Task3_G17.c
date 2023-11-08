
/*

   LAB2_TASK3_CO321
   GROUP_17 : E/19/244 , E/19/247 , E/19/249

   3. Extend the program in part 2, so that the number of times the push button was released
      is displayed as a binary number on a set of LEDs connected to PORTB.

    chosen Pins of PORTB => 6 LSBs of PORTb
    using external INTERRUPT 0 (INT0)
*/


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t count = 0;    //Assigning a variable to count the number of times the button is pressed

int main(void)
{
	DDRD &= ~(1<<2); // assigning PD2(INT0) to be input
  	DDRB = 0b00111111; // assigning 6LSBs of PORTB to be outputs..
  	  
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
  
  if(PORTB == 0b00111111){
    PORTB = 0b00000000;
  }

  count++;
  PORTB = count;      //According to the binary number the LEDs will light up


  
}

