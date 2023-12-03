#include <SFML/Graphics.hpp>
#include "../Header/WindowConfig.h"

/**
     * @brief Ustawia domyślne parametry okna.
     *
     * @param window Referencja do obiektu sf::RenderWindow.
     */
void WindowConfig::setDefault(sf::RenderWindow &window)
{
    window.setFramerateLimit(60);

};