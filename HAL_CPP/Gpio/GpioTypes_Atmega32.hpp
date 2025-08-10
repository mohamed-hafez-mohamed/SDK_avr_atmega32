/**
 * @file E: GpioTypes_Atmega32.hpp
 * @brief Gpio Types For Atmega32 Target.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */

#ifndef GPIO_TYPES_ATMEGA_32_HPP
#define GPIO_TYPES_ATMEGA_32_HPP
/************************************
INCLUDES
************************************/
#include <stdint.h>
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
		namespace types
		{
			/**
          * @brief Gpio Port ID Enumeration.
          */
			enum class port_id : uint8_t
			{
            A = UINT8_C(0),              ///< Port A ID
				B = UINT8_C(1),              ///< Port B ID
				C = UINT8_C(2),              ///< Port C ID
				D = UINT8_C(3),              ///< Port D ID
			}; 

			/**
          * @brief Gpio Pin ID Enumeration.
          */
			enum class pin_id : uint8_t
			{
            PB0 = UINT8_C(1),            ///< Pin PB0 ID
				PB1 = UINT8_C(2),            ///< Pin PB1 ID
				PB2 = UINT8_C(3),            ///< Pin PB2 ID
				PB3 = UINT8_C(4),            ///< Pin PB3 ID
				PB4 = UINT8_C(5),            ///< Pin PB4 ID
				PB5 = UINT8_C(6),            ///< Pin PB5 ID
				PB6 = UINT8_C(7),            ///< Pin PB6 ID
				PB7 = UINT8_C(8),            ///< Pin PB7 ID
				PD0 = UINT8_C(14),           ///< Pin PD0 ID
				PD1 = UINT8_C(15),           ///< Pin PD1 ID
				PD2 = UINT8_C(16),           ///< Pin PD2 ID
				PD3 = UINT8_C(17),           ///< Pin PD3 ID
				PD4 = UINT8_C(18),           ///< Pin PD4 ID
				PD5 = UINT8_C(19),           ///< Pin PD5 ID
				PD6 = UINT8_C(20),           ///< Pin PD6 ID
				PD7 = UINT8_C(21),           ///< Pin PD7 ID
				PC0 = UINT8_C(22),           ///< Pin PD0 ID
				PC1 = UINT8_C(23),           ///< Pin PD1 ID
				PC2 = UINT8_C(24),           ///< Pin PD2 ID
				PC3 = UINT8_C(25),           ///< Pin PD3 ID
				PC4 = UINT8_C(26),           ///< Pin PD4 ID
				PC5 = UINT8_C(27),           ///< Pin PD5 ID
				PC6 = UINT8_C(28),           ///< Pin PD6 ID
				PC7 = UINT8_C(29),           ///< Pin PD7 ID
				PA0 = UINT8_C(40),           ///< Pin PA0 ID
				PA1 = UINT8_C(39),           ///< Pin PA1 ID
				PA2 = UINT8_C(38),           ///< Pin PA2 ID
				PA3 = UINT8_C(37),           ///< Pin PA3 ID
				PA4 = UINT8_C(36),           ///< Pin PA4 ID
				PA5 = UINT8_C(35),           ///< Pin PA5 ID
				PA6 = UINT8_C(34),           ///< Pin PA6 ID
				PA7 = UINT8_C(33)            ///< Pin PA7 ID
			};

			/**
          * @brief Gpio Direction Enumeration.
          */
			enum direction : uint8_t
			{
				Input = UINT8_C(0),          ///< Zero Means Input
				Output = UINT8_C(1)          ///< One Means Output
			};
			/**
          * @brief Gpio Port Width.
          */
			using port_width = uint8_t;
		} // namespace types
	} // namespace gpio
} // namespace HAL

#endif // GPIO_TYPES_ATMEGA_32_HPP

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/