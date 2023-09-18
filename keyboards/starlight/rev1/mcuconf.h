#ifndef MCUCONF_H
#define MCUCONF_H

#define STM32F103_MCUCONF

#define STM32_USB_CLOCK_REQUIRED            TRUE
#define STM32_USBPRE                        STM32_USBPRE_DIV1P5


#define STM32_PWM_USE_TIM1 TRUE
#define STM32_PWM_USE_ADVANCED TRUE


/*
 * USB driver system settings.
 */
#define STM32_USB_USE_USB1                  TRUE
#define STM32_USB_LOW_POWER_ON_SUSPEND      FALSE
#define STM32_USB_USB1_HP_IRQ_PRIORITY      13
#define STM32_USB_USB1_LP_IRQ_PRIORITY      14

#endif /* MCUCONF_H */