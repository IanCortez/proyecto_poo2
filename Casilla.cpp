//
// Created by Ian on 3/08/2021.
//

#include "Casilla.h"

user::Casilla::Casilla(float squareSize) {
  rectangle = sf::RectangleShape(sf::Vector2f(squareSize, squareSize));
}

sf::RectangleShape& user::Casilla::get_rectangle() {
  return this->rectangle;
}

