/**
 * @file Zombie.h
 *
 * @brief Plik nagłówkowy klasy Zombie, reprezentującej postać zombie w grze.
 */
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;
using namespace std;
#define width1 50
#define height1 10

/**
 * @class Zombie
 *
 * @brief Reprezentuje postać zombie w grze.
 */
class Zombie
{
public:
    int hp; /**< Aktualne punkty zdrowia zombie. */
    int maxHp; /**< Maksymalna ilość punktów zdrowia zombie. */
    Texture texture; /**< Tekstura używana do renderowania zombie. */
    RectangleShape shape; /**< Kształt zombie. */
    Animation animation; /**< Animacja ogólnego ruchu zombie. */
    Animation attackAnimation; /**< Animacja ataku zombie. */
    Animation movingAnimation; /**< Animacja ruchu zombie w kierunku gracza. */
    bool finished = false; /**< Flaga wskazująca, czy animacja zombie została zakończona. */
    bool attacking = false; /**< Flaga wskazująca, czy zombie aktualnie wykonuje atak. */
    sf::RectangleShape hpBarBack; /**< Kształt tła paska zdrowia. */
    sf::RectangleShape hpBarInside; /**< Kształt przedstawiający aktualne zdrowie. */

    /**
     * @brief Konstruktor klasy Zombie.
     *
     * @param texture Referencja do tekstury używanej do renderowania zombie.
     */
    Zombie(Texture &texture)
    {
        this -> hp = rand()%3+1;
        this -> maxHp = hp+1;
        this -> texture = texture;
        shape.setTexture(&texture);
        initHp();
    }

    /**
     * @brief Tworzy zombie w oknie gry.
     *
     * @param window Referencja do okna gry.
     */
    void spawn(sf::RenderWindow &window) {
        if (animation.current_animation == 6) {
            finished = true;
        }
        if (!finished) {
            animation.run_animation(this->shape, 6, 80, 684, 80, 76, texture, 20, window);
        }
        hpBarBack.setPosition(shape.getPosition().x, shape.getPosition().y - 35);
        hpBarInside.setPosition(hpBarBack.getPosition());
    }

    /**
     * @brief Renderuje pasek zdrowia zombie.
     *
     * @param target Cel renderowania.
     */
    void renderHp(sf::RenderTarget& target)
    {
        if(!finished){
            target.draw(hpBarBack);
            target.draw(hpBarInside);
        }
    }

    /**
     * @brief Inicjalizuje właściwości paska zdrowia.
     */
    void initHp()
    {
        hpBarBack.setSize(sf::Vector2f(width1,height1));
        hpBarBack.setFillColor(sf::Color(50,50,50,200));
        hpBarBack.setPosition(shape.getPosition().x,shape.getPosition().y - 35);

        hpBarInside.setSize(sf::Vector2f(width1,height1));
        hpBarInside.setFillColor(sf::Color(250,20,20,200));
        hpBarInside.setPosition(hpBarBack.getPosition());
    }

    /**
     * @brief Aktualizuje pasek zdrowia na podstawie aktualnych punktów zdrowia.
     *
     */
    void updateHp() {
        float percentage = static_cast<float>(hp) / static_cast<float>(maxHp);
        hpBarInside.setSize(sf::Vector2f(static_cast<float>(std::floor(width1 * percentage)), hpBarInside.getSize().y));
    }

    /**
     * @brief Aktualizuje pasek zdrowia na podstawie aktualnych punktów zdrowia.
     */
    void attack(RectangleShape player, sf::RenderWindow &window)
    {
        if((player.getGlobalBounds().intersects(shape.getGlobalBounds()) && finished) || attacking)
        {
            if(attacking)
            {
                if(attackAnimation.current_animation >= 12)
                {
                    attacking = false;
                }
            }
            else
            {
                attacking = true;
            }
            int resultX = player.getPosition().x - shape.getPosition().x;
            int resultY = player.getPosition().y - shape.getPosition().y;
            int resultXCheck = resultX;
            int resultYCheck = resultY;
            if(resultXCheck < 0)
                resultXCheck *= -1;
            if(resultYCheck < 0)
                resultYCheck *= -1;
            if(resultXCheck > resultYCheck)
            {
                if(resultX > 0)
                {
                    attackAnimation.run_animation(shape,12,80,608,80,76,texture,10, window);
                }
                else
                {
                    attackAnimation.run_animation(shape,12,80,455,80,76,texture,10, window);
                }
            }
            else
            {
                if(resultY > 0)
                {
                    attackAnimation.run_animation(shape,12,80,381,80,76,texture,10, window);
                }
                else
                {
                    attackAnimation.run_animation(shape,12,80,532,80,76,texture,10, window);
                }
            }
        }
    }

    /**
     * @brief Przesuwa zombie w kierunku gracza.
     *
     * @param player RectangleShape reprezentujący gracza.
     * @param window Referencja do okna gry.
     */
    void moveShapeTowardsPlayer(sf::RectangleShape player, sf::RenderWindow& window) {
        if(finished && !attacking) {
            // Get the position of the shape and player
            sf::Vector2f shapePos = shape.getPosition();
            sf::Vector2f playerPos = player.getPosition();

            // Calculate the direction vector from shape to player
            sf::Vector2f direction = playerPos - shapePos;

            // Normalize the direction vector
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            if (length != 0) {
                direction /= length;
            }

            // Set the speed of the movement
            float speed = 2.0f;

            // Calculate the new position of the shape
            sf::Vector2f newPosition = shapePos + direction * speed;
            // Move the shape towards the player
            shape.setPosition(newPosition);

            renderHp(window);
            updateHp();
            movingAnimation.run_animation(shape,8,80,304,80,78,texture,10,window);
            // Draw the updated shape on the window
            window.draw(shape);
        }
    }

};

/**
 * @brief Dodaje zombie do wektora zombie z losową pozycją.
 *
 * @param zombieVec Wektor zombie.
 * @param zombie Obiekt zombie do dodania.
 * @param window Referencja do okna gry.
 */
void add(vector<Zombie> &zombieVec, Zombie zombie, sf::RenderWindow& window)
{
    int number = rand()%4+1;
    if(number == 1)
    {
        zombie.shape.setPosition(Vector2f(433,732));
        zombie.shape.setSize(Vector2f(66,33));
        zombieVec.push_back(zombie);
        zombieVec.back().initHp();
        zombieVec.back().renderHp(window);
        return;
    }
    else if (number == 2)
    {
        zombie.shape.setPosition(Vector2f(60,590));
        zombie.shape.setSize(Vector2f(66,33));
        zombieVec.push_back(zombie);
        zombieVec.back().initHp();
        zombieVec.back().renderHp(window);
        return;
    }
    else if (number == 3)
    {
        zombie.shape.setPosition(Vector2f(154,484));
        zombie.shape.setSize(Vector2f(66,33));
        zombieVec.push_back(zombie);
        zombieVec.back().initHp();
        zombieVec.back().renderHp(window);
        return;
    }
    else if (number == 4)
    {
        zombie.shape.setPosition(Vector2f(960,325));
        zombie.shape.setSize(Vector2f(66,33));
        zombieVec.push_back(zombie);
        zombieVec.back().initHp();
        zombieVec.back().renderHp(window);
        return;
    }

}

#ifndef ZOMBIENOSPAGHETTI_ZOMBIE_H
#define ZOMBIENOSPAGHETTI_ZOMBIE_H

#endif //ZOMBIENOSPAGHETTI_ZOMBIE_H
