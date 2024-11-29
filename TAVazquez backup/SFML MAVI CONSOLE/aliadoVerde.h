#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include "unidadTipo.h"

using namespace sf;

class aliadoVerde : public unidadTipo {
public:
    aliadoVerde(Texture& texture);
};