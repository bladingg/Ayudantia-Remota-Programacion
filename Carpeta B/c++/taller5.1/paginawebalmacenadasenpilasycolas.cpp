#include <string>
#include <iostream>

using namespace std;

struct Nodo
{
public:
  std::string url;
  Nodo* siguiente;
};

class Pila
{
private:
  Nodo* cima;

public:
  Pila() : cima(nullptr) {}
  void apilar(std::string url = "")
  {
    if (url.empty())
    {
      std::cout << "La URL esta vacia, no se puede apilar.\n";
      return;
    }
    else
    {
      Nodo* nuevo = new Nodo();
      nuevo->url = url;
      nuevo->siguiente = cima;
      cima = nuevo;
    }
  }

  void desapilar()
  {
    if (cima != nullptr)
    {
      Nodo* temp = cima;
      cima = cima->siguiente;
      std::cout << "Desapilando: " << temp->url << std::endl;
      delete temp;
    }
  }

  std::string obtenerCima() 
  {
    if (cima != nullptr)
    {
      return cima->url;
    }
    return "";
  }

  void estaVacia()
  {
    if (cima == nullptr)
    {
      std::cout << "La pila esta vacia." << std::endl;
    }
    else
    {
      std::cout << "La pila no esta vacia." << std::endl;
    }
  }

  void printPila()
  {
    Nodo* temp = cima;
    if (temp == nullptr)
    {
      std::cout << "La pila esta vacia.\n";
      return;
    }
    std::cout << "Contenido de la pila:\n";
    while (temp != nullptr)
    {
      std::cout << temp->url << std::endl;
      temp = temp->siguiente;
    }
    delete temp;
  }

  void buscarPila(std::string url){
    Nodo* temp = cima;
    if (url.empty()){
      std::cout << "La URL esta vacia, no se puede buscar.\n";
      return;
    }
    while (temp != nullptr){
      if (temp->url == url){
        std::cout << "Encontrado: " << temp->url << std::endl;
        delete temp;
        return;
      }
      else if(temp->siguiente == nullptr && temp->url != url){
        std::cout << "No se encontro la URL: " << url << std::endl;
      }
      temp = temp->siguiente;
    }
    delete temp;
  }

};

int main(int argc, char const *argv[])
{
  Pila pila;
  
  pila.estaVacia();
  for (int i = 0; i < 10; ++i){
    pila.apilar("https://pagina" + std::to_string(i+1) + ".com");
  }
  pila.estaVacia();
  pila.printPila();
  pila.desapilar();
  pila.printPila();
  pila.buscarPila("552");
  pila.buscarPila("");

  return 0;
}
