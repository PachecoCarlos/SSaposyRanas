#include "Objetos.h"
#include "Espinas.h"
#include "Bloques.h"
#include "CubosEnergia.h"

int Objetos::numeroObjetos = 0;

//Metodo para obtener el numero de objetos creados
int Objetos::getNumeroObjetos()
{
	return numeroObjetos;
}

//Constructor de la clase
Objetos::Objetos(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc) {
	numeroObjetos++;
	numero = numeroObjetos;
	nombre = "";
	x = _x;
	y = _y;
	ancho = _ancho;
	alto = _alto;
	caracter = _caracter;
	colorFondo = _colorFondo;
	colorCaracter = _colorCaracter;

	mapeado = _mc;
	mapaElementosPantalla = new map<int, ElementoPantalla>;
}

//Metodo del patron factory Method para crear objetos en base al tipo que se pedia
//Objetos* Objetos::getObjeto(string _tipoObjeto, int _x, int _y, int _ancho, int _alto){
//	if (_tipoObjeto == "Espina")
//		return new Espinas(_x, _y, _ancho, _alto, 'X', 0);
//	else if (_tipoObjeto == "Bloque")
//		return new Bloques(_x, _y, _ancho, _ancho, '#', 0, 0);
//	else if (_tipoObjeto == "CuboEnergia")
//		return new CubosEnergia(_x, _y, _ancho, _alto, '@', 5, 1);
//	else
//		return NULL;
//}
