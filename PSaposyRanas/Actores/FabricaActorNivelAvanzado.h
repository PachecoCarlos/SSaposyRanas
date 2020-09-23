#pragma once
#include "FabricaActor.h"

//clase hija que hereda de la clase padre fabricaActor relacionados que tienen un funcionamiento en comun(aplicando el patron Abstrac Fatory) 
class FabricaActorNivelAvanzado :public FabricaActor {
private:

    //Atributos privados propios de la clase estaticos
    static int NumeroEnemigosA1;
    static int NumeroEnemigosA2;
    static int NumeroEnemigosA3;
    static int NumeroEnemigosA4;
    static int NumeroEnemigosA5;
public:

    //Sobrecarga de metodos de la clase padre obligatorio 
    Actor* CrearSapo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearCocodrilo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearAuto1(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearAuto2(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearTortuga(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
    Actor* CrearTronco(int _x, int _y, int _dx, int _dy, MapaElementosPantalla* m);
};