#pragma once
#include "Potenciadores.h"
class PotenciadoresContretosTipo2 :
    public Potenciadores
{
public:
    PotenciadoresContretosTipo2(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc,
        int _velocidad, int _salto, int _energia, int _escudo, int _vidas);
    Potenciadores* Clonar();
};

