#include "../Header/Animations.h"
/**
 * @file Animations.cpp
 * @brief Implementacja klasy Animations.
 */


/**
 * @brief Uruchamia określoną animację na RectangleShape.
 *
 * Funkcja ustawia teksturę na RectangleShape i przemieszcza prostokąt wzdłuż arkusza sprite'ów
 * w celu wyświetlenia określonej animacji. Funkcja pozwala na ustawienie odstępu czasu pomiędzy wyświetleniem kolejnych klatek animacji.
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
void Animation::run_animation(sf::RectangleShape &rectangleShape, int animationNumber, int x, int y, int width,
                              int height, sf::Texture &texture, int delay, sf::RenderWindow &window) {
    rectangleShape.setTexture(&texture);
    rectangleShape.setTextureRect(IntRect(current_animation*x,y,width,height));
    if(timer >= delay)
    {

        current_animation++;
        if(current_animation > animationNumber)
            current_animation = 0;

        rectangleShape.setTextureRect(IntRect(current_animation*x,y,width,height));
        timer = 0;
    }
    else
        timer++;

    window.draw(rectangleShape);
}