#include "ActorMovimientoNormal.h"

//Constructor
ActorMovimientoNormal::ActorMovimientoNormal(vector<string>* _avatar, int* _x, int* _y, int* _dx, int* _dy,
	int* _colorCaracter, int* _colorFondo, MapaElementosPantalla* _mce) :
	ActorMovimiento(_avatar, _x, _y, _dx, _dy, _colorCaracter, _colorFondo, _mce) {
	mapaElementoPantallaActor = new map<int, ElementoPantalla>();
}

void ActorMovimientoNormal::Mostrar() {
	Coordenada2D p = { 0, 0 };
	auto avatarActor = avatar;
	// Limpiamos el mapa de actores para que en cada movimiento actualice sus posiciones(x,y)
	mapaElementoPantallaActor->clear();
	bool ban = true;
	int a;
	int b;
	for (int i = 0; i < filasAvatar; i++) {
		for (int j = 0; j < avatarActor[i].size(); j++) {
			if (x + j >= limiteIzquierda && x + j < limiteDerecha && y + i >= limiteSuperior && y + i < limiteInferior) {
				//Posiciones
				p.x = x + j;
				p.y = y + i;
				EstablecerColor(colorFondo, colorCaracter);
				gotoxy(p.x, p.y);

				cout << avatarActor[i][j] << endl;
				ElementoPantalla elementoPantallaActual;
				if (ban)
				{
					a = p.x;
					b = p.y;
					ban = false;
				}
				//De la estructura ElementoPantalla va actualizando sus nuevos valores
				elementoPantallaActual.x = a;
				elementoPantallaActual.y = b;
				elementoPantallaActual.caracter = avatarActor[i][j];
				elementoPantallaActual.colorCaracter = colorCaracter;
				elementoPantallaActual.colorFondo = colorFondo;
				mapaElementoPantallaActor->insert(pair<int, ElementoPantalla>(Coordenada2DALlave(p, 119), elementoPantallaActual));
				// Actulizamos el mapa de actores 
			}
		}
	}
}

void ActorMovimientoNormal::Mover() {
	int llaveActual = 0;
	Coordenada2D p = { 0, 0 };
	ElementoPantalla cc = { 0,0 };
	/*Para cada alternativa realizamos la misma logica, con la variante en el primer ciclo
	for cambia su condicion depende de la circunstancia*/
	if (dx < 0) {
		for (p.x = getX() + columnasAvatar - 1; p.x <= getX() + columnasAvatar - dx; p.x++) {
			if (p.x >= limiteIzquierda && p.x < limiteDerecha) {
				for (p.y = y; p.y < (y + filasAvatar); p.y++) {
					// Pasamos coordenadas y nos devuelve una llave
					llaveActual = Coordenada2DALlave(p, mapaElementos->getAnchoPantalla());
					// Pasamos una llave y nos devuelve un elementoPantalla donde se puede acceder a sus colores y caracteres
					cc = mapaElementos->ObtenerElementoPantalla(llaveActual);
					gotoxy(p.x, p.y);
					EstablecerColor(cc.colorFondo, cc.colorCaracter);
					cout << cc.caracter;
				}
			}
		}
	}

	if (dx > 0) {
		for (p.x = getX() + columnasAvatar; p.x > getX() - dx; p.x--) {
			if (p.x >= limiteIzquierda && p.x < limiteDerecha) {
				for (p.y = y; p.y < (y + filasAvatar); p.y++) {
					// Pasamos coordenadas y nos devuelve una llave
					llaveActual = Coordenada2DALlave(p, mapaElementos->getAnchoPantalla());
					// Pasamos una llave y nos devuelve un elementoPantalla donde se puede acceder a sus colores y caracteres
					cc = mapaElementos->ObtenerElementoPantalla(llaveActual);
					gotoxy(p.x, p.y);
					EstablecerColor(cc.colorFondo, cc.colorCaracter);
					cout << cc.caracter;
				}
			}
		}
	}

	if (dy < 0) {
		p.y = y + filasAvatar - 1;
		if (p.y >= limiteSuperior && p.y < limiteInferior) {
			for (int i = x; i <= (x + columnasAvatar); i++) {
				p.x = i;
				// Pasamos coordenadas y nos devuelve una llave
				llaveActual = Coordenada2DALlave(p, mapaElementos->getAnchoPantalla());
				// Pasamos una llave y nos devuelve un elementoPantalla donde se puede acceder a sus colores y caracteres
				cc = mapaElementos->ObtenerElementoPantalla(llaveActual);
				gotoxy(p.x, p.y);
				EstablecerColor(cc.colorFondo, cc.colorCaracter);
				cout << cc.caracter;
			}
		}
	}

	if (dy > 0) {
		p.y = y;
		if (p.y >= limiteSuperior && p.y < limiteInferior) {
			for (int i = x; i <= (x + columnasAvatar); i++) {
				p.x = i;
				// Pasamos coordenadas y nos devuelve una llave
				llaveActual = Coordenada2DALlave(p, mapaElementos->getAnchoPantalla());
				// Pasamos una llave y nos devuelve un elementoPantalla donde se puede acceder a sus colores y caracteres
				cc = mapaElementos->ObtenerElementoPantalla(llaveActual);
				gotoxy(p.x, p.y);
				EstablecerColor(cc.colorFondo, cc.colorCaracter);
				cout << cc.caracter;
			}
		}
	}

	//Condiciones para mostrar la posicion x
	x = x + dx;

	if (dx < 0) {
		if (x + columnasAvatar < limiteIzquierda) {
			x = limiteDerecha;
		}
	}

	if (dx > 0) {
		if (x > limiteDerecha) {
			x = limiteIzquierda - columnasAvatar;
		}
	}
	//Condiciones para mostrar el caracter en la posicion y
	y = y + dy;

	if (dy < 0) {
		if (y + filasAvatar < limiteSuperior) {
			y = limiteSuperior;
		}
	}

	if (dy > 0) {
		if (y > limiteInferior - filasAvatar) {
			y = limiteInferior - filasAvatar;
		}
	}

	Mostrar();
}