/* ========================================
 * Name : Watchdog Timer 
 * Date : 20.09.18
 * Author : Kartikey Agrawal
 * Details : Header file for Watchdog timer
 * 			 Refer to Architecture Technical Reference Manual for futher details
 * 			 https://kartikey0303.github.io/pdf/Register_TRM.pdf
 * 			 https://kartikey0303.github.io/pdf/Arch_TRM.pdf
*/


#ifndef __t_WDT_H_
	#define __t_WDT_H_
	
	#include "t_udtypes.h"
	
	t_uint32 t_GetResetReason(t_uint32);
	void t_WDT_SetMatch(t_uint32, t_uint32);
	void t_WDT_ClearInterrupt(t_uint32);
	void t_WDT_Enable(t_uint32);
	t_uint32 t_WDT_GetEnabledStatus(t_uint32);
	void t_WDT_SetCascade(t_uint32);
	void t_WDT_SetClearOnMatch(t_uint32, t_uint32);
	void t_WDT_SetMode(t_uint32, t_uint32);
	
	t_uint32 t_WDT_GetMode(t_uint32);
	
	t_uint32 t_WDT_GetMode(t_uint32);
	
	void t_WDT_ResetCounters(t_uint32);
	
	void t_WDT_WatchdogFeed(t_uint32);
	
	/*
	 * https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=806
	 */
	#define REG_WDT_CAUSE 0x400B0300u
	
	/* Match value for Counter 1 and Counter 2
	 * https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=801
	 */
	#define REG_WDT_MATCH 0x400B0208u
	
	/* To set the mode of counter
	 * https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=802s
	 */
	#define REG_WDT_CONFIG 0x400B020Cu
	
	/* Control Watchdog Timer
	 * https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=804
	 */
	#define REG_WDT_CONTROL 0x400B0210u
	
	/* Watchdog Counters 0/1
	 * https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=799
	 */
	#define REG_WDT_CTR_LOW 0x400B0200u
	
	/* Watchdog Counters 2
	 * https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=800
	 */
	#define REG_WDT_CTR_HIGH 0x400B0204u
	
	/* Reset Cause Observation Register
	 * https://kartikey0303.github.io/pdf/Register_TRM.pdf#page=806
	 */
	#define REG_RES_CAUSE 0x400B0300u
	
#endif
