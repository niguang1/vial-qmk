#ifndef MCUCONF_H
#define MCUCONF_H

#define STM32F103_MCUCONF

#define STM32_USB_CLOCK_REQUIRED            TRUE
#define STM32_USBPRE                        STM32_USBPRE_DIV1P5


#define STM32_PWM_USE_TIM1 TRUE
#define STM32_PWM_USE_ADVANCED TRUE

/*
 * SPI driver system settings.
 */
#undef STM32_SPI_USE_SPI1
#define STM32_SPI_USE_SPI1                  TRUE
#define STM32_SPI_USE_SPI2                  FALSE
#define STM32_SPI_USE_SPI3                  FALSE
// #define STM32_SPI_SPI1_DMA_PRIORITY         1
// #define STM32_SPI_SPI2_DMA_PRIORITY         1
// #define STM32_SPI_SPI3_DMA_PRIORITY         1
// #define STM32_SPI_SPI1_IRQ_PRIORITY         10
// #define STM32_SPI_SPI2_IRQ_PRIORITY         10
// #define STM32_SPI_SPI3_IRQ_PRIORITY         10
// #define STM32_SPI_DMA_ERROR_HOOK(spip)      osalSysHalt("DMA failure")


/*
 * USB driver system settings.
 */
#define STM32_USB_USE_USB1                  TRUE
#define STM32_USB_LOW_POWER_ON_SUSPEND      FALSE
#define STM32_USB_USB1_HP_IRQ_PRIORITY      13
#define STM32_USB_USB1_LP_IRQ_PRIORITY      14


#endif /* MCUCONF_H */