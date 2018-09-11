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

void t_DelayCycles(t_uint32);

t_uint8 t_EnterCriticalSection(void);

void t_ExitCriticalSection(t_uint8);

int main(void)
{
	//500 Cycles delay
	t_DelayCycles(500);
    for(;;)
    {
    }
}

/*
 * Name :       t_DelayCycles
 * Function :   To give a delay of "cycles" Cycles
 * Paramaters : cycles - unsigned long
 * Details :    The value of "cycles" is stored in R0 where it is decremented 
 *				writen in assembly language
*/
void t_DelayCycles(t_uint32 cycles)
{
	asm("LSR R0, #2");
	asm("BEQ t_CyclesDone");
	asm("t_LOOP: SUB R0, #1");
	asm("BNE t_LOOP");
	asm("t_CyclesDone: BX LR");
}
