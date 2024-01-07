#include "../Header/BitMap.h"
/**
 * @file BitMap.cpp
 * @brief Implementacja klasy BitMap.
 */


/**
 * @brief Ustawia numer aktualnego etapu gry.
 *
 * @param stage Numer etapu gry.
 */
void BitMap::setStage(int stage) {
    this->stage = stage;
}

/**
 * @brief Pobiera numer aktualnego etapu gry.
 *
 * @return Numer etapu gry.
 */
int BitMap::getStage() {
    return stage;
}

/**
 * @brief Konfiguruje bitmapę na podstawie aktualnego etapu gry.
 *
 * Metoda ta ustawia odpowiednią teksturę na podstawie numeru etapu gry.
 *
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param view Referencja do obiektu sf::View.
 */
void BitMap::configureBitMap(sf::RenderWindow &window, View &view){

    if(stage == 0)
    {
        sf::Sprite sprite;
        sprite.setTexture(menu);
        window.draw(sprite);
    }
    else if(stage == 1)
    {
        sf::Sprite sprite;
        sprite.setTexture(intrukcja);
        window.draw(sprite);

    }
    else if(stage == 2)
    {
        sf::Sprite sprite;
        sprite.setTexture(wybor);
        window.draw(sprite);

    }
    else if(stage == 3)
    {
       sf::Sprite sprite;
        sprite.setTexture(map);
        window.setView(view);
        window.draw(sprite);

    }
    else if(stage == 4)
    {
        sf::Sprite sprite;
        sprite.setTexture(ded);
        window.draw(sprite);
    }
}