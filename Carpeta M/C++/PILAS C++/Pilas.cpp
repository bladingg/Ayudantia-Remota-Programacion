#include <iostream>
#include <cstring>
using namespace std;

struct Nodo {
    int id;
    char* nombre;
    int edad;
    Nodo* siguiente;  
};
struct Pila{
    int tam;
    Nodo* cima;
};

Nodo* topPila(Pila* pila){
    Nodo* cimaActual = pila->cima;
    return cimaActual;
}
bool is_empty(Pila* pila) {
    int t = pila->tam;
    bool pila_vacia;
    if (t == 0) {
        pila_vacia = true;
    } else {
        pila_vacia = false;
    }
    return pila_vacia;
}

Pila* crearPila(){
    Pila * pila = (Pila*)malloc(sizeof(Pila));
    pila->tam = 0;
    pila->cima = NULL;
    return pila;
}
void push(Pila* pila, int id, const char* nombre, int edad){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo -> id = id;
    nodo -> nombre = (char*)malloc(strlen(nombre)+1);
    strcpy(nodo->nombre, nombre);
    nodo -> edad = edad;
    if (pila->tam == 0){
        nodo->siguiente = NULL;
        pila->cima = nodo;
    }else{
        nodo->siguiente = pila->cima;
        pila->cima = nodo;
    }
    pila->tam = pila->tam + 1;
}

int main() {
    Pila* pila = crearPila();

    bool es_vacia = ::is_empty(pila);
    cout << "¿Pila vacía?: " << es_vacia << endl;

    push(pila, 5, "Marcelo", 30);
    push(pila, 20, "Martin", 40);
    push(pila, 30, "Ana", 25);

    es_vacia = :: is_empty(pila);
    cout << "¿Pila vacía?: " << es_vacia << endl;

    Nodo* cima = topPila(pila);
    if (cima != NULL)
        cout << "Valor actual de la cima: " << cima->id << ", " << cima->nombre << ", " << cima->edad << endl;

    Nodo* actual = pila->cima;
    while (actual != NULL) {
        cout << "ID: " << actual->id
             << ", Nombre: " << actual->nombre
             << ", Edad: " << actual->edad << endl;
        actual = actual->siguiente;
    }
    return 0;
}
