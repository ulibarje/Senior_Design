/*******************************************************
 * File Name: conversions.c
 * Authors: Jesse Ulibarri, Shane Licari, Eli Yazzolino
 * Date: 4/20/2017
 *
 * Description:
********************************************************/

#include <stdlib.h>
#include <string.h>
#include "conversions.h"

/**************************************************************************************
 * Name: bytes_to_float
 *
 * Description: 
 *************************************************************************************/
void bytes_to_float(unsigned char* src, float* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    memcpy(u.bytes, src, 4);
    *dest = u.a;
}//bytes_to_float

/**************************************************************************************
 * Name: float_to_bytes
 *
 * Description: 
 *************************************************************************************/
void float_to_bytes(float src, unsigned char* dest) {
    union {
        float a;
        unsigned char bytes[4];
    } u;
    u.a = src;
    memcpy(dest, u.bytes, 4);
}//float_to_bytes


