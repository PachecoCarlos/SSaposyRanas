#pragma once
#include "Potenciadores.h"
class PotenciadoresContretosTipo1 :
    public Potenciadores
{
private:
    int radioEnergia;
public:
    PotenciadoresContretosTipo1(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc,
        int _velocidad, int _salto, int _energia, int _escudo, int _vidas);
    Potenciadores* Clonar();

    int getRadioEnergia() { return radioEnergia; }
    void setRadioEnergia(int _radioEnergia) { radioEnergia = _radioEnergia; }

};

