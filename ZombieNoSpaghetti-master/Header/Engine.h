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

/**
 * @file Engine.h
 * @brief Definicja klasy Engine, która zarządza główną logiką gry.
 */

/**
 * @brief Główna klasa zarządzająca logiką gry.
 */
class Engine
{
public:
    /**
  * @brief Konstruktor klasy Engine.
  * Inicjalizuje okno gry, ustawienia graficzne oraz obiekty gry.
  */
    Engine() : window(sf::VideoMode(1366, 768), "Zombiaki no spagetti!") {
        init_graphic();
        init_variables();
        bitMap.setStage(0);
    }
    //Zmienne
    sf::RenderWindow window; ///< Okno gry.
    Event event;
    bool wasMouseButtonPressed; ///< Flaga wciśnięcia przycisku myszy
    bool wasWalkKeysPressed; ///< Flaga wciśnięcia WSAD-u
    bool wasShootKeyPressed; ///< Flaga wciśnięcia spacji
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
    Animation dead;
    Texture archerTexture;
    Texture berserkTexture;
    Texture arrowTexture;
    Texture zombieTexture;
    //Buttons
    std::vector<Button> buttonVector = init_buttons(window, bitMap, player, archerTexture, berserkTexture);
    std::vector<Button> buttonVectorHovered = init_buttonsHovered(window, bitMap, BerserkMenu, LucznikMenu);
    //Funkcje

    /**
     * @brief Inicjalizuje zmienne klasy Engine.
     * Ustawia początkowe wartości dla flag, liczników, i połówki rozmiarów okna.
     */
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

    /**
     * @brief Inicjalizuje elementy graficzne, takie jak tekstury i widok.
     */
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

    /**
    * @brief Obsługuje zdarzenia, takie jak zamknięcie okna.
    */
    void event_update()
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    /**
     * @brief Aktualizuje wektory obiektów gry (np. ruch strzał, spawn zombie).
     */
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
            zombie.attack(player.getPlayerModel(),window);
            zombie.moveShapeTowardsPlayer(player.getPlayerModel(),window);
            if(zombie.shape.getGlobalBounds().intersects(player.getPlayerModel().getGlobalBounds()) && !zombie.attacking)
            {
                player.hp = player.hp -1;

            }
        }


        for(int i = 0; i < arrowVector.size(); ++i)
        {
            for(int j = 0; j < zombieVector.size(); ++j)
            {
                if(arrowVector[i].arrowShape.getGlobalBounds().intersects(zombieVector[j].shape.getGlobalBounds()))
                {
                    zombieVector.erase(zombieVector.begin() + j);
                    arrowVector.erase(arrowVector.begin() + i);
                    player.punkty++;
                    break;
                }
            }
        }
    }
