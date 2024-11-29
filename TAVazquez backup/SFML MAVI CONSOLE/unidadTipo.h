#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace sf;

class unidadTipo {
protected:
    Sprite sprite;
    bool EsClickeado = false;
    float tiempodeReaparicion = 4.0f;
    int tiempoPasado = 0;
public:
    Clock clock;
    int Ocupar = 0;
    bool estaActivo = false;
    unidadTipo(Texture& texture);
    void Posicion(int spawn);
    void Dibujar(RenderWindow& App);
    void Borrar();
    void Reaparecer(int a, int b, int c);
    void ReiniciarReloj();
    bool VerificarM(Vector2i mousePos);


};
