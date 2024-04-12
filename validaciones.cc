#include <iostream>
#include <string>

using namespace std;

// Creamos un struct llamado nodo, donde como atributos tiene dato de tipo entero,
// y un puntero de tipo nodo llamado siguiente.
struct nodo {
  int dato;
  nodo *siguiente;
};

// Creamos una funcion basica para saber si un string esta vacio
bool estaVacio(string numero) {
  return numero[0] == ' ' || numero[0] == '\0';
}

// Creamos una funcion para que el usuario no pueda ingresar mas de un guion.
// Ej: --2 (Ingreso un numero negativo invalido)
bool validarGuiones(string numero) {
  // Creamos un contador de tipo short, que este nos ayudara a saber cuantos caracteres guiones tiene el string
  short contador = 0;
  // Y creamos un iterador que nos ayudara a ir iterando en el string
  int i = 0;
  // Esta bandera nos ayudara para salir del ciclo si encontramos mas de un guion
  bool bandera = 1;

  // Definimos que mientras la bandera sea verdadera, y no hayamos llegado al final del string sigamos iterando
  while (bandera && numero[i] != '\0') {
    // Si encontramos un guion sumamos uno a nuestro contador
    if (numero[i] == '-')
      contador++;
    // Si nuestro contador ya es mas de 1, volvemos nuestra bandera falsa
    if (contador > 1)
      bandera = 0;

    // Aumentamos en un 1 nuestro iterador para que iteremos en el string
    i++;
  }
  // Regresamos el valor de nuestra bandera
  return bandera;
}

// Creamos una funcion para validar que el numero ingresado del usuario sea un numero negativo valido

bool EsNumeroNegativoValido(string numero) {
  // Creamos un iterador que nos ayudara a iterar en el string
  int i = 0;
  // Creamos una bandera que nos ayudara a salir del ciclo si encontramos un numero negativo invalido
  bool bandera = 1;
  // Definimos que mientras la bandera sea verdadera, y no hayamos llegado al final del string sigamos iterando
  while (bandera && numero[i] != '\0') {
    // Si encontramos un guion, verificamos que el siguiente caracter no sea un espacio, o que no sea el final del string
    if (numero[i] == '-')
      if (numero[i + 1] == ' ' || numero[i + 1] == '\0' || i - 1 > -1)
        bandera = 0;

    // Aumentamos en un 1 nuestro iterador para que iteremos en el string
    i++;
  }
  // Regresamos el valor de nuestra bandera
  return bandera;
}

// Creamos una funcion para saber si un string es un numero
bool EsNumero(string numero) {
  // Creamos un iterador que nos ayudara a iterar en el string
  int i = 0;
  // Creamos una bandera que nos ayudara a salir del ciclo si encontramos un numero invalido
  int bandera = 1;
  // Definimos que mientras la bandera sea verdadera, y no hayamos llegado al final del string sigamos iterando
  while (bandera && numero[i] != '\0') {
    // Si el caracter en la posicion i no es un numero, o no es un guion, volvemos nuestra bandera falsa
    if ((numero[i] < '0' || numero[i] > '9') && numero[i] != '-')
      bandera = 0;

    // Aumentamos en un 1 nuestro iterador para que iteremos en el string
    i++;
  }
  // Regresamos el valor de nuestra bandera
  return bandera;
}

// Creamos una funcion para crear un nodo, donde le pasamos como parametro un dato de tipo entero
nodo *crearNodo(int dato) {
  // Creamos un puntero dinamico de tipo nodo llamado nuevo
  nodo *nuevo = new nodo;
  // Le asignamos el dato que le pasamos como parametro
  nuevo->dato = dato;
  // Y hacemos que siguiente apunte a nullptr
  nuevo->siguiente = nullptr;
  // Regresamos el puntero nuevo
  return nuevo;
}

// Creamos una funcion para limpiar la pantalla
void limpiarPantalla() {
  cout << "\033[H\033[J";
}

// Creamos una funcion para validar la entrada del usuario
bool esEntradaValida(string numero) {
  // Si el string esta vacio, regresamos falso
  if (estaVacio(numero))
    return 0;
  // Si el string tiene mas de un guion, regresamos falso
  if (!validarGuiones(numero))
    return 0;
  // Si el string no es un numero negativo valido, regresamos falso
  if (!EsNumeroNegativoValido(numero))
    return 0;
  // Si el string no es un numero, regresamos falso
  if (!EsNumero(numero))
    return 0;

  // Si no se cumple ninguna de las condiciones anteriores, regresamos verdadero
  return 1;
}

