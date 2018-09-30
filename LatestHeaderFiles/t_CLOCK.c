/* ========================================
 * Name : Clock Basic
 * Date : 17.09.18
 * Author : Kartikey Agrawal
 * Details : Source file for Clocking
 * 			 Refer to Architecture Technical Reference Manual for futher details
 * https://drive.google.com/file/d/0B3i9TBs6C1vTdnVqTFlRdkxKeTRFY0tnaFZoVHBrVnJtY1E0/view?usp=drive_open		
*/

#include "t_CLOCK.h"

//setting default frequency as 48MHz
t_uint32 t_sys_freq = 48000000;
const t_reg8 t_ImoFreqMhz2Reg[46] = {
            /*  3 MHz */ 0x03u,  /*  4 MHz */ 0x04u,  /*  5 MHz */ 0x05u,  /*  6 MHz */ 0x06u,
            /*  7 MHz */ 0x07u,  /*  8 MHz */ 0x08u,  /*  9 MHz */ 0x09u,  /* 10 MHz */ 0x0Au,
            /* 11 MHz */ 0x0Bu,  /* 12 MHz */ 0x0Cu,  /* 13 MHz */ 0x0Eu,  /* 14 MHz */ 0x0Fu,
            /* 15 MHz */ 0x10u,  /* 16 MHz */ 0x11u,  /* 17 MHz */ 0x12u,  /* 18 MHz */ 0x13u,
            /* 19 MHz */ 0x14u,  /* 20 MHz */ 0x15u,  /* 21 MHz */ 0x16u,  /* 22 MHz */ 0x17u,
            /* 23 MHz */ 0x18u,  /* 24 MHz */ 0x19u,  /* 25 MHz */ 0x1Bu,  /* 26 MHz */ 0x1Cu,
            /* 27 MHz */ 0x1Du,  /* 28 MHz */ 0x1Eu,  /* 29 MHz */ 0x1Fu,  /* 30 MHz */ 0x20u,
            /* 31 MHz */ 0x21u,  /* 32 MHz */ 0x22u,  /* 33 MHz */ 0x23u,  /* 34 MHz */ 0x25u,
            /* 35 MHz */ 0x26u,  /* 36 MHz */ 0x27u,  /* 37 MHz */ 0x28u,  /* 38 MHz */ 0x29u,
            /* 39 MHz */ 0x2Au,  /* 40 MHz */ 0x2Bu,  /* 41 MHz */ 0x2Eu,  /* 42 MHz */ 0x2Fu,
            /* 43 MHz */ 0x30u,  /* 44 MHz */ 0x31u,  /* 45 MHz */ 0x32u,  /* 46 MHz */ 0x33u,
            /* 47 MHz */ 0x34u,  /* 48 MHz */ 0x35u };


/*
 * Name :       t_ClkWriteHfclkDirect()
 * Function :   Select between source for High Frequency Clock 1) IMO 2)External Clock
 * Paramaters : t_clkselect
 * Details :    The value of "cycles" is stored in R0 where it is decremented 
 *				writen in assembly language
*/
void t_ClkWriteHfclkDirect(t_uint32 t_clkselect)
{
	t_uint8 t_interruptState = t_EnterCriticalSection();
	
	(*(t_reg32*)REG_CLK_SELECT) = (*(t_reg32 *) 0x400b0100u)& ~((( t_uint32 ) 0x07u) |(t_clkselect & (t_uint32)0x07u));
	
    t_ExitCriticalSection(t_interruptState);
}

/*
 * Name :       t_ClkWriteSysclkDiv()
 * Function :   To divide the high frequency clock to get the required clock frequency
 * Paramaters : t_divider
 * Details :    0x400b0100u = CLK_SELECT -> refer Register_Technical Reference manual
*/
void t_ClkWriteSysClkDiv(t_uint32 t_divider)
{
    t_uint8  t_interruptState = t_EnterCriticalSection();
    t_uint8 t_Sys_Clk_Div[8]={1,2,4,8,16,32,64,128};
	
	//21,20,19 clear and set that bit
    (*(t_reg32 *) REG_CLK_SELECT) = ((*(t_reg32 *) REG_CLK_SELECT) & ((t_uint32)(~(t_uint32)((t_uint32 )0x07u) << 19)))|((t_uint32)(((t_uint32)t_divider & (( t_uint32 )0x07u)) << (19u)));
    t_sys_freq = t_sys_freq / t_Sys_Clk_Div[t_divider];
    t_ExitCriticalSection(t_interruptState);
	
}

/*
 * Name :       t_Delay_ms
 * Function :   To provide delay in Milli-seconds
 * Paramaters : t_time_ms
 * Details :    
*/
void t_Delay_ms(t_uint32 t_time_ms)
{
	//MHz to KHz andn delay for that time
	t_DelayCycles(t_time_ms *(t_sys_freq/1000u));
}

/*
 * Name :       t_Delay_us
 * Function :   To provide delay in Micro-seconds
 * Paramaters : t_time_us
 * Details :    
*/
void t_Delay_us(t_uint32 t_time_us)
{
   t_DelayCycles(t_time_us *(t_sys_freq/1000000u));
}

/*
 * Name :       t_DelayCycles
 * Function :   To give a delay of "cycles" Cycles
 * Paramaters : cycles - unsigned long
 * Details :    The value of "cycles" is stored in R0 where it is decremented 
 *				writen in assembly language
*/
t_DelayCycles(t_uint32 cycles)
{
	asm("LSR R0, #2");
	asm("BEQ t_CyclesDone");
	asm("t_LOOP: SUB R0, #1");
	asm("BNE t_LOOP");
	asm("t_CyclesDone: BX LR");
}

