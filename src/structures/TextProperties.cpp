
#include "structures/TextProperties.hpp"

TextProperties::TextProperties(sf::Font const &font, sf::String const &string, uint const &caracSize, sf::Color const &color, sf::Uint32 const &style) noexcept
{
	s_font = font;
	s_string = string;
	s_caracSize = caracSize;
	s_color = color;
	s_style = style;
}
