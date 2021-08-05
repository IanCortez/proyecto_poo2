#pragma once

// STL includes
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
// SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
/* -- NO USAR NAMESPACES -- */


struct Node {
    // Identifiers
    bool is_start = false;
    bool is_objective = false;
    bool is_visited = false;
    bool is_obstacle = false;
    bool correct_route = false;
    unsigned int node_id{};

    // Posicion en cuadricula
    int x{};
    int y{};

    // Pesos (distancias) a nivel local (distancia recorrida hasta el momento) y global (menor distancia recorrida
    // hasta el momento)
    float global_goal{};
    float local_goal{};

    // Nodos adyacentes y padre
    std::vector<Node*> adjacents;
    Node* parent = nullptr;

    Node() = default;
};
