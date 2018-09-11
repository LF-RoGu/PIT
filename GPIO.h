/*
 * GPIO.h
 *
 *  Created on: Sep 11, 2018
 *      Author: LuisFernando
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "DataTypeDefinitions.h"


/**Defines freq por system clock**/
#define SYSTEM_CLOCK_FREQ 21000000
/**Defines definidos por jlpe**/
/** Constant that represent the clock enable for GPIO A */
#define GPIO_CLOCK_GATING_PORTA 0x00000200
/** Constant that represent the clock enable for GPIO B */
#define GPIO_CLOCK_GATING_PORTB 0x00000400
/** Constant that represent the clock enable for GPIO C */
#define GPIO_CLOCK_GATING_PORTC 0x00000800
/** Constant that represent the clock enable for GPIO D  */
#define GPIO_CLOCK_GATING_PORTD 0x00001000
/** Constant that represent the clock enable for GPIO E */
#define GPIO_CLOCK_GATING_PORTE 0x00002000

/** Selects a pullup resistor */
#define GPIO_PS    0x00000001
/** Enables the pulldown or pullup resistors*/
#define GPIO_PE    0x00000002
/** Selects slow or fast slew rate */
#define GPIO_SRE   0x00000004
/** Enables the passive filter */
#define GPIO_PFE   0x00000010
/** Enables the open drain  */
#define GPIO_ODE   0x00000020
/** Selects between low drive strength and high drive strength */
#define GPIO_DSE   0x00000040
/** Selects alternative function 1 (GPIO) */
#define GPIO_MUX1  0x00000100
/** Selects alternative function 2 */
#define GPIO_MUX2  0x00000200
/** Selects alternative function 3 */
#define GPIO_MUX3  0x00000300
/** Selects alternative function 4 */
#define GPIO_MUX4  0x00000400
/** Selects alternative function 5 */
#define GPIO_MUX5  0x00000500
/** Selects alternative function 6 */
#define GPIO_MUX6  0x00000600
/** Selects alternative function 7 */
#define GPIO_MUX7  0x00000700
/** Sets DMA request on rising edge.*/
#define DMA_RISING_EDGE    0x00010000
/** Sets DMA request on falling edge.*/
#define DMA_FALLING_EDGE   0x00020000
/** Sets DMA request on either edge.*/
#define DMA_EITHER_EDGE    0x00030000
/** Sets Interrupt when logic 0.*/
#define INTR_LOGIC0        0x00080000
/** Sets Interrupt on rising-edge.*/
#define INTR_RISING_EDGE   0x00090000
/** Sets Interrupt on falling-edge.*/
#define INTR_FALLING_EDGE  0x000A0000
/** Sets Interrupt on either edge.*/
#define INTR_EITHER_EDGE   0x000B0000
/** Sets Interrupt when logic 1.*/
#define INTR_LOGIC1        0x000C0000

/*! This definition is used to configure whether a pin is an input or an output*/
typedef enum {GPIO_INPUT,/*!< Definition to configure a pin as input */
			  GPIO_OUTPUT /*!< Definition to configure a pin as output */
			 }GPIO_PIN_CONFIG;
/*! These constants are used to select an specific port in the different API functions*/
typedef enum{GPIO_A, /*!< Definition to select GPIO A */
			 GPIO_B, /*!< Definition to select GPIO B */
			 GPIO_C, /*!< Definition to select GPIO C */
			 GPIO_D, /*!< Definition to select GPIO D */
			 GPIO_E, /*!< Definition to select GPIO E */
			 GPIO_F  /*!< Definition to select GPIO F */
			} GPIO_portNameType;

/*! This data type is used to configure the pin control register*/
typedef const uint32 GPIO_pinControlRegisterType;

uint8 GPIO_clockGating(GPIO_portNameType portName);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief
 	 	 This function configure different characteristics in an specific GPIO:
 	 	 pullup or pulldown resistor,slew rate, drive strength, passive filter,open drain pin,alternative functions in the GPIO
 	 \param[in] portName Port to be configured.
 	 \param[in]  pin Specific pin to be configured.
 	 \param[in]  pinControlRegister Pointer to a constant configuration value that configures the pin characteristics. In particular this function
 	 uses the definitions GPIO_PS, GPIO_PE, GPIO_MUX1 etc. For example, in order to configure the pullup resistor ans the pin as GPIO it is need to
 	 declare the type in following way:
 	 GPIO_pinControlRegisterType PinControlRegister = GPIO_MUX1|GPIO_PS|GPIO_PE;
 	 \return 1 if the portName is valid else return 0
 */
uint8 GPIO_pinControlRegister(GPIO_portNameType portName,uint8 pin,GPIO_pinControlRegisterType* pinControlRegister);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief
 	 	 This function configure all the GPIO port as input when 1 logic is written or output when 0 logic is written.
 	 \param[in] portName Port to configure
 	 \param[in] direction Input value to specify the port as input or output.
 	 \return void

 */
void GPIO_dataDirectionPORT(GPIO_portNameType portName, uint32 direction);
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief  This function configure specific pins of a GPIO port as input when 1 logic is written or output when 0 logic is written.
 	 \param[in] portName Port to configure.
 	 \param[in] state Value to specify if the pin behaves as input or output.
 	 \param[in] pin Input value to specify the pin number.
 	 \return void
 */

#endif /* GPIO_H_ */
