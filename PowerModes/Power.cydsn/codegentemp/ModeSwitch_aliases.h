/*******************************************************************************
* File Name: ModeSwitch.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ModeSwitch_ALIASES_H) /* Pins ModeSwitch_ALIASES_H */
#define CY_PINS_ModeSwitch_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ModeSwitch_0			(ModeSwitch__0__PC)
#define ModeSwitch_0_PS		(ModeSwitch__0__PS)
#define ModeSwitch_0_PC		(ModeSwitch__0__PC)
#define ModeSwitch_0_DR		(ModeSwitch__0__DR)
#define ModeSwitch_0_SHIFT	(ModeSwitch__0__SHIFT)
#define ModeSwitch_0_INTR	((uint16)((uint16)0x0003u << (ModeSwitch__0__SHIFT*2u)))

#define ModeSwitch_INTR_ALL	 ((uint16)(ModeSwitch_0_INTR))


#endif /* End Pins ModeSwitch_ALIASES_H */


/* [] END OF FILE */
