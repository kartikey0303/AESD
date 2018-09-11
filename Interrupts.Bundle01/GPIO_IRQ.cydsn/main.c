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

    CY_ISR_PROTO(GPIO_ISR);
        
    isr_StartEx(GPIO_ISR);

    for(;;)
    {
       
    }
}

CY_ISR(GPIO_ISR)
{
    SW_ClearInterrupt();
    RED_LED_Write(~RED_LED_Read());
}

/* [] END OF FILE */
