#include "Crosshair.h"


Crosshair::Crosshair(Texture& texture) {
    sprite.setTexture(texture);
};
    void Crosshair::posicion(Vector2i mousePos) {
        sprite.setPosition(Vector2f(mousePos));
    };
    void Crosshair::Dibujar(RenderWindow& App) {
        App.draw(sprite);
    };
