/*
 * LDR.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#ifndef INC_LDR_H_
#define INC_LDR_H_

#include "ADC.h"

// Vref = 3.3
// Res = 2^12 = 4096-1 = 4095
// step = Vref / Res
// Dout = Vin/step = Vin*res / Vref
// Vin = adc value *Vref / res

#define Dark 		4000 // Dout=Vin/Step = Vin*Res/Vref Vin assum 1v

GPIO_PinConfig_t ldr_Cfg;

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
#define LDR_channel 0
#define LDR_Pin 0
#define LDR_Port GPIOA

void HAL_LDR_Init (void);
uint16_t HAL_LDR_Output_Value(void);



#endif /* INC_LDR_H_ */
