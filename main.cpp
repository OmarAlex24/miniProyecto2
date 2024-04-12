// Importamos las funciones de el archivo "validaciones.cc"
#include "validaciones.cc"
#include <iostream>

using namespace std;

int main() {

  // Creamos punteros de tipo nodo para cada lista
  nodo *lista1 = nullptr;
  nodo *lista2 = nullptr;
  nodo *u = nullptr;
  nodo *interseccion = nullptr;
  nodo *diferencia = nullptr;

  // Llamamos a nuestra funcion llenarLista(), donde validamos que la entrada del
  // usuario sea valida, y pedir un numero hasta que el usuario ingrese la letra 's'
  llenarLista(lista1, "la Lista 1:");
  llenarLista(lista2, "la Lista 2:");

  // Imprimimos lista 1 con la funcion imprimirLista(), donde, simplemente
  // recorremos la lista hasta llegar a nullptr
  cout << "\nLa lista 1 es:\n";
  imprimirLista(lista1);

  // Imprimimos lista 2 con la funcion imprimirLista(), donde, simplemente
  // recorremos la lista hasta llegar a nullptr
  cout << "\nLa lista 2 es:\n";
  imprimirLista(lista2);

  // Ahora, llamamos a nuestra funcion unirListas(), donde pasamos como parametros,
  // las 2 listas que queremos unir, y la lista donde guardaremos el resultado respectivamente.
  cout << "\nAhora unimos las 2 listas: \n";
  unirListas(lista1, lista2, u);

  // Preguntamos que si el resultado de la union es vacias, informarselo al usuario.
  // Si no simplemente imprimimos la lista 'u'
  if (u == nullptr)
    cout << "No se pueden unir listas vacias.\n";
  else
    imprimirLista(u);

  // Ahora, llamamos a nuestra funcion unirListas(), donde pasamos como parametros,
  // las 2 listas que queremos saber su interseccion, y la lista donde guardaremos el resultado respectivamente.
  cout << "\nAhora, la interseccion de las 2 listas\n";
  interseccionListas(lista1, lista2, interseccion);

  // Preguntamos que si el resultado de la interseccion es vacias, informarselo al usuario.
  // Si no, simplemente imprimimos la lista 'interseccion'
  if (interseccion == nullptr)
    cout << "No existen puntos de interseccion entre las listas.\n";
  else
    imprimirLista(interseccion);

  // En este caso primero preguntamos que si la lista1 es vacia, le informamos al usuario que no se puede
  // obtener una diferencia de una lista vacia

  // Si no, simplemente llamamos a la funcion diferenciaListas() para obtener la diferencia de
  // las 2 listas que le pasamos como parametro, y la lista donde guardaremos el resultado respectivamente.
  // E imprimimos la lista.
  cout << "\nAhora, la diferencia de las 2 listas\n";
  if (lista1 == nullptr)
    cout << "No se puede obtener la diferencia de una lista vacia.\n";
  else {
    diferenciaListas(lista1, lista2, diferencia);
    imprimirLista(diferencia);
  }
  return 0;
}