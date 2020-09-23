#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"../Utilitarios.h"
#include"../MapaElementosPantalla.h"
using namespace std;

class ActorMovimiento {
protected:
	vector<string> avatar;
	map<int, ElementoPantalla>* mapaElementoPantallaActor;
	int x;
	int y;
	int dx;
	int dy;
	static int limiteSuperior;
	static int limiteInferior;
	static int limiteIzquierda;
	static int limiteDerecha;
	int colorCaracter;
	int colorFondo;
	int filasAvatar;
	int columnasAvatar;
	MapaElementosPantalla* mapaElementos;
public:
	// Constructor
	ActorMovimiento(vector<string>* _avatar, int* _x, int* _y, int* _dx, int* _dy,
		int* _colorCaracter, int* _colorFondo, MapaElementosPantalla* _mce);

	// funciones inline
	inline int ObtenerNumeroFilasAvatar() const { return avatar.size(); }
	inline int ObtenerNumeroCaracteresString(string cadenaCaracteres) const { return cadenaCaracteres.length(); }
	inline int ObtenerAreaAvatar() const { return filasAvatar * columnasAvatar; }

	// Metodos virtuales
	virtual void Mostrar() {};
	virtual void Mover() {};

	// Metodos accesores
	map<int, ElementoPantalla>* getMapaElementoPantallaAvatar() {
		return mapaElementoPantallaActor;
	}
	void setMapaElementoPantallaActor(map<int, ElementoPantalla>* _mapaElementoPantallaActor) { mapaElementoPantallaActor = _mapaElementoPantallaActor; }

	int getX() const { return x; }
	void setX(int _x) { this->x = _x; }

	int getY() const { return y; }
	void setY(int _y) { this->y = _y; }

	int getDX() const { return dx; }
	void setDX(int _dx) { dx = _dx; }

	int getDY() const { return dy; }
	void setDY(int _dy) { dy = _dy; }

	int getNroColumnas() const { return columnasAvatar; }
	void setNroColumnas(int _col) { columnasAvatar = _col; }
};