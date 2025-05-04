#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int numero;
    int *punteroNumero;
    cout<<"Digite un numero para comprobar si es par o impar"<<endl; cin>>numero;
    punteroNumero = &numero;
    if(*punteroNumero %2 ==0){
        cout<<"El numero "<<*punteroNumero<<" es par y la direccion de memoria es: "<<&numero<<endl;
    }else{
        cout<<"El numero "<<*punteroNumero<<" es impar y la direccion de memoria es: "<<&numero<<endl;
    }

}  
//El programa pide un numero al usuario y lo almacena en una variable llamada numero.
// Luego, se crea un puntero llamado punteroNumero que apunta a la dirección de memoria de la variable numero.
// A continuación, se utiliza el puntero para comprobar si el número es par o impar utilizando el operador módulo (%).
// Si el número es par, se imprime un mensaje indicando que es par y se muestra la dirección de memoria de la variable numero utilizando el operador &.
// Si el número es impar, se imprime un mensaje indicando que es impar y se muestra la dirección de memoria de la variable numero.
