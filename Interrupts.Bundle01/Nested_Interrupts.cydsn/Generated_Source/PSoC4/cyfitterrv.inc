;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.1 Update 1
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2017 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; Clock_1
Clock_1__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL11
Clock_1__DIV_ID EQU 0x00000040
Clock_1__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL0
Clock_1__PA_DIV_ID EQU 0x000000FF

; GREEN_LED
GREEN_LED__0__DR EQU CYREG_GPIO_PRT2_DR
GREEN_LED__0__DR_CLR EQU CYREG_GPIO_PRT2_DR_CLR
GREEN_LED__0__DR_INV EQU CYREG_GPIO_PRT2_DR_INV
GREEN_LED__0__DR_SET EQU CYREG_GPIO_PRT2_DR_SET
GREEN_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL2
GREEN_LED__0__HSIOM_MASK EQU 0x0F000000
GREEN_LED__0__HSIOM_SHIFT EQU 24
GREEN_LED__0__INTCFG EQU CYREG_GPIO_PRT2_INTR_CFG
GREEN_LED__0__INTR EQU CYREG_GPIO_PRT2_INTR
GREEN_LED__0__INTR_CFG EQU CYREG_GPIO_PRT2_INTR_CFG
GREEN_LED__0__INTSTAT EQU CYREG_GPIO_PRT2_INTR
GREEN_LED__0__MASK EQU 0x40
GREEN_LED__0__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
GREEN_LED__0__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
GREEN_LED__0__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
GREEN_LED__0__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
GREEN_LED__0__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
GREEN_LED__0__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
GREEN_LED__0__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
GREEN_LED__0__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
GREEN_LED__0__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
GREEN_LED__0__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
GREEN_LED__0__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
GREEN_LED__0__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
GREEN_LED__0__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
GREEN_LED__0__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
GREEN_LED__0__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
GREEN_LED__0__PC EQU CYREG_GPIO_PRT2_PC
GREEN_LED__0__PC2 EQU CYREG_GPIO_PRT2_PC2
GREEN_LED__0__PORT EQU 2
GREEN_LED__0__PS EQU CYREG_GPIO_PRT2_PS
GREEN_LED__0__SHIFT EQU 6
GREEN_LED__DR EQU CYREG_GPIO_PRT2_DR
GREEN_LED__DR_CLR EQU CYREG_GPIO_PRT2_DR_CLR
GREEN_LED__DR_INV EQU CYREG_GPIO_PRT2_DR_INV
GREEN_LED__DR_SET EQU CYREG_GPIO_PRT2_DR_SET
GREEN_LED__INTCFG EQU CYREG_GPIO_PRT2_INTR_CFG
GREEN_LED__INTR EQU CYREG_GPIO_PRT2_INTR
GREEN_LED__INTR_CFG EQU CYREG_GPIO_PRT2_INTR_CFG
GREEN_LED__INTSTAT EQU CYREG_GPIO_PRT2_INTR
GREEN_LED__MASK EQU 0x40
GREEN_LED__PA__CFG0 EQU CYREG_UDB_PA2_CFG0
GREEN_LED__PA__CFG1 EQU CYREG_UDB_PA2_CFG1
GREEN_LED__PA__CFG10 EQU CYREG_UDB_PA2_CFG10
GREEN_LED__PA__CFG11 EQU CYREG_UDB_PA2_CFG11
GREEN_LED__PA__CFG12 EQU CYREG_UDB_PA2_CFG12
GREEN_LED__PA__CFG13 EQU CYREG_UDB_PA2_CFG13
GREEN_LED__PA__CFG14 EQU CYREG_UDB_PA2_CFG14
GREEN_LED__PA__CFG2 EQU CYREG_UDB_PA2_CFG2
GREEN_LED__PA__CFG3 EQU CYREG_UDB_PA2_CFG3
GREEN_LED__PA__CFG4 EQU CYREG_UDB_PA2_CFG4
GREEN_LED__PA__CFG5 EQU CYREG_UDB_PA2_CFG5
GREEN_LED__PA__CFG6 EQU CYREG_UDB_PA2_CFG6
GREEN_LED__PA__CFG7 EQU CYREG_UDB_PA2_CFG7
GREEN_LED__PA__CFG8 EQU CYREG_UDB_PA2_CFG8
GREEN_LED__PA__CFG9 EQU CYREG_UDB_PA2_CFG9
GREEN_LED__PC EQU CYREG_GPIO_PRT2_PC
GREEN_LED__PC2 EQU CYREG_GPIO_PRT2_PC2
GREEN_LED__PORT EQU 2
GREEN_LED__PS EQU CYREG_GPIO_PRT2_PS
GREEN_LED__SHIFT EQU 6

