#include "Fondo.h"


void Fondo::CambiarFondo(Texture& newTexture) {
    texture = newTexture;
    fondo.setTexture(texture);
};
void Fondo::HacerFondo(RenderWindow& App) {
    App.draw(fondo);
};