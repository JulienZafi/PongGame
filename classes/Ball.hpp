#ifndef BALL_HPP
#define BALL_HPP

#include "../functions/functions.hpp"

/**
* @brief Creates a ball instance
*/
class Ball
{
public:
	enum Init { UPLEFT = 0, UPRIGHT, DOWNLEFT, DOWNRIGHT };

	/**
	* @brief Default constructor
	*/
	Ball();

	/**
	* @brief Creates an Player instance
	* @param[in] position Initial position
	* @param[in] size Rectangle size
	*/
	Ball(sf::Vector2f const &position, double const &radius);

	/**
	* @brief Default destructor
	*/
	~Ball();

	/**
	* @brief Moves Player by x and y distances
	* @param[in] x Move on x direction
	* @param[in] y Move on y direction
	*/
	void move(int const &x, int const &y) noexcept;

	/**
	* @brief Get player rectangle boundaries to treat collisions
	*/
	sf::FloatRect getBallHitbox() const noexcept;

	/**
	* @brief Display Circle Shape
	* @param[in] window Displaying window
	*/
	void display(sf::RenderWindow *window) noexcept;

	/**
	* @brief Get ball x,y position
	*/
	sf::Vector2f getPosition() const noexcept;

	/**
	* @brief Set ball x,y position
	* @param[in] (x,y) new position
	*/
	void setPosition(sf::Vector2f newPos) noexcept;

	/**
	* @brief Change ball direction
	* @param[in] new direction
	*/
	void changeDirection(sf::Vector2f newDir) noexcept;

	/**
	* @brief Get ball direction
	*/
	sf::Vector2f getDirection() const noexcept;

private:
	sf::CircleShape *m_circle;
	sf::Vector2f m_direction;
	sf::Vector2f m_position;
	double m_radius;
	sf::FloatRect m_hitBox;
};
#endif // !BALL_HPP
