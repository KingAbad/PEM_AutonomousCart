/*******************************************************************************
* File Name: Rood.h  
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

#if !defined(CY_PINS_Rood_H) /* Pins Rood_H */
#define CY_PINS_Rood_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Rood_aliases.h"


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
} Rood_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Rood_Read(void);
void    Rood_Write(uint8 value);
uint8   Rood_ReadDataReg(void);
#if defined(Rood__PC) || (CY_PSOC4_4200L) 
    void    Rood_SetDriveMode(uint8 mode);
#endif
void    Rood_SetInterruptMode(uint16 position, uint16 mode);
uint8   Rood_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Rood_Sleep(void); 
void Rood_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Rood__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Rood_DRIVE_MODE_BITS        (3)
    #define Rood_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Rood_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Rood_SetDriveMode() function.
         *  @{
         */
        #define Rood_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Rood_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Rood_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Rood_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Rood_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Rood_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Rood_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Rood_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Rood_MASK               Rood__MASK
#define Rood_SHIFT              Rood__SHIFT
#define Rood_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Rood_SetInterruptMode() function.
     *  @{
     */
        #define Rood_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Rood_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Rood_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Rood_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Rood__SIO)
    #define Rood_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Rood__PC) && (CY_PSOC4_4200L)
    #define Rood_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Rood_USBIO_DISABLE              ((uint32)(~Rood_USBIO_ENABLE))
    #define Rood_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Rood_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Rood_USBIO_ENTER_SLEEP          ((uint32)((1u << Rood_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Rood_USBIO_SUSPEND_DEL_SHIFT)))
    #define Rood_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Rood_USBIO_SUSPEND_SHIFT)))
    #define Rood_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Rood_USBIO_SUSPEND_DEL_SHIFT)))
    #define Rood_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Rood__PC)
    /* Port Configuration */
    #define Rood_PC                 (* (reg32 *) Rood__PC)
#endif
/* Pin State */
#define Rood_PS                     (* (reg32 *) Rood__PS)
/* Data Register */
#define Rood_DR                     (* (reg32 *) Rood__DR)
/* Input Buffer Disable Override */
#define Rood_INP_DIS                (* (reg32 *) Rood__PC2)

/* Interrupt configuration Registers */
#define Rood_INTCFG                 (* (reg32 *) Rood__INTCFG)
#define Rood_INTSTAT                (* (reg32 *) Rood__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Rood_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Rood__SIO)
    #define Rood_SIO_REG            (* (reg32 *) Rood__SIO)
#endif /* (Rood__SIO_CFG) */

/* USBIO registers */
#if !defined(Rood__PC) && (CY_PSOC4_4200L)
    #define Rood_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Rood_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Rood_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Rood_DRIVE_MODE_SHIFT       (0x00u)
#define Rood_DRIVE_MODE_MASK        (0x07u << Rood_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Rood_H */


/* [] END OF FILE */
