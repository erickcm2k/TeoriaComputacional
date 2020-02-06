#include "afd.h"
using namespace std;

int main() {

    string nombreArchivo;
    cout << "Ingresa el nombre del archivo de texto: "; cin >> nombreArchivo;
    nombreArchivo += ".txt";
    cout << endl;
    fstream miArchivo(nombreArchivo);
    string lineaActual = "";
    int numeroDeEstados = 0;
    string alfabeto;
    bool pasoPrimeraLinea = false;
    Estado estadoActual;
    vector<Estado> estadosDelAutomata;

    if(miArchivo.is_open()){
        while (getline(miArchivo, lineaActual)) {        
            //cout << lineaActual << endl;
            numeroDeEstados++;
            if (!pasoPrimeraLinea) {
                pasoPrimeraLinea = true;
                alfabeto = (string)lineaActual;//= obtenerAlfabeto(lineaActual);
            } else {
                estadoActual = obtenerDatosAFD(lineaActual);
                estadosDelAutomata.push_back(estadoActual);
            }
        }

        int numeroSimbolosAlfabeto = alfabeto.size();
        numeroDeEstados--;

        // Se imprime toda la informacion relacionada con el automata.
        cout << "El alfabeto es: " << alfabeto << " con el cual operara el automata. " << endl;
 
        cout << "Simbolos del alfabeto: " << numeroSimbolosAlfabeto << endl;
        cout << "Numero de estados del automata: " << numeroDeEstados << endl;
        cout << "\nDatos de todos los estados: \n" << endl;

        for(int i = 0; i < estadosDelAutomata.size(); i++){

            cout << "Datos del elemento numero " << i << " del automata ingresado." << endl;
            cout << "Nombre del estado: " << estadosDelAutomata[i].nombreEstadoActual << endl;
            cout << "Es estado de aceptacion (0/1): " << estadosDelAutomata[i].esDeAceptacion << endl;
            cout << "Estados con los que choca: ";
            for(int j = 0; j < estadosDelAutomata[i].estadosConLosQueChoca.size(); j++){
                cout << estadosDelAutomata[i].estadosConLosQueChoca[j] << " ";
            }
            cout << "\n\n";
        }   

    } else {
        cout << "El archivo no se puede abrir. " << endl;
        cout << "Es posible que no exista o el nombre este mal escrito. \n" << endl;
    }
}