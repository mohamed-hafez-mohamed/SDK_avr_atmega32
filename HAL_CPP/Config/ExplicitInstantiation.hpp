/**
 * @file ExplicitInstantiation.hpp
 * @brief Explicit Instantiation Header File for F29H85X Timers.
 * @details The explicit instantiation is necessary to ensure that the template classes
 *  are compiled and linked correctly, especially when used across different translation units.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */

#ifndef _HAL_TIMER_EXPLICIT_INSTANTIATION_HPP
#define _HAL_TIMER_EXPLICIT_INSTANTIATION_HPP

/************************************
INCLUDES
************************************/
#include "HAL/Timer/Timer_F29H85x.hpp"
#include "HAL/Timer/TimerTraits_F29H85x.hpp"

/************************************
NAMESPACES
************************************/
namespace HAL{
    namespace timer{

        //Explicitly instantiate the Timer class with the F29H85x_Traits
        template class Timer<Atmega32_Timer0_Traits>;
        //Explicitly instantiate the F29H85X_Timer class with the F29H85x_Traits
        template class Atmega32_Timer<Atmega32_Timer0_Traits>;
    }
}

#endif // _HAL_TIMER_EXPLICIT_INSTANTIATION_HPP_