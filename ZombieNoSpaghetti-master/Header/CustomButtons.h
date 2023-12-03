#ifndef ZOMBIENOSPAGHETTI_CUSTOMBUTTONS_H
#define ZOMBIENOSPAGHETTI_CUSTOMBUTTONS_H
#include <vector>
#include "Button.h"
#include "BitMap.h"
#include "../Header/Player.h"

/**
 * @file CustomButtons.h
 * @brief Deklaracja funkcji inicjalizujących niestandardowe przyciski.
 */

/**
 * @brief Inicjalizuje przyciski dla standardowych ustawień.
 *
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param bitMap Referencja do obiektu BitMap.
 * @param player Referencja do obiektu Player.
 * @param archerTexture Tekstura dla łucznika.
 * @param berserkTexture Tekstura dla berserka.
 * @return Wektor obiektów Button zainicjalizowanych dla standardowych ustawień.
 */
std::vector<Button> init_buttons(sf::RenderWindow &window, BitMap &bitMap,Player &player, Texture &archerTexture, Texture &berserkTexture);

/**
 * @brief Inicjalizuje przyciski dla stanu najechania kursorem myszy.
 *
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param bitMap Referencja do obiektu BitMap.
 * @param berserkAnimation Referencja do obiektu Animation dla animacji berserka.
 * @param lucznikAnimation Referencja do obiektu Animation dla animacji łucznika.
 * @return Wektor obiektów Button zainicjalizowanych dla stanu najechania myszą.
 */
std::vector<Button> init_buttonsHovered(sf::RenderWindow &window, BitMap &bitMap, Animation &berserkAnimation, Animation &lucznikAnimation);
#endif //ZOMBIENOSPAGHETTI_CUSTOMBUTTONS_H
