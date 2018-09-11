/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    CY_ISR_PROTO(IND_ISR);
    CY_ISR_PROTO(IND_1_ISR);

    Timer_1_Start();
    isr_1_StartEx(IND_ISR);
    isr_2_StartEx(IND_1_ISR);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}
CY_ISR(IND_ISR)
	{
   	Timer_1_ClearInterrupt(Timer_1_INTR_MASK_TC);
    RED_LED_Write(0);
   	CyDelay(5000);
    RED_LED_Write(1);
    CyDelay(5000);
    }

    CY_ISR(IND_1_ISR)
	{
    	GREEN_LED_Write(0);
    	CyDelay(500);
    	GREEN_LED_Write(1);
	}

/* [] END OF FILE */
