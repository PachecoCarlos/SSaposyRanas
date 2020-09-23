#include "Potenciadores.h"
#include "../Utilitarios.h"

//Constructor
Potenciadores::Potenciadores(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc, int _velocidad,
	int _salto, int _energia, int _escudo, int _vidas) :Objetos(_x, _y, _ancho, _alto, _caracter, _colorFondo, _colorCaracter, _mc) {
	velocidad = _velocidad;
	salto = _salto;
	energia = _energia;
	escudo = _escudo;
	vidas = _vidas;
}

void Potenciadores::Mostrar() {
	//metodo que permite el mapeado Para los objetos y luego mostrarlos
	Coordenada2D xy;
	ElementoPantalla cc;
	cc.caracter = getCaracter();
	cc.colorCaracter = getColorCaracter();
	cc.colorFondo = getColorFondo();

	for (int i = 0; i < getAncho(); i++) {
		//Establece su nueva posicion para luego mostrar el caracter
		xy.x = getX() + i; xy.y = getY();
		gotoxy(xy.x, xy.y);
		EstablecerColor(cc.colorFondo, cc.colorCaracter);
		cout << cc.caracter << endl;
		mapaElementosPantalla->insert(pair<int, ElementoPantalla>(Coordenada2DALlave(xy, mapeado->getAnchoPantalla()), cc));
	}
	mapeado->ActualizarElementosPantalla(mapaElementosPantalla);
}
