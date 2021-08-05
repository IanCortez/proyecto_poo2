#pragma once

#include "Librerias.h"
#include "Casilla.h"


namespace user {
    class Grid {
    private:
        // Grid Size
        const float gridSizeF = 80.0f;  // tamaño de las casillas
        const unsigned gridSizeU = static_cast<unsigned>(gridSizeF);
        const unsigned int casillas_count = 10; // cantidad de casillas por fila de la cuadricula
        std::vector<std::vector<user::Casilla*>> casillas;
        std::vector<std::vector<Node*>> nodos;

    public:
        Grid();
        std::vector<std::vector<user::Casilla*>>& get_casillas();
        std::vector<std::vector<Node*>>& get_nodos();
        [[nodiscard]] float get_gridSize() const;
        [[nodiscard]] unsigned int get_casillas_count();
    };
}