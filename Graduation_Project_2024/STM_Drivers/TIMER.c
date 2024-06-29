/*
 * TIMER.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */


#include "Timer.h"


void TIM2_Init(void)
{
	// Enable Timer 2 clock
	RCC_TIMER2_CLK_EN();

	// Reset Timer 2 configuration
	TIM2->CR1 = 0;
	TIM2->CR2 = 0;
	TIM2->SMCR = 0;
	TIM2->DIER = 0;
	TIM2->SR = 0;
	TIM2->EGR = 0;
	TIM2->CCMR1 = 0;
	TIM2->CCMR2 = 0;
	TIM2->CCER = 0;

	// Configure Timer 2 base unit
	TIM2->PSC = (SYSTEM_CLOCK / 1000000) - 1; // Prescaler for 1 MHz clock (1 us ticks)
	TIM2->ARR = 0xFFFF; // Max period (16-bit timer)
	TIM2->CR1 = TIM_CR1_CEN; // Enable the timer
}


void Delay_us(uint32_t us)
{
	// Configure Timer 2 for a delay in microseconds
	TIM2->ARR = us - 1; // Set the auto-reload value
	TIM2->CNT = 0; // Reset the counter
	TIM2->CR1 |= TIM_CR1_CEN; // Enable the counter

	// Wait for the update event flag to be set
	while (!(TIM2->SR & TIM_SR_UIF));

	// Clear the update event flag
	TIM2->SR &= ~TIM_SR_UIF;
}

void Delay_ms(uint32_t ms)
{
	for (uint32_t i = 0; i < ms; i++)
	{
		Delay_us(1000); // 1000 microseconds = 1 millisecond
	}
}


void Delay_Sec(uint32_t sec)
{
	for (uint32_t i = 0; i < sec; i++)
	{
		Delay_ms(1000); // 1000 microseconds = 1 millisecond
	}
}

void TIM1_Init_PWM(void)
{
	/*GPIO Configuration */
	//PA8 CH1 PWM1
	GPIO_PinConfig_t x;
	x.GPIO_PinNumber = GPIO_PIN_8;
	x.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
	x.GPIO_Output_Speed = GPIO_Output_Speed_10M;
	MCAL_GPIO_Init(GPIOA, &x);

	//A11 CH4 PWM2
	//MGPIO_voidSetPinDirection(GPIOA,PIN11,OTPUT_SPEED_10MHZ_AFOPP);

	/*Timer1 Configuration*/
	//Bit 11 TIM1EN: TIM1 timer clock enable
	RCC_APB2ENR |=(1<<11);

	//Bit 7 ARPE: Auto-reload preload enable
	TIM1_CR1 |=(1<<7);

	//Upcounting is active when the DIR bit in the TIMx_CR1 register is low
	//Bit 4 DIR: Direction
	TIM1_CR1 &=~(1<<4);

	TIM1_PSC=7;

	//allows generating a signal with a frequency determined by the value of the TIMx_ARR register
	TIM1_ARR = 0xC350;

	/*=========================Channel 1 ==============================*/
	//Bits 6:4 OC1M: Output Compare 1 mode
	//110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
	TIM1_CCMR1 |=(0b110<<4);

	/*The corresponding preload register must be enabled by setting the
    OCxPE bit in the TIMx_CCMRx register*/
	//Bit 3 OC1PE: Output Compare 1 preload enable
	TIM1_CCMR1 |=(1<<3);


	//Bit 1 CC1P: Capture/Compare 1 output polarity
	//1: OC1 active low
	//TIM1_CCER |=(1<<1);


	//Bit 0 CC1E: Capture/Compare 1 output enable
	TIM1_CCER |=(1<<0);

	//Bits 12:14 OC1M: Output Compare 1 mode
	//110: PWM mode 1 - In upcounting, channel 4 is active as long as TIM1_CNT<TIM1_CCR4
	TIM1_CCMR2 |=(0b110<<12);




	/*=========================Channel 4 ==============================*/
	//Bit 11 OC4PE: Output compare 4 preload enable
	TIM1_CCMR2 |=(1<<11);

	//Bit 12 CC4E: Capture/Compare 4 output enable
	TIM1_CCER |=(1<<12);

	//Bit 13 CC14P: Capture/Compare 4 output polarity
	//1: OC1 active low
	//TIM1_CCER |=(1<<13);


	//Bit 15 MOE: Main output enable
	TIM1_BDTR |=(1<<15);

	//Bit 0 CEN: Counter enable
	//TIM1_CR1 |=(1<<0);







}


/*//allows generating a signal with a frequency determined by the value of the TIMx_ARR register
	TIM1_ARR = 0xC350;
 *
 */

void Timer1_PWM1_Set_Value(int PWM1)
{
	//duty cycle determined by the value of the TIMx_CCRx register.
	TIM1_CCR1 = PWM1;
	//Bit 0 CEN: Counter enable
	TIM1_CR1 |=(1<<0);
}


void Timer1_PWM2_Set_Value(int PWM2)
{
	//duty cycle determined by the value of the TIMx_CCRx register.
	TIM1_CCR4 = PWM2;
	//Bit 0 CEN: Counter enable
	TIM1_CR1 |=(1<<0);
}
