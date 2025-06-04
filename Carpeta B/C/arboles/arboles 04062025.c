// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu() {
    printf("\nMenu:\n");
    printf("Seleccione una opcion:\n");
    printf("1- Insertar 12 valores\n");
    printf("2- Buscar valor\n");
    printf("3- Recorrido inorden\n");
    printf("4- Recorrido preorden\n");
    printf("5- Recorrido postorden\n");
    printf("6- Mostrar minimo\n");
    printf("7- Eliminar valor\n");
    printf("8- Salir\n");
}

typedef struct Nodo {
    int dato;
    struct Nodo* izq;
    struct Nodo* der;
} Nodo;

Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }
    if (valor < raiz->dato) {
        raiz->izq = insertar(raiz->izq, valor);
    } else {
        raiz->der = insertar(raiz->der, valor);
    }
    return raiz;
}

void inorden(Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izq);
        printf("%d ", raiz->dato);
        inorden(raiz->der);
    }
}

void preorden(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void postorden(Nodo* raiz) {
    if (raiz != NULL) {
        postorden(raiz->izq);
        postorden(raiz->der);
        printf("%d ", raiz->dato);
    }
}

void liberarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izq);
        liberarArbol(raiz->der);
        free(raiz);
    }
}

Nodo* buscar(Nodo* raiz, int valor) {
    if (raiz == NULL || raiz->dato == valor) {
        return raiz;
    }
    if (valor < raiz->dato) {
        return buscar(raiz->izq, valor);
    } else {
        return buscar(raiz->der, valor);
    }
}

Nodo* minimo(Nodo* nodo) {
    while (nodo != NULL && nodo->izq != NULL)
        nodo = nodo->izq;
    return nodo;
}

Nodo* eliminar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    if (valor < raiz->dato) {
        raiz->izq = eliminar(raiz->izq, valor);
    } else if (valor > raiz->dato) {
        raiz->der = eliminar(raiz->der, valor);
    } else {
        // Caso 1: Nodo sin hijos
        if (raiz->izq == NULL && raiz->der == NULL) {
            free(raiz);
            return NULL;
        }
        // Caso 2: Nodo con un solo hijo
        else if (raiz->izq == NULL) {
            Nodo* temp = raiz->der;
            free(raiz);
            return temp;
        } else if (raiz->der == NULL) {
            Nodo* temp = raiz->izq;
            free(raiz);
            return temp;
        }
        // Caso 3: Nodo con dos hijos
        Nodo* temp = minimo(raiz->der);
        raiz->dato = temp->dato;
        raiz->der = eliminar(raiz->der, temp->dato);
    }
    return raiz;
}

bool busqueda(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    } else if (arbol->dato == n) {
        return true;
    } else if (n < arbol->dato) {
        return busqueda(arbol->izq, n);
    } else {
        return busqueda(arbol->der, n);
    }
}


int main() {
    printf("Arbol binario de busqueda\n\n");
    Nodo* raiz = NULL;
    int valor, opcion;
    Nodo* encontrado;
    int insertados = 0;

    do {
        menu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (insertados == 0) {
                    for (int i = 0; i < 12; i++) {
                        printf("Ingrese un valor:\n");
                        scanf("%d", &valor);
                        raiz = insertar(raiz, valor);
                    }
                    insertados = 1;
                    printf("12 valores insertados.\n");
                } else {
                    printf("Ya se han insertado los 12 valores.\n");
                }
                break;
            case 2:
                if (insertados == 0) {
                    printf("Primero debe insertar los 12 valores.\n");
                } else {
                    printf("Ingrese el valor a buscar: ");
                    scanf("%d", &valor);
                    if (busqueda(raiz, valor)) {
                        printf("Valor %d encontrado en el árbol.\n", valor);
                    } else {
                        printf("Valor %d no encontrado.\n", valor);
                    }
                }
                break;

            case 3:
                if (insertados == 0) {
                    printf("Primero debe insertar los 12 valores.\n");
                } else {
                    printf("Recorrido inorden: ");
                    inorden(raiz);
                    printf("\n");
                }
                break;
            case 4:
                if (insertados == 0) {
                    printf("Primero debe insertar los 12 valores.\n");
                } else {
                    printf("Recorrido preorden: ");
                    preorden(raiz);
                    printf("\n");
                }
                break;
            case 5:
                if (insertados == 0) {
                    printf("Primero debe insertar los 12 valores.\n");
                } else {
                    printf("Recorrido postorden: ");
                    postorden(raiz);
                    printf("\n");
                }
                break;
            case 6:
                if (insertados == 0) {
                    printf("Primero debe insertar los 12 valores.\n");
                } else {
                    Nodo* min = minimo(raiz);
                    if (min != NULL)
                        printf("El valor minimo es: %d\n", min->dato);
                    else
                        printf("El arbol esta vacio.\n");
                }
                break;
            case 7:
                if (insertados == 0) {
                    printf("Primero debe insertar los 12 valores.\n");
                } else {
                    printf("Ingrese el valor a eliminar: ");
                    scanf("%d", &valor);
                    raiz = eliminar(raiz, valor);
                    printf("Valor %d eliminado del arbol.\n", valor);
                }
                break;
            case 8:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 8);

    liberarArbol(raiz);
    return 0;
}