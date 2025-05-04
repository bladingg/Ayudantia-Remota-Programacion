#include <iostream>
using namespace std;

int main(){
    int suma = 0, resta = 0, multiplicacion = 0, division = 0;
    int digito1, digito2;
    cout<<"Digite el primer numero"<<endl;
    cin>>digito1;
    cout<<"Digite el segundo numero"<<endl;
    cin>>digito2;

    //OPERACIONES
    suma = digito1+digito2;
    resta = digito1-digito2;
    multiplicacion = digito1*digito2;
    division = digito1/digito2;

    cout<<"--RESULTADOS--"<<endl;
    cout<<"SUMA = "<<suma<<"\n"<<"RESTA = "<<resta<<"\n"<<"MULTIPLICACION = "<<multiplicacion<<"\n"<<"DIVISION = "<<division;
    

}
