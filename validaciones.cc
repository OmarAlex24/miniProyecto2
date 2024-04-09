#include <iostream>
#include <string>

using namespace std;

bool estaVacio(string numero) {
  return numero[0] == ' ' || numero[0] == '\0';
}

bool validarGuiones(string numero) {
  short contador = 0;
  int i = 0;
  bool bandera = 1;
  while (bandera && numero[i] != '\0') {
    if (numero[i] == '-') {
      contador++;
    }

    if (contador > 1) {
      bandera = 0;
    }
    i++;
  }
  return bandera;
}

bool EsNumeroNegativoValido(string numero) {
  int i = 0;
  bool bandera = 1;
  while (bandera && numero[i] != '\0') {
    if (numero[i] == '-') {
      if (numero[i + 1] == ' ' || numero[i + 1] == '\0' || i - 1 > -1) {
        bandera = 0;
      }
    }
    i++;
  }
  return bandera;
}

bool EsNumero(string numero) {
  int i = 0;
  int bandera = 1;
  while (bandera && numero[i] != '\0') {
    if ((numero[i] < '0' || numero[i] > '9') && numero[i] != '-') {
      bandera = 0;
    }

    i++;
  }
  return bandera;
}
