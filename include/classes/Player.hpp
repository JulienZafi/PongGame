#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

/**
* @brief Creates a player instance
*/
class Player
{
public:
	/**
	* @brief Default constructor
	*/
	Player();

	/**
	* @brief Creates an Player instance
	* @param[in] position Initial position
	* @param[in] size Rectangle size
	*/
	Player(sf::Vector2f const &position, sf::Vector2f const &size);

	/**
	* @brief Default destructor
	*/
	~Player();

	/**
	* @brief Moves Player by x and y distances
	* @param[in] x Move on x direction
	* @param[in] y Move on y direction
	*/
	void move(int const &x, int const &y) noexcept;

	/**
	* @brief Get player rectangle boundaries to treat collisions
	*/
	sf::FloatRect getPlayerHitbox() const noexcept;

	/**
	* @brief Set Score to show on screen
	* @param[in] score Current score
	*/
	void setPlayerScore(unsigned int const &score) noexcept;

	/**
	* @brief Get player score
	*/
	unsigned int getPlayerScore() const noexcept;

	/**
	* @brief Display Shape
	* @param[in] window Displaying window
	*/
	void display(sf::RenderWindow *window) noexcept;

	/**
	* @brief Get player x,y position
	*/
	sf::Vector2f getPosition() const noexcept;

	/**
	* @brief Set player x,y position
	* @param[in] (x,y) new position
	*/
	void setPosition(sf::Vector2f newPos) noexcept;

private:
	sf::RectangleShape *m_player;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::FloatRect m_hitBox;
	unsigned int m_score;
};

#endif // PLAYER_HPP

