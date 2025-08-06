/**
 * @file E: Timer_Atmega32.hpp
 * @brief Timer Atmega32 Header File For Atmega32 Target.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */

#ifndef TIMER_ATMEGA_32_HPP
#define TIMER_ATMEGA_32_HPP
/************************************
INCLUDES
************************************/
#include "Timer.hpp"
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
	namespace timer
	{
		/**
		 * @brief Timer class for Atmega32.
		 * @details This class provides an interface for using the timer functionality on Atmega32.
		 */
		template<typename Traits> : public Timer<Traits>
		class Atmega32_Timer
		{
			public:
				using timer_width_t = typename Traits::timer_width_t;          ///< Type for Timer Width

				/**
				 * @brief Clear the timer over flow flag.
				 */
				void clear_overflow_flag(void);

				/**
				 * @brief Check the overflow flag status.
				 * @return True if the overflow flag is set, false otherwise.
				 */
				void is_overflowed(void);

				/**
				 * @brief Set the timer period.
				 * @return period the period set fpr the timer.
				 */
				void set_period(timer_width_t period);
		};
	} // namespace gpio
} // namespace HAL

#endif // TIMER_ATMEGA_32_HPP

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/