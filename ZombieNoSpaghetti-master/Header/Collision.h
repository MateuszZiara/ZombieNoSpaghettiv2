#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @file Collision.h
 * @brief Deklaracja pliku nagłówkowego Collision.h oraz związanych z nim funkcji.
 */

/**
 * @tparam Collision
 * @brief Szablon dla kolizji
 *
 * @tparam T Typ obiektu, który może wziąć udział w kolizji.
 * @param obj Obiekt, który może wziąć udział w kolizji.
 * @param window Okno, w którym dochodzi do kolizji.
 * @return Zwraca bool czy obiekt doprowadził do kolizji z granicami.
 */
template<typename T> bool collisionWithBorderRect(T obj, sf::RenderWindow &window) {
    sf::FloatRect objectBounds = obj.getGlobalBounds(); ///< Pobiera globalne granice dla obiektu

    if (objectBounds.left < 0 || objectBounds.top < 0 ||
        objectBounds.left + objectBounds.width > window.getSize().x ||
        objectBounds.top + objectBounds.height > window.getSize().y) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Funkcja sprawdzająca, czy RectangleShape dotyka obszaru na planszy.
 *
 * @param rect Prostokąt, którego dotykanie jest sprawdzane.
 * @param points Wektor punktów reprezentujących obszar na planszy.
 * @param window Okno, w którym zachodzi sprawdzanie.
 * @return Zwraca wektor (sf::Vector2f), który reprezentuje, czy prostokąt dotyka obszaru, oraz w którym miejscu.
 */
sf::Vector2f isRectangleTouchingField(sf::RectangleShape& rect, std::vector<sf::Vector2f> points, sf::RenderWindow& window);


#ifndef ZOMBIENOSPAGHETTI_MOVE_H
#define ZOMBIENOSPAGHETTI_MOVE_H

#endif //ZOMBIENOSPAGHETTI_MOVE_H
