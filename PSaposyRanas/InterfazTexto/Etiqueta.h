#pragma once
#include "ComponenteIT.h"
#include<iostream>
#include "..\Utilitarios.h"

using namespace std;
// Desciende de componente
class Etiqueta :
    public ComponenteIT
{
private:
    string texto;
public:
    Etiqueta(string _texto, int _x, int _y);
    void Mostrar();

    void setTexto(string _texto) { texto = _texto; }
    string getTexto() { return texto; }
};

