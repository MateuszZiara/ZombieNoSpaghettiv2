#include <SFML/Audio.hpp>
#include <map>

class SoundEffects {
public:
    sf::Music music;
    std::map<int, std::string> soundsContainer;
public:
    SoundEffects(); // Constructor
    void addToContainer(int key, const std::string& value);

    void playMusic(int value);
    void stopMusic();
    void makeSound(int value);
};

#ifndef ZOMBIENOSPAGHETTI_MUSIC_H
#define ZOMBIENOSPAGHETTI_MUSIC_H

#endif //ZOMBIENOSPAGHETTI_MUSIC_H