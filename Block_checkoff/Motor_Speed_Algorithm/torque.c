/************************************************************
 * Author: Shane Licari
 * Date: 2/14/17
 *
 * Description: This program will calculate a motor torque
 *  based off of a steering angle while ramping the torque
 *  at a certain rate.
 *  ********************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include <avr/sleep.h>
#include <math.h>
#include "hd44780.h"

#define nop_a5  0x00
#define rd_pos  0x10
#define speed1_relay 4      //Port C Pin 0
#define speed2_relay 5      //Port C Pin 1
#define pc_relay 6          //Port C pin 2
#define pirate_switch 0     //Port D Pin 0
#define BAUD 9600           //USART Baud Rate
#define FOSC 16000000
#define MYUBBR FOSC/16/BAUD-1
//Global Variables
float torque_right = 0.0;
float torque_left = 0.0;
uint16_t steering_angle;

struct int_frac{
    uint16_t integer;
    uint16_t fraction;
};

    struct int_frac TR;
    struct int_frac TL;
    uint8_t data_array[10];

/****************************************************************
 * Name: timer1_init
 *
 * Description:
 ****************************************************************/
void timer1_init(){
    //Initialize 16 bit Timer/Counter 1 for Fast PWM
    TCCR1A |= (1<<WGM11)|(1<<WGM10);
    TCCR1B |= (1<<WGM13)|(1<<WGM12);
    
    //Set Prescalar to 64
    TCCR1B |= (1<<CS11)|(1<<CS10);

    //Set Output Comare Match A Value
    OCR1A = 24999; 

    //Configure Timer/Counter 1 Output Compare Match A Interrupt
    TIMSK |= (1<<TOIE1);

}//timer1_init


/****************************************************************
 * Name: spi_encoder_init
 *
 * Description: This function configures the SPI protocol for
 * using the steering sensor.
 ****************************************************************/
void spi_encoder_init(){

    //Set data direction for SPI and set pullup for MISO
    DDRB |= (1<<PB0)|(1<<PB1)|(1<<PB2)|(0<<PB3);
    PORTB |= (1<<PB3); //MISO line
    

    //Enable SPI, shift LSB first, mast mode, clk low on idle,
    //data sampled on rising edge, clk/16 = 1MHz datarate
    SPCR = (1<<SPE)|(0<<DORD)|(1<<MSTR)|(0<<CPOL)|(0<<CPHA)|(1<<SPR0);
}//spi_encoder_init

/****************************************************************
 * Name: spi_init
 *
 * Description: 
 ****************************************************************/
void spi_init(void){
    DDRB = DDRB | 0x07;         //Turn on SS, MOSI, SCLK pins
    SPCR = (1<<SPE)|(1<<MSTR);  //Set up SPI mode
    SPSR = (1<<SPI2X);          //Run at Double Speed
}//spi_init

/****************************************************************
 * Name: spi_float_to_int
 *
 * Description: 
 ****************************************************************/
void spi_float_to_int(struct int_frac *value, float number){
    //uint16_t result;
    value->integer = (uint16_t)number;
    value->fraction = 1000 * (number - value->integer);
    
    //result = (integer_part<<8);//|(fraction_part);
    //return value;
}

/****************************************************************
 * Name: get_angle
 *
 * Description: 
 ****************************************************************/
uint16_t get_angle(){

    uint8_t high_byte;
    uint8_t low_byte;
    uint16_t angle;
    uint8_t i;

    spi_encoder_init();

    PORTD &= ~(1<<PD0); //Set Select Line Low
    SPDR = rd_pos;      //Send get position command
    while(bit_is_clear(SPSR, SPIF)){} //Wait for SPI transmission
    PORTD |= (1<<PD0);  //Set Select Line High
    _delay_us(20);

    //Wait for Encoder Ready Response
    while(SPDR != rd_pos){
    
        PORTD &= ~(1<<PD0);     //Set Select Line Low
        SPDR = nop_a5;          //Send no-op
        while(bit_is_clear(SPSR, SPIF)){}
        PORTD |= (1<<PD0);      //Set Select Line High
        _delay_us(20);          //Wait
        if(i == 10) {
            PORTA |= (1<<PA1);
            PORTD &= ~(1<<PD0);     //set select line low
            SPDR = rd_pos;          //send get position command
            while(bit_is_clear(SPSR, SPIF)) {}
            PORTD |= (1<<PD0);      //set select line high
            PORTA &= ~(1<<PA1);
            _delay_us(20);
        }//if
    i++;

    }//while

    //Encoder is ready, read the upper byte (top 4 bits of the 12 total)
    PORTD &= ~(1<<PD0);     //Set Select Line Low
    SPDR = nop_a5;          //Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to be Received
    PORTD |= (1<<PD0);      //Set Select Line High
    high_byte = SPDR;       //Store Position
    _delay_us(20);          //Wait

    PORTD &= ~(1<<PD0);     //Set Select Line Low
    SPDR = nop_a5;           //Send no-op
    while(bit_is_clear(SPSR, SPIF)){}   //Wait for Position to Be received
    PORTD |= (1<<PD0);      //Set Select Line High
    low_byte = SPDR;

    angle = (high_byte<<8)|(low_byte);
    spi_init();
    return angle;
}//get_angle



/****************************************************************
 * Name: motor_torque
 *
 * Description: 
 ****************************************************************/
