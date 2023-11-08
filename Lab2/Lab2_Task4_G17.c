/*

  LAB2_TASK4_CO321
  GROUP_17 : E/19/244 , E/19/247 , E/19/249

 4.Connect two push buttons (A and B) to two external interrupt pins. Connect 6 LEDs to
   a GPIO port. Write a program where a user can input a binary number using the two
   push buttons (press A to input a '0', press B to input a '1') through external interrupts,
   and display that number using the LEDs. The number must be updated and displayed
   every time one of the buttons are pressed.
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	DDRD &= ~(1<<2) & ~(1<<3); // assigning PD2(INT0) and PD3(INT1) to be input
  	DDRB |= (1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0); // assigning 6LSBs of PORTB to be outputs..
  	  
  	// setting ISC bits 00 and 01 to generate interrupt for RISING EDGE detection for INT0..
    EICRA |= (1<<ISC01);
  	EICRA |= (1<<ISC00);
  
  	// setting ISC bits 10 and 11 to generate interrupt request for RISING EDGE detection of INT1..
   	EICRA |= (1<<ISC11);
  	EICRA |= (1<<ISC10);
   
  	// enabling GLOBAL interrupt..
  	sei();
  
  	// enabling external interrupt for INT0;
  	EIMSK |= (1<<INT0);
  	EIMSK |= (1<<INT1);
  
    while(1)
    {
      // Makes the program run forever...

    }
  
  	return 0;
  
}

// Interrupt Service routine for INT0;
// for bit 0

ISR(INT0_vect){
  	PORTB = PORTB << 1;   //just do a left shift..
}

// Interrupt Service routine for INT1;
// for bit 1

ISR(INT1_vect){
  	PORTB = PORTB << 1;  // do a left shift..
  	PORTB |= 1;			 // perform logical OR operation to add 1 as the lsb
}




