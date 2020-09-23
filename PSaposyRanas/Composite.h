#pragma once
// inclusion de las librerias
#include <vector>
#include <algorithm>

using namespace std;
// El template maneja cualquier tipo de clase 
template<typename Componente>
// Se esta creando la clase componente que desiende de un template tipo componente
class Composite : public Componente
{
protected:
	//Va a almacenar hijos de tipo componente
	vector<Componente*> hijos; //Lista de los hijos componentes.

public:
	// Se crea un tipo de dato que valga igual vector<Componente*>::iterator
	typedef	typename vector<Componente*>::iterator IteradorHijo;

	// Metodo para añadir un hijo 
	void AgregarHijo(Componente* hijo)
	{
		// Le pasa un hijo tipo componete
		// se busca de principio a fin bucando hijo
		// Si lo encuentra lo guarda en itr
		// Si no manda la direccion final y añade
		IteradorHijo itr = find(hijos.begin(), hijos.end(), hijo);
		if (itr == hijos.end())
		{
			hijos.push_back(hijo);
		}
	}

	Componente* ObtenerHijo(int indice) {
		return hijos.pop_back(indice);
	}

	Componente* Obtener(int indice) {
		return hijos[indice];
	}

	void EliminarHijo(Componente* hijo)
	{
		IteradorHijo itr = find(hijos.begin(), hijos.end(), hijo);
		if (itr != hijos.end())
		{
			hijos.erase(itr);
		}
	}

	void VaciarHijos()
	{
		hijos.clear();
	}

	virtual ~Composite()
	{

	}
};