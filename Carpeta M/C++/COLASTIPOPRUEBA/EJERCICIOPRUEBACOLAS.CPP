#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

typedef struct Nodo{
    int id;
    string nombre;
    struct Nodo* siguiente;        
}Nodo;
typedef struct Cola{
    int tam;
    struct Nodo* principio;
    struct Nodo* final;
}Cola;

Cola* crearCola();
void enqueue(Cola* cola, int id , string nombre);
void dequeue(Cola* cola);
bool isEmpty(Cola* cola);
void front(Cola* cola);
void reasignarId(Cola* cola);
void mostrarCola(Cola* cola);
int main(){
    Cola* cola = crearCola();
    int opcion;
    int id = 0;
    do{
        cout << "1. Agregar persona a la cola" << endl;
        cout << "2. Atender a la persona con prioridad en la cola" << endl;
        cout << "3. Verificar si la cola esta vacia" << endl;
        cout << "4. Proximo cliente a atender" << endl;
        cout << "5. Mostrar cola" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1: {
                string nombre;
                cout << "Digite el nombre de la persona para agregar" << endl;
                cin >> nombre;
                id++;
                enqueue(cola, id, nombre);
                break;
            }
            case 2: {
                dequeue(cola);
                break;
            }
            case 3: {
                if (isEmpty(cola)) {
                    cout << "La cola esta vacia" << endl;
                } else {
                    cout << "La cola tiene " << cola->tam << " personas" << endl;
                }
                
                break;
            }
            case 4: {
                front(cola);
                break;
            }
            case 5: {
                mostrarCola(cola);
                break;
            }
            case 6: {
                cout << "Saliendo del programa..." << endl;
                free(cola);
                break;
            }
            default: {
                cout << "Opcion no valida, por favor intente de nuevo." << endl;
                break;
            }
        }
    } while (opcion != 6);
}
void enqueue(Cola* cola, int id, string nombre){
    Nodo* nvnodo = new Nodo();
    nvnodo -> id = id;
    nvnodo -> nombre = nombre;
    nvnodo -> siguiente = NULL;
    if(cola->final == NULL){
        cola->principio = nvnodo;
        cola->final = nvnodo;
    }else{
        cola->final->siguiente = nvnodo;
        cola->final = nvnodo;
    }
    cola->tam++;
    cout<<"Cliente agregado a la cola"<<endl;
}
bool isEmpty(Cola* cola){
    return cola->tam == 0;
}
void dequeue(Cola* cola){
    if(isEmpty(cola)){
        cout<<"La cola esta vacia"<<endl;
        return;
    }
    int tam = cola->tam;
    if(tam == 1){
        delete(cola->principio);
        cola->principio = NULL;
        cola->final = NULL;
        cola->tam--;
        cout<<"Persona atendida, la cola se encuentra vacia"<<endl;
    }else if(tam > 1){
        Nodo* nodoAnterior = cola->principio;
        cola->principio = cola->principio->siguiente;
        delete(nodoAnterior);
        cola->tam--;
        reasignarId(cola);
    }
}
void reasignarId(Cola* cola){
    Nodo* actual = cola->principio;
    int id = 1;
    while(actual != NULL){
        actual->id = id++;
        actual = actual->siguiente;
    }
}
void front(Cola* cola){
    if(isEmpty(cola)){
        cout<<"La cola esta vacia"<<endl;
        return;
    }
    cout<<"El proximo cliente a atender es: " << cola->principio->nombre << " con ID: " << cola->principio->id << endl;
}
void mostrarCola(Cola* cola){
    Nodo* actual = cola->principio;
    if(isEmpty(cola)){
        cout << "La cola esta vacia" << endl;
        return;
    }
    cout << "Clientes en la cola: " << endl;
    while(actual != NULL){
        cout << "ID: " << actual->id << ", Nombre: " << actual->nombre << endl;
        actual = actual->siguiente;
    }
}
Cola* crearCola(){
    Cola* cola = new Cola();
    cola->tam = 0;
    cola->principio = NULL;
    cola->final = NULL;
    return cola;
}

