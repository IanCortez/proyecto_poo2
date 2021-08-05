#pragma once

#include "Librerias.h"
#include "Grid.h"

namespace user {
    class Ventana {
    private:
        const long window_width = 800;
        const long window_height = 800;
        sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(window_width, window_height), "A* Pathfinding");
        user::Grid grid = user::Grid();

    public:
        Ventana() = default;
        sf::RenderWindow& get_OpenWindow();
        void start();
        void solve_Astar();
    };
}