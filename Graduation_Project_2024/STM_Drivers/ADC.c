/*
 * ADC.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */



#include "ADC.h"

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
#define ADC_SQR3_SQ1    0

// Global ISR pointer to function.
static void (*ADC_callback)(void) = NULL;

/************************************************************************/
/*                   Functions Implementations                          */
/************************************************************************/

void MCAL_ADC_init(void) {
    // Enable ADC clock
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Power on ADC
    ADC1->CR2 |= ADC_CR2_ADON;

    // Set ADC prescaler
    RCC->CFGR |= RCC_CFGR_ADCPRE_DIV4;

    // Set ADC resolution to 12-bit and right alignment
    ADC1->CR2 &= ~(ADC_CR2_ALIGN | ADC_CR2_RES);

    // Disable injected and regular interrupts
    ADC1->CR1 &= ~(ADC_CR1_JEOCIE | ADC_CR1_EOCIE);

    // Set continuous mode
    ADC1->CR2 |= ADC_CR2_CONT;

    // Enable ADC
    ADC1->CR2 |= ADC_CR2_ADON;
}

void MCAL_ADC_SelectChannel(uint8_t ChannelNum) {
    // Select Regular channel
    ADC1->SQR3 = (ADC1->SQR3 & ~(ADC_SQR3_SQ1)) | (ChannelNum << 0);
}

uint16_t MCAL_ADC_ConvertToDigital(uint8_t ChannelNum) {
    // Select Regular channel
    MCAL_ADC_SelectChannel(ChannelNum);

    // Start conversion of regular channels
    ADC1->CR2 |= ADC_CR2_SWSTART;

    // Poll for end of conversion
    while (!(ADC1->SR & ADC_SR_EOC));

    // Clear the EOC flag
    ADC1->SR &= ~ADC_SR_EOC;

    // Return ADC Data
    return ADC1->DR;
}

void MCAL_ADC_SetCallBack(void (*callback)(void)) {
    ADC_callback = callback;
}

void ADC_IRQHandler(void) {
    if (ADC_callback != NULL) {
        ADC_callback();
    }

    // Clear the flags
    ADC1->SR &= ~(ADC_SR_EOC | ADC_SR_STRT);
}
