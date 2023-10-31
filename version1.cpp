#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

/*=================FUNCION PARA PODER ELEGIR EL JUGADOR QUE COMIENZA===========================*/
vector<int> contabilizar(const vector<string>& mano)
{
    vector<string> Ases = {"A DIAMANTES", "A CORAZONES", "A TREBOLES", "A ESPADAS"};
    vector<string> Ks = {"K DIAMANTES", "K CORAZONES", "K TREBOLES", "K ESPADAS"};
    vector<string> Qs = {"Q DIAMANTES", "Q CORAZONES", "Q TREBOLES", "Q ESPADAS"};
    vector<string> Js = {"J DIAMANTES", "J CORAZONES", "J TREBOLES","J ESPADAS"};
    vector<string> dieces = {"10 DIAMANTES", "10 CORAZONES", "10 TREBOLES", "10 ESPADAS"};
    int ases1 = 0;
    int ks1 = 0;
    int qs1 = 0;
    int js1 = 0;
    int dieces1 = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (mano[i] == Ases[x])
            {
                ases1++;
            }
            if (mano[i] == Ks[x])
            {
                ks1++;
            }
            if (mano[i] == Qs[x])
            {
                qs1++;
            }
            if (mano[i] == Js[x])
            {
                js1++;
            }
            if (mano[i] == dieces[x])
            {
                dieces1++;
            }
        }
    }

    vector<int> contadores = {ases1, ks1, qs1, js1, dieces1};
    return contadores;
}

/*=======================FUNCION PARA VECTOR ORDENADO===================*/

bool ordenado(vector<string>& vector1)
{
    bool bandera = false;

    if (vector1[0] == "10 DIAMANTES" || vector1[0] == "10 CORAZONES" || vector1[0] == "10 TREBOLES" || vector1[0] == "10 ESPADAS")
    {
        if (vector1[1] == "J DIAMANTES" || vector1[1] == "J CORAZONES" || vector1[1] == "J TREBOLES" || vector1[1] == "J ESPADAS")
        {
            if (vector1[2] == "Q DIAMANTES" || vector1[2] == "Q CORAZONES" || vector1[2] == "Q TREBOLES" || vector1[2] == "Q ESPADAS")
            {
                if (vector1[3] == "K DIAMANTES" || vector1[3] == "K CORAZONES" || vector1[3] == "K TREBOLES" || vector1[3] == "K ESPADAS")
                {
                    if (vector1[4] == "A DIAMANTES" || vector1[4] == "A CORAZONES" || vector1[4] == "A TREBOLES" || vector1[4] == "A ESPADAS")
                    {
                        bandera = true;
                    }
                }
            }
        }
    }

    return bandera;
}


/*===========================FUNCION CAMBIO DE ORDEN=====================*/
vector<string> cambioOrden(vector<string>& vector1, int cartaSeleccionada1, int cartaSeleccionada2)
{
    string aux = vector1[cartaSeleccionada1 - 1];
    vector1[cartaSeleccionada1 - 1] = vector1[cartaSeleccionada2 - 1];
    vector1[cartaSeleccionada2 - 1] = aux;

    return vector1;
}

/*===========================FUNCION PARA INTERCAMBIO===================*/

vector<string> intercambio(vector<string>& vector1, vector<string>& vector2, const string& cartaSeleccionada1, const string& cartaSeleccionada2)
{
    for (int i = 0; i < 5; i++)
    {
        if (vector1[i] == cartaSeleccionada1)
        {
            vector1[i] = cartaSeleccionada2;
        }
    }

    return vector1;
}



