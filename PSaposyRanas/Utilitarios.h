#pragma once

#include <Windows.h>
#include <vector>
#include <iostream>

using namespace std;
/*estructura utilizada para determinar su posicion*/
struct Coordenada2D {
	int x;
	int y;
};

/*Estructura utilizada para los elementos necesarios de la pantalla*/
struct ElementoPantalla {
	int x;
	int y;
	char caracter;
	int colorCaracter;
	int colorFondo;
};

void gotoxy(int x, int y);
void OcultarCursor();
void GameOver(bool);

void EstablecerColor(int _colorFondo, int _colorCaracter);

Coordenada2D LlaveACoordenada2D(int _llave, int _ancho);

/*Dentro de ella permite acceder a toda la extructura Coordenada2D y aparte un entero como parametros */
int Coordenada2DALlave(Coordenada2D _c, int _ancho);
