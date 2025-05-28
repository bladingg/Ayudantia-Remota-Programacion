#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Nodo{
    int ID;
    char* comando;
    struct Nodo* siguiente;
}Nodo;
typedef struct Pila{
    int tam;
    struct Nodo* cima;
}Pila;

void push(Pila* pila, int id, char* comando);
void pop(Pila* pila);
bool isEmpty(Pila* pila);
Pila* crearPila();
void topPila(Pila* pila);
void mostrarPila(Pila* pila);
int main(){
    Pila* pila = crearPila();
    int opcion;
    char* comando;
    do{
        cout<<"Ingrese una opcion: "<<endl;
        cout<<"1. Agregar comando a la pila"<<endl;
        cout<<"2. Eliminar comando de la pila"<<endl;
        cout<<"3. Ver comando en la cima de la pila"<<endl;
        cout<<"4. Mostrar pila"<<endl;
        cout<<"5. Pila vacia?"<<endl;
        cout<<"6. Salir"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:{
                int id;
                comando = (char*)malloc(50*sizeof(char));
                cout<<"Ingrese el ID del comando: ";
                cin>>id;
                cout<<"Ingrese el comando: ";
                cin>>comando;
                push(pila, id, comando);
                break;
            }
            case 2:
                pop(pila);
                break;
            case 3:
                topPila(pila);
                break;
            case 4:{
                mostrarPila(pila);
                break;
            }
            case 5:{
                if(isEmpty(pila)){
                    cout<<"La pila esta vacia"<<endl;
                }else{
                    cout<<"La pila no esta vacia"<<endl;
                }
                break;
            }
            case 6:
                cout<<"Saliendo del programa..."<<endl;
                free(pila);
                break;
        }

    }while(opcion != 6);
}
bool isEmpty(Pila* pila){
    return (pila->tam == 0);
}
Pila* crearPila(){
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->cima = NULL;
    pila->tam = 0;
    return pila;
}
void pop(Pila* pila){
    if(isEmpty(pila)){
        cout<<"La pila esta vacia"<<endl;
    }
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    pila->cima = nodo->siguiente;
    free(nodo->comando);
    free(nodo);
    pila->tam--;
}
void topPila(Pila* pila){
    if(isEmpty(pila)){
        cout<<"La pila esta vacia"<<endl;
    }
    Nodo* cimaActual = pila->cima;
    cout<<"El comando cima de la pila es: "<<cimaActual->comando<<" con el ID: "<<cimaActual->ID<<endl;
}
void push(Pila* pila, int id, char* comando){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->comando = (char*)malloc(50*sizeof(char));
    nodo->comando = comando;
    nodo->ID = id;
    nodo->siguiente= NULL;
    if(pila->cima == NULL){
        nodo->siguiente = NULL;
        pila->cima = nodo;
        pila->tam++;
    }else{
        nodo->siguiente = pila->cima;
        pila->cima = nodo;
        pila->tam++;
    }
    cout<<"Comando agregado exitosamente"<<endl;
}
void mostrarPila(Pila* pila){
    if(isEmpty(pila)){
        cout<<"La pila esta vacia"<<endl;
        return;
    }
    Nodo* actual = pila->cima;
    cout<<"Contenido de la pila:"<<endl;
    while(actual != NULL){
        cout<<"ID: "<<actual->ID<<", Comando: "<<actual->comando<<endl;
        actual = actual->siguiente;
    }
}