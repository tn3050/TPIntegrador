#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include "unidadTipo.h"

using namespace sf;

class enemigoRojo : public unidadTipo {
public:
    enemigoRojo(Texture& texture);
};