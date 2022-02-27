#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <SFML/Graphics.hpp>

enum UserChoice { SOLO = 0, MULTI, EXIT, NONE };

/**
* @brief Class that handles user inputs
*/
class Input
{
	struct Button { bool up, down, upP2, downP2, enter, escape; };

public:
	/**
	* @brief Default constructor
	*/
	Input();

	/**
	* @brief Handles events and user inputs
	* @param[in] event Current event typee
	* @param[in] window Current window
	*/
	void inputHandler(sf::Event const& event, sf::RenderWindow *window);

	/**
	* @brief Get current button
	*/
	Input::Button getButton() const noexcept;

private:
	Button m_button;
};

#endif // !INPUT_HANDLER_HPP

