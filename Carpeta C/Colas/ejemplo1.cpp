#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Nodo {
    int saldo;
    char* rut;
    struct Nodo *siguiente;
} Nodo;

typedef struct Cola {
    Nodo* principio;
    Nodo* final;
    int tam;
} Cola;

Cola* crearCola();
Nodo* crearNodo(Cola* cola);
void enquehue(Cola* cola);
void dequeue(Cola* cola);
Nodo* front(Cola* cola);
bool isEmpty(Cola* cola);
void imprimirMenu();
void imprimirIsEmpty(bool esVacio);
void iniciar();
void imprimirColas(Cola* cola);
void imprimirUnNodo(Nodo* nodoInicio);
void atender(Nodo* primero, Cola* cola);

int main() {
    iniciar();
}

Cola* crearCola() {
    Cola* cola = (Cola*) malloc(sizeof(Cola));
    cola -> principio = NULL;
    cola -> final = NULL;
    cola -> tam = 0;
    return cola;
}

Nodo* crearNodo(Cola* cola) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo -> rut = (char*) malloc(20 * sizeof(char));
    cout<<"Ingrese su rut: ";
    cin.ignore();
    cin.getline(nuevoNodo -> rut, 20);
    nuevoNodo -> saldo = 0;
    nuevoNodo -> siguiente = NULL;
    return nuevoNodo;
}

void enquehue(Cola* cola) {
    Nodo* nuevoNodo = crearNodo(cola);
    if(cola -> tam == 0) {
        cola -> principio = nuevoNodo;
        cola -> final = nuevoNodo;
    } else {
        // otra opcion
        // Nodo* final_anterior = cola -> final;
        // cola -> final  = nuevoNodo;
        // final_anterior -> siguiente = nuevoNodo;
        cola -> final -> siguiente = nuevoNodo;
        cola -> final = nuevoNodo;
    }
    cola -> tam += 1;
}

void dequeue(Cola* cola) {
    Nodo* primero = front(cola);
    int tam = cola -> tam;
    if(tam == 1) {
        free(primero);
        cola -> principio = NULL;
        cola -> final = NULL;
        cola -> tam -= 1;
    } else if(tam > 1) {
        Nodo* eliminar = cola -> principio;
        cola -> principio = eliminar -> siguiente;
        free(eliminar);
        cola -> tam -= 1;
    }
}

void atender(Nodo* primero, Cola* cola) {
    if (!isEmpty(cola)) {
        int saldoIngresado;
        cout<<"POV: ERES EL CLIENTE\n";
        cout<<"hola, cuanto saldo quiere agregar a su cuenta? ";
        cin>>saldoIngresado;
        primero -> saldo += saldoIngresado;
        cout<<"Se han cargado $"<<saldoIngresado<<" pesos a su cuenta, chao vuelva pronto :)\n"<<endl;
        cout<<"=== Nuevos datos ===\n";
        imprimirUnNodo(primero);
    } else cout<<"No hay clientes en la fila\n";
}

Nodo* front(Cola* cola) {
    return cola -> principio;
}

bool isEmpty(Cola* cola) {
    return cola -> tam == 0;
}

void imprimirMenu() {
    cout << "===== BIENVENIDO =====" << endl;
    cout << "1. Agregar a la cola" << endl;
    cout << "2. Quitar de la cola" << endl;
    cout << "3. Ver datos cliente actual" << endl;
    cout << "4. Verificar si la cola está vacía" << endl;
    cout << "5. Imprimir cola" << endl;
    cout << "6. Atender al cliente" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void imprimirIsEmpty(bool esVacio) {
    if(esVacio) cout<<"La cola está vacía"<<endl; else cout<<"La cola no está vacía\n";
}

void iniciar() {
    int opcion;
    Cola* cola = crearCola();
    while(opcion != 7) {
        imprimirMenu();
        cin>>opcion;
        if(opcion == 1) {
            enquehue(cola);
        } else if (opcion == 2) {
            dequeue(cola);
        } else if (opcion == 3) {
            imprimirUnNodo(front(cola));
        } else if (opcion == 4) {
            imprimirIsEmpty(isEmpty(cola));
        } else if (opcion == 5) {
            imprimirColas(cola);
        } else if (opcion == 6) {
            atender(front(cola), cola);
        } else if (opcion == 7) {
            cout<<"Saliendo..."<<endl;
        } else {
            cout<<"Opcion no valida"<<endl;
        }
    }
}

void imprimirUnNodo(Nodo* nodoInicio) {
    cout<<"\nRut: "<<nodoInicio->rut<<endl;
    cout<<"Saldo: "<<nodoInicio->saldo<<"\n"<<endl;
}

void imprimirColas(Cola* cola) {
    Nodo* actual = cola -> principio;
    if(cola -> tam == 0) {
        cout<<"inicio -> NULL\nfinal -> NULL"<<endl;
    } else {
        cout<<"inicio -> ";
        while(actual != NULL) {
            cout<<actual->rut<<" -> ";
            actual = actual -> siguiente;
        }
        cout<<"NULL"<<endl;
    }

}