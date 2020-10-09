/*******************************************************************************
* File Name: GROUND.h  
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

#if !defined(CY_PINS_GROUND_H) /* Pins GROUND_H */
#define CY_PINS_GROUND_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GROUND_aliases.h"


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
} GROUND_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   GROUND_Read(void);
void    GROUND_Write(uint8 value);
uint8   GROUND_ReadDataReg(void);
#if defined(GROUND__PC) || (CY_PSOC4_4200L) 
    void    GROUND_SetDriveMode(uint8 mode);
#endif
void    GROUND_SetInterruptMode(uint16 position, uint16 mode);
uint8   GROUND_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void GROUND_Sleep(void); 
void GROUND_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(GROUND__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define GROUND_DRIVE_MODE_BITS        (3)
    #define GROUND_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GROUND_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the GROUND_SetDriveMode() function.
         *  @{
         */
        #define GROUND_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define GROUND_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define GROUND_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define GROUND_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define GROUND_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define GROUND_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define GROUND_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define GROUND_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define GROUND_MASK               GROUND__MASK
#define GROUND_SHIFT              GROUND__SHIFT
#define GROUND_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in GROUND_SetInterruptMode() function.
     *  @{
     */
        #define GROUND_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define GROUND_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define GROUND_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define GROUND_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(GROUND__SIO)
    #define GROUND_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(GROUND__PC) && (CY_PSOC4_4200L)
    #define GROUND_USBIO_ENABLE               ((uint32)0x80000000u)
    #define GROUND_USBIO_DISABLE              ((uint32)(~GROUND_USBIO_ENABLE))
    #define GROUND_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define GROUND_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define GROUND_USBIO_ENTER_SLEEP          ((uint32)((1u << GROUND_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << GROUND_USBIO_SUSPEND_DEL_SHIFT)))
    #define GROUND_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << GROUND_USBIO_SUSPEND_SHIFT)))
    #define GROUND_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << GROUND_USBIO_SUSPEND_DEL_SHIFT)))
    #define GROUND_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(GROUND__PC)
    /* Port Configuration */
    #define GROUND_PC                 (* (reg32 *) GROUND__PC)
#endif
/* Pin State */
#define GROUND_PS                     (* (reg32 *) GROUND__PS)
/* Data Register */
#define GROUND_DR                     (* (reg32 *) GROUND__DR)
/* Input Buffer Disable Override */
#define GROUND_INP_DIS                (* (reg32 *) GROUND__PC2)

/* Interrupt configuration Registers */
#define GROUND_INTCFG                 (* (reg32 *) GROUND__INTCFG)
#define GROUND_INTSTAT                (* (reg32 *) GROUND__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define GROUND_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(GROUND__SIO)
    #define GROUND_SIO_REG            (* (reg32 *) GROUND__SIO)
#endif /* (GROUND__SIO_CFG) */

/* USBIO registers */
#if !defined(GROUND__PC) && (CY_PSOC4_4200L)
    #define GROUND_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define GROUND_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define GROUND_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define GROUND_DRIVE_MODE_SHIFT       (0x00u)
#define GROUND_DRIVE_MODE_MASK        (0x07u << GROUND_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins GROUND_H */


/* [] END OF FILE */
