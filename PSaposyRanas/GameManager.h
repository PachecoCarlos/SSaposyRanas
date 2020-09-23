#pragma once

#include <list>
#include <queue>
#include "InterfazTexto/Panel.h"
#include "Escenario/FranjasEscenario.h"
#include "Escenario/DirectorFranjasEscenario.h"
#include "Escenario/BuilderFranjasEscenario.h"
#include "Escenario/FranjaInicioBuilder.h"
#include "Escenario/FranjaRioBuilder.h"
#include "Escenario/FranjaCalleBuilder.h"
#include "Escenario/FranjaMedioBuilder.h"
#include "Escenario/FranjaCasaBuilder.h"
#include "Escenario/FabricaPotenciadores.h"
#include "Escenario/Potenciadores.h"
#include "Actores/FabricaActor.h"
#include "InterfazTexto/Marcador.h"
#include "InterfazTexto/CuadroTexto.h"

#include "Actores/Mosca.h"

class GameManager{
	//singleton de GameManager
private:
	//aqui es donde se almacenara la instancia
	static GameManager* instancia;
	//constructor privado para evitar instancias
	GameManager();
public:
	//metodo accesor estatico de instancia
	static GameManager* getInstancia();
//atributos propios privados de la clase
private:
	int dxSapo;
	int dySapo;
	bool gameOver;
	bool ganar;
	MapaElementosPantalla* mapaCaracteresEscenario;

	Panel* pisoJuego;

	//Potenciadores
	Potenciadores* Potenciador01;
	Potenciadores* Potenciador02;
	Potenciadores* Potenciador03;
	Potenciadores* Potenciador04;
	Potenciadores* Potenciador05;
	Potenciadores* Potenciador06;
	
	//Actor independientes;
	Actor* Facundo;
	
	list<Actor*> listaActorFila1;
	list<Actor*> listaActorFila2;
	list<Actor*> listaActorFila3;
	list<Actor*> listaActorFila4;
	list<Actor*> listaActorFila5;

	//Franjas del juego echos con Builder
	DirectorFranjasEscenario DirectorFE; // El director

	//Inicio
	FranjasEscenario* FEInicio;
	FranjaInicioBuilder franjaInicioBuilder;

	//Rio
	FranjasEscenario* FERio;
	FranjaRioBuilder franjaRio;

	//Medio
	FranjasEscenario* FEMedio;
	FranjaMedioBuilder franjaMedio;

	//Calle
	FranjasEscenario* FECalle;
	FranjaCalleBuilder franjaCalle;

	//Casa
	FranjasEscenario* FECasas;
	FranjaCasaBuilder franjaCasas;


	//listas que almacenaran objetos echos por  factory metod
	list<Objetos*> listaObjetos;
	list<Actor*> listaActor;

	CuadroTexto* nombreJugador;

	Marcador* marcadorJuego;

	Mosca* m;

	queue<bool> esta;

public:
	//destructor de la clase
	~GameManager();
	//declaracion de metodos de control
	void Bucle();
	bool Tecla();
	//void IniciarJuego(FabricaActores* _f);//->sin brigge
	void IniciarJuego(FabricaActor* _f);

	// Metodo para determinar la colicion
	void Colision(map<int, ElementoPantalla> _mapaElementosPantalla);
	void GanarPuntos();
	//declaracion de los metodos de movimiento 
	bool moverseJuntos(Actor* actor);
	bool moverseJuntosColi(Actor* actor);
	//declaracion de los metodos comida del sapo y muerte del sapo
	void ComerMosca(map<int, ElementoPantalla> _mapaElementosPantalla);
	void muerteSapo();
	//declaracion de metodos para mostrar objetos y elementos
	int mostrarObjeto(vector<Bloques*>);
	void MostrarMapaElementosPantalla(map<int, ElementoPantalla> _mapaElementosPantalla);
	bool fin();
};