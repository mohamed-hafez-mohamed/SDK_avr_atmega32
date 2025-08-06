/**
 * @file Timer_Atmega32.cpp
 * @brief Timer Driver Source File.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */
/************************************
INCLUDES
************************************/
#include "MCAL/TIMER0/TIMER0.h"
#include "Timer.hpp"
/************************************
EXTERN VARIABLES
************************************/

/************************************
PRIVATE MACROS / DEFINES / CONSTANT EXPRESSIONS
************************************/

/************************************
PRIVATE TYPEDEFS / CLASSES
************************************/

/************************************

STATIC / ANONYMOUS NAMESPACE VARIABLES
************************************/

/************************************

GLOBAL VARIABLES
************************************/

/************************************

STATIC FUNCTION PROTOTYPES
************************************/

/************************************

STATIC FUNCTION IMPLEMENTATION
************************************/

/************************************

GLOBAL FUNCTIONS IMPLEMENTATION
**********************************/
using namespace HAL::timer;

typename<typename Traits>
void Timer<Traits>::init(const config_t& config)
{
	// Initialization logic for the timer based on the provided configuration.
	// This is typically done in the mcal library, so this function may be empty.
}

template<typename Traits>
void Timer<Traits>::start()
{
	///< Start the timer with the specified prescaler.
}

template<typename Traits>
void Timer<Traits>::stop()
{
	///< Stop the timer
}
	
template<typename Traits>
TimerWidth Timer<Traits>::get_value() const
{
	///< Get the current timer value.
}

template<typename Traits>
TimerWidth Timer<Traits>::set_prescaler(Prescaler prescaler) 
{
	///< Set the prescaler for the timer.
}

template<typename Traits>
void Timer<Traits>::set_callback(Callback_t cb)
{
	///< Set the callback function to be called on timer overflow.
}

template<typename Traits>
void Timer<Traits>::enable_interrupt()
{
	///< Enable the timer interrupt.
}

template<typename Traits>
void Timer<Traits>::disable_interrupt()
{
	///< Disable the timer interrupt.
}

template<typename Traits>
void Atmega32_Timer<Traits>::clear_overflow_flag(void)
{
	///< Clear the timer overflow flag.
}

template<typename Traits>
void Atmega32_Timer<Traits>::is_overflowed(void)
{
	///< Check if the timer has overflowed.
	///< Return true if overflowed, false otherwise.
}

template<typename Traits>
void Atmega32_Timer<Traits>::set_period(timer_width_t period)
{
	///< Set the timer period.
	///< This typically involves writing to the timer's compare register or similar.
	///< The exact implementation will depend on the specific timer hardware and its registers.
}

// The purpose of the following include is to ensure that the class templates are instantiated. 
// As a result of implementing the methods of a class template in a source file, we need to explicitly instantiate them in the same implementation file.
// This is necessary to avoid linker errors when the class templates are used in multiple translation units.
// This file should be defined by each core, depending on the specific timers used by that core.
#include "Config/HAL/Timer/ExplicitInstantiation.hpp"
/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/