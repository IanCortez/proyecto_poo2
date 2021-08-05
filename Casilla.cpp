#include "Casilla.h"

user::Casilla::Casilla(float squareSize) {
  rectangle = sf::RectangleShape(sf::Vector2f(squareSize, squareSize));
}

sf::RectangleShape& user::Casilla::get_rectangle() {
  return this->rectangle;
}

