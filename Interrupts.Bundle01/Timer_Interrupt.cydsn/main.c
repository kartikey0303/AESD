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
    Timer_Start();
    CY_ISR_PROTO(Timer_ISR);
    isr_StartEx(Timer_ISR);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}
CY_ISR(Timer_ISR)
{
    Timer_ClearInterrupt(Timer_TC_INTERRUPT_MASK);
    GREEN_LED_Write(~GREEN_LED_Read());
}

/* [] END OF FILE */
