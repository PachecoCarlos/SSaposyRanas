#include "Bloques.h"
#include "../Utilitarios.h"

//Metodos heredados y redefinidos de la clase Objetos
void Bloques::Mostrar() {

	//Variables que se necesitan para actualizar el mapa
	Coordenada2D xy;
	ElementoPantalla cc;
	cc.caracter = getCaracter();
	cc.colorCaracter = getColorCaracter();
	cc.colorFondo = getColorFondo();
	
	//Visualizacion del elemento en pantalla
	for (int i = 0; i < getAncho(); i++) {
		for (int j = 0; j < getAlto(); j++) {
			xy.x = getX() + i; xy.y = getY() + j;
			gotoxy(xy.x, xy.y);
			EstablecerColor(cc.colorFondo, cc.colorCaracter);
			cout << cc.caracter << endl;
			mapaElementosPantalla->insert(pair<int, ElementoPantalla>(Coordenada2DALlave(xy, mapeado->getAnchoPantalla()), cc));
		}
	}

	//Actualizacion del mapa
	mapeado->ActualizarElementosPantalla(mapaElementosPantalla);
}