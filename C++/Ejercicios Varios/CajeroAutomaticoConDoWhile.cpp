#include <iostream>
using namespace std;

int main(){
    int saldoInicial = 500;
    int opcion;
    int deposito;
    int retiro;
    do{
        cout<<"Bienvenido al Cajero Automatico, que operacion desea realizar"<<endl;
        cout<<"1. Depositar saldo"<<endl;
        cout<<"2. Retirar saldo"<<endl;
        cout<<"3. Ver su saldo actual"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"Digite el saldo a depositar"<<endl;
                cin>>deposito;
                saldoInicial = saldoInicial + deposito;
                break;
            case 2:
                cout<<"Digite el saldo a retirar"<<endl;
                cin>>retiro;
                if(retiro>saldoInicial){
                    cout<<"ERROR!! El saldo a retirar es mayor al monto de su cuenta"<<endl;
                    cout<<"Su saldo actual es de: "<<saldoInicial<<endl;
                }else{
                    saldoInicial = saldoInicial-retiro;
                }
                break;
            case 3:
                cout<<"Su saldo actual es de: "<<saldoInicial<<endl;
                break;
            case 4:
                cout<<"Finalizando el programa..."<<endl;
                break;
            default:
                cout<<"Opcion invalida, intente nuevamente"<<endl;
                break;
        }
    }while(opcion!=4);
    return 0;
}
//El programa es un cajero automatico, el cual permite al usuario depositar, retirar y ver su saldo actual.
// El programa utiliza un bucle do-while para permitir al usuario realizar varias operaciones hasta que decida salir.
// El saldo inicial se establece en 500 y se actualiza después de cada operación de depósito o retiro.