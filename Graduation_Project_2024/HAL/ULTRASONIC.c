/*
 * ULTRASONIC.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */


#include "ULTRASONIC.h"

void wait_ms (int x)
{
	unsigned int i , j ;
	for (i= 0 ; i<x ; i++)
		for (j= 0 ; j<255 ; j++);
}
void udelay(uint32_t us){
	while(us--){
		for(uint32_t i=0; i< clk/4000000; i++);
	}
}


float HAL_Ultrasonic_get_distance(void) {
	// Configure GPIO
	//RCC_GPIOA_CLK_EN() ;

	GPIO_PinConfig_t Pin_Cfg;
	// TRIG pin as output
	Pin_Cfg.GPIO_PinNumber = TRIG_PIN;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_Output_Speed = GPIO_Output_Speed_2M;
	MCAL_GPIO_Init(TRIG_PORT, &Pin_Cfg);
	// ECHO pin as input
	Pin_Cfg.GPIO_PinNumber = ECHO_PIN;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(ECHO_PORT, &Pin_Cfg);

	// Trigger pulse

	MCAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, 0);
	STK_u8SetuSBusyWait(5);
	MCAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, 1);
	udelay(10);
	MCAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, 0);

	// Wait for echo (rising edge)
	while (!MCAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN));

	// Measure pulse duration using delay loop
	uint32_t duration = 0;
	while (MCAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)) {
		duration++;
		udelay(1);
	}

	// Calculate distance
	float distance = (float)duration*.343;

	return distance;
}


/*
 *
#include <Ultra.h>
#include "Timer.h"
// Define the trigger and echo pins
#define TRIG_PIN   GPIO_PIN_9  // Example: PB0
#define ECHO_PIN   GPIO_PIN_8  // Example: PB1
#define ULTRASONIC_PORT GPIOA
#define TIM_CR1_CEN (1 << 0)

void Ultrasonic_Init(void)
{
    // Initialize GPIOB for Trigger and Echo pins
    GPIO_PinConfig_t GPIO_InitStructure;

    // Enable GPIOB clock
    RCC_GPIOB_CLK_EN();

    // Configure Trigger pin as output push-pull
    GPIO_InitStructure.GPIO_PinNumber = TRIG_PIN;
    GPIO_InitStructure.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.GPIO_Output_Speed = GPIO_Output_Speed_2M;
    MCAL_GPIO_Init(ULTRASONIC_PORT, &GPIO_InitStructure);

    // Configure Echo pin as input floating
    GPIO_InitStructure.GPIO_PinNumber = ECHO_PIN;
    GPIO_InitStructure.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    MCAL_GPIO_Init(ULTRASONIC_PORT, &GPIO_InitStructure);

    // Initialize Timer 4
    RCC_TIMER4_CLK_EN();
    TIM4->PSC = 8 - 1;  // Prescaler to get 1 MHz timer clock (assuming 8 MHz system clock)
    TIM4->ARR = 0xFFFF;  // Set auto-reload value to maximum (16-bit)
    TIM4->CR1 |= TIM_CR1_CEN;  // Enable Timer 4
}

uint32_t Ultrasonic_Read(void)
{
    uint32_t startTime, endTime;
    uint32_t timeout = TIMEOUT;
    static uint32_t timeElapsed = 0;

    // Send a 10us pulse to Trigger pin
    MCAL_GPIO_WritePin(ULTRASONIC_PORT, TRIG_PIN, 1);
    Delay_us(10);
    MCAL_GPIO_WritePin(ULTRASONIC_PORT, TRIG_PIN, 0);

    // Wait for Echo pin to go high
    while (!MCAL_GPIO_ReadPin(ULTRASONIC_PORT, ECHO_PIN))
    {
        if (--timeout == 0)
            return 0xFFFFFFFF; // Timeout, no object detected
    }

    // Capture the start time
    startTime = TIM4->CNT;
    timeout = TIMEOUT;

    // Wait for Echo pin to go low
    while (MCAL_GPIO_ReadPin(ULTRASONIC_PORT, ECHO_PIN))
    {
        if (--timeout == 0)
            return 0xFFFFFFFF; // Timeout, no object detected
    }

    // Capture the end time
    endTime = TIM4->CNT;

    // Calculate the time difference in microseconds
    timeElapsed = (endTime >= startTime) ? (endTime - startTime) : ((0xFFFF - startTime) + endTime + 1);

    // Calculate distance in cm (timeElapsed / 58.2 gives the distance in cm)
    return timeElapsed / 58;
}


*/
