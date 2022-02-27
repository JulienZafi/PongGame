#include "../classes/Game.hpp"

#include <iostream>
void Game::run(sf::RenderWindow *theWindow, UserChoice choice)
{
	this->display(theWindow);

	double speed{ BALL_SPEED / sqrt(2) };
	this->m_ball->move(speed, speed);

	// Handle AI if user choice is solo mode
	if (choice == UserChoice::SOLO)
	{
		// Player moves only if future position is on screen limits
		m_secondPlayer->move(0, m_secPlayerDir * PLAYER_SPEED/5);
	}
	else{}
}

int main()
{
	//==========================
	// Initialize Selection Menu
	//==========================
	InitUI::showUI();

	return 0;
}