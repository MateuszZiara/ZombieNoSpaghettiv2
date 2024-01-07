/**
 * @file SoundEffects.h
 * @brief Deklaracja klasy SoundEffects.
 */

#ifndef ZOMBIENOSPAGHETTI_MUSIC_H
#define ZOMBIENOSPAGHETTI_MUSIC_H

#include <SFML/Audio.hpp>
#include <map>

/**
 * @class SoundEffects
 * @brief Zarządza efektami dźwiękowymi i muzyką w grze.
 */
class SoundEffects {
public:
    sf::Music music; /**< Reprezentuje odtwarzacz muzyki. */
    std::map<int, std::string> soundsContainer; /**< Zawiera efekty dźwiękowe przypisane do kluczy całkowitych. */

public:
    /**
     * @brief Konstruktor domyślny klasy SoundEffects.
     */
    SoundEffects();

    /**
     * @brief Dodaje efekt dźwiękowy do kontenera.
     * @param key Klucz przypisujący efekt dźwiękowy.
     * @param value Ścieżka do pliku efektu dźwiękowego.
     */
    void addToContainer(int key, const std::string& value);

    /**
     * @brief Odtwarza muzykę na podstawie podanego klucza.
     * @param value Klucz związany z pożądaną muzyką.
     */
    void playMusic(int value);

    /**
     * @brief Zatrzymuje aktualnie odtwarzaną muzykę.
     */
    void stopMusic();

    /**
     * @brief Odtwarza efekt dźwiękowy na podstawie podanego klucza.
     * @param value Klucz związany z pożądanym efektem dźwiękowym.
     */
    void makeSound(int value);
};

#endif //ZOMBIENOSPAGHETTI_MUSIC_H