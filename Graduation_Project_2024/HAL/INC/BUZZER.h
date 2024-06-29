/*
 * BUZZER.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_


#include "GPIO.h"


#define Buzzer_Port GPIOB
#define Buzzer_Pin  GPIO_PIN_6

void HAL_Buzzer_Init(void);
void HAL_Buzzer_ON (void);
void HAL_Buzzer_OFF (void);

#endif /* INC_BUZZER_H_ */