; RED_LED
RED_LED__0__DR EQU CYREG_GPIO_PRT0_DR
RED_LED__0__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
RED_LED__0__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
RED_LED__0__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
RED_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
RED_LED__0__HSIOM_MASK EQU 0x0F000000
RED_LED__0__HSIOM_SHIFT EQU 24
RED_LED__0__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
RED_LED__0__INTR EQU CYREG_GPIO_PRT0_INTR
RED_LED__0__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
RED_LED__0__INTSTAT EQU CYREG_GPIO_PRT0_INTR
RED_LED__0__MASK EQU 0x40
RED_LED__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
RED_LED__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
RED_LED__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
RED_LED__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
RED_LED__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
RED_LED__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
RED_LED__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
RED_LED__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
RED_LED__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
RED_LED__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
RED_LED__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
RED_LED__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
RED_LED__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
RED_LED__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
RED_LED__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
RED_LED__0__PC EQU CYREG_GPIO_PRT0_PC
RED_LED__0__PC2 EQU CYREG_GPIO_PRT0_PC2
RED_LED__0__PORT EQU 0
RED_LED__0__PS EQU CYREG_GPIO_PRT0_PS
RED_LED__0__SHIFT EQU 6
RED_LED__DR EQU CYREG_GPIO_PRT0_DR
RED_LED__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
RED_LED__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
RED_LED__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
RED_LED__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
RED_LED__INTR EQU CYREG_GPIO_PRT0_INTR
RED_LED__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
RED_LED__INTSTAT EQU CYREG_GPIO_PRT0_INTR
RED_LED__MASK EQU 0x40
RED_LED__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
RED_LED__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
RED_LED__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
RED_LED__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
RED_LED__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
RED_LED__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
RED_LED__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
RED_LED__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
RED_LED__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
RED_LED__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
RED_LED__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
RED_LED__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
RED_LED__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
RED_LED__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
RED_LED__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
RED_LED__PC EQU CYREG_GPIO_PRT0_PC
RED_LED__PC2 EQU CYREG_GPIO_PRT0_PC2
RED_LED__PORT EQU 0
RED_LED__PS EQU CYREG_GPIO_PRT0_PS
RED_LED__SHIFT EQU 6

; SW
SW__0__DR EQU CYREG_GPIO_PRT0_DR
SW__0__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
SW__0__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
SW__0__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
SW__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
SW__0__HSIOM_MASK EQU 0xF0000000
SW__0__HSIOM_SHIFT EQU 28
SW__0__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
SW__0__INTR EQU CYREG_GPIO_PRT0_INTR
SW__0__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
SW__0__INTSTAT EQU CYREG_GPIO_PRT0_INTR
SW__0__MASK EQU 0x80
SW__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
SW__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
SW__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
SW__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
SW__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
SW__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
SW__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
SW__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
SW__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
SW__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
SW__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
SW__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
SW__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
SW__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
SW__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
SW__0__PC EQU CYREG_GPIO_PRT0_PC
SW__0__PC2 EQU CYREG_GPIO_PRT0_PC2
SW__0__PORT EQU 0
SW__0__PS EQU CYREG_GPIO_PRT0_PS
SW__0__SHIFT EQU 7
SW__DR EQU CYREG_GPIO_PRT0_DR
SW__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
SW__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
SW__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
SW__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
SW__INTR EQU CYREG_GPIO_PRT0_INTR
SW__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
SW__INTSTAT EQU CYREG_GPIO_PRT0_INTR
SW__MASK EQU 0x80
SW__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
SW__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
SW__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
SW__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
SW__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
SW__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
SW__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
SW__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
SW__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
SW__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
SW__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
SW__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
SW__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
SW__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
SW__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
SW__PC EQU CYREG_GPIO_PRT0_PC
SW__PC2 EQU CYREG_GPIO_PRT0_PC2
SW__PORT EQU 0
SW__PS EQU CYREG_GPIO_PRT0_PS
SW__SHIFT EQU 7

