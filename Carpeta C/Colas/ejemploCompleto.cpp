// Situación:
// En un centro de atención telefónica, cada cliente que llama es puesto en espera. 
// Las llamadas deben atenderse en el mismo orden en que llegan, por lo tanto se 
// requiere una estructura de datos tipo cola (FIFO).

// Por ejemplo, si los clientes llaman en este orden: Lucía, Carlos, Elena, deben ser atendidos en ese mismo orden.

// Se debe implementar un sistema que simule esta cola de llamadas utilizando una lista enlazada simple, que permita:

// Agregar un cliente (nombre)

// Visualizar el primer cliente en la cola (quién será atendido)

// Verificar si existen clientes esperando

// Tarea para el estudiante:
// Diseñar en C++ una cola utilizando listas enlazadas simples que administre las 
// llamadas cumpliendo las siguientes operaciones:

// enqueue(nombre): Agregar un nuevo cliente al final de la cola.

// front(): Ver el primer cliente en la cola.

// isEmpty(): Verificar si hay clientes en la cola.

// Además, permitir al usuario interactuar con estas opciones a través de un menú en main().

#include <iostream>
#include <stdlib.h>

typedef struct Nodo {
    struct Nodo* siguiente;
    char* nombre;
    int numero;
    bool mayor;
} Nodo;

typedef struct Cola {
    Nodo* inicio;
    Nodo* final;
    int tam;
} Cola;

using namespace std;

bool esMayor(int edad) {
    return edad >= 18;
}

void esMayorString(bool esMayor) {
    if(esMayor) cout<<"Si\n"; else cout<<"No\n";
}

Cola* crearCola() {
    Cola* cola = (Cola*) malloc(sizeof(Cola));
    cola -> tam = 0;
    cola -> inicio = NULL;
    cola -> final = NULL;
    return cola;
}

Nodo* crearNodo() {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->nombre = (char*) malloc(40 * sizeof(char));
    nuevoNodo-> siguiente = NULL;
    int edad;
    cout<<"Ingrese nombre de la persona: ";
    cin>>nuevoNodo->nombre;
    cout<<"Ingrese el numero de telefono de la persona: ";
    cin>>nuevoNodo->numero;
    cout<<"Ingrese edad: ";
    cin>>edad;
    bool mayor = esMayor(edad);
    nuevoNodo -> mayor = mayor;
    return nuevoNodo;
}

void enquehue(Cola* cola, Nodo* nuevoCliente) {
    if (cola -> tam == 0) {
        cola -> inicio = nuevoCliente;
        cola -> final = nuevoCliente;
        cola -> tam += 1;
    } else {
        cola -> final -> siguiente = nuevoCliente;
        cola -> final = nuevoCliente;
        cola -> tam += 1;
    }
    cout<<"Cliente agregado\n"<<endl;
}

Nodo* front(Cola* cola) {
    return cola -> inicio;
}

void dequehue(Cola* cola) {
    if(cola -> tam == 1) {
        free(front(cola));
        cola -> inicio = NULL;
        cola -> final = NULL;
        cola -> tam -= 1;
    } else if (cola -> tam > 1){
        Nodo* nodoInicio = front(cola);
        cola -> inicio = cola -> inicio -> siguiente;
        free(nodoInicio);
        cola -> tam -= 1;
    }
    cout<<"Cliente atendido, se elimino de la cola\n";
}

void imprimirMenu() {
    cout<<"\n1. Llega nuevo cliente"<<endl;
    cout<<"2. Se atiende a cliente, se elimina"<<endl;
    cout<<"3. Comprobar si la fila tiene gente"<<endl;
    cout<<"4. Imprimir cola"<<endl;
    cout<<"5. Salir\n"<<endl;
    cout<<"Ingresar opcion: ";
}

bool isEmpty(Cola* cola) {
    return cola -> tam == 0;
}

void atender(Nodo* front) {
    Nodo* cliente = front;
    cout<<"Atendiendo al cliente "<<cliente->nombre<<"\n";
    cout<<"Nombre: "<<cliente->nombre<<"\n"<<"Numero telefono: "<<cliente->numero<<"\n"<<"Es mayor de edad: ";
    esMayorString(cliente->mayor);
    cout<<"\n";
}

void imprimirCola(Cola*cola) {
    Nodo* actual = cola -> inicio;
    if(!isEmpty(cola)) {
        cout<<"Inicio -> ";
        while(actual != NULL) {
            cout<<actual->nombre<<"-> ";
            actual = actual -> siguiente;
        }
        cout<<"NULL";
    } else {
        cout<<"Inicio -> NULL\nFinal -> NULL\n";
    }
}

void iniciar() {
    int opcion;
    Cola* cola = crearCola();
    do {
        imprimirMenu();
        cin>>opcion;
        if(opcion == 1) {
            Nodo* nuevoCliente = crearNodo();
            enquehue(cola, nuevoCliente);
        } else if(opcion == 2) {
            if(!isEmpty(cola)) {
                atender(front(cola));
                dequehue(cola);
            }
        } else if(opcion == 3) {
            if(isEmpty(cola)) {
                cout<<"Cola vacia\n";
            } else {
                cout<<"Hay gente en la cola\n";
            }
        } else if(opcion == 4) {
            imprimirCola(cola);
        } else if(opcion == 5) {
            cout<<"Saliendo\n";
            free(cola);
        } else {
            cout<<"Opcion no valida"<<endl;
        }
    } while(opcion != 5);
}




int main() {

    iniciar();
    return 0;
}