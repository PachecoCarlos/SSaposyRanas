#pragma once
#include<iostream>
#include"../MapaElementosPantalla.h"
using namespace std;

class Objetos {
private:
	static int numeroObjetos;
	int numero;
	string nombre;
	int x;
	int y;
	int ancho;
	int alto;
	char caracter;

	int colorFondo;
	int colorCaracter;
protected:

	MapaElementosPantalla* mapeado;
	map<int, ElementoPantalla>* mapaElementosPantalla;

public:
	Objetos(int _x, int _y, int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc);

	//Metodos propios de la clase
	static int getNumeroObjetos();
	virtual void Mostrar() = 0;

	//Metodos accesores
	map<int, ElementoPantalla>* getMapaElementoPantalla() { return mapaElementosPantalla; }
	void setMapaElementoPantalla(map<int, ElementoPantalla>* _mapaElementoPantalla) { mapaElementosPantalla = _mapaElementoPantalla; }

	int getNumero() { return numero; }
	string getNombre() { return nombre; }
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	char getCaracter() { return caracter; }

	void setNumero(int _numero) { numero = _numero; }
	void setNombre(string _nombre) { nombre = _nombre; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setCaracter(char _caracter) { caracter = _caracter; }

	void setColorFondo(int _colorFondoBorde) { colorFondo = _colorFondoBorde; }
	int getColorFondo() { return colorFondo; }

	void setColorCaracter(int _colorCaracterBorde) { colorCaracter = _colorCaracterBorde; }
	int getColorCaracter() { return colorCaracter; }
};