#include <string>
#include <iostream>

using namespace std;

//typedef
struct Nodo
{
public:
  std::string url; // URL de la página web almacenada
  Nodo* siguiente; // Puntero a la URL de la página web

  // Nodo(std::string newUrl) : url(newUrl), siguiente(nullptr)
  // {
    // url = newUrl; // Inicializa la URL
    // siguiente = nullptr; // Inicializa el puntero a la URL
  // }
};

class Pila
{
private:
  Nodo* cima;

public:
  Pila() : cima(nullptr)
  {
    // cima = new Nodo("");
  }

  // funciones de la pila sin retorno de valores
  void apilar(std::string url = "")
  {
    if (url.empty())
    {
      std::cout << "La URL esta vacia, no se puede apilar.\n";
      return; // Si la URL está vacía, no hacemos nada
    }
    else
    {
      // declaramos un nuevo nodo con la URL proporcionada
      // y lo apilamos en la cima de la pila
      Nodo* nuevo = new Nodo();
      // Nodo* nuevo = new Nodo(url);
      nuevo->url = url;
      // Asignamos el nuevo nodo a la cima de la pila
      // El siguiente del nuevo nodo apunta a la cima actual
      // asi misma
      nuevo->siguiente = cima; // Asignamos el puntero al nodo actual
      cima = nuevo;
    }
  }

  void desapilar()
  {
    // valida que no se intente desapilar de una pila vacía para evitar errores
    if (cima != nullptr)
    {
      Nodo* temp = cima;
      // libera la memoria del nodo desapilado
      // Mueve la cima al siguiente nodo
      cima = cima->siguiente;
      std::cout << "Desapilando: " << temp->url << std::endl; // Muestra la URL desapilada
      delete temp;
    }
  }

  std::string obtenerCima() 
  {
    if (cima != nullptr)
    {
      return cima->url;
    }
    return ""; // Valor por defecto si la pila está vacía
  }

  void estaVacia()
  // std::string estaVacia()
  {
    if (cima == nullptr)
    {
      std::cout << "La pila esta vacia." << std::endl;
      // return "La pila esta vacia.";
    }
    else
    {
      std::cout << "La pila no esta vacia." << std::endl;
      // return "La pila no esta vacia.";
    }
  }

  void printPila()
  {
    Nodo* temp = cima; //3
    if (temp == nullptr)
    {
      std::cout << "La pila esta vacia.\n";
      return;
    }
    std::cout << "Contenido de la pila:\n";
    while (temp != nullptr)
    {
      std::cout << temp->url << std::endl; // Imprime la URL del nodo actual
      temp = temp->siguiente; // Mueve al siguiente nodo
    }
  }
};

int main(int argc, char const *argv[])
{
  Pila pila;
  
  pila.estaVacia();
  pila.apilar("3");
  pila.apilar("2");
  pila.apilar("1");
  // pila.apilar("https://www.altavista.com");
  // std::cout << "Cima de la pila: " << pila.obtenerCima() << std::endl;
  pila.estaVacia();
  pila.printPila();
  // pila.apilar("https://www.big.com");
  // std::cout << "Cima de la pila: " << pila.obtenerCima() << std::endl;
  // pila.apilar("https://www.onion.com");
  // std::cout << "Cima de la pila: " << pila.obtenerCima() << std::endl;
  // pila.apilar("");
  // pila.apilar("https://www.google.com");
  // std::cout << "Cima de la pila: " << pila.obtenerCima() << std::endl;
  // pila.apilar("");
  pila.desapilar();
  pila.printPila();

  return 0;
}
