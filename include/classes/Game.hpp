#ifndef GAME_HPP
#define GAME_HPP

#pragma region CONSTANTS

// Ball dimension & position
#define BALL_RADIUS 30
#define BALL_POS std::make_pair(1237.5, 542.5)

//Rackets dimension & offset
#define RACKET_SIZE std::make_pair(40, 250)
#define RACKET_POS std::make_pair(550, 0)

// Object speed
#define BALL_SPEED 7
#define PLAYER_SPEED 15

#pragma endregion

#include "Ball.hpp"
#include "Player.hpp"

#include "../initialization/InitUI.hpp"

/**
* @brief Handles game actions
*/
class Game
{
public:
	/**
	* @brief Default constructor
	*/
	Game();

	/**
	* @brief Default destructor
	*/
	~Game();

	/**
	* @brief Display Circle Shape
	* @param[in] window Displaying window
	*/
	void display(sf::RenderWindow *window) noexcept;

	/**
	* @brief Running game 
	*/
	void run(sf::RenderWindow *window, UserChoice choice);

	/**
	* @brief Handles rackets motion
	*/
	void handleInputs(sf::RenderWindow *window, UserChoice choice, sf::Event &event) noexcept;

	/**
	* @brief Move player according to user choice :
	* - If solo mode : Up-Down keys to move player 1
	* - If multi mode : Z-S to move player 1 and Up-Down to move player 2
	* @param[in] choice User choice ( solo or multi)
	* @param[in] input Input Keys
	*/
	void movePlayer(UserChoice const choice, Input const input, int const disp) noexcept;

	/**
	* @brief Check ball collision with players and game screen limits
	* @param[in] choice User choice (solo or multi)
	*/
	void checkCollision(UserChoice const choice) noexcept;

private:
	Player *m_firstPlayer;
	Player *m_secondPlayer;
	Ball *m_ball;
	int m_secPlayerDir;
};

#endif // GAME_HPP