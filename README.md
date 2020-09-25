# SaposyRanas
<div>
    <p>
        Videojuego “Sapos y Ranas” en C++ para consola
    </p>
</div>
<p>
    Este es el trabajo resultante del semestre 01/2020, que fue desarrollado por un equipo conformado por el docente de la asignatura y un grupo de estudiantes:
        
   <ul>
        <li>
            Docente: Ing. Carlos Walter Pacheco Lora
        </li>
   </ul>
   <ul>
       <li>
            Univ. Acebey Laime Martin Andres 
       </li>
       <li>
            Univ. Berrios Escalera Abril Johana
       </li>
       <li>
            Univ. Gonzales Tito Sebastian
       </li>
       <li>
            Univ. Taboada Chuve Alexy Sdenka
       </li>
       <li> 
            Univ. Villca Saigua Raul Carmelo
    </li>
       <li>
            Univ. Limachi Carrillo Grover Tomas
       </li>
       <li>
            Univ. Peñafiel Picha Erick Martín
       </li>
 </ul>
 </p>
<p>
    El videojuego “Sapos y Ranas” elaborado en la materia de “Programación
    Avanzada” de la universidad Mayor, Real y Pontificia de San Francisco
    Xavier, está basado en el videojuego árcade clásico “Frogger”, que consiste
    en llevar a una rana a través de ciertos obstáculos evitando que muera.
</p>
<p>
    Para la construcción del juego se utilizó diferentes patrones listados a
    continuación:
</p>
<li>  Abstract factory
    </li>
    <li>
        Adapter
    </li>
    <li>
        Bridge
    </li>
    <li>
        Builder
    </li>
    <li>
        Composite
    </li>
    <li>
        Factory Method
    </li>
    <li>
        Prototype
    </li>
    <li>
        Singleton
    </li>
    <li>
        Strategy
    </li>
</ul>
<p>
    Para una mejor organización de los clases que componen el juego, se las
    dividió en diferentes carpetas:
</p>
<ul>
    <li>
        <strong>Actores: </strong>
        En esta carpeta se encuentran todo lo referente a los diferentes
        personajes del videojuego, su representación visual e incluido el
        movimiento que realizaran.<strong></strong>
    </li>
    <li>
        <strong>Escenario:</strong>
        Aquí esta organizado todo lo que es referente a la visualización del
        escenario, los diferentes objetos que aparecerán en el (Bloques,
        Espinas, CubosEnergia).<strong></strong>
    </li>
    <li>
        <strong>InterfazTexto:</strong>
        En esta carpeta se puede encontrar todas las clases referentes a la
interfaz visual, al menú y al funcionamiento del videojuego.        <strong></strong>
    </li>
</ul>
<h1>
    Patrón Singleton
</h1>
<p>
    Este patrón limita el número de instancias posibles de una clase en nuestro
    programa.
</p>
<p>
    Su intención consiste en garantizar que una clase solo tenga una instancia
    y proporcionar un punto de acceso global a ella.
</p>
<p>
    <img
        width="535"
        height="309"
        src="01.jpg"
        align="left"
        hspace="12"
    />
</p>
<p>
    En el juego se implementa este patrón a la clase GameManager para limitar
    una solo instancia de esta clase, para ello en GameManager.h se declaran la
    variable instancia estática de tipo GameManager en esta variable se
    almacenará la instancia, declaramos constructor privado para evitar
    instancias y declaramos el método acceso getInstancia estática de tipo
    GameManager. En el GameManager.cpp implementamos el patrón donde la
    variable instancia igualamos a cero por que la instancia se inicializara
    bajo demanda y en el método getInstancia almacenamos y retornamos la
    instancia de la clase en la variable instancia.
</p>
<p>
    El las clases NivelAvanzado.h, NivelBasico.h y NivelMedio.h llamamos al
    método accesor getInstancia en vez de instanciar la clase.
</p>
<p>
    <strong>GameManager.h</strong>
</p>
<p>
    class GameManager {
</p>
<p>
    //simgleton de GameManager
</p>
<p>
    private:
</p>
<p>
    static GameManager* instancia; //aqui es donde se almacenara la instancia
</p>
<p>
    GameManager(); //constructor privado para evitar instancias
</p>
<p>
    public:
</p>
<p>
    static GameManager* getInstancia(); //metodo accesor estatico de instancia
</p>
<p>
    }
</p>
<p>
    <strong>GameManager.cpp</strong>
</p>
<p>
    <strong></strong>
</p>
<p>
    //implementacion del singleton
</p>
<p>
    GameManager* GameManager::instancia = 0; //nulo por que la instancia se
    inicializara bajo demanda
</p>
<p>
    GameManager* GameManager::getInstancia() { //metodo accesor donde gurdamos
    la instancia no se podra instanciar mietras no se llame al metodo
</p>
<p>
    if (instancia == 0) {
</p>
<p>
    instancia = new GameManager();
</p>
<p>
    }
</p>
<p>
    return instancia;
</p>
<p>
    }
</p>
<p>
    GameManager::GameManager() {}
</p>
<p>
    Llamamos al método getInstacia en las clases NivelAvanzado, NivelBasico y
    NivelIntermedio
</p>
<h1>
    Patrón Abstract Factory (Fabrica Abstracta)
</h1>
<p>
    Este patrón nos provee un método (interfaz) que delega la creación de un
    conjunto de objetos relacionados busca agrupar un conjunto de clases que
    tiene un funcionamiento en común.
</p>
<p>
    <img
        width="438"
        height="248"
        src="02.jpg"
        align="left"
        hspace="12"
    />
    En el Juego se implementa el patrón para fabricar actores, donde la clase
    Actor es una clase abstracta es abstracta porque tiene un método virtual
    int dano()=0 esta clase es la clase padre que tiene sus respectivos
    atributos , métodos y métodos acceso res. Donde las clases hijas Auto,
    Cocodrilo, Mosca, Sapo, Tortuga y Tronco heredan de clase padre Actor y el
    método virtual dano() se sobre escribe obligatoriamente en todas las clases
    hijas.
