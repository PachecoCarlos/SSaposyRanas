#pragma once
#include "ActorMovimiento.h"
class ActorMovimientoAleatorio :
    //Heredamos los metodos publicos de la clase ActorMovimientoAleatorio
    public ActorMovimiento {
public:
    ActorMovimientoAleatorio(vector<string>* _avatar, int* _x, int* _y, int* _dx, int* _dy,
        int* _colorCaracter, int* _colorFondo, MapaElementosPantalla* _mce);

    void Mostrar();
    void Mover();

};