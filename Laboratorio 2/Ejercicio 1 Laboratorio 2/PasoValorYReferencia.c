#include <stdio.h>
#include <stdlib.h>
//Aplique todo dentro de las funciones, no en el main.
void pasoValorCambio(long int a, long int b);    
void pasoReferenciaCambio(long int *f, long int *g);   
int main(){
    long int a = 20;
    long int b = 30;
    printf("---PASO POR VALOR---\n");
    printf("A = %ld, B = %ld\n", a,b);
    printf("CAMBIO\n");
    pasoValorCambio(a,b);
    printf("A = %ld, B = %ld (Valores fuera de la funcion)\n", a,b);
    printf("---PASO POR REFERENCIA---\n");
    printf("A = %ld, B = %ld\n",a,b);
    printf("CAMBIO\n");
    long int* f = &a;
    long int* g = &b;
    pasoReferenciaCambio(f,g);
    printf("A = %ld, B = %ld (Valores fuera de la funcion)\n", *f,*g);
    return 0;   
}
void pasoValorCambio(long int a, long int b){
    a = 30;
    b = 20;
    printf("A = %ld, B = %ld (Valores dentro de la funcion)\n", a,b);
}

void pasoReferenciaCambio(long int *f, long int *g){
    *f = 30;
    *g = 20;
    printf("A = %ld, B = %ld (Valores dentro de la funcion)\n", *f, *g);
}

//EL CODIGO SE BASA EN EL PASO POR VALOR Y REFERENCIA DE VARIABLES, EN DONDE SE MANIPULAN LOS VALORES DE LAS VARIABLES A TRAVES DE FUNCIONES.
//EN EL PASO POR VALOR, LOS CAMBIOS NO SE REFLEJAN FUERA DE LA FUNCION, MIENTRAS QUE EN EL PASO POR REFERENCIA, LOS CAMBIOS SÍ SE REFLEJAN FUERA DE LA FUNCION.
//EL CODIGO MUESTRA LA DIFERENCIA ENTRE AMBOS EN UN EJEMPLO SENCILLO, DONDE SE CAMBIAN LOS VALORES DE DOS VARIABLES ENTERAS.
//EL PASO POR VALOR SE MANEJA CON COPIAS DE LOS VALORES, MIENTRAS QUE EL PASO POR REFERENCIA SE MANEJA CON PUNTEROS QUE HACEN REFERENCIA A LA DIRECCION DE MEMORIA DE LAS VARIABLES ORIGINALES.
//EL CODIGO ES UNA DEMOSTRACION BASICA DE CÓMO FUNCIONAN ESTOS DOS TIPOS DE PASO DE PARAMETROS EN C.
 







