#include "Gestiones.hpp"

void GestionarCapturaArchivo()
{
    int m, n;
    string nombreArchivo;

    cout << "CAPTURAR MATRIZ A ARCHIVO\n" << endl;

    CapturarDimensiones(m, n);

    cout << "\nCapturar matriz:\n";
    double** matriz = CrearArreglo2D(m, n);
    CapturarMatriz(matriz, m, n);

    system("pause");
    system("cls");

    cout << "CAPTURAR MATRIZ A ARCHIVO\n" << endl;
    cout << "Capturando matriz: " << endl;
    ImprimirMatriz(matriz, m, n);

    nombreArchivo = NombrarArchivo();

    ImprimirMatrizArchivo(matriz, m, n, nombreArchivo);

    DestruirArreglo2D(matriz, m);

    system("pause");
}

void GestionarSuma()
{
    int mA(0), nA(0), mB(0), nB(0);
    int opUser;
    string nombreArchivo;
    double** matrizA = CrearArreglo2D(MAX_REN, MAX_COL);
    double** matrizB = CrearArreglo2D(MAX_REN, MAX_COL);

    do
    {
        cout << "SUMA DE MATRICES\n" << endl;

        cout << "Elija una opci\242n de captura: " << endl;
        cout << CONSOLA << ") Captura manual en consola" << endl;
        cout << ARCHIVO << ") Captura desde archivo" << endl;
        cout << "3) Regresar al men\243 anterior" << endl;

        do
        {
            CapturaSegura(opUser, "OPCION (entre 1 y 3): ");
        } while (opUser < 1 || opUser > 3);

        if (opUser == 3) continue;

        system("cls");
        cout << "SUMA DE MATRICES\n" << endl;
        switch (opUser)
        {
        case CONSOLA:
            cout << "= MATRIZ A =\n" << endl;
            CapturarDimensiones(mA, nA);

            cout << "\nCapturar matriz A:\n";
            CapturarMatriz(matrizA, mA, nA);
            ImprimirMatriz(matrizA, mA, nA);

            system("pause");
            system("cls");

            cout << "= MATRIZ B =\n " << endl;
            CapturarDimensiones(mB, nB);

            cout << "\nCapturar matriz B:\n";
            CapturarMatriz(matrizB, mB, nB);
            ImprimirMatriz(matrizB, mB, nB);
            break;

        case ARCHIVO:
            ifstream entrada;

            cout << "= MATRIZ A = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada.is_open()) entrada.close();
                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matrizA, mA, nA, nombreArchivo);

            ImprimirMatriz(matrizA, mA, nA);

            cout << "= MATRIZ B = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matrizB, mB, nB, nombreArchivo);

            ImprimirMatriz(matrizB, mB, nB);
            break;
        }

        system("pause");
        system("cls");

        cout << "SUMA DE MATRICES\n" << endl;
        if (mA == mB && nA == nB)
        {
            double** matrizR = CrearArreglo2D(mA, nA);

            ImprimirMatriz(matrizA, mA, nA);
            cout << setw(nA * 5) << "+" << endl;
            ImprimirMatriz(matrizB, mB, nB);
            SumaMatriz(matrizA, matrizB, matrizR, mA, nA);
            cout << setw(nA * 5) << "=" << endl;
            ImprimirMatriz(matrizR, mA, nA);

            cout << "\250Desea imprimir el resultado a un archivo?" << endl;
            cout << "1) S\241" << endl;
            cout << "2) No" << endl;

            do
            {
                CapturaSegura(opUser, "OPCION (entre 1 y 2): ");
            } while (opUser < 1 || opUser > 2);

            if (opUser == 1)
            {
                nombreArchivo = NombrarArchivo();
                ImprimirMatrizArchivo(matrizR, mA, nA, nombreArchivo);
            }

            DestruirArreglo2D(matrizR, mA);
        }
        else
        {
            cout << "ERROR: Los dos arreglos no se pueden sumar.\n\n";
        }

        DestruirArreglo2D(matrizA, MAX_REN);
        DestruirArreglo2D(matrizB, MAX_REN);
        break;

    } while (opUser != 3);

    system("pause");
}

