/*******************************************************************************
* File Name: Groen.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Groen.h"

static Groen_BACKUP_STRUCT  Groen_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Groen_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Groen_SUT.c usage_Groen_Sleep_Wakeup
*******************************************************************************/
void Groen_Sleep(void)
{
    #if defined(Groen__PC)
        Groen_backup.pcState = Groen_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Groen_backup.usbState = Groen_CR1_REG;
            Groen_USB_POWER_REG |= Groen_USBIO_ENTER_SLEEP;
            Groen_CR1_REG &= Groen_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Groen__SIO)
        Groen_backup.sioState = Groen_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Groen_SIO_REG &= (uint32)(~Groen_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Groen_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Groen_Sleep() for an example usage.
*******************************************************************************/
void Groen_Wakeup(void)
{
    #if defined(Groen__PC)
        Groen_PC = Groen_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Groen_USB_POWER_REG &= Groen_USBIO_EXIT_SLEEP_PH1;
            Groen_CR1_REG = Groen_backup.usbState;
            Groen_USB_POWER_REG &= Groen_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Groen__SIO)
        Groen_SIO_REG = Groen_backup.sioState;
    #endif
}


/* [] END OF FILE */
