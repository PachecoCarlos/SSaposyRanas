#include "Marcador.h"

Marcador::Marcador(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase, int _borde,
	int _colorFondoBorde, int _colorCaracterBorde, char _caracterBorde) :
	ObjetoIT(_x, _y, _ancho, _alto, _colorFondoBase, _colorCaracterBase, _caracterBase), borde(_borde),
	colorFondoBorde(_colorFondoBorde), colorCaracterBorde(_colorCaracterBorde), caracterBorde(_caracterBorde) {
	vidas = 0;
	puntos = 0;
	nombre = "";
}
// Genera los border del marcador
void Marcador::GenerarBordes() {
	Coordenada2D c;
	EstablecerColor(colorFondoBorde, colorCaracterBorde);
	for (int i = 0; i < borde; i++) {
		for (int j = i; j < ObjetoIT::getAncho() - i; j++) {
			c.x = ObjetoIT::getX() + j;
			c.y = ObjetoIT::getY() + i;
			gotoxy(c.x, c.y);
			cout << caracterBorde << endl;

			c.x = ObjetoIT::getX() + j;
			c.y = ObjetoIT::getY() + ObjetoIT::getAlto() - i - 1;
			gotoxy(c.x, c.y);
			cout << caracterBorde << endl;

		}

		for (int k = i; k < ObjetoIT::getAlto() - i - 2; k++) {
			c.x = ObjetoIT::getX() + i;
			c.y = ObjetoIT::getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << caracterBorde << endl;


			c.x = ObjetoIT::getX() + ObjetoIT::getAncho() - i - 1;
			c.y = ObjetoIT::getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << caracterBorde << endl;
		}
	}
}

// Genera el Fondo del marcador
void Marcador::GenerarFondo() {
	Coordenada2D c;

	EstablecerColor(ObjetoIT::getColorFondoBase(), ObjetoIT::getColorCaracterBase());

	for (int i = borde; i < ObjetoIT::getAncho() - borde; i++) {
		for (int j = borde; j < ObjetoIT::getAlto() - borde; j++) {
			c.x = ObjetoIT::getX() + i;
			c.y = ObjetoIT::getY() + j;
			gotoxy(c.x, c.y);
			cout << ObjetoIT::getCaracterBase() << endl;

		}
	}

	gotoxy(3, ObjetoIT::getY() + (ObjetoIT::getAlto() - 1) / 2);
	cout << "Nombre del Jugador: " << nombre;

	gotoxy(ObjetoIT::getAncho() / 3, ObjetoIT::getY() + (ObjetoIT::getAlto() - 1) / 2);
	cout << "Vidas del Jugador: " << vidas;
	gotoxy(ObjetoIT::getAncho() / 2 + 10, ObjetoIT::getY() + (ObjetoIT::getAlto() - 1) / 2);
	cout << "Puntos del Jugador: " << puntos;

}

void Marcador::Mostrar()
{
	GenerarFondo();
	GenerarBordes();
}