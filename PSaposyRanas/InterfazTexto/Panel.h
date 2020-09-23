#pragma once
#include "..\Composite.h"
#include "ComponenteIT.h"
#include "..\Utilitarios.h"
#include <map>
#include"../MapaElementosPantalla.h"

// Desciende de una clase composite tipo componeteIT
// Va a heredar todo de composite
class Panel : public Composite<ComponenteIT>, public ObjetoIT {
private:
	int borde;
	int colorFondoBorde;
	int colorCaracterBorde;
	char caracterBorde;

	int anchoPantalla;
	char caracterFondo;
	MapaElementosPantalla* mapeado;
	map<int, ElementoPantalla>* mapaElementosPantalla;
public:
	//Diferentes Contructores segun se necesite
	Panel();
	Panel(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, char _caracterBase, int _borde,
		int _colorFondoBorde, int _colorCaracterBorde, char _caracterBorde);

	Panel(int _x, int _y, int _ancho, int _alto,
		int _colorFondoBase, int _colorCaracterBase,
		char _caracterBase, int _anchoPantalla,
		char _caracterBorde, int _borde, MapaElementosPantalla* _mapeado);

	void GenerarBordes();
	void GenerarFondo();

	void Mostrar();
	// metodos de acceso
	void setBorde(int _borde) { borde = _borde; }
	int getBorde() { return borde; }

	int getX() { return ObjetoIT::getX(); }
	int getY() { return ObjetoIT::getY(); }

	void setColorFondoBorde(int _colorFondoBorde) { colorFondoBorde = _colorFondoBorde; }
	int getColorFondoBorde() { return colorFondoBorde; }

	void setColorCaracterBorde(int _colorCaracterBorde) { colorCaracterBorde = _colorCaracterBorde; }
	int getColorCaracterBorde() { return colorCaracterBorde; }

	void setCaracterBorde(char _caracterBorde) { caracterBorde = _caracterBorde; }
	char getCaracterBorde() { return caracterBorde; }
};