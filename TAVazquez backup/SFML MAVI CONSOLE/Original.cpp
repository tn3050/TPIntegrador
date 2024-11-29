//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
using namespace sf;


class Puntaje {
private:
    Font fuente;
    int puntos = 0;
    Text puntajeT;
public:
        Puntaje(Font& newFont) {
        fuente = newFont;
        puntajeT.setFont(fuente);
        puntajeT.setPosition(720, 650);
        puntajeT.setCharacterSize(30);
        puntajeT.setFillColor(Color::Black);
    };
        void posicion(int a) {
            switch (a) {
            case 1:
                puntajeT.setPosition(200, 645);
                break;
            case 2:
                puntajeT.setPosition(400, 400);
                break;
            };
        };
        void actualizarPuntaje() {
            puntajeT.setString(std::to_string(puntos));
        };

        void Dibujar(RenderWindow& App) {
            App.draw(puntajeT);
        };
        void SumaPuntaje(int valor) {
            puntos += valor;
        };
        void restaPuntaje(int valor) {
            puntos -= valor;
        };
    };


//Cambiar fondo
class Fondo {
private:
    Sprite fondo;
    Texture texture;
public:
    void CambiarFondo(Texture& newTexture) {
        texture = newTexture;
        fondo.setTexture(texture);
    }
    void HacerFondo(RenderWindow& App) {
        App.draw(fondo);
    }
};
//Mira
class Crosshair {
private:
    Sprite sprite;
public:
    Crosshair(Texture& texture) {
        sprite.setTexture(texture);
    }
    void posicion(Vector2i mousePos) {
        sprite.setPosition(Vector2f(mousePos));
    }
    void Dibujar(RenderWindow& App) {
        App.draw (sprite);
    }
};

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
    unidadTipo(Texture& texture) {
        sprite.setTexture(texture);
    };
    void Posicion(int spawn) {
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
    void Dibujar(RenderWindow& App) {
        if (estaActivo) {
            App.draw(sprite);
        };
    };
    void Borrar() {
        estaActivo = false;
    }
    void Reaparecer(int a,int b, int c) {
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

        }
    }
    void ReiniciarReloj() {
        clock.restart();
    };

    bool VerificarM(Vector2i mousePos) {
        return sprite.getGlobalBounds().contains(Vector2f(mousePos));
    }


};

    class aliadoVerde : public unidadTipo {
    public:
        aliadoVerde(Texture& texture) : unidadTipo(texture) {};
    };
    class enemigoRojo : public unidadTipo {
    public:
        enemigoRojo(Texture& texture) : unidadTipo(texture) {};
    };

