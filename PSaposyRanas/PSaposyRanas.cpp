#include <iostream>
#include "Utilitarios.h"
#include <conio.h>
#include <stdio.h>
#include "InterfazTexto/Interface.h"
#include "InterfazTexto/Panel.h"
#include "GameManager.h"

using namespace std;
Interface pantalla;

int main(){

	OcultarCursor();

	//Se inicia toda la interfaz que inicia el juego
	Interface().IniciarInterface();
}