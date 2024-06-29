/*
 * STK.h
 *
 *  Created on: Jun 28, 2024
 *      Author: Yahya
 */

#ifndef INC_STK_H_
#define INC_STK_H_



/*******************************************************************************
*                        		SYSTICK TYPE	                               *
*******************************************************************************/

#define STK_u8_PERIODIC_INTERVAL		0
#define STK_u8_SINGLE_INTERVAL			1



/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

/*******************************************************************************
*                        		Clock Source	                               *
*******************************************************************************/
#define STK_u8_AHB						0
#define STK_u8_AHB_8					1

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		STK_u8Init
* Description:			Function to init the systick clock source and disable it
* Parameters (in):    	void
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
uint8_t STK_u8Init(uint8_t Copy_u8ClockSource);

/*******************************************************************************
* Function Name:		STK_u8SetuSBusyWait
* Description:			Function to create microsecond delay with the systick timer
* Parameters (in):    	The number of ticks required to delay
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
uint8_t STK_u8SetuSBusyWait(uint32_t Copy_u32TimeInUs);

/*******************************************************************************
* Function Name:		STK_u8SetmSBusyWait
* Description:			Function to create millisecond delay with the systick timer
* Parameters (in):    	The number of ticks required to delay
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
uint8_t STK_u8SetmSBusyWait(uint32_t Copy_u32msTime);

/*******************************************************************************
* Function Name:		STK_u8SetIntervalSingle
* Description:			Function to create single shot interrupt
* Parameters (in):    	The number of ticks required to fire the interrupt
* 						Pointer to fuction to be the systick handler
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
uint8_t STK_u8SetIntervalSingle(uint32_t Copy_u32NumOfTicks, void(*Copy_pf)(void));

/*******************************************************************************
* Function Name:		STK_u8SetIntervalPeriodic
* Description:			Function to create periodic interrupt
* Parameters (in):    	The number of ticks required to fire the interrupt
* 						Pointer to fuction to be the systick handler
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
uint8_t STK_u8SetIntervalPeriodic(uint32_t Copy_u32NumOfTicks, void(*Copy_pf)(void));

/*******************************************************************************
* Function Name:		STK_u8Stop
* Description:			Function to stop and disable the systick timer
* Parameters (in):    	void
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
uint8_t STK_u8Stop(void);

/*******************************************************************************
* Function Name:		STK_u8GetElapsedTime
* Description:			Function to calculate the elapsed time
* Parameters (in):    	Pointer to variable to save the elapsed time in it
* Parameters (out):   	void
* Return value:      	None
********************************************************************************/
uint8_t STK_u8GetElapsedTime      (uint32_t * Copy_pu32ElapsedTime);

/*******************************************************************************
* Function Name:		STK_u8GetRemainingTime
* Description:			Function to calculate the remaining time
* Parameters (in):    	Pointer to variable to save the remaining time in it
* Parameters (out):   	void
* Return value:      	None
********************************************************************************/
uint8_t STK_u8GetRemainingTime    (uint32_t * Copy_pu32RemainingTime);





#endif /* INC_STK_H_ */
