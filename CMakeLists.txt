cmake_minimum_required(VERSION 3.19)
project(Projecto_poo2)
set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS system window graphics)


add_executable(ProyectoPOO_2 main.cpp Librerias.h Casilla.cpp Casilla.h Ventana.cpp Ventana.h Grid.cpp Grid.h)
target_link_libraries(ProyectoPOO_2 sfml-system sfml-window sfml-graphics -static)