; Timer_1
Timer_1_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
Timer_1_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
Timer_1_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
Timer_1_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
Timer_1_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
Timer_1_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
Timer_1_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
Timer_1_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
Timer_1_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
Timer_1_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
Timer_1_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
Timer_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
Timer_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
Timer_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
Timer_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
Timer_1_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
Timer_1_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
Timer_1_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
Timer_1_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2

; isr_1
isr_1__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
isr_1__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
isr_1__INTC_MASK EQU 0x80000
isr_1__INTC_NUMBER EQU 19
isr_1__INTC_PRIOR_MASK EQU 0xC0000000
isr_1__INTC_PRIOR_NUM EQU 1
isr_1__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
isr_1__INTC_SET_EN_REG EQU CYREG_CM0_ISER
isr_1__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; isr_2
isr_2__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
isr_2__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
isr_2__INTC_MASK EQU 0x01
isr_2__INTC_NUMBER EQU 0
isr_2__INTC_PRIOR_MASK EQU 0xC0
isr_2__INTC_PRIOR_NUM EQU 2
isr_2__INTC_PRIOR_REG EQU CYREG_CM0_IPR0
isr_2__INTC_SET_EN_REG EQU CYREG_CM0_ISER
isr_2__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 48000000
CYDEV_BCLK__HFCLK__KHZ EQU 48000
CYDEV_BCLK__HFCLK__MHZ EQU 48
CYDEV_BCLK__SYSCLK__HZ EQU 48000000
CYDEV_BCLK__SYSCLK__KHZ EQU 48000
CYDEV_BCLK__SYSCLK__MHZ EQU 48
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 16
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x112D11A1
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 16
CYDEV_CHIP_MEMBER_4D EQU 12
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 17
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 15
CYDEV_CHIP_MEMBER_4I EQU 21
CYDEV_CHIP_MEMBER_4J EQU 13
CYDEV_CHIP_MEMBER_4K EQU 14
CYDEV_CHIP_MEMBER_4L EQU 20
CYDEV_CHIP_MEMBER_4M EQU 19
CYDEV_CHIP_MEMBER_4N EQU 9
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 18
CYDEV_CHIP_MEMBER_4Q EQU 11
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 22
CYDEV_CHIP_MEMBER_FM3 EQU 26
CYDEV_CHIP_MEMBER_FM4 EQU 27
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 23
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 24
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 25
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4M
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 0
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4M_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_Disallowed
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 10
CYDEV_DFT_SELECT_CLK1 EQU 11
CYDEV_DMA_CHANNELS_AVAILABLE EQU 8
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_INTR_NUMBER_DMA EQU 13
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_VDDIO_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_m0s8can_VERSION EQU 1
CYIPBLOCK_m0s8cpussv2_VERSION EQU 1
CYIPBLOCK_m0s8csd_VERSION EQU 1
CYIPBLOCK_m0s8ioss_VERSION EQU 1
CYIPBLOCK_m0s8lcd_VERSION EQU 2
CYIPBLOCK_m0s8lpcomp_VERSION EQU 2
CYIPBLOCK_m0s8peri_VERSION EQU 1
CYIPBLOCK_m0s8scb_VERSION EQU 2
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 2
CYIPBLOCK_m0s8udbif_VERSION EQU 1
CYIPBLOCK_m0s8wco_VERSION EQU 1
CYIPBLOCK_s8pass4al_VERSION EQU 1
DMA_CHANNELS_USED__MASK EQU 0
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END