#include <unistd.h>
#include "../Header/Button.h"
using namespace std;
/**
 * @file Button.cpp
 * @brief Implementacja klasy Button.
 */

    /**
     * @brief Funkcja zwraca granice przycisku.
     *
     * @return bitmap Wartość bitmapy przypisana do przycisku (domyślnie -1).
     */
sf::RectangleShape Button::getButtonBorder() {
    return buttonBorder;
}

/**
 * @brief Rysuje przyciski na oknie gry.
 *
 * @param vectorButton Wektor przycisków do narysowania.
 * @param window Referencja do obiektu sf::RenderWindow.
 */
void draw_buttons(std::vector<Button> buttons,sf::RenderWindow &window)
{
    for(Button button : buttons)
        window.draw(button.getButtonBorder());
}

/**
 * @brief Sprawdza, czy któryś przycisk jest najechany kursorem myszy.
 *
 * @param vectorButton Wektor przycisków do sprawdzenia.
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param bitmapValue Wartość bitmapy, którą należy sprawdzić (domyślnie -1).
 */
void check_if_button_pressed(const std::vector<Button>& vectorButton, sf::RenderWindow &window, int bitmapValue)
{

    for(Button button : vectorButton)
        if(button.getButtonBorder().getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && button.get_bitmap() == bitmapValue)
        {
            button.run_function();
            break;
        }


}

/**
     * @brief Uruchamia przypisaną funkcję przycisku.
     */
void Button::run_function() {
    function();
}

/**
     * @brief Pobiera wartość bitmapy przypisanej do przycisku.
     *
     * @return Wartość bitmapy przycisku.
     */
int Button::get_bitmap() {
    return bitmap;
}

/**
 * @brief Sprawdza, czy któryś przycisk jest najechany kursorem myszy.
 *
 * @param vectorButton Wektor przycisków do sprawdzenia.
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param bitmapValue Wartość bitmapy, którą należy sprawdzić (domyślnie -1).
 */
void check_if_button_hovered(const std::vector<Button>& vectorButton, sf::RenderWindow &window, int bitmapValue)
{
    for(Button button : vectorButton)
        if(button.getButtonBorder().getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && button.get_bitmap() == bitmapValue)
        {
            button.run_function();
        }
}
