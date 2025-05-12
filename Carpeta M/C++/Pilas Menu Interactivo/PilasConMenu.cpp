//Menu interactivo para una pila
//Que permite agregar elementos a la pila
//Mostrar el ultimo elemento agregado a la pila
//Mostrar la pila
//Eliminar un elemento de la pila por nombre
//Eliminar el ultimo elemento agregado a la pila
//Salir del programa
//Se implemento la funcion pop() para eliminar el ultimo elemento agregado a la pila
//Este programa fue realizado con ayuda de IA, pero fue revisado y corregido por un estudiante
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>
using namespace std;

typedef struct Nodo{
    int id;
    char* nombre;
    int edad;
    Nodo* siguiente;
}Nodo;
typedef struct Pila{
    int tam;
    Nodo* cima;
}Pila;
Nodo* topPila(Pila *pila);
bool pilaVacia(Pila *pila);
Pila* crearPila();
void push(Pila* pila, int id, const char* nombre, int edad);
void pop(Pila* pila);
void eliminarPorNombre(Pila* pila, const char* nombre);
void liberarPila(Pila *pila);
void liberarNodo(Nodo *nodo);
void mostrarPila(Pila *pila);
int main(){
    Pila *pila = crearPila();
    int opcion;
    do{
        cout <<"Bienvenido a su menu interactivo de pilas"<<endl;
        cout<<"1. Agregar elemento a la pila"<<endl;
        cout<<"2. Mostrar ultimo elemento agregado a la pila"<<endl;
        cout<<"3. Mostrar pila"<<endl;
        cout<<"4. Eliminar un elemento de la pila por nombre"<<endl;
        cout<<"5. Eliminar el ultimo elemento agregado a la pila"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: {
                char nombre[50];
                int id, edad;
                cout<<"Ingrese el id: ";
                cin>>id;
                cout<<"Ingrese el nombre: ";
                cin>>nombre;
                cout<<"Ingrese la edad: ";
                cin>>edad;
                push(pila, id, nombre, edad);
                cout<<"Elemento agregado correctamente"<<endl;
                break;
            }
            case 2:{
                bool pilaV =  pilaVacia(pila);
                if (pilaV){
                    cout<<"La pila esta vacia"<<endl;
                }else{
                    Nodo *cimaActual = topPila(pila);
                    cout<<"La cima de la pila es: "<<cimaActual->id<<", "<<cimaActual->nombre<<", "<<cimaActual->edad<<endl;
                }
                break;
            }
            case 3:{
                bool pilaV = pilaVacia(pila);
                if (pilaV){
                    cout<<"La pila esta vacia"<<endl;
                }else{
                    mostrarPila(pila);
                }
                break;
            }
            case 4:{
                bool pilaV = pilaVacia(pila);
                if (pilaV){
                    cout<<"La pila esta vacia"<<endl;
                }else{
                    char nombre[50];
                    cout<<"Ingrese el nombre a eliminar: ";
                    cin>>nombre;
                    eliminarPorNombre(pila, nombre);
                }
                break;
            }
            case 5:{
                pop(pila);
                cout<<"Elemento eliminado correctamente"<<endl;
                break;

            }
            
            case 6:{
                cout<<"Saliendo del programa..."<<endl;
                liberarPila(pila);
                break;
            }
        }
    }while(opcion !=6);
}

Nodo *topPila(Pila *pila){
    Nodo *cimaActual = pila->cima;
    return cimaActual;
}
void push(Pila * pila, int id, const char* nombre, int edad){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->id = id;
    nodo->nombre = (char*)malloc(strlen(nombre)+1);
    strcpy(nodo->nombre, nombre);
    nodo->edad = edad;
    if (pila->tam == 0){
        nodo->siguiente = NULL;
        pila->cima = nodo;
    }else{
        nodo->siguiente = pila->cima;
        pila->cima = nodo;
    }
    pila->tam = pila->tam + 1;
}
Pila* crearPila(){
    Pila *pila = (Pila*)malloc(sizeof(Pila));
    pila->tam = 0;
    pila->cima = NULL;
    return pila;
}
bool pilaVacia(Pila *pila){
    int t = pila ->tam;
    bool pilaVacia;
    if (t==0){
        pilaVacia = true;
    }else{
        pilaVacia = false;
    }
    return pilaVacia;
}
void liberarPila(Pila *pila){
    Nodo *nodoActual = pila->cima;
    while (nodoActual != NULL){
        Nodo *nodoEliminar = nodoActual;
        nodoActual = nodoActual->siguiente;
        free(nodoEliminar->nombre);
        free(nodoEliminar);
    }
    free(pila);
}

void mostrarPila(Pila *pila){
    Nodo *nodoActual = pila->cima;
    cout<<"Elementos de la pila: "<<endl;
    while(nodoActual != NULL){
        cout<<nodoActual->id<<","<<nodoActual->nombre<<","<<nodoActual->edad<<endl;
        nodoActual = nodoActual->siguiente;
    }
}
void eliminarPorNombre(Pila *pila, const char* nombre){
    Nodo *nodoActual = pila->cima;
    Nodo *nodoAnterior = NULL;
    while (nodoActual != NULL && strcmp(nodoActual->nombre, nombre) != 0){
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguiente;
    }
    if (nodoActual ==NULL){
        cout<<"No se encontro el nombre"<<endl;
        return;
    }
    if (nodoAnterior == NULL){
        pila->cima = nodoActual->siguiente;
    }else{
        nodoAnterior->siguiente = nodoActual->siguiente;
    
    }
    free(nodoActual->nombre);
    free(nodoActual);
    pila->tam--;
    cout<<"Elemento de la pila eliminado correctamente"<<endl;

}
void pop(Pila* pila) {
    if (pilaVacia(pila)) {
        cout << "La pila ya está vacía" << endl;
        return;
    }
    Nodo* nodoEliminar = pila->cima;
    pila->cima = nodoEliminar->siguiente;
    free(nodoEliminar->nombre);
    free(nodoEliminar);
    pila->tam--;
}




