/*
 * LDR.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */



#include "LDR.h"



void HAL_LDR_Init (void){
	MCAL_ADC_init();
	ldr_Cfg.GPIO_PinNumber = LDR_Pin;
	ldr_Cfg.GPIO_MODE = GPIO_MODE_Analog;
	MCAL_GPIO_Init(LDR_Port, &ldr_Cfg);
}



uint16_t HAL_LDR_Output_Value(void){
	uint16_t Dout = 0;
	Dout = MCAL_ADC_ConvertToDigital(LDR_channel);
	return Dout;
}
