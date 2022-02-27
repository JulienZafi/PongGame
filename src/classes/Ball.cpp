
#include "classes/Ball.hpp"

Ball::Ball()
{
	m_circle = new sf::CircleShape;
	m_position = sf::Vector2f();
	m_radius = 0;
	m_hitBox = sf::FloatRect();
	m_direction = sf::Vector2f();
}

Ball::Ball(sf::Vector2f const &position, double const &radius) : m_position(position), m_radius(radius)
{
	m_circle = new sf::CircleShape;
	m_circle->setPosition(position);
	m_circle->setRadius(radius);
	m_circle->setFillColor(sf::Color::White);

	m_hitBox = sf::FloatRect();
	m_hitBox = m_circle->getGlobalBounds();

	unsigned int initialDirection = randNumber(3); // Enum Init from 0 to 3
	switch (initialDirection)
	{
	case Init::UPLEFT:
		m_direction = sf::Vector2f(-1, -1);
		break;
	case Init::UPRIGHT:
		m_direction = sf::Vector2f(1, -1);
		break;
	case Init::DOWNLEFT:
		m_direction = sf::Vector2f(-1, 1);
		break;
	case Init::DOWNRIGHT:
		m_direction = sf::Vector2f(1, 1);
		break;
	default:
		break;
	}
}

Ball::~Ball()
{
	if (m_circle != nullptr)
	{
		delete m_circle;
	}
	else{}
}

void Ball::move(int const &x, int const &y) noexcept
{
	this->setPosition(sf::Vector2f(m_circle->getPosition().x + x * m_direction.x, m_circle->getPosition().y + y * m_direction.y));
}

sf::FloatRect Ball::getBallHitbox() const noexcept
{
	return m_hitBox;
}

void Ball::display(sf::RenderWindow *window) noexcept
{
	window->draw(*m_circle);
}

sf::Vector2f Ball::getPosition() const noexcept
{
	return m_position;
}

void Ball::setPosition(sf::Vector2f newPos) noexcept
{
	m_circle->setPosition(newPos);
	m_position = newPos;
}

void Ball::changeDirection(sf::Vector2f newDir) noexcept
{
	m_direction = sf::Vector2f(m_direction.x * newDir.x, m_direction.y * newDir.y);
}

sf::Vector2f Ball::getDirection() const noexcept
{
	return m_direction;
}