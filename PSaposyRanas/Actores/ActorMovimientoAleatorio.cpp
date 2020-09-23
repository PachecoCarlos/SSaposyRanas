#include "ActorMovimientoAleatorio.h"
#include"ActorMovimientoNormal.h"

//Constructor
ActorMovimientoAleatorio::ActorMovimientoAleatorio(vector<string>* _avatar, int* _x, int* _y, int* _dx, int* _dy,
	int* _colorCaracter, int* _colorFondo, MapaElementosPantalla* _mce) :
	ActorMovimiento(_avatar, _x, _y, _dx, _dy, _colorCaracter, _colorFondo, _mce) {
	mapaElementoPantallaActor = new map<int, ElementoPantalla>();
}

void ActorMovimientoAleatorio::Mostrar() {
	Coordenada2D p = { 0, 0 };
	auto avatarActor = avatar;
	// Limpiamos el mapa de actores para que en cada movimiento actualice sus posiciones(x,y)
	mapaElementoPantallaActor->clear();
	for (int i = 0; i < filasAvatar; i++) {
		for (int j = 0; j < avatarActor[i].size(); j++) {
			if (x + j >= limiteIzquierda && x + j < limiteDerecha && y + i >= limiteSuperior && y + i < limiteInferior) {
				p.x = x + j;
				p.y = y + i;
				EstablecerColor(colorFondo, colorCaracter);
				gotoxy(p.x, p.y);
				cout << avatarActor[i][j] << endl;
				ElementoPantalla elementoPantallaActual;
				//Establecemos sus nuevas posiciones para el mapeado
				elementoPantallaActual.x = p.x;
				elementoPantallaActual.y = p.y;
				elementoPantallaActual.caracter = avatarActor[i][j];
				elementoPantallaActual.colorCaracter = colorCaracter;
				elementoPantallaActual.colorFondo = colorFondo;
				mapaElementoPantallaActor->insert(pair<int, ElementoPantalla>(Coordenada2DALlave(p, 119), elementoPantallaActual));
				// Actualizamos el mapa de actores 
			}
		}
	}
}

void ActorMovimientoAleatorio::Mover() {
	int xx = 0, yy = 0;
	int llave = 0;
	Coordenada2D p = { 0, 0 };
	ElementoPantalla cc = { 0,0 };
	for (int j = getX(); j < getX() + columnasAvatar; j++) {
		p.x = j;
		for (int i = getY(); i < (getY() + filasAvatar); i++) {
			p.y = i;
			llave = Coordenada2DALlave(p, mapaElementos->getAnchoPantalla());
			// Pasamos una llave y nos devuelve un elementoPantalla donde se puede acceder a sus colores y caracteres
			cc = mapaElementos->ObtenerElementoPantalla(llave);
			gotoxy(p.x, p.y);
			EstablecerColor(cc.colorFondo, cc.colorCaracter);
			cout << cc.caracter;
		}
	}
	//Permite realizar el movimiento aleatorio
	xx = 5 + rand() % 110;
	yy = 5 + rand() % 24;
	setX(xx); setY(yy);
	Mostrar();
}
