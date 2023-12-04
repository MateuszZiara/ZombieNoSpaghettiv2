#ifndef ZOMBIENOSPAGHETTI_BITMAP_H
#define ZOMBIENOSPAGHETTI_BITMAP_H
#include <SFML/Graphics.hpp>
#include "Animations.h"
#include "../Header/Player.h"

/**
 * @file Bitmap.h
 * @brief Deklaracja klasy nagłówkowej BitMap.h określająca funkcje do reprezentacja bitmap w grze.
 */

/**
 * @class BitMap
 * @brief Klasa reprezentująca bitmapę w grze.
 *
 * Klasa ta odpowiada za zarządzanie różnymi etapami gry i ładowanie odpowiadających im tekstur.
 */
class BitMap
{
    int stage; ///< Numer aktualnego etapu gry.
    Texture map; ///< Tekstura mapy gry.
    Texture menu; ///< Tekstura menu.
    Texture intrukcja; ///< Tekstura instrukcji.
    Texture wybor; ///< Tekstura ekranu wyboru.
    Texture ded; ///< Tekstura ded wyboru.
public:
    /**
     * @brief Ustawia numer aktualnego etapu gry.
     *
     * @param stage Numer etapu gry.
     */
    void setStage(int stage);

    /**
     * @brief Pobiera numer aktualnego etapu gry.
     *
     * @return Numer etapu gry.
     */
    int getStage();
    /**
     * @brief Konfiguruje bitmapę na podstawie aktualnego etapu gry.
     *
     * Metoda ta ustawia odpowiednią teksturę na podstawie numeru etapu gry.
     *
     * @param window Referencja do obiektu sf::RenderWindow.
     * @param view Referencja do obiektu sf::View.
     */
    void configureBitMap(sf::RenderWindow &window, View &view);

    /**
     * @brief Konstruktor klasy BitMap.
     *
     * Wczytuje tekstury dla różnych etapów gry.
     */
    BitMap()
    {
        map.loadFromFile("../Textures/mapkadocelowa.png");
        menu.loadFromFile("../Textures/menu.png");
        intrukcja.loadFromFile("../Textures/instrukcja_gotowa.png");
        wybor.loadFromFile("../Textures/wybor.png");
        ded.loadFromFile("../Textures/ded.png");
    }
};
#endif //ZOMBIENOSPAGHETTI_BITMAP_H
