/*******************************************************************************
* Title                 :   LED 
* Filename              :   LED_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   1/8/2025
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description 
*  17/08/20   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file LED_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/
extern "C"
{
    #include "platform_PCfg.h"
    #include "common.h"
	#include "GPIO.h"
}	
#include "Gpio.hpp"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
int main()
{
    using namespace HAL::gpio;
   Gpio l_gpio;
   pin l_pinA0 = l_gpio.get_pin(static_cast<pin_id> (A0));
   pin l_pinA1 = l_gpio.get_pin(static_cast<pin_id> (A1));
   pin l_pinA2 = l_gpio.get_pin(static_cast<pin_id> (A2));
   l_pinA0.set_direction(static_cast<direction> (PORT_INPUT));
   l_pinA1.set_direction(static_cast<direction> (PORT_INPUT));
   l_pinA2.set_direction(static_cast<direction> (PORT_OUTPUT));
    while(1)
    {
        static uint8 l_switch1Status = 0;
        static uint8 l_switch2Status = 0;
        l_switch1Status = l_pinA0.get_pin_value();
        l_switch2Status = l_pinA1.get_pin_value();
		if(l_switch1Status != 0)
		{
		   l_switch1Status = 0;
		   l_pinA2.set_pin();
		}
        if(l_switch2Status != 0)
		{
		   l_switch2Status = 0;
		   l_pinA2.clear_pin();
		}
    }
    return 0;
}

/*************** END OF FUNCTIONS ***************************************************************************/
