#include "functions/functions.hpp"

void loadFont(sf::Font& font) noexcept
{
	std::string path{ "resources/04B_08__.ttf" };
	if (!font.loadFromFile(path))
	{
		std::string message{ "Unable to load text font from " + path };
		LOG(message);
	}
	else{}
}

void setText(sf::Text &text, TextProperties const &properties) noexcept
{
	text.setFont(properties.s_font);
	text.setString(properties.s_string);
	text.setCharacterSize(properties.s_caracSize);
	text.setFillColor(properties.s_color);
	text.setStyle(properties.s_style);
}