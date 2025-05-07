#include <iostream>
#include <stdlib.h>
using namespace std

struct Nodo{
    int id;
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
void push(Pila* pila, int id){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo -> id = id;
    if (pila->tam == 0){
        nodo->siguiente = NULL;
        pila->cima = nodo;
    }else{
        nodo->siguiente = pila->cima;
        pila->cima = nodo;
    }
    pila->tam = pila->tam + 1;
}

int main(){
    Pila pila = crearPila();
    int opcion;
    do{
        cout<<"1. Ingrese un nuevo elemento a la pila"<<endl;
        cout<<"2. Ver el ultimo elemento ingresado a la pila"<<endl;
        cout<<"3. Verificar si hay un elemento en la pila"<<endl;
        cout<<"4. Salir del programa"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
            
            case 2:
            Nodo* cima = topPila(pila);
            if (cima != NULL){
                cout << "Valor del ultimo elemento ingresado: " << cima->id <<endl;
            }
            break;
            case 3:
                bool es_vacia = ::is_empty(pila);
                cout << "¿Existe un elemento en la pila?: " << es_vacia << endl;
                break;
            case 4:
                

        }
            
    }
}