/*=============================FUNCION PARA REPARTIR LAS CARTAS DE CADA CORRAL=======================*/
vector<string> barajarCartas()
{
    string valores[] = {"10 DIAMANTES", "J DIAMANTES", "Q DIAMANTES", "K DIAMANTES", "A DIAMANTES",
                        "10 CORAZONES", "J CORAZONES", "Q CORAZONES", "K CORAZONES", "A CORAZONES",
                        "10 TREBOLES", "J TREBOLES", "Q TREBOLES", "K TREBOLES", "A TREBOLES",
                        "10 ESPADAS", "J ESPADAS", "Q ESPADAS", "K ESPADAS", "A ESPADAS"};

    vector<string> cartas(valores, valores + 20);
    srand(static_cast<unsigned>(time(0)));
    random_shuffle(cartas.begin(), cartas.end());

    return cartas;
}

/*===================FUNCION PARA TIRAR EL DADO===================*/
int dado()
{
    int valorDado= rand()%6+1;

    return valorDado;

}

string alMazo(const vector<string>& vector1, const vector<string>& vector2)
{
    string mazo[] = {"10 DIAMANTES", "J DIAMANTES", "Q DIAMANTES", "K DIAMANTES", "A DIAMANTES",
                    "10 CORAZONES", "J CORAZONES", "Q CORAZONES", "K CORAZONES", "A CORAZONES",
                    "10 TREBOLES", "J TREBOLES", "Q TREBOLES", "K TREBOLES", "A TREBOLES",
                    "10 ESPADAS", "J ESPADAS", "Q ESPADAS", "K ESPADAS", "A ESPADAS"};

    for (int i = 0; i < 5; i++)
    {
        for (int x = 0; x < 20; x++)
        {
            if (vector1[i] == mazo[x])
            {
                mazo[x] = "";
            }
            if (vector2[i] == mazo[x])
            {
                mazo[x] = "";
            }
        }
    }

    string carta;
    bool bandera = true;

    do
    {
        int seleccionada = rand() % 20;
        if (mazo[seleccionada] != "")
        {
            carta = mazo[seleccionada];
            bandera = false;
        }
    } while (bandera);

    return carta;
}



