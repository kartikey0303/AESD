#include <project.h>
CY_ISR_PROTO(IND_ISR);
int main()
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    TCPWM_Start();
    isr_1_StartEx(IND_ISR);
    uint8 InterruptState;
for(;;)
    {    
        InterruptState=CyEnterCriticalSection();
        Pin_LED_Write(0);
        CyDelay(5200);
        CyExitCriticalSection(InterruptState);
        Pin_LED_Write(1);
        CyDelay(5200);
    }
}

CY_ISR(IND_ISR)
{
    TCPWM_ClearInterrupt(TCPWM_INTR_MASK_TC);
    Pin_LED_1_Write(0);
    CyDelay(500);
    Pin_LED_1_Write(1);
    
}