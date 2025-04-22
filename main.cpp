#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

#include "Gestiones.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main()
{
    int opUser;  
    
    do
    {
        system("cls");
        cout << "OPERACIONES CON MATRICES\n" << endl;
        cout << "Este programa calcula las siguientes operaciones de matrices usando numeros reales (redondeados a tres decimales)." << endl;
        cout << "Eliga una de las opciones siguientes:\n " << endl;

        cout << CAPTURAR_ARCHIVO << ") CAPTURAR MATRIZ A ARCHIVO" << endl;
        cout << SUMA << ") SUMA DE MATRICES" << endl;
        cout << RESTA << ") RESTA DE MATRICES" << endl;
        cout << PROD_ESCALAR << ") PRODUCTO POR ESCALAR" << endl;
        cout << MULTIPLICACION << ") MULTIPLICACION DE MATRICES" << endl;
        cout << TRANSPUESTA << ") TRANSPUESTA DE MATRICES" << endl;
        cout << INVERSA << ") INVERSA DE LA MATRIZ" << endl;
        cout << "8) SALIR" << endl;

        cout << endl;

        CapturaSegura(opUser, "OPCION (Entre 1 y 8): ");

        if (opUser == 8) continue;

        system("cls");
        switch (opUser)
        {
        case CAPTURAR_ARCHIVO: GestionarCapturaArchivo(); break;
            case SUMA:  GestionarSuma(); break;
            case RESTA: GestionarResta(); break;
            case PROD_ESCALAR: GestionarProdEscalar(); break;
            case MULTIPLICACION: GestionarMultiplicacion(); break; //Buggeado
            case TRANSPUESTA: GestionarTranspuesta(); break;
            case INVERSA: break;
        }
    } while (opUser != 8);

    cout << "\n\n";
    system("pause");
    return 0;
}


