/*
  LAB2_TASK1_CO321
  GROUP_17 : E/19/244 , E/19/247 , E/19/249

 1. PD7 pin is connected to a push button. Write a program that uses 6 LEDs connected to
    PORTB (6 LSBs) to display the number of times the push button is pressed, as a binary
    number. Implement without using external interrupts. (i.e. Use polling)
*/

#include <avr/io.h>

uint8_t count = 0;    //Assigning a variable to calculate the number of times the button is pressed

int main(void)
{
	DDRD &= ~(1<<7); // assigning PD7 to be input
  DDRB |= (1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0); // assigning 6LSBs of PORTB to be outputs..
    
  uint8_t previous = 0; //Assigning a variable to indicate the previous state of the button
  while(1)
  {
    uint8_t currentState = PIND & (1<<7);    
    if(currentState == 0 && previous != 0)   // check whether button is pressed (button's state change)..=> i.e: PD7 == 1 to PD7 == 0
    {
      ++count;            
      PORTB = count;			// lit up LEDs in the binary increasing manner..
    }
    
    previous = currentState;    //Setting the current state of the LEDs as the previous state
    
  }

  return 0;
  
}