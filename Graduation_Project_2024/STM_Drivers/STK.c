/*
 * STK.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */


#include "STM32f103x6.h"

#include "STK.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define STK_u32_BASE_ADDRESS						0xE000E010U

typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
}STK_RegDef_t;

#define STK						((STK_RegDef_t *)STK_u32_BASE_ADDRESS)
/*******************************************************************************
*                           Global Variables                                  *
*******************************************************************************/

/* to store the address of the function to be the ISR */
static void (*STK_Pf)(void) = NULL;
static uint8_t STK_u8ModeOfInterval; /* Variable to save the current mode of the STK */

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		STK_voidInit
********************************************************************************/
uint8_t STK_u8Init(uint8_t Copy_u8ClockSource)
{
	uint8_t Local_u8ErrorState = STD_TYPES_OK;

	/* Choose the Clock Source */
	if(Copy_u8ClockSource == STK_u8_AHB)
	{
		SET_BIT(STK->CTRL,2);
	}
	else if (Copy_u8ClockSource == STK_u8_AHB_8)
	{
		CLR_BIT(STK->CTRL,2);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	/* Disable the timer */
	CLR_BIT(STK->CTRL,0);

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetBusyWait
********************************************************************************/
 uint8_t STK_u8SetuSBusyWait(uint32_t Copy_u32Time_us)
{
	 uint8_t Local_u8ErrorState = STD_TYPES_OK;
	uint32_t Local_u32LoadValue;

	if(GET_BIT(STK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u32LoadValue = (F_CPU/1000000)*Copy_u32Time_us ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u32LoadValue = (F_CPU/8000000)*Copy_u32Time_us ;
	}

	if(Local_u32LoadValue <= 0x00FFFFFFFF)
	{
		/* Close the exception request */
		CLR_BIT(STK->CTRL,1);
		/* Load the required delay */
		STK->LOAD = Local_u32LoadValue ;
		/* Enable the timer */
		SET_BIT(STK->CTRL,0);
		/* Start the change immediately by writing any value to VAL register */
		STK->VAL = 0;
		/* Wait until timer reach zero */
		while(GET_BIT(STK->CTRL,16) == 0);
		/* Disable Timer */
		CLR_BIT(STK->CTRL,0);
		STK->LOAD = 0;
		STK->VAL  = 0;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetmSBusyWait
********************************************************************************/
 uint8_t STK_u8SetmSBusyWait(uint32_t Copy_u32Time_ms)
{
	 uint8_t Local_u8ErrorState = STD_TYPES_OK;

	for(uint32_t i = 0 ; i < Copy_u32Time_ms ; i++)
	{
		STK_u8SetuSBusyWait(1000);
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetIntervalSingle
********************************************************************************/
 uint8_t STK_u8SetIntervalSingle(uint32_t Copy_u32Time_us, void(*Copy_pf)(void))
{
	 uint8_t Local_u8ErrorState = STD_TYPES_OK;
	uint32_t Local_u32LoadValue;

	if(GET_BIT(STK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u32LoadValue = (F_CPU/1000000)*Copy_u32Time_us ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u32LoadValue = (F_CPU/8000000)*Copy_u32Time_us ;
	}
	if((Local_u32LoadValue <= 0x00FFFFFF) && (Copy_pf != NULL))
	{
		/* Set Callback Function */
		STK_Pf = Copy_pf;
		/* Load the required delay */
		STK->LOAD = Local_u32LoadValue ;
		/* Enable the timer */
		SET_BIT(STK->CTRL,0);
		/* Set the mode = interval */
		STK_u8ModeOfInterval = STK_u8_SINGLE_INTERVAL;
		/* Enable the exception request */
		SET_BIT(STK->CTRL,1);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetIntervalPeriodic
********************************************************************************/
 uint8_t STK_u8SetIntervalPeriodic(uint32_t Copy_u32Time_us, void(*Copy_pf)(void))
{
	 uint8_t Local_u8ErrorState = STD_TYPES_NOK;
	uint32_t Local_u8LoadValue;

	if(GET_BIT(STK->CTRL,2)) /* The clock source is AHB/1 */
	{
		Local_u8LoadValue = (F_CPU/1000000)*Copy_u32Time_us ;
	}
	else /* The clock source is AHB/8 */
	{
		Local_u8LoadValue = (F_CPU/8000000)*Copy_u32Time_us ;
	}
	if((Local_u8LoadValue <= 0x00FFFFFF) && (Copy_pf != NULL))
	{
		/* Set Callback Function */
		STK_Pf = Copy_pf;
		/* Load the required delay */
		STK->LOAD = Local_u8LoadValue-1 ;
		/* Enable the timer */
		SET_BIT(STK->CTRL,0);
		/* Set the mode = interval */
		STK_u8ModeOfInterval = STK_u8_PERIODIC_INTERVAL;
		/* Enable the exception request */
		SET_BIT(STK->CTRL,1);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8Stop
********************************************************************************/
 uint8_t STK_u8Stop(void)
{
	 uint8_t Local_u8ErrorState = STD_TYPES_OK;

	CLR_BIT(STK->CTRL,0);
	STK->LOAD = 0;
	STK->VAL  = 0;

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8GetElapsedTime
********************************************************************************/
 uint8_t STK_u8GetElapsedTime      (uint32_t * Copy_pu32ElapsedTime)
{
	 uint8_t Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_pu32ElapsedTime != NULL)
	{
		*Copy_pu32ElapsedTime = (STK->LOAD - STK->VAL) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8GetRemainingTime
********************************************************************************/
 uint8_t STK_u8GetRemainingTime    (uint32_t * Copy_pu32RemainingTime)
{
	 uint8_t Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_pu32RemainingTime != NULL)
	{
		*Copy_pu32RemainingTime = STK->VAL ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
*                       Interrupt Service Routines                            *
*******************************************************************************/
void SysTick_Handler(void)
{
	if(STK_u8ModeOfInterval == STK_u8_SINGLE_INTERVAL)
	{
		/* Disable and Stop The Timer */
		CLR_BIT(STK->CTRL,0);
		CLR_BIT(STK->CTRL,1);
		STK->LOAD = 0;
		STK->VAL  = 0;
	}
	if(STK_Pf != NULL)
	{
		STK_Pf();
	}
	/* Clear The Interrupt Flag */
	CLR_BIT(STK->CTRL,16);
}
