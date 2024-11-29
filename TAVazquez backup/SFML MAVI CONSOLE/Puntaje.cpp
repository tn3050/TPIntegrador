#include "Puntaje.h"

Puntaje::Puntaje(Font& newFont) {
    fuente = newFont;
    puntajeT.setFont(fuente);
    puntajeT.setPosition(720, 650);
    puntajeT.setCharacterSize(30);
    puntajeT.setFillColor(Color::Black);
};
void Puntaje::posicion(int a) {
    switch (a) {
    case 1:
        puntajeT.setPosition(200, 645);
        break;
    case 2:
        puntajeT.setPosition(400, 400);
        break;
    };
};
void Puntaje::actualizarPuntaje() {
    puntajeT.setString(std::to_string(puntos));
};

void Puntaje::Dibujar(RenderWindow& App) {
    App.draw(puntajeT);
};
void Puntaje::SumaPuntaje(int valor) {
    puntos += valor;
};
void Puntaje::restaPuntaje(int valor) {
    puntos -= valor;
};