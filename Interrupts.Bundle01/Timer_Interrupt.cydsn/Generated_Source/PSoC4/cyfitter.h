/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.1 Update 1
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

/* Clock_1 */
#define Clock_1__CTRL_REGISTER CYREG_PERI_PCLK_CTL11
#define Clock_1__DIV_ID 0x00000040u
#define Clock_1__DIV_REGISTER CYREG_PERI_DIV_16_CTL0
#define Clock_1__PA_DIV_ID 0x000000FFu

/* GREEN_LED */
#define GREEN_LED__0__DR CYREG_GPIO_PRT2_DR
#define GREEN_LED__0__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define GREEN_LED__0__DR_INV CYREG_GPIO_PRT2_DR_INV
#define GREEN_LED__0__DR_SET CYREG_GPIO_PRT2_DR_SET
#define GREEN_LED__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define GREEN_LED__0__HSIOM_MASK 0x0F000000u
#define GREEN_LED__0__HSIOM_SHIFT 24u
#define GREEN_LED__0__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define GREEN_LED__0__INTR CYREG_GPIO_PRT2_INTR
#define GREEN_LED__0__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define GREEN_LED__0__INTSTAT CYREG_GPIO_PRT2_INTR
#define GREEN_LED__0__MASK 0x40u
#define GREEN_LED__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define GREEN_LED__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define GREEN_LED__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define GREEN_LED__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define GREEN_LED__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define GREEN_LED__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define GREEN_LED__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define GREEN_LED__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define GREEN_LED__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define GREEN_LED__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define GREEN_LED__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define GREEN_LED__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define GREEN_LED__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define GREEN_LED__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define GREEN_LED__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define GREEN_LED__0__PC CYREG_GPIO_PRT2_PC
#define GREEN_LED__0__PC2 CYREG_GPIO_PRT2_PC2
#define GREEN_LED__0__PORT 2u
#define GREEN_LED__0__PS CYREG_GPIO_PRT2_PS
#define GREEN_LED__0__SHIFT 6u
#define GREEN_LED__DR CYREG_GPIO_PRT2_DR
#define GREEN_LED__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define GREEN_LED__DR_INV CYREG_GPIO_PRT2_DR_INV
#define GREEN_LED__DR_SET CYREG_GPIO_PRT2_DR_SET
#define GREEN_LED__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define GREEN_LED__INTR CYREG_GPIO_PRT2_INTR
#define GREEN_LED__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define GREEN_LED__INTSTAT CYREG_GPIO_PRT2_INTR
#define GREEN_LED__MASK 0x40u
#define GREEN_LED__PA__CFG0 CYREG_UDB_PA2_CFG0
#define GREEN_LED__PA__CFG1 CYREG_UDB_PA2_CFG1
#define GREEN_LED__PA__CFG10 CYREG_UDB_PA2_CFG10
#define GREEN_LED__PA__CFG11 CYREG_UDB_PA2_CFG11
#define GREEN_LED__PA__CFG12 CYREG_UDB_PA2_CFG12
#define GREEN_LED__PA__CFG13 CYREG_UDB_PA2_CFG13
#define GREEN_LED__PA__CFG14 CYREG_UDB_PA2_CFG14
#define GREEN_LED__PA__CFG2 CYREG_UDB_PA2_CFG2
#define GREEN_LED__PA__CFG3 CYREG_UDB_PA2_CFG3
#define GREEN_LED__PA__CFG4 CYREG_UDB_PA2_CFG4
#define GREEN_LED__PA__CFG5 CYREG_UDB_PA2_CFG5
#define GREEN_LED__PA__CFG6 CYREG_UDB_PA2_CFG6
#define GREEN_LED__PA__CFG7 CYREG_UDB_PA2_CFG7
#define GREEN_LED__PA__CFG8 CYREG_UDB_PA2_CFG8
#define GREEN_LED__PA__CFG9 CYREG_UDB_PA2_CFG9
#define GREEN_LED__PC CYREG_GPIO_PRT2_PC
#define GREEN_LED__PC2 CYREG_GPIO_PRT2_PC2
#define GREEN_LED__PORT 2u
#define GREEN_LED__PS CYREG_GPIO_PRT2_PS
#define GREEN_LED__SHIFT 6u

