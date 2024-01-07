/**
 * @file SoundEffects.cpp
 * @brief Implementacja klasy SoundEffects.
 */

#include "../Header/SoundEffects.h"
#include <iostream>

/**
 * @brief Konstruktor domyślny klasy SoundEffects.
 */
SoundEffects::SoundEffects() {
    addToContainer(1, "../Sounds/background.ogg");
    //addToContainer(2, "../Sounds/zombieNoise.ogg");
    //addToContainer(3, "../Sounds/playerNoise.ogg");
}

/**
 * @brief Dodaje efekt dźwiękowy do kontenera.
 * @param key Klucz przypisujący efekt dźwiękowy.
 * @param value Ścieżka do pliku efektu dźwiękowego.
 */
void SoundEffects::addToContainer(int key, const std::string& value) {
    soundsContainer[key] = value;
}

/**
 * @brief Odtwarza muzykę na podstawie podanego klucza.
 * @param value Klucz związany z pożądaną muzyką.
 */
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

/**
 * @brief Zatrzymuje aktualnie odtwarzaną muzykę.
 */
void SoundEffects::stopMusic() {
    music.stop();
}

/**
 * @brief Odtwarza efekt dźwiękowy na podstawie podanego klucza.
 * @param value Klucz związany z pożądanym efektem dźwiękowym.
 */
void SoundEffects::makeSound(int value) {
    auto it = soundsContainer.find(value);
    if (it != soundsContainer.end()) {
        if (!music.openFromFile(it->second)) {
            std::cout << "Nie znaleziono utworu.";
        }
        music.setVolume(20);
        music.play();
    } else {
        std::cout << "Podana wartość nie jest zadeklarowana w słowniku.";
    }
}
