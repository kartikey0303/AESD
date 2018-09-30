/* ========================================
 * Name : Clock Basic
 * Date : 11.09.18
 * Author : Kartikey Agrawal
 * Details : Basic implemention of setting clock in Clock
 * 			 Refer to Architecture Technical Reference Manual for futher details
 * https://drive.google.com/file/d/0B3i9TBs6C1vTdnVqTFlRdkxKeTRFY0tnaFZoVHBrVnJtY1E0/view?usp=drive_open		
*/


/* R0 = 100
 * LSR R0, #2
 * BEQ t_CyclesDone
 * t_loop : SUB R0,#1
 * BNE t_loop; Branch if not equal
 * t_CyclesDone : BX LR
*/
#include "t_udtypes.h"
#include "t_CLOCK.h"
#include "t_GPIO.h"

int main(void)
{
	GPIO_SET_MODE(GPIO_PRT2_PC, 6, GPIO_DM_STRONG);
	/*b) 48
	t_ClkWriteImoFreq(48u);*/
	
	//c)
	t_ClkWriteImoFreq(12u);
	
	t_ClkWriteHfclkDirect(0x00);
	
	/*a)
	t_ClkWriteSysClkDiv(0);*/
	
	/*b)(1/24)MHz
	t_ClkWriteSysClkDiv(1);*/
	
	//c)
	t_ClkWriteSysClkDiv(0);
    for(;;)
    {
		GPIO_WRITE_PIN(GPIO_PRT2_DR, 6, 0);
		//t_Delay_ms(500);
		
		/*b) 48 * (1/24)
		t_DelayCycles(48000000);*/
		
		//c)delay of 0.25sec
		t_DelayCycles(3000000);
		
		GPIO_WRITE_PIN(GPIO_PRT2_DR, 6, 1);
		
		//t_Delay_ms(500);
		
		//t_DelayCycles(48000000);
		
		//c)
		t_DelayCycles(3000000);
    }
}


