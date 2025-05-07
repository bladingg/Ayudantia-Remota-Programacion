#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    char* nombre;
    struct Nodo *siguiente;
} Nodo;

typedef struct Pila {
    int tam;
    Nodo* cima;
} Pila;

using namespace std;

void iniciarPrograma(Pila *pila);
Pila* crearPila();
void insertarInicio(Nodo* nodo, Pila* pila);
Nodo* top(Pila* pila);
bool isEmpty(Pila *pila);
void imprimirMenu();
void liberarPila(Pila* pila);
void liberarNodo(Nodo* nodo);
Nodo* crearNodo(Pila* pila);
void imprimirCancion(Nodo* nodo);

int main() {
    Pila* pila = crearPila();
    iniciarPrograma(pila);
    if(isEmpty(pila)) liberarPila(pila);
    else{
        Nodo* nodoRecorrer = pila -> cima;
        while(nodoRecorrer != NULL){
            Nodo* aux = nodoRecorrer;
            nodoRecorrer = nodoRecorrer -> siguiente;
            liberarNodo(aux);
        
        }
        liberarPila(pila);
    }
    return 0;
}

void iniciarPrograma(Pila* pila){
    int opcion=0;
    while(true){
        imprimirMenu();
        cout<<"Ingresar opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: {

                
                Nodo * nuevoNodo = crearNodo(pila);
                insertarInicio(nuevoNodo, pila);
                cout<<"Cancion agregada correctamente."<<endl;
                break;
                
            }
            
            case 2: {
                if(isEmpty(pila)) cout<<"No hay canciones en la lista."<<endl;
                else{
                    imprimirCancion(top(pila));
                }
                break;
            }
            
            case 3: {
                if(isEmpty(pila)) cout<<"No hay canciones en la lista."<<endl;
                else{
                    cout<<"Hay canciones en la lista."<<endl;
                }
                break;
            }
            
            case 4: {

                
                cout<<"Saliendo del programa..."<<endl;
                return;
                
            }
                default: {

                    cout<<"Opcion no valida. Intente de nuevo."<<endl;
                    break;
                }
            
        }
    }
}



Nodo* crearNodo(Pila* pila) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo -> nombre = (char*) malloc(100 * sizeof(char));
    
    cout<<"Ingrese el nombre de la cancion: ";
    cin.ignore();
    cin.getline(nuevoNodo -> nombre, 100);
    
    return nuevoNodo;

}

void imprimirCancion(Nodo* nodo) {
    cout<<"Nombre de la cancion: "<<nodo->nombre<<endl;
}

Pila* crearPila() {
    Pila *pila = (Pila*) malloc(sizeof(Pila));
    pila -> tam = 0;
    pila -> cima = NULL;
    return pila;
}

void insertarInicio(Nodo* nodo, Pila* pila) {
    nodo -> siguiente = pila -> cima;
    pila -> cima = nodo;
    pila -> tam += 1;
}

Nodo* top(Pila* pila) {
    return pila -> cima;
}

bool isEmpty(Pila *pila) {
    if (pila -> tam == 0) {
        return true;
    } else return false;
}

void imprimirMenu() {

    cout<<"------------------Menu de gestor de canciones-----------------"<<endl;
    cout<<"1. Agregar cancion"<<endl;
    cout<<"2. Ver proxima cancion en reversa"<<endl;
    cout<<"3. Comprobar si hay canciones"<<endl;
    cout<<"4. Salir del programa"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;

}

void liberarPila(Pila* pila) {
    free(pila);
}

void liberarNodo(Nodo* nodo) {
    free(nodo);
}





