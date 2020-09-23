#pragma once
#include "Objetos.h"
class Potenciadores :
    public Objetos
{
private:
    string tipo;
    int velocidad;
    int salto;
    int energia;
    int escudo;
    int vidas;
public:
    //Constructor
    Potenciadores(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc,
        int _velocidad, int _salto, int _energia, int _escudo, int _vidas);
    //acorde al patron prototype, debemos crear un metodo de tipo virtual y abstracto para poder clorar
    virtual Potenciadores* Clonar() = 0;
    void Mostrar();

    //Metodos accesores
    string getTipo() { return tipo; }
    int getVelocidad() { return velocidad; }
    int getSalto() { return salto; }
    int getEnergia() { return energia; }
    int getEscudo() { return escudo; }
    int getVidas() { return vidas; }

    void setTipo(string _tipo) { tipo = _tipo; }
    void setVelocidad(int _velocidad) { velocidad = _velocidad; }
    void setSalto(int _salto) { salto = _salto; }
    void setEnergia(int _energia) { energia = _energia; }
    void setEscudo(int _escudo) { escudo = _escudo; }
    void setVidas(int _vidas) { vidas = _vidas; }
};