void motor_torque(float* torque_right, float* torque_left, uint16_t* steer_angle){
    
    uint16_t angle;
    float torque_ratio;
    static float general_torque;
    general_torque = general_torque + 0.1;
    static uint8_t max_torque = 25;
   
    uint8_t user_mode = PIND | 0x7F;

    angle = get_angle();
    *steer_angle = angle;
    

    switch(user_mode){

        //No Acceleration, Ramp 
        case 0x00:
            break;
        //Accelerating Mode, Ramp Up
        case 0x7F:
            //Prevent torque from exceeding max torque
            if(general_torque > max_torque){
                general_torque = max_torque;
            }
            //We are turning right
            if(angle >= 0 && angle <= 2048){
                torque_ratio = ((-0.00031)*angle)+(0.99972);
                *torque_right = general_torque*torque_ratio;
                *torque_left = general_torque;
            }
            //We are turning left
            else{
                torque_ratio = ((1.033)*log((double)angle))-(7.59);
                *torque_left = general_torque*torque_ratio;
                *torque_right = general_torque;
            }
            break;
        //Cruise Mode
        case 0x03:
            break;
        default:
            if(general_torque != 0) {
                general_torque = 0;
                *torque_left = 0;
                *torque_right = 0;
            }
            else {}
            break;

    }//switch
}//motor_torque

void usart_init(unsigned char ubrr){
    
    //Set Baud Rate at 9600
    UBRR1H = (unsigned char)(ubrr>>8);
    UBRR1L = (unsigned char)ubrr;

    //Enable Transmitter and Reciever
    UCSR1B = (1<<RXEN)|(1<<TXEN);
    
    //Set Frame Format, 8 bit data, 2 stop bit, Asynchronous
    UCSR1C |= (1<<UCSZ11)|(1<<UCSZ10)|(1<<USBS1);
}//usart_init

void usart_transmit(uint8_t data_array[]){
    int i = 0;
    for(;i<10; i++){
        //Wait for empty transmit buffer
        while(!(UCSR1A & (1<<UDRE1)));

    //Put data into buffer, send data
        UDR1 = data_array[i];
        }//for
}//usart_transmit




void pirate_mode(){

    //Configure interrupt 0 so a rising edge will wake up the controller from sleep mode
    EICRA = (1<<ISC01); //Generate aysnchronous interrupt request on rising edge
    EIMSK = (1<<INT0);  //Enable external interrupt 0

    set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Enable power down mode, set sleep enable bit
                                         //in the MCUCR register
    PORTB &= ~((1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay)); //Turn off relay circuits
    cli();  //Clear global interrupt
    sleep_enable(); //Set sleep enable bit in MCUCR register
    sei();          //Set global interrupt bit
    sleep_cpu();    //CPU is sleeping
    sleep_disable();   //CPU wakes up on rising edge ISR is executed

    PORTB |= (1<<speed1_relay)|(1<<speed2_relay)|(1<<pc_relay); //Turn on relay circuits
}//pirate_mode

ISR(INT0_vect){
    EIMSK &= ~(1<<INT0);
}//ISR

ISR(TIMER1_OVF_vect){
    PORTB ^= (1<<PB7);
    PORTF |= (1<<PF0);
    motor_torque(&torque_right, &torque_left, &steering_angle);
    spi_float_to_int(&TR, torque_right);
    spi_float_to_int(&TL, torque_left);
    data_array[0] = TR.integer >> 8;
    data_array[1] = TR.integer & 0x00FF;
    data_array[2] = TR.fraction >> 8;
    data_array[3] = TR.fraction & 0x00FF;
    data_array[4] = TL.integer >> 8;
    data_array[5] = TL.integer & 0x00FF;
    data_array[6] = TL.fraction >> 8;
    data_array[7] = TL.fraction & 0x00FF;
    data_array[8] = steering_angle >> 8;
    data_array[9] = steering_angle & 0x00FF;
    usart_transmit(data_array);
    spi_init();
    PORTF &= ~(1<<PF0);

}//timer1_isr



int main(){

    struct int_frac TR;
    struct int_frac TL;
   // char lcd_data1[16] = {"         "};
   // char lcd_data2[16] = {"             "};
   // char lcd_data3[16] = {"        "};
   // char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    DDRB |= (1<<PB7)|(1<<PB6);
    DDRF = 0xFF;
    DDRD |= (1<<PD0);   //SPI SS pin
    DDRD &= ~(1<<PD7);  //Configure Port D Pin 7 for input
    PORTD |= (1<<PD7);  //enable pullup
    timer1_init();      //initialize 16 bit timer
    sei();

    while(1){
        
        
    }//while
return 0;
}//main

/**
 
        clear_display();
        cursor_home();
    }//while
 
        lcd_data1[0] = numbers[TR.integer/100 % 10];
        lcd_data1[1] = numbers[TR.integer/10 % 10];
        lcd_data1[2] = numbers[TR.integer % 10];
        lcd_data1[3] = '.';
        lcd_data1[4] = numbers[TR.fraction/100 % 10];
        lcd_data1[5] = numbers[TR.fraction/10 % 10];
        lcd_data1[6] = numbers[TR.fraction % 10];

        lcd_data2[0] = numbers[TL.integer/100 % 10];
        lcd_data2[1] = numbers[TL.integer/10 % 10];
        lcd_data2[2] = numbers[TL.integer % 10];
        lcd_data2[3] = '.';
        lcd_data2[4] = numbers[TL.fraction/100 % 10];
        lcd_data2[5] = numbers[TL.fraction/10 % 10];
        lcd_data2[6] = numbers[TL.fraction % 10];
        
        lcd_data3[0] = numbers[steering_angle/1000 % 10];
        lcd_data3[1] = numbers[steering_angle/100 % 10];
        lcd_data3[2] = numbers[steering_angle/10 % 10];
        lcd_data3[3] = numbers[steering_angle/1 % 10];
        

        string2lcd(lcd_data1);
        string2lcd(lcd_data2);
        string2lcd(lcd_data3);

**/