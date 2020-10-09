/*******************************************************************************
* File Name: Groen.h  
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

#if !defined(CY_PINS_Groen_H) /* Pins Groen_H */
#define CY_PINS_Groen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Groen_aliases.h"


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
} Groen_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Groen_Read(void);
void    Groen_Write(uint8 value);
uint8   Groen_ReadDataReg(void);
#if defined(Groen__PC) || (CY_PSOC4_4200L) 
    void    Groen_SetDriveMode(uint8 mode);
#endif
void    Groen_SetInterruptMode(uint16 position, uint16 mode);
uint8   Groen_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Groen_Sleep(void); 
void Groen_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Groen__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Groen_DRIVE_MODE_BITS        (3)
    #define Groen_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Groen_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Groen_SetDriveMode() function.
         *  @{
         */
        #define Groen_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Groen_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Groen_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Groen_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Groen_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Groen_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Groen_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Groen_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Groen_MASK               Groen__MASK
#define Groen_SHIFT              Groen__SHIFT
#define Groen_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Groen_SetInterruptMode() function.
     *  @{
     */
        #define Groen_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Groen_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Groen_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Groen_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Groen__SIO)
    #define Groen_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Groen__PC) && (CY_PSOC4_4200L)
    #define Groen_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Groen_USBIO_DISABLE              ((uint32)(~Groen_USBIO_ENABLE))
    #define Groen_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Groen_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Groen_USBIO_ENTER_SLEEP          ((uint32)((1u << Groen_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Groen_USBIO_SUSPEND_DEL_SHIFT)))
    #define Groen_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Groen_USBIO_SUSPEND_SHIFT)))
    #define Groen_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Groen_USBIO_SUSPEND_DEL_SHIFT)))
    #define Groen_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Groen__PC)
    /* Port Configuration */
    #define Groen_PC                 (* (reg32 *) Groen__PC)
#endif
/* Pin State */
#define Groen_PS                     (* (reg32 *) Groen__PS)
/* Data Register */
#define Groen_DR                     (* (reg32 *) Groen__DR)
/* Input Buffer Disable Override */
#define Groen_INP_DIS                (* (reg32 *) Groen__PC2)

/* Interrupt configuration Registers */
#define Groen_INTCFG                 (* (reg32 *) Groen__INTCFG)
#define Groen_INTSTAT                (* (reg32 *) Groen__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Groen_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Groen__SIO)
    #define Groen_SIO_REG            (* (reg32 *) Groen__SIO)
#endif /* (Groen__SIO_CFG) */

/* USBIO registers */
#if !defined(Groen__PC) && (CY_PSOC4_4200L)
    #define Groen_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Groen_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Groen_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Groen_DRIVE_MODE_SHIFT       (0x00u)
#define Groen_DRIVE_MODE_MASK        (0x07u << Groen_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Groen_H */


/* [] END OF FILE */
