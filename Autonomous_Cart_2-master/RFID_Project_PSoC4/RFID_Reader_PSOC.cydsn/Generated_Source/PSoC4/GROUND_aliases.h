/*******************************************************************************
* File Name: GROUND.h  
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

#if !defined(CY_PINS_GROUND_ALIASES_H) /* Pins GROUND_ALIASES_H */
#define CY_PINS_GROUND_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define GROUND_0			(GROUND__0__PC)
#define GROUND_0_PS		(GROUND__0__PS)
#define GROUND_0_PC		(GROUND__0__PC)
#define GROUND_0_DR		(GROUND__0__DR)
#define GROUND_0_SHIFT	(GROUND__0__SHIFT)
#define GROUND_0_INTR	((uint16)((uint16)0x0003u << (GROUND__0__SHIFT*2u)))

#define GROUND_INTR_ALL	 ((uint16)(GROUND_0_INTR))


#endif /* End Pins GROUND_ALIASES_H */


/* [] END OF FILE */
