/*******************************************************************************
* File Name: ModeSwitch.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ModeSwitch_H) /* Pins ModeSwitch_H */
#define CY_PINS_ModeSwitch_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ModeSwitch_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} ModeSwitch_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ModeSwitch_Read(void);
void    ModeSwitch_Write(uint8 value);
uint8   ModeSwitch_ReadDataReg(void);
#if defined(ModeSwitch__PC) || (CY_PSOC4_4200L) 
    void    ModeSwitch_SetDriveMode(uint8 mode);
#endif
void    ModeSwitch_SetInterruptMode(uint16 position, uint16 mode);
uint8   ModeSwitch_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ModeSwitch_Sleep(void); 
void ModeSwitch_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ModeSwitch__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ModeSwitch_DRIVE_MODE_BITS        (3)
    #define ModeSwitch_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ModeSwitch_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ModeSwitch_SetDriveMode() function.
         *  @{
         */
        #define ModeSwitch_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ModeSwitch_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ModeSwitch_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ModeSwitch_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ModeSwitch_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ModeSwitch_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ModeSwitch_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ModeSwitch_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ModeSwitch_MASK               ModeSwitch__MASK
#define ModeSwitch_SHIFT              ModeSwitch__SHIFT
#define ModeSwitch_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ModeSwitch_SetInterruptMode() function.
     *  @{
     */
        #define ModeSwitch_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ModeSwitch_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ModeSwitch_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ModeSwitch_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ModeSwitch__SIO)
    #define ModeSwitch_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ModeSwitch__PC) && (CY_PSOC4_4200L)
    #define ModeSwitch_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ModeSwitch_USBIO_DISABLE              ((uint32)(~ModeSwitch_USBIO_ENABLE))
    #define ModeSwitch_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ModeSwitch_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ModeSwitch_USBIO_ENTER_SLEEP          ((uint32)((1u << ModeSwitch_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ModeSwitch_USBIO_SUSPEND_DEL_SHIFT)))
    #define ModeSwitch_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ModeSwitch_USBIO_SUSPEND_SHIFT)))
    #define ModeSwitch_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ModeSwitch_USBIO_SUSPEND_DEL_SHIFT)))
    #define ModeSwitch_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ModeSwitch__PC)
    /* Port Configuration */
    #define ModeSwitch_PC                 (* (reg32 *) ModeSwitch__PC)
#endif
/* Pin State */
#define ModeSwitch_PS                     (* (reg32 *) ModeSwitch__PS)
/* Data Register */
#define ModeSwitch_DR                     (* (reg32 *) ModeSwitch__DR)
/* Input Buffer Disable Override */
#define ModeSwitch_INP_DIS                (* (reg32 *) ModeSwitch__PC2)

/* Interrupt configuration Registers */
#define ModeSwitch_INTCFG                 (* (reg32 *) ModeSwitch__INTCFG)
#define ModeSwitch_INTSTAT                (* (reg32 *) ModeSwitch__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ModeSwitch_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ModeSwitch__SIO)
    #define ModeSwitch_SIO_REG            (* (reg32 *) ModeSwitch__SIO)
#endif /* (ModeSwitch__SIO_CFG) */

/* USBIO registers */
#if !defined(ModeSwitch__PC) && (CY_PSOC4_4200L)
    #define ModeSwitch_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ModeSwitch_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ModeSwitch_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ModeSwitch_DRIVE_MODE_SHIFT       (0x00u)
#define ModeSwitch_DRIVE_MODE_MASK        (0x07u << ModeSwitch_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ModeSwitch_H */


/* [] END OF FILE */
