#include "Gestiones.hpp"

void GestionarCapturaArchivo()
{
    int mA, nA;
    char solicitud[50];
    char nombreArchivo[22];

    cout << "CAPTURAR MATRIZ A ARCHIVO\n" << endl;

    cout << "= MATRIZ A =\n" << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(mA, solicitud);
    } while (mA < 1 || mA > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(nA, solicitud);
    } while (nA < 1 || nA > MAX_COL);

    cout << "\nCapturar matriz A:\n";
    double** matrizA = CrearArreglo2D(mA, nA);
    CapturarMatriz(matrizA, mA, nA);

    system("pause");
    system("cls");

    cout << "CAPTURAR MATRIZ A ARCHIVO\n" << endl;

    cout << "Capturando matriz: " << endl;

    ImprimirMatriz(matrizA, mA, nA);

    do
    {
        cout << "\nIntroduzca el nombre del archivo (maximo 20 caracteres): ";
        cin >> nombreArchivo;
    } while (strlen(nombreArchivo) > 20);


    char extension[5] = ".txt" ;
    char aux[5] = {};
    int j = 0;

    cout << "len: ";
    cout << strlen(nombreArchivo);


    for (int i = strlen(nombreArchivo) - 4; nombreArchivo[i] == '\0' ; ++i, ++j)
    {
        aux[j] = nombreArchivo[i];
    }

    cout << "aux: ";
    cout << aux;
 

    if (strcmp(aux,nombreArchivo) == 0)
    {       
        cout << "nombre : " << endl;
        cout << nombreArchivo << endl;
    }
    else
    {
        char nombreArchivoR[sizeof(nombreArchivo)+sizeof(extension)];

        strcpy_s(nombreArchivoR, nombreArchivo);
        strcat_s(nombreArchivoR, extension);

        cout << "nombre con extension: " << endl;
        cout << nombreArchivoR << endl;
    }

    system("pause");
}


void GestionarSuma()
{
    int mA, nA, mB, nB;
    char solicitud[50];
    cout << "SUMA DE MATRICES\n" << endl; 

    cout << "= MATRIZ A =\n" << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(mA, solicitud);
    } while (mA < 1 || mA > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(nA, solicitud);
    } while (nA < 1 || nA > MAX_COL);

    cout << "\nCapturar matriz A:\n";
    double** matrizA = CrearArreglo2D(mA, nA);
    CapturarMatriz(matrizA, mA, nA);
    ImprimirMatriz(matrizA, mA, nA);

    system("pause");
    system("cls");

    cout << "= MATRIZ B =\n " << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(mB, solicitud);
    } while (mB < 1 || mB > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(nB, solicitud);
    } while (nB < 1 || nB > MAX_COL);

    cout << "\nCapturar matriz B:\n";
    double** matrizB = CrearArreglo2D(mB, nB);
    CapturarMatriz(matrizB, mB, nB);
    ImprimirMatriz(matrizB, mB, nB);

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

        DestruirArreglo2D(matrizR, mA);
    }
    else
    {
        cout << "ERROR: Los dos arreglos no se pueden sumar.\n\n";
    }

    DestruirArreglo2D(matrizA, mA);
    DestruirArreglo2D(matrizB, mB);

    system("pause");
}

void GestionarResta()
{
    int mA, nA, mB, nB;
    char solicitud[50];
    cout << "RESTA DE MATRICES\n" << endl;

    cout << "= MATRIZ A =\n" << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(mA, solicitud);
    } while (mA < 1 || mA > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(nA, solicitud);
    } while (nA < 1 || nA > MAX_COL);

    cout << "\nCapturar matriz A:\n";
    double** matrizA = CrearArreglo2D(mA, nA);
    CapturarMatriz(matrizA, mA, nA);
    ImprimirMatriz(matrizA, mA, nA);

    system("pause");
    system("cls");

    cout << "= MATRIZ B =\n " << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(mB, solicitud);
    } while (mB < 1 || mB > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(nB, solicitud);
    } while (nB < 1 || nB > MAX_COL);

    cout << "\nCapturar matriz B:\n";
    double** matrizB = CrearArreglo2D(mB, nB);
    CapturarMatriz(matrizB, mB, nB);
    ImprimirMatriz(matrizB, mB, nB);

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

        DestruirArreglo2D(matrizR, mA);
    }
    else
    {
        cout << "ERROR: Los dos arreglos no se pueden restar.\n\n";
    }

    DestruirArreglo2D(matrizA, mA);
    DestruirArreglo2D(matrizB, mB);

    system("pause");
}

