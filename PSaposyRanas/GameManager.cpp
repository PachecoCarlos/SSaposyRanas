#include "GameManager.h"
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include "Utilitarios.h"

//Implementacion del singleton
  //nulo por que la instancia se inicializara bajo demanda
GameManager* GameManager::instancia = 0;
//metodo accesor donde guardamos y retornamos la instancia no se podra instanciar mietras no se llame al metodo
GameManager* GameManager::getInstancia() {
	if (instancia == 0) {
		instancia = new GameManager();
	}
	return instancia;
}

GameManager::GameManager() {
	
	gameOver = false;
	ganar = false;
	mapaCaracteresEscenario = new MapaElementosPantalla (120, 28);
	pisoJuego = new Panel(0, 0, 120, 28, 1, 6, '.', 120, ' ', 0, mapaCaracteresEscenario);

	//pasando el tipo de franja al director de BUILDER
	// Franja Inicio
	DirectorFE.setBuilder(&franjaInicioBuilder);
	FEInicio = DirectorFE.getFranjaEscenario(mapaCaracteresEscenario);

	// Franja Rio
	DirectorFE.setBuilder(&franjaRio);
	FERio = DirectorFE.getFranjaEscenario(mapaCaracteresEscenario);

	// Franja Medio
	DirectorFE.setBuilder(&franjaMedio);
	FEMedio = DirectorFE.getFranjaEscenario(mapaCaracteresEscenario);

	// Franja Calle
	DirectorFE.setBuilder(&franjaCalle);
	FECalle = DirectorFE.getFranjaEscenario(mapaCaracteresEscenario);

	// Franja Casa
	DirectorFE.setBuilder(&franjaCasas);
	FECasas = DirectorFE.getFranjaEscenario(mapaCaracteresEscenario);

	m = new Mosca({ {"* *"},{"[+]"} }, 70, 15, 0, 0, 3, 7, mapaCaracteresEscenario);
	nombreJugador = new CuadroTexto(91, 20, 25, 10, 2, 5, ' ');//
	marcadorJuego = new Marcador(0, 28, 120, 5, 8, 15, 177, 1, 2, 15, '#');
}

GameManager::~GameManager()
{

}

//metodo de control de acciones del sapo determinado colisiones con el enemigo
void GameManager::Bucle() {
	while (!gameOver) {
		//Llama a cada clase Para cada fila determinando el tipo de colision y movimiento que tomara el sapo
		for (auto it = std::begin(listaActorFila1); it != std::end(listaActorFila1); ++it) {
			(*it)->Mover();		
			esta.push(moverseJuntosColi(*it));
			Facundo->Mostrar();
			m->Mostrar();
		}
		
		for (auto it = std::begin(listaActorFila2); it != std::end(listaActorFila2); ++it) {
			(*it)->Mover();
			esta.push(moverseJuntos(*it));
			Facundo->Mostrar();
			m->Mostrar();
		}

		for (auto it = std::begin(listaActorFila3); it != std::end(listaActorFila3); ++it) {
			(*it)->Mover();			
			esta.push(moverseJuntos(*it));
			Facundo->Mostrar();
			m->Mostrar();
		}

		for (auto it = std::begin(listaActorFila4); it != std::end(listaActorFila4); ++it) {
			(*it)->Mover();
			Colision(*(*it)->getMapaElementoPantallaActor());
			m->Mostrar();
		}

		for (auto it = std::begin(listaActorFila5); it != std::end(listaActorFila5); ++it) {
			(*it)->Mover();
			Colision(*(*it)->getMapaElementoPantallaActor());
			m->Mostrar();
		}

		ComerMosca(*m->getMapaElementoPantallaActor());

		muerteSapo();

		if (Tecla()) {
			Facundo->setDX(dxSapo);
			Facundo->setDY(dySapo);
			Facundo->Mover();
			Beep(500,250);
			GanarPuntos();
		}	
		//Si llega a cubrir todas las casas, El jugador gana
		if (Facundo->getPuntos() == 400) {
			ganar = true;
			gameOver = true;
		}
	}
	
}

