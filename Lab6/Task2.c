
/*
 * CO321 => Lab6 Serial Communication
 * Task 2
 * Group 17: 
 *  E/19/244, Hamshica M. 
 *  E/19/247, Musthak S.M.
 *  E/19/249, SMuthukumarana M.P.S.A.
 * 
*/

#include <avr/io.h>
#include <util/delay.h>

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


void USART_Init( unsigned int ubrr)
{
    /*Set baud rate */
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    // Enable receiver and transmitter 
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C |= (3<<UCSZ00);   // (3<<UCSZ00) = (1<<UCSZ01) | (1<UCSZ00)
    UCSR0C &= ~(1<<USBS0);
}

void usart_send( unsigned char data )
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)))
    ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
}


unsigned char usart_receive( void )
{
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) )
    ;
    /* Get and return received data from buffer */
    return UDR0;
}

int main(void)
{
    USART_Init(MYUBRR);
    
    // Group 17
    char Hamsicha[] = "E/19/244 ";
    char Musthak[] = "E/19/247 ";
    char Sayumi[] = "E/19/249 ";

    char ch;
    

    for(int i = 0; Hamsicha[i] != '\0'; i++)
    {
        ch = Hamsicha[i];
        usart_send(ch);
        _delay_ms(10);
    }

    for(int i = 0; Musthak[i] != '\0'; i++)
    {
        ch = Musthak[i];
        usart_send(ch);
        _delay_ms(10);
    }

    for(int i = 0; Sayumi[i] != '\0'; i++)
    {
        ch = Sayumi[i];
        usart_send(ch);
        _delay_ms(10);
    }

    

}   




