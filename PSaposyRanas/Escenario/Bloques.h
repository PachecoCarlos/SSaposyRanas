#pragma once
#include "Objetos.h"

class Bloques : public Objetos {

public:
	//Constructor de la clase
	Bloques(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc) :
		Objetos(_x, _y, _ancho, _alto, _caracter, _colorFondo, _colorCaracter, _mc) {}

	//Metodos heredados y redefinidos de la clase Objetos
	void Mostrar();
};