//metodo de control de teclas para hacer distintas operaciones en el juego
bool GameManager::Tecla() {
	bool teclaPresionada = false;
	dxSapo = 0;
	dySapo = 0;
	
	char key = ';';
	int noPasoCasas = mostrarObjeto(FECasas->getBloquesFE());
	int noPasoMedio = mostrarObjeto(FEMedio->getBloquesFE());
	int noPasoInicio = mostrarObjeto(FEInicio->getBloquesFE());
	int noPasoCalle = mostrarObjeto(FECalle->getBloquesFE());

	if (_kbhit()) {
		key = _getch();
	}

	if (key == 72) {

		if (noPasoCasas == 3 || noPasoMedio == 3 || noPasoInicio == 3 || noPasoCalle == 3)
			dySapo = 0;
		else
			dySapo = -1;
		teclaPresionada = true;
	}

	if (key == 80) {
		if (noPasoCasas == 4 || noPasoMedio == 4 || noPasoInicio == 4 || noPasoCalle == 4)
			dySapo = 0;
		else
			dySapo = 1;
		teclaPresionada = true;
	}

	if (key == 75) {
		if (noPasoCasas == 2 || noPasoMedio == 2 || noPasoInicio == 2 || noPasoCalle == 2)
			dxSapo = 0;
		else
			dxSapo = -1;
		teclaPresionada = true;
	}

	if (key == 77) {
		if (noPasoCasas == 1 || noPasoMedio == 1 || noPasoInicio == 1 || noPasoCalle == 1)
			dxSapo = 0;
		else
			dxSapo = 1;
		teclaPresionada = true;
	}

	if (key == 27) {
		gameOver = true;
	}

	if (key == 113) {
		
	}
	return teclaPresionada;
}
//metodo de para para iniciar juego y mostrar dodos los elementos del juego
void GameManager::IniciarJuego(FabricaActor* _f) {
	nombreJugador->Mostrar();

	marcadorJuego->setNombre(nombreJugador->getTexto());
	pisoJuego->Mostrar();

	//Mostrando las franjas
	FERio->Mostrar();
	FEInicio->Mostrar();
	FEMedio->Mostrar();
	FECalle->Mostrar();
	FECasas->Mostrar();


//Determinan la cantidad de Actores que habra en cada Fila
	for (int i = 0; i < 3; i++) {
		listaActorFila1.push_back(_f->CrearCocodrilo(0 + (i * 50), 10, -1, 0, mapaCaracteresEscenario));
	}

	for (int i = 0; i < 2; i++) {
		listaActorFila3.push_back(_f->CrearTortuga(0 + (i * 50), 6, 1, 0, mapaCaracteresEscenario));
	}

	for (int i = 0; i < 3; i++) {
		listaActorFila2.push_back(_f->CrearTronco(10 + (i * 50), 3, -1, 0, mapaCaracteresEscenario));
	}

	for (int i = 0; i < 3; i++) {
		listaActorFila4.push_back(_f->CrearAuto1(20 + (i * 50), 17, 1, 0, mapaCaracteresEscenario));
	}

	for (int i = 0; i < 2; i++) {
		listaActorFila5.push_back(_f->CrearAuto2(15 + (i * 50), 22, -1, 0, mapaCaracteresEscenario));
	}


	Facundo = _f->CrearSapo(65, 26, 0, 0,mapaCaracteresEscenario);
	Facundo->Mostrar();
	//el marcador almacena los puntos y vidas del sapo
	marcadorJuego->setVidas(Facundo->getVidas());
	marcadorJuego->setPuntos(Facundo->getPuntos());
	marcadorJuego->Mostrar();


	m->Mostrar();

	Bucle();

	Sleep(1000);
	system("cls");
	GameOver(ganar);
	Sleep(2000);
	EstablecerColor(0, 0);
	system("cls");
}

