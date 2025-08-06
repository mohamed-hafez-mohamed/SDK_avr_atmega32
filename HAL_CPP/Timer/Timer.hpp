/**
 * @file Timer.hpp
 * @brief Timer Driver Header File.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */
#ifndef TIMER_HPP
#define TIMER_HPP

/************************************
INCLUDES
************************************/
#include <cstdint>
#include "HAL_CPP/Config/TimerConfig.hpp"
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
		template<typename Traits>
		class Timer
		{
			public:
			    /************************************
                 TYPE ALIASES
                 ************************************/
			    using timer_id_t = typename Traits::timer_id_t;                     ///< Type for Timer ID
			    using timer_base_address_t = typename Traits::timer_base_address_t; ///< Type for Timer Base Address
				using timer_width_t = typename Traits::timer_width_t;               ///< Type for Timer Width
				using prescaler_t = typename Traits::prescaler_t;                   ///< Type for Timer Prescaler
				using Config_t = typename Traits::Config_t;                         ///< Type for Timer Config
				using Callback_t = typename Traits::Callback_t;                     ///< Type for Timer Callback
				/************************************
				 STATIC VARIABLES
				 ************************************/
				static constexpr timer_id_t timer_id = Traits::timer_id;        ///< Timer ID for this Timer instance.
				static Callback_t callback;                                     ///< Callback function to be called on timer overflow.
                
				/************************************
				 CONSTRUCTORS 
				 ************************************/
                Timer() = default;                       ///< Default constructor.
                Timer(const Timer&) = delete;            ///< Delete copy constructor.
                Timer& operator=(const Timer&) = delete; ///< Delete copy assignment operator.
                Timer(Timer&&) = default;                ///< Default move constructor.
                Timer& operator=(Timer&&) = default;     ///< Default move assignment operator.
				/************************************
				 METHODS
				 ************************************/
		
				/**
				 * @brief Initialize the timer.
				 * @param config The configuration for the timer.
				 */
				void init(const Config_t& config);

				/**
				 * @brief Start the timer with a specified prescaler.
				 */
				void start();

				/**
				 * @brief Stop the timer.
				 */
				void stop(void);
                
				/**
                 * @brief Gets the current value of the timer.
                 * @return The current value of the timer.
                 */
                TimerWidth get_value() const;
    
                /**
                 * @brief Sets the prescaler for the timer.
                 * @param prescaler The prescaler value to set.
                 */
                void set_prescaler(Prescaler prescaler);

				/**
				 * @brief Set the callback function to be called on timer overflow.
				 * @param callback The callback function.
				 */
				void set_callback(Callback _callback){callback = _callback;};
			    
				/**
				 * @brief Enables the timer interrupt.
				 */
				void enable_interrupt();

				/**
				 * @brief Disables the timer interrupt.
				 */
                void disable_interrupt();
			protected:
				static constexpr timer_base_address_t timer_base_address = Traits::timer_base_address; ///< Base address for this Timer instance.

		};

		/**
         * @brief Static member initialization for the Timer class template.
         * @details This initializes the static member 'callback' of the Timer class template for the given Traits type.
         * @note This is a templated static variable, so it is valid to define and initialize it in the header file.
         */
        template<typename Traits>
        typename Timer<Traits>::callback_t Timer<Traits>::callback{}; 

		
	} // namespace timer
} // namespace HAL

#endif // TIMER_HPP

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/