void GestionarProdEscalar()
{
    int m, n;
    double escalar;
    char solicitud[50];
    cout << "PRODUCTO POR UN ESCALAR\n" << endl;

    cout << "= MATRIZ A =\n" << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(m, solicitud);
    } while (m < 1 || m > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(n, solicitud);
    } while (n < 1 || n > MAX_COL);

    cout << "\nCapturar matriz A:\n";
    double** matriz = CrearArreglo2D(m, n);
    CapturarMatriz(matriz, m, n);
    ImprimirMatriz(matriz, m, n);

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

    DestruirArreglo2D(matriz,m);

    system("pause");
}

void GestionarMultiplicacion()
{
    int mA, nA, mB, nB;
    char solicitud[50];
    cout << "MULTIPLICACION DE MATRICES\n" << endl;

    cout << "= MATRIZ A =\n" << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(mA, solicitud);
    } while (mA < 1 || mA > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(nA, solicitud);
    } while (nA < 1 || nA > MAX_COL);

    cout << "\nCapturar matriz A:\n";
    double** matrizA = CrearArreglo2D(mA, nA);
    CapturarMatriz(matrizA, mA, nA);
    ImprimirMatriz(matrizA, mA, nA);

    system("pause");
    system("cls");

    cout << "MULTIPLICACION DE MATRICES\n" << endl;

    cout << "= MATRIZ B =\n " << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(mB, solicitud);
    } while (mB < 1 || mB > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(nB, solicitud);
    } while (nB < 1 || nB > MAX_COL);

    cout << "\nCapturar matriz B:\n";
    double** matrizB = CrearArreglo2D(mB, nB);
    CapturarMatriz(matrizB, mB, nB);
    ImprimirMatriz(matrizB, mB, nB);

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

        DestruirArreglo2D(matrizR, mA);
    }
    else
    {
        cout << "ERROR: Los dos arreglos no se pueden multiplicar (las columnas de la matriz A no coinciden con los renglones de la matriz B).";
    }

    DestruirArreglo2D(matrizA, mA);
    DestruirArreglo2D(matrizB, mB);

    system("pause");
}

void GestionarTranspuesta()
{
    int m, n;
    char solicitud[50];
    cout << "TRANSPUESTA DE LA MATRIZ\n" << endl;

    cout << "= MATRIZ =\n" << endl;
    sprintf_s(solicitud, "Numero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(m, solicitud);
    } while (m < 1 || m > MAX_REN);

    sprintf_s(solicitud, "Numero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(n, solicitud);
    } while (n < 1 || n > MAX_COL);

    cout << "\nCapturar matriz A:\n";
    double** matriz = CrearArreglo2D(m, n);

    CapturarMatriz(matriz, m, n);
    ImprimirMatriz(matriz, m, n);
    double** matrizT = CrearArreglo2D(n, m);

    system("pause");
    system("cls");
    cout << "TRANSPUESTA DE LA MATRIZ\n" << endl;

    cout << "Matriz original: " << endl;
    ImprimirMatriz(matriz, m, n);

    TranspuestaMatriz(matriz, matrizT, m, n);

    cout << "Transpuesta: " << endl;
    ImprimirMatriz(matrizT, n, m);

    DestruirArreglo2D(matriz, m);
    DestruirArreglo2D(matrizT, m);

    system("pause");
}