//
// Created by coons on 01.12.2023.
//
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;
using namespace std;
#define width1 50
#define height1 10
class Zombie
{
public:

    int hp;
    int maxHp;
    Texture texture;
    RectangleShape shape;
    Animation animation;
    Animation attackAnimation;
    Animation movingAnimation;
    bool finished = false;
    bool attacking = false;
    sf::RectangleShape hpBarBack;
    sf::RectangleShape hpBarInside;
    Zombie(Texture &texture)
    {
        this -> hp = rand()%3+1;
        this -> maxHp = hp+1;
        this -> texture = texture;
        shape.setTexture(&texture);
        initHp();
    }
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
    void renderHp(sf::RenderTarget& target)
    {
        if(!finished){
            target.draw(hpBarBack);
            target.draw(hpBarInside);
        }
    }

    void initHp()
    {
        hpBarBack.setSize(sf::Vector2f(width1,height1));
        hpBarBack.setFillColor(sf::Color(50,50,50,200));
        hpBarBack.setPosition(shape.getPosition().x,shape.getPosition().y - 35);

        hpBarInside.setSize(sf::Vector2f(width1,height1));
        hpBarInside.setFillColor(sf::Color(250,20,20,200));
        hpBarInside.setPosition(hpBarBack.getPosition());
    }
    void updateHp() { //TODO Postać na wstępie ma hp, ale trzeba gdzieś jej dodać (najlepiej przy zadawaniu obrażenia) aktualizację hp
        float percentage = static_cast<float>(hp) / static_cast<float>(maxHp);
        hpBarInside.setSize(sf::Vector2f(static_cast<float>(std::floor(width1 * percentage)), hpBarInside.getSize().y));
    }
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
