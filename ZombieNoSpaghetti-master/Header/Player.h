
#ifndef ZOMBIENOSPAGHETTI_PLAYER_H
#define ZOMBIENOSPAGHETTI_PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animations.h"
#include "Arrow.h"

using namespace std;
class Player {
public:
    Player()
    {
        if(klasa)
            MAXhp = 7;
        else
            MAXhp = 10;
        width = 50.f;
        hpBarMaxWidth = width;
        height = 10.f;
        previousPosition = playerModel.getPosition();

    }
    sf::Vector2f previousPosition;
    sf::Vector2f velocity;
    sf::RectangleShape hpBarBack;
    sf::RectangleShape hpBarInside;
    Texture texture;
    sf::RectangleShape playerModel;
    void setKlasa(bool choose);
    sf::RectangleShape getPlayerModel();
    void move(sf::RenderWindow &window, Animation &Animation, bool hold, std::vector<std::vector<::Vector2f>> pointsVector, int &lastKey);
    void initModel(sf::Texture &texture);
    bool getKlasa();
    void attack(Animation &animation, bool &attackKey, int &key, sf::RenderWindow &window, vector<Arrow> &arrowVector, int &delaycount, Texture &textureArrow);
private:
    bool klasa; // True - łucznik, False - Berserker
    float MAXhp;
    float width;
    float hpBarMaxWidth;
    float height;

    void UpdatePos() {
        previousPosition = playerModel.getPosition();
        playerModel.move(velocity);
    }

    void UndoMove() {
        playerModel.setPosition(previousPosition);
    }
};
#endif //ZOMBIENOSPAGHETTI_PLAYER_H
