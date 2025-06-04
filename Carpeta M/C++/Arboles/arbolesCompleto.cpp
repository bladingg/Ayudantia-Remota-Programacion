#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Nodo{
    int valor;
    struct Nodo* izq;
    struct Nodo* der;   
}Nodo;

Nodo* crear_nodo ();
Nodo* insertar(Nodo* raiz, int valor);
void inorden(Nodo* raiz);
void preorden(Nodo* raiz);
void postorden(Nodo* raiz);
bool busqueda(Nodo* arbol, int valor);
Nodo* eliminar(Nodo* raiz, int valor);
int profundidad(Nodo* raiz, int valor, int nivel);
Nodo* minimo(Nodo* nodo);

int main(){
    Nodo* raiz = NULL;
    int opcion;
    int valor, i;
    cout << "Ingrese 12 valores enteros:\n";
    for(i = 0; i < 12; i++){
        cout << "Valor " << (i+1) << ": ";
        cin >> valor;
        raiz = insertar(raiz, valor);
        }
    do{
        cout << "\n--- MENU ---\n";
        cout << "1. Mostrar los valores en recorrido Inorden" << endl;
        cout << "2. Mostrar los valores en recorrido Preorden"<< endl;
        cout << "3. Mostrar los valores en recorrido Postorden" << endl;
        cout << "4. Buscar si existe un elemento en especifico" << endl;
        cout << "5. Eliminar un elemento en especifico"<< endl;
        cout << "6. Buscar la profundidad de un elemento"<<endl;
        cout << "7. Insertar un nuevo elemento"<<endl;
        cout << "8. Salir"<< endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion){

            case 1:
                cout << "Recorrido Inorden: ";
                inorden(raiz);
                cout << endl;
                break;
            case 2:
                cout << "Recorrido Preorden: "<< endl;
                preorden(raiz);
                cout << endl;
                break;
            case 3:
                cout << "Recorrido Postorden: "<< endl;
                postorden(raiz);
                cout << endl;
                break;
            case 4:
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                if(busqueda(raiz, valor))
                    cout << "El valor SI existe en el arbol."<<endl;
                else
                    cout << "El valor NO existe en el arbol."<<endl;
                break;
            case 5:
                cout << "Ingrese el valor a eliminar: ";
                cin >> valor;
                raiz = eliminar(raiz, valor);
                cout << "Elemento eliminado (si existia)."<<endl;
                break;
            case 6:
                cout << "Ingrese el valor para buscar su profundidad: ";
                cin >> valor;
                {
                    int prof = profundidad(raiz, valor, 0);
                    if(prof != -1)
                        cout << "La profundidad del elemento es: " << prof << endl;
                    else
                        cout << "El elemento no existe en el arbol."<<endl;
                }
                break;
            case 7:
                cout<<"Inserte un nuevo valor: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                cout << "Valor insertado correctamente."<<endl;
                break;
            case 8:
                cout << "Saliendo..."<<endl;
                break;
            default:
                cout << "Opcion invalida."<<endl;
        }
    }while (opcion != 8);
    return 0;
}
Nodo* minimo(Nodo* nodo){
    while (nodo && nodo->izq != NULL)
        nodo = nodo->izq;
    return nodo;
}
bool busqueda(Nodo* arbol, int n){

    if (arbol == NULL){
        return false;
    }
    else if(arbol->valor ==n){
        return true;
    }
    else if(n< arbol->valor){
        return busqueda (arbol->izq, n);
    }else{
        return busqueda(arbol->der , n);
    }
}
int profundidad(Nodo* raiz, int valor, int nivel){
    if (raiz== NULL)
        return -1;
    if (raiz->valor == valor)
        return nivel;
    int izq = profundidad (raiz->izq, valor, nivel +1);
    if (izq != -1)
        return izq;
    return profundidad (raiz->der, valor, nivel + 1);
}
Nodo* eliminar (Nodo* raiz, int valor){
    if (raiz == NULL) return NULL;
    if (valor < raiz->valor)
        raiz->izq = eliminar(raiz->izq, valor);
    else if(valor > raiz->valor)
        raiz->der = eliminar(raiz->der, valor);
    else{
        if (raiz->izq == NULL){
            Nodo* temp = raiz->der;
            free(raiz);
            return temp;
        }else if(raiz->der ==NULL){
            Nodo* temp = raiz->izq;
            free(raiz);
            return temp;
        }
        Nodo* temp = minimo(raiz->der);
        raiz->valor = temp->valor;
        raiz->der = eliminar(raiz->der, temp->valor);
    }
    return raiz;
}
void inorden(Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->valor);
        inorden(raiz->der);
    }
}
void preorden(Nodo* raiz) {
    if (raiz != NULL) {
       	cout<<raiz->valor<<endl;			   	
        preorden(raiz->izq);
        preorden(raiz->der); 
    }
}
void postorden(Nodo* raiz) {
    if (raiz != NULL) {
        postorden(raiz->izq);
	   	postorden(raiz->der);
		cout<<raiz->valor<<endl;
	}
}
Nodo* crear_nodo(int valor){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo-> valor = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}
Nodo* insertar(Nodo* raiz, int valor){
    if(raiz == NULL){
        return crear_nodo(valor);
    }
    if (valor<raiz->valor){
        raiz->izq = insertar(raiz->izq, valor);
    }else{
        raiz->der = insertar(raiz->der, valor);
    }
    return raiz;
}