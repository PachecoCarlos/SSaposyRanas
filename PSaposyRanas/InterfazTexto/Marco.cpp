#include "Marco.h"
#include <iostream>
#include "..\Utilitarios.h"

using namespace std;

Marco::Marco(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase, int _borde,
	int _colorFondoBorde, int _colorCaracterBorde, char _caracterBordeHorizontal, char _caracterBordeVertical) :
	ObjetoIT(_x, _y, _ancho, _alto, _colorFondoBase, _colorCaracterBase, _caracterBase), borde(_borde),
	colorFondoBorde(_colorFondoBorde), colorCaracterBorde(_colorCaracterBorde), caracterBordeHorizontal(_caracterBordeHorizontal),
	caracterBordeVertical(_caracterBordeVertical)
{
	titulo = "";
	contenido = "";
}
//Genera los bordes del marco
void Marco::GenerarBordes() {
	Coordenada2D c;
	EstablecerColor(colorCaracterBorde, colorFondoBorde);
	for (int i = 0; i < borde; i++) {
		for (int j = i; j < ObjetoIT::getAncho() - i; j++) {
			c.x = ObjetoIT::getX() + j;
			c.y = ObjetoIT::getY() + i;
			gotoxy(c.x, c.y);
			cout << caracterBordeVertical << endl;
			c.x = ObjetoIT::getX() + j;
			c.y = ObjetoIT::getY() + ObjetoIT::getAlto() - i - 1;
			gotoxy(c.x, c.y);
			cout << caracterBordeVertical << endl;
		}

		for (int k = i; k < ObjetoIT::getAlto() - i - 2; k++)
		{
			c.x = ObjetoIT::getX() + i;
			c.y = ObjetoIT::getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << caracterBordeHorizontal << endl;

			c.x = ObjetoIT::getX() + ObjetoIT::getAncho() - i - 1;
			c.y = ObjetoIT::getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << caracterBordeHorizontal << endl;
		}
	}
	if (titulo.empty()) {
		gotoxy(ObjetoIT::getX(), ObjetoIT::getY());
		cout << char(201);
	}
	else {
		gotoxy(ObjetoIT::getX(), ObjetoIT::getY());
		cout << titulo;
	}
	gotoxy(ObjetoIT::getX() + ObjetoIT::getAncho() - 1, ObjetoIT::getY());
	cout << char(187);
	gotoxy(ObjetoIT::getX(), ObjetoIT::getY() + ObjetoIT::getAlto() - 1);
	cout << char(200);
	gotoxy(ObjetoIT::getX() + ObjetoIT::getAncho() - 1, ObjetoIT::getY() + ObjetoIT::getAlto() - 1);
	cout << char(188);
}
// Genera un fondo donde tambien se incluira texto
void Marco::GenerarFondo()
{
	Coordenada2D c;
	EstablecerColor(ObjetoIT::getColorFondoBase(), ObjetoIT::getColorCaracterBase());
	for (int i = 0; i < ObjetoIT::getAncho(); i++) {
		for (int j = 0; j < ObjetoIT::getAlto(); j++) {
			gotoxy(ObjetoIT::getX() + i, ObjetoIT::getY() + j);
			cout << ObjetoIT::getCaracterBase() << endl;
		}
	}

	int largoTexto = contenido.length();
	if (largoTexto > ObjetoIT::getAncho()) {
		int lineas = 0;
		while (largoTexto > ObjetoIT::getAncho()) {
			largoTexto -= ObjetoIT::getAncho();
			lineas++;
		}
		int j = 3;
		int x = 1;
		for (int i = 0; i < contenido.length(); i++) {
			if (j > ObjetoIT::getAncho() - 8) {

				gotoxy(ObjetoIT::getX() + j, (ObjetoIT::getY() + ObjetoIT::getAlto() / 2) - lineas + x);
				cout << contenido[i];
				j = 3;
				x++;
			}
			else {
				gotoxy(ObjetoIT::getX() + j, (ObjetoIT::getY() + ObjetoIT::getAlto() / 2) - lineas + x);
				cout << contenido[i];
				j++;
			}
		}
	}
	else {
		int xTexto = ObjetoIT::getX() + (ObjetoIT::getAncho() - largoTexto) / 2;
		int yTexto = ObjetoIT::getY() + ObjetoIT::getAlto() / 2;
		gotoxy(xTexto, yTexto);
		cout << contenido << endl;
	}
}



void Marco::Mostrar()
{
	GenerarFondo();
	GenerarBordes();

	for (unsigned int i = 0; i < hijos.size(); i++)
	{
		hijos[i]->Mostrar();
	}
}