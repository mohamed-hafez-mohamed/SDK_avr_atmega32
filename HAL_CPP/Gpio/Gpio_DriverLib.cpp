/**
 * @file Gpio_DriverLib.cpp
 * @brief Gpio Driver Source File.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */
/************************************
INCLUDES
************************************/
#include "Gpio.hpp"
#include "MCAL\GPIO\GPIO.h"
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
using namespace HAL::gpio;

void Gpio::init(void)
{
   /** 
	 * Initialization is done in the mcal libray.
	 * Add any initialization code if needed.
	 */
}

bool pin_view::get_pin_value(void) const
{
	return static_cast<bool>(pin_read(static_cast<uint8_t>(m_pin)));
}

pin_view::operator bool(void) const
{
	return static_cast<bool>(pin_read(static_cast<uint8_t>(m_pin)));
}

void pin::set_direction(direction pin_direction)
{
	pin_dirc(static_cast<uint8_t>(m_pin), static_cast<pinDirc_t>(pin_direction));
}

void pin::set_pin(void)
{
	pin_write(static_cast<uint8_t>(m_pin), static_cast<logic_status_t>(true));
}

void pin::clear_pin(void)
{
	pin_write(static_cast<uint8_t>(m_pin), static_cast<logic_status_t>(false));
}

void pin::write_pin(bool pin_state)
{
	pin_write(static_cast<uint8_t>(m_pin), static_cast<logic_status_t>(pin_state));
}

pin& pin::operator =(bool pin_state)
{
   pin_write(static_cast<uint8_t>(m_pin), static_cast<logic_status_t>(pin_state));
	return *this;
}

port_width port_view::get_port_value(void) const
{
	return static_cast<bool>(port_read(static_cast<port_t>(m_port)));
}

port_view::operator port_width(void) const
{
	return static_cast<bool>(port_read(static_cast<port_t>(m_port)));
}

void port::write_port(port_width port_state)
{
	port_write(static_cast<port_t>(m_port), static_cast<uint8_t>(port_state));
}

port& port::operator =(port_width port_state)
{
   port_write(static_cast<port_t>(m_port), static_cast<uint8_t>(port_state));
	return *this;
}

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/