</p>
<p>
    La Clase padre FabricaActor abstracta tiene atributos y los métodos
    virtuales de tipo Actor (ej. Virtual Actor* crearSapo()=0) estos métodos
    creados sobrecargaran (se sobre escribirá) obligatoriamente las diferentes
    fabricas especializadas, como FabricaActorNivelAvanzado,
    FabricaActorNivelBasico y FabricaActorNivelMedio son clases hijas que
    heredan de la clase padre FabricaActor que a la ves estas clase hijas tiene
    su propios atributos privado.
</p>
<p>
    La creación de los objetos es gracias a los métodos virtuales mencionados
    anteriormente, que relacionan a las tres clases que tienen funcionamiento
    en común.
</p>
<p>
    Las clases que heredan de la clase actor son todos las actores del juego
    son parte de la aplicación del patrón Abstract Factory
</p>
<p>
    Clase abstracta para la aplicación del patrón que contiene
    métodos(interfaz) para la creación de un conjunto de objetos.
</p>
<p>
    <strong>FabricaActor.h</strong>
</p>
<p>
    /*esta es la interfaz necesaria en abstract Factory -&gt;clase padre
    abstracta*/
</p>
<p>
    class FabricaActor {
</p>
<p>
    public:
</p>
<p>
    //constructor de la clase
</p>
<p>
    FabricaActor() {
</p>
<p>
    anchoTortuga = anchoCorrect(avatarTortuga);
</p>
<p>
    anchoCocodrilo = anchoCorrect(avatarCocodrilo);
</p>
<p>
    anchoAuto1 = anchoCorrect(avatarAuto1);
</p>
<p>
    anchoAuto2 = anchoCorrect(avatarAuto2);
</p>
<p>
    anchoTronco = anchoCorrect(avatarTronco);
</p>
<p>
    }
</p>
<p>
    //creando metodos que las fabrizas especializadas sobrecargaran
    obligatoriamente
</p>
<p>
    virtual Actor* CrearSapo(int _x, int _y, int _dx, int _dy,
    MapaElementosPantalla* m) = 0;
</p>
<p>
    virtual Actor* CrearCocodrilo(int _x, int _y, int _dx, int _dy,
    MapaElementosPantalla* m) = 0;
</p>
<p>
    virtual Actor* CrearAuto1(int _x, int _y, int _dx, int _dy,
    MapaElementosPantalla* m) = 0;
</p>
<p>
    virtual Actor* CrearAuto2(int _x, int _y, int _dx, int _dy,
    MapaElementosPantalla* m) = 0;
</p>
<p>
    virtual Actor* CrearTortuga(int _x, int _y, int _dx, int _dy,
    MapaElementosPantalla* m) = 0;
</p>
<p>
    virtual Actor* CrearTronco(int _x, int _y, int _dx, int _dy,
    MapaElementosPantalla* m) = 0;
</p>
<p>
    Las clases FabricaActorNivelAvanzado, FabricaActorNivelBasico y
    FabricaActorNivelMedio Sobrecargan los métodos creados en
    FabricaActor(clase padre) para su posterior fabrica de actores
</p>
<p>
    Ejemplo :
</p>
<p>
    FabricaActorNivelAvanzado.h
</p>
<p>
    #include "FabricaActor.h"
</p>
<p>
    //clase hija que hereda de la clase padre fabricaActor relacionados que
    tienen un funcionamiento en común(aplicando el patron Abstrac Fatory)
</p>
<p>
    class FabricaActorNivelAvanzado :public FabricaActor {
</p>
<p>
    private:
</p>
<p>
    //atributos privados propios de la clase estaticos
</p>
<p>
    static int NumeroEnemigosA1;
</p>
<p>
    static int NumeroEnemigosA2;
</p>
<p>
    static int NumeroEnemigosA3;
</p>
<p>
    static int NumeroEnemigosA4;
</p>
<p>
    static int NumeroEnemigosA5;
</p>
<p>
    public:
</p>
<p>
    //sobrecarga de metodos de la clase padre obligatorio
</p>
<p>
    Actor* CrearSapo(int _x, int _y, int _dx, int _dy, MapaElementosPantalla*
    m);
</p>
<p>
    Actor* CrearCocodrilo(int _x, int _y, int _dx, int _dy,
    MapaElementosPantalla* m);
</p>
<p>
    Actor* CrearAuto1(int _x, int _y, int _dx, int _dy, MapaElementosPantalla*
    m);
</p>
<p>
    Actor* CrearAuto2(int _x, int _y, int _dx, int _dy, MapaElementosPantalla*
    m);
</p>
<p>
    Actor* CrearTortuga(int _x, int _y, int _dx, int _dy,
    MapaElementosPantalla* m);
</p>
<p>
    Actor* CrearTronco(int _x, int _y, int _dx, int _dy, MapaElementosPantalla*
    m);
</p>
<p>
    };
</p>
<p>
    }
</p>
<p>
    En la clase FabricaActorNivelAvanzado.cpp solo se esta instanciando los
    actores, y se está retornando.
</p>
<h1>
    Patrón Composite
</h1>
<p>
    El patrón de diseño Composite nos sirve para construir estructuras
    complejas partiendo de otras estructuras mucho más simples, dicho de otra
    manera, podemos crear estructuras compuestas las cuales están conformadas
    por otras estructuras más pequeñas.
</p>
<p>
    <img
        width="642"
        height="254"
        src="03.jpg"
        align="left"
        hspace="12"
    />
    Compone objetos en estructuras de árbol para jerarquías de parte-todo.
    Permite que los clientes traten de manera uniforme a los objetos
    individuales y a los compuestos.
</p>
<h2>
    Participantes
</h2>
<p>
    · Componente: Generalmente es una interface o clase abstracta la cual tiene
    las operaciones mínimas que serán utilizadas, este componente deberá ser
    extendido por los otros dos componentes, hojas, y compuestos.
</p>
<p>
    · Hoja: Representa la parte más simple o pequeña de toda la estructura.
</p>
<p>
    · Compuesto: Define el comportamiento de los componentes hijo, almacena a
    componentes hijos, implementa las operaciones de la interfaz Componente
    relacionadas con los hijos
</p>
<p>
    El componente en el juego es la clase ComponenteIT.h que esta heredando de
    ObjetoIt.h todas sus características.
