#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

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
            for (int i = 0; i < 5; i++)
            {
                jugador1.push_back(todasLasCartas[i]);
                jugador2.push_back(todasLasCartas[i + 5]);
            }

            vector<int> contadores1 = contabilizar(jugador1);
            vector<int> contadores2 = contabilizar(jugador2);

            cout << "Cartas del Jugador 1: ";
            for (int i = 0; i < 5; i++)
            {
                cout << jugador1[i] << " ";
            }
            cout << endl;

            cout << "Cartas del Jugador 2: ";
            for (int i = 0; i < 5; i++)
            {
                cout << jugador2[i] << " ";
            }
            cout << endl;

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

            if (ases1 > ases2 || (ases1 == ases2 && ks1 > ks2) || (ases1 == ases2 && ks1 == ks2 && qs1 > qs2) ||
                (ases1 == ases2 && ks1 == ks2 && qs1 == qs2 && js1 > js2) ||
                (ases1 == ases2 && ks1 == ks2 && qs1 == qs2 && js1 == js2 && dieces1 > dieces2))
            {
                cout << "Comienza a jugar el jugador: 1" << endl;
            }
            else
            {
                cout << "Comienza a jugar el jugador: 2" << endl;
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

    ///parte inicial casi completa



    return 0;
}
