/* ========================================
 *
 * Kartikey Agrawal
 * Date : 21/08/18 & 27/08/18 & 29/08/18
 * Advanced Embedded Systems
 * Topic : Using basic bit operations enabling interrupts
 * ========================================
*/

#include "t_GPIO.h"
#include "t_UDTYPES.h"

void GPIO_ISR(void);

int main(void)
{
	GPIO_WRITE_PIN(GPIO_PRT0_DR, 7, 1);
	//Set pin 7 as Resistive Pull up
	GPIO_SET_MODE(GPIO_PRT0_PC, 7, GPIO_DM_RPU);
	//Set pin 6 as Strong mode
	GPIO_SET_MODE(GPIO_PRT0_PC, 6, GPIO_DM_A_STRONG);
	
	//TO enable global interrupt use PRIMASK Register
	__asm("CPSIE I");//assembly instruction
	
	//To disable IRQ0 interrupt , because while configuring we need to disable the interrupt
	//CM0_ICER
	(*(t_reg32*)0xE000E180) = 0x00000001;
	
	/*Ideally we want to do
	 * (*(t_reg32*)0x00000040u) = (t_reg32) ( &GPIO_ISR);
	 * But code memory cannot be changed dynamically
	 */
	
	//The starting address of ISR us placed into vector location(table)
	(*(t_reg32*)(0x20000040u)) = (t_reg32) (&GPIO_ISR);
	
	//To configure P0[7]'s rising edge as the source of interrupt
	(*(t_reg32*)(0x4004000C)) = ((*t_reg32*)(0x4004000C)) & (~((t_uint32)0x03u << (0x077u*0x02u)))|(t_uint32)(0x01u <<(0x07
	
	//To assign priority to IRQ0
	//insert link for pdf - PSoC_4200M
	//insert link for pdf - PSoC 4200M Registers - TRM - page 10 - CM0_IPR0
	(*(t_reg32*)0xE000E400) = ((*(t_reg32*)0xE000E400) & ((t_uint32)(~(0xC0)))) | ((t_uint32)(0x03u << 6));
	
	//Now we need to enable interrupt
	//CM0_
	(*(t_reg32*)(0xE000E100)) = 0x01u;
}

void GPIO_ISR(void)
{
}

/* [] END OF FILE */
