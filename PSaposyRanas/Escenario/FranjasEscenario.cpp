#include "FranjasEscenario.h"

void FranjasEscenario::Mostrar() {

	//Metodo para mostrar el panel
	panelFE->Mostrar();
	//Metodos para mostrar los objetos almacenados en los vectores
	for (auto it = std::begin(bloquesFE); it != std::end(bloquesFE); ++it) {
		(*it)->Mostrar();
	}

	for (auto it = std::begin(espinasFE); it != std::end(espinasFE); ++it) {
		(*it)->Mostrar();
	}
}
