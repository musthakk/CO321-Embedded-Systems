#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000

int main(void){
  
  DDRB = DDRB | 0x0F; // confingure pins 0,1,2,3 of portB to output
  
  while(1)
  {
    PORTB = PORTB | 0x0F; // setting pins 0,1,2,3 of portB to HIGH
    _delay_ms(BLINK_DELAY_MS);
    PORTB = ~PORTB; // setting pins 0,1,2,3 of portB to LOW
    _delay_ms(BLINK_DELAY_MS);
    
  }
  
  return 0; 
}