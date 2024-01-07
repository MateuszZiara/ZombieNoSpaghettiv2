#include <valarray>
#include <SFML/Graphics.hpp>
#include <algorithm> // for std::sort
#include "../Header/Collision.h"
/**
 * @file Collision.cpp
 * @brief Implementacja klasy Collision.
 */

/**
 * @brief Pobiera globalne granice wielokąta zdefiniowanego przez punkty.
 *
 * @param points Wektor punktów definiujących wielokąt.
 * @return Obiekt sf::FloatRect reprezentujący globalne granice wielokąta.
 */
sf::FloatRect getGlobalBounds(const std::vector<sf::Vector2f>& points) {
    sf::ConvexShape tempField;
    tempField.setPointCount(points.size());

    for (std::size_t i = 0; i < points.size(); ++i) {
        tempField.setPoint(i, points[i]);
    }

    return tempField.getGlobalBounds();
}

/**
 * @brief Tworzy wielokąt reprezentujący obszar na planszy.
 *
 * @param points Wektor punktów definiujących obszar na planszy.
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param fillColor Kolor wypełnienia obszaru na planszy.
 * @return Obiekt sf::ConvexShape reprezentujący obszar na planszy.
 */
sf::ConvexShape getField(const std::vector<sf::Vector2f>& points, sf::RenderWindow& window, const sf::Color& fillColor)
{
    // Create a convex shape to represent the field
    sf::ConvexShape field;
    field.setPointCount(points.size());

    // Set the points of the convex shape
    for (std::size_t i = 0; i < points.size(); ++i) {
        field.setPoint(i, points[i]);

        sf::Vertex line[] = {
                sf::Vertex(points[i]),
                sf::Vertex(points[(i + 1) % points.size()])
        };

        window.draw(line, 2, sf::Lines);
    }
    // Set the fill color of the field
    field.setFillColor(fillColor);

    // Draw the filled field
    window.draw(field);
    return field;
}

/**
 * @brief Rysuje granice prostokąta z określonym kolorem.
 *
 * @param rect Prostokąt, którego granice są rysowane.
 * @param window Referencja do obiektu sf::RenderWindow.
 * @param boundsColor Kolor granic prostokąta.
 */
void drawRectangleBounds(const sf::RectangleShape& rect, sf::RenderWindow& window, const sf::Color& boundsColor)
{
    // Create a rectangle shape representing the global bounds
    sf::RectangleShape boundsRect(rect.getGlobalBounds().getSize());
    boundsRect.setPosition(rect.getGlobalBounds().left, rect.getGlobalBounds().top);
    boundsRect.setFillColor(sf::Color::Transparent);
    boundsRect.setOutlineColor(boundsColor);
    boundsRect.setOutlineThickness(2.0f);

    // Draw the outlined rectangle
    window.draw(boundsRect);
}

/**
 * @brief Sprawdza, czy punkt znajduje się wewnątrz wielokąta.
 *
 * @param point Punkt, którego przynależność do wielokąta jest sprawdzana.
 * @param polygon Wielokąt, w którym sprawdzana jest przynależność punktu.
 * @return Zwraca true, jeżeli punkt znajduje się wewnątrz wielokąta, w przeciwnym razie false.
 */
bool isPointInsidePolygon(const sf::Vector2f& point, const std::vector<sf::Vector2f>& polygon)
{
    bool inside = false;
    for (std::size_t i = 0, j = polygon.size() - 1; i < polygon.size(); j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}




/**
 * @brief Sprawdza, czy prostokąt dotyka obszaru na planszy.
 *
 * @param rect Prostokąt, którego dotykanie jest sprawdzane.
 * @param points Wektor punktów definiujących obszar na planszy.
 * @param window Referencja do obiektu sf::RenderWindow.
 * @return Zwraca wektor sf::Vector2f reprezentujący punkt dotykania prostokąta, lub sf::Vector2f(-100, -100), jeżeli nie ma kolizji.
 */
sf::Vector2f isRectangleTouchingField(sf::RectangleShape& rect, std::vector<sf::Vector2f> points, sf::RenderWindow& window)
{
    // Sort the points in counterclockwise order
    std::sort(points.begin(), points.end(), [&points](const sf::Vector2f& a, const sf::Vector2f& b) {
        return std::atan2(a.y - points[0].y, a.x - points[0].x) < std::atan2(b.y - points[0].y, b.x - points[0].x);
    });

    // Draw the filled field with red color
    sf::ConvexShape field = getField(points, window, sf::Color::Red);
    field.setPointCount(points.size());
    for (std::size_t i = 0; i < points.size(); ++i) {
        field.setPoint(i, points[i]);
    }
    field.setFillColor(sf::Color::Red);

    // Draw the rectangle bounds with yellow color
    drawRectangleBounds(rect, window, sf::Color::Yellow);

    // Iterate over the sorted points of the rectangle
    for (const sf::Vector2f& rectPoint : {
            rect.getPosition(),
            {rect.getPosition().x + rect.getSize().x, rect.getPosition().y},
            {rect.getPosition().x, rect.getPosition().y + rect.getSize().y},
            {rect.getPosition().x + rect.getSize().x, rect.getPosition().y + rect.getSize().y}
    }) {
        // Check if the point is inside the convex shape (use the sorted points)
        if (isPointInsidePolygon(rectPoint, points)) {
            return rectPoint;
        }
    }
    return sf::Vector2f(-100, -100);
}


