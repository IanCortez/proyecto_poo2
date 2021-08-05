#include "Grid.h"

user::Grid::Grid() {
  std::vector<std::vector<user::Casilla*>> temp1;
  unsigned int id = 0;
  for(int i=0; i<casillas_count; ++i){
    std::vector<user::Casilla*> temp2;
    std::vector<Node*> temp_nodes;
    for(int j=0; j<casillas_count; ++j){
      // Generar vector de casillas
      auto* cuadro = new user::Casilla(gridSizeF);
      cuadro->get_rectangle().move(sf::Vector2f(gridSizeF*j, gridSizeF*i));
      cuadro->get_rectangle().setOutlineColor(sf::Color::Red);
      cuadro->get_rectangle().setOutlineThickness(5.0f);
      cuadro->get_rectangle().setFillColor(sf::Color::Cyan);
      temp2.push_back(cuadro);

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
    temp1.push_back(temp2);
  }
  casillas = std::move(temp1);

  // Settear nodos adyacentes para cada nodo en la grafica
  for(int x=0; x<casillas_count; ++x){
    for(int y=0; y<casillas_count; ++y){
      // Conexiones sin diagonales adyacentes
      if(y > 0) {
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(reinterpret_cast<Node *>(&nodos[y - 1][x + 0]));
      }
      if(y < casillas_count - 1){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(reinterpret_cast<Node *>(&nodos[y + 1][x + 0]));
      }
      if(x > 0){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(reinterpret_cast<Node *>(&nodos[y + 0][x - 1]));
      }
      if(x < casillas_count - 1){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(reinterpret_cast<Node *>(&nodos[y + 0][x + 1]));
      }

      // Con adyacentes
      /*
      if(y > 0 && x>0){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(reinterpret_cast<Node *>(&nodos[y - 1][x - 1]));
      }
      if(y < casillas_count-1 && x > 0){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(reinterpret_cast<Node *>(&nodos[y + 1][x - 1]));
      }
      if(y > 0 && x < casillas_count-1){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(reinterpret_cast<Node *>(&nodos[y - 1][x + 1]));
      }
      if(y < casillas_count-1 && x < casillas_count-1){
        auto& temp = (nodos[y][x]->adjacents);
        temp.push_back(reinterpret_cast<Node *>(&nodos[y + 1][x + 1]));
      }
       */
    }
  }
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