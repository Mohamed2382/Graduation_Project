/*
 * STD_TYPES.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#ifndef INC_STD_TYPES_H_
#define INC_STD_TYPES_H_


#include <stdio.h>
#include <stdlib.h>

//Standard data type
typedef unsigned long  int  uint32_t;
typedef unsigned short int  uint16_tt;
typedef signed   long  int  sint32_t;
typedef signed   short int  sint16_t;

typedef unsigned char        uint8_t;
typedef signed   char        sint8_t;

typedef float               f32_t;
typedef double              f64_t;
typedef long     double     f80_t;

#define NULL_ptr ((void*)0)
#define TRUE  1
#define FALSE 0
#define NOT_FOUND -1

#define E_OK         0x00
#define E_NOT_OK     0x01

#define STD_TYPES_OK            1
#define STD_TYPES_NOK           0

typedef void(*fptr_t)(void);

#define NULL                   ((void*)0)
#define F_CPU				8000000 /* 8Mhz */

typedef uint8_t Std_Return_Type ;



#endif /* INC_STD_TYPES_H_ */