void GestionarResta()
{
    int mA(0), nA(0), mB(0), nB(0);
    int opUser;
    string nombreArchivo;
    double** matrizA = CrearArreglo2D(MAX_REN, MAX_COL);
    double** matrizB = CrearArreglo2D(MAX_REN, MAX_COL);

    do
    {
        cout << "RESTA DE MATRICES\n" << endl;

        cout << "Elija una opci\242n de captura: " << endl;
        cout << CONSOLA << ") Captura manual en consola" << endl;
        cout << ARCHIVO << ") Captura desde archivo" << endl;
        cout << "3) Regresar al men\243 anterior" << endl;

        do
        {
            CapturaSegura(opUser, "OPCION (entre 1 y 3): ");
        } while (opUser < 1 || opUser > 3);

        if (opUser == 3) continue;

        system("cls");
        cout << "RESTA DE MATRICES\n" << endl;

        switch (opUser)
        {
        case CONSOLA:
            cout << "= MATRIZ A =\n" << endl;
            CapturarDimensiones(mA, nA);

            cout << "\nCapturar matriz A:\n";
            CapturarMatriz(matrizA, mA, nA);
            ImprimirMatriz(matrizA, mA, nA);

            system("pause");
            system("cls");

            cout << "= MATRIZ B =\n " << endl;
            CapturarDimensiones(mB, nB);

            cout << "\nCapturar matriz B:\n";
            CapturarMatriz(matrizB, mB, nB);
            ImprimirMatriz(matrizB, mB, nB);
            break;

        case ARCHIVO:
            ifstream entrada;

            cout << "= MATRIZ A = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada.is_open()) entrada.close();
                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matrizA, mA, nA, nombreArchivo);

            ImprimirMatriz(matrizA, mA, nA);

            cout << "= MATRIZ B = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matrizB, mB, nB, nombreArchivo);

            ImprimirMatriz(matrizB, mB, nB);
            break;
        }

        system("pause");
        system("cls");

        cout << "RESTA DE MATRICES\n" << endl;
        if (mA == mB && nA == nB)
        {
            double** matrizR = CrearArreglo2D(mA, nA);

            ImprimirMatriz(matrizA, mA, nA);
            cout << setw(nA * 5) << "-" << endl;
            ImprimirMatriz(matrizB, mB, nB);
            RestaMatriz(matrizA, matrizB, matrizR, mA, nA);
            cout << setw(nA * 5) << "=" << endl;
            ImprimirMatriz(matrizR, mA, nA);

            cout << "\250Desea imprimir el resultado a un archivo?" << endl;
            cout << "1) S\241" << endl;
            cout << "2) No" << endl;

            do
            {
                CapturaSegura(opUser, "OPCION (entre 1 y 2): ");
            } while (opUser < 1 || opUser > 2);

            if (opUser == 1)
            {
                nombreArchivo = NombrarArchivo();
                ImprimirMatrizArchivo(matrizR, mA, nA, nombreArchivo);
            }

            DestruirArreglo2D(matrizR, mA);
        }
        else
        {
            cout << "ERROR: Los dos arreglos no se pueden restar.\n\n";
        }

        DestruirArreglo2D(matrizA, MAX_REN);
        DestruirArreglo2D(matrizB, MAX_REN);
        break;

    } while (opUser != 3);

    system("pause");
}

void GestionarProdEscalar()
{
    int m(0), n(0);
    int opUser;
    string nombreArchivo;
    double** matriz = CrearArreglo2D(MAX_REN, MAX_COL);
    double escalar;

    do
    {
        cout << "PRODUCTO POR UN ESCALAR\n" << endl;

        cout << "Elija una opci\242n de captura: " << endl;
        cout << CONSOLA << ") Captura manual en consola" << endl;
        cout << ARCHIVO << ") Captura desde archivo" << endl;
        cout << "3) Regresar al men\243 anterior" << endl;

        do
        {
            CapturaSegura(opUser, "OPCION (entre 1 y 3): ");
        } while (opUser < 1 || opUser > 3);

        if (opUser == 3) continue;

        system("cls");
        cout << "PRODUCTO POR UN ESCALAR\n" << endl;

        switch (opUser)
        {
        case CONSOLA:
            cout << "= MATRIZ =\n" << endl;
            CapturarDimensiones(m, n);

            cout << "\nCapturar matriz A:\n";
            CapturarMatriz(matriz, m, n);
            ImprimirMatriz(matriz, m, n);
            break;

        case ARCHIVO:
            ifstream entrada;
            cout << "= MATRIZ = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada.is_open()) entrada.close();
                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matriz, m, n, nombreArchivo);

            ImprimirMatriz(matriz, m, n);
            break;
        }

        CapturaSegura(escalar, "\nEscalar: ");

        system("pause");
        system("cls");

        cout << "PRODUCTO POR UN ESCALAR\n" << endl;

        cout << setw(n * 5) << escalar << endl;
        cout << setw(n * 5) << "*" << endl;
        ImprimirMatriz(matriz, m, n);
        ProductoEscalar(matriz, escalar, m, n);
        cout << setw(n * 5) << "=" << endl;
        ImprimirMatriz(matriz, m, n);

        cout << "\250Desea imprimir el resultado a un archivo?" << endl;
        cout << "1) S\241" << endl;
        cout << "2) No" << endl;

        do
        {
            CapturaSegura(opUser, "OPCION (entre 1 y 2): ");
        } while (opUser < 1 || opUser > 2);

        if (opUser == 1)
        {
            nombreArchivo = NombrarArchivo();
            ImprimirMatrizArchivo(matriz, m, n, nombreArchivo);
        }

        DestruirArreglo2D(matriz, m);
        break;

    } while (opUser != 3);

    system("pause");
}

