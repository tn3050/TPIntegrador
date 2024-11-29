#include "unidadTipo.h"


    unidadTipo::unidadTipo(Texture& texture) {
        sprite.setTexture(texture);
    };
    void unidadTipo::Posicion(int spawn) {
        switch (spawn) {
        case 1:
            sprite.setPosition(50, 30);
            //Arriba izquierda
            break;
        case 2:
            sprite.setPosition(520, 30);
            //Arriba derecha
            break;
        case 3:
            sprite.setPosition(50, 300);
            //Abajo Izquierda
            break;
        case 4:
            sprite.setPosition(520, 300);
            //Abajo derecha
            break;
        case 5:
            sprite.setPosition(290, 350);
            //Puerta medio
            break;
        };
    };
    void unidadTipo::Dibujar(RenderWindow& App) {
        if (estaActivo) {
            App.draw(sprite);
        };
    };
    void unidadTipo::Borrar() {
        estaActivo = false;
    };
    void unidadTipo::Reaparecer(int a, int b, int c) {
        if (clock.getElapsedTime().asSeconds() >= tiempodeReaparicion) {
            clock.restart();
            estaActivo = false;
            int spawn = rand() % 5 + 1;
            while (spawn == a || spawn == b || spawn == c) {
                spawn = rand() % 5 + 1;
            };
            Ocupar = spawn;
            Posicion(spawn);
            estaActivo = true;

        };
    };
    void unidadTipo::ReiniciarReloj() {
        clock.restart();
    };

    bool unidadTipo::VerificarM(Vector2i mousePos) {
        return sprite.getGlobalBounds().contains(Vector2f(mousePos));
    };
