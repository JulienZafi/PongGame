#ifndef INIT_UI_HPP
#define INIT_UI_HPP

#pragma region CONSTANTS

#define WIN_TITLE "PONG GAME"
#define SCREEN_POS std::make_pair(600, 50)
#define SCREEN_SIZE std::make_pair(1275, 985)

#pragma endregion

#include <cstdint>

#include "../classes/InputHandler.hpp"

/**
* @brief Class that handles selection menu
*/
class InitUI
{
public:
	/**
	* @brief The SFML Window is set as a static variable
	*/
	static sf::RenderWindow *theWindow;
	static sf::RectangleShape *theGameScreen;

	/**
	* @brief Constructor is not necessary, only class methods and members are used
	*/
	InitUI() = delete;

	/**
	* @brief Show User Interface
	*		 Possibles choices :
	*		 - Play against the AI
	*		 - Play against another player
	*/
	static void showUI();

	/**
	* @brief Get user action 
	*/
	static void initGameScreen();

	/**
	* @brief Get Game title "PONG" from file "gameTitle.res"
	* @return Game title
	*/
	static std::string getGameTitle() noexcept;

	/**
	* @brief set game UI
	*/
	static void setUI() noexcept;

	/**
	* @brief draw game UI
	*/
	static void drawUI();

	/**
	* @brief handle menu
	* @return If user choose SOLO, MULTI or EXIT (0, 1, 2)
	*/
	static UserChoice handleMenu() noexcept;

	/**
	* @brief Set button actions
	* @param[in] input Input instance to handle button actions
	*/
	static void buttonHandler(Input const &input) noexcept;

	/**
	* @brief Deletes created pointers
	*/
	static void freeMemory() noexcept;

private:
	static sf::Text m_gameTitle;
	static sf::Text m_soloGame;
	static sf::Text m_multiGame;
	static sf::Text m_exit;
	static sf::Text m_menuHandler;
	static UserChoice m_choice;
};

#endif // !INIT_UI_HPP

