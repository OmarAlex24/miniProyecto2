#include "validaciones.cc"
#include <iostream>

using namespace std;

struct nodo {
  int dato;
  nodo *siguiente;
};

nodo *crearNodo(int dato) {
  nodo *nuevo = new nodo;
  nuevo->dato = dato;
  nuevo->siguiente = nullptr;
  return nuevo;
}

void limpiarPantalla() {
  cout << "\033[H\033[J";
}

bool esNumero(char dato) {
  return dato >= '0' && dato <= '9';
}

bool esEntradaValida(string numero) {

  if (estaVacio(numero)) {
    return 0;
  }
  if (!validarGuiones(numero)) {
    return 0;
  }

  if (!EsNumeroNegativoValido(numero)) {
    return 0;
  }

  if (!EsNumero(numero)) {
    return 0;
  }

  return 1;
}

void leerDato(string &elemento) {
  do {
    cout << "Escribe un numero ('s' para finalizar): ";
    getline(cin, elemento);
    if (!esEntradaValida(elemento) && elemento != "s") {
      limpiarPantalla();
      cout << "Ingreso un numero invalido, porfavor intentelo nuevamente\n";
    }
  } while (!esEntradaValida(elemento) && elemento != "s");
}

void insertarOrdenado(nodo *&inicio, nodo *nuevo) {
  bool bandera = 1;
  if (inicio == nullptr) {
    inicio = nuevo;
    bandera = 0;
  }
  if (bandera && nuevo->dato <= inicio->dato) {
    nuevo->siguiente = inicio;
    inicio = nuevo;
    bandera = 0;
  }
  nodo *aux = inicio;
  while (bandera && aux->siguiente != nullptr) {
    if (nuevo->dato >= aux->dato && nuevo->dato <= (aux->siguiente)->dato) {
      nuevo->siguiente = aux->siguiente;
      aux->siguiente = nuevo;
      bandera = 0;
    } else {
      aux = aux->siguiente;
    }
  }
  if (bandera) {
    aux->siguiente = nuevo;
  }
}

void llenarLista(nodo *&inicio, string mensaje) {
  string elemento;
  do {
    cout << "Ingresar datos en " << mensaje << "\n";
    leerDato(elemento);
    if (elemento != "s") {
      limpiarPantalla();
      insertarOrdenado(inicio, crearNodo(stof(elemento)));
      cout << "Elemento insertado con exito\n";
    }
  } while (elemento != "s");
}

void imprimirLista(nodo *inicio) {

  if (inicio == nullptr) {
    cout << "La lista esta vacia\n";
  } else {

    nodo *aux = inicio;
    while (aux != nullptr) {
      cout << aux->dato << ' ';
      aux = aux->siguiente;
    }
    cout << "\n";
  }
}

bool estaElNodo(nodo *inicio, int elemento) {
  if (inicio == nullptr)
    return 0;

  bool bandera = 0;
  nodo *aux = inicio;
  while (!bandera && aux != nullptr) {
    if (aux->dato == elemento)
      bandera = 1;
    aux = aux->siguiente;
  }
  return bandera;
}

void insertarFinal(nodo *&inicio, nodo *nuevo) {

  if (inicio == nullptr) {
    inicio = nuevo;
  } else {
    nodo *aux = inicio;
    while (aux->siguiente != nullptr) {
      aux = aux->siguiente;
    }
    aux->siguiente = nuevo;
  }
}

void unirListas(nodo *lista1, nodo *lista2, nodo *&listaFinal) {
  if (lista1 == nullptr && lista2 == nullptr) {
    cout << "Las listas estan vacias, primero debes llenarlas\n";
    return;
  }

  nodo *aux = lista1;

  while (aux != nullptr) {
    if (!estaElNodo(listaFinal, aux->dato)) {
      insertarFinal(listaFinal, crearNodo(aux->dato));
    }
    aux = aux->siguiente;
  }

  aux = lista2;
  while (aux != nullptr) {
    if (!estaElNodo(listaFinal, aux->dato)) {
      insertarFinal(listaFinal, crearNodo(aux->dato));
    }
    aux = aux->siguiente;
  }
}

void interseccionListas(nodo *lista1, nodo *lista2, nodo *&listaFinal) {

  if (lista1 == nullptr && lista2 == nullptr) {
    cout << "Las listas estan vacias, primero debes llenarlas\n";
    return;
  }

  nodo *aux = lista1;
  while (aux != nullptr) {
    if (estaElNodo(lista2, aux->dato))
      insertarFinal(listaFinal, crearNodo(aux->dato));
    aux = aux->siguiente;
  }
}

void diferenciaListas(nodo *lista1, nodo *lista2, nodo *&listaFinal) {
  if (lista1 == nullptr && lista2 == nullptr) {
    cout << "Las listas estan vacias, primero debes llenarlas\n";
    return;
  }

  nodo *aux = lista1;

  while (aux != nullptr) {
    if (!estaElNodo(lista2, aux->dato)) {
      insertarFinal(listaFinal, crearNodo(aux->dato));
    }
    aux = aux->siguiente;
  }
}

int main() {
  nodo *lista1 = nullptr;
  nodo *lista2 = nullptr;
  nodo *u = nullptr;
  nodo *interseccion = nullptr;
  nodo *diferencia = nullptr;

  llenarLista(lista1, "la Lista 1:");
  llenarLista(lista2, "la Lista 2:");

  cout << "\nLa lista 1 es:\n";
  imprimirLista(lista1);

  cout << "\nLa lista 2 es:\n";
  imprimirLista(lista2);

  cout << "\nAhora unimos las 2 listas: \n";
  unirListas(lista1, lista2, u);
  imprimirLista(u);

  cout << "\nAhora, la interseccion de las 2 listas\n";
  interseccionListas(lista1, lista2, interseccion);
  imprimirLista(interseccion);

  cout << "\nAhora, la diferencia de las 2 listas\n";
  diferenciaListas(lista1, lista2, diferencia);
  imprimirLista(diferencia);

  return 0;
}