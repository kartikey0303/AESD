/* ========================================
 *
 * Kartikey Agrawal
 * Date : 14/08/18
 * Advanced Embedded Systems
 *
 * ========================================
*/

#ifndef __t_GPIO_H_
	#define __t_GPIO_H_
	
	//MACROS
	#define GPIO_SET_MODE(PC_Reg_Add, pin, mode) (*((t_reg32 *)PC_Reg_Add)) = ((*((t_reg32 *)PC_Reg_Add)) & (~((t_uint32)0x07u << (pin * (t_uint32)0x03u)))) | (mode<<(pin * (t_uint32)0x03u))
	
	#define GPIO_READ_PIN(PS_Reg_Add, pin) ((t_uint32)((*((t_reg32 *) PS_Reg_Add)) & (1UL<<pin)) >> pin)
	
	#define GPIO_WRITE_PIN(DR_Reg_Add, pin, value) *((t_reg32 *) DR_Reg_Add) = (*((t_reg32 *)DR_Reg_Add) & (~(1UL<<pin))) | ((value << pin)&(1UL<<pin))
	
	//PORTS
	#define GPIO_PRT0_DR 0x40040000u
	#define GPIO_PRT0_PS 0x40040004u
	#define GPIO_PRT0_PC 0x40040008u

	#define GPIO_PRT1_DR 0x40040100u
	#define GPIO_PRT1_PS 0x40040104u
	#define GPIO_PRT1_PC 0x40040108u

	#define GPIO_PRT2_DR 0x40040200u
	#define GPIO_PRT2_PS 0x40040204u
	#define GPIO_PRT2_PC 0x40040208u

	#define GPIO_PRT3_DR 0x40040300u
	#define GPIO_PRT3_PS 0x40040304u
	#define GPIO_PRT3_PC 0x40040308u

	#define GPIO_PRT4_DR 0x40040400u
	#define GPIO_PRT4_PS 0x40040404u
	#define GPIO_PRT4_PC 0x40040408u

	#define GPIO_PRT5_DR 0x40040500u
	#define GPIO_PRT5_PS 0x40040504u
	#define GPIO_PRT5_PC 0x40040508u

	#define GPIO_PRT6_DR 0x40040600u
	#define GPIO_PRT6_PS 0x40040604u
	#define GPIO_PRT6_PC 0x40040608u

	#define GPIO_PRT7_DR 0x40040700u
	#define GPIO_PRT7_PS 0x40040704u
	#define GPIO_PRT7_PC 0x40040708u

	//GPIO_DriveMode_Analog_HighImpedance
	#define GPIO_DM_A_HIZ 0x00u
	//GPIO_DriveMode_Digital_HighImpedance
	#define GPIO_DM_D_HIZ 0x01u
	//GPIO_DriveMode_ResistivePullUp
	#define GPIO_DM_RPU 0x02u
	//GPIO_DriveMode_ResistivePullDown
	#define GPIO_DM_RPD 0x03u
	//GPIO_DriveMode_OpenDrainLow
	#define GPIO_DM_OD_L 0x04u
	//GPIO_DriveMode_OpenDrainHigh
	#define GPIO_DM_OD_H 0x05u
	//GPIO_DriveMode_Strong
	#define GPIO_DM_A_STRONG 0x06u
	//GPIO_DriveMode_ResistivePullUpAndDown
	#define GPIO_DM_RPUD 0x07u

#endif

/* [] END OF FILE */
