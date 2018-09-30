
#include "project.h"

CY_ISR_PROTO(WakeUp_Isr);

int main(void)
{
	isr_WakeUp_StartEx(WakeUp_Isr);
	
    CyGlobalIntEnable; /* Enable global interrupts. */
	
	Timer_1_Start(); /* Start Timer compoenent */
	
	
	/* If Reset is because of Hibernate i.e. interrrupt is raised to come back
	 * from Hibernate, the Blue LED will blink
	 */
	if(CySysPmGetResetReason() == CY_PM_RESET_REASON_WAKEUP_HIB)
	{
		RESET_LED_Write(0);
		CyDelay(500);
		RESET_LED_Write(1);
	}
	
	/* If Reset is because of Stop i.e. WakeUp pin is raised to LOW to come back
	 * from Stop Mode, the Blue LED will blink. But the IO pins must be unfrozen
	 */
	if(CySysPmGetResetReason() == CY_PM_RESET_REASON_WAKEUP_STOP)
	{
		/* IOs must be unfrozen after STOP mode */
		CySysPmUnfreezeIo();
		RESET_LED_Write(0);
		CyDelay(500);
		RESET_LED_Write(1);
	}
	
    for(;;)
    {
		//Timer_1_Start();	
		LED_Write(0); /* LED ON */
		while(ModeSwitch_Read() != 0u); /* Wait Until switch is being pressed */
		while(ModeSwitch_Read() == 0u); /* Wait until the switch is released*/
		CyDelay(200); /* Wait for 200ms for debouncing*/
		LED_Write(1); /* LED OFF */
		
		/* Timer is a UDB component, it will keep working */
		//CySysPmSleep(); /* Enter into Sleep Mode */
		
		/* Timer will stop working, so it will retain the state of Green LED */
		//CySysPmDeepSleep(); /* Enter into Deep Sleep Mode */
		
		/* UDB is completely off
		 * To come back to active mode Reset must be pressed
		 */
		//CySysPmHibernate(); /* Enter into Hibernate Mode */
		
		/* To come back to active mode, send LOW to P0[7] */
		CySysPmSetWakeupPolarity(CY_PM_STOP_WAKEUP_ACTIVE_LOW);/*P0[7] is the wakeup pin*/
		CySysPmStop();/*Enter into Stop Mode*/
		
		/* If Interrupt is falling edge, not required for rising edge*/
		while(ModeSwitch_Read() == 0u); /* Wait for button */
    }
}

CY_ISR(WakeUp_Isr)
{
	ModeSwitch_ClearInterrupt();
}

/* [] END OF FILE */
