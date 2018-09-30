/* ========================================
 * Name : Watchdog timer
 * Date : 20.09.18
 * Author : Kartikey Agrawal
 * Details : Source file for Watchdog Timer
 * 			 Refer to Architecture Technical Reference Manual for futher details
 * 			 https://kartikey0303.github.io/pdf/Register_TRM.pdf
 * 			 https://kartikey0303.github.io/pdf/Arch_TRM.pdf		
*/

#include "t_WDT.h"
#include "t_CLOCK.h"

/*
 * Name :       t_GetResetReason
 * Function :   Function to get the reason for reset
 * Paramaters : t_reason -
 * Details :    Get reason for reset
 * 				4 -> RESET_SOFT Cortex-M0 requested a system reset through it's SYSRESETREQ.  
 *					 This can be done via a debugger probe or in firmware
 * 				3 -> RESET_PROT_FAULT A protection violation occurred that requires a RESET.  This includes, but is not limited to, 
 *					 hitting a debug breakpoint while in Privileged Mode
 * 				0 -> A WatchDog Timer reset has occurred since last power cycle.
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=806
*/
t_uint32 t_GetResetReason(t_uint32 t_reason)
{
	t_uint32 t_returnStatus;

	t_reason &= (((t_uint32)1u << 0) | ((t_uint32)1u << 3) | ((t_uint32)1u << 4));
	t_returnStatus = (*(t_reg32 *) REG_RES_CAUSE) &(((t_uint32)1u << 0) | ((t_uint32)1u << 3)| ((t_uint32)1u << 4));
	(*(t_reg32 *)REG_RES_CAUSE) = t_reason;
	
	return (t_returnStatus);
}

/*
 * Name :       t_WDT_SetMatch
 * Function :   Function to set match value of register
 * Paramaters : t_CounterNo -> Counter No
 * 				t_Match -> Match Value
 * Details :    Set the match value for the register
 * 				 31 : 16 	WDT_MATCH1 Match value for Watchdog Counter 1 Default Value: 0
 * 				 15 : 0 	WDT_MATCH0 Match value for Watchdog Counter 0 Default Value: 0
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=801
*/
void t_WDT_SetMatch(t_uint32 t_CounterNo, t_uint32 t_Match)
{
	t_uint32 t_RegValue;
	/* Wait for previous changes to come into effect */
	//CyDelayUs((uint16)100u);
	t_Delay_us(100u);
	t_RegValue =  (*(t_reg32 *) REG_WDT_MATCH)& (~((t_uint32)((t_uint32)(0x0000FFFFu) << (t_CounterNo * 16u))));
	(*(t_reg32 *) REG_WDT_MATCH) = (t_RegValue | (t_Match << (t_CounterNo * 16u)));

	/* Make sure match synchronization has started */
	//CyDelayUs((uint16)35u);
	t_Delay_us(35u);

	/*
	t_Delay_us(100u);	
	(*(t_reg32*)REG_WDT_MATCH) = ((*(t_reg32*)REG_WDT_MATCH) & (~((0x0000FFFF) << (t_CounterNo * 16)))) | (t_Match);
	t_Delay_us(35u);*/
}

/*
 * Name :       t_WDT_ClearInterrupt
 * Function :   Function to Clear Interrupt
 * Paramaters : t_CounterMask -> Counter Mask
 * Details :    Clear Interrupt
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=804
*/
void t_WDT_ClearInterrupt(t_uint32 t_CounterMask)
{
	t_uint8 t_interruptState;      
	t_interruptState = t_EnterCriticalSection();
	t_CounterMask &= (((t_uint32)0x01u << 2u) |((t_uint32)0x01u << 10u) |((t_uint32)0x01u << 18u));
	(*(t_reg32 *)REG_WDT_CONTROL) = ((*(t_reg32 *)REG_WDT_CONTROL) & ~(((t_uint32)0x01u << 2u) |((t_uint32)0x01u << 10u) |((t_uint32)0x01u << 18u)))|t_CounterMask ;
	(void)(*(t_reg32 *) REG_WDT_CONTROL);
	t_ExitCriticalSection(t_interruptState);
}

