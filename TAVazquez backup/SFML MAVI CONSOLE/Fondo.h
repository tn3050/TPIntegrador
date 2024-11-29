#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace sf;

class Fondo {
private:
    Sprite fondo;
    Texture texture;
public:
    void CambiarFondo(Texture& newTexture);
    void HacerFondo(RenderWindow& App);
};