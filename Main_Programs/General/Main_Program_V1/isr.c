/********************************************************
 * File Name: isr.c
 *
 * *****************************************************/

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "speed.h"
#include "steering.h"
#include "system_init.h"
#include "pirate.h"
#include "conversions.h"
#include "uart.h"
#include <string.h>
#include <stdlib.h>

#define NO_INPUT        0xFF
#define ACCELERATE      0x7F
#define CRUISE          0xBF
#define PIRATE          0xFE
#define MAX_TORQUE_CUR  25


float torque_right = 0.0;
unsigned char torque_r_bytes[4];
float torque_left = 0.0;
unsigned char torque_l_bytes[4];
float speed = 0.0;
unsigned char speed_bytes[4];
float cruise_speed = 20;
uint16_t steering_angle;
float steering_angle_float = 0.0;
float base_torque = 0.0;
uint16_t timestamp_history;
float integral = 0.0;
uint8_t rx_buff[] = {0, 0, 0, 0};


/*********************************************************************
 * ISR: timer1
 *
 * Description: This interrupt handles all of the main program timing.
 *  Set to 10Hz
 *********************************************************************/
ISR(TIMER1_OVF_vect) {
	
	
	USART0_RX(&rx_buff, 4);
	uart1_uint8_transmit(rx_buff, 4);
	
/**
    uint8_t user_mode = PIND | 0x3E; //Mask everything out except PORTD 0, 6, and 7
    steering_angle = 1;// get_angle();
	//speed = (float)atof(rx_buff);

	
    switch(user_mode) 
    {
        //Accelerate button was let go
        case NO_INPUT:
            integral = 0;
           // speed =(float)rx_buff; // calc_speed(timestamp_history, speed);
            if(torque_right != 0) {
                base_torque = 0;
                torque_right = 0;
                torque_left = 0;
            }

            float_to_bytes(&torque_right,torque_r_bytes);
			float_to_bytes(&speed, speed_bytes);
            //float_to_bytes(&torque_left, torque_l_bytes);
            //float_to_bytes(&speed, speed_bytes);
            uart1_uint8_transmit(torque_r_bytes,4);
			//uart1_uint8_transmit(speed_bytes, 4);
            //uart0_uchar(torque_l_bytes);
            //uart0_uchar(speed_bytes);

            break;
       
	 
            //Accelerate button is pushed
        case ACCELERATE:
            integral = 0;
            base_torque = base_torque + 0.5;
            if(base_torque > MAX_TORQUE_CUR) { base_torque = MAX_TORQUE_CUR; }

            //Calculate new values for the motor controllers
            //cruise_speed = 20;
	    	//cruise_speed = rx_buff; //calc_speed(timestamp_history, speed);
            //cruise_speed = speed;
            set_differential_torque(&torque_right, &torque_left, steering_angle, base_torque);
                
            //Convert floats to bytes and send on uart
            float_to_bytes(&torque_right, torque_r_bytes);
            //float_to_bytes(&torque_left, torque_l_bytes);
            //float_to_bytes(&speed, speed_bytes);
            uart1_uint8_transmit(torque_r_bytes,4);
            //uart0_uchar(torque_l_bytes);
            //uart0_uchar(speed_bytes);

            break;
	 case CRUISE:
           
            if(base_torque > MAX_TORQUE_CUR) { base_torque = MAX_TORQUE_CUR; }
			
            //Calculate new values for the motor controllers
            //speed = (float)rx_buff; //calc_speed(timestamp_history, speed);
            cruise_speed = 20;
            //cruise(&torque_right, &torque_left, steering_angle, &base_torque, cruise_speed, speed, &integral);
	    	if(speed < cruise_speed){
			base_torque = base_torque + 2;
	   	 }
	    	if(speed > cruise_speed) 
			base_torque = 0;
            
	    	set_differential_torque(&torque_right, &torque_left, steering_angle, base_torque);
	    

            //Convert floats to bytes and send on uart
            float_to_bytes(&torque_right, torque_r_bytes);
            float_to_bytes(&speed, speed_bytes);
            //float_to_bytes(&torque_left, torque_l_bytes);
            //float_to_bytes(&speed, speed_bytes);
	    	uart1_uint8_transmit(torque_r_bytes, 4);
            //uuart1_uint8_transmit(1, 1);art1_uint8_transmit(speed_bytes, 4);
            //uart0_uchar(torque_l_bytes);
            //uart0_uchar(speed_bytes);

            break;


        //Cruise button is pushed
              case PIRATE:

            pirate_mode();

            break;
            
        default:
            break;

    }//switch*/
}//timer1_ISR


/*********************************************************************
 * ISR: pirate_mode
 *
 * Description: The pirate mode switch is connected to external
 *  interrupt 0. If triggered, the pirate mode function will be called.
 *********************************************************************/

ISR(INT0_vect){

    //NOT SURE WHAT THIS IS FOR
    EIMSK &= ~(1<<INT0);

}//ISR

/*********************************************************************
 * ISR: speed_sensor_2
 *
 * Description: Same as speed_sensor_1 description. 
 *********************************************************************/
/*ISR(TIMER3_CAPT_vect) {

    uint16_t timestamp = ICR3;
    static uint16_t timestamp_hist = 0;

    //wrap around at the end of the timer
    if(timestamp < timestamp_hist) { timestamp_history = 65535 - timestamp_hist + timestamp; }
    else { timestamp_history = timestamp - timestamp_hist; }
           
    timestamp_hist = timestamp;

}*/

/**ISR(USART0_RX_vect){
	static uint8_t i = 0;

	DDRB |= (1<<PB6);
	PORTB ^= (1<<PB6);
	_delay_ms(10);
	
    unsigned char data = UDR0;
    if(data == 'G') {
        i = 0;
	}
	else {
        rx_buff[i] = data;
        i++;
    }

}**/



