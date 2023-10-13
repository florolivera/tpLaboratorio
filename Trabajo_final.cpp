
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int opcion;
    string jugador1,jugador2;
    int cartasjugador1[5];
    int cartasjugador2[5];
 string cartas[20] = {
        "copa 10",
        "Basto 10",
        "Espada 10",
        "oro 10",

        "copa j",
        "basto j",
        "espada j",
        "oro j" ,

        "copa q",
        "basto q",
        "espada q",
        "oro q",

        "copa k",
        "basto k",
        "espada k",
        "oro k",

        "copa a",
        "basto a",
        "espada a",
        "oro a"};

    cout<<"CLUTCH"<<endl<<"------------"<<endl;
    cout<<"1-JUGAR"<<endl<<"2-ESTADISTICAS"<<endl<<"3-CREDITOS"<<endl;
    cin>>opcion;
    cout<<endl;


    switch (opcion) {
        case 1:
            cout << "Ha seleccionado la opcion 1." << endl;
            cout<<"Nombre del primer jugador: ";
            cin>>jugador1;
            cout<<"Nombre del segundo jugador: ";
            cin>>jugador2;
            break;
        case 2:
            cout << "Ha seleccionado la opcion 2." << endl;
            break;
        case 3:
            cout << "Ha seleccionado la opcion 3." << endl;
            break;
        default:
           cout << "Opcion no válida." << endl;
            }
        for (int i=0;i<5;i++){
              cartasjugador1[i] = rand()%20+1;


        }
        for (int i=0;i<5;i++){
              cartasjugador2[i] = rand()%20+1;


        }

        cout<<"CARTAS DEL JUGADOR 1: "<<endl;
        for (int i=0; i<5; i++)
        {
            cout<<cartas[cartasjugador1[i]]<<endl;
        }




        return 0;
}
