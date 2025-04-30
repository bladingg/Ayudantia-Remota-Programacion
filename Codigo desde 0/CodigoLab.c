#include <stdio.h> // Libreria para entrada/salida
#include <stdlib.h> // Libreria para funciones de memoria dinamica
typedef struct Nodo{ // Definicion de la estructura Nodo donde se guardara el valor y el puntero al siguiente nodo.
    int valor; 
    struct Nodo *siguiente;
}Nodo;
typedef struct Lista{ // Definicion de la estructura Lista donde se guardara el puntero al primer nodo y el tamaño de la lista.
    int tamaño;
    Nodo *head;
}Lista;

void agregarNodo(Lista* lista, int valor, int posicion) { // Funcion para agregar un nodo a la lista donde se le pasa la lista, el valor y la posicion donde se desea agregar el nodo.
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    if (posicion < 1){
        printf("La posicion ingresada es invalida, porfavor intente denuevo\n");
        free(nuevoNodo); // Liberar la memoria del nodo si no se va a usar
        return;
    }
    if (lista->head == NULL) {
        nuevoNodo->siguiente = lista->head;
        lista->head = nuevoNodo;
        printf("Nodo agregado al inicio de la lista, ya que su lista se encuentra vacia\n");
    }else {
        Nodo* nodoActual = lista->head;
        int indice = 1;

        while (nodoActual->siguiente != NULL && indice < posicion - 1) {
            nodoActual = nodoActual->siguiente;
            indice++;
        }

        // Insertar el nodo en la posición deseada
        nuevoNodo->siguiente = nodoActual->siguiente;
        nodoActual->siguiente = nuevoNodo;
        if (indice < posicion - 1) {
            printf("Nodo agregado al final de la lista, ya que el tamano ingresado excede la capacidad\n");
        } else {
            printf("Nodo agregado en la posicion %d\n", posicion);
        }
        
    }
    // Incrementar el tamaño de la lista
    lista->tamaño++;
}
Nodo* buscarNodo(Lista* lista, int valorBuscado){ // Funcion para buscar un nodo en la lista donde se le pasa la lista y el valor a buscar.
    if (lista->head == NULL) {
        printf("La lista esta vacia\n");
        return NULL;
    }
    Nodo* nodoActual = lista->head;
    while(nodoActual !=NULL){
        if(nodoActual->valor == valorBuscado){
            break;
        }else{
            //Mover el puntero al siguiente nodo
            nodoActual = nodoActual->siguiente;
        }
    }
    return nodoActual;
}
Nodo* obtenerIndice(Lista *lista, int indice){
    Nodo* nodoActual = lista->head;
    int ultimoIndice = lista->tamaño;
    int i;
    for(i = 0; i<ultimoIndice; i= i+1){
        if(i == indice){
            break;
        }else{
            nodoActual = nodoActual->siguiente;
        }     
    }
    return nodoActual;
}
Nodo* eliminarNodo(Lista* lista, int valorEliminar){
    Nodo* nodoActual = lista->head;
    Nodo* nodoAnterior = NULL;
    while(nodoActual != NULL){
        if(nodoActual->valor == valorEliminar){
            if(nodoAnterior == NULL){
                lista->head = nodoActual->siguiente;
            }else{
                nodoAnterior->siguiente = nodoActual->siguiente;

            }
            printf("Nodo con valor %d eliminado\n", valorEliminar);
            free(nodoActual);
            lista->tamaño--;
            return lista->head;
        }
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguiente;
    }
    printf("El nodo con valor %d no se encontro en la lista\n", valorEliminar);
    return NULL; 
}
int main() {
    Lista lista;
    lista.tamaño = 0;
    lista.head = NULL;
    int opcion;
    do{
        printf("Bienvenido a su menu interactivo, que operacion desea realizar\n");
        printf("1. Agregar nodo\n");
        printf("2. Buscar nodo\n");
        printf("3. Obtener indice de un nodo\n");
        printf("4. Eliminar nodo\n");
        printf("5. Mostrar lista\n");
        printf("6. Salir\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:{
                int valor, posicion;
                printf("Ingrese el valor del nodo: ");
                scanf("%d", &valor);
                printf("Las posiciones a agregar empiezan desde el numero 1\n");
                printf("Ingrese la posicion donde desea agregar el nodo: ");
                scanf("%d", &posicion);
                agregarNodo(&lista, valor, posicion);
                break;
            }
            case 2:
            {
                int valorBuscado;
                printf("Ingrese el valor del nodo a buscar: ");
                scanf("%d", &valorBuscado);
                Nodo* nodoEncontrado = buscarNodo(&lista, valorBuscado);
                if (nodoEncontrado != NULL) {
                    printf("Nodo encontrado con valor: %d\n", nodoEncontrado->valor);
                } else {
                    printf("Nodo no encontrado\n");
                }
                break;
            }
            case 3:{
                int indice;
                printf("Ingrese el indice del nodo a obtener: ");
                scanf("%d", &indice);
                if(indice < 0 || indice >= lista.tamaño){
                    printf("El indice ingresado es invalido, porfavor intente de nuevo\n");
                }else{
                    Nodo* nodoEncontrado = obtenerIndice(&lista, indice);
                    if (nodoEncontrado != NULL) {
                        printf("Nodo encontrado en el indice %d con valor: %d\n", indice, nodoEncontrado->valor);
                    } else {
                        printf("Nodo no encontrado\n");
                    }
                }
                break;
            case 4:{
                int valorEliminar;
                printf("Ingrese el valor del nodo a eliminar: ");
                scanf("%d", &valorEliminar);
                eliminarNodo(&lista, valorEliminar);
                break;
            }
            case 5:{
                Nodo* nodoActual = lista.head;
                printf("Lista: ");
                while (nodoActual != NULL) {
                    printf("%d --> ", nodoActual->valor);
                    nodoActual = nodoActual->siguiente;
                }
                printf("NULL\n");
                break;
            }
            case 6:{
                printf("Saliendo del programa...\n");
                break;
            }
            default:{
                printf("Opcion no valida. Intente de nuevo.\n");
            }
        }
    }
    }while(opcion !=6);
}
