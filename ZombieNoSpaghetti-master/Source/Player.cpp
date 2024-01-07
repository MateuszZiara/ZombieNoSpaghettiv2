#include "../Header/Player.h"
#include "../Header/Collision.h"
#include "../Header/Animations.h"
#include <iostream>
/**
 * @file Player.cpp
 * @brief Implementacja klasy Player.
 */


/**
     * @brief Ustawia klasę gracza na podstawie wyboru.
     *
     * @param choose True - łucznik, False - Berserker.
     */
void Player::setKlasa(bool choose) {
    klasa = choose;
}

/**
     * @brief Zwraca model gracza.
     *
     * @return Prostokąt reprezentujący model gracza.
     */
sf::RectangleShape Player::getPlayerModel() {
    return playerModel;
}

/**
   * @brief Przesuwa gracza na podstawie klawiszy wciśniętych przez użytkownika.
   *
   * @param window Referencja do obiektu sf::RenderWindow.
   * @param Animation Referencja do obiektu Animation.
   * @param hold Określa, czy klawisz jest wciśnięty.
   * @param pointsVector Wektor wektorów punktów definiujących obszary na planszy.
   * @param lastKey Ostatni wciśnięty klawisz.
   */
void Player::move(sf::RenderWindow &window, Animation &Animation, bool hold, std::vector<std::vector<::Vector2f>> pointsVector, int &lastKey) {
    int key = lastKey;
    int increment = 3;

    for(std::vector<sf::Vector2f> pointsinvec : pointsVector)
    {
        if(isRectangleTouchingField(playerModel,pointsinvec,window).x != -100 )
       //cout << key; //wyswietlanie granicy na ktora weszła postac
        if(isRectangleTouchingField(playerModel,pointsinvec,window).x != -100 )
        {
            while(isRectangleTouchingField(playerModel,pointsinvec,window).x != -100) {

                if(key == 0)
                    key = lastKey;
                if (key == 1 ) { //w
                    playerModel.setPosition(playerModel.getPosition().x,
                                            playerModel.getPosition().y + playerModel.getGlobalBounds().height-75);
                }
                if (key == 2) { //s
                    playerModel.setPosition(playerModel.getPosition().x,
                                            playerModel.getPosition().y - playerModel.getGlobalBounds().height + 75);
                }
                if (key == 3) { // d
                    playerModel.setPosition(playerModel.getPosition().x - playerModel.getGlobalBounds().width+45,
                                            playerModel.getPosition().y);
                }
                if (key == 4) { // a
                    playerModel.setPosition(playerModel.getPosition().x + playerModel.getGlobalBounds().width-45, playerModel.getPosition().y);
                }
                if (key == 5) //wd
                {

                    playerModel.setPosition(playerModel.getPosition().x - playerModel.getGlobalBounds().width+45, playerModel.getPosition().y + playerModel.getGlobalBounds().height-75);
                }
                if (key == 6) //wa
                {
                    increment ++;
                    playerModel.setPosition(playerModel.getPosition().x + playerModel.getGlobalBounds().width-45, playerModel.getPosition().y + playerModel.getGlobalBounds().height-75);
                }
                if (key == 7) //sa
                {
                    playerModel.setPosition(playerModel.getPosition().x + playerModel.getGlobalBounds().width-45, playerModel.getPosition().y - playerModel.getGlobalBounds().height + 75);
                }
                if (key == 8) //sd
                {
                    increment ++;
                    playerModel.setPosition(playerModel.getPosition().x - playerModel.getGlobalBounds().width+45, playerModel.getPosition().y - playerModel.getGlobalBounds().height + 75);
                }
            }
        }

    }
    if(!hold)
        Animation.current_animation = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerModel.move(0.f,-3.0f);
        //if(klasa)
            Animation.run_animation(playerModel, 9, 69,480,69,96,texture,5,window);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerModel.move(0.f,3.0f);
       // if(klasa)
            Animation.run_animation(playerModel, 9, 69,96,69,96,texture,5,window);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerModel.move(3.f,0.f);
       // if(klasa)
        Animation.run_animation(playerModel,9,69,192,69,96,texture,5,window);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerModel.move(-3.f,0.f);
        //if(klasa)
        Animation.run_animation(playerModel, 9, 69,672,69,96,texture,5,window);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
    {
        key = 5;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
    {
        key = 6;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
    {
        key = 7;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
    {
        key = 8;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        key = 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        key = 2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        key = 3;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        key = 4;
    }

    lastKey = key;
    sf::FloatRect globalBounds = playerModel.getGlobalBounds();
    sf::RectangleShape boundsRect(sf::Vector2f(globalBounds.width, globalBounds.height));
    boundsRect.setPosition(sf::Vector2f(globalBounds.left, globalBounds.top));
    boundsRect.setFillColor(sf::Color(0, 0, 0, 0)); // Transparent fill
    boundsRect.setOutlineColor(sf::Color::Red);
    boundsRect.setOutlineThickness(1.0f);
    window.draw(boundsRect);
}

/**
    * @brief Inicjalizuje model gracza.
    *
    * @param texture Tekstura do użycia dla modelu gracza.
    */
void Player::initModel(sf::Texture &texture) {
        if(klasa)
             this -> texture.loadFromFile("../Textures/lucznik.png");
        else
            this -> texture.loadFromFile("../Textures/berserker.png");
        playerModel.setTexture(&texture);
        playerModel.setPosition(sf::Vector2f(250,600));
        playerModel.setSize(sf::Vector2f(46,76));
        playerModel.setTextureRect(sf::IntRect(0, 0, 66, 96));

}

/**
     * @brief Zwraca wybraną klasę gracza.
     *
     * @return True - łucznik, False - Berserker.
     */
bool Player::getKlasa() {
    return klasa;
}

/**
     * @brief Obsługuje atak gracza.
     *
     * @param animation Referencja do obiektu Animation.
     * @param attackKey Określa, czy klawisz ataku jest wciśnięty.
     * @param key Klawisz ataku.
     * @param window Referencja do obiektu sf::RenderWindow.
     * @param arrowVector Wektor strzał gracza.
     * @param delaycount Licznik opóźnienia ataku.
     * @param textureArrow Tekstura do użycia dla strzał.
     */
void Player::attack(Animation &shoot, bool &attackKey, int &key, sf::RenderWindow &window, vector<Arrow> &arrowVector, int &delaycount, Texture &textureArrow) {
    delaycount++;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            key = 1;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            key = 2;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            key = 3;
        else
            key = 0;


    if(shoot.current_animation == 5 && delaycount >= 6 && getKlasa())
    {
        Arrow arrow(key,sf::Vector2f(playerModel.getPosition().x,playerModel.getPosition().y+playerModel.getSize().y/2-12), textureArrow);
        arrowVector.push_back(arrow);
        delaycount = 0;
    }
    if(shoot.current_animation == 9) {
        attackKey = false;
        shoot.current_animation = 0;
    }
    if(key == 0) {
        if(klasa)
            shoot.run_animation(playerModel, 9, 69, 288, 69, 96, texture, 5, window);
        else
            shoot.run_animation(playerModel, 9, 69, 288, 69, 96, texture, 1, window);
    }
    else if(key == 1){
        if(klasa)
        shoot.run_animation(playerModel,9,69,768,69,96,texture,5,window);
        else
            shoot.run_animation(playerModel,9,69,768,69,96,texture,1,window);
    }
    else  if(key == 3){
        if(klasa)
        shoot.run_animation(playerModel,9,69,864,69,96,texture,5,window);
        else
            shoot.run_animation(playerModel,9,69,864,69,96,texture,1,window);
    }
    else{
        if(klasa)
        shoot.run_animation(playerModel,9,69,576,69,96,texture,5,window);
        else
            shoot.run_animation(playerModel,9,69,576,69,96,texture,1,window);
    }


}
