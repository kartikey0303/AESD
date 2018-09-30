/* ========================================
 * Name : Interrupt Basic
 * Date : 17.09.18
 * Author : Kartikey Agrawal
 * Details : Source file for Interrupts
 * 			 Refer to Architecture Technical Reference Manual for futher details
 * 			 https://kartikey0303.github.io/pdf/Register_TRM.pdf
 * 			 https://kartikey0303.github.io/pdf/Arch_TRM.pdf
*/

#include "t_INTR.h"

/*
 * Name :       INT_Disable
 * Function :   Function to Disable Interrupt
 * Paramaters : IRQ_N ->
 * Details :	31 : 0 CLRENA Disables, or reads the enabled state of one 
 *				or more interrupts. Each bit corresponds to the same numbered interrupt. 
 *				Default Value: 0
 *
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=579
*/
void INT_Disable(t_uint8 IRQ_N)
{
    *((t_reg32*)(t_INT_ClearEnable))=(((t_uint32)0x01u) << IRQ_N);
}

/*
 * Name :       INT_Enable
 * Function :   Function to Enable Interrupt
 * Paramaters : IRQ_N ->
 * Details :	31 : 0 SETENA Enables, or reads the enabled state of one 
 *				or more interrupts. Each bit corresponds to the same numbered interrupt. 
 *				Default Value: 0
 *
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=578
*/
void INT_Enable(t_uint8 IRQ_N)
{
    *((t_reg32*)(t_INT_SetEnable))=(((t_uint32)0x01u) << IRQ_N);
}

/*
 * Name :       INT_Set_Priority
 * Function :   Function to Set Priority of Interrupt
 * Paramaters : IRQ_N ->
 * Details :	31 : 30 -> PRI_N3 Priority of interrupt number N+3. Default Value: 0
 *				23 : 22 -> PRI_N2 Priority of interrupt number N+2. Default Value: 0
 *				15 : 14 -> PRI_N1 Priority of interrupt number N+1. Default Value: 0
 *				7 : 6   -> PRI_N0 Priority of interrupt number N. Default Value: 0
 *
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=578
*/
void INT_Set_Priority(t_uint8 IRQ_N,t_uint8 priority)
{
    t_uint8 priorityOffset = ((IRQ_N % 4u) * 8u) + 6u;
    t_uint32 PRIO_REG = (t_INT_PriorityInterrupt + ((t_uint32)((IRQ_N/4)*4)));
    *(t_reg32*)(PRIO_REG)= (*(t_reg32 *) (PRIO_REG) & (~((t_uint32)0x3u<<priorityOffset)))|((t_uint32)priority << priorityOffset); 
}

void INT_Set_ISR_Address(t_uint8 IRQ_N,t_uint32 Address)
{
    *((t_reg32*)(0x20000040u+(t_uint32)(IRQ_N*4)))= Address;
}

/*
t_uint8 t_EnterCriticalSection()
{
    asm("MRS r0, PRIMASK");
    asm("CPSID I");
    asm("BX lr");
}

void t_ExitCriticalSection(t_uint8 t_IntrStatus)
{
    asm("MSR PRIMASK, r0");
    asm("BX lr");
}*/