/*
 * ADC.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_




#include "STM32f103x6.h"

#include "GPIO.h"

#define SET_BIT(Reg, bitnum) (Reg) |= (1 << (bitnum))
#define CLR_BIT(Reg, bitnum) (Reg) &= ~(1 << (bitnum))
#define TOGGLE_BIT(Reg, bitnum) (Reg) ^= (1 << (bitnum))

/* Macros for RCC APB2ENR register */
#define RCC_APB2ENR_ADC1EN  (1U << 9)

/* Macros for ADC CR2 register */
#define ADC_CR2_ADON        (1U << 0)
#define ADC_CR2_ALIGN       (1U << 11)
#define ADC_CR2_RES         (0U << 23)
#define ADC_CR2_CONT        (1U << 1)
#define ADC_CR2_SWSTART     (1U << 22)

/* Macros for RCC CFGR register */
#define RCC_CFGR_ADCPRE_DIV2   (0b00U << 14)
#define RCC_CFGR_ADCPRE_DIV4   (0b01U << 14)
#define RCC_CFGR_ADCPRE_DIV6   (0b10U << 14)
#define RCC_CFGR_ADCPRE_DIV8   (0b11U << 14)

/* Macros for ADC CR1 register */
#define ADC_CR1_JEOCIE      (1U << 7)
#define ADC_CR1_EOCIE       (1U << 5)

/* Macros for ADC SQR3 register */
#define ADC_SQR3_SQ1_Pos    0
#define ADC_SQR3_SQ1_Msk    (0x1FU << ADC_SQR3_SQ1_Pos)

/* Macros for ADC SR register */
#define ADC_SR_EOC          (1U << 1)
#define ADC_SR_STRT         (1U << 4)

/* Macros for ADC SQR3 register */
#define ADC_SQR3_SQ1_Pos    0
#define ADC_SQR3_SQ2_Pos    5
#define ADC_SQR3_SQ3_Pos    10
#define ADC_SQR3_SQ4_Pos    15
#define ADC_SQR3_SQ5_Pos    20
#define ADC_SQR3_SQ6_Pos    25
#define ADC_SQR3_SQ7_Pos    30
#define ADC_SQR3_SQ8_Pos    0
#define ADC_SQR3_SQ9_Pos    5
#define ADC_SQR3_SQ10_Pos   10
#define ADC_SQR3_SQ11_Pos   15
#define ADC_SQR3_SQ12_Pos   20
#define ADC_SQR3_SQ13_Pos   25
#define ADC_SQR3_SQ14_Pos   30

/* Macros for ADC CR2 register */
#define ADC_CR2_ADON    (1U << 0)
#define ADC_CR2_ALIGN   (1U << 11)
#define ADC_CR2_RES     (0U << 23)
#define ADC_CR2_CONT    (1U << 1)
#define ADC_CR2_SWSTART (1U << 22)

/* Macros for RCC CFGR register */
#define RCC_CFGR_ADCPRE_DIV2   (0b00U << 14)
#define RCC_CFGR_ADCPRE_DIV4   (0b01U << 14)
#define RCC_CFGR_ADCPRE_DIV6   (0b10U << 14)
#define RCC_CFGR_ADCPRE_DIV8   (0b11U << 14)

/*macros for adc channels */
/*
ADC_IN0 -> PA0
ADC_IN1 -> PA1
ADC_IN2 -> PA2
ADC_IN3 -> PA3
ADC_IN4 -> PA4
ADC_IN5 -> PA5
ADC_IN6 -> PA6
ADC_IN7 -> PA7
ADC_IN8 -> PB0
ADC_IN9 -> PB1
 */


void MCAL_ADC_init(void) ;
void MCAL_ADC_SelectChannel(uint8_t ChannelNum) ;
uint16_t MCAL_ADC_ConvertToDigital(uint8_t ChannelNum) ;
void MCAL_ADC_SetCallBack(void (*callback)(void)) ;
void ADC_IRQHandler(void) ;






#endif /* INC_ADC_H_ */
