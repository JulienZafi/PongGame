#ifndef TEXT_PROPERTIES_HPP 
#define TEXT_PROPERTIES_HPP

#define uint unsigned int

#include <SFML/Graphics.hpp>

/**
* @brief This structure allows to handle more easily the creation of a Text instance
*/
struct TextProperties
{
	TextProperties() = default;
	TextProperties(sf::Font const &font, sf::String const &string, uint const &caracSize, sf::Color const &color, sf::Uint32 const &style) noexcept;

	sf::Font s_font;
	sf::String s_string;
	uint s_caracSize;
	sf::Color s_color;
	sf::Uint32 s_style;
};

#endif // !TEXT_PROPERTIES_HPP 

