#include "PotenciadoresContretosTipo1.h"

//Constructor
PotenciadoresContretosTipo1::PotenciadoresContretosTipo1(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc,
	int _velocidad, int _salto, int _energia, int _escudo, int _vidas) :Potenciadores(_x, _y, _ancho, _alto, _caracter, _colorFondo, _colorCaracter, _mc, _velocidad, _salto, _energia, _escudo, _vidas)
{
	setTipo("PotenciadorTipo1");
}


Potenciadores* PotenciadoresContretosTipo1::Clonar()
{
	return new PotenciadoresContretosTipo1(*this);
}