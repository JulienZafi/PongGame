#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <random>

#include "../structures/TextProperties.hpp"

#define LOG(x) std::cout << x << std::endl

/**
* @brief Load type face from file
* @param[in] font Font to get from file
*/
void loadFont(sf::Font &font) noexcept;

/**
* @brief Set Text instance using properties defined by user
* @param[in] text Text to set
* @param[in] properties Structure that contains all necessary info to set text instance
*/
void setText(sf::Text &text, TextProperties const &properties) noexcept;

/**
* @brief Choose a random number
* @param[in] num Max number allowed
* @return a random number between 0 and num
*/
unsigned int randNumber(unsigned int num);

#endif // !FUNCTIONS_HPP