int main()
{   
    srand(time(NULL));
    //Fondo, menu, vidas, instrucciones y gameover
    Texture MenuJ, InstruccionesJ, GameoverJ, Juegofondo, VidasT;
    MenuJ.loadFromFile("MenuJuego.png");
    InstruccionesJ.loadFromFile("JuegoInstrucciones.png");
    GameoverJ.loadFromFile("JuegoGameover.png");
    Juegofondo.loadFromFile("JuegoM.png");
    VidasT.loadFromFile("JuegoVidas3.png");
    //Crosshair, Enemigos y Aliado
    Texture crosshairT,enemigoA, enemigoB, enemigoC, aliadoA;
    crosshairT.loadFromFile("crosshair.png");
    enemigoA.loadFromFile("enemigoRojoA.png");
    enemigoB.loadFromFile("enemigoRojoB.png");
    enemigoC.loadFromFile("enemigoRojoC.png");
    aliadoA.loadFromFile("aliadoVerdeA.png");
    //Fuente
    Font fuente;
    fuente.loadFromFile("arial.ttf");
    //Test
    Sprite VidasJ;
    VidasJ.setTexture(VidasT);
    VidasJ.setPosition(550, 750);
    Fondo backgroundJuego;
    //Vidas, spawn y inocentes
    int vidas = 3;
    int spawn = 0;
    int inocentes = 0;
    //Control de inicio
    bool EmpezarJuego = false;
    //Menu
    backgroundJuego.CambiarFondo(MenuJ);
    //Mira
    Crosshair crosshair(crosshairT);
    //Puntaje
    Puntaje enemigosMuertos(fuente);
    Puntaje puntaje(fuente);
    puntaje.posicion(1);
    puntaje.actualizarPuntaje();
    enemigosMuertos.actualizarPuntaje();

    //Enemigos y aliados
    enemigoRojo Enem1(enemigoA);
    enemigoRojo Enem2(enemigoB);
    enemigoRojo Enem3(enemigoC);
    aliadoVerde Alia1(aliadoA);
    
   

    /////Creamos la ventana//////

    RenderWindow App(VideoMode(800, 800), "TP");
    //Iniciar
    bool IniciarJuego = false;
    /////Loop principal//////
    App.setMouseCursorVisible(false);
    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed) {
                App.close();
            }
            if (event.type == Event::KeyPressed) {

                if (event.key.code == Keyboard::Num1) {
                    backgroundJuego.CambiarFondo(Juegofondo);
                    EmpezarJuego = true;
                    IniciarJuego = true;
                }

                if (event.key.code == Keyboard::Num2 && !EmpezarJuego) {
                    backgroundJuego.CambiarFondo(InstruccionesJ);
                }

                if (event.key.code == Keyboard::Num3 && !EmpezarJuego) {
                    App.close();
                }

                if (event.key.code == Keyboard::Num4 && !EmpezarJuego) {
                    backgroundJuego.CambiarFondo(MenuJ);
                }
                //Test
                if (event.key.code == Keyboard::Num5) {
                    vidas--;
                    puntaje.SumaPuntaje(5);
                }
            }

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left && EmpezarJuego) {
                    if (Enem1.VerificarM(Mouse::getPosition(App)) && Enem1.estaActivo) {
                        Enem1.Borrar();
                        Enem1.ReiniciarReloj();
                        puntaje.SumaPuntaje(1);
                        enemigosMuertos.SumaPuntaje(1);
                    }
                    if (Enem2.VerificarM(Mouse::getPosition(App)) && Enem2.estaActivo) {
                        Enem2.Borrar();
                        Enem2.ReiniciarReloj();
                        puntaje.SumaPuntaje(1);
                        enemigosMuertos.SumaPuntaje(1);
                    }
                    if (Enem3.VerificarM(Mouse::getPosition(App)) && Enem3.estaActivo) {
                        Enem3.Borrar();
                        Enem3.ReiniciarReloj();
                        puntaje.SumaPuntaje(1);
                        enemigosMuertos.SumaPuntaje(1);
                    }
                    if (Alia1.VerificarM(Mouse::getPosition(App)) && Alia1.estaActivo) {
                        Alia1.Borrar();
                        Alia1.ReiniciarReloj();
                        puntaje.SumaPuntaje(0);
                        inocentes++;
                        vidas--;
                    }
                }
            }
        }
        if (EmpezarJuego) {
            Enem1.Reaparecer(Enem2.Ocupar,Enem3.Ocupar,Alia1.Ocupar);
            Enem2.Reaparecer(Enem1.Ocupar, Enem3.Ocupar, Alia1.Ocupar);
            Enem3.Reaparecer(Enem1.Ocupar, Enem2.Ocupar, Alia1.Ocupar);
            Alia1.Reaparecer(Enem1.Ocupar,Enem2.Ocupar, Enem3.Ocupar);
        };
        if (Enem1.estaActivo && Enem1.clock.getElapsedTime().asSeconds() >= 3.9f && EmpezarJuego) {
            --vidas;
            Enem1.Borrar();
        };
        if (Enem2.estaActivo && Enem2.clock.getElapsedTime().asSeconds() >= 3.9f && EmpezarJuego) {
            --vidas;
            Enem2.Borrar();
        };
        if (Enem3.estaActivo && Enem3.clock.getElapsedTime().asSeconds() >= 3.9f && EmpezarJuego) {
            --vidas;
            Enem3.Borrar();
        };
        //Gameover
        if (vidas <= 0) {
            backgroundJuego.CambiarFondo(GameoverJ);
            inocentes = inocentes * 2;
            puntaje.restaPuntaje(inocentes);
            puntaje.actualizarPuntaje();
            puntaje.posicion(2);
            EmpezarJuego = false;
            while (App.isOpen()) {
                Event event2;
                while (App.pollEvent(event2)) {
                    if (event2.type == Event::Closed || (event2.type == Event::KeyPressed)) {
                        App.close();
                    }
                }
                App.clear(Color::White);
                backgroundJuego.HacerFondo(App);
                puntaje.Dibujar(App);
                App.display();
            } break;
        }
        if (vidas == 2) {
            VidasT.loadFromFile("JuegoVidas2.png");
        };
        if (vidas == 1) {
            VidasT.loadFromFile("JuegoVidas1.png");
        };

        
            crosshair.posicion(Mouse::getPosition(App));
            puntaje.actualizarPuntaje();
            enemigosMuertos.actualizarPuntaje();
            App.clear(Color::White);
            backgroundJuego.HacerFondo(App);
            if (IniciarJuego) {
                Enem1.Dibujar(App);
                Enem2.Dibujar(App);
                Enem3.Dibujar(App);
                Alia1.Dibujar(App);
                App.draw(VidasJ);
                enemigosMuertos.Dibujar(App);
                puntaje.Dibujar(App);
            };
            crosshair.Dibujar(App);
            App.display();
        

 }
 return 0;
}