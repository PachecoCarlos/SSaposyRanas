#include "Menu.h"
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "..\Utilitarios.h"
#include <iostream>
#include "Boton.h"

using namespace std;

Menu::Menu(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int _colorCaracterBase, int _caracterBase) :
	ObjetoIT(_x, _y, _ancho, _alto, _colorFondoBase, _colorCaracterBase, _caracterBase)
{
	indiceElementoActual = 1;
	indiceElementoAnterior = 1;
	marco = new Marco(30, 15, 60, 12, 0, 15, 177, 1, 0, 1, 186, 205);
}

void Menu::Mostrar()
{
	// Llama a ObjetoIT para poder aceder a sus atributos 
	EstablecerColor(ObjetoIT::getColorFondoBase(), ObjetoIT::getColorCaracterBase());
	for (int i = 0; i < ObjetoIT::getAncho(); i++) {
		for (int j = 0; j < ObjetoIT::getAlto(); j++) {
			gotoxy(ObjetoIT::getX() + i, ObjetoIT::getY() + j);
			cout << ObjetoIT::getCaracterBase() << endl;
		}
	}
	//hijos esta heredando de composite
	for (unsigned int i = 0; i < hijos.size(); i++)
	{
		hijos[i]->Mostrar();
	}
}

void Menu::MostrarSelector() {
	int posxSelector = 0;
	int posySelector = 0;

	posxSelector = hijos[indiceElementoAnterior]->getX() - 4;
	posySelector = hijos[indiceElementoAnterior]->getY();
	gotoxy(posxSelector, posySelector);
	cout << "   " << endl;

	posxSelector = hijos[indiceElementoActual]->getX() - 4;
	posySelector = hijos[indiceElementoActual]->getY();
	gotoxy(posxSelector, posySelector);
	cout << "-->" << endl;
}
// Asignacion de movilidad entre Elementos segun la tecla
bool Menu::getTecla() {
	bool teclaPresionada = false;

	char key = ';';

	if (_kbhit()) {
		key = _getch();
	}
	//recorrera hacia arriba
	if (key == 72) {
		teclaPresionada = true;

		if (indiceElementoActual > 1)
			indiceElementoActual--;
	}
	//recorrera hacia abajo
	if (key == 80) {
		teclaPresionada = true;

		if (indiceElementoActual < numeroElementos - 1)
			indiceElementoActual++;
	}
	if (key == 27) {
		opcionSalir = true;
	}

	if (key == 13) {
		teclaPresionada = true;
		hijos[indiceElementoActual]->preEnter();
		//Llamar al metodo respectivo
	}

	return teclaPresionada;
}

void Menu::Bucle() {
	while (!opcionSalir) {
		if (hijos[indiceElementoActual]->fin())
		{
			opcionSalir = true;
		}

		indiceElementoAnterior = indiceElementoActual;
		if (getTecla()) {
			if (indiceElementoActual != indiceElementoAnterior) {
				hijos[indiceElementoAnterior]->setSeleccionado(false);
				hijos[indiceElementoAnterior]->Mostrar();
				hijos[indiceElementoActual]->setSeleccionado(true);
				hijos[indiceElementoActual]->Mostrar();
			}

			gotoxy(30, 15);
			//El indiceElementoActual definira que acciones se realizara para mostrar en pantalla
			switch (indiceElementoActual) {
			case 1:
				marco->setTitulo("Nivel Basico");
				marco->setContenido("Nivel Basico del Juego");
				marco->setColorFondoBase(6);
				break;
			case 2:
				marco->setTitulo("Nivel Medio");
				marco->setContenido("Nivel Medio del Juego");
				marco->setColorFondoBase(2);
				break;
			case 3:
				marco->setTitulo("Nivel Avanzado");
				marco->setContenido("Nivel Avanzado del juego");
				marco->setColorFondoBase(5);
				break;
			case 4:
				marco->setTitulo("Salir");
				marco->setContenido("Salir del juego");
				marco->setColorFondoBase(8);
				break;
			}
			if (!hijos[indiceElementoActual]->fin())
			{
				marco->Mostrar();
			}
		}
	}
}


void Menu::Iniciar() {
	numeroElementos = hijos.size();
	marco->Mostrar();
	Bucle();
}
