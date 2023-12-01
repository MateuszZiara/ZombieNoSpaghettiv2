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
    Zombie(Texture texture, RectangleShape shape)
    {
        this -> hp = rand()%3+1;
        this -> texture = texture;
        shape.setTexture(&texture);
    }

};
void add(vector<Zombie>& zombieVec, Zombie& zombie)
{
    int number = rand()%4+1;
    if(number == 1)
    {
        zombie.shape.setPosition(Vector2f(433,732));
        zombieVec.push_back(zombie);
        return;
    }
    else if (number == 2)
    {
        zombie.shape.setPosition(Vector2f(60,590));
        zombieVec.push_back(zombie);
        return;
    }
    else if (number == 3)
    {
        zombie.shape.setPosition(Vector2f(154,484));
        zombieVec.push_back(zombie);
        return;
    }
    else if (number == 4)
    {
        zombie.shape.setPosition(Vector2f(960,325));
        zombieVec.push_back(zombie);
        return;
    }
}
#ifndef ZOMBIENOSPAGHETTI_ZOMBIE_H
#define ZOMBIENOSPAGHETTI_ZOMBIE_H

#endif //ZOMBIENOSPAGHETTI_ZOMBIE_H
