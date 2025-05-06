#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
typedef struct Nodo {
    int numeroInscripcion; // Número de inscripción del participante
    char nombre[50];       // Nombre del participante
    struct Nodo *siguiente;
} Nodo;

// Definición de la estructura Lista
typedef struct Lista {
    int tamano; // Tamaño de la lista
    Nodo *head;
} Lista;

// Función para agregar un nuevo participante
void agregarParticipante(Lista *lista, char nombre[50]) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo participante.\n");
        return;
    }
    nuevoNodo->numeroInscripcion = lista->tamano + 1; // Número de inscripción basado en el tamaño
    for (int i = 0; i < 50; i++) {
        nuevoNodo->nombre[i] = nombre[i];
        if (nombre[i] == '\0') { // Detenerse al encontrar el carácter nulo
            break;
        }
    }
    nuevoNodo->siguiente = NULL;

    if (lista->head == NULL) {
        // Lista vacía, agregar al inicio
        lista->head = nuevoNodo;
        printf("Participante agregado al inicio de la lista.\n");
    } else {
        // Agregar al final de la lista
        Nodo *nodoActual = lista->head;
        while (nodoActual->siguiente != NULL) {
            nodoActual = nodoActual->siguiente;
        }
        nodoActual->siguiente = nuevoNodo;
        printf("Participante agregado al final de la lista.\n");
    }

    lista->tamano++;
}
void removerParticipante(Lista *lista, int numeroInscripcion){
    if(lista->head ==NULL){
        printf("La lista esta vacia.\n");
        return;
    }
    Nodo *nodoActual = lista->head;
    Nodo *nodoAnterior = NULL;
    while(nodoActual != NULL){
        if(nodoActual->numeroInscripcion == numeroInscripcion){
            if(nodoAnterior ==NULL){
                lista->head = nodoActual->siguiente;
            }else{
                nodoAnterior->siguiente = nodoActual->siguiente;
            }
            printf("Participante eliminado.\n");
            free(nodoActual);
            lista->tamano--;
            return;
        }
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguiente;

    }
    printf("Participante no encontrado.\n");
}
// Función para mostrar la lista de participantes
void mostrarParticipantes(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo *nodoActual = lista->head;
    printf("Lista de participantes:\n");
    while (nodoActual != NULL) {
        printf("Numero de inscripcion: %d, Nombre: %s\n", nodoActual->numeroInscripcion, nodoActual->nombre);
        nodoActual = nodoActual->siguiente;
    }
}
void buscarParticipante(Lista *lista, int numeroInscripcion) {
    if (lista->head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo *nodoActual = lista->head;
    while (nodoActual != NULL) {
        if (nodoActual->numeroInscripcion == numeroInscripcion) {
            printf("Participante encontrado: Numero de inscripcion: %d, Nombre: %s\n",
                   nodoActual->numeroInscripcion, nodoActual->nombre);
            return;
        }
        nodoActual = nodoActual->siguiente;
    }

    printf("No se encontró un participante con el número de inscripción %d.\n", numeroInscripcion);
}
void consultarParticipantePorOrden(Lista *lista, int orden) {
    if (lista->head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    if (orden < 1 || orden > lista->tamano) {
        printf("El número de orden ingresado es inválido.\n");
        return;
    }

    Nodo *nodoActual = lista->head;
    for (int i = 1; i < orden; i++) {
        nodoActual = nodoActual->siguiente;
    }

    printf("Participante en el numero de orden %d: Numero de inscripcion: %d, Nombre: %s\n",
           orden, nodoActual->numeroInscripcion, nodoActual->nombre);
}

// Función principal
int main() {
    Lista lista;
    lista.tamano = 0;
    lista.head = NULL;
    int opcion;
do {
    printf("\nMenu de gestion de participantes:\n");
    printf("1. Agregar participante\n");
    printf("2. Mostrar lista de participantes\n");
    printf("3. Remover participante\n");
    printf("4. Buscar participante por numero de inscripcion\n");
    printf("5. Consultar participante por numero de orden\n");
    printf("6. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1: {
            char nombre[50];
            printf("Ingrese el nombre del participante: ");
            scanf(" %[^\n]", nombre); // Leer cadena con espacios
            agregarParticipante(&lista, nombre);
            break;
        }
        case 2:
            mostrarParticipantes(&lista);
            break;
        case 3: {
            int numeroInscripcion;
            printf("Ingrese el numero de inscripcion del participante a eliminar: ");
            scanf("%d", &numeroInscripcion);
            removerParticipante(&lista, numeroInscripcion);
            break;
        }
        case 4:{
            int numeroInscripcion;
            printf("Ingrese el numero de inscripción del participante a buscar: ");
            scanf("%d", &numeroInscripcion);
            buscarParticipante(&lista, numeroInscripcion);
            break;
        }
        case 5:{
            int orden;
            printf("Ingrese el número de orden del participante a consultar: ");
            scanf("%d", &orden);
            consultarParticipantePorOrden(&lista, orden);
            break;
        }
        case 6:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
    return 0;
}