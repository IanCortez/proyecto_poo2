#pragma once

#include "Librerias.h"

namespace user {
    class Casilla {
    private:
        sf::RectangleShape rectangle;

    public:
        Casilla() = default;
        explicit Casilla(float squareSize);
        sf::RectangleShape& get_rectangle();
    };
}