#pragma once
#include "SeleccionObjetoIT.h"
#include "../GameManager.h"
#include "../Actores/FabricaActorNivelBasico.h"

//Nivel de dificultad del juego basico
class NivelBasico :
    public SeleccionObjetoIT
{
public:
    FabricaActor* faNivelBasico = new FabricaActorNivelBasico;
    GameManager* gm01 = GameManager::getInstancia();
    void presEnter() {
        gm01->IniciarJuego(faNivelBasico);
    }
    bool fin() {
        return gm01->fin();
    }
};

