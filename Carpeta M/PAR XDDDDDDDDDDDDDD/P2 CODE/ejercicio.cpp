#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Nodo{
    int toneladas;
    char* patente;
    struct Nodo* siguiente;
}Nodo;
typedef struct Cola{
    int tam;
    struct Nodo* principio;
    struct Nodo* final;
}Cola;

void enqueue(Cola* cola, int toneladas, char* patente);
void dequeue(Cola* cola);
void front(Cola* cola);
bool isEmpty(Cola* cola);
void mostrarPatentes(Cola* cola);
Cola* crearCola();

int main(){
    Cola* cola= crearCola();
    int opcion;
    char* patente;
    do{
        cout<<"1. Agregar camion."<<endl;
        cout<<"2. Atender al siguiente camion."<<endl;
        cout<<"3. Siguiente camion en ser atendido."<<endl;
        cout<<"4. Estado de cola de camiones"<<endl;
        cout<<"5. Lista de camiones"<<endl;
        cout<<"6. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1: {
                int tonelada;
                cout<<"Digite la patente del camion"<<endl;
                patente = (char*)malloc(50*sizeof(char));
                cin>>patente;
                cout<<"Digite la tonelada del camion"<<endl;
                cin>>tonelada;
                enqueue(cola, tonelada, patente);
                break;          
                
            }
            case 2: {
                dequeue(cola);
                break;        
            }
            case 3: {
                front(cola);
                break;            
            }
            case 4:{
                if (isEmpty(cola)){
                    cout<<"La cola esta vacia"<<endl;                
                }else{
                    cout<<"La cola no esta vacia"<<endl;
                }
                break;
            }
            case 5: {
                mostrarPatentes(cola);
                break;    
            }
            case 6:{
                cout<<"Saliendo del programa.."<<endl;          
            }
        
            default:
                cout<<"Error, opcion invalida"<<endl;
                break;
        }
    }while(opcion !=6);
    
}

Cola* crearCola(){
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->tam = 0;
    cola->principio = NULL;
    cola->final = NULL;
    return cola;
}
bool isEmpty(Cola* cola){
    return (cola->tam ==0);
}
void enqueue(Cola* cola, int toneladas, char* patente){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->patente = (char*)malloc(50*sizeof(char));
    nodo->patente = patente;
    nodo->toneladas = toneladas;
    nodo->siguiente = NULL;
    if (cola->final == NULL){
        cola->principio = nodo;
        cola->final = nodo;
    }else{
        nodo->siguiente = cola->final;
        cola->final = nodo;
    }
    cout<<"Cliente agregado a la cola correctamente"<<endl;
    cola->tam++;
}
void dequeue(Cola* cola){
    if(isEmpty(cola)){
        cout<<"La cola esta vacia"<<endl;
        return;     
    }
    if(cola->tam == 1){
        free(cola->principio);
        cola->principio = NULL;
        cola->final = NULL;
        cola->tam--;    
    }else if(cola->tam>1){
        Nodo* nodoAnterior = cola->principio;
        cola->principio = nodoAnterior->siguiente;
        free(nodoAnterior);
        cola->tam--;
    }
    cout<<"Cliente eliminado correctamente"<<endl;

}
void front(Cola* cola){
    cout<<"El siguiente camion a atender es: "<<cola->principio<<endl;

}
void mostrarPatentes(Cola* cola){
    if(isEmpty(cola)){
        cout<<"La cola esta vacia"<<endl;
        return;    
    }
    Nodo* nodo = cola->principio;
    cout<<"Patentes de camiones"<<endl;
    while(nodo != NULL){
        cout<<"Patentes: "<<nodo->patente<<" Toneladas: "<<nodo->toneladas;
        nodo = nodo->siguiente;
    }
    
}


