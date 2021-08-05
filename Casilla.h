#pragma once

#include "Librerias.h"

namespace user {
    class Casilla {
    private:
        sf::RectangleShape rectangle; // rectangulo para dibujar la casilla

    public:
        Casilla() = default;
        explicit Casilla(float squareSize);
        sf::RectangleShape& get_rectangle();
    };
}