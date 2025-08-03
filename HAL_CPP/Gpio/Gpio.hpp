/**
 * @file Gpio.hpp
 * @brief Gpio Driver Header File.
 * @author Mohamed Hafez
 * @date 2025-08-02
 * @version 1.0
 */
#ifndef GPIO_HPP
#define GPIO_HPP

/************************************
INCLUDES
************************************/
#include <cstdint>
#include "HAL_CPP/Config/GpioConfig.hpp"
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
		class Gpio;
		/********************* Configuration Section ********************** */
		using port_id = config::port_id;
		using pin_id = config::pin_id;
		using direction = types::direction;
		using port_width = types::port_width;
		/****************************************************************** */

		/**
       * @class pin_view
       * @brief Represents a read only view of a Gpio pin.
       */
		class pin_view
		{
			friend class Gpio;    ///< Only Gpio class can instantiate pin_view objects.
			public:
			   /**
             * @brief Get the pin ID.
             * @return The pin ID.
             */
				inline pin_id get_pin_id(void) const { return m_pin; }
            
				/**
             * @brief Get the pin direction.
             * @return The pin direction.
             */
				direction get_pin_direction(void) const;

				/**
             * @brief Read the pin value.
             * @return The pin current state.
             */
				bool get_pin_value(void) const;
            
				/**
             * @brief Implicit conversion to bool.
             * @return The pin current state.
             */
				operator bool(void) const;

				/**
             * @brief Copy consturctor and copy assignment operator are defaulted .
             * @details It's ok to copy the current state of this object to another object.
             */
				pin_view(const pin_view&) = default;               ///< Copy consturctor
            pin_view& operator =(const pin_view&) = default;   ///< Copy assignment operator

				/**
             * @brief Move consturctor and move assignment operator are defaulted .
             * @details It's ok to move the current state of this object to another object.
             */
				pin_view(pin_view&&) = default;                   ///< Move consturctor
            pin_view& operator =(pin_view&&) = default;       ///< Move assignment operator
			protected:
			pin_id m_pin;   ///< The pin id

			/**
          * @brief Parameterized constructor .
          * @details Initialize the pin.
			 * @param pin the id of the pin.
          */
			explicit inline pin_view(pin_id pin) : m_pin{pin}{}
		};

		/**
       * @class pin
       * @brief Represents a read/write of a Gpio pin.
       */
		class pin : public pin_view
		{
			friend class Gpio;    ///< Only Gpio class can instantiate pin_view objects.
			public:
			   /**
             * @brief set the pin direction to a specific direction.
             * @param pin_direction the direction to set (Input / Output).
             */
			   void set_direction(direction pin_direction);

				/**
             * @brief Set the pin state.
             */
				void set_pin(void);

				/**
             * @brief Clear the pin state.
             */
				void clear_pin(void);

				/**
             * @brief Toggle the pin state.
             */
				void toggle_pin(void);

				/**
             * @brief Write true/false to a pin.
             * @param pin_state the pin state to write (true / false).
             */
			   void write_pin(bool pin_state);
            
				/**
             * @brief Assignment operator.
             * @param pin_state the pin state to write (true / false).
				 * @return refrence to the current pin object.
             */
				pin& operator =(bool pin_state);

				/**
             * @brief Copy consturctor and copy assignment operator are deleted .
             * @details Prevents copy the pin as it represents a hardware resource.
             */
				pin(const pin&) = delete;               ///< Copy consturctor is deleted
            pin& operator =(const pin&) = delete;   ///< Copy assignment operator is deleted

				/**
             * @brief Move consturctor and move assignment operator are defaulted .
             * @details It's ok to move the current state of this object to another object.
             */
				pin(pin&&) = default;                   ///< Move consturctor
            pin& operator =(pin&&) = default;       ///< Move assignment operator
			protected:
			   /**
             * @brief Parameterized constructor .
             * @details Initialize the pin.
			    * @param pin the id of the pin.
             */
			   explicit inline pin(pin_id pin) : pin_view(pin) {}
		};

		/**
       * @class port_view
       * @brief Represents a read only view of a Gpio port.
       */
		class port_view
		{
			friend class Gpio;    ///< Only Gpio class can instantiate port_view objects.
			public:
			   /**
             * @brief Get the port ID.
             * @return The port ID.
             */
				inline port_id get_port_id(void) const { return m_port; }
            
				/**
             * @brief Get the port direction.
             * @return The port direction.
             */
				direction get_port_direction(void) const;

				/**
             * @brief Read the port value.
             * @return The port current state.
             */
				port_width get_port_value(void) const;
            
				/**
             * @brief Implicit conversion to port_width.
             * @return The port current state.
             */
				operator port_width(void) const;

				/**
             * @brief Copy consturctor and copy assignment operator are defaulted .
             * @details It's ok to copy the current state of this object to another object.
             */
				port_view(const port_view&) = default;               ///< Copy consturctor
            port_view& operator =(const port_view&) = default;   ///< Copy assignment operator

				/**
             * @brief Move consturctor and move assignment operator are defaulted .
             * @details It's ok to move the current state of this object to another object.
             */
				port_view(port_view&&) = default;                   ///< Move consturctor
            port_view& operator =(port_view&&) = default;       ///< Move assignment operator
			protected:
			port_id m_port;   ///< The port id

			/**
          * @brief Parameterized constructor .
          * @details Initialize the port.
			 * @param port the id of the port.
          */
			explicit inline port_view(port_id port) : m_port{port}{}
		};

		/**
       * @class port
       * @brief Represents a read/write of a Gpio port.
       */
		class port : public port_view
		{
			friend class Gpio;    ///< Only Gpio class can instantiate port_view objects.
			public:
				/**
             * @brief Set the port pins state.
				 * @param pin_mask A pin mask specifying which pins to set
             */
				void set_pins(port_width pin_mask);

				/**
             * @brief Clear the port pins state.
				 * @param pin_mask A pin mask specifying which pins to clear
             */
				void clear_pins(port_width pin_mask);

				/**
             * @brief Toggle the port pins state.
				 * @param pin_mask A pin mask specifying which pins to toggle
             */
				void toggle_pins(port_width pin_mask);

				/**
             * @brief Write true/false to a port.
             * @param port_state the port state to write.
             */
			   void write_port(port_width port_state);
            
				/**
             * @brief Assignment operator.
             * @param port_state the port state to write.
				 * @return refrence to the current port object.
             */
				port& operator =(port_width port_state);

				/**
             * @brief Copy consturctor and copy assignment operator are deleted .
             * @details Prevents copy the port as it represents a hardware resource.
             */
				port(const port&) = delete;               ///< Copy consturctor is deleted
            port& operator =(const port&) = delete;   ///< Copy assignment operator is deleted

				/**
             * @brief Move consturctor and move assignment operator are defaulted .
             * @details It's ok to move the current state of this object to another object.
             */
				port(port&&) = default;                   ///< Move consturctor
            port& operator =(port&&) = default;       ///< Move assignment operator
			protected:
			   /**
             * @brief Parameterized constructor .
             * @details Initialize the port.
			    * @param port the id of the port.
             */
			   explicit inline port(port_id port) : port_view(port) {}
		};

		/**
       * @class Gpio
       * @brief Gpio driver for managing Gpio ports and pins.
       */
		class Gpio
		{
			public:
			   /**
             * @brief Default constructor for Gpio.
             */
			   Gpio(void) = default;
   
			   /**
             * @brief Initialize Gpio driver.
             */
			   void init(void);

				/**
             * @brief Get the pin object.
			    * @param pin_id the id of the pin.
				 * @return pin object
             */
				inline pin get_pin(pin_id pin_id)
				{
					return pin(pin_id);
				}

				/**
             * @brief Get the pin view object.
			    * @param pin_id the id of the pin.
				 * @return pin view object
             */
				inline pin_view get_pin_view(pin_id pin_id) const
				{
					return pin_view(pin_id);
				}

				/**
             * @brief Get the port object.
			    * @param port_id the id of the port.
				 * @return port object
             */
				inline port get_port(port_id port_id)
				{
					return port(port_id);
				}

				/**
             * @brief Get the port view object.
			    * @param port_id the id of the port.
				 * @return port view object
             */
				inline port_view get_port_view(port_id port_id) const
				{
					return port_view(port_id);
				}

            /**
             * @brief Overload the [] operator to get the port object via it's id.
			    * @param port_id the id of the port.
				 * @return port object
             */
            inline port operator [](port_id port_id)
				{
					return port(port_id);
				}

				/**
             * @brief Overload the [] operator to get the port object via it's id.
			    * @param port_id the id of the port.
				 * @return port view object
             */
            inline port_view operator [](port_id port_id) const
				{
					return port_view(port_id);
				}

		};
	}
}

#endif // Gpio_HPP

/*******************************************************************************
Change History
 ********************************************************************************
   Date        Who            Change
------------ --------  ------------------------------------------------

 *******************************************************************************/

/*=============================================================================*
 End of File
 *=============================================================================*/