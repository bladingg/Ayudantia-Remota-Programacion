#include <iostream>
#include <stdlib.h>

typedef struct Nodo {
    int id;
    struct Nodo* siguiente;
} Nodo;

typedef struct Cola {
    Nodo* principio;
    Nodo* final;
    int tam;
    int estudiantesEvaluados;
} Cola;

using namespace std;

void iniciar();
Nodo* crearNodo(Cola* cola);
Cola* crearCola();
void rendirExamen(Cola* cola);
void verificarAlumnos(bool estaVacio, Cola* cola);
void enquehue(Cola* cola);
void dequehue(Cola* cola);
Nodo* front(Cola* cola);
bool isEmpty(Cola* cola);
void rendirExamen(Cola* cola);
void imprimirMenu();
void imprimirColas(Cola* cola);

int main() {
    
    iniciar();

    return 0;
}

void iniciar() {
    Cola* cola = crearCola();
    int opcion;
    while(opcion != 6) {
        imprimirMenu();
        cin>>opcion;
        if(opcion == 1) {
            enquehue(cola);
        } else if(opcion == 2) {
            rendirExamen(cola);
        } else if(opcion == 3) {
            dequehue(cola);
        }else if(opcion == 4) {
            verificarAlumnos(isEmpty(cola), cola);
        }  else if(opcion == 5) {
            imprimirColas(cola);
        } else if(opcion == 6) {
            cout<<"Saliendo del programa..."<<endl;
        } else {
            cout<<"Opcion no valida\n"<<endl;
        }
    }
}

Cola* crearCola() {
    Cola* cola = (Cola*) malloc(sizeof(Cola));
    cola -> tam = 0;
    cola -> principio = NULL;
    cola -> final = NULL;
    return cola;
}

void verificarAlumnos(bool estaVacio, Cola* cola) {
    if(isEmpty(cola)) {
        cout<<"No quedan estudiantes en la cola\n";
    } else {
        cout<<"Aun quedan estudiantes en la cola\n";
    }
}

Nodo* crearNodo(Cola* cola) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo-> siguiente = NULL;
    cout<<"Ingrese id del estudiante: ";
    cin>>nuevoNodo->id;
    return nuevoNodo;
}

void enquehue(Cola* cola) {
    Nodo* nuevoNodo = crearNodo(cola);
    if(cola -> tam == 0) {
        cola -> principio = nuevoNodo;
        cola -> final = nuevoNodo;
        cola -> tam += 1;
        cout<<"Estudiante agregado a la cola\n";
    } else {
        cola -> final -> siguiente = nuevoNodo;
        cola -> final = nuevoNodo;
        cola -> tam += 1;
        cout<<"Estudiante agregado a la cola\n";
    }
}

void dequehue(Cola* cola) {
    Nodo* primerNodo = front(cola);
    if(cola -> tam == 1) {
        cout<<"Se ha eliminado al estudiante: "<<primerNodo->id<<"\n";
        free(primerNodo);
        cola -> principio = NULL;
        cola -> final = NULL;
        cola -> tam -= 1;

    } else if(cola -> tam > 1) {
        cout<<"Se ha eliminado al estudiante: "<<primerNodo->id<<"\n";
        cola -> principio = primerNodo -> siguiente;
        cola -> tam -= 1;
        free(primerNodo);
    }
}

Nodo* front(Cola* cola) {
    return cola -> principio;
}

bool isEmpty(Cola* cola) {
    return cola -> tam == 0;
}

void rendirExamen(Cola* cola) {
    Nodo* primerEstudiante = front(cola);
    cout<<"\n--- Estudiante en prueba ---\nid: "<<primerEstudiante->id<<"\n";
}

void imprimirMenu() {
    cout<<"\n1. Agregar alumno a la cola"<<endl;
    cout<<"2. Rendir examen oral"<<endl;
    cout<<"3. Eliminar alumno de la cola"<<endl;
    cout<<"4. Verificar si quedan estudiantes"<<endl;
    cout<<"5. Imprimir cola"<<endl;
    cout<<"6. Salir"<<endl;
    cout<<"Ingrese una opcion: ";
}

void imprimirColas(Cola* cola) {
    Nodo* actual = cola -> principio;
    if(cola -> tam == 0) {
        cout<<"inicio -> NULL\nfinal -> NULL"<<endl;
    } else {
        cout<<"inicio -> ";
        while(actual != NULL) {
            cout<<actual->id<<" -> ";
            actual = actual -> siguiente;
        }
        cout<<"NULL"<<endl;
    }

}