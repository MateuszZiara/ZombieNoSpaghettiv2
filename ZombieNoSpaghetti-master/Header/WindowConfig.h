#ifndef ZOMBIENOSPAGHETTI_WINDOWCONFIG_H
#define ZOMBIENOSPAGHETTI_WINDOWCONFIG_H
#include <SFML/Graphics.hpp>

/**
 * @file WindowConfig.h
 * @brief Deklaracja klasy WindowConfig oraz związanej z nią funkcji.
 */

/**
 * @class WindowConfig
 * @brief Klasa do konfiguracji okna gry.
 */
class WindowConfig
{
public:
    /**
     * @brief Ustawia domyślne parametry okna.
     *
     * @param window Referencja do obiektu sf::RenderWindow.
     */
    static void setDefault(sf::RenderWindow &window);
};
#endif //ZOMBIENOSPAGHETTI_WINDOWCONFIG_H
