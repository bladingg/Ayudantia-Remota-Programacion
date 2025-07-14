#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Nodo{
    char* estudiante;
    int edad;
    int ano;
    struct Nodo* siguiente;
}Nodo;

typedef struct Lista{
    int tam;
    Nodo* cabeza;
}Lista;

Lista* crearLista();
void agregarEstudiantes(char* estudiante, int edad, int ano, Lista* lista);
Nodo* buscarEstudiante(Lista* lista, char* estudianteBuscado);
void mostrarEstudiantes(Lista* lista);
int main(){
    int opcion;
    char* nombre;
    int edad;
    int ano;
    char* estudianteBuscar;
    Lista* lista = crearLista();
    do{
        cout<<endl;
        cout<<"1. Agregar estudiante"<<endl;
        cout<<"2. Buscar estudiante"<<endl;
        cout<<"3. Mostrar lista de estudiantes"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                nombre = (char*)malloc(50*sizeof(char));
                cout<<"Digite el nombre del estudiante para agregar"<<endl;
                cin>>nombre;
                cout<<"Digite la edad del estudiante"<<endl;
                cin>>edad;
                cout<<"Digite el ano de ingreso del estudiante"<<endl;
                cin>>ano;
                agregarEstudiantes(nombre,edad,ano,lista);
                break;
                }
            case 2: {
                estudianteBuscar = (char*)malloc(50*sizeof(char));
                cout<<"Digite el estudiante a buscar"<<endl;
                cin>>estudianteBuscar;
                Nodo* estudianteBusc = buscarEstudiante(lista, estudianteBuscar);
                if (estudianteBusc != NULL){
                    cout<<"El estudiante se encontro CONCHETUMARE"<<estudianteBusc->estudiante<<endl;
                    }else{
                        cout<<"El aweonao no existe"<<endl;
                    }
                    break;   
                }
            case 3:{
                cout<<"Lista de estudiantes"<<endl;
                mostrarEstudiantes(lista);
                break;  
                }
            case 4:{
                cout<<"Saliendo del programa"<<endl;
                break;
                
            }
        }
    }while(opcion != 4);
    return 0;
}

Lista* crearLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->tam = 0;
    lista->cabeza = NULL;
    return lista;
}
Nodo* buscarEstudiante(Lista* lista, char* estudianteBuscado){
    Nodo* estudianteActual = lista->cabeza;
    while(estudianteActual != NULL){
        if(estudianteActual->estudiante == estudianteBuscado){
            break;
        }else{
            estudianteActual = estudianteActual->siguiente;
        }
        
    }
    return estudianteActual;

}
void agregarEstudiantes(char* estudiante, int edad, int ano, Lista* lista){
    Nodo* estudianteNuevo = (Nodo*)malloc(sizeof(Nodo));
    estudianteNuevo->estudiante = (char*)malloc(50*sizeof(char));

    estudianteNuevo->estudiante = estudiante;
    estudianteNuevo->edad = edad;
    estudianteNuevo->ano = ano;
    estudianteNuevo ->siguiente = NULL;

    if(lista->cabeza == NULL){
        lista->cabeza = estudianteNuevo;
    }else{
        Nodo* actual = lista->cabeza;
        while(actual->siguiente != NULL){
            actual = actual->siguiente;

        }
        actual->siguiente=estudianteNuevo;
    }
    lista->tam = lista->tam + 1;

}
void mostrarEstudiantes(Lista* lista){
    Nodo* actual = lista->cabeza;
    while(actual !=NULL){
        cout<<actual->estudiante;
        cout<<actual->edad;
        cout<<actual->ano;
        actual = actual->siguiente;
    }
}
