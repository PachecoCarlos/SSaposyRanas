#include "CuadroTexto.h"

CuadroTexto::CuadroTexto(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase) :
	ObjetoIT(_x, _y, _ancho, 3, _colorFondoBase, _colorCaracterBase, _caracterBase) {
	texto = "";
}
// Muestra un marco donde se añade texto
void CuadroTexto::Mostrar() {
	Coordenada2D c;
	for (int i = 0; i < 1; i++) {
		for (int j = i; j < ObjetoIT::getAncho() - i; j++) {
			c.x = ObjetoIT::getX() + j;
			c.y = ObjetoIT::getY() + i;
			gotoxy(c.x, c.y);
			cout << bordeVerticales << endl;
			c.x = ObjetoIT::getX() + j;
			c.y = ObjetoIT::getY() + ObjetoIT::getAlto() - i - 1;
			gotoxy(c.x, c.y);
			cout << bordeVerticales << endl;
		}

		for (int k = i; k < ObjetoIT::getAlto() - i - 2; k++) {
			c.x = ObjetoIT::getX() + i;
			c.y = ObjetoIT::getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << bordeHorizontales << endl;

			c.x = ObjetoIT::getX() + ObjetoIT::getAncho() - i - 1;
			c.y = ObjetoIT::getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << bordeHorizontales << endl;
		}
	}
	gotoxy(ObjetoIT::getX(), ObjetoIT::getY() - 1);
	cout << "Introduzca su Nombre:" << endl;
	do {
		for (int i = 1; i < ObjetoIT::getAncho() - 1; i++) {
			gotoxy(ObjetoIT::getX() + i, ObjetoIT::getY() + 1);
			cout << " ";
		}
		gotoxy(ObjetoIT::getX() + 1, ObjetoIT::getY() + 1);
		cin >> texto;
	} while (texto.length() > 10);
}