// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo* izq;
    struct Nodo* der;
}Nodo;

Nodo* crearNodo(int valor){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo -> dato = valor;
    nuevoNodo -> izq = NULL;
    nuevoNodo -> der = NULL;
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

int main() {
    // Write C code here
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
}