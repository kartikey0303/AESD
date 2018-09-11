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
    Timer_1_Start();
    Timer_2_Start();
    
    CY_ISR_PROTO(Timer_1_ISR);
    CY_ISR_PROTO(Timer_2_ISR);
    
    isr_1_StartEx(Timer_1_ISR);
    isr_2_StartEx(Timer_2_ISR);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

CY_ISR(Timer_1_ISR)
{
    Timer_1_ClearInterrupt(Timer_1_TC_INTERRUPT_MASK);
    RED_LED_Write(0);
    CyDelay(500);
    RED_LED_Write(1);
}

CY_ISR(Timer_2_ISR)
{
    Timer_2_ClearInterrupt(Timer_2_TC_INTERRUPT_MASK);
    GREEN_LED_Write(0);
    CyDelay(500);
    GREEN_LED_Write(1);
}
/* [] END OF FILE */
