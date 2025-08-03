/**
 * @file E: GpioConfig.hpp
 * @brief Gpio Driver Configuration Header File.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */

#ifndef GPIO_CONFIG_HPP
#define GPIO_CONFIG_HPP
/************************************
INCLUDES
************************************/
#include "HAL_CPP/Gpio/GpioTypes_Atmega32.hpp"
/************************************
 * MACROS / CONSTANT EXPRESSIONS
 ************************************/

/************************************
EXPORTED VARIABLES
************************************/

/************************************
NAMESPACES
************************************/
namespace HAL
{
	namespace gpio
	{
		namespace config
		{
			/**
          * @brief Gpio Port ID Enumeration Configuration.
          */
			using port_id = HAL::gpio::types::port_id;

			/**
          * @brief Gpio Pin ID Enumeration Configuration.
          */
			using pin_id = HAL::gpio::types::pin_id;
		} // namespace config
	} // namespace gpio
} // namespace HAL

#endif // GpioConfig.hpp

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/