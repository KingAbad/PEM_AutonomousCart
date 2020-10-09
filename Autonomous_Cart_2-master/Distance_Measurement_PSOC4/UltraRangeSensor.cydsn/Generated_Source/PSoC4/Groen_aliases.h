/*******************************************************************************
* File Name: Groen.h  
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

#if !defined(CY_PINS_Groen_ALIASES_H) /* Pins Groen_ALIASES_H */
#define CY_PINS_Groen_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Groen_0			(Groen__0__PC)
#define Groen_0_PS		(Groen__0__PS)
#define Groen_0_PC		(Groen__0__PC)
#define Groen_0_DR		(Groen__0__DR)
#define Groen_0_SHIFT	(Groen__0__SHIFT)
#define Groen_0_INTR	((uint16)((uint16)0x0003u << (Groen__0__SHIFT*2u)))

#define Groen_INTR_ALL	 ((uint16)(Groen_0_INTR))


#endif /* End Pins Groen_ALIASES_H */


/* [] END OF FILE */
