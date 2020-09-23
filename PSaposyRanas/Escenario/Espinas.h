#pragma once
#include "Objetos.h"
class Espinas : public Objetos {
public:
	Espinas(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc) :
		Objetos(_x, _y, _ancho, _alto, _caracter, _colorFondo, _colorCaracter, _mc) {}
	void Mostrar();
};