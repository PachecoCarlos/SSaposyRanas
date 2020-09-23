#pragma once
#include "SeleccionObjetoIT.h"
#include "../GameManager.h"
#include "../Actores/FabricaActorNivelIntermedio.h"

//Nivel de dificultad del juego medio
class NivelMedio :
	public SeleccionObjetoIT
{
public:
	FabricaActor* faNivelIntermedio = new FabricaActorNivelIntermedio;
	GameManager* gm01 = GameManager::getInstancia();
	void presEnter() {
		gm01->IniciarJuego(faNivelIntermedio);
	}
	bool fin() {
		return gm01->fin();
	}
};


