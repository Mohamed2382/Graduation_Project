/*
 * DC.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#ifndef INC_DC_H_
#define INC_DC_H_


#include "GPIO.h"

#define forward  1
#define backward 2

#define Motor_PORT_M1 GPIOB
#define Motor_PORT_M2 GPIOB

#define Motor_PIN1    ((uint16_t)0x0001) //b0
#define Motor_PIN2    ((uint16_t)0x0002) //b1
#define Motor_PIN3 	  ((uint16_t)0x0008) //b3
#define Motor_PIN4    ((uint16_t)0x0010) //b4
#define motor_Enable  ((uint16_t)0x0100) //a8

#define motor_1 1
#define motor_2 2


void HAL_Motor1_init(GPIO_TypeDef *GPIOx, uint8_t PIN1, uint8_t PIN2) ;
void HAL_Motor2_init(GPIO_TypeDef *GPIOx, uint8_t PIN3, uint8_t PIN4);
void HAL_Motor_Stop(uint8_t motor);
void HAL_Motor1_Direction(uint8_t direction);
void HAL_Motor2_Direction(uint8_t direction);
void HAL_Speed_Motor(uint32_t speed);


#endif /* INC_DC_H_ */
