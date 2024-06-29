/*
 * ULTRASONIC.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_




#include "GPIO.h"
#include "STM32f103x6.h"
#include "RCC.h"


// Define pins (adjust if needed)
#define TRIG_PIN GPIO_PIN_11
#define TRIG_PORT GPIOA
#define ECHO_PIN GPIO_PIN_12
#define ECHO_PORT GPIOA
#define clk 8000000


float HAL_Ultrasonic_get_distance(void) ;





#endif /* INC_ULTRASONIC_H_ */
