/*
 * TIMER.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_




#include "GPIO.h"
#include "STM32f103x6.h"
#include "RCC.h"


/*
Timer 1 (TIM1):

Channel 1: PA8
Channel 2: PA9
Channel 3: PA10
Channel 4: PA11

Timer 2 (TIM2):
Channel 1: PA0
Channel 2: PA1
Channel 3: PA2
Channel 4: PA3

Timer 3 (TIM3):
Channel 1: PA6
Channel 2: PA7
Channel 3: PB0
Channel 4: PB1

Timer 4 (TIM4):
Channel 1: PB6
Channel 2: PB7
Channel 3: PB8
Channel 4: PB9
 */

#define TIM_CR1_CEN      (1 << 0) // Counter enable
#define TIM_SR_UIF       (1 << 0) // Update interrupt flag





//TIMER1
#define TIM1_BASE                              0x40012C00
#define TIM1_CNT                              *( volatile uint32_t *)(TIM1_BASE+0x24)
#define TIM1_CR1                              *( volatile uint32_t *)(TIM1_BASE+0x00)
#define TIM1_PSC                              *( volatile uint32_t *)(TIM1_BASE+0x28)
#define TIM1_SR                               *( volatile uint32_t *)(TIM1_BASE+0x10)
#define TIM1_DIER                             *( volatile uint32_t *)(TIM1_BASE+0x0c)
#define TIM1_ARR                              *( volatile uint32_t *)(TIM1_BASE+0x2c)
#define TIM1_CCR1                             *( volatile uint32_t *)(TIM1_BASE+0x34)
#define TIM1_CCMR1                            *( volatile uint32_t *)(TIM1_BASE+0x18)
#define TIM1_CCER                             *( volatile uint32_t *)(TIM1_BASE+0x20)
#define TIM1_BDTR                             *( volatile uint32_t *)(TIM1_BASE+0x44)
#define TIM1_CCR4                             *( volatile uint32_t *)(TIM1_BASE+0x40)
#define TIM1_CCMR2                            *( volatile uint32_t *)(TIM1_BASE+0x1c)


/*===================PWM values===============*/
#define RCC_APB1ENR                           *( volatile uint32_t *)(RCC_BASE+0x1C)
#define RCC_APB2ENR                           *( volatile uint32_t *)(RCC_BASE+0x18)


#define PWM_TIM_0                            0
#define PWM_TIM_10                           0xFFFF/10
#define PWM_TIM_20                           0xFFFF/5
#define PWM_TIM_25                           0xFFFF/4
#define PWM_TIM_30                           0xFFFF/3.33
#define PWM_TIM_40                           0xFFFF/2.5
#define PWM_TIM_50                           0xFFFF/2
#define PWM_TIM_60                           0xFFFF/1.666
#define PWM_TIM_75                           0xFFFF/1.333
#define PWM_TIM_80                           0xFFFF/1.25
#define PWM_TIM_90                           0xFFFF/1.111
#define PWM_TIM_100                          0xFFFF/1




// Function prototypes
void Delay_us(uint32_t us);
void Delay_ms(uint32_t ms);
void TIM2_Init(void);
void Delay_Sec(uint32_t sec);




void TIM1_Init_PWM(void);
void Timer1_PWM1_Set_Value(int PWM1);
void Timer1_PWM2_Set_Value(int PWM2);




#endif /* INC_TIMER_H_ */
