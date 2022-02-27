
#include "classes/Game.hpp"

#include <fstream>
#include <sstream>

#define LOG(x) std::cout << x << std::endl

//===========================
// Initialize static variable
//===========================
#pragma region STATIC VARIABLES

sf::RenderWindow *InitUI::theWindow = new sf::RenderWindow;
sf::RectangleShape *InitUI::theGameScreen = new sf::RectangleShape;
sf::Text InitUI::m_gameTitle{};
sf::Text InitUI::m_soloGame{};
sf::Text InitUI::m_multiGame{};
sf::Text InitUI::m_exit{};
sf::Text InitUI::m_menuHandler{};
UserChoice InitUI::m_choice = UserChoice::NONE;

#pragma endregion

void InitUI::showUI()
{	
	//============================================================
	// Create Window with the same pixel depth as the desktop mode
	//============================================================
	sf::VideoMode desktopMode{ sf::VideoMode::getDesktopMode() };
	theWindow->create(desktopMode, WIN_TITLE, sf::Style::Default);
	theWindow->setVerticalSyncEnabled(true);

	setUI();

	//================================
	// Initialize menuHandler position
	//================================
	m_menuHandler.setPosition(sf::Vector2f(30, 285));

	//=====================================
	// Game Instance to handle game running
	//=====================================
	Game* game = new Game();
	while (theWindow->isOpen())
	{

		if (m_choice == UserChoice::NONE)
		{
			m_choice = handleMenu();
		}
		else{}

		sf::Event event{};
		game->handleInputs(theWindow, m_choice, event);

		theWindow->clear(sf::Color::Black);

		drawUI();		
		initGameScreen();
		theWindow->draw(*theGameScreen);

		if (m_choice == UserChoice::SOLO || m_choice == UserChoice::MULTI)
		{
			game->run(theWindow, m_choice);
		}
		else{}

		//===============================
		// Display all elements on screen
		//===============================
		theWindow->display();

		game->checkCollision(m_choice);
	}

	delete game;
}

void InitUI::initGameScreen()
{
	theGameScreen->setPosition(sf::Vector2f(SCREEN_POS.first, SCREEN_POS.second));
	theGameScreen->setSize(sf::Vector2f(SCREEN_SIZE.first, SCREEN_SIZE.second));
	theGameScreen->setFillColor(sf::Color::Transparent);
	theGameScreen->setOutlineColor(sf::Color::White);
	theGameScreen->setOutlineThickness(1.5);
}

std::string InitUI::getGameTitle() noexcept
{
	std::string path = "resources/gameTitle.res";
	std::ifstream inputFile{ path };

	std::string gameTitle{};
	if (inputFile.is_open())
	{
		std::string line{};
		std::ostringstream oss{};
		while (std::getline(inputFile, line))
		{
			oss << line << std::endl;
		}

		gameTitle = oss.str();
	}
	else
	{
		LOG("Unable to open " + path);
	}

	return gameTitle;
}

void InitUI::setUI() noexcept
{
	std::string const gameTitle{ getGameTitle() };

	//====================
	// Set text properties
	//====================
	sf::Font font{};
	loadFont(font);
	TextProperties properties(font, gameTitle, 16, sf::Color::White, sf::Text::Regular);

	sf::Text txt{};
	setText(txt, properties);
	m_gameTitle = txt;

	properties.s_string = "Solo";
	properties.s_caracSize = 60;

	setText(txt, properties);
	m_soloGame = txt;

	properties.s_string = "Multi";

	setText(txt, properties);
	m_multiGame = txt;

	properties.s_string = "Exit";

	setText(txt, properties);
	m_exit = txt;

	properties.s_caracSize = 100;
	properties.s_string = "*";
	properties.s_color = sf::Color::Green;

	setText(txt, properties);
	m_menuHandler = txt;
}

void InitUI::drawUI()
{
	sf::Font font{};
	loadFont(font);
	m_gameTitle.setFont(font);
	theWindow->draw(m_gameTitle);

	m_soloGame.setPosition(sf::Vector2f(100, 300));
	m_soloGame.setFont(font);
	theWindow->draw(m_soloGame);

	m_multiGame.setPosition(sf::Vector2f(100, 500));
	m_multiGame.setFont(font);
	theWindow->draw(m_multiGame);

	m_exit.setPosition(sf::Vector2f(100, 700));
	m_exit.setFont(font);
	theWindow->draw(m_exit);

	m_menuHandler.setFont(font);
	theWindow->draw(m_menuHandler);
}

UserChoice InitUI::handleMenu() noexcept
{
	sf::Event event{};
	Input input{};
	while (theWindow->pollEvent(event))
	{
		// Handle inputs and events
		input.inputHandler(event, theWindow);
	}

	buttonHandler(input);

	//===========================
	//Current user choice handler 
	//===========================
	// Get the difference between m_menuHandler position and m_soloGame position (-(300 - 285) in order to begin to zero
	// - 300 : initial position of m_soloGame
	// - 285 : initial position of m_menuHandler
	UserChoice choice = UserChoice::NONE;
	unsigned int currentChoice = m_menuHandler.getPosition().y - (m_soloGame.getPosition().y - (300 - 285));
	switch (currentChoice)
	{
	case 0 : // Solo
		if (input.getButton().enter)
		{
			choice = UserChoice::SOLO;
		}
		else{}

		break;
	case 200: // Multi (initial position : 500)
		if (input.getButton().enter)
		{
			choice = UserChoice::MULTI;
		}
		else{}

		break;
	case 400: // Exit (initial position : 700
		if (input.getButton().enter)
		{
			choice = UserChoice::EXIT;
			theWindow->close();
		}
		else {}

		break;
	default:
		break;
	}

	return choice;
}

void InitUI::buttonHandler(Input const& input) noexcept
{
	unsigned int position = m_menuHandler.getPosition().y;
	if (input.getButton().up)
	{
		if (position != 285)
		{
			m_menuHandler.move(sf::Vector2f(0, -200));
		}
		else
		{
			m_menuHandler.setPosition(sf::Vector2f(30, 685));
		}
	}
	else if (input.getButton().down)
	{
		if (position != 685)
		{
			m_menuHandler.move(sf::Vector2f(0, 200));
		}
		else
		{
			m_menuHandler.setPosition(sf::Vector2f(30, 285));
		}
	}
	else if (input.getButton().escape)
	{
		theWindow->close();
	}

	// Update color
	switch (position)
	{
	case 285:
		m_soloGame.setFillColor(sf::Color::Green);
		m_multiGame.setFillColor(sf::Color::White);
		m_exit.setFillColor(sf::Color::White);
		break;
	case 485:
		m_soloGame.setFillColor(sf::Color::White);
		m_multiGame.setFillColor(sf::Color::Green);
		m_exit.setFillColor(sf::Color::White);
		break;
	case 685:
		m_soloGame.setFillColor(sf::Color::White);
		m_multiGame.setFillColor(sf::Color::White);
		m_exit.setFillColor(sf::Color::Green);
		break;
	default:
		break;
	}
}

void InitUI::freeMemory() noexcept
{
	//=======================
	// Free pointer to window
	//=======================
	if (theWindow != nullptr)
	{
		delete theWindow;
	}
	else {}

	if (theGameScreen != nullptr)
	{
		delete theGameScreen;
	}
	else {}
}
