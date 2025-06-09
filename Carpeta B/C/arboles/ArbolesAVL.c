// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    int altura;
    struct Nodo* izq;
    struct Nodo* der;
}Nodo;

Nodo* crearNodo(int valor){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo -> dato = valor;
    nuevoNodo -> izq = NULL;
    nuevoNodo -> der = NULL;
    nuevoNodo ->altura = 1;
    return nuevoNodo;
}

Nodo* insertar(Nodo* raiz, int valor){
    if (raiz == NULL){
        return crearNodo(valor);
    }
    if (valor < raiz->dato){
        raiz->izq = insertar(raiz->izq, valor);
    } else {
        raiz->der = insertar(raiz->der, valor);
    }
    return raiz;
}

void inorden(Nodo* raiz) {
    if(raiz!=NULL){
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}

void preorden(Nodo* raiz){
    if(raiz != NULL) {
        printf("%d ",raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void postorden(Nodo* raiz){
    if(raiz != NULL){
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ",raiz->dato);
    }
}

void liberarArbol(Nodo* raiz){
    if(raiz != NULL) {
        liberarArbol(raiz->izq);
        liberarArbol(raiz->der);
        free(raiz);
    }
}

Nodo* buscar(Nodo* raiz, int valor){
    if(raiz == NULL || raiz->dato == valor){
        return raiz;
    }
    if(valor < raiz->dato){
        return buscar(raiz->izq, valor);
    } else{
        return buscar(raiz->der, valor);
    }
}

int altura(Nodo* nodo){
    if (nodo == NULL){
        return 0;
    } return nodo->altura;
}

int max (int a, int b){
    if (a>b){
        return a;
    }else{
        return b;
    }
}

int comparador (int a, int b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int factorBalance(Nodo* nodo){
    if (nodo == NULL) {
        return 0;
    }
    return altura(nodo->izq) - altura(nodo->der);
}

Nodo* rotarDer(Nodo* y){
    Nodo* x = y->izq;
    Nodo* T2 = x->der;
    
    x->der = y;
    y->izq = T2;
    
    y->altura = max(altura(y->izq), altura(y->der)) +1;
    x->altura = max(altura(y->izq), altura(x->der)) +1;
    return x;
}

Nodo* rotarIzq(Nodo* x) {
    Nodo* y = x->der;
    Nodo*T2 = y->izq;
    
    y->izq = x;
    x->der = T2;
    
    x->altura = max(altura(x->izq), altura(x->der)) +1;
    y->altura = max(altura(y->izq), altura(y->der)) +1;
    return y;
}

Nodo* nuevoInsertar(Nodo* nodo, int valor){
    if (nodo == NULL){
        return nuevoNodo(valor);
    }if (valor < nodo->dato){
        nodo->izq = insertar(nodo->izq,valor);
    }else if (valor > nodo->dato){
        nodo->der = nuevoInsertar(nodo->der, valor);
    }else{
        return nodo;
    }
    
    nodo->altura = 1 + max (altura(nodo->izq), altura(nodo->der));
    
    int balance = factorBalance(nodo);
    
    // RR Rotacion simple a la derecha
    if (balance > 1 && valor < nodo->izq->dato){
        return rotarDer(nodo);
    }
    // LL Rotacion simple a la izquierda
    if (balance < -1 && valor > nodo->der->dato){
        return rotar Izquierda(nodo);
    }
    
    // LR izquierda luego derecha
    if (balance > 1 && valor > nodo->izq->dato) {
        nodo->izq = rotarIzq(nodo->izq);
        return rotadDer(nodo);
    }
    // RL derecha luego izquierda
    if (balance < -1 && valor < nodo->der->dato){
        nodo->der = rotarDer(nodo->der);
        return rotarIzq(nodo);
    }
    return nodo;
}

void menu() {
    printf("\nMenu:\n");
    printf("Seleccione una opcion:\n");
    printf("1- Crear arbol vacio\n");
    printf("2- Insertar valores\n");
    printf("3- Recorrido inorden\n");
    printf("4- Recorrido preorden\n");
    printf("5- Recorrido postorden\n");
    printf("6- Mostrar altura\n");
    printf("7- Mostrar balance\n");
    printf("8- Salir\n");
    printf("Seleccione una opcion:\n");
}

int main() {
    int valor, opcion;
    do{
        menu();
        scanf("%d", &opcion);
    } while(opcion!=8)
    
    /*
    printf("Arbol binario de busqueda\n\n");
    Nodo* raiz = NULL;
    int valor;
    for(int i = 0; i<12; i++){
        printf("Ingrese un valor:\n");
        scanf("%d",&valor);
        raiz = insertar(raiz,valor);
    }
    printf("Raiz: %d\n",raiz->dato);
    if(raiz->izq){
        printf("Hijo izquierdo: %d\n", raiz->izq->dato);
    }
    if(raiz->der){
        printf("Hijo derecho: %d\n", raiz->der->dato);
    }
    printf("Recorrido inorden: ");
    inorden(raiz);
    printf("\n");
    printf("Recorrido preorden: ");
    preorden(raiz);
    printf("\n");
    printf("Recorrido postorden: ");
    postorden(raiz);
    printf("\n");
    liberarArbol(raiz);
    return 0;
    */
}