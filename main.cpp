#include <iostream> 
#include <string>

using namespace std;


double suma ( double n1, double n2 ){
    return n1 + n2;
}

double resta ( double n1, double n2 ){
    return n1 - n2;
}

double multiplicacion ( double n1, double n2 ){
    return n1 * n2;
}

double division ( double n1, double n2 ){
    return n1 / n2;
}

bool estaVacio ( string numero ){
    return numero[0] == ' ' || numero[0] == '\0';
}

bool validarGuiones ( string numero ){
    short contador = 0;
    int i = 0;
    bool bandera = 1;
    while ( bandera && numero[i] != '\0' ){
        if ( numero[i] == '-' ){
            contador++;
        }

        if ( contador > 1 ){
            bandera = 0;
        }
        i++;
    }
    return bandera;
}

bool validarPuntos ( string numero ){
    short contador = 0;
    int i = 0;
    bool bandera = 1;
    while ( bandera && numero[i]!= '\0' ){
        if ( numero[i] == '.' ){
            contador++;
        }
        if ( contador > 1 ){
            bandera = 0;
        }
        i++;
    }
    return bandera;
}

bool EsNumeroNegativoValido ( string numero ){
    int i = 0;
    bool bandera = 1; 
    while ( bandera && numero[i] != '\0' ){
        if ( numero [i] == '-' ){
            if ( numero[i+1] == ' ' || numero[i+1] == '\0' || i-1 > -1 ){
                bandera = 0;
            }
        }
        i++;
    }
    return bandera;
}

bool esDoubleValido ( string numero ){
    if ( numero[0] == '.' ){
        if ( numero[1] == '\0' ){
            return 0;
        }
    }
    return 1;
}

bool EsNumero ( string numero ){
    int i = 0;
    int bandera = 1;
    while ( bandera && numero[i] != '\0' ){
        if (( numero[i] < '0' || numero[i] > '9') && numero[i] != '-' && numero[i] != '.'){
            bandera = 0;
        } 

        i++;
    }
    return bandera;
}

bool esCadenaValida ( string numero ){
    
    if ( estaVacio( numero )){
        return 0;
    }
    if ( !validarGuiones( numero )){
        return 0;
    }
    
    if ( !EsNumeroNegativoValido( numero )){
        return 0;
    }

    if (!EsNumero( numero )){
        return 0;
    }

    if (!validarPuntos( numero )){
        return 0;
    }

    if ( !esDoubleValido ( numero )){
        return 0;
    }
    
    return 1;
}

bool EsOperador ( char operador ){
    return  ( operador == '+' || operador == '-' || operador == '/' || operador == '*' || operador == '=' );
}

double ingresarNumero (){
    string numeroAux;

    do {
        cout << "       Numero: ";
        getline(cin,numeroAux);
        if ( !esCadenaValida( numeroAux) ){
            cout << "Ingreso un numero invalido, intentalo nuevamente." << endl;
        }
        
    } while ( !esCadenaValida(numeroAux) ); 
    return stod(numeroAux);
}

bool unicoOperador ( string operador ){
    int i  = 0;
    bool bandera = 1;
    while ( bandera && operador[i]!= '\0' ){
        if ( EsOperador( operador[i] ) ){
            if ( operador[i+1] != '\0'){
                bandera = 0;
            }
        }
        i++;
    }
    return bandera;
}

bool esOperadorValido ( string operador ){
    if ( estaVacio ( operador )){
        return 0;
    }

    if ( !unicoOperador( operador )){
        return 0;
    }

    return EsOperador ( operador[0] );
}

char ingresarOperador (){
    string operadorAux ;
    do { 
        cout << "       Operador (+, -, /, *, =): ";
        getline ( cin , operadorAux);
        if ( !esOperadorValido ( operadorAux) ){
            cout << "Ingreso un operador invalido, intentalo nuevamente" << endl;
        }
    } while ( !esOperadorValido( operadorAux ));
    return operadorAux[0];
}

void realizarOperacion ( double numero, char operador, double &resultado ){
    switch (operador){
    case '+':
        resultado = suma ( resultado, numero); 
        break;
    case '-':
        resultado = resta ( resultado, numero );
        break;
    case '*':
        resultado = multiplicacion ( resultado, numero );
        break;
    case '/':
        if ( numero == 0 ){
            cout << "No se puede dividir entre cero, ingresa nuevamente el operador." << endl;
        } else {
        resultado = division ( resultado , numero );
        }
        break;
    default:
        resultado = resultado;
        break;
    }

}

void menuPrincipal (){
    cout << "|**Calculadora**|" << endl;
    double resultado, numero;
    char operador;
    numero = ingresarNumero();
    resultado = numero;
    operador = ingresarOperador();
    while ( operador != '=' ) {
        numero = ingresarNumero();
        realizarOperacion ( numero, operador, resultado );
        operador = ingresarOperador();
    }
    cout << "El resultado es: " << resultado << endl;
}


int main(){
    menuPrincipal();
    return 0;
}
