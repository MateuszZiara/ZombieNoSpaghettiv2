#include <SFML/Graphics.hpp>
#include "../Header/WindowConfig.h"
/**
 * @file WindowConfig.cpp
 * @brief Implementacja klasy WindowConfig.
 */

/**
     * @brief Ustawia domyślne parametry okna.
     *
     * @param window Referencja do obiektu sf::RenderWindow.
     */
void WindowConfig::setDefault(sf::RenderWindow &window)
{
    window.setFramerateLimit(60);
};