</p>
<p>
    En el juego se define una clase Composite.h que podrá manejar cualquier
    tipo de componente usando template, de esta clase podrá contener otras
    clases hijas de tipo componente ya definiendo sus métodos para poder
    agregar hijos o eliminarlos y acceder a ellos.
</p>
<p>
    Como el patrón composite puede tener otras hojas tipo composite y estos
    mismos pueden tener otros componentes compuestos.
</p>
<p>
    using namespace std;
</p>
<p>
    // El template maneja cualquier tipo de clase
</p>
<p>
    template&lt;typename Componente&gt;
</p>
<p>
    // Se está creando la clase componente que desciende de un template tipo
    componente
</p>
<p>
    class Composite : public Componente
</p>
<p>
    {
</p>
<p>
    protected:
</p>
<p>
    //Va a almacenar hijos de tipo componente
</p>
<p>
    vector&lt;Componente*&gt; hijos; //Lista de los hijos componentes.
</p>
<p>
    public:
</p>
<p>
    // Se crea un tipo de dato que valga igual
    vector&lt;Componente*&gt;::iterator
</p>
<p>
    Typedef typename vector&lt;Componente*&gt;::iterator IteradorHijo;
</p>
<p>
    // Método para añadir un hijo
</p>
<p>
    void AgregarHijo(Componente* hijo)
</p>
<p>
    {
</p>
<p>
    // Le pasa un hijo tipo componente
</p>
<p>
    // se busca de principio a fin buscando hijo
</p>
<p>
    // Si lo encuentra lo guarda en itr
</p>
<p>
    // Si no manda la dirección final y añade
</p>
<p>
    IteradorHijo itr = find(hijos.begin(), hijos.end(), hijo);
</p>
<p>
    if (itr == hijos.end())
</p>
<p>
    {
</p>
<p>
    hijos.push_back(hijo);
</p>
<p>
    }
</p>
<p>
    }
</p>
<p>
    void EliminarHijo(Componente* hijo)
</p>
<p>
    {
</p>
<p>
    IteradorHijo itr = find(hijos.begin(), hijos.end(), hijo);
</p>
<p>
    if (itr != hijos.end())
</p>
<p>
    {
</p>
<p>
    hijos.erase(itr);
</p>
<p>
    }
</p>
<p>
    }
</p>
<p>
    void VaciarHijos()
</p>
<p>
    {
</p>
<p>
    hijos.clear();
</p>
<p>
    }
</p>
<p>
    };
</p>
<p>
    Las hojas de este Composite seria: Panel.h, Marcador.h, Botón.h, Marco.h,
    Etiqueta.h, Menu.h, Panel.h; cada uno de estos puede contener sus propias
    hojas (hijos), además que cada uno tiene sus propios atributos y métodos.
</p>
<p>
    En Interfaz.cpp se añaden unos dentro de otros formando parte del Interfaz
    de texto.
</p>
<h1>
    Patrón Strategy
</h1>
<p>
    <img
        width="576"
        height="206"
        src="04.jpg"
        align="left"
        hspace="12"
    />
    Es una alternativa a la herencia múltiple. Las estrategias permiten
    configurar una clase con un determinado comportamiento de entre muchos
    posibles. Se Implementa cuando se necesitan distintas variantes de un
    algoritmo. En lugar de tener muchas condicionales, podemos mover las ramas
    de estos a sus propias estrategias.
</p>
<h2>
    Participantes
</h2>
<p>
    · Estrategia: Declara una interfaz común a todos los algoritmos permitidos.
    El contexto usa esta interfaz para llamar al algoritmo definido por una
    Estrategia Concreta.
</p>
<ul>
    <li>
        Estrategia concreta
    </li>
</ul>
<p>
    · Contexto: Se configura con un objeto estrategia Concreta. Mantiene una
    referencia a un objeto estrategia Puede definir una interfaz que permite a
    la Estrategia acceder a sus datos.
</p>
<p>
    En el juego se implementa el patrón strategy con las clases: ObjetoIT.h,
    NivelBasico.h, NivelMedio.h, NivelAvanzado.h, ObjetoSalir.h,
    SelecciónObjetoIT.h.
</p>
<p>
    Ø <strong><em>Estrategia</em></strong> (SelecciónObjetoIT.h)
</p>
<p>
    Definimos la interfaz Strategy de la cual crearemos estrategias puntuales
    (presEnter() y fin()) para cada caso.
</p>
<p>
    // clase Abstracta para seleccionar un objeto
</p>
<p>
    class SeleccionObjetoIT
</p>
<p>
    {
</p>
<p>
    public:
</p>
<p>
    virtual void presEnter() = 0;
</p>
<p>
    virtual bool fin() = 0;
</p>
<p>
    };
</p>
<p>
    Ø <strong><em>Estrategia Concreta </em></strong>(NivelBasico.h,
    NivelMedio.h, NivelAvanzado.h, SeleccionSalir.h)
</p>
<p>
    Son las implementaciones de las estrategias, cada nivel será una diferente
    variante de las estrategias puntuales.
</p>
<p>
    Ejemplos:
</p>
<p>
    // nivel de dificultad del juego basico
</p>
<p>
    class NivelBasico :
</p>
<p>
    public SeleccionObjetoITh
</p>
<p>
    {
</p>
<p>
    public:
</p>
<p>
    FabricaActor* faNivelBasico = new FabricaActorNivelBasico;
</p>
<p>
    GameManager* gm01 = GameManager::getInstancia();
</p>
<p>
    void presEnter() {
</p>
<p>
    gm01-&gt;IniciarJuego(faNivelBasico);
</p>
<p>
    }
</p>
<p>
    bool fin() {
</p>
<p>
    return gm01-&gt;fin();
</p>
<p>
    }
</p>
<p>
    };
</p>
<p>
    //--------------------------------------------------------------------------
</p>
<p>
    // desciende de SeleccionObjetoIT
</p>
<p>
    class ObjetoSalir :
</p>
<p>
    public SeleccionObjetoIT
</p>
<p>
    {
</p>
<p>
    public:
</p>
<p>
    bool pres = false;
</p>
<p>
    void presEnter() {
</p>
<p>
    pres = true;
</p>
<p>
    }
</p>
<p>
    bool fin() {
</p>
<p>
    return pres;
</p>
<p>
    }
</p>
<p>
    };
