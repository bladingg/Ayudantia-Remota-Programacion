#include <iostream>
#include <string>
using namespace std;
struct Producto{
    string nombre;
    int precio;
    int cantidad;
};

int main(){
    int precioP, cantidadP, total= 0;
    Producto productos[3];
    cout<<"Ingrese 3 productos"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Producto "<<i+1<<endl;
        cout<<"Nombre: ";
        cin>>productos[i].nombre;
        cout<<"Precio del producto: ";
        cin>>productos[i].precio;
        precioP = productos[i].precio;
        cout<<"Cantidad de los productos: ";
        cin>>productos[i].cantidad;
        cantidadP = productos[i].cantidad;
        total = total + cantidadP * precioP;
    }
    cout<<"Total a pagar: "<<total<<endl;
    return 0;
}
//Este ejercicio consiste en ingresar 3 productos, su precio y cantidad por pantalla.
//Luego se calcula el total a pagar multiplicando la cantidad por el precio de cada producto.
//Finalmente se imprime el total a pagar por pantalla.
//El resultado es correcto y se imprime el total a pagar por pantalla.




