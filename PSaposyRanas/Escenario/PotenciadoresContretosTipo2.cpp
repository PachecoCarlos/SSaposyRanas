#include "PotenciadoresContretosTipo2.h"

PotenciadoresContretosTipo2::PotenciadoresContretosTipo2(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc,
	int _velocidad, int _salto, int _energia, int _escudo, int _vidas) :Potenciadores(_x, _y, _ancho, _alto, _caracter, _colorFondo, _colorCaracter, _mc, _velocidad, _salto, _energia, _escudo, _vidas)

{
	setTipo("PotenciadorTipo2");
}

Potenciadores* PotenciadoresContretosTipo2::Clonar()
{
	return new PotenciadoresContretosTipo2(*this);
}