</p>
<p>
    Ø <strong><em>Contexto </em></strong>(ObjetoIT.h)
</p>
<p>
    #pragma once
</p>
<p>
    #include "SeleccionObjetoIT.h"
</p>
<p>
    // clase abstracta de la cual heredaran sus componentes sus clases hijas
</p>
<p>
    class ObjetoIT
</p>
<p>
    {
</p>
<p>
    // Propiedades generales que tiene un objeto
</p>
<p>
    private:
</p>
<p>
    int x;
</p>
<p>
    int y;
</p>
<p>
    int ancho;
</p>
<p>
    int alto;
</p>
<p>
    int colorFondoBase;
</p>
<p>
    int colorCaracterBase;
</p>
<p>
    char caracterBase;
</p>
<p>
    bool seleccionado;
</p>
<p>
    bool visible;
</p>
<p>
    SeleccionObjetoIT* seleccion;
</p>
<p>
    public:
</p>
<p>
    //se crean constructores según la utilidad
</p>
<p>
    ObjetoIT(int _x, int _y, int _ancho, int _alto, int _colorFondoBase, int
    _colorCaracterBase, char _caracterBase);
</p>
<p>
    ObjetoIT(int _x, int _y);
</p>
<p>
    ObjetoIT() {};
</p>
<p>
    ------------------------------------------
</p>
<p>
    //permite definir el método seleccionado
</p>
<p>
    void setSeleccionObjetoIT(SeleccionObjetoIT* _obj) { seleccion = _obj; }
</p>
<p>
    //permite acceder a sus datos
</p>
<p>
    virtual void preEnter();
</p>
<p>
    void ObjetoIT::preEnter()
</p>
<p>
    {
</p>
<p>
    seleccion-&gt;presEnter();
</p>
<p>
    }
</p>
<p>
    <strong></strong>
</p>
<p>
    virtual bool fin();
</p>
<p>
    {
</p>
<p>
    return seleccion-&gt;fin()
</p>
<p>
    }
</p>
<p>
    ----------------------------------------
</p>
<p>
    virtual void Mostrar() = 0;
</p>
<p>
    // se crean sus métodos de acceso
</p>
<h1>
    Patrón Adapter
</h1>
<p>
    Este patrón permite a dos clases con diferentes interfaces trabajar entre
    ellas a través de un objeto intermedio con el que se comunican e
    interactúan.
</p>
<p>
    Para ello, un objeto adaptador reenvía al otro objeto los datos que recibe
    (a través de los métodos que implementa, definidos en una clase abstracta o
    interface) tras manipularlos en caso necesario.
</p>
<p>
    Este patrón se aplicó para el actor águila donde las clases que interactúan
son <strong>Actor, Águila y AguilaAdapter. </strong>Las clases    <strong>Actor y Águila</strong> trabajan entre ellas, aunque tengan
interfaces diferentes donde se comunican por la clase    <strong>AguilaAdapter </strong>trabaja como objeto intermedio donde
    interactúan atreves se ella.
</p>
<table cellpadding="0" cellspacing="0">
    <tbody>
        <tr>
            <td width="321" height="0">
            </td>
        </tr>
        <tr>
            <td>
            </td>
            <td>
                <img
                    width="363"
                    height="0"
                    src="05.jpg"
                />
            </td>
        </tr>
    </tbody>
</table>
<br clear="ALL"/>
<p>
    La clase
</p>
<strong>AguilaAdapter</strong>
<p>
    hace herencia de las clases padres
</p>
<strong>Actor y Aguila</strong>
<p>
    donde hereda sus atributos y el método mostrar de Actor, ya que de la misma
    manera puede heredar de la clase Águila ya estas interactúan entre ellas.
</p>
<p>
    Las clases Águila y AguilaAdapter están excluidos del proyecto por razones
    de que este actor no se esta incluido en el juego, pero de esa manera se
    implementa este patrón si se desea implementar.
</p>
<p>
    <strong>Aguila.h</strong>
</p>
<p>
    class Aguila
</p>
<p>
    {
</p>
<p>
    //atributos propios de la clase de tipo privado
</p>
<p>
    private:
</p>
<p>
    string NombreAguila;
</p>
<p>
    string RepresentacionVisual;
</p>
<p>
    int PosicionXI;
</p>
<p>
    int PosicionXD;
</p>
<p>
    int PosicionYS;
</p>
<p>
    int PosicionYI;
</p>
<p>
    public:
</p>
<p>
    //constructor de la clase publica
</p>
<p>
    Aguila(string Nombre, string RepresentacionVisual, int _PosicionXI, int
    _PosicionXD, int _PosicionYS, int PosicionYI);
</p>
<p>
    //metodos publicos declarados de la clase
</p>
<p>
    void VisualizarEnPantalla();
</p>
<p>
    void AtraparAnimal() {};
</p>
<p>
    };
</p>
<p>
    <strong>Aguila.cpp</strong>
</p>
<p>
    Aguila::Aguila(string _NombreAguila, string _RepresentacionVisual, int
    _PosicionXI, int _PosicionXD, int _PosicionYS, int _PosicionYI) :
    NombreAguila(_NombreAguila), RepresentacionVisual(_RepresentacionVisual),
</p>
<p>
    PosicionXI(_PosicionXI), PosicionXD(_PosicionXD),
</p>
<p>
    PosicionYS(_PosicionYS), PosicionYI(_PosicionYI)
</p>
<p>
    {
</p>
<p>
    }
</p>
<p>
    void Aguila::VisualizarEnPantalla()
</p>
<p>
    {
</p>
<p>
    gotoxy(PosicionXI, PosicionYI);
</p>
<p>
    cout &lt;&lt; RepresentacionVisual &lt;&lt; "\nBBBBB" &lt;&lt; "\nAAAAAA"
    &lt;&lt; endl;
</p>
<p>
    }
</p>
<p>
    AguilaAdapter.h esta clase hace herencia de las clases Actor y Aguila donde
    trabajan juntas
</p>
<p>
    #include "Actores.h"
</p>
<p>
    #include "Aguila.h"
</p>
<p>
    //clase hija que interactua como objeto intermedio para que las clases
    actor y Aguila trabajen entre ellas
</p>
<p>
    class AguilaAdapter :
</p>
<p>
    public Actores, public Aguila
</p>
<p>
    {
</p>
<p>
    public:
</p>
<p>
    //contructor de la clase
</p>
<p>
    AguilaAdapter(vector&lt;string&gt; _avatar, int _x, int _y, int _dx, int
    _dy, int _limiteSuperior, int _limiteInferior, int _limiteIzquierda, int
    _limiteDerecha, MapasCaracteres* _mce);
</p>
<p>
    void Mostrar();//metodo heredado de actor
</p>
<p>
    void MostrarInformacionClase();//metodo propio de la clase
</p>
<p>
    //metodo inline de representacion visual del avatar de tipo string que
    retorna valor del mismo tipo
</p>
<p>
    inline string AvatarARepresentacionVisual(vector&lt;string&gt; _avatar) {
</p>
<p>
    string rvt = "";
</p>
<p>
    for (int i = 0; i &lt; _avatar.size(); i++) {
</p>
<p>
    for (int j = 0; j &lt; _avatar[i].length(); j++) {
</p>
<p>
    rvt = rvt + _avatar[i][j];
</p>
<p>
    }
</p>
<p>
    //rvt = rvt + '\n';
</p>
<p>
    }
</p>
<p>
    return rvt;
</p>
<p>
    }
</p>
<p>
    AguilaAdapter.cpp
</p>
<p>
    #include "AguilaAdapter.h"
</p>
<p>
    //inplementacion del constructor de la clase
</p>
<p>
    AguilaAdapter::AguilaAdapter(vector&lt;string&gt; _avatar, int _x, int _y,
    int _dx, int _dy, int _limiteSuperior, int _limiteInferior, int
    _limiteIzquierda, int _limiteDerecha, MapasCaracteres* _mce)
    :Aguila("NombreAguila", AvatarARepresentacionVisual(_avatar), _x, _x + 5,
    _y, _y), Actores(_avatar, _x, _y, _dx, _dy, _limiteSuperior,
    _limiteInferior, _limiteIzquierda, _limiteDerecha, _mce) {
</p>
<p>
    }
</p>
<p>
    //inplementacion del metodo heredado de actor
</p>
<p>
    void AguilaAdapter::Mostrar()
</p>
<p>
    {
</p>
<p>
    VisualizarEnPantalla();
</p>
<p>
    }
</p>
<p>
    //inplementacion del metodo propio de la clase
</p>
<p>
    void AguilaAdapter::MostrarInformacionClase()
</p>
<p>
    {
</p>
<p>
    }
</p>
<h1>
    Patrón de Creación – Factory Method
</h1>
<p>
    Este patrón de creación define una interfaz para crear un objeto, pero
    delega la creación del objeto a sus subclases. En la aplicabilidad que se
    le puede dar a este patrón, se la puede usar cuando no se puede prever
    cuantas clases de objetos serán utilizados y cuando se quiere delegar su
    creación a una interfaz que los vaya manejando.
</p>
<p>
    Para comenzar a utilizar el patrón Factory Method, se requiere de una clase
    que sea el creador con una función static que se encargará de devolver el
    objeto que sea requerido, en este caso del videojuego “Sapos y Ranas” el
    creador será la clase Objetos, una clase abstracta de la cual se heredara
    el método Mostrar que es una función virtual pura, esta clase se define de
    la siguiente forma:
</p>
<p>
    <strong>
        Implementación del constructor y el método static (Objeto.cpp)
    </strong>
</p>
<p>
    //Aquí se puede observar la implementación de la función static que creara
    los objetos según el "tipoObjeto" que se le mande y retornara ese objeto
    creado con los diferentes valores que requiere el cliente"
</p>
<p>
    Objetos* Objetos::getObjeto(string _tipoObjeto, int _x, int _y, int _ancho,
    int _alto)
</p>
<p>
    {
</p>
<p>
    if (_tipoObjeto == "Espina")
</p>
<p>
    return new Espinas(1, "espina01", _x, _y, _ancho, _alto, 'X', 0);
</p>
<p>
    else if (_tipoObjeto == "Bloque")
</p>
<p>
    return new Bloques(1, "bloque01", _x, _y, _ancho, _ancho, '#', 0, 0);
</p>
<p>
    else if (_tipoObjeto == "CuboEnergia")
</p>
<p>
    return new CubosEnergia(1, "cuboenergia01", _x, _y, _ancho, _alto, '@', 5,
    1);
</p>
<p>
    else
</p>
<p>
    return NULL;
</p>
<p>
    }
</p>
<p>
    <strong></strong>
</p>
<p>
    Como puede observarse en el código, es necesario definir e implementar una
    función static que será la interfaz de creación de los diferentes objetos,
    en base al tipo de objeto que se requiera.
</p>
<p>
    Y para finalizar su implementación en el cliente (GameManager) se hace de
    la siguiente manera:
</p>
<p>
    <strong>GameManager.h</strong>
</p>
<p>
    <strong>
        <br/>
    </strong>
    //Para facilitar la visualización de este objeto se crea una lista que
    almacenara los diferentes objetos creados<strong></strong>
</p>
<p>
    list&lt;Objetos*&gt; listaObjetos;
</p>
<p>
    <strong>Implementación del patrón – GameManager.cpp</strong>
</p>
<p>
    <strong></strong>
</p>
<p>
    //Para la creacion de este objeto se puede observar como se le pasa el tipo
    de objeto requerido y se lo añade a la lista
</p>
<p>
    listaObjetos.push_back(Objetos::getObjeto("Espina", 5, 15, 4, 3));
</p>
<p>
    listaObjetos.push_back(Objetos::getObjeto("Bloque", 20, 4, 10, 5));
</p>
<p>
    listaObjetos.push_back(Objetos::getObjeto("CuboEnergia", 50, 4, 1, 1));
</p>
<p>
    Como se puede observar la implementación de este patrón es sencilla, pero
    se excluye del juego ya que los diferentes objetos que son requeridos en el
    juego como ser: “Espinas”, “CubosEnergia” y “Bloque”, ya han sido
    implementados con el patrón Builder y se crean a partir de ahí, sin
    embargo, este es otra opción con la cual se puede obtener el mismo
    resultado.
</p>
<h1>
    Prototype
</h1>
<p>
    Permite crear objetos prediseñados sin conocer detalles de cómo crearlos.
    Esto lo logra especificando los prototipos de objetos a crear. El concepto
    de este patrón es simple: en lugar de crear un objeto, se clona, es decir,
    se realiza una copia exacta de otro objeto dado, el cual tiene como
    finalidad crear nuevos objetos duplicándolos, clonando una instancia creada
    previamente, lo cual permite reducir la herencia y la cantidad de clases
    innecesarias.
</p>
<p>
    <img
        width="322"
        height="0"
        src="06.jpg"
        align="left"
        hspace="12"
        alt="Prototype en UML"
    />
    Uno de los puntos del patrón es que un programa puede dinámicamente añadir
    y borrar objetos prototipo en tiempo de ejecución. Esta es una ventaja que
    no ofrece ninguno de los otros patrones de creación, esto mismo esconde los
    nombres de los productos específicos al cliente.
</p>
<h2>
    Implementación en el código
</h2>
<p>
    Para la implementación de este patrón creamos las clases, que
    relacionándolo con el esquema tenemos:
</p>
<ul>
    <li>
        Potenciadores (abstract)
    </li>
</ul>
<p>
    · PotenciadoresConcretosTipo1 (PrototipoConcreto1)
</p>
<p>
    · PotenciadoresConcretosTipo2 (PrototipoConcreto2)
</p>
<p>
    Clase Potenciadores:
</p>
<p>
    Para la implementación del patrón la clase debe ser una clase abstracta, el
    cual nos permite clonar, esta debe ser de tipo virtual puro, es decir, que
    no se puede declarar en la clase Potenciadores, pero sí de forma obligada
    en sus clases hijas.
</p>
<p>
    class Potenciadores :
</p>
<p>
    public Objetos
</p>
<p>
    {
</p>
<p>
    private:
</p>
<p>
    string tipo;
</p>
<p>
    int velocidad;
</p>
<p>
    int salto;
</p>
<p>
    int energia;
</p>
<p>
    int escudo;
</p>
<p>
    int vidas;
</p>
<p>
    public:
</p>
<p>
    //Constructor
</p>
<p>
    Potenciadores(int _x, int _y, int _ancho, int _alto, char _caracter, int
    _colorFondo, int _colorCaracter, MapaElementosPantalla* _mc,
</p>
<p>
    int _velocidad, int _salto, int _energia, int _escudo, int _vidas);
</p>
<p>
    //acorde al patron prototype, debemos crear un metodo de tipo virtual y
    abstracto para poder clorar
</p>
<p>
    virtual Potenciadores* Clonar() = 0;
</p>
<p>
    void Mostrar();}
</p>
<p>
    Dentro de las clases Hijas:
</p>
<p>
    Dentro del constructor luego de definir los parámetros concretos que se
    está utilizando para una determinada clase, definimos un método asesor”
    setTipo” que permita determinar el tipo concreto que es, esta puede ser un
    entero, string, etc.
</p>
<p>
    Dentro del método Clonar, retorna un nuevo objeto de la clase donde está
    definido el método clon, a esta se le pasa un puntero que hace referencia a
    todos los parámetros que recibe en la clase.
</p>
<p>
    PotenciadoresContretosTipo1::PotenciadoresContretosTipo1(int _x, int _y,
    int _ancho, int _alto, char _caracter, int _colorFondo, int _colorCaracter,
    MapaElementosPantalla* _mc,int _velocidad, int _salto, int _energia, int
    _escudo, int _vidas) :Potenciadores(_x, _y, _ancho, _alto, _caracter,
    _colorFondo, _colorCaracter, _mc, _velocidad, _salto, _energia, _escudo,
    _vidas)
</p>
<p>
    {
</p>
<p>
    setTipo("PotenciadorTipo1");
</p>
<p>
    }
</p>
<p>
    Potenciadores* PotenciadoresContretosTipo1::Clonar()
</p>
<p>
    {
</p>
<p>
    return new PotenciadoresContretosTipo1(*this);
</p>
<p>
    }
</p>
<h1>
    Bridge
</h1>
<p>
    · “También conocido como Handle/Body, es una técnica usada en programación
    para desacoplar una abstracción de su implementación, no une
    permanentemente una implementación a una interfaz, sino que la
    implementación puede configurarse en tiempo de ejecución de manera que
    ambas puedan ser modificadas independientemente sin necesidad de alterar
    por ello la otra”.
</p>
<p>
    · Logra minimizar el acoplamiento, hacer que las clases dependan de
    abstracciones en lugar de depender de implementaciones, prefiere el uso de
    composición antes que el uso de herencia.
</p>
<p>
    · Mejora la extensibilidad, podemos extender las jerarquías de Abstracción
    y de Implementador de forma independiente.
</p>
<ul>
    <li>
        <img
            width="589"
            height="0"
            src="07.jpg"
            align="left"
            hspace="12"
            alt="Bridge classdia.png"
        />
        Oculta detalles de implementación a los clientes, se puede aislar a los
        clientes de los detalles de implementación, como el compartimiento de
        objetos implementadores y el correspondiente mecanismo de conteo de
        referencias.
    </li>
</ul>
<h2>
    Implementación en el código
</h2>
<p>
    Para la implementación del patrón, utilizamos las siguientes clases:
</p>
<ul>
    <li>
        ActorMovimiento (Clase Padre)
    </li>
</ul>
<p>
    · ActorMovimientoAleatorio(Clase Hija)
</p>
<p>
    · ActorMovimientoNormal(Clase Hija)
</p>
<p>
    Clase Padre:
</p>
<p>
    Dentro de la clase padre, creamos un método el cual sea virtual puro
    “Mostrar Mover” el cual obligatoriamente debe implementarse en las clases
    hijas.
</p>
<p>
    Clases Hijas:
</p>
<p>
    Dentro de las clases hijas, implementamos las clases Mostrar y Mover,
    nótese que en cada clase permite mover y mostrar al actor pero de diferente
    manera, esto es lo que permite el patrón bridge, el cual logra que cada
    hija logre implementar el mismo método pero de diferente manera.
</p>
<h3>
    En La Clase Actormovimientoaleatorio:
</h3>
<p>
    void ActorMovimientoAleatorio::Mostrar(){//aquí dentro se implementa un
    método de mostrar movimiento aleatorio}
</p>
<h3>
    En la Clase ActorMovimientoNormal:
</h3>
<p>
    void ActorMovimientoNormal::Mostrar() {//aquí dentro se implementa un
    método de mostrar el movimiento normal
</p>
<p>
    //}
</p>
<p>
    Ahora bien ¿Cómo hacemos para que las clases sepan que movimiento deben
    implementar? En este caso creamos el constructor de la clase por defecto y
    dentro de ella creamos una variable “movimientoActor” la cual permite crear
    un nuevo objeto, y le digo que tipo de comportamiento o implementación le
    voy a asignar, permitiendo así conocer cómo se va amostrar y mover.
</p>
<p>
    en la clase auto, toma el movimiento normal
</p>
<p>
    Auto::Auto(vector&lt;string&gt; _avatar, int _x, int _y, int _dx, int _dy,
    int _colorCaracter, int _colorFondo, MapaElementosPantalla* m)
</p>
<p>
    :Actor(_avatar, _x, _y, _dx, _dy, _colorCaracter, _colorFondo, m) {
</p>
<p>
    movimientoActor = new ActorMovimientoNormal(&amp;_avatar, &amp;_x, &amp;_y,
    &amp;_dx, &amp;_dy, &amp;_colorCaracter, &amp;_colorFondo, m);
</p>
<p>
    }
</p>
<p>
    Sin embargo, para la clase Mosca toma un movimiento Aleatorio
    Mosca::Mosca(vector&lt;string&gt; _avatar, int _x, int _y, int _dx, int
    _dy, int _colorCaracter, int _colorFondo, MapaElementosPantalla* m) :
</p>
<p>
    Actor(_avatar, _x, _y, _dx, _dy, _colorCaracter, _colorFondo, m) {
</p>
<p>
    movimientoActor = new ActorMovimientoAleatorio(&amp;_avatar, &amp;_x,
    &amp;_y, &amp;_dx, &amp;_dy, &amp;_colorCaracter, &amp;_colorFondo, m);
</p>
<p>
    }
</p>
<h1>
    Patrón de Creación - Builder
</h1>
<p>
    Este patrón tiene la función que tiene este patrón es la construcción de
    objetos complejos a partir de la abstracción de los elementos que lo
    compondrán. Como ejemplo consideremos que se quiere construir un auto, para
    la construcción de este objeto complejo es necesaria sus partes como
    podrían ser: motor, neumáticos, carrocería, batería. Al igual con este
    patrón se puede crear diferentes representaciones de este objeto con solo
    algunas partes de la cual lo componen.
</p>
<p>
    <img
        width="440"
        height="221"
        src="08.jpg"
    />
</p>
<h2>
    Esquema Base del Patrón
</h2>
<p>
    En el videojuego “Sapos y ranas”, este patrón se implementó en la
    construcción de las diferentes franjas que hay en el escenario puesto en el
    juego, como los que serían “FranjaInicioBuilder”, “FranjaCalleBuilder”,
    “FranjaMedioBuilder”, “FranjaCasasBuilder” y “FranjaRioBuilder”.
</p>
<p>
    Primero necesitamos una clase que sea el producto final de todo el patrón,
    esta vendría a ser “FranjasEscenario” con los diferentes componentes que se
    utilizaran en el objeto a construir.
</p>
<h3>
    FranjasEscenario.h
</h3>
<p>
    class FranjasEscenario
</p>
<p>
    {
</p>
<p>
    private:
</p>
<p>
    Panel* panelFE;
</p>
<p>
    vector&lt;Bloques*&gt; bloquesFE;
</p>
<p>
    vector&lt;Espinas*&gt; espinasFE;
</p>
<p>
    public:
</p>
<p>
    void Mostrar();
</p>
<p>
    Panel* getPanelFE() { return panelFE; }
</p>
<p>
    vector&lt;Bloques*&gt; getBloquesFE() { return bloquesFE; }
</p>
<p>
    vector&lt;Espinas*&gt; getEspinasFE() { return espinasFE; }
</p>
<p>
    void setPanelFE(Panel* _panelFE) { panelFE = _panelFE; }
</p>
<p>
    void setBloquesFE(vector&lt;Bloques*&gt; _bloquesFE) { bloquesFE =
    _bloquesFE; }
</p>
<p>
    void setEspinasFE(vector&lt;Espinas*&gt; _espinasFE) { espinasFE =
    _espinasFE; }
</p>
<p>
    };
</p>
<h3>
    Implementación de (FranjasEscenario.cpp)
</h3>
<p>
    #include "FranjasEscenario.h"
</p>
<p>
    void FranjasEscenario::Mostrar() {
</p>
<p>
    //Metodo para mostrar el panel
</p>
<p>
    panelFE-&gt;Mostrar();
</p>
<p>
    //Metodos para mostrar los objetos almacenados en los vectores
</p>
<p>
    for (auto it = std::begin(bloquesFE); it != std::end(bloquesFE); ++it) {
</p>
<p>
    (*it)-&gt;Mostrar();
</p>
<p>
    }
</p>
<p>
    for (auto it = std::begin(espinasFE); it != std::end(espinasFE); ++it) {
</p>
<p>
    (*it)-&gt;Mostrar();
</p>
<p>
    }
</p>
<p>
    }<strong></strong>
</p>
<p>
    A continuación, se crea un constructor, en la cual se define la interfaz
    para crear las partes de un objeto Producto. En el videojuego este
    constructor es “BuilderFranjasEscenario” una clase abstracta, en el cual se
    implementará los métodos virtuales puros que se heredaran a los
    constructores concretos:
</p>
<p>
    // clase abstracta pura
</p>
<p>
    class BuilderFranjasEscenario
</p>
<p>
    {
</p>
<p>
    public:
</p>
<p>
    // Cambiamos la clase superficie por la clase Panel y usamos
    MapaElementosPantalla para guardar caracter, color y posiciones
</p>
<p>
    virtual Panel* getPanelFranjaEscenario(MapaElementosPantalla*) = 0;
</p>
<p>
    virtual vector&lt;Bloques*&gt;
    getBloquesFranjaEscenario(MapaElementosPantalla*) = 0;
</p>
<p>
    virtual vector&lt;Espinas*&gt;
    getEspinasFranjaEscenario(MapaElementosPantalla*) = 0;
</p>
<p>
    };
</p>
<p>
    Aquí se definen las partes que se usaran en la composición del objeto
    (Panel*, vector&lt;Bloques*&gt;, vector&lt;Espinas*&gt;), todos definidos
    con punteros.
</p>
<p>
    Para el siguiente paso necesitamos un <strong>Director </strong>el cual
    construirá el objeto a partir de la interfaz del constructor, en el
    videojuego esta definido como “DirectorFranjasEscenario”.
</p>
<h3>
    Definición del director (DirectorFranjasEscenario.h)
</h3>
<p>
    class DirectorFranjasEscenario{
</p>
<p>
    private:
</p>
<p>
    BuilderFranjasEscenario* builder;
</p>
<p>
    public:
</p>
<p>
    void setBuilder(BuilderFranjasEscenario* _builder) { builder = _builder; }
</p>
<p>
    //Método que devolverá la creación del objeto con los objetos que fueron
    pedidos por el cliente FranjasEscenario*
    getFranjaEscenario(MapaElementosPantalla*_mce);
</p>
<p>
    };
</p>
<h3>
    Implementación de los métodos (DirectorFranjasEscenario.cpp)
</h3>
<p>
    // El director te crea una franja con los objetos que tu le dices y te
    retorna un franja
</p>
<p>
    FranjasEscenario*
    DirectorFranjasEscenario::getFranjaEscenario(MapaElementosPantalla* _mce)
</p>
<p>
    {
</p>
<p>
    FranjasEscenario* franjaEscenario = new FranjasEscenario;
</p>
<p>
    franjaEscenario-&gt;setPanelFE(builder-&gt;getPanelFranjaEscenario(_mce));
</p>
<p>
    franjaEscenario-&gt;setBloquesFE(builder-&gt;getBloquesFranjaEscenario(_mce));
</p>
<p>
    franjaEscenario-&gt;setEspinasFE(builder-&gt;getEspinasFranjaEscenario(_mce));
</p>
<p>
    return franjaEscenario;
</p>
<p>
    }
</p>
<p>
    Para el siguiente paso será necesaria la creacion de los constructores
    concretos, los cuales los definimos como “FranjaInicioBuilder”,
    “FranjaCalleBuilder”, “FranjaMedioBuilder”, “FranjaCasasBuilder” y
    “FranjaRioBuilder”.
</p>
<p>
Estos constructores concretos se crean a partir del    <strong>builder </strong>que en nuestro videojuego seria
    “BuilderFranjasEscenario”, de este se hereda los métodos de creación de los
diferentes componentes para asi armar el    <strong>Constructor Concreto</strong>.
</p>
<h3>
    Ejemplo: FranjaInicioBuilder.h
</h3>
<p>
    class FranjaInicioBuilder :
</p>
<p>
    public BuilderFranjasEscenario
</p>
<p>
    {
</p>
<p>
    Panel* getPanelFranjaEscenario(MapaElementosPantalla* _mce);
</p>
<p>
    vector&lt;Bloques*&gt; getBloquesFranjaEscenario(MapaElementosPantalla*);
</p>
<p>
    vector&lt;Espinas*&gt; getEspinasFranjaEscenario(MapaElementosPantalla*);
</p>
<p>
    };
</p>
<p>
    <strong>
        Implementación de los métodos según las partes que requiera el usuario
        (FranjasInicioBuilder.cpp)
    </strong>
</p>
<p>
    En la fraja de inicio lo que se necesitaría seria un panel, 3 “Bloques”
    almacenados en un vector y 3 objetos “Espinas” igualmente almacenados en un
    vector.
</p>
<p>
    #include "FranjaInicioBuilder.h"
</p>
<p>
    Panel* FranjaInicioBuilder::getPanelFranjaEscenario(MapaElementosPantalla*
    _mce) {
</p>
<p>
    Panel* panelFI = new Panel(1, 26, 118, 3, 5, 6, '*', 120, ' ', 0, _mce);
</p>
<p>
    return panelFI;
</p>
<p>
    }
</p>
<p>
    vector&lt;Bloques*&gt;
    FranjaInicioBuilder::getBloquesFranjaEscenario(MapaElementosPantalla* m)
</p>
<p>
    {
</p>
<p>
    vector&lt;Bloques*&gt; bloquesFI;
</p>
<p>
    bloquesFI.push_back(new Bloques(1, 26, 20, 2, 'X', 5, 2, m));
</p>
<p>
    bloquesFI.push_back(new Bloques(50, 26, 10, 2, 'B', 5, 2, m));
</p>
<p>
    bloquesFI.push_back(new Bloques(99, 26, 20, 2, 'X', 5, 2, m));
</p>
<p>
    return bloquesFI;
</p>
<p>
    }
</p>
<p>
    }
</p>
<p>
    Para finalizar el ejemplo se lo implementa en el cliente (GameManager) para
    su creación y visualización en el juego. Se define la franja de inicio como
    un puntero a la clase del producto final (FranjasEscenario) y se declara
    igualmente el constructor concreto (FranjaInicioBuilder) que es necesario
    para que el director cree el objeto en base a ello.
</p>
<p>
    <strong>GameManager.h</strong>
</p>
<p>
    FranjasEscenario* FEInicio;
</p>
<p>
    FranjaInicioBuilder franjaInicioBuilder;
</p>
<p>
    <strong>GameManager.cpp</strong>
    <strong></strong>
</p>
<p>
    <strong></strong>
</p>
<p>
    //pasando el tipo de franja al director de BUILDER
</p>
<p>
    DirectorFE.setBuilder(&amp;franjaInicioBuilder);
</p>
<p>
    // Franja Inicio
</p>
<p>
    FEInicio = DirectorFE.getFranjaEscenario(mapaCaracteresEscenario);
</p>
<p>
    Este patrón es muy utilizado como se menciono antes para la construcción de
    un objeto en base a sus partes e incluso para crear diferentes
    representaciones como se hizo en el juego (“FranjaInicioBuilder” es muy
    diferente a “FranjaRioBuilder”).
</p>
<p>
    <strong></strong>
</p>
