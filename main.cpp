#include "Librerias.h"
#include "Ventana.h"


int main() {
  user::Ventana* ventana;
  ventana = new user::Ventana();

  ventana->start();

  return 0;
}
