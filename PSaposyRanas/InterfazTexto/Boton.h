#pragma once
#include "ComponenteIT.h"
#include<iostream>
#include "..\Utilitarios.h"

using namespace std;

class Boton :
    public ComponenteIT
{
private:
    string texto;
public:
    Boton(string texto, int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase);
    void Mostrar();
};

