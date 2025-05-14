#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct Nodo{
    int valor;
    char* nombre;
    struct Nodo* siguiente; 
}Nodo;

typedef struct Cola{
    int tam;
    Nodo* principio;
    Nodo* final;
}Cola;
Cola* crearCola();
void enqueue(Cola* cola, int valor, const char* nombre);
void dequeue(Cola* cola);
void mostrarCola(Cola* cola);
bool isEmpty(Cola* cola);
void front(Cola* cola);

int main(){
    Cola* cola = crearCola();
    int opcion;
    do{
        cout << "1. Agregue personas a la cola" << endl;
        cout << "2. Elimine a la persona atendida" << endl;
        cout << "3. Mostrar el orden de la cola" << endl;
        cout << "4. Persona con prioridad de atencion" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:{
                int valor;
                char nombre[20];
                cout << "Ingrese su numero de ticket: ";
                cin >> valor;
                cout << "Ingrese su nombre: ";
                cin >> nombre;
                enqueue(cola, valor, nombre);
                break;
            }
            case 2:
                dequeue(cola);
                break;
            case 3:
                mostrarCola(cola);
                break;
            case 4:
                front(cola);
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }while(opcion != 5);
    return 0;
}

Cola* crearCola(){
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    cola->tam = 0;
    cola->principio = NULL;
    cola->final = NULL;
    return cola;
}

void enqueue(Cola* cola, int valor, const char* nombre){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->nombre = (char*)malloc(20*sizeof(char));
    strcpy(nuevoNodo->nombre, nombre);
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

void dequeue(Cola* cola){
    if (isEmpty(cola)){
        cout << "La cola esta vacia" << endl;
        return;
    }
    int tam = cola->tam;
    if (tam == 1){
        free(cola->principio);
        cola->principio = NULL;
        cola->final = NULL;
        cola->tam = cola ->tam - 1;
    }else if(tam>1){
        Nodo* principioAnterior = cola->principio;
        cola->principio = principioAnterior->siguiente;
        free(principioAnterior);
        cola->tam = cola->tam - 1;
    }
}
bool isEmpty(Cola* cola){
    return (cola->tam == 0);
}
void mostrarCola(Cola* cola){
    if (isEmpty(cola)){
        cout << "La cola esta vacia" << endl;
        return;
    }else{
        Nodo* actual = cola->principio;
        cout << "Cola: "<<endl;
        while (actual != NULL){
            cout << actual->valor << ","<< actual->nombre<<endl;
            actual = actual->siguiente;
        }
        cout << endl;
    }
}
void front(Cola* cola){
    if (isEmpty(cola)){
        cout << "La cola esta vacia" << endl;
        return;
    }
    cout << "El primer cliente en la cola es: " << cola->principio->valor << "," << cola->principio->nombre << endl;
}


