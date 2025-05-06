#include <iostream>
using namespace std;
int main(){
    int array1[5], array2[5];
    int *puntero1 = array1;
    int *puntero2 = array2;
    int sumaArreglo1 = 0, sumaArreglo2 = 0;
    float promedio1,promedio2;
    cout<< "Ingresar 10 numeros enteros:" << endl;
    for(int i=0;i<5;i++){
        cout<<"Primer arreglo:" <<endl;
        cout<<"Numero "<<i+1<<": ";
        cin>> *(puntero1+i);
    }
    for(int i=0;i<5;i++){
        cout<<"Segundo arreglo:"<<endl;
        cout<<"Numero "<<i+1<<": ";
        cin>> *(puntero2+i);
    }
    for (int i=0;i<5;i++){
        sumaArreglo1 = sumaArreglo1 + *(puntero1+i); 
    }
    promedio1 = sumaArreglo1/5.0;
    for(int i=0; i<5; i++){
        sumaArreglo2 = sumaArreglo2 + *(puntero2+i);
    }
    promedio2 = sumaArreglo2/5.0;

    cout<<"La suma total de los arreglos es: "<<sumaArreglo1+sumaArreglo2<<endl;
    cout<<"El promedio del arreglo 1 es de: "<<promedio1<<endl;
    cout<<"El promedio del arreglo 2 es de: "<<promedio2<<endl;
    return 0;
}

//Este ejercicio consite en ingresar 10 numeros enteros por pantalla, 5 para cada arreglo.
//Luego se suman los dos arreglos y se imprime la suma total y el promedio de cada arreglo por separado.
//Se utiliza punteros para acceder a los elementos de los arreglos y se imprime el resultado por pantalla.
//El resultado es correcto y se imprime la suma total y el promedio de cada arreglo por separado.
