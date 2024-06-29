/*
 * DC.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */


#include "DC.h"
#include "Timer.h"

void HAL_Motor1_init(GPIO_TypeDef *GPIOx,uint8_t PIN1 , uint8_t PIN2 ){

	GPIO_PinConfig_t X;
	X.GPIO_PinNumber = PIN1;
	X.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	X.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOx, &X);

	X.GPIO_PinNumber = PIN2;
	X.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	X.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOx, &X);

}

void HAL_Motor2_init(GPIO_TypeDef *GPIOx,uint8_t PIN3 , uint8_t PIN4 ){

	GPIO_PinConfig_t X;
	X.GPIO_PinNumber = PIN3;
	X.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	X.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOx, &X);

	X.GPIO_PinNumber = PIN4;
	X.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	X.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOx, &X);

}



void HAL_Motor_Stop(uint8_t motor){
	if (motor == motor_1){
		MCAL_GPIO_WritePin(Motor_PORT_M1, Motor_PIN1, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(Motor_PORT_M1, Motor_PIN2, GPIO_PIN_RESET);
	}
	else if (motor == motor_2){
		MCAL_GPIO_WritePin(Motor_PORT_M2, Motor_PIN3, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(Motor_PORT_M2, Motor_PIN4, GPIO_PIN_RESET);

	}
}


void HAL_Motor1_Direction(uint8_t direction)
{
	switch (direction){
	case forward:{
		// Forward
		MCAL_GPIO_WritePin(Motor_PORT_M1, Motor_PIN1, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(Motor_PORT_M1, Motor_PIN2, GPIO_PIN_RESET);
	}
	break;
	case backward:{
		// Backward
		MCAL_GPIO_WritePin(Motor_PORT_M1, Motor_PIN1, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(Motor_PORT_M1, Motor_PIN2, GPIO_PIN_SET);
	}
	break;
	default:{
		MCAL_GPIO_WritePin(Motor_PORT_M1, Motor_PIN1, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(Motor_PORT_M1, Motor_PIN2, GPIO_PIN_RESET);

	}
	break;
	}

}


void HAL_Motor2_Direction(uint8_t direction)
{
	switch (direction){
	case forward:{
		// Forward
		MCAL_GPIO_WritePin(Motor_PORT_M2, Motor_PIN3, GPIO_PIN_SET);
		MCAL_GPIO_WritePin(Motor_PORT_M2, Motor_PIN4, GPIO_PIN_RESET);
	}
	break;
	case backward:{
		// Backward
		MCAL_GPIO_WritePin(Motor_PORT_M2, Motor_PIN3, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(Motor_PORT_M2, Motor_PIN4, GPIO_PIN_SET);
	}
	break;
	default:{
		MCAL_GPIO_WritePin(Motor_PORT_M2, Motor_PIN3, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(Motor_PORT_M2, Motor_PIN4, GPIO_PIN_RESET);

	}
	break;
	}

}
/*
Timer 1 (TIM1):

Channel 1: PA8
Channel 2: PA9
Channel 3: PA10
Channel 4: PA11
*/



void HAL_Speed_Motor (uint32_t speed){
	GPIO_PinConfig_t x;
	x.GPIO_PinNumber = motor_Enable;
	x.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
	x.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOA, &x);
	Timer1_PWM1_Set_Value((speed *50000 )/100);

}

