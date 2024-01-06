#include <SFML/Audio.hpp>
#include "../Header/SoundEffects.h"
#include <iostream>

SoundEffects::SoundEffects() {
    addToContainer(1, "../Sounds/background.ogg");
    //addToContainer(2, "../Sounds/zombieNoise.ogg");
    //addToContainer(3, "../Sounds/playerNoise.ogg");
}

void SoundEffects::addToContainer(int key, const std::string& value) {
    soundsContainer[key] = value;
}

void SoundEffects::playMusic(int value) {
    if (music.getStatus() != sf::Music::Playing) {
        auto it = soundsContainer.find(value);
        if (it != soundsContainer.end()) {
            if (!music.openFromFile(it->second)) {
                std::cout << "Nie znaleziono utworu.";
            }
            music.setLoop(true);
            music.setVolume(20);
            music.play();
        } else {
            std::cout << "Podana wartość nie jest zadeklarowana w słowniku.";
        }
    }
}

void SoundEffects::stopMusic() {
    music.stop();
}

void SoundEffects::makeSound(int value) {
    auto it = soundsContainer.find(value);
    if (it != soundsContainer.end()) {
        if (!music.openFromFile(it->second)) {
            std::cout<<"Nie znaleziono utworu.";
        }
        music.setVolume(20);
        music.play();
    } else {
        std::cout<<"Podana wartość nie jest zadeklarowana w słowniku.";
    }
}
