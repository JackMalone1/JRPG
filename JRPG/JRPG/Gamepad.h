#ifndef GAMEPAD_H
#define GAMEPAD_H

#ifdef _DEBUG
#define GAMEPAD_DEBUG_INFO
#endif // _DEBUG


/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 21/03/2020
/// </summary>

#include <SFML/Graphics.hpp>
#include <iostream>

/// <summary>
/// A struct for storing the state of the gamepad.
/// </summary>
struct GamepadState
{
	bool FaceBottom{ false }; // XBox360: A		PS4: X
	bool FaceRight{ false }; // XBox360: B		PS4: Circle
	bool FaceLeft{ false }; // XBox360: X		PS4: Square
	bool FaceTop{ false }; // XBox360: Y		PS4: Triangle
	bool LB{ false };
	bool RB{ false };
	bool LeftThumbStickClick{ false };
	bool RightThumbStickClick{ false };
	bool DpadUp{ false };
	bool DpadDown{ false };
	bool DpadLeft{ false };
	bool DpadRight{ false };
	bool Start{ false }; // Also Options button on PS4 controller
	bool Back{ false }; // Also Share button on PS4 controller
	bool Options{ false }; // Also Start button on XBox360 controller
	bool Share{ false }; // Also Back button on XBox360 controller
	float RTrigger{ 0.0f };
	float LTrigger{ 0.0f };
	sf::Vector2f LeftThumbStick{ 0.0f, 0.0f };
	sf::Vector2f RightThumbStick{ 0.0f, 0.0f };

	// Extras (Not shared with different controllers/no equivalent button)
	bool PS4Logo{ false };
	bool TouchpadClick{ false };
};

/// <summary>
/// An enum to store what type of controller is connected.
/// </summary>
enum class ControllerType
{
	XBox360,
	Playstation4
};

/// <summary>
/// A class for easier access and automatic button mapping of connected controllers.
/// </summary>
class Gamepad
{
public:

	/// <summary>
	/// Sets base values for the controller. The connect() function should still be called before use
	/// </summary>
	Gamepad();

	/// <summary>
	/// Updates the gamepad state accordingly depending on the controller type.
	/// <para>Should be called every frame BEFORE use.</para>
	/// </summary>
	void update();

	/// <summary>
	/// Tries to identify the type of connected controller.
	/// <para>Returns true if the type was detected.</para>
	/// <para>Should only really be called after the connect() function has been called.</para>
	/// <para>The connect() function calls this automatically, but can be called again</para>
	/// <para>to check if identification was successful.</para>
	/// </summary>
	/// <returns>Whether the type was detected or not</returns>
	bool identifyControllerType();

	/// <summary>
	/// Connects the controller if there is a connected controller available.
	/// <para>Should only be called once per controller, or if the controller is disconnected.</para>
	/// <para>Should be called before the controller is ever used for best results</para>
	/// </summary>
	/// <returns>Whether the controller connected correctly</returns>
	bool connect();

	/// <summary>
	/// Checks if the controller is currently connected
	/// </summary>
	/// <returns></returns>
	bool const isConnected() const;

	/// <summary>
	/// Returns the current state of the controller.
	/// </summary>
	/// <returns>Current state of the controller</returns>
	GamepadState const & getCurrentState() const;

	/// <summary>
	/// Returns the previous state of the controller.
	/// </summary>
	/// <returns>Previous state of the controller</returns>
	GamepadState const& getPreviousState() const;

	/// <summary>
	/// Returns the number of connected controllers.
	/// </summary>
	/// <returns>Number of connected controllers</returns>
	static int const getNoOfConnectedControllers();

	/// <summary>
	/// Set the type of connected controller.
	/// <para>For if you want to ask the user what type of controller they are using.</para>
	/// </summary>
	/// <param name="t_type">Controller type</param>
	void setControllerType(ControllerType const t_type);

	/// <summary>
	/// Returns the type of controller connected
	/// </summary>
	/// <returns>Type of controller</returns>
	ControllerType const getControllerType() const;

	/// <summary>
	/// Sets the deadzone for the analog sticks.
	/// <para>Should be a value between 0 (No deadzone) and 100 (no feedback).</para>
	/// <para>By default, the deadzone is 15.</para>
	/// </summary>
	/// <param name="t_deadzone">Deadzone value</param>
	void setAnalogStickDeadzone(float const t_deadzone);

	/// <summary>
	/// Returns the current analog stick deadzone value.
	/// </summary>
	/// <returns>Analog stick deadzone</returns>
	float const getAnalogStickDeadzone() const;

	/// <summary>
	/// Sets the index of the gamepad the object refers to.
	/// <para>This function should normally never be used and may cause issues with further controllers.</para>
	/// <para>Only call this function if you know what you're doing.</para>
	/// </summary>
	/// <param name="t_index">New gamepad index</param>
	void setGamepadIndex(int const t_index);

	/// <summary>
	/// Sets the default controller type the gamepad is set to if no type could be detected.
	/// </summary>
	/// <param name="t_type">Type of controller</param>
	static void setDefaultControllerType(ControllerType const t_type);

private:

	/// <summary>
	/// Updates the current state with the XBox 360 controller button map.
	/// </summary>
	void updateXBox360();
	
	/// <summary>
	/// Updates the current state with the playstation 4 controller button map.
	/// </summary>
	void updatePlaystation4();

	/// <summary>
	/// Sets the values of the analog sticks to 0 if they are below the deadzone threshold.
	/// </summary>
	void confineAnalogSticksToDeadzone();

	// Number of connected controllers.
	static int s_noOfControllers;

	// Default controller if no specific type can be identified (By default set to XBox 360)
	static ControllerType s_defaultControllerType;

	// Deadzone for the dpad (really a joystick).
	const float m_DPAD_DEADZONE{ 50.0f };

	// Deadzone for the XBox 360 triggers.
	const float m_XBOX_TRIGGER_DEADZONE{ 5.0f };

	// Deadzone for the analog sticks.
	float m_analogStickDeadzone{ 15.0f };

	// Index of the controller the object refers to.
	int m_gamepadIndex;

	// The current state of all buttons.
	GamepadState m_currentState;

	// The previous state of all buttons.
	// Can be used with the current state to check for button presses (just pressed).
	GamepadState m_previousState;

	// The type of the controller the object refers to
	ControllerType m_controllerType;

};

#endif // !GAMEPAD_H
