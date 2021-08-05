#include "Grid.h"

user::Grid::Grid() {
  unsigned int id = 0;
  for(int i=0; i<casillas_count; ++i){
    std::vector<user::Casilla*> temp;
    std::vector<Node*> temp_nodes;
    for(int j=0; j<casillas_count; ++j){
      // Generar vector de casillas
      auto cuadro = new user::Casilla(gridSizeF); // generar un puntero a la casilla
      cuadro->get_rectangle().move(sf::Vector2f(gridSizeF*j, gridSizeF*i)); // desplazar la cuadricula
      cuadro->get_rectangle().setOutlineColor(sf::Color::Red);  // Color de las separaciones de las cuadriculas
      cuadro->get_rectangle().setOutlineThickness(5.0f);  // Separaciones de las cuadriculas
      cuadro->get_rectangle().setFillColor(sf::Color::Cyan);  // Color de las cuadriculas
      temp.push_back(cuadro);

      // Generar vector de nodos
      // Posible error desde esta parte
      auto node = new Node();
      node->node_id = id;
      node->x = j;
      node->y = i;
      temp_nodes.push_back(node);

      ++id;
    }
    nodos.push_back(temp_nodes);
    casillas.push_back(temp);
  }

  // Settear nodos adyacentes para cada nodo en la grafica
  for(int x=0; x<casillas_count; ++x){
    for(int y=0; y<casillas_count; ++y){
      // Conexiones sin diagonales adyacentes
      if(y > 0) {
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(nodos[y - 1][x + 0]);
      }
      if(y < casillas_count - 1){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(nodos[y + 1][x + 0]);
      }
      if(x > 0){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(nodos[y + 0][x - 1]);
      }
      if(x < casillas_count - 1){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(nodos[y + 0][x + 1]);
      }

      if(y > 0 && x>0){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(nodos[y - 1][x - 1]);
      }
      if(y < casillas_count-1 && x > 0){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(nodos[y + 1][x - 1]);
      }
      if(y > 0 && x < casillas_count-1){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(nodos[y - 1][x + 1]);
      }
      if(y < casillas_count-1 && x < casillas_count-1){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(nodos[y + 1][x + 1]);
      }
    }
  }
}

user::Grid& user::Grid::operator=(const user::Grid& grid){
  if(this == &grid) return *this;
  casillas = grid.casillas;
  nodos = grid.nodos;
}

std::vector<std::vector<user::Casilla*>>& user::Grid::get_casillas() {
  return this->casillas;
}

std::vector<std::vector<Node*>>& user::Grid::get_nodos() {
  return this->nodos;
}

float user::Grid::get_gridSize() const {
  return gridSizeF;
}

unsigned int user::Grid::get_casillas_count(){
  return casillas_count;
}