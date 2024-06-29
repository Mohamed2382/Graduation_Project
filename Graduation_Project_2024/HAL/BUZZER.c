/*
 * BUZZER.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */



#include "BUZZER.h"

GPIO_PinConfig_t Buz_CFG;
void HAL_Buzzer_Init(void){
	Buz_CFG.GPIO_PinNumber = Buzzer_Pin;
	Buz_CFG.GPIO_Output_Speed  = GPIO_Output_Speed_2M;
	Buz_CFG.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	MCAL_GPIO_Init(Buzzer_Port, &Buz_CFG);
}
void HAL_Buzzer_ON (void){
	MCAL_GPIO_WritePin(Buzzer_Port, Buzzer_Pin, GPIO_PIN_SET);
}
void HAL_Buzzer_OFF (void){
	MCAL_GPIO_WritePin(Buzzer_Port, Buzzer_Pin, GPIO_PIN_RESET);
}