/*
 * Name :       t_WDT_Enable
 * Function :   Function to Enable Counter
 * Paramaters : t_CounterNo -> Counter number
 * Details :    Clear Interrupt
 *				16 :  WDT_ENABLE2 Enable Counter 2 
 * 								  0: Counter is disabled (not clocked) 
 *								  1: Counter is enabled (counting up) 
 *								  Note: This field takes considerable time (up to 3 LFCLK cycles) to take effect.  
 * 								  It must not be changed more than once in that period. 
 *				8 :   WDT_ENABLE1 Enable Counter 1
 * 								  0: Counter is disabled (not clocked) 
 *								  1: Counter is enabled (counting up) 
 *								  Note: This field takes considerable time (up to 3 LFCLK cycles) to take effect.  
 * 								  It must not be changed more than once in that period.
 *				0 :   WDT_ENABLE0 Enable Counter 0
 * 								  0: Counter is disabled (not clocked) 
 *								  1: Counter is enabled (counting up) 
 *								  Note: This field takes considerable time (up to 3 LFCLK cycles) to take effect.  
 * 								  It must not be changed more than once in that period.
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=804
*/
void t_WDT_Enable(t_uint32 t_CounterNo)
{
	(*(t_reg32*) REG_WDT_CONTROL) = (*(t_reg32*)REG_WDT_CONTROL) | ((0x00000001) << (t_CounterNo * 0x08u));
	
	if(t_CounterNo == 0x00)
	{
		while(t_WDT_GetEnabledStatus(0x00) == 0)
		{
			
		}
	}
	if(t_CounterNo == 0x01)
	{
		while(t_WDT_GetEnabledStatus(0x01) == 0)
		{
			
		}
	}
	if(t_CounterNo == 0x02)
	{
		while(t_WDT_GetEnabledStatus(0x02) == 0)
		{
			
		}
	}
}

/*
 * Name :       t_WDT_GetEnabledStatus
 * Function :   Get Status of WDT
 * Paramaters : t_CounterNo -> CounterNo
 * Details :    
 * 				17 : WDT_ENABLED2 Indicates actual state of counter.  
 * 				May lag WDT_ENABLE2 by up to 3 LFCLK cycles.  
 *				After changing WDT_ENABLE2, do not enter DEEPSLEEP mode 
 *				until this field acknowledges the change.
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=804
*/
t_uint32 t_WDT_GetEnabledStatus(t_uint32 t_CounterNo)
{
	return (((*(t_reg32*) REG_WDT_CONTROL) >> ((0x08u * t_CounterNo) + 0x01u)) & 0x01u);
}

/*
 * Name :       t_WDT_SetCascade
 * Function :   Set Cascading Counters using WDT
 * Paramaters : t_CascadeMask -> Cascade Mask
 * Details :    
 * 				11 : WDT_CASCADE1_2 -> Cascade Watchdog Counters 1,2. 
 *				Counter 2 increments the cycle after WDT_CTR1=WDT_MATCH1. 
 *				It is allowed to cascade all three WDT counters. 
 *				0: Independent counters 
 *				1: Cascaded counters 
 *				Default Value: 0

 *				3 : WDT_CASCADE0_1 -> Cascade Watchdog Counters 0,1.  
 *				Counter 1 increments the cycle after WDT_CTR0=WDT_MATCH0.
 *				0: Independent counters 
 *				1: Cascaded counters 
 *				Default Value: 0
 
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=802
*/
void t_WDT_SetCascade(t_uint32 t_CascadeMask)
{
	t_uint32 t_ConfigRegValue;
	t_uint32 t_CountersEnableStatus;

	t_CountersEnableStatus = t_WDT_GetEnabledStatus(0x00) |
                            t_WDT_GetEnabledStatus(0x01) |
                            t_WDT_GetEnabledStatus(0x02);
	//Counter must not be enables before setting the Cascading
							
	if(t_CountersEnableStatus == 0)
	{
		t_ConfigRegValue = (*(t_reg32 *)REG_WDT_CONFIG)&((t_uint32)(~(((t_uint32)0x01u << 3u)|((t_uint32)0x01u << 11u))));
            t_ConfigRegValue |= t_CascadeMask;
            (*(t_reg32 *)REG_WDT_CONFIG) = t_ConfigRegValue;
	}
}

/*
 * Name :       t_WDT_SetClearOnMatch
 * Function :   Set value of Clear Bit when counter is equal to match
 * Paramaters : t_CounterNum -> Counter Number
 * 				t_Enable -> 
 * Details :    
 *				10 : WDT_CLEAR1 -> Clear Watchdog Counter when WDT_CTR1=WDT_MATCH1. 
 *				In other words WDT_CTR1 divides LFCLK by (WDT_MATCH1+1). 
 * 				0: Free running counter
 *				1: Clear on match 
 *				Default Value: 0 
 *
 *				2 : WDT_CLEAR0 -> Clear Watchdog Counter when WDT_CTR0=WDT_MATCH0. 
 *				In other words WDT_CTR0 divides LFCLK by (WDT_MATCH0+1). 
 * 				0: Free running counter
 *				1: Clear on match 
 *				Default Value: 0 
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=802
*/
void t_WDT_SetClearOnMatch(t_uint32 t_CounterNum, t_uint32 t_Enable)
{
	t_uint32 t_ConfigRegValue;

	if(0u == t_WDT_GetEnabledStatus(t_CounterNum))
	{
		t_ConfigRegValue = (*(t_reg32 *) REG_WDT_CONFIG) & ~(((t_uint32)((t_uint32)1u << (0x02u+(t_CounterNum * 0x08u)))));
		t_ConfigRegValue|= (t_uint32)(t_Enable << (0x02u+(t_CounterNum * 0x08u)));
		*(t_reg32 *)REG_WDT_CONFIG = t_ConfigRegValue;
	}
}

