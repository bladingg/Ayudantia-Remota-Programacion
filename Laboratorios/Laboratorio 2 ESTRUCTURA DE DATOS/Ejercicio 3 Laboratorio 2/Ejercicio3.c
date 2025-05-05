#include <stdio.h>
#include <stdlib.h>

int main(){
    int numerosIngresar, *numeros, par = 0, impar = 0, suma = 0;
    do{
        printf("Ingrese la cantidad de numeros (No ingrese >=0, o igualmente >100)\n");
        scanf("%d", &numerosIngresar);
        if(numerosIngresar <=0 || numerosIngresar>100){
            printf("Cantidad invalida\n");
        }

    }while (numerosIngresar<=0 || numerosIngresar>100);

    numeros = (int *)malloc(numerosIngresar * sizeof(int));
    if (numeros ==NULL){
        printf("Error\n");
        return 1;
    }

    printf("Ingrese los %d numeros:\n",numerosIngresar);
    for (int i = 0; i<numerosIngresar;i++){
        printf("Numero %d: ", i+1);
        scanf("%d",&numeros[i]);
        suma = suma + numeros[i];
        if(numeros[i] % 2 == 0){
            par++;
        }else{
            impar++;
        }
    }

    printf("La suma total de los numeros es de: %d\n", suma);
    printf("La cantidad de numeros pares es de: %d\n", par);
    printf("La cantidad de numeros impares es de: %d\n",impar);
    free(numeros);
    return 0;
}