/*=====================BLOQUE PRINCIPAL===============================*/
int main()
{
    vector<string> todasLasCartas = barajarCartas();
    vector<string> jugador1, jugador2;
    int opcion;
    string jugadores1, jugadores2;
    vector<string> cartasBloqueadasJugador1;
    vector<string> cartasBloqueadasJugador2;
    bool jugador1Ordenado = false;
    bool jugador2Ordenado = false;
    int partidasJugador1 = 0;
    int partidasJugador2 = 0;
    int vueltas = 0;
    int jugadorComienza;


    cout << "CLUTCH" << endl << "------------" << endl;
    cout << "1-JUGAR" << endl << "2-ESTADISTICAS" << endl << "3-CREDITOS" << endl;
    cin >> opcion;
    cout << endl;
    if(opcion == 1)
    {
            cout << "Ha seleccionado la opcion 1." << endl;
            cout << "Nombre del primer jugador: ";
            cin >> jugadores1;
            cout << "Nombre del segundo jugador: ";
            cin >> jugadores2;

            /*==========SE LES ASIGNA LAS CARTAS DEL CORRAL=============*/

            //si el corral de alguno queda ordenado se vuelve a repartir
        do{
            for (int i = 0; i < 5; i++)
            {
                jugador1.push_back(todasLasCartas[i]);
                jugador2.push_back(todasLasCartas[i + 5]);
            }

            jugador1Ordenado = ordenado(jugador1);
            jugador2Ordenado = ordenado(jugador2);
        }while(jugador1Ordenado || jugador2Ordenado);
        do{
            vueltas++;
            cout<<"VUELTA: "<<vueltas<<endl;
            vector<int> contadores1 = contabilizar(jugador1);
            vector<int> contadores2 = contabilizar(jugador2);

            cout << "Cartas de "<<jugadores1<<": ";
            for (int i = 0; i < 5; i++)
            {
                cout << jugador1[i] << " ";
            }
            cout << endl;

            cout << "Cartas de "<<jugadores2<<": ";
            for (int i = 0; i < 5; i++)
            {
                cout << jugador2[i] << " ";
            }
            cout << endl;

            /*================SE SELECCIONA EL JUGADOR QUE INICIA==============*/

            int ases1 = contadores1[0];
            int ks1 = contadores1[1];
            int qs1 = contadores1[2];
            int js1 = contadores1[3];
            int dieces1 = contadores1[4];

            int ases2 = contadores2[0];
            int ks2 = contadores2[1];
            int qs2 = contadores2[2];
            int js2 = contadores2[3];
            int dieces2 = contadores2[4];


            jugador1Ordenado = ordenado(jugador1);
            jugador2Ordenado = ordenado(jugador2);


            if(vueltas < 1)
            {
                if(jugadorComienza == 1)
                {
                    jugadorComienza = 2;
                }
                else
                {
                    jugadorComienza = 1;
                }

            }
            else if (ases1 > ases2 || (ases1 == ases2 && ks1 > ks2) || (ases1 == ases2 && ks1 == ks2 && qs1 > qs2) ||
                (ases1 == ases2 && ks1 == ks2 && qs1 == qs2 && js1 > js2) ||
                (ases1 == ases2 && ks1 == ks2 && qs1 == qs2 && js1 == js2 && dieces1 > dieces2))
            {
                cout << "Comienza a jugar el jugador: " << jugadores1 << endl;
                jugadorComienza = 1;
            }
            else
            {
                cout << "Comienza a jugar el jugador: "<< jugadores2 << endl;
                jugadorComienza = 2;
            }

            char t;
            int dadoResultado;
            cout<<"Ingrese 'T' para lanzar el dado: ";
            cin>>t;
            if(t == 'T' || t == 't')
            {
                dadoResultado = dado();
                cout<<"RESULTADO DEL DADO: "<<dadoResultado<<endl;
            }

            int cartaSeleccionada;
            string cartaEliminada;


            if(dadoResultado == 6)
            {
                int accion;
                cout<<"Elija la accion que quiere realizar(1-5): "<<endl;
                cout<<"1- intercambiar una carta de su corral por una del mazo."<<endl;
                cout<<"2- elegir una carta de su contrincante cambiarla por una del mazo."<<endl;
                cout<<"3- elegir una carta de su contrincante para agregar a su corral."<<endl;
                cout<<"4- intercambiar el orden de dos cartas de su corral."<<endl;
                cout<<"5- bloquear carta de su corral para que el contrincante no accione sobre ella."<<endl;
                cin>>accion;
                dadoResultado = accion;
            }
            if(dadoResultado == 1)
            {
                cout<<endl<<"Seleccione una carta (1 - 5): "<<endl;
                if(jugadorComienza == 1)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] <<"("<<i+1<<")"<< ": ";
                    }
                    cin>>cartaSeleccionada;
                    cartaEliminada = jugador1[cartaSeleccionada - 1];
                    jugador1[cartaSeleccionada - 1] = "";
                    cout<<"Se intergambia la carta: "<<cartaEliminada<<endl;
                    jugador1[cartaSeleccionada -1] = alMazo(jugador1, jugador2);
                    cout<<"carta robada del mazo: "<<jugador1[cartaSeleccionada - 1];
                    cout<<endl<<"Ahora el mazo de "<<jugadores1<<" quedo: "<<endl;

                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] << " ";
                    }
                }
                else
                {
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador2[i] <<"("<<i+1<<")"<< " ";
                    }
                    cout<<": ";
                    cin>>cartaSeleccionada;
                    cartaEliminada = jugador2[cartaSeleccionada - 1];
                    jugador2[cartaSeleccionada - 1] = "";
                    cout<<"Se intercambia la carta: "<<cartaEliminada<<endl;
                    jugador2[cartaSeleccionada -1] = alMazo(jugador1, jugador2);
                    cout<<"Carta robada del mazo: "<<jugador2[cartaSeleccionada - 1];
                    cout<<endl<<"Ahora el mazo de "<<jugadores2<<" quedo: "<<endl;

                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador2[i] << " ";
                    }

                }

            }
            if(dadoResultado == 2)
            {
                cout<<"seleccione una carta de su oponente (1 - 5): "<<endl;
                if(jugadorComienza == 1)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        if (find(cartasBloqueadasJugador2.begin(), cartasBloqueadasJugador2.end(), jugador2[i]) == cartasBloqueadasJugador2.end())
                            {
                                cout << jugador2[i] << "(" << i + 1 << "): ";
                            }
                    }
                    cin>>cartaSeleccionada;
                    cartaEliminada = jugador2[cartaSeleccionada - 1];
                    jugador2[cartaSeleccionada - 1] = "";
                    cout<<"Se intercambia la carta: "<<cartaEliminada<<endl;
                    jugador2[cartaSeleccionada -1] = alMazo(jugador1, jugador2);
                    cout<<"carta robada del mazo: "<<jugador2[cartaSeleccionada - 1];
                    cout<<endl<<"Ahora el mazo de "<<jugadores2<<" quedo: "<<endl;

                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador2[i] << " ";
                    }
                }
                else
                {
                    for (int i = 0; i < 5; i++)
                    {
                        if (find(cartasBloqueadasJugador1.begin(), cartasBloqueadasJugador1.end(), jugador1[i]) == cartasBloqueadasJugador1.end())
                            {
                                cout << jugador1[i] << "(" << i + 1 << "): ";
                            }
                    }

                    cin>>cartaSeleccionada;
                    cartaEliminada = jugador1[cartaSeleccionada - 1];
                    jugador1[cartaSeleccionada - 1] = "";
                    cout<<"Se intergambia la carta: "<<cartaEliminada<<endl;
                    jugador1[cartaSeleccionada -1] = alMazo(jugador1, jugador2);
                    cout<<"carta robada del mazo: "<<jugador1[cartaSeleccionada - 1];
                    cout<<endl<<"Ahora el mazo de "<<jugadores1<<" quedo: ";

                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] << " ";
                    }
                }

            }
            if(dadoResultado == 3)
            {
                int cartaPropia, cartaContrario;
                string seleccionada1, seleccionada2;

                if(jugadorComienza == 1)
                {

                    cout << "Seleccione la carta del corral de " << jugadores1 << ": " << endl;
                   for (int i = 0; i < 5; i++)
                    {
                        if (find(cartasBloqueadasJugador1.begin(), cartasBloqueadasJugador1.end(), jugador1[i]) == cartasBloqueadasJugador1.end())
                            {
                                cout << jugador1[i] << "(" << i + 1 << "): ";
                            }
                    }
                    cin >> cartaPropia;
                    seleccionada1 = jugador1[cartaPropia-1];

                    cout << "Seleccione la carta del corral de " << jugadores2 << ": " << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        if (find(cartasBloqueadasJugador2.begin(), cartasBloqueadasJugador2.end(), jugador2[i]) == cartasBloqueadasJugador2.end())
                            {
                                cout << jugador2[i] << "(" << i + 1 << "): ";
                            }
                    }
                    cin >> cartaContrario;
                    seleccionada2 = jugador2[cartaContrario-1];

                    jugador1 = intercambio(jugador1, jugador2, seleccionada1, seleccionada2);
                    jugador2 = intercambio(jugador2, jugador1, seleccionada2, seleccionada1);

                    cout<<"Los corrales quedaron: "<<endl;
                    cout<<"Corral de "<<jugadores1<<": ";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] << " ";
                    }
                    cout<<endl<<"Corral de "<<jugadores2<<": ";
                    for (int i = 0; i < 5; i++)
                    {
                        if (find(cartasBloqueadasJugador2.begin(), cartasBloqueadasJugador2.end(), jugador2[i]) == cartasBloqueadasJugador2.end())
                            {
                                cout << jugador2[i] << "(" << i + 1 << "): ";
                            }
                    }
                }
                else
                {
                    cout << "Seleccione la carta del corral de " << jugadores2 << ": " << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador2[i] << "(" << i + 1 << "): ";
                    }
                    cin >> cartaPropia;

                    seleccionada1 = jugador1[cartaPropia - 1];



                    cout << "Seleccione la carta del corral de " << jugadores1 << ": " << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] << "(" << i + 1 << "): ";
                    }
                    cin >> cartaContrario;
                    seleccionada2 = jugador2[cartaContrario - 1];
                    jugador2 = intercambio(jugador2, jugador1, seleccionada2, seleccionada1);
                    jugador1 = intercambio(jugador1, jugador2, seleccionada1, seleccionada2);

                    cout<<"Los corrales quedaron: "<<endl;
                    cout<<"Corral de "<<jugadores2<<": ";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador2[i] << " ";
                    }

                    cout<<endl<<"Corral de "<<jugadores1<<": ";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] << " ";
                    }
                }
            }
            if(dadoResultado == 4)
            {
                int cartaSeleccionada1, cartaSeleccionada2;

                if(jugadorComienza == 1)
                {
                    cout<<"Seleccione las dos cartas para cambiar su orden: "<<endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] << "(" << i + 1 << "): ";
                    }
                    cout<<"Primer carta: ";
                    cin>>cartaSeleccionada1;
                    cout<<"Segunda carta: ";
                    cin>>cartaSeleccionada2;

                    jugador1 = cambioOrden(jugador1, cartaSeleccionada1, cartaSeleccionada2);

                    cout<<"Resultado del corral de "<<jugadores1<<": "<<endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] << "(" << i + 1 << "): ";
                    }

                }
                else
                {
                    cout<<"Seleccione las dos cartas para cambiar su orden: "<<endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador2[i] << "(" << i + 1 << "): ";
                    }
                    cout<<"Primer carta: ";
                    cin>>cartaSeleccionada1;
                    cout<<"Segunda carta: ";
                    cin>>cartaSeleccionada2;

                    jugador2 = cambioOrden(jugador2, cartaSeleccionada1, cartaSeleccionada2);

                    cout<<"Resultado del corral de "<<jugadores1<<": "<<endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador2[i] << "(" << i + 1 << "): ";
                    }
                }

            }
            if (dadoResultado == 5)
            {
                int cartaABloquear;
                cout << "Elija una carta de su corral para bloquear (1-5): "<<endl;

                if (jugadorComienza == 1)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador1[i] <<"("<<i+1<<")"<< " ";
                    }
                    cin >> cartaABloquear;
                    cartasBloqueadasJugador1.push_back(jugador1[cartaABloquear - 1]);
                }
                else
                {
                    for (int i = 0; i < 5; i++)
                    {
                        cout << jugador2[i] <<"("<<i+1<<")"<< " ";
                    }
                    cin >> cartaABloquear;
                    cartasBloqueadasJugador2.push_back(jugador2[cartaABloquear - 1]);
                }
                if (jugadorComienza == 1)
                {
                    jugador1[cartaABloquear - 1] = "";
                } else
                {
                    jugador2[cartaABloquear - 1] = "";
                }
            }


            /*===========DETERMINAR PARTIDA GANADA============*/
            jugador1Ordenado = false;
            jugador2Ordenado = false;

            jugador1Ordenado = ordenado(jugador1);
            jugador2Ordenado = ordenado(jugador2);

            if(jugador1Ordenado)
            {
                partidasJugador1++;
                cout<<endl<<"Partida ganada por: "<<jugadores1<<endl;
            }

            if(jugador2Ordenado)
            {
                partidasJugador2++;
                 cout<<endl<<"Partida ganada por: "<<jugadores2<<endl;
            }


        }while(!(jugador1Ordenado || jugador2Ordenado));

    }
    else if(opcion == 2)
    {
        cout<<"proximamente... ";
    }
    else if(opcion == 3)
    {
        cout<<"proximamente...";
    }





    return 0;
}