bool GameManager::fin() {
	return gameOver;
}
//implemetacion del metodo comer del sapo
void GameManager::ComerMosca(map<int, ElementoPantalla> _mapaElementosPantalla){
	bool colision = false;
	//Primer for de la mosca
	for (auto it = std::begin(_mapaElementosPantalla); it != std::end(_mapaElementosPantalla); ++it) {
		for (auto it1 = std::begin(*Facundo->getMapaElementoPantallaActor()); it1 != std::end(*Facundo->getMapaElementoPantallaActor()); ++it1) {
			//Si el sapo y la mosca tienen la misma posicion colision es verdad
			if ((*it).first == (*it1).first) {
				colision = true;
				break;
			}
		}
		if (colision)
			break;
	}
	//mietras colision sea verdad entonces el sapo come a la mosca y aumeta su numero de vidas
	if (colision){
		Facundo->setVidas(Facundo->getVidas() + 1);
		m->Mover();
		marcadorJuego->setVidas(Facundo->getVidas());
		marcadorJuego->Mostrar();
	}
}
//metodo de determinacion de colicion del sapo
void GameManager::Colision(map<int, ElementoPantalla> _mapaElementosPantalla){
	bool colision = false;
	//Primer ciclo avatar enemigo
	for (auto it = std::begin(_mapaElementosPantalla); it != std::end(_mapaElementosPantalla); ++it) {
		// Segundo ciclo avatar Sapo
		for (auto it1 = std::begin(*Facundo->getMapaElementoPantallaActor()); it1 != std::end(*Facundo->getMapaElementoPantallaActor()); ++it1) {
			// se va comparando si las llaves son iguales o por lo menos hay un significa cada actor estan en un mismo punto
			if ((*it).first == (*it1).first) {
				Facundo->setVidas(Facundo->getVidas() - 1);
				colision = true;
				break;
			}
		}
		if (colision)
			break;
	}
	if (Facundo->getVidas() == 0)
		gameOver = true;
	//Si existe Colision, facundo toma el desplazamiento del enemigo, y asi permita que se muevan juntos
	if(colision){
		Facundo->setX(65);
		Facundo->setY(26);
		Facundo->setDX(0);
		Facundo->setDY(0);
		Facundo->Mover();
		m->Mover();
		marcadorJuego->setVidas(Facundo->getVidas());
		marcadorJuego->Mostrar();
	}
}

//metodo de  ganar puntos dependiendo si cumplen las acciones que se debe realizar para ganar puntos en el juego 
void GameManager::GanarPuntos(){
	bool punto = false;
	for (auto it = std::begin(*Facundo->getMapaElementoPantallaActor()); it != std::end(*Facundo->getMapaElementoPantallaActor()); ++it) {
		// se va comparando si las llaves son iguales o por lo menos hay un significa cada actor estan en un mismo punto
		//Si el sapo se encuentra en las casas, aumenta puntos
		if ((*it).second.y <= FECasas->getPanelFE()->getY()) {
			punto = true;
			Facundo->setPuntos(Facundo->getPuntos() + 100);
			break;
		}
	}
	//Al ganar puntos, el sapo vuelve al inicio para seguir jugando
	if (punto) {
		Facundo->setX(65);
		Facundo->setY(26);
		Facundo->setDX(0);
		Facundo->setDY(0);
		Facundo->Mover();
		m->Mover();
		marcadorJuego->setPuntos(Facundo->getPuntos());
		marcadorJuego->Mostrar();
	}
}
//metodo de colision con los enemigos que no le agan perder puntos y pueda moverce juntos
bool GameManager::moverseJuntos(Actor* actor){
	map<int, ElementoPantalla> _mapaElementosPantalla = *actor->getMapaElementoPantallaActor();
	int ancho = actor->getNroColumnas();
	int alto = actor->getAvatar().size();
	bool encuentro = false;
	bool rio = false;
	//Primer ciclo for del enemigo
	for (auto it = std::begin(_mapaElementosPantalla); it != std::end(_mapaElementosPantalla); ++it) {
		//Segundo ciclo for del Sapo
		for (auto it1 = std::begin(*Facundo->getMapaElementoPantallaActor()); it1 != std::end(*Facundo->getMapaElementoPantallaActor()); ++it1) {	
			
			//Si Facundo se encuentra dentro del enemigo sin colisionar con sus bordes, El encuentro es vertadero
			if ((*it1).second.x > (*it).second.x && (*it1).second.x + Facundo->getNroColumnas() < (*it).second.x + ancho && (*it1).second.y >= (*it).second.y && (*it1).second.y - 1 < (*it).second.y + alto) {
				encuentro = true;
				break;
			}
		}
		if (encuentro)
			break;
	}
	if (encuentro){
		//Mientras el encuentro sea verdadero, Facundo toma el desplazamiento del enemigo
			Facundo->setDX(actor->getDX());
			Facundo->setDY(0);
			Facundo->Mostrar();
			Facundo->Mover();
		return true;
	}else 
		return false;
	
}
//metodo de determinacion de colision si es verdad o no que se encuentra en la misma posicion del enemigo para que se puedan mover junto a el 
bool GameManager::moverseJuntosColi(Actor* actor){
	map<int, ElementoPantalla> _mapaElementosPantalla = *actor->getMapaElementoPantallaActor();
	int ancho = actor->getNroColumnas();
	int alto = actor->getAvatar().size();
	bool encuentro = false;
	bool rio = false;
	for (auto it = std::begin(_mapaElementosPantalla); it != std::end(_mapaElementosPantalla); ++it) {
		for (auto it1 = std::begin(*Facundo->getMapaElementoPantallaActor()); it1 != std::end(*Facundo->getMapaElementoPantallaActor()); ++it1) {		
			if ((*it1).second.x > (*it).second.x + 15 && 
				(*it1).second.x + Facundo->getNroColumnas() < (*it).second.x + ancho && 
				(*it1).second.y >= (*it).second.y && 
				(*it1).second.y < (*it).second.y + alto) {
				encuentro = true;
				break;
			}
		}
		if (encuentro)
			break;
	}
	if (encuentro){
			Facundo->setDX(actor->getDX());
			Facundo->setDY(0);
			Facundo->Mostrar();
			Facundo->Mover();
			return true;
	}
	else 
		return false;
	
}
//metodo de determinasion de la colicion con el enemigo comprando pisiciones y depende de ello pierda un determinado numero vidas
void GameManager::muerteSapo(){
	bool junto = false;
	bool rio = false;
	for (int i = 0; i < esta.size(); i++) {
		if (esta.front()) {
			junto = true;
		}
		esta.pop();
	}
	if (!junto){
		for (auto it1 = std::begin(*Facundo->getMapaElementoPantallaActor()); it1 != std::end(*Facundo->getMapaElementoPantallaActor()); ++it1) {
			//Si Facundo llega al rio, tiene la misma posicion, disminuye el numero de vidas
			if ((*it1).second.y >= FERio->getPanelFE()->getY() && (*it1).second.y + Facundo->getAvatar().size() <= FERio->getPanelFE()->getY() + 11){
				Facundo->setVidas(Facundo->getVidas() - 1);
				rio = true;
				break;
			}
		}
		if (Facundo->getVidas() == 0)
			gameOver = true;
		//Si cumple el booleano, Facundo vuelve a la vereda
		if (rio){
			Facundo->setX(65);
			Facundo->setY(26);
			Facundo->setDX(0);
			Facundo->setDY(0);
			Facundo->Mover();
			m->Mover();
			marcadorJuego->setVidas(Facundo->getVidas());
			marcadorJuego->Mostrar();
		}
	}
}