void GestionarMultiplicacion()
{
    int mA(0), nA(0), mB(0), nB(0);
    int opUser;
    string nombreArchivo;
    double** matrizA = CrearArreglo2D(MAX_REN, MAX_COL);
    double** matrizB = CrearArreglo2D(MAX_REN, MAX_COL);

    do
    {
        cout << "MULTIPLICACION DE MATRICES\n" << endl;

        cout << "Elija una opci\242n de captura: " << endl;
        cout << CONSOLA << ") Captura manual en consola" << endl;
        cout << ARCHIVO << ") Captura desde archivo" << endl;
        cout << "3) Regresar al men\243 anterior" << endl;

        do
        {
            CapturaSegura(opUser, "OPCION (entre 1 y 3): ");
        } while (opUser < 1 || opUser > 3);

        if (opUser == 3) continue;

        system("cls");
        cout << "MULTIPLICACION DE MATRICES\n" << endl;

        switch (opUser)
        {
        case CONSOLA:
            cout << "= MATRIZ A =\n" << endl;
            CapturarDimensiones(mA, nA);

            cout << "\nCapturar matriz A:\n";
            CapturarMatriz(matrizA, mA, nA);
            ImprimirMatriz(matrizA, mA, nA);

            system("pause");
            system("cls");

            cout << "= MATRIZ B =\n " << endl;
            CapturarDimensiones(mB, nB);

            cout << "\nCapturar matriz B:\n";
            CapturarMatriz(matrizB, mB, nB);
            ImprimirMatriz(matrizB, mB, nB);
            break;

        case ARCHIVO:
            ifstream entrada;

            cout << "= MATRIZ A = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada.is_open()) entrada.close();
                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matrizA, mA, nA, nombreArchivo);

            ImprimirMatriz(matrizA, mA, nA);

            cout << "= MATRIZ B = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matrizB, mB, nB, nombreArchivo);

            ImprimirMatriz(matrizB, mB, nB);
            break;
        }

        system("pause");
        system("cls");

        cout << "MULTIPLICACION DE MATRICES\n" << endl;
        if (nA == mB)
        {
            double** matrizR = CrearArreglo2D(mA, nB);

            InicializarMatrizCero(matrizR, mA, nB);

            ImprimirMatriz(matrizA, mA, nA);
            cout << setw(nA * 5) << "*" << endl;
            ImprimirMatriz(matrizB, mB, nB);
            MultiplicacionMatrices(matrizA, matrizB, matrizR, mA, mB, nB);
            cout << setw(nA * 5) << "=" << endl;
            ImprimirMatriz(matrizR, mA, nB);

            cout << "\250Desea imprimir el resultado a un archivo?" << endl;
            cout << "1) S\241" << endl;
            cout << "2) No" << endl;

            do
            {
                CapturaSegura(opUser, "OPCION (entre 1 y 2): ");
            } while (opUser < 1 || opUser > 2);

            if (opUser == 1)
            {
                nombreArchivo = NombrarArchivo();
                ImprimirMatrizArchivo(matrizR, mA, nB, nombreArchivo);
            }

            DestruirArreglo2D(matrizR, mA);
        }
        else
        {
            cout << "ERROR: Los dos arreglos no se pueden multiplicar (las columnas de la matriz A no coinciden con los renglones de la matriz B).\n\n";
        }

        DestruirArreglo2D(matrizA, MAX_REN);
        DestruirArreglo2D(matrizB, MAX_REN);
        break;

    } while (opUser != 3);

    system("pause");
}