/*
 * Name :       t_WDT_SetMode
 * Function :   Set Mode of specified WDT
 * Paramaters : t_CounterNum -> Counter Number
 * 				t_Mode -> Mode Number
 * 					0x0: NOTHING: Do nothing
 *					0x1: INT: Assert WDT_INTx
 * 					0x2: RESET: Assert WDT Reset
 *					0x3: INT_THEN_RESET: Assert WDT_INTx, 
 *						 assert WDT Reset after 3rd unhandled interrupt
 *
 * Details :    
 *				(9 : 8) WDT_MODE1 -> Watchdog Counter Action on Match (WDT_CTR1=WDT_MATCH1)
 * 				Default Value: 0
 *				(1 : 0) WDT_MODE0 -> Watchdog Counter Action on Match (WDT_CTR1=WDT_MATCH0)
 * 				Default Value: 0
 *
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=802
*/
void t_WDT_SetMode(t_uint32 t_CounterNum, t_uint32 t_Mode)
{
	t_uint32 t_ConfigRegValue; 
	if(0u == t_WDT_GetEnabledStatus(t_CounterNum))
	{
		t_ConfigRegValue = (*(t_reg32 *)REG_WDT_CONFIG) & (~((t_uint32)((t_uint32)0x03u << (t_CounterNum * 0x08))));
		t_ConfigRegValue |= (t_uint32)((t_Mode & (t_uint32)(0x03u)) << (t_CounterNum * 0x08));
		(*(t_reg32 *)REG_WDT_CONFIG) = t_ConfigRegValue;
	}
}

t_uint32 t_WDT_GetMode(t_uint32 t_CounterNum)
{
	return (((*(t_reg32 *)0x400b020cu) >> (t_CounterNum * 0x08)) & ((t_uint32)(0x03u)));
}

/*
 * Name :       t_WDT_ResetCounter
 * Function :   Reset Counters of WDT
 * Paramaters : t_CounterMask -> 
 *
 * Details :    
 *				19 : WDT_RESET2 -> Resets counter 2 back to 0000_0000.  
 *				Hardware will reset this bit after counter was reset.  
 *				This will take several LFCLK cycles to take effect.  
 * 				Wait until the reset completes before enabling the WDT. 
 *				Default Value: 0
 *				11 : WDT_RESET1 -> Resets counter 2 back to 0000_0000.  
 *				Hardware will reset this bit after counter was reset.  
 *				This will take several LFCLK cycles to take effect.  
 * 				Wait until the reset completes before enabling the WDT. 
 *				Default Value: 0
 *				2 : WDT_RESET0 -> Resets counter 2 back to 0000_0000.  
 *				Hardware will reset this bit after counter was reset.  
 *				This will take several LFCLK cycles to take effect.  
 * 				Wait until the reset completes before enabling the WDT. 
 *				Default Value: 0
 *
 * 				https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=802
*/
//https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=804
void t_WDT_ResetCounters(t_uint32 t_CountersMask)
    {
        /* Set new WDT reset value */
        (*(t_reg32 *)REG_WDT_CONTROL) |= (t_CountersMask &(((t_uint32)0x01u << 3u) |((t_uint32)0x01u << 11u) |((t_uint32)0x01u << 19u)));

        while (((*(t_reg32 *)REG_WDT_CONTROL) & (((t_uint32)0x01u << 3u) |((t_uint32)0x01u << 11u) |((t_uint32)0x01u << 19u)))!=0)
        {
            /* Wait for reset to come into effect */
        }
    }
    
 void t_WDT_WatchdogFeed(t_uint32 t_CounterNum)
    {
        if(t_CounterNum == 0x00)
        {
            if(t_WDT_GetMode(t_CounterNum)==3)
            {
                t_WDT_ClearInterrupt(((t_uint32)0x01u << 2u));
            }
            else if(t_WDT_GetMode(t_CounterNum)==2)
            {
                t_WDT_ResetCounters(((t_uint32)0x01u << 3u));
                t_WDT_ClearInterrupt(((t_uint32)0x01u << 2u));
            }
            else
            {
                /* Do nothing. */
            }
        }
        else if(t_CounterNum == 0x01)
        {
            if(t_WDT_GetMode(t_CounterNum)==3)
            {
                t_WDT_ClearInterrupt(((t_uint32)0x01u << 10u));
            }
            else if(t_WDT_GetMode(t_CounterNum)==2)
            {
               t_WDT_ResetCounters(((t_uint32)0x01u << 11u));
                t_WDT_ClearInterrupt(((t_uint32)0x01u << 10u));
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            /* Do nothing. */
        }
    }




