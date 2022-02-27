
#include "classes/InputHandler.hpp"

Input::Input()
{
    m_button.enter = false;
    m_button.escape = false;
    m_button.down = false;
    m_button.up = false;
    m_button.downP2 = false;
    m_button.upP2 = false;
}

Input::Button Input::getButton() const noexcept
{
    return m_button;
}

// Handle events and inputs
void Input::inputHandler(sf::Event const& event, sf::RenderWindow *window)
{
    // CLOSE WINDOW WHEN CLICK ON CROSS
    if (event.type == sf::Event::Closed)
    {
        // CLOSE WINDOW
        window->close();
    }
    else {}

    // HANDLE INPUTS (Keyboard / Mouse) 
    // Detection if pressed
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code) // Code of the key pressed by user
        {
        case sf::Keyboard::Enter:
            m_button.enter = true;
            break;
        case sf::Keyboard::Escape:
            m_button.escape = true;
            break;
        case sf::Keyboard::Down:
            m_button.down = true;
            break;
        case sf::Keyboard::Up:
            m_button.up = true;
            break;
        case sf::Keyboard::S:
            m_button.downP2 = true;
            break;
        case sf::Keyboard::Z:
            m_button.upP2 = true;
            break;
        default:
            break;
        }
    }
    else {}

    // Detection if released
    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code) // Code of the key pressed by user
        {
        case sf::Keyboard::Enter:
            m_button.enter = false;
            break;
        case sf::Keyboard::Escape:
            m_button.escape = false;
            break;
        case sf::Keyboard::Down:
            m_button.down = false;
            break;
        case sf::Keyboard::Up:
            m_button.up = false;
        case sf::Keyboard::S:
            m_button.downP2 = false;
            break;
        case sf::Keyboard::Z:
            m_button.upP2 = false;
            break;
        default:
            break;
        }
    }
    else {}
}