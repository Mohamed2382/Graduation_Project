/*
 * EXTI.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */


#include "EXTI.h"
#include "STM32f103x6.h"
#include "GPIO.h"
#include <stdint.h>


/* ================================================ */
/* ============== Generic Variables =============== */
/* ================================================ */

void (* GP_IRQ_CallBack[15])(void); // Array Of 15 Pointer To Functions Take void And Return Nothing


/* ================================================ */
/* =============== Generic Macros ================= */
/* ================================================ */
//from page 191 in family stm
#define AFIO_GPIO_EXTI_Mapping(x) (	(x == GPIOA)?0:\
		(x == GPIOB)?1:\
				(x == GPIOC)?2:\
						(x == GPIOD)?3:0 )


/* ================================================ */
/* =============== Generic functions  ============= */
/* ================================================ */
void Enable_NVIC (uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0: NVIC_IRQ6_EXTI0_EN(); break;
	case 1: NVIC_IRQ7_EXTI1_EN(); break;
	case 2: NVIC_IRQ8_EXTI2_EN(); break;
	case 3:	NVIC_IRQ9_EXTI3_EN(); break;
	case 4: NVIC_IRQ10_EXTI4_EN(); break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9: NVIC_IRQ23_EXTI5_9_EN(); break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15: NVIC_IRQ40_EXTI10_15_EN(); break;
	}
}

void Disable_NVIC (uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0: NVIC_IRQ6_EXTI0_DI(); break;
	case 1: NVIC_IRQ7_EXTI1_DI(); break;
	case 2: NVIC_IRQ8_EXTI2_DI(); break;
	case 3:	NVIC_IRQ9_EXTI3_DI(); break;
	case 4: NVIC_IRQ10_EXTI4_DI(); break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9: NVIC_IRQ23_EXTI5_9_DI(); break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15: NVIC_IRQ40_EXTI10_15_DI(); break;
	}
}


void Update_EXTI(EXTI_PinConfig_t* EXTI_Config){
	/*
	 * 1) Configure GPIO To Be Alternative Function Input (Floating Input)
	 */
	GPIO_PinConfig_t PinConfig;

	/* Update the GPIO Pin to be floating input */
	PinConfig.GPIO_PinNumber = EXTI_Config->EXTI_Pin.GPIO_Pin;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_Pin.GPIOx, &PinConfig);

	/*
	 * 2) Update AFIO to Route between EXTI Line With Port A,B,C,D
	 * fromNVIC ( Non-Vectored Interrupt Controller )
	 * EXTICR (External interrupt controller registers ) reg[0,1,2,3] --> index of reg
	 * position [0,4,8,12]
	 * External interrupt configuration register 1 = EXTI0,EXTI1,EXTI2,EXTI3
	 * External interrupt configuration register 2 = EXTI4,EXTI5,EXTI6,EXTI7
	 * External interrupt configuration register 3 = EXTI8,EXTI9,EXTI10,EXTI11
	 * External interrupt configuration register 4 = EXTI12,EXTI13,EXTI14,EXTI15
	 * we will implementation another AFIO_TypeDef by creat EXTICR[4] ;
	 * exti 13 --->13/4 = index (3) reg 4
	 * exti 13 --->10/4 = index (2) reg 3
	 */
	uint8_t AFIO_EXTICR_index = EXTI_Config->EXTI_Pin.EXTI_InputLineNumber / 4;
	uint8_t AFIO_EXTICR_position = (EXTI_Config->EXTI_Pin.EXTI_InputLineNumber % 4) *4;
	/*to set four bits in reg
	 * 13%4 = 1 * 4 = 4
	 * 10%4=2*4=8
	 */

	/* Clear the four bits first */
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_position);

	/* Set the four bits for the port */
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_Pin.GPIOx) & 0xF) << AFIO_EXTICR_position);

	/*
	 * 3) Update Rising / Falling Edge Register
	 */

	/* Reset bits of rising */
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);

	/* Reset bits of falling */
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);

	/* Which mode ?!*/
	if(EXTI_Config->Trigger_Case == EXTI_Trigger_Rising)
	{
		/* Set bits of rising */
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		/* Set bits of falling */
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RF)
	{
		/* Set bits of rising & falling */
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}

	/*
	 * 4) Update Interrupt Handling CallBack
	 */

	GP_IRQ_CallBack[EXTI_Config->EXTI_Pin.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;


	/*
	 * 5) Enable/Disable IRQ EXTI & NVIC
	 */

	if(EXTI_Config->IRQ_Enable == EXTI_IRQ_Enable)
	{
		//page 207 Interrupt mask register by IMR
		//		MRx: Interrupt Mask on line x
		//		0: Interrupt request from Line x is masked
		//		1: Interrupt request from Line x is not masked
		EXTI->IMR |= (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
		Enable_NVIC(EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->IRQ_Enable == EXTI_IRQ_Disable)
	{
		EXTI->IMR &= ~(1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
		Disable_NVIC(EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
}


/* ================================================ */
/* ================ Public APIs =================== */
/* ================================================ */

/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_Init
 * @brief			- This Is Used To Initialize EXTI From Specific GPIO PIN and Specify Mask/Trigger Condition and IRQ CallBack
 * @param [in] 		- EXTI_Config: set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval 			- None
 * Note				- None
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t * EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}



/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_Update
 * @brief			- This Is Used To Update EXTI From Specific GPIO PIN and Specify Mask/Trigger Condition and IRQ CallBack
 * @param [in] 		- EXTI_Config: set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval 			- None
 * Note				- None
 */
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t * EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}

/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_DeInit
 * @brief			- Reset EXTI Registers and NVIC corresponding IRQ Mask
 * @retval 			- None
 * Note				- None
 */
void MCAL_EXTI_GPIO_DeInit(void)
{
	// two options through rcc or reset reg for EXTI
	// but rcc not access of EXTI
	EXTI->IMR 	= 0x00000000;		// Reset value as data-sheet
	EXTI->EMR	= 0x00000000;
	EXTI->RTSR 	= 0x00000000;
	EXTI->FTSR 	= 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR 	= 0xFFFFFFFF;		// This bit is cleared by writing one on it.

	/* Disable All EXTI IRQ From NVIC (Non-Vectored Interrupt Controllers) */
	NVIC_IRQ6_EXTI0_DI();
	NVIC_IRQ6_EXTI0_DI();
	NVIC_IRQ7_EXTI1_DI();
	NVIC_IRQ8_EXTI2_DI();
	NVIC_IRQ9_EXTI3_DI();
	NVIC_IRQ10_EXTI4_DI();
	NVIC_IRQ23_EXTI5_9_DI();

}



/* ================================================ */
/* =============== ISR Functions ================== */
/* ================================================ */



// EXTI0
void EXTI0_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 0;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[0]();

}

// EXTI1
void EXTI1_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 1;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[1]();

}

// EXTI2
void EXTI2_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 2;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[2]();

}

