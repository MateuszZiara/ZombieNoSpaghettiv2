//
// Created by coons on 01.12.2023.
//
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
using namespace std;
#define width 50
#define height 10

/**
 * @file Zombie.h
 * @brief Definicja klasy Zombie reprezentującej przeciwnika w grze.
 */

/**
 * @class Zombie
 * @brief Klasa reprezentująca przeciwnika w grze.
 */
class Zombie
{
public:

    int hp;
    int maxHp;
    Texture texture;
    RectangleShape shape;
    Animation animation;
    bool finished = false;
    sf::RectangleShape hpBarBack;
    sf::RectangleShape hpBarInside;

    /**
      * @brief Konstruktor klasy Zombie.
      * Inicjalizuje zdrowie, maksymalne zdrowie, teksturę i kształt przeciwnika.
      * @param texture Tekstura przeciwnika.
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
     * @brief Funkcja spawnująca przeciwnika.
     * Jeśli animacja przeciwnika nie została zakończona, uruchamia animację.
     * @param window Referencja do obiektu sf::RenderWindow, na którym przeciwnik jest renderowany.
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
     * @brief Funkcja rysująca pasek zdrowia przeciwnika.
     * Rysuje tło i wewnętrzną część paska zdrowia, jeśli animacja przeciwnika nie została zakończona.
     * @param target Referencja do obiektu sf::RenderTarget, na którym pasek zdrowia jest renderowany.
     */
    void renderHp(sf::RenderTarget& target)
    {
        if(!finished){
            target.draw(hpBarBack);
            target.draw(hpBarInside);
        }
    }

    /**
     * @brief Inicjalizuje pasek zdrowia przeciwnika.
     * Ustawia rozmiar i kolory tła oraz wewnętrznej części paska zdrowia.
     */
    void initHp()
    {
        hpBarBack.setSize(sf::Vector2f(width,height));
        hpBarBack.setFillColor(sf::Color(50,50,50,200));
        hpBarBack.setPosition(shape.getPosition().x,shape.getPosition().y - 35);

        hpBarInside.setSize(sf::Vector2f(width,height));
        hpBarInside.setFillColor(sf::Color(250,20,20,200));
        hpBarInside.setPosition(hpBarBack.getPosition());
    }

    /**
     * @brief Inicjalizuje pasek zdrowia przeciwnika.
     * Ustawia rozmiar i kolory tła oraz wewnętrznej części paska zdrowia.
     */
    void updateHp() { //TODO Postać na wstępie ma hp, ale trzeba gdzieś jej dodać (najlepiej przy zadawaniu obrażenia) aktualizację hp
        float percentage = static_cast<float>(hp) / static_cast<float>(maxHp);
        hpBarInside.setSize(sf::Vector2f(static_cast<float>(std::floor(width * percentage)), hpBarInside.getSize().y));
    }
};

/**
 * @brief Funkcja dodająca przeciwnika do wektora przeciwników.
 * Generuje losową liczbę, na podstawie której określa początkową pozycję przeciwnika.
 * @param zombieVec Wektor przeciwników.
 * @param zombie Przeciwnik do dodania.
 * @param window Referencja do obiektu sf::RenderWindow, na którym przeciwnik jest renderowany.
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
