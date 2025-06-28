#include <iostream>
using namespace std;

int main(){
    int *punt,i,x[5] = {1, 2, 3, 6, 8};
    punt=&x[0];
    // Imprimir los valores del array usando el puntero
    cout << "Valores del array usando el puntero:" << endl;
    for(i=0; i<5; i++){
        cout << *(punt+i) << endl;
    }
    punt[3] = 18;
    for(i=0; i<5; i++){
        cout << *(punt+i) << endl;
    }
    cout << "Fin" << endl;
    return 0;
}