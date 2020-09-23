#include "MapaElementosPantalla.h"

int MapaElementosPantalla::numeroMapasElementosPantalla = 0;

//Metodo para que se pueda contabilizar los mapas que se crea
int MapaElementosPantalla::getNumeroMapasElementosPantalla()
{
	return numeroMapasElementosPantalla;
}


//Constructor
MapaElementosPantalla::MapaElementosPantalla(int _anchoPantalla, int _altoPantalla) : anchoPantalla(_anchoPantalla), altoPantalla(_altoPantalla){
	mapaElementosPantalla = new map<int, ElementoPantalla>();
	numeroMapasElementosPantalla++;
	numeroMapaElementosPantalla = numeroMapasElementosPantalla;
}

// Metodo para agregar elementos al map
void MapaElementosPantalla::AgregarElementoPantalla(int _llave, ElementoPantalla _elementoPantalla){
	mapaElementosPantalla->insert(pair<int, ElementoPantalla>(_llave, _elementoPantalla));
}

//Metodo para actualizar los elementos en el map
void MapaElementosPantalla::ActualizarElementosPantalla(map<int, ElementoPantalla>* _elementosPantalla){
	for (auto elemento = _elementosPantalla->begin(); elemento != _elementosPantalla->end(); ++elemento) {
		auto itmc = mapaElementosPantalla->find(elemento->first);
		if (itmc != mapaElementosPantalla->end()) {
			itmc->second = elemento->second;
		}else {
			mapaElementosPantalla->insert(pair<int, ElementoPantalla>(elemento->first, elemento->second));
		}
	}
}

//Metodo para eliminar los elementos de la pantalla en base a la llave del elemento
void MapaElementosPantalla::EliminarElementoPantalla(int _llave) {
	mapaElementosPantalla->erase(_llave);
}

//Metodo para obtener los elementos en base a la llave que se le de
ElementoPantalla MapaElementosPantalla::ObtenerElementoPantalla(int _llave) {
	auto itmc = mapaElementosPantalla->find(_llave);
	if (itmc != mapaElementosPantalla->end()) {
		return itmc->second;
	}
	else {
		return ElementoPantalla{ 0, 0, 0, 0, 0 };
	}
}

//Muestra los diferentes elementos almacenados en el mapa (llave, caracter, colorFondo, colorCaracter)
void MapaElementosPantalla::Mostrar()
{
	gotoxy(0, 29);
	cout << "Elementos de mapaElementosPantalla:" << endl;

	for (auto elemento = mapaElementosPantalla->begin(); elemento != mapaElementosPantalla->end(); ++elemento) {
		cout << "[ " << elemento->first << " : " << elemento->second.caracter << "],  ";
	}
}



