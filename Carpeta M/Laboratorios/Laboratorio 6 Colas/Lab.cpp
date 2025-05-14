//Maicol Aracena 
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Nodo{
    int valor;
    struct Nodo* siguiente;
}Nodo;
typedef struct Cola{
    int tam;
    Nodo* principio;
    Nodo* final;
}Cola;
Cola* crearCola();
void agregarCliente(Cola* cola, int valor);
void atenderCliente(Cola* cola);
void mostrarClientes(Cola* cola);
bool isEmpty(Cola* cola);
void siguienteCliente(Cola* cola);
int main(){
    Cola* cola = crearCola();
    int opcion;
    do{
        cout<<"1. Agregar clientes"<<endl;
        cout<<"2. Atender al primer cliente"<<endl;
        cout<<"3. Mostrar clientes en la cola"<<endl;
        cout<<"4. Mostrar el siguiente cliente a atender"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                int numeroCliente;
                cout<<"Digite el numero del cliente"<<endl;
                cin>>numeroCliente;
                agregarCliente(cola,numeroCliente);
                break;
            }
            case 2:{
                atenderCliente(cola);
                break;
            }
            case 3:{
                mostrarClientes(cola);
                break;
            }
            case 4:{
                siguienteCliente(cola);
                break;
            }
            case 5:
                cout<<"Saliendo del programa...";
                break;
            default:
                cout<<"Opcion incorrecta, vuelva a digitar la opcion"<<endl;
                break;

        }
    }while(opcion !=5);
    return 0;
}

Cola* crearCola(){
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->tam = 0;
    cola->principio = NULL;
    cola->final = NULL;
    return cola;
}
void agregarCliente(Cola* cola, int valor){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    if(cola->final == NULL){
        cola->principio = nuevoNodo;
        cola->final = nuevoNodo;
    }else{
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
    cout << "Cliente agregado a la cola" << endl;
    cola->tam++;
}
void atenderCliente(Cola* cola){
    if (isEmpty(cola)){
        cout<<"La cola esta vacia"<<endl;
        return;
    }
    int tam = cola->tam;
    if (tam == 1){
        free(cola->principio);
        cola->principio = NULL;
        cola->final = NULL;
        cola->tam = cola ->tam - 1;
        cout<<"Cliente atendido"<<endl;
    }else if(tam>1){
        Nodo* principioAnterior = cola->principio;
        cola->principio = principioAnterior->siguiente;
        free(principioAnterior);
        cola->tam = cola->tam - 1;
        cout<<"Cliente atendido"<<endl;
    }
}
void mostrarClientes(Cola* cola){
    if (isEmpty(cola)){
        cout<<"La cola esta vacia"<<endl;
    }else{
        Nodo* nodoActual = cola->principio;
        cout<<"Cola de clientes(tickets): "<<endl;
        while(nodoActual != NULL){
            cout<<nodoActual->valor<<endl;
            nodoActual = nodoActual->siguiente;
        }   
    }
}
bool isEmpty(Cola* cola){
    return(cola->tam == 0);
}
void siguienteCliente(Cola* cola){
    if (isEmpty(cola)){
        cout<<"La cola esta vacia"<<endl;
    }
    cout<<"El siguiente ticket del cliente a atender es: "<< cola->principio->valor<<endl;
}




