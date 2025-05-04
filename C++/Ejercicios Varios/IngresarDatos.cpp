#include <iostream>
using namespace std;
//Programa para ingresar datos dentro de main, se implementara datos de un auto.
int main(){
    char modelo[20]; //[20] ES PARA QUE EL USUARIO TENGA ESE LIMITE DE CARACTERES.
    int ano;
    char patente[5]; //EL [5] ES PARA QUE EL USUARIO TENGA ESE LIMITE DE CARACTERES. 

    cout<<"Digite el modelo del auto: "<<endl; cin>>modelo;
    cout<<"Digite el ano del auto"<<endl; cin>>ano;
    cout<<"Digite la patente del auto"<<endl; cin>>patente;
    cout<<"------RESULTADOS------"<<endl;
    cout<<"MODELO = "<<modelo<<"\n"<<"ANO = "<<ano<<"\n"<<"PATENTE = "<<patente;
}
