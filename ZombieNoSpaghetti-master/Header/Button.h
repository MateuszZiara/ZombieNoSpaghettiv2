//
// Created by coons on 31.10.2023.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>

/**
 * @file Button.h
 * @brief Deklaracja pliku nagłówkowego Button.h oraz związanych funkcji.
 */

/**
 * @class Button
 * @brief Klasa reprezentująca przycisk w grze.
 */
class Button
{
public:

    /**
     * @brief Konstruktor klasy Button.
     *
     * Tworzy obiekt przycisku na podstawie podanych współrzędnych, funkcji oraz opcjonalnej wartości bitmapy.
     *
     * @param minX Minimalna wartość współrzędnej X przycisku.
     * @param maxX Maksymalna wartość współrzędnej X przycisku.
     * @param minY Minimalna wartość współrzędnej Y przycisku.
     * @param maxY Maksymalna wartość współrzędnej Y przycisku.
     * @param function Funkcja wywoływana po naciśnięciu przycisku.
     * @param bitmap Wartość bitmapy przypisana do przycisku (domyślnie -1).
     */
    Button(int minX, int maxX, int minY, int maxY, std::function<void()> function, int bitmap = -1)
    {
        this->minX = minX;
        this->maxX = maxX;
        this->minY = minY;
        this->maxY = maxY;
        buttonBorder.setSize(sf::Vector2f(maxX - minX, maxY - minY));
        buttonBorder.setPosition(minX,minY);
        buttonBorder.setFillColor(sf::Color(0,0,0,0));
        this->function = function;
        this->bitmap = bitmap;
    }

    /**
     * @brief Pobiera granice prostokąta reprezentującego przycisk.
     *
     * @return Obiekt sf::RectangleShape reprezentujący granice przycisku.
     */
    sf::RectangleShape getButtonBorder();

    /**
     * @brief Uruchamia przypisaną funkcję przycisku.
     */
    void run_function();

    /**
     * @brief Pobiera wartość bitmapy przypisanej do przycisku.
     *
     * @return Wartość bitmapy przycisku.
     */
    int get_bitmap();
private:
    int minX; ///< Minimalna wartość współrzędnej X przycisku.
    int maxX; ///< Maksymalna wartość współrzędnej X przycisku.
    int minY; ///< Minimalna wartość współrzędnej Y przycisku.
    int maxY; ///< Maksymalna wartość współrzędnej Y przycisku.
    int bitmap; ///< Wartość bitmapy przycisku.
    sf::RectangleShape buttonBorder; ///< Granice prostokąta reprezentującego przycisk.
public:
    std::function<void()> function; ///< Funkcja przypisana do przycisku.
};

/**
 * @brief Sprawdza, czy któryś przycisk został naciśnięty.
 *
 * @param vectorButton Wektor przycisków do sprawdzenia.
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param bitmapValue Wartość bitmapy, którą należy sprawdzić (domyślnie -1).
 */
void check_if_button_pressed(const std::vector<Button>& vectorButton, sf::RenderWindow &window, int bitmapValue = -1);

/**
 * @brief Rysuje przyciski na oknie gry.
 *
 * @param vectorButton Wektor przycisków do narysowania.
 * @param window Referencja do obiektu sf::RenderWindow.
 */
void draw_buttons(std::vector<Button> , sf::RenderWindow &window);

/**
 * @brief Sprawdza, czy któryś przycisk jest najechany kursorem myszy.
 *
 * @param vectorButton Wektor przycisków do sprawdzenia.
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param bitmapValue Wartość bitmapy, którą należy sprawdzić (domyślnie -1).
 */
void check_if_button_hovered(const std::vector<Button>& vectorButton, sf::RenderWindow &window, int bitmapValue = -1);
#ifndef ZOMBIENOSPAGHETTI_BUTTON_H
#define ZOMBIENOSPAGHETTI_BUTTON_H

#endif //ZOMBIENOSPAGHETTI_BUTTON_H
