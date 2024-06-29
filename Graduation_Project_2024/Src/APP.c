/*
 * APP.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#include "STM32f103x6.h"  // Include STM32f103x6 header file
#include "GPIO.h"         // Include GPIO header file
#include "Timer.h"        // Include Timer header file
#include "UART.h"         // Include UART header file
#include "ULTRASONIC.h"   // Include Ultrasonic header file
#include "LDR.h"          // Include LDR header file
#include "DC.h"           // Include DC motor header file

// Define motor speeds
#define speed_1 95
#define speed_2 85
#define speed_3 50

// Variable to hold received character and status flags
uint8_t ch = 0, direction = 0, light = 0, d = 0;

// Bluetooth task function
void Bluetooth_Task(void) {
	// Receive data from Bluetooth
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	// Echo received data back
	MCAL_UART_SendData(USART1, &ch, enable);

	// Check if received character is 't'
	if (ch == 't') {
		while (1) {
			MCAL_UART_ReceiveData(USART1, &ch, disable);

			if (ch == 'f') {
				MCAL_UART_SendData(USART1, &ch, enable);

				// Stop motors
				HAL_Motor_Stop(motor_1);
				HAL_Motor_Stop(motor_2);
				Delay_Sec(1);

				// Set motors to move forward
				HAL_Motor1_Direction(forward);
				HAL_Motor2_Direction(forward);
				while (1) {
					// Check light sensor value
					light = HAL_LDR_Output_Value();
					if (light < Dark)
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, HIGH);
					else
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, LOW);

					MCAL_UART_ReceiveData(USART1, &ch, disable);
					if (ch == 'e') {
						MCAL_UART_SendData(USART1, &ch, enable);
						// Ensure motors stop on exit
						HAL_Motor_Stop(motor_1);
						HAL_Motor_Stop(motor_2);
						Delay_Sec(1);
						break;
					}
				}
			} else if (ch == 'b') {
				MCAL_UART_SendData(USART1, &ch, enable);

				// Stop motors
				HAL_Motor_Stop(motor_1);
				HAL_Motor_Stop(motor_2);

				Delay_Sec(1);
				// Set motors to move backward
				HAL_Motor1_Direction(backward);
				HAL_Motor2_Direction(backward);
				while (1) {
					// Check light sensor value
					light = HAL_LDR_Output_Value();
					if (light < Dark)
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, HIGH);
					else
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, LOW);

					MCAL_UART_ReceiveData(USART1, &ch, disable);
					if (ch == 'e') {
						MCAL_UART_SendData(USART1, &ch, enable);

						// Ensure motors stop on exit
						HAL_Motor_Stop(motor_1);
						HAL_Motor_Stop(motor_2);
						Delay_Sec(1);
						break;
					}
				}
			}
		}
	} else if (ch == 'n') {
		while (1) {
			MCAL_UART_ReceiveData(USART1, &ch, disable);

			if (ch == 'f') {
				MCAL_UART_SendData(USART1, &ch, enable);

				// Stop motors
				HAL_Motor_Stop(motor_1);
				HAL_Motor_Stop(motor_2);
				Delay_Sec(1);

				// Set motors to move forward
				HAL_Motor1_Direction(forward);
				HAL_Motor2_Direction(forward);

				while (1) {
					MCAL_UART_ReceiveData(USART1, &ch, disable);
					if (ch == 'a') {
						// Set motor speed
						HAL_Speed_Motor(speed_1);
					} else if (ch == 'b') {
						// Set motor speed
						HAL_Speed_Motor(speed_2);
					} else if (ch == 'c') {
						// Set motor speed
						HAL_Speed_Motor(speed_3);
					}

					// Check light sensor value
					light = HAL_LDR_Output_Value();
					if (light < Dark)
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, HIGH);
					else
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, LOW);

					MCAL_UART_ReceiveData(USART1, &ch, disable);
					if (ch == 'e') {
						MCAL_UART_SendData(USART1, &ch, enable);
						// Ensure motors stop on exit
						HAL_Motor_Stop(motor_1);
						HAL_Motor_Stop(motor_2);
						Delay_Sec(1);
						break;
					}
				}
			}
		}
	} else if (ch == 'a') {
		while (1) {
			MCAL_UART_ReceiveData(USART1, &ch, disable);

			if (ch == 'f') {
				MCAL_UART_SendData(USART1, &ch, enable);

				// Stop motors
				HAL_Motor_Stop(motor_1);
				HAL_Motor_Stop(motor_2);
				Delay_Sec(1);

				// Set motors to move forward
				HAL_Motor1_Direction(forward);
				HAL_Motor2_Direction(forward);

				while (1) {
					// Check ultrasonic sensor distance
					d = HAL_Ultrasonic_get_distance();
					if (d < 20) {
						HAL_Motor_Stop(motor_1);
						HAL_Motor_Stop(motor_2);
					} else {
						HAL_Motor1_Direction(forward);
						HAL_Motor2_Direction(forward);
					}

					// Check light sensor value
					light = HAL_LDR_Output_Value();
					if (light < Dark)
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, HIGH);
					else
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, LOW);

					MCAL_UART_ReceiveData(USART1, &ch, disable);
					if (ch == 'e') {
						MCAL_UART_SendData(USART1, &ch, enable);
						// Ensure motors stop on exit
						HAL_Motor_Stop(motor_1);
						HAL_Motor_Stop(motor_2);
						Delay_Sec(1);
						break;
					}
				}
			}
		}
	} else if (ch == 'f') {
		while (1) {
			MCAL_UART_ReceiveData(USART1, &ch, disable);

			if (ch == 'f') {
				MCAL_UART_SendData(USART1, &ch, enable);

				// Stop motors
				HAL_Motor_Stop(motor_1);
				HAL_Motor_Stop(motor_2);
				Delay_Sec(1);

				// Set motors to move forward
				HAL_Motor1_Direction(forward);
				HAL_Motor2_Direction(forward);

				while (1) {
					// Check ultrasonic sensor distance
					d = HAL_Ultrasonic_get_distance();
					if (d < 20) {
						HAL_Motor_Stop(motor_1);
						HAL_Motor_Stop(motor_2);
					} else if (d < 50) {
						HAL_Buzzer_ON();
					} else {
						HAL_Motor1_Direction(forward);
						HAL_Motor2_Direction(forward);
						HAL_Buzzer_OFF();
					}

					// Check light sensor value
					light = HAL_LDR_Output_Value();
					if (light < Dark)
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, HIGH);
					else
						MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, LOW);

					MCAL_UART_ReceiveData(USART1, &ch, disable);
					if (ch == 'e') {
						MCAL_UART_SendData(USART1, &ch, enable);
						// Ensure motors stop on exit
						HAL_Motor_Stop(motor_1);
						HAL_Motor_Stop(motor_2);
						Delay_Sec(1);
						break;
					}
				}
			}
		}
	}
}

int main(void) {
	// Enable clock for peripherals
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_TIMER1_CLK_EN();
	RCC_TIMER2_CLK_EN();
	RCC_USART1_CLK_EN();
	RCC_AFIO_GPIOE_CLK_EN();
	RCC_ADC1_CLK_EN();

	// Initialize peripherals
	HAL_Buzzer_Init();
	HAL_LDR_Init();

	TIM1_Init_PWM();
	TIM2_Init();

	HAL_Motor1_init(Motor_PORT_M1, Motor_PIN1, Motor_PIN2);
	HAL_Motor2_init(Motor_PORT_M1, Motor_PIN3, Motor_PIN4);

	// Configure LDR output pin
	GPIO_PinConfig_t led_light;
	led_light.GPIO_PinNumber = GPIO_PIN_5;
	led_light.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	led_light.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOB, &led_light);

	// Configure buzzer output pin
	GPIO_PinConfig_t buzzer_pin;
	buzzer_pin.GPIO_PinNumber = GPIO_PIN_6;
	buzzer_pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	buzzer_pin.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOB, &buzzer_pin);

	// Configure UART
	UART_Config_t Bluetooth_Config;
	Bluetooth_Config.BaudRate = 9600;
	Bluetooth_Config.HwFlowCtl = UART_HwFlowCtl_NONE;
	Bluetooth_Config.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	Bluetooth_Config.P_IRQ_CallBack = Bluetooth_Task;
	Bluetooth_Config.Parity = UART_Parity__NONE;
	Bluetooth_Config.Payload_Length = UART_Payload_Length_8B;
	Bluetooth_Config.StopBits = UART_StopBits__1;
	Bluetooth_Config.USART_Mode = UART_MODE_TX_RX;

	// Initialize UART
	MCAL_UART_Init(USART1, &Bluetooth_Config);
	// Set UART GPIO pins
	MCAL_UART_GPIO_Set_Pins(USART1);

	while (1) {
		// Main loop
	}
}
