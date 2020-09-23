#pragma once
#include "FabricaActor.h"

//Clase hija que hereda de la clase padre fabricaActor relacionados que tienen un funcionamiento en comun(aplicando el patron Abstrac Fatory)
class FabricaActorNivelBasico : public FabricaActor {
private:
    ////atributos privados propios de la clase estaticos
    static int NumeroEnemigosB1;
    static int NumeroEnemigosB2;
    static int NumeroEnemigosB3;
    static int NumeroEnemigosB4;
    static int NumeroEnemigosB5;

public:
    //sobrecarga de metodos de la clase padre obligatorio
    Actor* CrearSapo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);

    Actor* CrearCocodrilo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearAuto1(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearAuto2(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearTortuga(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearTronco(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
};