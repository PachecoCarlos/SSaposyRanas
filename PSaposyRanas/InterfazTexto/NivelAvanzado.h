#pragma once
#include "SeleccionObjetoIT.h"
#include "../GameManager.h"
#include "../Actores/FabricaActorNivelAvanzado.h"
#include <Windows.h>

// Nivel de dificultad del juego avanzado
class NivelAvanzado :
	public SeleccionObjetoIT
{
public:
	FabricaActor* faNivelAvanzado = new FabricaActorNivelAvanzado;
	GameManager* gm01 = GameManager::getInstancia();
	void presEnter() {
		gm01->IniciarJuego(faNivelAvanzado);
	}
	bool fin() {
		return gm01->fin();
	}
};