// Creamos una funcion para leer un dato del usuario
void leerDato(string &elemento) {
  // Creamos un ciclo do-while, que se ejecutara mientras la entrada del usuario no sea valida
  // o no que ingrese la letra 's'
  do {
    cout << "Escribe un numero ('s' para finalizar): ";
    getline(cin, elemento);
    // Si la entrada del usuario no es valida, limpiamos la pantalla y le informamos al usuario que ingreso un numero invalido
    if (!esEntradaValida(elemento) && elemento != "s") {
      limpiarPantalla();
      cout << "Ingreso un numero invalido, porfavor intentelo nuevamente\n";
    }
  } while (!esEntradaValida(elemento) && elemento != "s");
}

// Creamos una funcion para saber si un nodo esta en la lista
bool estaElNodo(nodo *inicio, int elemento) {
  // Si la lista esta vacia, regresamos falso
  if (inicio == nullptr)
    return 0;
  // Creamos una bandera que nos ayudara a salir del ciclo si encontramos el nodo
  bool bandera = 0;
  // Creamos un puntero de tipo nodo llamado aux, que nos ayudara a recorrer la lista
  nodo *aux = inicio;
  // Definimos que mientras la bandera sea falsa, y no hayamos llegado al final de la lista sigamos iterando
  while (!bandera && aux != nullptr) {
    // Si el dato del nodo es igual al elemento que le pasamos como parametro, volvemos nuestra bandera verdadera
    if (aux->dato == elemento)
      bandera = 1;
    // Si no, simplemente avanzamos al siguiente nodo
    aux = aux->siguiente;
  }
  // Regresamos el valor de nuestra bandera
  return bandera;
}

// Creamos una funcion para insertar un nodo en la lista de forma ordenada
void insertarOrdenado(nodo *&inicio, nodo *nuevo) {
  // Creamos una bandera que nos ayudara a salir del ciclo si ya insertamos el nodo
  bool bandera = 1;
  // Si la lista esta vacia, simplemente hacemos que el inicio apunte al nuevo nodo
  // y volvemos nuesta bandera falsa
  if (inicio == nullptr) {
    inicio = nuevo;
    bandera = 0;
  }
  // Si la lista no esta vacia, y el dato del nuevo nodo es menor o igual al dato del inicio
  // simplemente hacemos que el nodo nuevo apunte a inicio, y hacemos que inicio sea igual al nuevo nodo
  if (bandera && nuevo->dato <= inicio->dato) {
    nuevo->siguiente = inicio;
    inicio = nuevo;
    bandera = 0;
  }
  // Creamos un puntero de tipo nodo llamado aux, que nos ayudara a recorrer la lista
  nodo *aux = inicio;
  // Definimos que mientras la bandera sea verdadera, y no hayamos llegado al final de la lista sigamos iterando
  while (bandera && aux->siguiente != nullptr) {
    // Si el dato del nuevo nodo es mayor o igual al dato del nodo actual, y menor o igual al dato del siguiente nodo
    if (nuevo->dato >= aux->dato && nuevo->dato <= (aux->siguiente)->dato) {
      // Hacemos que el siguiente del nuevo nodo apunte al siguiente del nodo actual
      nuevo->siguiente = aux->siguiente;
      // Hacemos que el siguiente del nodo actual apunte al nuevo nodo
      aux->siguiente = nuevo;
      // Volvemos nuestra bandera falsa
      bandera = 0;
    } else
      // Si no simplemente avanzamos al siguiente nodo
      aux = aux->siguiente;
  }
  // Si la bandera sigue siendo verdadera (es decir, que el dato del nuevo nodo es mayor al dato del ultimo nodo),
  // simplemente hacemos que el siguiente del nodo actual apunte al nuevo nodo
  if (bandera)
    aux->siguiente = nuevo;
}

// Creamos una funcion para llenar la lista
void llenarLista(nodo *&inicio, string mensaje) {
  // Creamos un string llamado elemento
  string elemento;
  // Creamos un ciclo do-while, que se ejecutara mientras el usuario no ingrese la letra 's'
  do {
    cout << "Ingresar datos en " << mensaje << "\n";
    // Llamamos a nuestra funcion leerDato(), donde le pasamos como parametro el string elemento
    leerDato(elemento);
    // Si el elemento es diferente de 's', limpiamos la pantalla
    if (elemento != "s") {
      limpiarPantalla();
      // Si el nodo no esta en la lista, simplemente lo insertamos
      if (!estaElNodo(inicio, stoi(elemento))) {
        insertarOrdenado(inicio, crearNodo(stoi(elemento)));
        cout << "Elemento insertado con exito\n";
        // Si no, le informamos al usuario que el elemento ya fue previamente ingresado
      } else
        cout << "El elemento fue previmente ingresado.\n";
    }
  } while (elemento != "s");
}

