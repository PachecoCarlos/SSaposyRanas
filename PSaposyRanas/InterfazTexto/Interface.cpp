#include "Interface.h"
#include <iostream>

using namespace std;
// constructor del interfaz
Interface::Interface() {

}

void Interface::IniciarInterface() {
	// niveles del juego
	NivelBasico basico;
	NivelMedio medio;
	NivelAvanzado avanzado;

	ObjetoSalir salir;
	// implementacion de etiquetas y botones
	Etiqueta* et1 = new Etiqueta("Menu principal", 10, 14);
	Boton bm1("Nivel Basico", 10, 15, 14, 3, 6, 15, 176);
	bm1.setSeleccionObjetoIT(&basico);
	//bm1.Mostrar();
	Boton bm2("Nivel Medio", 10, 18, 14, 3, 2, 15, 177);
	bm2.setSeleccionObjetoIT(&medio);
	Boton bm3("Nivel Avanzado", 10, 21, 14, 3, 5, 15, 177);
	bm3.setSeleccionObjetoIT(&avanzado);
	Boton bm4("Salir", 10, 24, 14, 3, 1, 15, 177);
	bm4.setSeleccionObjetoIT(&salir);

	// Implementacion de un menu
	Menu menuPrincipal(9, 13, 16, 15, 4, 15, 176);
	// Al menu se le ayaden las ateuetas y botones
	menuPrincipal.AgregarHijo(et1);
	menuPrincipal.AgregarHijo(&bm1);
	menuPrincipal.AgregarHijo(&bm2);
	menuPrincipal.AgregarHijo(&bm3);
	menuPrincipal.AgregarHijo(&bm4);

	//menuPrincipal.Mostrar();

	// Creacion del panel
	Panel panelPrincipal(0, 0, 120, 30, 5, 1, ' ', 3, 3, 4, ' ');
	panelPrincipal.AgregarHijo(new Etiqueta("JUEGO SAPOS Y RANAS", 15, 1));
	// Al panel se le agraga el menuPrincipal 
	panelPrincipal.AgregarHijo(&menuPrincipal);

	panelPrincipal.Mostrar();

	Etiqueta* eti = new Etiqueta("JUEGO SAPOS Y RANAS", 50, 1);
	eti->Mostrar();
	// Implemetacion del marco
	Marco marcoHistoria(5, 3, 110, 10, 0, 1, 176, 1, 0, 1, 186, 205);
	marcoHistoria.setTitulo("HISTORIA");
	marcoHistoria.setContenido(
		"Estes un Juego que se hizo porque la mejor forma de aprender seria haciendo un fuego. El objetivo del juego es guiar una rana hasta su hogar. Para hacerlo, la rana debe evitar coches mientras cruza una carretera congestionada y luego cruzar un rio lleno de amenazas. El jugador habil obtendra puntos adicionales a lo largo del camino."
	);
	marcoHistoria.Mostrar();

	menuPrincipal.Iniciar();
}