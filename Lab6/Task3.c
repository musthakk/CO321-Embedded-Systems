
/*
 * CO321 => Lab6 Serial Communication
 * Group 17: 
 *  E/19/244, Hamshica M. 
 *  E/19/247, Musthak S.M.
 *  E/19/249, SMuthukumarana M.P.S.A.
 * 
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

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
    printf("data");
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
    
    char c;
    int encrypt = 0;
    char Sentence[100];
    int i = 0;
    while (1)
    {
        c = usart_receive();

        if (encrypt == 0)
        {
            if(c == '\r')
            {
                encrypt = 1;
            }else{
                Sentence[i] = c;
                i++;
            }   
        }
        

        if(encrypt == 1)
        {
            for (int j = 0; j<i; j++)
            {
                c = Sentence[j];

                if(c>='A' && c<='Z'){
                //apply caesar cipher encryption
                c=(char)(c - 'A' + 3) % 26 + 'A';
                }else if(c>='a' && c<='z'){
                    c=(char)(c - 'a' + 3) % 26 + 'a';           
                }
                usart_send(c); 
            }

            encrypt = 0;
            i = 0;
            usart_send('\n');
        }

        

        
    }
    
    return 0;

}   




