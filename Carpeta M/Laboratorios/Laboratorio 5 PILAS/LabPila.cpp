//MAICOL ARACENA Y BENJAMIN ALEGRE
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Nodo{
    int id;
    Nodo* siguiente;
}Nodo;

typedef struct Pila{
    int tam;
    Nodo* cima;
}Pila;

Nodo* topPila(Pila* pila){
    Nodo* cima = pila->cima;
    return cima;
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
    Pila* pila = crearPila();
    int opcion;
    do{
        cout<<"1. Ingrese una nueva tarea"<<endl;
        cout<<"2. Tarea mas urgente"<<endl;
        cout<<"3. Verificar si hay un elemento en la pila"<<endl;
        cout<<"4. Salir del programa"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                int id;
                cout<<"Ingrese el id de la tarea: "<<endl;
                cin>>id;
                push(pila, id);
                break;
            }
            case 2:{
                Nodo* cima = topPila(pila);
                if (cima != NULL)
                    cout << "Tarea mas urgente: " << cima->id <<endl;
                break;
            }
            case 3:{
                bool es_vacia = ::is_empty(pila);
                cout << "¿Existen tareas pendientes?: " << es_vacia << endl;
                break;

            }  
            case 4:{
                cout<<"Saliendo del programa..."<<endl;
                free(pila);
                break;
            }
        }        
    }while (opcion !=4);
    return 0;
}
