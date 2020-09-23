#pragma once
#include "Actor.h"

//Aplicamos herencia donde la clase padre es actor
class Tortuga :
    public Actor
{
public:
    //Constructor de la clase
    Tortuga(vector<string> _avatar, int _x, int _y, int _dx, int _dy,
        int _colorCaracter, int _colorFondo, MapaElementosPantalla* m);
    //Sobrecarga obligatorio de metodo de la clase padre
    int dano() { return 0; }
};

