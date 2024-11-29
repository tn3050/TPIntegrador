#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace sf;

class Puntaje {
private:
    Font fuente;
    int puntos = 0;
    Text puntajeT;
public:
    Puntaje(Font& newFont);
    void posicion(int a);
    void actualizarPuntaje();
    void Dibujar(RenderWindow& App);
    void SumaPuntaje(int valor);
    void restaPuntaje(int valor);
};
