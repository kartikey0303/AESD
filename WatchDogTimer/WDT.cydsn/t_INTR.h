/* ========================================
 * Name : Interrupt Basic
 * Date : 
 * Author : Kartikey Agrawal
 * Details : Header file for Interrupts
 * 			 Refer to Architecture Technical Reference Manual for futher details
 * 			 https://kartikey0303.github.io/pdf/Register_TRM.pdf
 * 			 https://kartikey0303.github.io/pdf/Arch_TRM.pdf
*/
#ifndef __t_INTR_H_
	#define __t_INTR_H_

	#include "t_udtypes.h"
   
	void INT_Disable(t_uint8 IRQ_N);
	void INT_Enable(t_uint8 IRQ_N);
	void INT_Set_Priority(t_uint8 IRQ_N,t_uint8 priority);
	void INT_Set_ISR_Address(t_uint8 IRQ_N,t_uint32 Address);

	t_uint8 t_EnterCriticalSection(void);
	void t_ExitCriticalSection(t_uint8);

	#define IRQ0 0u
	#define IRQ1 1u
	#define IRQ2 2u
	#define IRQ3 3u
	#define IRQ4 4u
	#define IRQ5 5u
	#define IRQ6 6u
	#define IRQ7 7u
	#define IRQ8 8u
	#define IRQ9 9u
	#define IRQ10 10u
	#define IRQ11 11u
	#define IRQ12 12u
	#define IRQ13 13u
	#define IRQ14 14u
	#define IRQ15 15u
	#define IRQ16 16u
	#define IRQ17 17u
	#define IRQ18 18u
	#define IRQ19 19u
	#define IRQ20 20u
	#define IRQ21 21u
	#define IRQ22 22u
	#define IRQ23 23u
	#define IRQ24 24u
	#define IRQ25 25u
	#define IRQ26 26u
	#define IRQ27 27u
	#define IRQ28 28u
	#define IRQ29 29u
	#define IRQ30 30u
	#define IRQ31 31u
	
	//https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=579
	#define t_INT_ClearEnable 0xE000E180u
	
	//https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=578
	#define t_INT_SetEnable 0xE000E100u
	
	//https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=582
	#define t_INT_PriorityInterrupt 0xE000E400u
	
	//https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=582
	#define t_INT_PriorityInterrupt 0xE000E400u
    
#endif

/* [] END OF FILE */
