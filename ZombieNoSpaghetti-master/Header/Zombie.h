//
// Created by coons on 01.12.2023.
//
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Zombie
{
public:
    int hp;
    Texture texture;
    RectangleShape shape;
    Animation animation;
    bool finished = false;
    Zombie(Texture &texture)
    {
        this -> hp = rand()%3+1;
        this -> texture = texture;
        shape.setTexture(&texture);

    }
    void spawn(sf::RenderWindow &window)
    {
        if(animation.current_animation == 6) {
            finished = true;
        }
        if(!finished) {
            animation.run_animation(this->shape, 6, 80, 684, 80, 76, texture, 20, window);
        }
    }

};
void add(vector<Zombie> &zombieVec, Zombie zombie)
{
    int number = rand()%4+1;
    if(number == 1)
    {
        zombie.shape.setPosition(Vector2f(433,732));
        zombie.shape.setSize(Vector2f(66,33));
        zombieVec.push_back(zombie);
        return;
    }
    else if (number == 2)
    {
        zombie.shape.setPosition(Vector2f(60,590));
        zombie.shape.setSize(Vector2f(66,33));
        zombieVec.push_back(zombie);
        return;
    }
    else if (number == 3)
    {
        zombie.shape.setPosition(Vector2f(154,484));
        zombie.shape.setSize(Vector2f(66,33));
        zombieVec.push_back(zombie);
        return;
    }
    else if (number == 4)
    {
        zombie.shape.setPosition(Vector2f(960,325));
        zombie.shape.setSize(Vector2f(66,33));
        zombieVec.push_back(zombie);
        return;
    }
}
#ifndef ZOMBIENOSPAGHETTI_ZOMBIE_H
#define ZOMBIENOSPAGHETTI_ZOMBIE_H

#endif //ZOMBIENOSPAGHETTI_ZOMBIE_H
