//
// Created by coons on 14.11.2023.
//
#include <SFML/Graphics.hpp>
#ifndef ZOMBIENOSPAGHETTI_ARROW_H
#define ZOMBIENOSPAGHETTI_ARROW_H
/**
 * @file Arrow.h
 * @brief Deklaracja klasy Arrow - reprezentacja strzały w grze.
 */

/**
 * @class Arrow
 * @brief Deklaracja klasy reprezentującej strzałę w grze.
 *
 * Klasa ta odpowiada za utworzenie obiektu strzały z określonym kierunkiem, pozycją i teksturą.
 * Strzała może być skierowana w jednym z czterech kierunków: góra, dół, lewo, prawo.
 */
class Arrow {
public:
    /**
     * @brief Konstruktor klasy Arrow.
     *
     * Tworzy obiekt strzały na podstawie podanego kierunku, pozycji i tekstury.
     * W zależności od kierunku, ustawia odpowiedni fragment tekstury oraz rozmiar strzały.
     *
     * @param direction Kierunek, w którym ma być skierowana strzała (0-prawo, 1-lewo, 2-góra, 3-dół).
     * @param position Pozycja początkowa strzały (sf::Vector2f).
     * @param texture Referencja do tekstury strzały.
     */
    Arrow(int direction, sf::Vector2f position, sf::Texture &texture)
    {
        arrowShape.setTexture(&texture);
        arrowShape.setPosition(position.x,position.y);
        if(direction == 0) {
            arrowShape.setTextureRect(sf::IntRect(0, 1056, 46, 9));
            arrowShape.setSize(sf::Vector2f(35, 7));
        }
        else if (direction == 1) {
            arrowShape.setTextureRect(sf::IntRect(46, 1056, 46, 9));
            arrowShape.setSize(sf::Vector2f(35, 7));
        }
        else if (direction == 2) {
            arrowShape.setTextureRect(sf::IntRect(11, 1066, 8, 46));
            arrowShape.setSize(sf::Vector2f (7,35));
        }
        else {
            arrowShape.setTextureRect(sf::IntRect(0, 1066, 8, 46));
            arrowShape.setSize(sf::Vector2f (7,35));
        }
        this -> direction = direction;

    }
    sf::RectangleShape arrowShape; ///< Kształt strzały (RectangleShape).
    sf::Texture texture; ///< Tekstura strzały.
    int direction; ///< Kierunek strzały.
    /**
     * @brief Metoda do poruszania strzałą.
     *
     * Metoda ta powoduje ruch strzały, aktualizując jej pozycję o określoną wartość na podstawie jej kierunku.
     */
    void move();
};


#endif //ZOMBIENOSPAGHETTI_ARROW_H
