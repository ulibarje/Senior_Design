
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "math.h"
#include "uart_functions.h"

#define ON  1
#define OFF 0
#define TIRE_DIAM       22
#define SPROCKET_TEETH  42
#define SPEED1_RELAY    4
#define SPEED2_RELAY    5
#define PC_RELAY        6
#define PIRATE_SWITCH   7

//Global Variables
double tire_circ;
double distance_per_pulse;

uint16_t timestamps[16];

/*** Turn ON to enable datalogging ***/
uint8_t datalogging = ON;


/********************************************************
 * Name: system_init
 *
 * Description: Function takes care of all initializations.
 *  Timers, interrupts, UART, datalogging, ADC, IO
 * ******************************************************/
void system_init() {
 
    /******** ICP1 *********/

    //Makes use of the input capture function on PORTD.4.
    TCCR1A = 0x00;                          //Normal mode, no compare
    TCCR1B |= (1 << ICES1) | (1 << CS12);   //Input capture on rising edge,
                                            //256 clk prescale
    TIMSK |= (1 << TICIE1);                 //Enable input capture interrupt

    /******** ICP3 *********/
    //Makes use of the input capture function on PORTE.7.
    TCCR3A = 0x00;                          //Normal mode, no compare
    TCCR3B |= (1 << ICES3) | (1 << CS32);   //Input capture on rising edge,
                                            //256 clk prescale
    ETIMSK |= (1 << TICIE3);                 //Enable input capture interrupt

    /******** Enable Global Interrupts *********/
    sei();

    /******** IO *********/
    DDRB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Output for relay circuits
    DDRB |= (1<<PIRATE_SWITCH);     //Pirate mode enable on PORTD.0 (INT0)
    PORTB |= (1<<SPEED1_RELAY)|(1<<SPEED2_RELAY)|(1<<PC_RELAY); //Turn on relay circuits
    PORTB |= (1<<PIRATE_SWITCH);     //Set high

    /******** System Timer *********/
    //Timer will run on the 32kHz oscillator to allow for a slower speed
    //Normal mode, 32,768Hz with 8 pre-scale = 16Hz = 62.5mS

    // Follow procedures in the datasheet to select the external clock.
    TIMSK &= ~((1 << OCIE0) | (1 << TOIE0)); //clear interrupts
    ASSR |= (1 << AS0);                      //enable external clock
    TCCR0 = (0 << WGM01) | (0 << WGM00) | \
            (0 << CS01) | (1 << CS00);      //Normal mode, 8 prescale
    while(!((ASSR & 0b0111) == 0)) {}       //spin till registers finish updating
   
    ///*** Calculate the system needed constants ***/
    uint8_t j;
    tire_circ = TIRE_DIAM * M_PI;
    distance_per_pulse = tire_circ / SPROCKET_TEETH;

    for(j = 0; j < 9; j++) {
        timestamps[j] = 0;
    }

    /****** Datalogging *******/
    if(datalogging) { 

        //Set SS, MOSI, SCK as output
        DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
        //Configure SPI (Slave mode, clk low on idle, rising edge sample)
        SPCR = (1<<SPE)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR1)|(0<<SPR0);
        SPSR = (1<<SPI2X);

    }//if datalogging
    
    /******** ADC *********/
    //Initalize ADC and the ports
    DDRF &= ~(1<<PF1);  //Port F bit 1 is ADC input
    PORTF &= ~(1<<PF1); //Port F bit 1 pull up has to be off

    ADMUX = (0<<REFS1)|(1<<REFS0)|(1<<MUX0);    //Single ended input, Port F bit 0, 
                                                //right adjusted, 10 bit
    //ADC enabled, One shot mode, ADC complete interrupt enabled, clk prescalar 128 (125khz)
    ADCSRA = (1<<ADEN)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

    /****** UART0 *******/
    //uart_init();
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      //Enable TX, RX
    UCSR0C |= (0<<UMSEL0)|(0<<USBS0)|(1<<UCSZ00)|(1<<UCSZ01);   //Async, no parity, 1 stop bit
                                                                // 8-bit char size
    UBRR0H = (51 >> 8);     //set baudrate to 38.4k
    UBRR0L = 51;

    /****** UART2 *******/
    uart1_init();
/*    UCSR1B |= (1 << RXEN1) | (1 << TXEN1);      //Enable TX, RX
    UCSR1C |= (0<<UMSEL1)|(0<<USBS1)|(1<<UCSZ10)|(1<<UCSZ11);   //Async, no parity, 1 stop bit
                                                                // 8-bit char size
    UBRR1H = (51 >> 8);      //set baudrate to 38.4k
    UBRR1L = 51;
*/  
    
    /****** For Block Checkoff *******/
    
    //Send a value via UART
    uint8_t i;
    char characters[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(i = 0; i < 10; i++) {
        uart1_putc(characters[i]);
        _delay_ms(1000);
    }

    //*********** Send SPI Data **********
    //Send a value to the bar graph via SPI
    DDRF = (1 << PF6) | (1 << PF5);  //set data direction for bar graph poke

    _delay_ms(500);
    for(i = 1; i < 11; i++) {
        SPDR = i;
        while(bit_is_clear(SPSR, SPIF)) {} // wait until data is sent
        //********** Bar Graph Portion *******************
        PORTF |= (1 << PF6);      // move graph data from shift to storage reg.
        PORTF &= ~(1 << PF6);     // change 3-state back to high Z
        _delay_ms(1000);
    }

    /******************** End Testing **************************/


}//system_init


int main() {

DDRB |= (1 << PB7);

/****** System Timing *******/
DDRA |= (1 << PA0);                  //for timing requirement 
PORTA |= (1 << PA0);                 //begin timing

system_init();

PORTA &= ~(1 << PA0);   //end timing test

while(1) {
PORTB ^= (1 << PB7);
_delay_ms(1000);
}

return 0;
}//main
