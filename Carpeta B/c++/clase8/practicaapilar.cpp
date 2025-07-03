#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

typedef struct Nodo {
    string dato;
    Nodo* siguiente;
} Nodo;


int main(int argc, char const *argv[])
{
    // estamos inicializando varios nodos de forma manual
    Nodo* cabeza = (Nodo*)malloc(sizeof(Nodo));
    Nodo* segundo = (Nodo*)malloc(sizeof(Nodo));
    Nodo* tercero = (Nodo*) malloc(sizeof(Nodo));
    Nodo* cuarto = (Nodo*) malloc(sizeof(Nodo));


    // asignamos los valores a los nodos
    /**
     * @struct dato
     * @brief Contiene el dato de tipo string que representa el contenido de la página. 
     * @struct siguiente
     * @brief Puntero al siguiente nodo en la lista, que permite enlazar múltiples
     * 
     */
    cabeza->dato = "Página 1";
    cabeza->siguiente = segundo;
    segundo->dato = "Página 2";
    segundo->siguiente = tercero;
    tercero->dato = "Página 3";
    tercero->siguiente = cuarto;   
    cuarto->dato = "Página 4";
    cuarto->siguiente = nullptr; // El último nodo apunta a nullptr 

    cout << "Contenido de la lista enlazada:" << endl;

    // Recorrer e imprimir toda la lista
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;

    cout << "Fin" << endl;

    printf("Si\n");
    return 0;
}
