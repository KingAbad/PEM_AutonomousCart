/*******************************************************************************
* File Name: Blauw.h  
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

#if !defined(CY_PINS_Blauw_ALIASES_H) /* Pins Blauw_ALIASES_H */
#define CY_PINS_Blauw_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Blauw_0			(Blauw__0__PC)
#define Blauw_0_PS		(Blauw__0__PS)
#define Blauw_0_PC		(Blauw__0__PC)
#define Blauw_0_DR		(Blauw__0__DR)
#define Blauw_0_SHIFT	(Blauw__0__SHIFT)
#define Blauw_0_INTR	((uint16)((uint16)0x0003u << (Blauw__0__SHIFT*2u)))

#define Blauw_INTR_ALL	 ((uint16)(Blauw_0_INTR))


#endif /* End Pins Blauw_ALIASES_H */


/* [] END OF FILE */
