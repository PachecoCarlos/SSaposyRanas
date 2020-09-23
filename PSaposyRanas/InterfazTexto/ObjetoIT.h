#pragma once
#include "SeleccionObjetoIT.h"
// clase abstracta de la cual heredaran sus componentes sus clases hijas
class ObjetoIT
{
	// Propiedades generales que tiene un objeto
private:
	int x;
	int y;
	int ancho;
	int alto;
	int colorFondoBase;
	int colorCaracterBase;
	char caracterBase;
	bool seleccionado;
	bool visible;

	SeleccionObjetoIT* seleccion;

public:
	//se crean contructores segun la utilidad
	ObjetoIT(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase);
	ObjetoIT(int _x, int _y);
	ObjetoIT() {};
	//permite definir el metodo selecionado
	void setSeleccionObjetoIT(SeleccionObjetoIT* _obj) { seleccion = _obj; }
	//
	virtual void preEnter();
	virtual bool fin();

	virtual void Mostrar() = 0;
	// se crean sus metodos de acceso

	void setX(int _x) { x = _x; }
	int getX() { return x; }
	void setY(int _y) { y = _y; }
	int getY() { return y; }
	void setAncho(int _ancho) { ancho = _ancho; }
	int getAncho() { return ancho; }
	void setAlto(int _alto) { alto = _alto; }
	int getAlto() { return alto; }
	void setColorFondoBase(int _colorFondoBase) { colorFondoBase = _colorFondoBase; }
	int getColorFondoBase() { return colorFondoBase; }
	void setColorCaracterBase(int _colorCaracterBase) { colorCaracterBase = _colorCaracterBase; }
	int getColorCaracterBase() { return colorCaracterBase; }
	void setCaracterBase(char _caracterBase) { caracterBase = _caracterBase; }
	char getCaracterBase() { return caracterBase; }
	void setSeleccionado(bool _seleccionado) { seleccionado = _seleccionado; }
	bool getSeleccionado() { return seleccionado; }
	void setVisible(bool _visible) { visible = _visible; }
	bool getVisible() { return visible; }

};