// Creamos una funcion para imprimir la lista
void imprimirLista(nodo *inicio) {
  // Si la lista esta vacia, simplemente le informamos al usuario que la lista esta vacia
  if (inicio == nullptr)
    cout << "La lista esta vacia\n";
  else {
    // Si no, creamos un puntero de tipo nodo llamado aux, que nos ayudara a recorrer la lista
    nodo *aux = inicio;
    // Definimos que mientras no lleguemos al final de la lista, simplemente imprimimos el dato del nodo actual
    // y avanzamos al siguiente nodo
    while (aux != nullptr) {
      cout << aux->dato << ' ';
      aux = aux->siguiente;
    }
    cout << "\n";
  }
}

// Creamos una funcion para unir las listas
void unirListas(nodo *lista1, nodo *lista2, nodo *&listaFinal) {
  // Si ambas listas estan vacias, simplemente salimos de la funcion
  if (lista1 == nullptr && lista2 == nullptr) {
    return;
  }

  // Creamos un puntero de tipo nodo llamado aux, que nos ayudara a recorrer la lista 1
  nodo *aux = lista1;

  // Definimos que mientras no lleguemos al final de la lista 1, simplemente insertamos ordenadamente el nodo actual
  while (aux != nullptr) {
    insertarOrdenado(listaFinal, crearNodo(aux->dato));
    aux = aux->siguiente;
  }

  // Hacemos que el puntero aux apunte a la lista 2
  aux = lista2;
  // Definimos que mientras no lleguemos al final de la lista 2
  while (aux != nullptr) {
    // Si el dato del nodo actual no esta en la lista final, simplemente lo insertamos ordenadamente
    // con la funcion instertarOrdenado(), y pasandole como segundo parametro un nodo que creamos con la funcion crearNodo()
    // con el dato del nodo actual
    if (!estaElNodo(listaFinal, aux->dato))
      insertarOrdenado(listaFinal, crearNodo(aux->dato));
    // Avanzamos al siguiente nodo
    aux = aux->siguiente;
  }
}

// Creamos una funcion para saber la interseccion de las listas
void interseccionListas(nodo *lista1, nodo *lista2, nodo *&listaFinal) {
  // Si ambas listas estan vacias, simplemente salimos de la funcion
  if (lista1 == nullptr && lista2 == nullptr) {
    return;
  }
  // Creamos un puntero de tipo nodo llamado aux, que nos ayudara a recorrer la lista 1
  nodo *aux = lista1;
  // Definimos que mientras no lleguemos al final de la lista 1
  while (aux != nullptr) {
    // Si el dato del nodo actual esta en la lista 2, y no esta en la lista final, simplemente lo insertamos ordenadamente
    // con la funcion instertarOrdenado(), y pasandole como segundo parametro un nodo que creamos con la funcion crearNodo()
    // con el dato del nodo actual
    if (estaElNodo(lista2, aux->dato) && !estaElNodo(listaFinal, aux->dato))
      insertarOrdenado(listaFinal, crearNodo(aux->dato));
    // Avanzamos al siguiente nodo
    aux = aux->siguiente;
  }
}

// Creamos una funcion para saber la diferencia de las listas
void diferenciaListas(nodo *lista1, nodo *lista2, nodo *&listaFinal) {
  // Si lista 1 esta vacia, simplemente salimos de la funcion
  if (lista1 == nullptr) {
    return;
  }
  // Creamos un puntero de tipo nodo llamado aux, que nos ayudara a recorrer la lista 1
  nodo *aux = lista1;
  // Definimos que mientras no lleguemos al final de la lista 1
  while (aux != nullptr) {
    // Si el dato del nodo actual no esta en la lista 2, simplemente lo insertamos ordenadamente en la lista final
    // con la funcion instertarOrdenado(), y pasandole como segundo parametro un nodo que creamos con la funcion crearNodo()
    // con el dato del nodo actual
    if (!estaElNodo(lista2, aux->dato))
      insertarOrdenado(listaFinal, crearNodo(aux->dato));

    // Avanzamos al siguiente nodo
    aux = aux->siguiente;
  }
}
