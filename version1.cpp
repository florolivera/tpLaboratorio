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
            for (int i = 0; i < 5; i++)
            {
                jugador1.push_back(todasLasCartas[i]);
                jugador2.push_back(todasLasCartas[i + 5]);
            }

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

            int jugadorComienza;

            if (ases1 > ases2 || (ases1 == ases2 && ks1 > ks2) || (ases1 == ases2 && ks1 == ks2 && qs1 > qs2) ||
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
                cout<<"RESULTADO DEL DADO: "<<dadoResultado;
            }

            int cartaSeleccionada;
            string cartaEliminada;

            //ELIMINAR, PRUEBA....
            dadoResultado = 2;
            if(dadoResultado == 1)
            {
                cout<<"seleccione una carta (1 - 5): "<<endl;
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
                    cout<<"Se intergambia la carta: "<<cartaEliminada<<endl;
                    jugador2[cartaSeleccionada -1] = alMazo(jugador1, jugador2);
                    cout<<"carta robada del mazo: "<<jugador2[cartaSeleccionada - 1];
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
                    cout << jugador2[i] <<"("<<i+1<<")"<< ": ";
                    }
                    cin>>cartaSeleccionada;
                    cartaEliminada = jugador2[cartaSeleccionada - 1];
                    jugador2[cartaSeleccionada - 1] = "";
                    cout<<"Se intergambia la carta: "<<cartaEliminada<<endl;
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

            }
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