/**
     * @brief Aktualizuje widok gry w zależności od położenia gracza.
     */
    void view_update()
    {
        sf::Vector2f viewCenter(player.getPlayerModel().getPosition().x, player.getPlayerModel().getPosition().y);
        viewCenter.x = std::min(std::max(viewCenter.x, halfWindowWidth), window.getSize().x - halfWindowWidth);
        viewCenter.y = std::min(std::max(viewCenter.y, halfWindowHeight), window.getSize().y - halfWindowHeight);
        view.setCenter(viewCenter);
        view.setSize(window.getSize().x / 2, window.getSize().y / 2);
    }

    /**
     * @brief Aktualizuje sterowanie klawiaturą, obsługę przycisków myszy oraz animacje gracza.
     */
    void keyboard_update()
    {
        if(player.hp > 0) {
            if (!wasShootKeyPressed)
                player.move(window, walk, wasWalkKeysPressed, allPoints, lastkey);
            if (!wasMouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                check_if_button_pressed(buttonVector, window, bitMap.getStage());
            }
            wasMouseButtonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                wasWalkKeysPressed = true;
            }
            else
                wasWalkKeysPressed = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                wasShootKeyPressed = true;
                if(!player.getKlasa())
                {
                    sf::FloatRect expandedBounds = player.getPlayerModel().getGlobalBounds();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    {
                        expandedBounds.left -= 80;
                    }

                    // Check if D key is pressed and expand right
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        expandedBounds.width += 80;
                    }

                    // Check if W key is pressed and expand up
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        expandedBounds.top -= 80;
                    }

                    // Check if S key is pressed and expand down
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        expandedBounds.height += 80;
                    }
                    for(int i = 0; i < zombieVector.size(); ++i)
                    {
                        if (zombieVector[i].shape.getGlobalBounds().intersects(expandedBounds))
                        {
                            zombieVector.erase(zombieVector.begin() + i);
                            player.punkty++;
                        }
                    }
                }
            }
            if (!wasWalkKeysPressed && !wasShootKeyPressed) {
                idle.run_animation(player.playerModel, 9, 69, 0, 69, 96, player.texture, 5, window);
            }
            if (wasShootKeyPressed)
                player.attack(shoot, wasShootKeyPressed, key, window, arrowVector, delayCount, arrowTexture);

        }
        if(player.getPlayerModel().getPosition().y > window.getSize().y - player.getPlayerModel().getSize().y)
        {

            player.playerModel.setPosition(sf::Vector2f(player.getPlayerModel().getPosition().x,window.getSize().y - player.playerModel.getSize().y));
        }
        if(player.getPlayerModel().getPosition().x < 0)
        {

            player.playerModel.setPosition(sf::Vector2f( 0,player.getPlayerModel().getPosition().y));
        }
        if(player.getPlayerModel().getPosition().y < 0)
        {
            player.playerModel.setPosition(sf::Vector2f(player.getPlayerModel().getPosition().x,0));
        }
    }

    /**
     * @brief Aktualizuje stan przycisków gry (najechane).
     */
    void buttons_upadte()
    {
        check_if_button_hovered(buttonVectorHovered,window,bitMap.getStage());
    }

    /**
     * @brief Uruchamia silnik gry, rysuje obiekty, obsługuje zdarzenia, aktualizuje stany.
     */


    void run_engine()
    {
            zombieSpawn++;
            event_update();
            view_update();
            keyboard_update();
            bitMap.configureBitMap(window, view);
            buttons_upadte();
            vectors_update();
            window.draw(player.getPlayerModel());

            if(bitMap.getStage() == 3) {
                if (zombieSpawn >= 200) {
                    if (zombieVector.size() < 6) {
                        Zombie zombie(zombieTexture);
                        add(zombieVector, zombie, window);
                        zombieSpawn = 0;
                    }

                }
            }

        if(player.hp <= 0)
        {
            //Animation.run_animation(playerModel, 9, 69,96,69,96,texture,5,window);
            if(dead.current_animation < 8)
                if(player.klasa)
                    dead.run_animation(player.playerModel,9,69,384,69,96,archerTexture,10,window);
                else
                    dead.run_animation(player.playerModel,9,69,384,69,96,berserkTexture,10,window);
            if(dead.current_animation == 8)
            {
                zombieVector.clear();
                arrowVector.clear();
                window.setView(window.getDefaultView());
                player.playerModel.setSize(Vector2f(0,0));
                bitMap.setStage(4);
                sf::Text pointsText;
                Font font;
                font.loadFromFile("Arial.ttf");
                pointsText.setFont(font);
                pointsText.setCharacterSize(24);
                pointsText.setFillColor(sf::Color::White);
                pointsText.setPosition(10, 10); // Adjust the position as needed
                pointsText.setString("Points: " + std::to_string(player.punkty));
                window.draw(pointsText);
                //Render here player.punkty which is int
            }

        }


        window.display();
            window.clear();
    }
};
#endif //ZOMBIENOSPAGHETTI_ENGINE_H
