#ifndef ZOMBIENOSPAGHETTI_ANIMATIONS_H
#define ZOMBIENOSPAGHETTI_ANIMATIONS_H
#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @file Animations.h
 * @brief Deklaracja klasy Animations i powiązanej z nią funkcji.
 */

using namespace sf;
using namespace std;
/**
 * @class Animation
 * @brief Klasa reprezentująca animacje dla RectangleShape w SFML.
 */
class Animation
{
private:
    int timer; ///< Licznik używany do kontrolowania prędkości animacji.
public:
    Animation()
    {
        timer = 0;
        current_animation = 0;
    }
/**
     * @brief Uruchamia określoną animację dla danego RectangleShape.
     *
     * @param rectangleShape RectangleShape, do którego ma być zastosowana animacja.
     * @param animationNumber Numer animacji do uruchomienia.
     * @param x Współrzędna X sprite'a w teksturze.
     * @param y Współrzędna Y sprite'a w teksturze.
     * @param width Szerokość sprite'a w pikselach.
     * @param height Wysokość sprite'a w pikselach.
     * @param texture Referencja do tekstury zawierającej arkusz sprite'ów.
     * @param delay Opóźnienie między klatkami animacji w milisekundach.
     * @param window Referencja do SFML RenderWindow.
     */

    void run_animation(RectangleShape &rectangleShape, int animationNumber, int x, int y,int width, int height, Texture &texture, int delay, sf::RenderWindow &window);
    int current_animation; ///< Numer klatki bieżącej animacji.

};



#endif //ZOMBIENOSPAGHETTI_ANIMATIONS_H
