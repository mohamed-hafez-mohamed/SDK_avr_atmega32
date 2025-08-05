/**
 * @file E: Timer_Core0.hpp
 * @brief Timer Driver Configuration Header File For Core0.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */

#ifndef TIMER_CORE_0_HPP
#define TIMER_CORE_0_HPP
/************************************
INCLUDES
************************************/
#include "HAL_CPP/Timer/TimerTraits_Atmega32.hpp"
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

#endif // TIMER_CORE_0_HPP

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/