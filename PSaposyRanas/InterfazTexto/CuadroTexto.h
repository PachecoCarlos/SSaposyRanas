#pragma once
#include "ObjetoIT.h"
#include<iostream>
#include "..\Utilitarios.h"
using namespace std;
// Desciende de ObjetoIT
class CuadroTexto : public ObjetoIT {
private:
	char bordeVerticales = '-';
	char bordeHorizontales = '|';
	string texto;
public:
	CuadroTexto(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase);
	string getTexto() { return texto; }
	void Mostrar();
};