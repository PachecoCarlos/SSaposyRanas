#pragma once
#include<iostream>
#include<map>
#include<vector>
#include"../Utilitarios.h"
#include "ActorMovimiento.h"
#include"ActorMovimientoNormal.h"
#include"../MapaElementosPantalla.h"
using namespace std;
//clase padre abstracta para la utilizacion del patron abstract factory
class Actor {
	//atributos propios de la clase privados 
private:
	static int numeroActores;
	int numero;
	string nombre;
	vector<string> avatar;
	map<int, ElementoPantalla>* mapaElementoPantallaActor;
	MapaElementosPantalla* mapaElementosPatalla;
	int x;
	int y;
	int dx;
	int dy;
	int colorCaracter;
	int colorFondo;
	int vidas;
	int puntos;

protected:
	// declaramos la variable de ActorMovimiento
	ActorMovimiento* movimientoActor;

public:
	static int getNumeroActores();
	// Constructor de la clase actor
	Actor(vector<string> _avatar, int _x, int _y, int _dx, int _dy, int _colorCaracter, int _colorFondo, MapaElementosPantalla* _mce);
	Actor() {}
	// Metodo parte del patron Factory method
	static Actor* getActor(string nombre, int _x, int _y, int _dx, int _dy) {};
	// Metos virtuales 
	virtual void Mostrar();
	virtual void Mover();
	/*este metodo esta igualado a cero para luego sobrecargar o sobre escribir en las
	clases hijas asi tambien para la aplicabilidad del patron Abstrac Factory*/
	virtual int dano() = 0;

	// Metodos Accesores
	int getNumero() { return numero; }
	void setNumero(int _numero) { numero = _numero; }

	string getNombre() { return nombre; }
	void setNombre(string _nombre) { nombre = _nombre; }

	vector<string> getAvatar() const { return avatar; }
	void setAvatar(vector<string> _avatar) { avatar = _avatar; }

	map<int, ElementoPantalla>* getMapaElementoPantallaActor() { return movimientoActor->getMapaElementoPantallaAvatar(); }
	void set(map<int, ElementoPantalla>* _mapaElementoPantallaActor) { movimientoActor->setMapaElementoPantallaActor(_mapaElementoPantallaActor); }

	int getX() const { return x; }
	void setX(int _x) { movimientoActor->setX(_x); }

	int getY() const { return y; }
	void setY(int _y) { movimientoActor->setY(_y); }

	int getDX() const { return dx; }
	void setDX(int _dx) { movimientoActor->setDX(_dx); }

	int getDY() const { return dy; }
	void setDY(int _dy) { movimientoActor->setDY(_dy); }

	int getNroColumnas() const { return movimientoActor->getNroColumnas(); }
	void setNroColumnas(int _col) { movimientoActor->setNroColumnas(_col); }

	int getVidas() { return vidas; }
	void setVidas(int _vidas) { vidas = _vidas; }

	int getPuntos() { return puntos; }
	void setPuntos(int _puntos) { puntos = _puntos; }

};