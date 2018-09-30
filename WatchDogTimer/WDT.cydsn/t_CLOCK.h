/* ========================================
 * Name : Clock Basic
 * Date : 17.09.18
 * Author : Kartikey Agrawal
 * Details : Header file for Clocking System
 * 			 Refer to Architecture Technical Reference Manual for futher details
 * 			 https://kartikey0303.github.io/pdf/Register_TRM.pdf
 * 			 https://kartikey0303.github.io/pdf/Arch_TRM.pdf
*/

#ifndef __T_CLOCK_H_
	#define __T_CLOCK_H_
	
	#include "t_udtypes.h"	
	void t_DelayCycles(t_uint32);

	t_uint8 t_EnterCriticalSection(void);

	void t_ExitCriticalSection(t_uint8);

	void t_ClkWriteImoFreq(t_uint8);
	
	//High frequency clock 
	//select between IMO or High Frequency clock
	void t_ClkWriteHfclkDirect(t_uint32);
	
	void t_ClkWriteSysClkDiv(t_uint32);
	
	void t_Delay_ms(t_uint32);
	void t_Delay_us(t_uint32);

	#define REG_CLK_SELECT 0x400b0100u
	#define REG_CLK_IMO_TRIM1 0x400BFF28u
	#define REG_CLK_IMO_TRIM2 0x400BFF2Cu
	#define REG_PWR_BG_TRIM4 0x400BFF1Cu
	#define REG_PWR_BR_TRIM5 0x400BFF20u

	#define SFLASH_IMO_TRIM_BASE 0x0FFFF1D0u
	#define SFLASH_IMO_MAXF0 0x0FFFF1C0u
	#define SFLASH_IMO_ABS0 0x0FFFF1C1u
	#define SFLASH_IMO_TMPCO0 0x0FFFF1C2u

	#define SFLASH_IMO_MAXF1 0x0FFFF1C3u
	#define SFLASH_IMO_ABS1 0x0FFFF1C4u
	#define SFLASH_IMO_TMPCO1 0x0FFFF1C5u

	#define SFLASH_IMO_MAXF2 0x0FFFF1C6u
	#define SFLASH_IMO_ABS2 0x0FFFF1C7u
	#define SFLASH_IMO_TMPCO2 0x0FFFF1C8u

	#define SFLASH_IMO_MAXF3 0x0FFFF1C9u
	#define SFLASH_IMO_ABS3 0x0FFFF1CAu
	#define SFLASH_IMO_TMPCO3 0x0FFFF1CBu

	#define SFLASH_IMO_ABS4 0x0FFFF1CCu
	#define SFLASH_IMO_TMPCO4 0x0FFFF1CDu
	
#endif
/* [] END OF FILE */
