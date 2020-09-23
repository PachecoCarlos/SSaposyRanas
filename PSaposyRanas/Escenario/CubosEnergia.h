#pragma once
#include "Objetos.h"
class CubosEnergia :
	public Objetos
{
private:

	//Variables adicionales
	int cantidadEnergia;
	int tipoEnergia;
public:

	//Constructor de la clase
	CubosEnergia(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc, int _cantidadEnergia, int _tipoEnergia) :
		Objetos(_x, _y, _ancho, _alto, _caracter, _colorFondo, _colorCaracter, _mc) {
		cantidadEnergia = _cantidadEnergia;
		tipoEnergia = _tipoEnergia;
	}

	//Metodos heredados y redefinidos de la clase Objetos
	void Mostrar();
};

