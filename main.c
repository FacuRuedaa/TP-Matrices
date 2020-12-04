#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#include <time.h>
#define FIL 3
#define COL 3
#define ESC 27
#define F 10
#define C 30
#include <string.h>

void menu ();
void cargarMatrizRandomEnteros (int filas, int columnas, int A[filas][columnas]);
void cargarMatrizEnteros (int filas, int columnas, int A[filas][columnas]);
void mostrarMatriz (int filas, int columnas, int A[filas][columnas]);
int sumaMatriz (int filas, int columnas, int A[filas][columnas]);
float promedioMatriz (int filas, int columnas, int A[filas][columnas]);
int dato ();
int buscaDato (int filas, int columnas, int A[filas][columnas]);
int cargarArregloString (int filas, int columnas, char nombre[][columnas], int v);
void mostrarArregloString (int col, char nombre [][col], int v);
int buscaString (int col, char nombre[][col], int v, char palabra[]);
/// char menorString (int col, char nombre[][col], int v);
int posicionMenor (int col, char nombre[][col], int v, int c);
void ordenaStringPorSeleccion (int col, char nombre[][col], int v);
int determinanteMatrizEnteros (int filas, int columnas, int A[filas][columnas]);
void MatrizInversa (int fil, int col, int M[fil][col]);
void productoDeMatriz (int fil, int col, int A[fil][col], int f, int c, int B[f][c], int s, int t, int MatrizProducto[s][t]);

int main()
{
    int matrizEnteros [FIL][COL];
    int matrizDeterminante [2][2];
    int Matriz2x5 [2][5];
    int MatrizFinal [2][5];
    srand(time(NULL));
    int ejercicio, opcion, bandera, v=0, band;
    char palabras [F][C];
    char pino[] = "river";
    do{
        system("cls");
        menu();
        scanf("%d", &ejercicio);
        switch (ejercicio) {
        case 1:
            cargarMatrizRandomEnteros(FIL,COL,matrizEnteros);
            break;
        case 2:
            cargarMatrizEnteros (FIL, COL, matrizEnteros);
            break;
        case 3:
            mostrarMatriz(FIL, COL, matrizEnteros);
            break;
        case 4:
            printf("\nLa suma de los elementos de la matriz es de: %d\n", sumaMatriz(FIL,COL, matrizEnteros));
            break;
        case 5:
            printf("\nEl promedio de la matriz es de: %.2f", promedioMatriz(FIL, COL, matrizEnteros));
            break;
        case 6:
            bandera = buscaDato(FIL, COL, matrizEnteros);
            if (bandera == 1) {
                printf("\nEl dato se encuentra en la matriz\n");
            } else {
                printf("\nEl dato no se encuentra en la matriz\n");
            }
            break;
        case 7:
            v=cargarArregloString(F, C, palabras, v);
            break;
        case 8:
            mostrarArregloString(C, palabras, v);
            break;
        case 9:
            band = buscaString(C, palabras, v, pino);
            if (band == 0) {
                printf("\nLa palabra existe en el arreglo de string\n");
            } else {
                printf("\nLa palabra no se encuentra en el arreglo de string\n");
            }
            break;
        case 10:
            ordenaStringPorSeleccion(C, palabras, v);
            break;
        case 11:
            cargarMatrizRandomEnteros(2, 2, matrizDeterminante);
            mostrarMatriz(2, 2, matrizDeterminante);
            printf("\nEl determinante de la matriz es de: %d", determinanteMatrizEnteros(2, 2, matrizDeterminante));
            break;
        case 12:
            cargarMatrizRandomEnteros(2, 2, matrizDeterminante);
            mostrarMatriz(2, 2, matrizDeterminante);
            MatrizInversa(2, 2, matrizDeterminante);
            mostrarMatriz(2, 2, matrizDeterminante);
            productoDeMatriz(2, 2, matrizDeterminante, 2, 5, Matriz2x5, 2, 5, MatrizFinal);
            mostrarMatriz(2, 5, MatrizFinal);
            break;
        case 13:
            cargarMatrizRandomEnteros(2, 2, matrizDeterminante);
            cargarMatrizRandomEnteros(2, 5, Matriz2x5);
            mostrarMatriz(2, 2, matrizDeterminante);
            mostrarMatriz(2, 5, Matriz2x5);
            productoDeMatriz(2, 2, matrizDeterminante, 2, 5, Matriz2x5, 2, 5, MatrizFinal);
            mostrarMatriz(2, 5, MatrizFinal);
            break;
        default:
            printf("\nOpcion incorrecta\n");
        }
        printf("\n\t\t Presiones ESC para salir...\n\n");
        opcion = getch();
        system("pause");
    } while (opcion!=ESC);

    return 0;
}

