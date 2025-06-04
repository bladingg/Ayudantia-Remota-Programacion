#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Nodo{
    int valor;
    Nodo *siguiente;
}Nodo;

typedef struct Cola{
    int tam;
    Nodo *principio;
    Nodo *final;
}Cola;

Cola* crearCola();
void enqueue(Cola* cola, int valor);
void mostrarCola(Cola* cola);
void front(Cola* cola);
void dequeue(Cola* cola);
int main(){
    Cola* cola = crearCola();
    int opcion;
    do{
        cout<<"1. Ingrese cola a agregar"<<endl;
        cout<<"2. Mostrar colas"<<endl;
        cout<<"3. Mostrar el front de la cola"<<endl;
        cout<<"4. Eliminar el elemento princpial"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                int valor;
                cout<<"Digite el valor a ingresar"<<endl;
                cin>>valor;
                enqueue(cola, valor);
                break;
            }
            case 2:{
                mostrarCola(cola);
                break;
            }
            case 3:{
                front(cola);
                break;
            }
            case 4:{
                dequeue(cola);
                break;
            }
            case 5:{
                cout<<"Saliendo del programa"<<endl;
                break;
            }
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(opcion !=5);
}

Cola* crearCola(){
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->tam = 0;
    cola->principio = NULL;
    cola->final = NULL;
    return cola;
}
void enqueue(Cola* cola, int valor){
    int tam = cola->tam;
    Nodo* nodo= (Nodo*)malloc(sizeof(Nodo));
    nodo->valor = valor;
    nodo->siguiente = NULL;

    if (tam ==0){
        cola->principio = nodo;
        cola->final = nodo;
    }else{
        Nodo* finalAnterior = cola->final;
        cola->final = nodo;
        finalAnterior->siguiente = nodo;

    }
    cola->tam++;
}
void mostrarCola(Cola* cola){
    Nodo* nodoActual= cola->principio;
    cout<<"Los elementos de la cola son: "<<endl;
    while(nodoActual !=NULL){
        cout<<nodoActual->valor<<endl;
        nodoActual = nodoActual->siguiente;
    }
}
void front(Cola* cola){
    if (cola->tam == 0){
        cout<<"La cola esta vacia"<<endl;
    }else{
        cout<<"El front de la cola es: "<<cola->principio->valor<<endl;
    }
}
void dequeue(Cola* cola){
    if(cola->tam >0){
        Nodo *nodoActual = cola->principio;
        cola->principio = nodoActual->siguiente;
        if(cola->principio == NULL){
            cola->final = NULL;
        }
        cout<<"Se elimino el elemento: "<<nodoActual->valor<<endl;
        free(nodoActual);
        cola->tam--;
    } 
    else{
        cout<<"La cola esta vacia"<<endl;
    }
}