#include "Panel.h"
#include <iostream>
#include "..\Utilitarios.h"

using namespace std;
// Constructores
Panel::Panel() {

}
Panel::Panel(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase, int _borde,
	int _colorFondoBorde, int _colorCaracterBorde, char _caracterBorde) :
	ObjetoIT(_x, _y, _ancho, _alto, _colorFondoBase, _colorCaracterBase, _caracterBase), borde(_borde),
	colorFondoBorde(_colorFondoBorde), colorCaracterBorde(_colorCaracterBorde), caracterBorde(_caracterBorde)
{
	anchoPantalla = 120;
	caracterBorde = _caracterBorde;
	borde = _borde;
	mapeado = new MapaElementosPantalla(120, 28);
	mapaElementosPantalla = new map<int, ElementoPantalla>;
}

Panel::Panel(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase, int _anchoPantalla,
	char _caracterBorde, int _borde, MapaElementosPantalla* _mapeado) :ObjetoIT(_x, _y, _ancho, _alto, _colorFondoBase, _colorCaracterBase, _caracterBase) {
	anchoPantalla = _anchoPantalla;
	caracterBorde = _caracterBorde;
	borde = _borde;
	mapeado = _mapeado;
	mapaElementosPantalla = new map<int, ElementoPantalla>;
}
// Realiza los Bordes del panel
void Panel::GenerarBordes() {
	Coordenada2D c;
	int llave;

	ElementoPantalla elementoPantallaActual;

	elementoPantallaActual.caracter = caracterBorde;
	elementoPantallaActual.colorCaracter = colorCaracterBorde;
	elementoPantallaActual.colorFondo = colorFondoBorde;
	EstablecerColor(colorCaracterBorde, colorFondoBorde);

	for (int i = 0; i < borde; i++) {
		for (int j = i; j < ObjetoIT::getAncho() - i; j++) {
			c.x = ObjetoIT::getX() + j;
			c.y = ObjetoIT::getY() + i;
			gotoxy(c.x, c.y);
			cout << caracterBorde << endl;

			llave = Coordenada2DALlave(c, anchoPantalla);
			elementoPantallaActual.x = c.x;
			elementoPantallaActual.y = c.y;
			mapaElementosPantalla->insert(pair<int, ElementoPantalla>(llave, elementoPantallaActual));

			c.x = ObjetoIT::getX() + j;
			c.y = ObjetoIT::getY() + ObjetoIT::getAlto() - i - 1;
			gotoxy(c.x, c.y);
			cout << caracterBorde << endl;

			llave = Coordenada2DALlave(c, anchoPantalla);
			elementoPantallaActual.x = c.x;
			elementoPantallaActual.y = c.y;
			mapaElementosPantalla->insert(pair<int, ElementoPantalla>(llave, elementoPantallaActual));

		}

		for (int k = i; k < ObjetoIT::getAlto() - i - 2; k++) {
			c.x = ObjetoIT::getX() + i;
			c.y = ObjetoIT::getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << caracterBorde << endl;

			llave = Coordenada2DALlave(c, anchoPantalla);
			elementoPantallaActual.x = c.x;
			elementoPantallaActual.y = c.y;
			mapaElementosPantalla->insert(pair<int, ElementoPantalla>(llave, elementoPantallaActual));

			c.x = ObjetoIT::getX() + ObjetoIT::getAncho() - i - 1;
			c.y = ObjetoIT::getY() + k + 1;
			gotoxy(c.x, c.y);
			cout << caracterBorde << endl;

			llave = Coordenada2DALlave(c, anchoPantalla);
			elementoPantallaActual.x = c.x;
			elementoPantallaActual.y = c.y;
			mapaElementosPantalla->insert(pair<int, ElementoPantalla>(llave, elementoPantallaActual));
		}
	}
	if (mapeado != NULL) {
		mapeado->ActualizarElementosPantalla(mapaElementosPantalla);
	}
}
// Genera el fondo del panel
void Panel::GenerarFondo() {
	int llave;
	Coordenada2D c;
	ElementoPantalla elementoPantallaActual;
	elementoPantallaActual.caracter = ObjetoIT::getCaracterBase();
	elementoPantallaActual.colorCaracter = ObjetoIT::getColorCaracterBase();
	elementoPantallaActual.colorFondo = ObjetoIT::getColorFondoBase();

	EstablecerColor(ObjetoIT::getColorFondoBase(), ObjetoIT::getColorCaracterBase());

	for (int i = borde; i < ObjetoIT::getAncho() - borde; i++) {
		for (int j = borde; j < ObjetoIT::getAlto() - borde; j++) {
			c.x = ObjetoIT::getX() + i;
			c.y = ObjetoIT::getY() + j;
			gotoxy(c.x, c.y);
			EstablecerColor(ObjetoIT::getColorFondoBase(), ObjetoIT::getColorCaracterBase());
			cout << ObjetoIT::getCaracterBase() << endl;

			llave = Coordenada2DALlave(c, anchoPantalla);
			elementoPantallaActual.x = c.x;
			elementoPantallaActual.y = c.y;
			mapaElementosPantalla->insert(pair<int, ElementoPantalla>(llave, elementoPantallaActual));
		}
	}
	if (mapeado != NULL)
		mapeado->ActualizarElementosPantalla(mapaElementosPantalla);
}

// Muestra el panel y los hijos

void Panel::Mostrar()
{
	GenerarFondo();
	GenerarBordes();

	if (hijos.size() != 0)
		for (unsigned int i = 1; i < hijos.size(); i++)
		{
			hijos[i]->Mostrar();
		}
}