void menu ()
{
    printf("\n\t\t\tTRABAJO PRACTICO NUMERO 4.1\n\n");
    printf("1) Cargar una matriz random\n");
    printf("2) Cargar una matriz por el usuario\n");
    printf("3) Mostrar la matriz\n");
    printf("4) Suma de los elementos de la matriz\n");
    printf("5) Promedio elementos de la matriz\n");
    printf("6) Buscar un elemento en la matriz\n");
    printf("7) Cargar un arreglo de strings\n");
    printf("8) Mostrar un arreglo de strings\n");
    printf("9) Buscar una palabra en el arreglo de string\n");
    printf("10)Ordenar por seleccion el arreglo de string\n");
    printf("11)Determinante matriz 2x2\n");
    printf("12)Matriz inversa\n");
    printf("13)Producto de dos matrices\n");
}

void cargarMatrizRandomEnteros (int filas, int columnas, int A[filas][columnas])
{
    int i, j;

    for (i=0; i<filas; i++) {
        for (j=0; j<columnas; j++) {
            A[i][j] = rand()%100;
        }
    }
}

void cargarMatrizEnteros (int filas, int columnas, int A[filas][columnas])
{
    int i, j;

    for (i=0; i<filas; i++) {
        for (j=0; j<columnas; j++) {
            printf("\nIngrese un valor a la matriz: \n");
            scanf("%d", &A[i][j]);
            system("cls");
        }
    }
}

void mostrarMatriz (int filas, int columnas, int A[filas][columnas])
{
    int i, j;

    printf("\nEl contenido de la matriz es: \n");

    for (i=0; i<filas; i++) {
            printf("\n\n\t");
        for (j=0; j<columnas; j++) {
            printf("%d - ", A[i][j]);
        }
    }
    printf("\n");
}

int sumaMatriz (int filas, int columnas, int A[filas][columnas])
{
    int i, j, suma=0;

    for (i=0; i<filas; i++) {
        for (j=0; j<columnas; j++) {
            suma = suma + A[i][j];
        }
    }
    return suma;
}

float promedioMatriz (int filas, int columnas, int A[filas][columnas])
{
    int i, j,suma=0, cantidad=0;
    float promedio=0;
    suma = sumaMatriz(filas, columnas, A);
    cantidad = filas + columnas;

    promedio = (float) suma / cantidad;

    return promedio;
}

int dato ()
{
    int aBuscar;

    printf("\nIngrese el elemento a buscar en la matriz: \n");
    scanf("%d", &aBuscar);

    return aBuscar;
}

int buscaDato (int filas, int columnas, int A[filas][columnas])
{
    int elemento, i=0, j=0, flag=0;

    elemento = dato();

    while (i<filas && flag == 0){
        while (j<columnas && flag == 0) {
            if (A[i][j] == elemento) {
                flag = 1;
            } else {
                flag = 0;
            }
            j++;
        }
        j=0;
        i++;
    }
    return flag;
}
/// fil es la dimension
/// col es la cantidad de caracteres que puede tener la fila

int cargarArregloString (int filas, int columnas, char nombre[][columnas], int v)
{
    char opcion;
    while (v<filas && opcion!= ESC) {
        printf("\nIngrese las palabras que desea guardar: \n");
        fflush(stdin);
        gets(nombre[v]);
        v++;

        printf("\nESC para salir o cualquier tecla para cargar otra palabra\n");
        opcion=getch();
        system("cls");
    }
    return v;
}

void mostrarArregloString (int col, char nombre [][col], int v)
{
    for (int i=0; i<v; i++) {
        printf("%s - ", nombre[i]);
    }
    printf("\n");
}

int buscaString (int col, char nombre[][col], int v, char palabra[])
{
    int i=0;
    int igual=1;

    while (i<v && igual != 0){
        igual = strcmpi(nombre[i], palabra);
        i++;
    }
    return igual;
}

int posicionMenor (int col, char nombre[][col], int v, int c)
{
    int i=c+1;
    int posMenor=c;

    while (i<v) {
        if (strcmp(nombre[i], nombre[posMenor])<0) {
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenaStringPorSeleccion (int col, char nombre[][col], int v)
{
    int pos=0;
    char aux [C];

   for (int i=0; i<v-1; i++) {
        pos = posicionMenor(col, nombre, v, i);
        strcpy(aux, nombre[i]);
        strcpy(nombre[i], nombre[pos]);
        strcpy(nombre[pos], aux);
    }
}

int determinanteMatrizEnteros (int filas, int columnas, int A[filas][columnas])
{
    int a, b, c, d, determinante;

    a = A[0][0];
    b = A[0][1];
    c = A[1][0];
    d = A[1][1];

    determinante = (a*d) - (b*c);

    return determinante;
}

void MatrizInversa (int fil, int col, int M[fil][col]) /// NO FUNCIONA
{
    int i=0, j=0;
    float det;
    det = (float) 1 / determinanteMatrizEnteros(fil, col, M);
    for (i=0; i<fil; i++) {
        for (j=0; j<col;j++){
            M[i][j] = M[i][j]*det;
        }
        j=0;
    }
}

void productoDeMatriz (int fil, int col, int A[fil][col], int f, int c, int B[f][c], int s, int t, int MatrizProducto[s][t])
{

    for (int i=0; i<s; i++){
        for (int j=0; j<t; j++){
            MatrizProducto[i][j] = (A[i][0] * B[0][j] + A[i][1]*B[1][j]);
        }
    }
}
