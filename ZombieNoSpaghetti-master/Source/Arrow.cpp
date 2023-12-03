//
// Created by coons on 14.11.2023.
//

#include "../Header/Arrow.h"

/**
 * @brief Przesuwa strzałę w zależności od jej kierunku.
 *
 * Metoda przesuwa pozycję strzały w zależności od ustawionego kierunku.
 * Kierunki to: 0 - prawo, 1 - lewo, 2 - dół, 3 - góra.
 */

void Arrow::move() {
    if(direction == 0) {
        arrowShape.move(5, 0);
    }
    else if(direction == 1)
        arrowShape.move(-5,0);
    else if(direction == 2)
        arrowShape.move(0,5);
    else
        arrowShape.move(0,-5);
}