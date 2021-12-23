/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/*! @name PORTB18 (number 41), J1[1]/LCD_P14
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P14_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P14_PIN 18U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P14_PIN_MASK (1U << 18U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTB19 (number 42), J1[3]/LCD_P15
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P15_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P15_PIN 19U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P15_PIN_MASK (1U << 19U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTC0 (number 43), J1[5]/LCD_P20/USB_SOF_OUT
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P20_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P20_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P20_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTC4 (number 53), J1[7]/LCD_P24
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P24_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P24_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P24_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTC6 (number 55), J1[9]/LCD_P26
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P26_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P26_PIN 6U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P26_PIN_MASK (1U << 6U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTC7 (number 56), J1[11]/USB_SOF_OUT/LCD_P27
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P27_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P27_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P27_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTD0 (number 57), LCD-09_P40
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P40_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P40_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P40_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTD2 (number 59), J2[4]/D9/LCD_P42
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P42_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P42_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P42_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTD3 (number 60), J1[6]/D2/LCD_P43
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P43_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P43_PIN 3U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P43_PIN_MASK (1U << 3U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTD4 (number 61), J2[6]/D10/SPI1_PCS0/LCD_P44
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P44_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P44_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P44_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTE20 (number 9), J4[1]/DIFF_ADC0_DP/LCD_P59
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P59_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P59_PIN 20U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P59_PIN_MASK (1U << 20U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTE21 (number 10), J4[3]/DIFF_ADC0_DM/LCD_P60
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_LCD_P60_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_LCD_P60_PIN 21U                   /*!<@brief PORT pin number */
#define BOARD_LCD_P60_PIN_MASK (1U << 21U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLCDPins(void);

/*! @name PORTA4 (number 26), J1[10]/D4/SW1
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SW1_FGPIO FGPIOA             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SW1_GPIO GPIOA               /*!<@brief GPIO peripheral base pointer */
#define BOARD_SW1_GPIO_PIN_MASK (1U << 4U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SW1_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_SW1_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_SW1_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                           /* @} */

/*! @name PORTC3 (number 46), SW3/LLWU_P7/LCD_P23
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SW3_FGPIO FGPIOC             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SW3_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_SW3_GPIO_PIN_MASK (1U << 3U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SW3_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_SW3_PIN 3U                   /*!<@brief PORT pin number */
#define BOARD_SW3_PIN_MASK (1U << 3U)      /*!<@brief PORT pin mask */
                                           /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitBUTTONSPins(void);

/*! @name PORTE31 (number 19), LED2
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED2_FGPIO FGPIOE              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED2_GPIO GPIOE                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED2_GPIO_PIN_MASK (1U << 31U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED2_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED2_PIN 31U                   /*!<@brief PORT pin number */
#define BOARD_LED2_PIN_MASK (1U << 31U)      /*!<@brief PORT pin mask */
                                             /* @} */

/*! @name PORTD5 (number 62), J2[12]/D13/SPI1_SCK/LED1/LCD_P45
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED1_FGPIO FGPIOD             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED1_GPIO GPIOD               /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED1_GPIO_PIN_MASK (1U << 5U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED1_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_LED1_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_LED1_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                            /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDsPins(void);

#define SOPT5_LPUART0RXSRC_LPUART_RX 0x00u /*!<@brief LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX 0x00u /*!<@brief LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*! @name PORTA1 (number 23), J1[2]/D0/UART0_RX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART0_RX_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART0_RX_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART0_RX_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*! @name PORTA2 (number 24), J1[4]/D1/UART0_TX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART0_TX_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART0_TX_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART0_TX_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void);

/*! @name USB0_DP (number 5), J10[3]/USB_DP
  @{ */
/* @} */

/*! @name USB0_DM (number 6), J10[2]/USB_DM
  @{ */
/* @} */

/*! @name VREGIN (number 8), USB_REGIN
  @{ */
/* @} */

/*! @name PORTC0 (number 43), J1[5]/LCD_P20/USB_SOF_OUT
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_USB_SOF_OUT_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_USB_SOF_OUT_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_USB_SOF_OUT_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                   /* @} */

/*! @name PORTA5 (number 27), J1[12]/D5/USB_CLKIN
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_USB0_CLKIN_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_USB0_CLKIN_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_USB0_CLKIN_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                                  /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitUSBPins(void);

/*! @name PORTE24 (number 20), U2[7]/U10[4]/I2C0_SCL
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_I2C0_SCL_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_I2C0_SCL_PIN 24U                   /*!<@brief PORT pin number */
#define BOARD_I2C0_SCL_PIN_MASK (1U << 24U)      /*!<@brief PORT pin mask */
                                                 /* @} */

/*! @name PORTE25 (number 21), U2[6]/U10[6]/I2C0_SDA
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_I2C0_SDA_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_I2C0_SDA_PIN 25U                   /*!<@brief PORT pin number */
#define BOARD_I2C0_SDA_PIN_MASK (1U << 25U)      /*!<@brief PORT pin mask */
                                                 /* @} */

/*! @name PORTD1 (number 58), U2[9]/U10[9]/INT2_ACCEL/INT1_MAG/LCD_P41
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INT2_ACCEL_FGPIO FGPIOD             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_INT2_ACCEL_GPIO GPIOD               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INT2_ACCEL_GPIO_PIN_MASK (1U << 1U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INT2_ACCEL_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_INT2_ACCEL_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_INT2_ACCEL_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                  /* @} */

/*! @name PORTC5 (number 54), J1[15]/INT1_ACCEL/LCD_P25
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INT1_ACCEL_FGPIO FGPIOC             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_INT1_ACCEL_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INT1_ACCEL_GPIO_PIN_MASK (1U << 5U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INT1_ACCEL_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INT1_ACCEL_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_INT1_ACCEL_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                                  /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitACCEL_I2CPins(void);

/*! @name PORTA18 (number 32), EXTAL_32KHZ
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_EXTAL_32KHZ_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_EXTAL_32KHZ_PIN 18U                   /*!<@brief PORT pin number */
#define BOARD_EXTAL_32KHZ_PIN_MASK (1U << 18U)      /*!<@brief PORT pin mask */
                                                    /* @} */

/*! @name PORTA19 (number 33), XTAL_32KHZ
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_XTAL_32KHZ_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_XTAL_32KHZ_PIN 19U                   /*!<@brief PORT pin number */
#define BOARD_XTAL_32KHZ_PIN_MASK (1U << 19U)      /*!<@brief PORT pin mask */
                                                   /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitOSCPins(void);

/*! @name PORTE22 (number 11), J4[5]/DIFF_ADC1_DP
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITLIGHT_ADCPINS_LIGHT_SENSOR_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITLIGHT_ADCPINS_LIGHT_SENSOR_PIN 22U                   /*!<@brief PORT pin number */
#define BOARD_INITLIGHT_ADCPINS_LIGHT_SENSOR_PIN_MASK (1U << 22U)      /*!<@brief PORT pin mask */
                                                                       /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLIGHT_ADCPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