// EXTI3
void EXTI3_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 3;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[3]();

}

// EXTI4
void EXTI4_IRQHandler (void)
{
	/* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
	EXTI->PR |= 1 << 4;

	/* Call IRQ_CallBack */
	GP_IRQ_CallBack[4]();

}

// EXTI5 ---> EXTI9
void EXTI9_5_IRQHandler (void)
{
	if (EXTI->PR & 1<<5)	{EXTI->PR |= (1<<5); GP_IRQ_CallBack[5]();}
	if (EXTI->PR & 1<<6)	{EXTI->PR |= (1<<6); GP_IRQ_CallBack[6]();}
	if (EXTI->PR & 1<<7)	{EXTI->PR |= (1<<7); GP_IRQ_CallBack[7]();}
	if (EXTI->PR & 1<<8)	{EXTI->PR |= (1<<8); GP_IRQ_CallBack[8]();}
	if (EXTI->PR & 1<<9)	{EXTI->PR |= (1<<9); GP_IRQ_CallBack[9]();}
}

// EXTI10 ---> EXTI15
void EXTI15_10_IRQHandler (void)
{
	if (EXTI->PR & 1<<10)	{EXTI->PR |= (1<<10); GP_IRQ_CallBack[10]();}
	if (EXTI->PR & 1<<11)	{EXTI->PR |= (1<<11); GP_IRQ_CallBack[11]();}
	if (EXTI->PR & 1<<12)	{EXTI->PR |= (1<<12); GP_IRQ_CallBack[12]();}
	if (EXTI->PR & 1<<13)	{EXTI->PR |= (1<<13); GP_IRQ_CallBack[13]();}
	if (EXTI->PR & 1<<14)	{EXTI->PR |= (1<<14); GP_IRQ_CallBack[14]();}
	if (EXTI->PR & 1<<15)	{EXTI->PR |= (1<<15); GP_IRQ_CallBack[15]();}
}
