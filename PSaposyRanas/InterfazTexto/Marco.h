#pragma once
#include "..\Composite.h"
#include "ComponenteIT.h"
#include <iostream>
// Desciende de una clase composite tipo componeteIT
// Heredara todo de composite
class Marco : public Composite<ComponenteIT>, public ObjetoIT
{
private:
	int borde;
	int colorFondoBorde;
	int colorCaracterBorde;
	char caracterBordeHorizontal;
	char caracterBordeVertical;
	string titulo;
	string contenido;

public:
	Marco(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase, int _borde,
		int _colorFondoBorde, int _colorCaracterBorde, char _caracterBordeHorizontal, char _caracterBordeVertical);
	void GenerarBordes();
	void GenerarFondo();

	void Mostrar();
	//Metodos de acceso
	void setBorde(int _borde) { borde = _borde; }
	int getBorde() { return borde; }

	void setColorFondoBase(int _colorFondoBase) { ObjetoIT::setColorFondoBase(_colorFondoBase); }
	int getColorFondoBase() { return ObjetoIT::getColorFondoBase(); }

	void setColorCaracterBase(int _colorCaracterBase) { ObjetoIT::setColorCaracterBase(_colorCaracterBase); }
	int getColorCaracterBase() { return ObjetoIT::getColorCaracterBase(); }

	void setColorFondoBorde(int _colorFondoBorde) { colorFondoBorde = _colorFondoBorde; }
	int getColorFondoBorde() { return colorFondoBorde; }

	void setColorCaracterBorde(int _colorCaracterBorde) { colorCaracterBorde = _colorCaracterBorde; }
	int getColorCaracterBorde() { return colorCaracterBorde; }

	void setCaracterBordeHorizontal(char _caracterBordeHorizontal) { caracterBordeHorizontal = _caracterBordeHorizontal; }
	char getCaracterBordeHorizontal() { return caracterBordeHorizontal; }

	void setCarcacterBordeVertical(char _caracterBordeVertical) { caracterBordeVertical = _caracterBordeVertical; }
	char getCaracterBordeVertical() { return caracterBordeVertical; }

	void setContenido(string _contenido) { contenido = _contenido; }
	string getContenido() { return contenido; }

	void setTitulo(string _titulo) { titulo = _titulo; }
	string getTitulo() { return titulo; }
};

