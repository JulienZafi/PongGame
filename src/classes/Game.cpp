
#include "classes/Game.hpp"

Game::Game()
{
	m_ball = new Ball(sf::Vector2f(BALL_POS.first, BALL_POS.second), BALL_RADIUS);

	unsigned int offset = RACKET_POS.first;
	unsigned int xPos = BALL_POS.first - offset;
	unsigned int yPos = BALL_POS.second - RACKET_SIZE.second / 2;
	m_firstPlayer = new Player(sf::Vector2f(xPos, yPos), sf::Vector2f(RACKET_SIZE.first, RACKET_SIZE.second));

	xPos = BALL_POS.first + offset;
	m_secondPlayer = new Player(sf::Vector2f(xPos, yPos), sf::Vector2f(RACKET_SIZE.first, RACKET_SIZE.second));
	m_secPlayerDir = 1;
}

Game::~Game()
{
	if (m_firstPlayer != nullptr)
	{
		m_firstPlayer->~Player();
		delete m_firstPlayer;
	}
	else{}
	if (m_secondPlayer != nullptr)
	{
		m_secondPlayer->~Player();
		delete m_secondPlayer;
	}
	else {}

	if (m_ball != nullptr)
	{
		m_ball->~Ball();
		delete m_ball;
	}
	else {}
}

void Game::display(sf::RenderWindow *window) noexcept
{
	m_ball->display(window);
	m_firstPlayer->display(window);
	m_secondPlayer->display(window);
}

void Game::handleInputs(sf::RenderWindow *window, UserChoice choice, sf::Event &event) noexcept
{
	Input input{};
	while (window->pollEvent(event))
	{
		// Handle inputs and events
		input.inputHandler(event, window);

		if (input.getButton().up)
		{
			movePlayer(choice, input, -PLAYER_SPEED);
		}
		else if (input.getButton().down)
		{
			movePlayer(choice, input, PLAYER_SPEED);
		}
		else if (input.getButton().upP2)
		{
			movePlayer(choice, input, -PLAYER_SPEED);
		}
		else if (input.getButton().downP2)
		{
			movePlayer(choice, input, PLAYER_SPEED);
		}
		else if (input.getButton().escape)
		{
			window->close();
		}
	}
}

void Game::movePlayer(UserChoice const choice, Input const input, int const disp) noexcept
{
	Player* player = nullptr;

	switch (choice)
	{
	case UserChoice::SOLO:
		if (input.getButton().down || input.getButton().up)
		{
			player = m_firstPlayer;
		}
		else{}
		break;
	case UserChoice::MULTI:
		if (input.getButton().down || input.getButton().up)
		{
			player = m_secondPlayer;
		}
		else if (input.getButton().downP2 || input.getButton().upP2)
		{
			player = m_firstPlayer;
		}
		break;
	default:
		break;
	}

	if (player != nullptr)
	{
		// Player moves only if future position is on screen limits
		double futurePos = player->getPosition().y + disp;
		if ( futurePos > SCREEN_POS.second && futurePos+ RACKET_SIZE.second < SCREEN_POS.second + SCREEN_SIZE.second)
		{
			player->move(0, disp);

		}
		else{}
	}
	else{}
}

void Game::checkCollision(UserChoice const choice) noexcept
{
	sf::Vector2f futurePos{ m_ball->getPosition()};
	double speed{ BALL_SPEED / sqrt(2) };
	sf::Vector2f dir{ m_ball->getDirection() };
	futurePos += sf::Vector2f(speed * dir.x, speed * dir.y);

	// Check collision with upper and lower screen limits
	if (futurePos.y < SCREEN_POS.second || futurePos.y + 2 * BALL_RADIUS > SCREEN_POS.second + SCREEN_SIZE.second)
	{
		m_ball->changeDirection(sf::Vector2f(1, -1));
	}
	else {} 

	// Check collision with first player
	if (futurePos.x <= m_firstPlayer->getPosition().x + RACKET_SIZE.first
			&& futurePos.y + 2 * BALL_RADIUS >= m_firstPlayer->getPosition().y
				&& futurePos.y <= m_firstPlayer->getPosition().y + RACKET_SIZE.second)
	{
		if (futurePos.x <= m_firstPlayer->getPosition().x)
		{
			m_ball->changeDirection(sf::Vector2f(1, -1));
		}
		else
		{
			m_ball->changeDirection(sf::Vector2f(-1, 1));
		}

	}
	else {}

	// Check collision with second player
	if (futurePos.x + 2 * BALL_RADIUS > m_secondPlayer->getPosition().x
		&& (futurePos.y + 2 * BALL_RADIUS > m_secondPlayer->getPosition().y
			&& futurePos.y < m_secondPlayer->getPosition().y + RACKET_SIZE.second))
	{
		if (futurePos.x + 2 * BALL_RADIUS > m_secondPlayer->getPosition().x + RACKET_SIZE.first)
		{
			m_ball->changeDirection(sf::Vector2f(1, -1));
		}
		else
		{
			m_ball->changeDirection(sf::Vector2f(-1, 1));
		}
	}
	else {}

	// Reset ball position if one player loses
	if ((futurePos.x < m_firstPlayer->getPosition().x - 2 * BALL_RADIUS 
		|| futurePos.x > m_secondPlayer->getPosition().x + RACKET_SIZE.first))
	{
		// Timer / Clock to measure elapsed time
		sf::Clock timer{};
		sf::Vector2f lastDir{ m_ball->getDirection() };

		//while (timer.getElapsedTime().asMilliseconds() < 1)
		//{
			// Hide ball from screen
			//m_ball->setPosition(sf::Vector2f(-2 * BALL_RADIUS, BALL_POS.second));
		//}

		//if (timer.getElapsedTime().asMilliseconds() > 1)
		//{
			m_ball->setPosition(sf::Vector2f(BALL_POS.first, BALL_POS.second));
			timer.restart();
		//}
		//else{}
	}
	else{}

	// Reset second player direction if solo mode
	if (choice == UserChoice::SOLO)
	{
		double ballCenter{ m_ball->getPosition().y + BALL_RADIUS };
		double racketCenter{ m_secondPlayer->getPosition().y + RACKET_SIZE.second / 2 };
		double posToCheck{ racketCenter + m_secPlayerDir * PLAYER_SPEED };
		
		if (posToCheck < ballCenter - RACKET_SIZE.second / 2
			|| posToCheck - RACKET_SIZE.second / 2 < SCREEN_POS.second)
		{
			m_secPlayerDir = 1;

			// This is done only if the moves on second player direction
			if (m_ball->getDirection().x > 0 && m_ball->getPosition().x < SCREEN_POS.first + SCREEN_SIZE.first / 2)
			{
				m_secPlayerDir *= 2;
			}
			else{}
		}
		else if (posToCheck + RACKET_SIZE.second / 2 > SCREEN_POS.second + SCREEN_SIZE.second
			|| posToCheck > ballCenter + RACKET_SIZE.second / 2)
		{
			m_secPlayerDir = -1;

			// This is done only if the moves on second player direction
			if (m_ball->getDirection().x < 0 && m_ball->getPosition().x < SCREEN_POS.first + SCREEN_SIZE.first / 2)
			{
				m_secPlayerDir *= 2;
			}
			else{}
		}
		else {}
	}
	else{}
}