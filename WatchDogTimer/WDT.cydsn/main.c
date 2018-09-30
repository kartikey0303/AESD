#include "t_INTR.h"
#include "t_udtypes.h"
#include "t_GPIO.h"
#include "t_WDT.h"
#include "t_CLOCK.h"

void t_WDT_ISR(void);

int main()
{
	
	t_ClkWriteImoFreq(48);
	t_ClkWriteHfclkDirect(0);
	t_ClkWriteSysClkDiv(0);
	
	asm("CPSIE   i");
	INT_Disable(IRQ7);
	INT_Set_ISR_Address(IRQ7,(t_uint32)t_WDT_ISR);
	GPIO_SET_MODE(GPIO_PRT0_PC, 6, GPIO_DM_STRONG);
	GPIO_SET_MODE(GPIO_PRT2_PC, 6, GPIO_DM_STRONG);
	GPIO_SET_MODE(GPIO_PRT6_PC, 5, GPIO_DM_STRONG);
	GPIO_WRITE_PIN(GPIO_PRT0_DR, 6, 1);
	GPIO_WRITE_PIN(GPIO_PRT2_DR, 6, 1);
	GPIO_WRITE_PIN(GPIO_PRT6_DR, 5, 1);
	
	
	if (t_GetResetReason(((t_uint32)1u <<0))==0)
	{
		/* Toggle LED_Reset at startup after PowerUp/XRES event. */
		GPIO_WRITE_PIN(GPIO_PRT0_DR, 6, 0);            //RED
		t_Delay_ms(500);
		//CyDelay(500)
		GPIO_WRITE_PIN(GPIO_PRT0_DR, 6, 1);
	}
	
	else
	{
	/* Toggle LED_WdtReset at startup after WDT reset event. */
		GPIO_WRITE_PIN(GPIO_PRT6_DR, 5, 0);        //GREEN
		t_Delay_ms(500);
		//CyDelay(100);
		GPIO_WRITE_PIN(GPIO_PRT6_DR, 5, 1);
	}

	/* Set WDT counter 0 to generate interrupt on match */
	t_WDT_SetMode(0, 1);
	
	/* Loading Match Value of 0x4FFF 
	 * 0x4FFF * (1/32k)
	 */
	t_WDT_SetMatch(0, 0x4FFF);
	
	/* Clear Counter on Match */
	t_WDT_SetClearOnMatch(0, 1);

	/* Enable WDT counters 0 and 1 cascade */
	t_WDT_SetCascade(((t_uint32)0x01u << 3u));

	/* Set WDT counter 1 to generate reset on match */
	t_WDT_SetMatch(1,0x0008);

	/* Set Mode for counter 1 */
	t_WDT_SetMode(1, 2);

	/*  */
	t_WDT_SetClearOnMatch(1, 1);
	
	
	/* Enable WDT counters 0 and 1 */
	t_WDT_Enable((t_uint32)0x01 | ((t_uint32)(1UL<<8)));
	INT_Enable(IRQ7);	
	for(;;)
	{

	}
}

void t_WDT_ISR (void)
{
	/* Toggle pin state */
	GPIO_WRITE_PIN(GPIO_PRT2_DR, 6, ~GPIO_READ_PIN(GPIO_PRT2_PS, 6));; //GREEN

	/* Clear interrupts state */
	t_WDT_ClearInterrupt(((t_uint32)0x01u << 2u));

}