t_uint8 t_EnterCriticalSection(void)
{
	//Move from Special to working register
	asm("MRS R0, PRIMASK");
	//Disable Interrupt
	asm("CPSID I");
	//
	asm("BX LR");
}

/*
 * Name :       t_ExitCriticalSection
 * Function :   To exit critical section
 * Paramaters : t_IntrStatus -> which sends the value of R0
 * Details :    The value of "cycles" is stored in R0 where it is decremented 
 *				writen in assembly language
*/
void t_ExitCriticalSection(t_uint8 t_IntrStatus)
{
	asm("MSR PRIMASK, R0");
	asm("BX LR");
}


/*
 * Name :       t_ClkWriteImoFreq
 * Function :   To write frequency
 * Paramaters : t_freq -> value of frequency required
 * Details :    Clocking algorith implmentation
 *				For details see : 
*/
void t_ClkWriteImoFreq(t_uint8 t_freq)
{
	t_uint8 t_bgtrim4;
	t_uint8 t_bgtrim5;
	t_uint8 t_newImoTrim2Value;
	t_uint8 t_currentImoTrim2Value;
	t_uint8 t_imoTrim1Value;
	
	//From here on interrupts are disabled
	t_uint8 t_interruptstate = t_EnterCriticalSection();
	
	if((t_freq >= 3u) && (t_freq <= 48u))
	{
		if(t_freq <= (*(t_reg8*)SFLASH_IMO_MAXF0))
		{
			t_bgtrim4 = (*(t_reg8*)SFLASH_IMO_ABS0);
			t_bgtrim5 = (*(t_reg8*)SFLASH_IMO_TMPCO0);
		}
		
		else if(t_freq <= (*(t_reg8*)SFLASH_IMO_MAXF1))
		{
			t_bgtrim4 = (*(t_reg8*)SFLASH_IMO_ABS1);
			t_bgtrim5 = (*(t_reg8*)SFLASH_IMO_TMPCO1);
		}
		
		else if(t_freq <= (*(t_reg8*)SFLASH_IMO_MAXF2))
		{
			t_bgtrim4 = (*(t_reg8*)SFLASH_IMO_ABS2);
			t_bgtrim5 = (*(t_reg8*)SFLASH_IMO_TMPCO2);
		}
		
		else if(t_freq <= (*(t_reg8*)SFLASH_IMO_MAXF3))
		{
			t_bgtrim4 = (*(t_reg8*)SFLASH_IMO_ABS3);
			t_bgtrim5 = (*(t_reg8*)SFLASH_IMO_TMPCO3);
		}
		else
		{
			t_bgtrim4 = (*(t_reg8*)SFLASH_IMO_ABS4);
			t_bgtrim5 = (*(t_reg8*)SFLASH_IMO_TMPCO4);
		}
		
		t_newImoTrim2Value = t_ImoFreqMhz2Reg[t_freq - 3];
		t_currentImoTrim2Value =(t_uint32)(*((t_reg32*)REG_CLK_IMO_TRIM2) & 0x3F);
		
		if(((t_newImoTrim2Value >= 0x30u) && (t_freq >= 43u)&&(t_currentImoTrim2Value >= 43u)))
		{
			//Change CLK_IMO_TRIM2 to a lower frequency 24Mhz
			*(t_reg32*)REG_CLK_IMO_TRIM2 = (t_uint32)t_ImoFreqMhz2Reg[24u - 3];
			
			//Apply TRIM1, 
			t_imoTrim1Value = (t_uint8) (((t_uint8 *)SFLASH_IMO_TRIM_BASE)[t_freq-3]);
			*(t_reg32*)REG_CLK_IMO_TRIM1=(t_uint32)t_imoTrim1Value;
            *(t_reg32*)REG_PWR_BG_TRIM4=t_bgtrim4;
            *(t_reg32*)REG_PWR_BR_TRIM5=t_bgtrim5;
			
			//Delay for 5 millis
            t_DelayCycles(5u);
			
			//Change the Imo Frequency to the new Frequency
            *(t_reg32*)0x400BFF2C=t_ImoFreqMhz2Reg[t_freq-3];
		}
		else if (t_newImoTrim2Value > t_currentImoTrim2Value)
        {
        	t_imoTrim1Value = (t_uint8) ( ((t_uint8 *) SFLASH_IMO_TRIM_BASE)[t_freq-3]);
        	*(t_reg32*)REG_CLK_IMO_TRIM1 = (t_uint32)t_imoTrim1Value;
        	*(t_reg32*)REG_PWR_BG_TRIM4 = t_bgtrim4;
        	*(t_reg32*)REG_PWR_BR_TRIM5 = t_bgtrim5;
			
        	t_DelayCycles(5u);
			
        	*(t_reg32*)0x400BFF2C=t_ImoFreqMhz2Reg[t_freq-3];    
        }
        else
        {
        	*(t_reg32*)0x400BFF2C=t_ImoFreqMhz2Reg[t_freq-3];
			
        	t_DelayCycles(5u);
			
        	t_imoTrim1Value = (t_uint8) ( ((t_uint8 *) SFLASH_IMO_TRIM_BASE)[t_freq-3]);
        	*(t_reg32*)REG_CLK_IMO_TRIM1 = (t_uint32)t_imoTrim1Value;
       		*(t_reg32*)REG_PWR_BG_TRIM4 = t_bgtrim4;
        	*(t_reg32*)REG_PWR_BR_TRIM5 = t_bgtrim5;    
        }
	}
	//input frequency t_freq to MHz value
	t_sys_freq = t_freq * 1000000;
	
	t_ExitCriticalSection(t_interruptstate);
}


/* [] END OF FILE */
