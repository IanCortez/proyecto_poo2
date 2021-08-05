#include "Ventana.h"

sf::RenderWindow& user::Ventana::get_OpenWindow() {
  return this->window;
}


void user::Ventana::start() {
  // Ejecucion del programa
  sf::Vector2i mousePosWindow;
  sf::Vector2i mousePosGrid;

  while(window.isOpen()){
    sf::Event event{};

    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed) window.close();

    }

    // Render
    window.clear();

    // Get the node position where the mouse was clicked
    mousePosWindow = sf::Mouse::getPosition(window);
    if(mousePosWindow.x >= 0.0f) mousePosGrid.x = mousePosWindow.x / grid.get_gridSize();
    if(mousePosWindow.y >= 0.0f) mousePosGrid.y = mousePosWindow.y / grid.get_gridSize();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      if(mousePosGrid.x >= 0 && mousePosGrid.x < window_width){
        if(mousePosGrid.y >= 0 && mousePosGrid.y < window_height){
          grid.get_nodos()[mousePosGrid.y][mousePosGrid.x]->is_obstacle = true;
        }
      }
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
      if(mousePosGrid.x >= 0 && mousePosGrid.x < window_width){
        if(mousePosGrid.y >= 0 && mousePosGrid.y < window_height){
          grid.get_nodos()[mousePosGrid.y][mousePosGrid.x]->is_obstacle = false;
        }
      }
    }

    // Generar inicio en el mapa
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
      if(mousePosGrid.x >= 0 && mousePosGrid.x < window_width){
        if(mousePosGrid.y >= 0 && mousePosGrid.y < window_height){
          grid.get_nodos()[mousePosGrid.y][mousePosGrid.x]->is_start =
                  !grid.get_nodos()[mousePosGrid.y][mousePosGrid.x]->is_start;
        }
      }
    }

    // Generar la meta en el mapa
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      if(mousePosGrid.x >= 0 && mousePosGrid.x < window_width){
        if(mousePosGrid.y >= 0 && mousePosGrid.y < window_height){
          grid.get_nodos()[mousePosGrid.y][mousePosGrid.x]->is_objective =
                  !grid.get_nodos()[mousePosGrid.y][mousePosGrid.x]->is_objective;
        }
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      grid = user::Grid();
    }

    // Ejecutar el algoritmo de pathfinding
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
      solve_Astar();
    }


    // Dibujar cada rectangulo de la cuadricula
    for(auto i=0; i<grid.get_casillas_count(); ++i){
      for(auto j=0; j<grid.get_casillas_count(); ++j){
        if(grid.get_nodos()[j][i]->is_objective) grid.get_casillas()[j][i]->get_rectangle().setFillColor(sf::Color::Red);

        else if(grid.get_nodos()[j][i]->is_start) grid.get_casillas()[j][i]->get_rectangle().setFillColor(sf::Color::Yellow);

        else if(grid.get_nodos()[j][i]->is_obstacle) grid.get_casillas()[j][i]->get_rectangle().setFillColor(sf::Color::Green);

        else if(grid.get_nodos()[j][i]->is_visited) {
          if(grid.get_nodos()[j][i]->correct_route)
            grid.get_casillas()[j][i]->get_rectangle().setFillColor(sf::Color::White);
          else grid.get_casillas()[j][i]->get_rectangle().setFillColor(sf::Color::Black);
        }

        else grid.get_casillas()[j][i]->get_rectangle().setFillColor(sf::Color::Cyan);
      }
    }

    for(auto& sub1: grid.get_casillas()){
      for(auto& casilla: sub1){
        window.draw(casilla->get_rectangle());
      }
    }

    window.display();
  }
}


// Algoritmo
void user::Ventana::solve_Astar() {
  // Poner la distancia a los demas nodos, como infinito
  for(int i=0; i<grid.get_casillas_count(); ++i){
    for(int j=0; j<grid.get_casillas_count(); ++j){
      grid.get_nodos()[j][i]->local_goal = INFINITY;
      grid.get_nodos()[j][i]->global_goal = INFINITY;
    }
  }

  // Distancia mediante el teorema de pitagoras
  auto distance = [](Node* a, Node* b){
    auto dx = abs(a->x - b->x);
    auto dy = abs(a->y - b->y);
    auto h = (dx + dy) + (sqrt(2)-2)*fmin(dx,dy);
    return h;
  };
  // Distancia entre nodos, global siendo el valor total del recorrido
  auto heuristic = [distance](Node* a, Node* b){
    return distance(a, b);
  };

  Node* nodo_inicio = nullptr;
  Node* nodo_final = nullptr;
  for(auto& fila: grid.get_nodos()){
    for(auto& c: fila){
      if (c->is_start) nodo_inicio = c;
      if (c->is_objective) nodo_final = c;
    }
  }
  nodo_inicio->local_goal = 0.0f;
  nodo_inicio->global_goal = heuristic(nodo_inicio, nodo_final);
  auto& nodo_actual = nodo_inicio;

  std::list<Node*> nodesNotTestedList;
  nodesNotTestedList.push_back(nodo_inicio);

  while (!nodesNotTestedList.empty() && nodo_actual != nodo_final){
    nodesNotTestedList.sort([](const Node* lower, const Node* upper){
      return lower->global_goal < upper->global_goal;
    });

    while (!nodesNotTestedList.empty() && nodesNotTestedList.front()->is_visited){
      nodesNotTestedList.pop_front();
    }

    if(nodesNotTestedList.empty()) break;

    nodo_actual = nodesNotTestedList.front();
    nodo_actual->is_visited = true; // Solo visitar un nodo una vez

    for(auto& vecino: nodo_actual->adjacents){
      if(!vecino->is_visited && !vecino->is_obstacle) nodesNotTestedList.push_back(vecino);

      float possible_current_local_goal = nodo_actual->local_goal + distance(nodo_actual, vecino);
      if(possible_current_local_goal < vecino->local_goal){
        vecino->parent = nodo_actual;
        vecino->local_goal = possible_current_local_goal;

        vecino->global_goal = vecino->local_goal + heuristic(nodo_actual, nodo_final);
      }
    }
  }

  auto& p = nodo_final;
  while(p->parent != nullptr){
    p->correct_route = true;
    p = p->parent;
  }
}
