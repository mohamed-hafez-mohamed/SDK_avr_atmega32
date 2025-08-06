/**
 * @file E: Timer_Core0.hpp
 * @brief Timer Driver Configuration Header File For Core0.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */

#ifndef HAL_TIMER_CORE_0_HPP
#define HAL_TIMER_CORE_0_HPP
/************************************
INCLUDES
************************************/
#include "HAL/Timer/Timer_Atmega32.hpp"
#include "HAL/Timer/TimerTraits_Atmega32.hpp"
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
        using Cpu_Timer0 = Atmega32_Timer<Atmega32_Timer0_Traits>; ///< Alias for Timer 0.
    }
}

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