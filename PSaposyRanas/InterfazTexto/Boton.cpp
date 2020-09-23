#include "Boton.h"

Boton::Boton(string _texto, int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase) :
	ComponenteIT(_x, _y, _ancho, _alto, _colorFondoBase, _colorCaracterBase, _caracterBase), texto(_texto)
{
}

void Boton::Mostrar()
{
	if (getSeleccionado()) {
		EstablecerColor(15, 0);
	}
	else {
		EstablecerColor(getColorFondoBase(), getColorCaracterBase());
	}
	// para mostar el caracter
	for (int i = 0; i < getAncho(); i++) {
		for (int j = 0; j < getAlto(); j++) {

			gotoxy(getX() + i, getY() + j);
			cout << getCaracterBase() << endl;
		}
	}
	// para imprimir el texto en la mitad del boton
	int largoTexto = texto.length();
	int xTexto = getX() + (getAncho() - largoTexto) / 2;
	int yTexto = getY() + getAlto() / 2;
	gotoxy(xTexto, yTexto);
	cout << texto << endl;
}