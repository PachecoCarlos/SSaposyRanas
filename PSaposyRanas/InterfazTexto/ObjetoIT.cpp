#include "ObjetoIT.h"
//Constructores
ObjetoIT::ObjetoIT(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase) :
	x(_x), y(_y), ancho(_ancho), alto(_alto), colorFondoBase(_colorFondoBase), colorCaracterBase(_colorCaracterBase), caracterBase(_caracterBase)
{
	seleccionado = false;
	visible = true;
}

ObjetoIT::ObjetoIT(int _x, int _y) : x(_x), y(_y)
{
	ancho = 0;
	alto = 0;
	colorFondoBase = 0;
	colorCaracterBase = 1;
	caracterBase = ' ';
	seleccionado = false;
	visible = true;
}

void ObjetoIT::preEnter()
{
	seleccion->presEnter();
}

bool ObjetoIT::fin()
{
	return seleccion->fin();
}