//metodo que Permite mostrar los objetos en el juego
int GameManager::mostrarObjeto(vector<Bloques*> bloque){
	int i = 0;
	bool colision = false;
	for (auto it = std::begin(bloque); it != std::end(bloque); ++it) {
		for (auto it1 = std::begin(*Facundo->getMapaElementoPantallaActor()); it1 != std::end(*Facundo->getMapaElementoPantallaActor()); ++it1) {
			//Los condicionales permiten que el sapo no pueda pasar por encima de los obstaculos
			if ((*it1).second.x + Facundo->getNroColumnas() + 1 > (*it)->getX() && (*it1).second.x - 1 < (*it)->getX() + (*it)->getAncho() && (*it1).second.y + Facundo->getAvatar().size() >= (*it)->getY() && (*it1).second.y < (*it)->getY() + (*it)->getAlto() + 1) {
				if ((*it1).second.x + Facundo->getNroColumnas() == (*it)->getX()) {
					i = 1;
				}
				if ((*it1).second.x == (*it)->getX() + (*it)->getAncho()) {
					i = 2;
				}
				if ((*it1).second.y == (*it)->getY() + (*it)->getAlto()) {
					i = 3;
				}
				if ((*it1).second.y + Facundo->getAvatar().size() == (*it)->getY()) {
					i = 4;
				}
				colision = true;
				break;
			}

		}
		if (colision)
			break;
	}
	return i;
}
//metodo que permite mostrar todos los elementos en la patalla de juego
void GameManager::MostrarMapaElementosPantalla(map<int, ElementoPantalla> _mapaElementosPantalla){
	int i = 0;
	for (auto it = std::begin(_mapaElementosPantalla); it != std::end(_mapaElementosPantalla); ++it) {
		gotoxy(1, 27 + i);
		cout << (*it).first << " " << (*it).second.x << " " << (*it).second.y << " " << (*it).second.caracter << " " << (*it).second.colorCaracter << " " << (*it).second.colorFondo << endl;
		i++;
	}
}