/**
 * @file E: TimerTraits_Atmega32.hpp
 * @brief Timer Traits For Atmega32 Target.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */

#ifndef TIMER_TRAITS_ATMEGA_32_HPP
#define TIMER_TRAITS_ATMEGA_32_HPP
/************************************
INCLUDES
************************************/
#include <cstdint>
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
		 * @brief Timer Traits Class for Atmega32.
		 */
		struct TimerTraits
		{ 
			using timer_id_t           = std::uint8_t;   ///< Type for Timer ID
			using timer_base_address_t = std::uint8_t;   ///< Type for Timer Base Address
			using Callback_t = void(*)(void);            ///< Type alias for Timer Callback function type.
			/**
		     * @brief Enum for Timer Prescaler options.
		     */
			enum class prescaler_t : std::uint8_t
			{
				NO_CLK_SRC         = UINT8_C(0),          ///< Timer Disable
	            NO_PRESCALING      = UINT8_C(1),          ///< No-Prescaling
	            DIVIDE_BY_8        = UINT8_C(2),          ///< Divide by 8
	            DIVIDE_BY_64       = UINT8_C(3),          ///< Divide by 64
	            DIVIDE_BY_256      = UINT8_C(4),          ///< Divide by 256
	            DIVIDE_BY_1024     = UINT8_C(5),          ///< Divide by 1024
	            EXT_CLK_FALLING    = UINT8_C(6),          ///< External Clock on Falling Edge
	            EXT_CLK_RISING     = UINT8_C(7)           ///< External Clock on Rising Edge
			};

            struct Config_t{};    ///< Currently the configuration/initialization is handled entirely by TI Sysconfig, so we'll keep it empty.
		};

		/**
		 * @brief Timer 0 Traits Class for Atmega32.
		 */
		struct Atmega32_Timer0_Traits : public TimerTraits 
        {
		   using timer_width_t = std::uint8_t;                                              ///< Type for Timer Width
           static constexpr timer_id_t timer_id = 0;                                        ///< Timer ID for Timer 0.
           static constexpr timer_base_address_t timer_base_address = UINT32_C(0x52);       ///< Base address for Timer 0.
        };
	} // namespace timer
} // namespace HAL

#endif // TIMER_TRAITS_ATMEGA_32_HPP

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/