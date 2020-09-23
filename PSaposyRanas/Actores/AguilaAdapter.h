#pragma once
#include "Actores.h"
#include "Aguila.h"

//clase hija que interactua como objeto intermedio para que las clases actor y Aguila trabajen entre ellas
class AguilaAdapter :
	public Actores, public Aguila
{
public:

	//contructor de la clase 
	AguilaAdapter(vector<string> _avatar, int _x, int _y, int _dx, int _dy, int _limiteSuperior, int _limiteInferior, int _limiteIzquierda, int _limiteDerecha, MapasCaracteres* _mce);
	void Mostrar();//metodo heredado de actor
	void MostrarInformacionClase();//metodo propio de la clase
	
	//metodo inline de representacion visual del avatar de tipo string que retorna valor del mismo tipo
	inline string AvatarARepresentacionVisual(vector<string> _avatar) {
		string rvt = "";


		for (int i = 0; i < _avatar.size(); i++) {
			for (int j = 0; j < _avatar[i].length(); j++) {
				rvt = rvt + _avatar[i][j];
			}
			//rvt = rvt + '\n';
		}

		return rvt;
	}
};


