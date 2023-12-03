#include <SFML/Graphics.hpp>
#include "WindowConfig.h"
#include "Collision.h"
#include "BitMap.h"
#include "CustomButtons.h"
#include "Player.h"
#include "Arrow.h"
#include "Zombie.h"
#ifndef ZOMBIENOSPAGHETTI_ENGINE_H
#define ZOMBIENOSPAGHETTI_ENGINE_H
class Engine
{
public:
    Engine() : window(sf::VideoMode(1366, 768), "Zombiaki no spagetti!") {
        init_graphic();
        init_variables();
        bitMap.setStage(0);
    }
    //Zmienne
    sf::RenderWindow window;
    Event event;
    bool wasMouseButtonPressed;
    bool wasWalkKeysPressed;
    bool wasShootKeyPressed;
    Player player;
    BitMap bitMap;
    int key;
    int delayCount;
    View view;
    float halfWindowWidth;
    float halfWindowHeight;
    int lastkey = 0;
    int zombieSpawn = 0;
    int zombieCount = 0;
    vector<Arrow> arrowVector;
    vector<Zombie> zombieVector;
    std::vector<sf::Vector2f> points = {
            sf::Vector2f(458, 0),
            sf::Vector2f(300, 100),
            sf::Vector2f(354, 452),
            sf::Vector2f(500, 300),
            sf::Vector2f(0, 511)
    };
    std::vector<sf::Vector2f> points2 = {
            sf::Vector2f(410, 465), //pień
            sf::Vector2f(422, 482),
            sf::Vector2f(417, 509),
            sf::Vector2f(391, 505),
            sf::Vector2f(410, 465),
    };
    std::vector<sf::Vector2f> points3 = {
            sf::Vector2f(569, 24), //drzewo
            sf::Vector2f(648, 25),
            sf::Vector2f(653, 98),
            sf::Vector2f(619, 140),
            sf::Vector2f(583, 134),
            sf::Vector2f(587, 107),
            sf::Vector2f(550, 97),
    };
    std::vector<sf::Vector2f> points4 = {
            sf::Vector2f(1037, 0), //prawy brzeg
            sf::Vector2f(1366, 0),
            sf::Vector2f(1366, 768),
            sf::Vector2f(850, 768),
            sf::Vector2f(833, 754),
            sf::Vector2f(853, 723),
            sf::Vector2f(839, 678),
            sf::Vector2f(859, 579),
            sf::Vector2f(868, 470),
            sf::Vector2f(916, 413),
            sf::Vector2f(993, 403),
            sf::Vector2f(1006, 296),
            sf::Vector2f(1044, 246),
            sf::Vector2f(1031, 205),
            sf::Vector2f(1037, 0)
    };
    std::vector<std::vector<sf::Vector2f>> allPoints;
    Animation LucznikMenu;
    Animation BerserkMenu;
    Animation walk;
    Animation idle;
    Animation shoot;
    Texture archerTexture;
    Texture berserkTexture;
    Texture arrowTexture;
    Texture zombieTexture;
    //Buttons
    std::vector<Button> buttonVector = init_buttons(window, bitMap, player, archerTexture, berserkTexture);
    std::vector<Button> buttonVectorHovered = init_buttonsHovered(window, bitMap, BerserkMenu, LucznikMenu);
    //Funkcje
    void init_variables()
    {
        wasMouseButtonPressed = false;
        wasWalkKeysPressed = false;
        wasShootKeyPressed = false;
        key = -1;
        delayCount = 0;
        halfWindowWidth = window.getSize().x / 4;
        halfWindowHeight = window.getSize().y / 4;
        allPoints.push_back(points);
        allPoints.push_back(points2);
        allPoints.push_back(points3);
        allPoints.push_back(points4);
    }
    void init_graphic()
    {
        WindowConfig::setDefault(window);
        view = sf::View(sf::Vector2f(0.f,0.f), sf::Vector2f (window.getSize()));
        archerTexture.loadFromFile("../Textures/lucznik.png");
        berserkTexture.loadFromFile("../Textures/berserker.png");
        arrowTexture.loadFromFile("../Textures/lucznik.png");
        zombieTexture.loadFromFile("../Textures/zombie.png");
        draw_buttons(buttonVector,window);

    }
    void event_update()
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    void vectors_update() {
        for (int i = 0; i < arrowVector.size(); ++i) {
            arrowVector[i].move();
            if (collisionWithBorderRect(arrowVector[i].arrowShape, window)) {
                arrowVector.erase(arrowVector.begin() + i);
                break;
            }
            window.draw(arrowVector[i].arrowShape);
        }

        for (Zombie& zombie : zombieVector) {
            zombie.spawn(window);
            zombie.renderHp(window);
        }

        for (std::size_t i = 0; i < points.size(); ++i) {
            sf::Vertex line[] = {
                    sf::Vertex(points[i]),
                    sf::Vertex(points[(i + 1) % points.size()])
            };
            window.draw(line, 2, sf::Lines);
        }
    }

    void view_update()
    {
        sf::Vector2f viewCenter(player.getPlayerModel().getPosition().x, player.getPlayerModel().getPosition().y);
        viewCenter.x = std::min(std::max(viewCenter.x, halfWindowWidth), window.getSize().x - halfWindowWidth);
        viewCenter.y = std::min(std::max(viewCenter.y, halfWindowHeight), window.getSize().y - halfWindowHeight);
        view.setCenter(viewCenter);
        view.setSize(window.getSize().x / 2, window.getSize().y / 2);
    }
    void keyboard_update()
    {
        if(!wasShootKeyPressed)
            player.move(window,walk,wasWalkKeysPressed,allPoints, lastkey);
        if(!wasMouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            check_if_button_pressed(buttonVector, window, bitMap.getStage());
        }
        wasMouseButtonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            wasWalkKeysPressed = true;
        else
            wasWalkKeysPressed = false;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            wasShootKeyPressed = true;

        if(!wasWalkKeysPressed && !wasShootKeyPressed)
        {
            idle.run_animation(player.playerModel,9,69,0,69,96,player.texture,5,window);
        }
        if(wasShootKeyPressed)
            player.attack(shoot, wasShootKeyPressed, key, window, arrowVector, delayCount, arrowTexture);
    }
    void buttons_upadte()
    {
        check_if_button_hovered(buttonVectorHovered,window,bitMap.getStage());
    }
    void run_engine()
    {
        zombieSpawn++;
        event_update();
        view_update();
        keyboard_update();
        bitMap.configureBitMap(window,view);
        buttons_upadte();
        vectors_update();
        window.draw(player.getPlayerModel());
        isRectangleTouchingField(player.playerModel,points2,window);
        if(zombieSpawn >= 200)
        {
            Zombie zombie(zombieTexture);
            add(zombieVector,zombie,window);
            zombieSpawn = 0;
            zombieCount++;
        }
        window.display();
        window.clear();
    }
};
#endif //ZOMBIENOSPAGHETTI_ENGINE_H
