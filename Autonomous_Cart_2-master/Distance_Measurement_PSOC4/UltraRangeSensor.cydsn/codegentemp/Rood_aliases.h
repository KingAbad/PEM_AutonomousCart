/*******************************************************************************
* File Name: Rood.h  
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

#if !defined(CY_PINS_Rood_ALIASES_H) /* Pins Rood_ALIASES_H */
#define CY_PINS_Rood_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Rood_0			(Rood__0__PC)
#define Rood_0_PS		(Rood__0__PS)
#define Rood_0_PC		(Rood__0__PC)
#define Rood_0_DR		(Rood__0__DR)
#define Rood_0_SHIFT	(Rood__0__SHIFT)
#define Rood_0_INTR	((uint16)((uint16)0x0003u << (Rood__0__SHIFT*2u)))

#define Rood_INTR_ALL	 ((uint16)(Rood_0_INTR))


#endif /* End Pins Rood_ALIASES_H */


/* [] END OF FILE */