/* Timer */
#define Timer_cy_m0s8_tcpwm_1__CC CYREG_TCPWM_CNT0_CC
#define Timer_cy_m0s8_tcpwm_1__CC_BUFF CYREG_TCPWM_CNT0_CC_BUFF
#define Timer_cy_m0s8_tcpwm_1__COUNTER CYREG_TCPWM_CNT0_COUNTER
#define Timer_cy_m0s8_tcpwm_1__CTRL CYREG_TCPWM_CNT0_CTRL
#define Timer_cy_m0s8_tcpwm_1__INTR CYREG_TCPWM_CNT0_INTR
#define Timer_cy_m0s8_tcpwm_1__INTR_MASK CYREG_TCPWM_CNT0_INTR_MASK
#define Timer_cy_m0s8_tcpwm_1__INTR_MASKED CYREG_TCPWM_CNT0_INTR_MASKED
#define Timer_cy_m0s8_tcpwm_1__INTR_SET CYREG_TCPWM_CNT0_INTR_SET
#define Timer_cy_m0s8_tcpwm_1__PERIOD CYREG_TCPWM_CNT0_PERIOD
#define Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF CYREG_TCPWM_CNT0_PERIOD_BUFF
#define Timer_cy_m0s8_tcpwm_1__STATUS CYREG_TCPWM_CNT0_STATUS
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMD CYREG_TCPWM_CMD
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK 0x01u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT 0u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK 0x100u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT 8u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK 0x1000000u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT 24u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK 0x10000u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT 16u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL CYREG_TCPWM_CTRL
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK 0x01u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT 0u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE CYREG_TCPWM_INTR_CAUSE
#define Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK 0x01u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT 0u
#define Timer_cy_m0s8_tcpwm_1__TCPWM_NUMBER 0u
#define Timer_cy_m0s8_tcpwm_1__TR_CTRL0 CYREG_TCPWM_CNT0_TR_CTRL0
#define Timer_cy_m0s8_tcpwm_1__TR_CTRL1 CYREG_TCPWM_CNT0_TR_CTRL1
#define Timer_cy_m0s8_tcpwm_1__TR_CTRL2 CYREG_TCPWM_CNT0_TR_CTRL2

/* isr */
#define isr__INTC_CLR_EN_REG CYREG_CM0_ICER
#define isr__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define isr__INTC_MASK 0x80000u
#define isr__INTC_NUMBER 19u
#define isr__INTC_PRIOR_MASK 0xC0000000u
#define isr__INTC_PRIOR_NUM 3u
#define isr__INTC_PRIOR_REG CYREG_CM0_IPR4
#define isr__INTC_SET_EN_REG CYREG_CM0_ISER
#define isr__INTC_SET_PD_REG CYREG_CM0_ISPR

/* Miscellaneous */
#define CY_PROJECT_NAME "Timer_Interrupt"
#define CY_VERSION "PSoC Creator  4.1 Update 1"
#define CYDEV_BANDGAP_VOLTAGE 1.024
#define CYDEV_BCLK__HFCLK__HZ 48000000U
#define CYDEV_BCLK__HFCLK__KHZ 48000U
#define CYDEV_BCLK__HFCLK__MHZ 48U
#define CYDEV_BCLK__SYSCLK__HZ 48000000U
#define CYDEV_BCLK__SYSCLK__KHZ 48000U
#define CYDEV_BCLK__SYSCLK__MHZ 48U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 16u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x112D11A1u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 16u
#define CYDEV_CHIP_MEMBER_4D 12u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 17u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 15u
#define CYDEV_CHIP_MEMBER_4I 21u
#define CYDEV_CHIP_MEMBER_4J 13u
#define CYDEV_CHIP_MEMBER_4K 14u
#define CYDEV_CHIP_MEMBER_4L 20u
#define CYDEV_CHIP_MEMBER_4M 19u
#define CYDEV_CHIP_MEMBER_4N 9u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 18u
#define CYDEV_CHIP_MEMBER_4Q 11u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 22u
#define CYDEV_CHIP_MEMBER_FM3 26u
#define CYDEV_CHIP_MEMBER_FM4 27u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 23u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 24u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 25u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4M
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 0u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4M_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_Disallowed
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DFT_SELECT_CLK0 10u
#define CYDEV_DFT_SELECT_CLK1 11u
#define CYDEV_DMA_CHANNELS_AVAILABLE 8
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_IMO_TRIMMED_BY_USB 0u
#define CYDEV_IMO_TRIMMED_BY_WCO 0u
#define CYDEV_INTR_NUMBER_DMA 13u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_VDDIO 3.3
#define CYDEV_VDDIO_MV 3300
#define CYDEV_WDT_GENERATE_ISR 1u
#define CYIPBLOCK_m0s8can_VERSION 1
#define CYIPBLOCK_m0s8cpussv2_VERSION 1
#define CYIPBLOCK_m0s8csd_VERSION 1
#define CYIPBLOCK_m0s8ioss_VERSION 1
#define CYIPBLOCK_m0s8lcd_VERSION 2
#define CYIPBLOCK_m0s8lpcomp_VERSION 2
#define CYIPBLOCK_m0s8peri_VERSION 1
#define CYIPBLOCK_m0s8scb_VERSION 2
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 2
#define CYIPBLOCK_m0s8udbif_VERSION 1
#define CYIPBLOCK_m0s8wco_VERSION 1
#define CYIPBLOCK_s8pass4al_VERSION 1
#define DMA_CHANNELS_USED__MASK 0u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */