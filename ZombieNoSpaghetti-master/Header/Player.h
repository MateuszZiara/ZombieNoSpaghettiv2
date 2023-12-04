
#ifndef ZOMBIENOSPAGHETTI_PLAYER_H
#define ZOMBIENOSPAGHETTI_PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animations.h"
#include "Arrow.h"

/**
 * @file Player.h
 * @brief Plik nagłówkowy z deklaracja klasy Player oraz związanych z nią funkcji.
 */

/**
 * @class Player
 * @brief Klasa reprezentująca gracza w grze.
 */
using namespace std;
class Player {
public:

    /**
    * @brief Konstruktor klasy Player.
    */
    Player()
    {
        if(klasa)
            MAXhp = 10;
        else
            MAXhp = 10;
        width = 50.f;
        hpBarMaxWidth = width;
        height = 10.f;
        hp = MAXhp;
    }
    sf::RectangleShape hpBarBack;
    sf::RectangleShape hpBarInside;
    Texture texture;
    sf::RectangleShape playerModel;
    int key;
    bool attacking = false;
    int punkty = 0;

    /**
     * @brief Ustawia klasę gracza na podstawie wyboru.
     *
     * @param choose True - łucznik, False - Berserker.
     */
    void setKlasa(bool choose);

    /**
     * @brief Zwraca model gracza.
     *
     * @return Prostokąt reprezentujący model gracza.
     */
    sf::RectangleShape getPlayerModel();

    /**
   * @brief Przesuwa gracza na podstawie klawiszy wciśniętych przez użytkownika.
   *
   * @param window Referencja do obiektu sf::RenderWindow.
   * @param Animation Referencja do obiektu Animation.
   * @param hold Określa, czy klawisz jest wciśnięty.
   * @param pointsVector Wektor wektorów punktów definiujących obszary na planszy.
   * @param lastKey Ostatni wciśnięty klawisz.
   */
    void move(sf::RenderWindow &window, Animation &Animation, bool hold, std::vector<std::vector<::Vector2f>> pointsVector, int &lastKey);

    /**
    * @brief Inicjalizuje model gracza.
    *
    * @param texture Tekstura do użycia dla modelu gracza.
    */
    void initModel(sf::Texture &texture);

    /**
     * @brief Zwraca wybraną klasę gracza.
     *
     * @return True - łucznik, False - Berserker.
     */
    bool getKlasa();

    /**
     * @brief Obsługuje atak gracza.
     *
     * @param animation Referencja do obiektu Animation.
     * @param attackKey Określa, czy klawisz ataku jest wciśnięty.
     * @param key Klawisz ataku.
     * @param window Referencja do obiektu sf::RenderWindow.
     * @param arrowVector Wektor strzał gracza.
     * @param delaycount Licznik opóźnienia ataku.
     * @param textureArrow Tekstura do użycia dla strzał.
     */
    void attack(Animation &animation, bool &attackKey, int &key, sf::RenderWindow &window, vector<Arrow> &arrowVector, int &delaycount, Texture &textureArrow);
public:
    bool klasa; ///< True - łucznik, False - Berserker
    float MAXhp; ///< Maksymalna ilość punktów życia gracza.
    float width; ///< Szerokość postaci
    float hpBarMaxWidth; ///< Maksymalna szerokość paska zdrowia
    float height; ///< Wysokość postaci
    int hp;


};
#endif //ZOMBIENOSPAGHETTI_PLAYER_H
