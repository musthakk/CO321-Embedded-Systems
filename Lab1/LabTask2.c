#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY 200

int main(void)
{
  DDRB = DDRB | (0x0F);	    // define output pins of PORT B
  
  unsigned char temp = 0;   // variable to indicate the reverse instance of lighting..
  
  PORTB = 0x01;             // lit up first led
  
  while(1)
  {
    if (!temp)
    {
		PORTB = PORTB << 1;             // lit up leds in the order of ABCD
      	_delay_ms(BLINK_DELAY);         // delay
      	
      	if (PORTB & 1<<3)
          temp = 1;                     // when we reach led D, set the temp variable to reverse..
      
    }else{
      
      PORTB = PORTB >> 1;               // lit up leds in the order of DCBA
      _delay_ms(BLINK_DELAY);           // delay

      if (PORTB & 1)
        temp = 0;                       // when we reach the led A, set the temp variable to reverse the order.
      
    }
    
    
    
  }
  return 0;
  
}