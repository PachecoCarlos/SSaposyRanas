#pragma once
#include "..\Composite.h"
#include "ComponenteIT.h"
#include "..\Utilitarios.h"
#include <iostream>

using namespace std;
// Desciende de una clase composite tipo componeteIT
// Va a heredar todo de composite
class Marcador : public Composite<ComponenteIT>, public ObjetoIT
{
private:
	int borde;
	int colorFondoBorde;
	int colorCaracterBorde;
	char caracterBorde;
	int vidas;
	int puntos;
	string nombre;

public:
	Marcador(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase, int _borde,
		int _colorFondoBorde, int _colorCaracterBorde, char _caracterBorde);

	void GenerarBordes();
	void GenerarFondo();

	void Mostrar();
	// metodos de acceso 
	void setBorde(int _borde) { borde = _borde; }
	int getBorde() { return borde; }

	void setColorFondoBorde(int _colorFondoBorde) { colorFondoBorde = _colorFondoBorde; }
	int getColorFondoBorde() { return colorFondoBorde; }

	void setColorCaracterBorde(int _colorCaracterBorde) { colorCaracterBorde = _colorCaracterBorde; }
	int getColorCaracterBorde() { return colorCaracterBorde; }

	void setCaracterBorde(char _caracterBorde) { caracterBorde = _caracterBorde; }
	char getCaracterBorde() { return caracterBorde; }

	void setVidas(int _vidas) { vidas = _vidas; }
	int getVidas() { return vidas; }

	void setPuntos(int _puntos) { puntos = _puntos; }
	int getPuntos() { return puntos; }

	void setNombre(string _nombre) { nombre = _nombre; }
	string getNombre() { return nombre; }
};