void GestionarTranspuesta()
{
    int m(0), n(0);
    int opUser;
    string nombreArchivo;
    double** matriz = CrearArreglo2D(MAX_REN, MAX_COL);
    double** matrizT = CrearArreglo2D(MAX_REN, MAX_COL);

    do
    {
        cout << "TRANSPUESTA DE UNA MATRIZ\n" << endl;

        cout << "Elija una opci\242n de captura: " << endl;
        cout << CONSOLA << ") Captura manual en consola" << endl;
        cout << ARCHIVO << ") Captura desde archivo" << endl;
        cout << "3) Regresar al men\243 anterior" << endl;

        do
        {
            CapturaSegura(opUser, "OPCION (entre 1 y 3): ");
        } while (opUser < 1 || opUser > 3);

        if (opUser == 3) continue;

        system("cls");
        cout << "TRANSPUESTA DE UNA MATRIZ\n" << endl;

        switch (opUser)
        {
        case CONSOLA:
            cout << "= MATRIZ =\n" << endl;
            CapturarDimensiones(m, n);

            cout << "\nCapturar matriz :\n";
            CapturarMatriz(matriz, m, n);
            ImprimirMatriz(matriz, m, n);
            break;

        case ARCHIVO:
            ifstream entrada;
            cout << "= MATRIZ = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada.is_open()) entrada.close();
                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matriz, m, n, nombreArchivo);

            ImprimirMatriz(matriz, m, n);
            break;
        }

        system("pause");
        system("cls");

        cout << "TRANSPUESTA DE UNA MATRIZ\n" << endl;

        cout << "Matriz original: \n" << endl;
        ImprimirMatriz(matriz, m, n);
        TranspuestaMatriz(matriz, matrizT, m, n);
        cout << "\nTranspuesta: \n" << endl;
        ImprimirMatriz(matrizT, n, m);

        cout << "\250Desea imprimir el resultado a un archivo?" << endl;
        cout << "1) S\241" << endl;
        cout << "2) No" << endl;

        do
        {
            CapturaSegura(opUser, "OPCION (entre 1 y 2): ");
        } while (opUser < 1 || opUser > 2);

        if (opUser == 1)
        {
            nombreArchivo = NombrarArchivo();
            ImprimirMatrizArchivo(matrizT, n, m, nombreArchivo);
        }

        DestruirArreglo2D(matriz, m);
        DestruirArreglo2D(matrizT, n);
        break;

    } while (opUser != 3);

    system("pause");
}

void GestionarInversa()
{
    int m(0), n(0);
    int opUser;
    string nombreArchivo;
    double** matriz = CrearArreglo2D(MAX_REN, MAX_COL);
    double** matrizI = CrearArreglo2D(MAX_REN, MAX_COL);
    InicializarMatrizCero(matriz, m, n);

    do
    {
        cout << "INVERSA DE UNA MATRIZ\n" << endl;

        cout << "Elija una opci\242n de captura: " << endl;
        cout << CONSOLA << ") Captura manual en consola" << endl;
        cout << ARCHIVO << ") Captura desde archivo" << endl;
        cout << "3) Regresar al men\243 anterior" << endl;

        do
        {
            CapturaSegura(opUser, "OPCION (entre 1 y 3): ");
        } while (opUser < 1 || opUser > 3);

        if (opUser == 3) continue;

        system("cls");
        cout << "INVERSA DE UNA MATRIZ\n" << endl;

        switch (opUser)
        {
        case CONSOLA:
            cout << "= MATRIZ =\n" << endl;
            CapturarDimensiones(m, n);

            cout << "\nCapturar matriz :\n";
            CapturarMatriz(matriz, m, n);
            ImprimirMatriz(matriz, m, n);
            break;

        case ARCHIVO:
            ifstream entrada;
            cout << "= MATRIZ = " << endl;
            do
            {
                nombreArchivo = NombrarArchivo();

                entrada.open(nombreArchivo);

                if (!entrada.is_open()) entrada.close();
                if (!entrada) cout << "ERROR: El archivo no pudo ser abierto ya que no existe." << endl;

            } while (!entrada);

            entrada.close();
            CapturarMatrizArchivo(matriz, m, n, nombreArchivo);

            ImprimirMatriz(matriz, m, n);
            break;
        }

        system("pause");
        system("cls");

        cout << "INVERSA DE UNA MATRIZ\n" << endl;

        cout << "Matriz original: \n" << endl;
        ImprimirMatriz(matriz, m, n);

        if (m != n)
        {
            cout << "\nLa matriz no es cuadrada. La matriz no es invertible. Introduzca una matriz cuadrada para calcular la inversa.\n" << endl;
        }
        else
        {
            InvertirMatriz(matriz, m, matrizI);

            if (InvertirMatriz(matriz, m, matrizI) == false)
            {
                cout << "\nLa matriz no es invertible debido a que el determinante es igual a 0.\n" << endl;
            }
            else
            {
                cout << "\nInversa: \n" << endl;
                ImprimirMatriz(matrizI, m, n);

                cout << "\250Desea imprimir el resultado a un archivo?" << endl;
                cout << "1) S\241" << endl;
                cout << "2) No" << endl;

                do
                {
                    CapturaSegura(opUser, "OPCION (entre 1 y 2): ");
                } while (opUser < 1 || opUser > 2);

                if (opUser == 1)
                {
                    nombreArchivo = NombrarArchivo();
                    ImprimirMatrizArchivo(matrizI, m, n, nombreArchivo);
                }
            }
        }

        DestruirArreglo2D(matrizI, m);
        DestruirArreglo2D(matriz, m);
        break;

    } while (opUser != 3);

    system("pause");
}