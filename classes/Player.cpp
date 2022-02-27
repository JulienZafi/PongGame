#include "Player.hpp"

Player::Player()
{
	m_player = new sf::RectangleShape;
	m_position = sf::Vector2f(0, 0);
	m_size = sf::Vector2f(0, 0);
	m_hitBox = sf::FloatRect{};
	m_score = 0;
}

Player::Player(sf::Vector2f const& position, sf::Vector2f const& size) : m_position(position), m_size(size)
{
	m_player = new sf::RectangleShape;
	m_player->setPosition(position);
	m_player->setSize(size);
	m_player->setFillColor(sf::Color::White);

	m_hitBox = sf::FloatRect{};
	m_hitBox = m_player->getGlobalBounds();
	m_score = 0;
}

Player::~Player()
{
	if (m_player != nullptr)
	{
		delete m_player;
	}
	else{}
}

void Player::move(int const& x, int const& y) noexcept
{
	this->setPosition(sf::Vector2f(m_player->getPosition().x, m_player->getPosition().y + y));
}

sf::FloatRect Player::getPlayerHitbox() const noexcept
{
	return m_hitBox;
}

void Player::setPlayerScore(unsigned int const& score) noexcept
{
	m_score = score;
}

unsigned int Player::getPlayerScore() const noexcept
{
	return m_score;
}

void Player::display(sf::RenderWindow *window) noexcept
{
	window->draw(*m_player);
}

sf::Vector2f Player::getPosition() const noexcept
{
	return m_position;
}

void Player::setPosition(sf::Vector2f newPos) noexcept
{
	m_player->setPosition(newPos);
	m_position = newPos;
}