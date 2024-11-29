#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace sf;

class Crosshair {
private:
    Sprite sprite;
public:
    Crosshair(Texture& texture);
    void posicion(Vector2i mousePos);
    void Dibujar(RenderWindow& App);
};