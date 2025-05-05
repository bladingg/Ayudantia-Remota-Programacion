#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;    
void crearContacto();
void agregarContacto();
void eliminarContacto();
void verContacto();

struct contacto{
    string nombre, apellido, telefono;
}datosTelefonicos;

int main(){
    int opcion;
    do{
        cout<<"Bienvenido a su sistema de contactos, digite el numero que desea realizar."<<endl;
        cout<<"1. Crear contactos"<<endl;
        cout<<"2. Agregar contactos"<<endl;
        cout<<"3. Eliminar contactos"<<endl;
        cout<<"4. Ver sus contactos"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                crearContacto();
                cout<<"\n";
                
                break;
            case 2:
                agregarContacto();
                cout<<"\n";
               
                break;
            case 3: 
                eliminarContacto();
                cout<<"\n";
                
                break;
            case 4:
                verContacto();
                cout<<"\n";
                break;
            case 5:   
                break;
        }
        cout<<"Gracias por usar nuestro sistema"<<endl;
        

    }while (opcion !=5);
    return 0;
}
void crearContacto(){
    ofstream archivo;
    char respuesta;
    archivo.open("AgendaTelefonica.txt",ios::out);
    if (archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    cout<<"\tAgenda telefonica.txt\n\n";
    do{
        fflush(stdin);
        cout<<"Digite su nombre: "<<endl;
        getline(cin,datosTelefonicos.nombre);
        cout<<"Digite su apellido: "<<endl;
        getline(cin,datosTelefonicos.apellido);
        cout<<"Digite su numero telefonico"<<endl;
        getline(cin,datosTelefonicos.telefono);
        archivo<<"Nombre: "<<datosTelefonicos.nombre<<endl;
        archivo<<"Apellido: "<<datosTelefonicos.apellido<<endl;
        archivo<<"Numero telefonico: "<<datosTelefonicos.telefono<<endl;
        cout<<"\n";
        cout<<"Desea agregar otro contacto?";
        cout<<"(S/N)"<<endl;
        cin>>respuesta;

    }while ((respuesta == 'S') || (respuesta == 's'));
    archivo.close();
}

void eliminarContacto(){
    string linea, nombre, apellido, telefono;
    ifstream archivo("AgendaTelefonica.txt");
    ofstream archivoTemporal("temporal.txt", ios::app);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    cout<<"Digite el nombre del contacto que desea eliminar: "<<endl;
    cin>>nombre;
    cout<<"Digite el apellido del contacto que desea eliminar: "<<endl;
    cin>>apellido;
    cout<<"Digite el telefono del contacto que desea eliminar: "<<endl;
    cin>>telefono;

    while(getline(archivo, linea)){
        if(linea.find(nombre) == string::npos && linea.find(apellido) == string::npos && linea.find(telefono) == string::npos){
            archivoTemporal<<linea<<endl;

        }
    }
    archivo.close();
    archivoTemporal.close();
    remove("AgendaTelefonica.txt");
    rename("temporal.txt", "AgendaTelefonica.txt");
    cout<<"Contacto eliminado correctamente"<<endl;
}
void agregarContacto(){
    ofstream archivo;
    char respuesta;
    archivo.open("AgendaTelefonica.txt",ios::app);
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    do{
        fflush(stdin);
        cout<<"\n";
        cout<<"Nombre: "; getline(cin, datosTelefonicos.nombre);
        cout<<"Apellido: "; getline(cin, datosTelefonicos.apellido);
        cout<<"Telefono: "; getline(cin, datosTelefonicos.telefono);

        archivo<<"Nombre: "<<datosTelefonicos.nombre<<endl;
        archivo<<"Apellido: "<<datosTelefonicos.apellido<<endl;
        archivo<<"Telefono: "<<datosTelefonicos.telefono<<endl;

        cout<<"Desea agregar otro contacto? (S/N)"<<endl;
        cin>>respuesta;
    }while((respuesta == 'S')|| (respuesta == 's'));
    archivo.close();
}
void verContacto(){
    string linea;
    ifstream archivo("AgendaTelefonica.txt");
    if(archivo.fail()){
        cout<<"Error al abrir el archivo";
        exit(1);
    }
    cout<<"\tAgenda telefonica.txt\n\n";
    cout<<"----------------------------------"<<endl;
    while(getline(archivo, linea)){
        cout<<linea<<endl;
        getline(archivo, linea);
        cout<<linea<<endl;
        getline(archivo, linea);
        cout<<linea<<endl;
        cout<<"----------------------------------"<<endl;
    }
    cout<<"\n\n";

    archivo.close();
}
